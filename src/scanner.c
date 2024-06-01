#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include <stdio.h>

// The member order must match the ``externals`` array in ``grammar.js`` but
// the names are irrelevant
typedef enum {
    /* From treesitter docs:

        If a syntax error is encountered during regular parsing,
        Tree-sitter’s first action during error recovery will be to call the
        external scanner’s scan function with all tokens marked valid.

    We use the _ERROR_SENTINEL to detect this.
    */
    _ERROR_SENTINEL,
    _EOD_SENTINEL,
    EOL,
    EMPTY_LINE,
    NIH_WHITESPACE,
    NODE_CONTINUE,
    FLAG_NODE_DEF,
    NODE_BEGIN,
    NODE_END,
    AUTOCLOSE_WARNING,
} TokenType;


static bool includes_sol_symbols(
        /* This is a simple helper function that just checks to see if
        any of the currently valid symbols include the start of the
        line, which triggers a special parse mechanism.
        */
        const bool *valid_symbols
) {
    return (
        valid_symbols[EMPTY_LINE]
        || valid_symbols[NODE_CONTINUE]
        || valid_symbols[NODE_BEGIN]
        || valid_symbols[NODE_END]);
}


//////////////////////////////////////////////////////////////////////////////
// STRING/UNICODE HELPERS
//////////////////////////////////////////////////////////////////////////////
static const int32_t SPACE_CHAR[] = {
    // See https://www.fileformat.info/info/unicode/category/Zs/list.htm
    0x0020,
    0x00A0,
    0X1680,
    0X2000,
    0X2001,
    0X2002,
    0X2003,
    0X2004,
    0X2005,
    0X2006,
    0X2007,
    0X2008,
    0X2009,
    0X200A,
    0X202F,
    0X205F,
    0X3000,};
static const int32_t TAB_CHAR[] = {
    0x0009,};
static const int32_t NEWLINE = 0x000A;
static const int32_t ZWSP = 0x200B;
static const int32_t ZWNBSP = 0xFEFF;
static const int32_t NODEDEF_SYMBOL = 0x003E;


static bool is_space(
        int32_t lookahead
) {
    for (
        size_t i = 0;
        i < (sizeof(SPACE_CHAR) / sizeof(SPACE_CHAR[0]));
        ++i
    ) {
        if (SPACE_CHAR[i] == lookahead) {
            return true;
        }
    }

    return false;
}


static bool is_tab(
        int32_t lookahead
) {
    for (
        size_t i = 0;
        i < (sizeof(TAB_CHAR) / sizeof(TAB_CHAR[0]));
        ++i
    ) {
        if (TAB_CHAR[i] == lookahead) {
            return true;
        }
    }

    return false;
}


static bool is_horizontal_whitespace(
        int32_t lookahead
) {
    return is_space(lookahead) || (lookahead == ZWNBSP) || (lookahead == ZWSP);
}


static bool is_indentation_or_eol(
        int32_t lookahead
) {
    return lookahead == NEWLINE || is_space(lookahead) || is_tab(lookahead);
}


//////////////////////////////////////////////////////////////////////////////
// TYPEDEFS
//////////////////////////////////////////////////////////////////////////////

// IMPORTANT: if you change anything here, YOU MUST ALSO UPDATE SERIALIZATION!
typedef struct {
    uint8_t node_depth;
} Node;
// SUPER IMPORTANT: if you add anything here with a variable length, you'll
// need to make significant changes to de/serialization! We currently rely
// upon knowing the node size in advance before even starting to serialize the
// node stack, so that we can preface it with a total size (though I'm not
// actually sure the total size is needed, so maybe you can skip that? or,
// I suppose you could store the node COUNT first, and then the size of each
// node immediately before serializing it)


// IMPORTANT: if you change anything here, YOU MUST ALSO UPDATE SERIALIZATION!
typedef struct {
    // Together, these determine how indentation is determined for a file. It
    // must always be the same indentation character used, and it must always
    // be repeated the same number of times.
    int32_t indentation_char;
    uint8_t indentation_char_repetitions;

    bool any_token_emitted;
    bool eof_eol_emitted;
    bool at_eof;
    // We use this to denote that we've emitted all possible zero-length tokens
    // at the end of the file.
    bool post_eof;

    TokenType previous_token;

    Array(Node *) * node_stack;
} Scanner;


size_t _SCANNER_FIELD_LENGTHS[] = {
    sizeof(int32_t),
    sizeof(uint8_t),
    sizeof(bool),
    sizeof(bool),
    sizeof(bool),
    sizeof(bool),
    sizeof(TokenType)};


//////////////////////////////////////////////////////////////////////////////
// MEMORY MANAGEMENT
//////////////////////////////////////////////////////////////////////////////
void *tree_sitter_cleancopy_external_scanner_create(
        void
) { 
    Scanner *scanner = (Scanner *)ts_malloc(sizeof(Scanner));

    // This is how you create an empty array
    // hmm, this emits a compiler warning because the Array(Node *) is used as
    // a throwaway type to calculate a size.
    scanner->node_stack = ts_malloc(sizeof(Array(Node *)));
    scanner->indentation_char = 0;
    scanner->indentation_char_repetitions = 0;
    scanner->any_token_emitted = false;
    scanner->eof_eol_emitted = false;
    scanner->at_eof = false;
    scanner->post_eof = false;
    array_init(scanner->node_stack);

    return scanner;
}


void tree_sitter_cleancopy_external_scanner_destroy(
        void *payload
) {
    Scanner *scanner = (Scanner *)payload;

    // I haven't shown the allocation of the nodes yet,
    // but keep in mind that `array_delete` does not deallocate any memory
    // you store in the array itself.
    for (size_t i = 0; i < scanner->node_stack->size; ++i) {
    // I use `array_get` even though you can index the contents directly.
        ts_free(array_get(scanner->node_stack, i));
    }

    // The array is a growable one, `array_delete` ensures that the
    // memory is deleted.
    array_delete(scanner->node_stack);

    ts_free(scanner);
}


static void push_node(
        /* Adds a new node to the scanner's node stack, growing the stack
        automatically.
        */
        Scanner *scanner,
        uint8_t node_depth
) {
    Node *node = ts_malloc(sizeof(Node));
    node->node_depth = node_depth;

    array_push(scanner->node_stack, node);
}


static void pop_and_free_node(
        /* Removes the tail node from the scanner's node stack and frees
        any memory associated with it.
        */
        Scanner *scanner
) {
    if (scanner->node_stack->size > 0) {
        ts_free(array_pop(scanner->node_stack));
    }
}


//////////////////////////////////////////////////////////////////////////////
// SCANNING
//////////////////////////////////////////////////////////////////////////////


static void emit_token(
        /* Helper for all the bookkeeping we need to do any time we
        emit a token. **Note that the caller is still responsible for
        advancing the lexer if required!!!**
        */
        TSLexer *lexer,
        Scanner *scanner,
        TokenType token
) {
    scanner->any_token_emitted = true;
    scanner->previous_token = token;
    lexer->result_symbol = token;
}


typedef struct {
    bool preliminary_token_found;
    TokenType preliminary_token;
    uint8_t preliminary_indentation_depth;
    uint16_t indentation_chars_found;
    int32_t lookahead_at_line_start;
} _SolParseState;


static bool advance_to_maybe_node_end(
        /* Node endings mark the end of an indented block -- ie, dedentation.
        Note that these are **always** zero-width tokens, and there will **not**
        be an initial NODE_CONTINUE here. Also note that we may emit multiple
        node_ends for a single call, in case we're dedenting multiple
        indentation levels, but that treesitter doesn't support this in a
        scan pass. Therefore, we simply pop the corresponding node off of the
        stack, and allow the next scan pass to retry parse_node_end. This is
        perhaps somewhat wasteful, since we'll be parsing the indentation
        multiple times when unwrapping multiple block indentation levels, but
        it's also simple and robust.

        NOTE THAT THIS CANNOT BE CALLED UNTIL AFTER AT LEAST ONE NODE_CONTINUE
        HAS HAPPENED! The grammar is responsible for enforcing this, but if
        the grammar is broken, well, this will get errors because of the
        indentation char not being defined on the scanner.
        */
        TSLexer *lexer,
        Scanner *scanner,
        _SolParseState *parse_state
) {
    // Technically not possible, but maybe in an error condition? Better than
    // a panic!
    if (scanner->node_stack->size == 0) { return false; }
    
    uint8_t current_node_depth = (
        ((Node *)*array_back(scanner->node_stack))->node_depth);
    if (current_node_depth == 0) { return false; }

    // Keep in mind that we might be dedenting multiple levels, so this might
    // be less than this
    uint16_t max_indentation_char_count = (
        scanner->indentation_char_repetitions * (current_node_depth - 1));
    uint16_t indentation_chars_found = parse_state->indentation_chars_found;

    // The general strategy here is to keep advancing until we either hit the
    // maximum number of characters we'd expect for a dedentation, or the EoF,
    // or the first non-indentation character. Then we'll check to see how many
    // indentation characters we consumed to decide if it's a plausible node
    // end
    while (
        !lexer->eof(lexer)
        && indentation_chars_found < max_indentation_char_count
    ) {
        if (lexer->lookahead == scanner->indentation_char) {
            ++indentation_chars_found;
            lexer->advance(lexer, false);
        } else {
            break;
        }
    }

    // Note that node_ends are zero-width tokens on the NEXT LINE of the
    // parse; therefore, they must always be zero-width, and we NEVER want to
    // mark_end!
    parse_state->indentation_chars_found = indentation_chars_found;

    // We want to check here if the next lookahead character is the indentation
    // character. If it is, we just want to advance, but we don't want to mark
    // the end or set the found token
    if (
        // purely defensive; should never be greater than
        indentation_chars_found >= max_indentation_char_count
        && lexer->lookahead == scanner->indentation_char
    ) { return false; }

    // Note that, since we're working with integers, this will round towards
    // 0, meaning that we'll automatically round down to the nearest FULL
    // indentation level -- which is exactly what we want
    parse_state->preliminary_indentation_depth = (
        indentation_chars_found / scanner->indentation_char_repetitions);
    parse_state->preliminary_token_found = true;
    parse_state->preliminary_token = NODE_END;
    return true;
}


static bool advance_to_maybe_node_continue(
        /* Node continuations appear at the beginning of every line where the
        indentation level does not change. Note that this does not include,
        for example, the leading bit of a node_begin -- if a line includes an
        increase in the indentation level, then the ENTIRE indentation for that
        line will be marked as a node_begin.
        */
        TSLexer *lexer,
        Scanner *scanner,
        _SolParseState *parse_state
) {
    // This handles node continues at L0 indentation
    if (
        // Case 1: we've never encountered indentation in the file, ever
        scanner->indentation_char_repetitions == 0
        // Case 2: we have encountered it, but we've popped back out to L0
        || scanner->node_stack->size == 0
        // Case 3: we somehow got in a situation where document has a root
        // node, but its depth is 0. This would imply changes to grammar.js
        || ((Node *)*array_back(scanner->node_stack))->node_depth == 0
    ) {
        // We want to make sure that the next character **is NOT** indentation;
        // otherwise, it's not a valid node continue. That will either be a
        // node_begin or an error state; either way, we don't want to mark a
        // preliminary token. But assuming that's not the case, we can just
        // continue on.
        if (
            !lexer->eof(lexer)
            && !is_indentation_or_eol(lexer->lookahead)
        ){
            parse_state->preliminary_indentation_depth = 0;
            parse_state->preliminary_token_found = true;
            parse_state->preliminary_token = NODE_CONTINUE;
            return true;
        }

    // ... and this handles all other indentation levels. Note that, by
    // definition, this means we already know what the indentation info is,
    // because defining it is done within parse_node_begin
    } else {
        uint16_t indentation_chars_found = parse_state->indentation_chars_found;
        uint8_t previous_node_depth = (
            (Node *)*array_back(scanner->node_stack))->node_depth;

        uint16_t max_indentation_char_count = (
            previous_node_depth * scanner->indentation_char_repetitions);

        // TODO: refactor into something reusable!
        while (
            !lexer->eof(lexer)
            && indentation_chars_found < max_indentation_char_count
        ) {
            if (lexer->lookahead == scanner->indentation_char) {
                ++indentation_chars_found;
                lexer->advance(lexer, false);
            } else {
                break;
            }
        }

        parse_state->indentation_chars_found = indentation_chars_found;

        // We want to check here if the next lookahead character is the indentation
        // character. If it isn't, we don't want to set the found token
        if (
            // IMPORTANT:
            // Note the different termination condition -- we need to match
            // this exactly!
            indentation_chars_found != max_indentation_char_count
            || lexer->lookahead == scanner->indentation_char
        ) { return false; }

        parse_state->preliminary_indentation_depth = previous_node_depth;
        parse_state->preliminary_token_found = true;
        parse_state->preliminary_token = NODE_CONTINUE;
        return true;
    }

    return false;
}


static bool _ensure_indent_info(
        /* This is responsible for ensuring we have indentation info defined
        on the scanner, and defining exactly what the indentation strategy is.
        Currently, we support either a single tab character per indentation,
        or 4 repeated unicode space-like characters (unicode category Zs).

        Returns true if the indent info is available, or false if unavailable.
        Note that the only situation this will return false is if the lookahead
        character was not an indentation character.
        */
        Scanner *scanner,
        int32_t lookahead
) {
    if (scanner->indentation_char_repetitions == 0) {
        if (is_space(lookahead)) {
            scanner->indentation_char = lookahead;
            scanner->indentation_char_repetitions = 4;
            return true;
        } else if (is_tab(lookahead)) {
            scanner->indentation_char = lookahead;
            scanner->indentation_char_repetitions = 1;
            return true;
        } else {
            return false;
        }
    }

    return true;
}


static bool advance_to_maybe_node_begin(
        /* Node beginnings mark the start of an indented block, AFTER any
        node metadata has been defined. Note that we will mark the entire
        indentation whitespace (from line start onwards) of the line as a
        NODE_BEGIN -- there will **not** be an initial NODE_CONTINUE.
        */
        TSLexer *lexer,
        Scanner *scanner,
        _SolParseState *parse_state
) {
    if (_ensure_indent_info(scanner, parse_state->lookahead_at_line_start)) {

        uint8_t previous_node_depth;
        if (scanner->node_stack->size > 0) {
            previous_node_depth = (
                ((Node *)*array_back(scanner->node_stack))->node_depth);
        } else {
            previous_node_depth = 0;
        }

        uint16_t indentation_chars_found = parse_state->indentation_chars_found;
        uint16_t max_indentation_char_count = (
            (previous_node_depth + 1) * scanner->indentation_char_repetitions);

        // TODO: refactor into something reusable!
        while (
            !lexer->eof(lexer)
            && indentation_chars_found < max_indentation_char_count
        ) {
            if (lexer->lookahead == scanner->indentation_char) {
                ++indentation_chars_found;
                lexer->advance(lexer, false);
            } else {
                break;
            }
        }

        parse_state->indentation_chars_found = indentation_chars_found;

        // We want to check here if the next lookahead character is the indentation
        // character. If it isn't, we don't want to set the found token
        if (
            // IMPORTANT:
            // Note, again, the different check condition here!
            // purely defensive; should never be greater than
            indentation_chars_found < max_indentation_char_count
            || lexer->lookahead == scanner->indentation_char
        ) { return false; }

        parse_state->preliminary_indentation_depth = previous_node_depth + 1;
        parse_state->preliminary_token_found = true;
        parse_state->preliminary_token = NODE_BEGIN;
        return true;
    }

    // Wasn't an indentation character, so... can't be a node_begin!
    return false;
}


static bool check_for_empty_line(
        /* Empty lines can actually have meaning in cleancopy, since they
        (generally, assuming the application implements it that way) denote
        the boundaries between paragraphs. Ideally, we could parse these as
        part of the grammar; however, three things conspire against us to
        make it more pragmatic to parse them here in the scanner:
        ++  We're doing lots of other whitespace shenanigans, and it's easy
            to accidentally get into conflict situations
        ++  The regex grammar doesn't support assertions (so we can't detect
            being at the beginning of the line)
        ++  we can't have zero-length matches, so we can't define an empty
            line as a newline followed by 0 or more whitespace characters
            followed by a newline
        */
        TSLexer *lexer,
        Scanner *scanner,
        _SolParseState *parse_state
) {
    while (
        !lexer->eof(lexer)
        && is_horizontal_whitespace(lexer->lookahead)
    ) {
        lexer->advance(lexer, false);
    }

    // Status check: we started at the beginning of the line and advanced
    // through either the EoF or until we found the first character that
    // wasn't horizontal whitespace. But we still need to be careful, so that
    // we don't get into an infinite loop of empty lines at the EoF.

    if (lexer->eof(lexer)) {
        return true;
    }

    // Note that we DON'T want to consume the newline. This makes the rules
    // more consistent, which... I think anyways... might help somewhat with
    // stability.
    if (lexer->lookahead == NEWLINE) {
        return true;
    }

    return false;
}


static bool parse_start_of_line(
        /* We have several different tokens that are all valid at the
        start of the line, and all need to know exactly how much
        whitespace exists from the beginning of the line. However, we
        only have 1 codepoint of lookahead to deal with, **and** we
        can't rewind the lexer state to a previous codepoint. That means
        that we have an extra layer of ambiguity, especially surrounding
        empty lines -- which might be either shorter or longer than the
        other possible tokens, but are always valid at the same time --
        that we need to handle. And that's what this function does!

        Oh yeah, to further complicate things, don't forget that we can
        only mark the end of the consumed token at the current position
        of the lexer -- we can't rewind that, either!

        Note: this is extremely fragile. If you mess this up even a little
        bit, it can very quickly destroy the entire parse tree and/or result
        in infinite loops, especially at EoF -- particularly if you have a
        node_begin without a matching node_end.
        */
        TSLexer *lexer,
        Scanner *scanner,
        const bool *valid_symbols
) {
    // This should be obvious, but if we aren't at the beginning of the line,
    // these aren't the droids you're looking for. This should be redundant
    // WRT the grammar, but the interplay between the different moving parts
    // can be a little hard to reason about
    if (lexer->get_column(lexer) != 0) { return false; }
    // This is less obvious: even empty lines require an EoL at their end.
    // So if the previous token was an empty line, then still need to emit the
    // EoL for it.
    // Note that if the line has whitespace, it'll get caught by the above,
    // but if it's truly a blank line, we'll still be at column zero.
    // Also note that continuations stacking on top of continuations would be
    // doubly errorful (no EoL), so we can abort those here, too
    if (
        scanner->any_token_emitted
        // Note: NOT TRUE for node_begin and node_end!
        && (
            scanner->previous_token == EMPTY_LINE
            || scanner->previous_token == NODE_CONTINUE
        )
    ) { return false; }

    printf("... sol\n");
    _SolParseState *parse_state = ts_malloc(sizeof(_SolParseState));
    parse_state->preliminary_token_found = false;
    parse_state->preliminary_indentation_depth = 0;
    parse_state->indentation_chars_found = 0;
    parse_state->lookahead_at_line_start = lexer->lookahead;
    lexer->mark_end(lexer);

    // NOTE: order matters here! We need to go in order from least to most
    // indentation.
    if (valid_symbols[NODE_END]) {
        printf("... node end\n");
        advance_to_maybe_node_end(lexer, scanner, parse_state);
    }
    if (valid_symbols[NODE_CONTINUE]) {
        printf("... node cont\n");
        advance_to_maybe_node_continue(lexer, scanner, parse_state);
    }
    if (valid_symbols[NODE_BEGIN]) {
        printf("... node beg\n");
        advance_to_maybe_node_begin(lexer, scanner, parse_state);
    }

    // Note that indentation isn't the same as horizontal whitespace (based
    // on our grammar), so we need to preemptively mark_end if we found
    // a preliminary NODE_CONTINUE so that we keep its position in case of
    // non-indentation whitespace that doesn't last until the end of the
    // line
    // Important: this depends upon node_continue checking for
    // whitespace ahead of the last lookahead character. Otherwise,
    // you could accidentally have consumed more whitespace during
    // check_for_empty_line, and get into an error state.
    if (
        parse_state->preliminary_token_found
        && parse_state->preliminary_token == NODE_CONTINUE
    ) {
        lexer->mark_end(lexer);
    }

    // !!!!! IMPORTANT NOTE FOR THE FOLLOWING !!!!!
    // If the main scanner function already marked us as at the EoF, that
    // means we're on our second pass "consuming" the EoF. At this point, the
    // only remaining tokens we can emit are code_ends. **Anything else will
    // probably cause an infinite loop.**

    // We may or may not have found a preliminary token, but we still need to
    // check to see if the whole line is empty, since this could have more
    // (or less!) whitespace than any of the above.
    if (
        !scanner->eof_eol_emitted
        && valid_symbols[EMPTY_LINE]
        && check_for_empty_line(lexer, scanner, parse_state)
    ){
        printf("... empty line\n");
        lexer->mark_end(lexer);
        // Early return here, to override the preliminary token found. Also
        // be sure to mark the end, so that we advance until the start of the
        // next line, and don't get stuck in an infinite loop.
        emit_token(lexer, scanner, EMPTY_LINE);
        ts_free(parse_state);
        return true;
    }

    // No early return, so no empty line. Check to see if we found a token.
    // If so, we need to update the lex state; if not, return false.
    if (parse_state->preliminary_token_found) {
        // We need to be really careful that these are ALWAYS emitted at the
        // EoF, regardless of what happens, so we handle these separately.
        if (parse_state->preliminary_token == NODE_END) {
            // Note: since treesitter only supports one token at a time, we're
            // just going to pop the current node off the stack, set the found
            // token, and re-parse the exact same indentation repeatedly until
            // we've popped the correct number of nodes. This is maybe a little
            // wasteful, but it should be very robust.
            pop_and_free_node(scanner);

            emit_token(lexer, scanner, parse_state->preliminary_token);
            ts_free(parse_state);
            return true;

        // For all other zero-width tokens, however, we need to make sure that
        // we haven't already processed the EoF, lest we get stuck in an
        // infinite loop of mismatched expectations between scanner and parser
        } else if (
            !scanner->eof_eol_emitted
        ){
            if (parse_state->preliminary_token == NODE_BEGIN) {
                push_node(scanner, parse_state->preliminary_indentation_depth);
            }

            // Note: we did mark_end for the NODE_CONTINUE already!
            emit_token(lexer, scanner, parse_state->preliminary_token);
            ts_free(parse_state);
            return true;
        }

        printf("... ptf, ret false\n");
        ts_free(parse_state);
        return false;
    }

    printf("... end, ret false\n");
    ts_free(parse_state);
    return false;
}


static bool parse_eol(
        /* We need to parse the EoL externally for two reasons: first of
        all, the interplay with empty lines -- which might be a
        zero-length token between two newlines -- is very tricky.
        Second, we need to be sure to always emit a newline at the end
        of the file, which the normal treesitter lexer can't do.
        */
        TSLexer *lexer,
        Scanner *scanner,
        const bool *valid_symbols
) {
    if (lexer->lookahead == NEWLINE) {
        lexer->advance(lexer, false);
        emit_token(lexer, scanner, EOL);
        printf("...normal eol\n");
        return true;
    }
    // As mentioned in the docstring, the point here is that we ALWAYS need
    // to emit exactly one EoL at the EoF.
    if (
        lexer->eof(lexer)
        && !scanner->eof_eol_emitted
    ) {
        emit_token(lexer, scanner, EOL);
        scanner->eof_eol_emitted = true;
        printf("...eof eol\n");
        return true;
    }

    printf("...parse eol about to ret false\n");
    printf("...eol emitted? %d\n", scanner->eof_eol_emitted);
    return false;
}


static bool parse_flag_node_def(
        /* Treesitter doesn't recognize ambiguities in terminals, so it
        never notices conflicts between ``>``, which is generally
        permissible in node content **except** at the start of the line,
        and the node marker, which is only permissible at the start of
        the line.

        We use this zero-width token as a flag, to force the parse tree
        to be invalid for node content, and therefore switch over to
        parsing a node definition.
        */
        TSLexer *lexer,
        Scanner *scanner,
        const bool *valid_symbols
) {
    if (lexer->lookahead == NODEDEF_SYMBOL) {
        emit_token(lexer, scanner, FLAG_NODE_DEF);
        return true;
    }
    return false;
}


static bool parse_nih_whitespace(
        /* Non-indentation horizontal whitespace is used in various
        places, typically as an optional visual divider. We keep it
        within the external scanner so that we always have an exact and
        consistent definition of horizontal whitespace characters, but
        note that it doesn't (strictly speaking) need to be the same as
        the indentation character.
        */
        TSLexer *lexer,
        Scanner *scanner,
        const bool *valid_symbols
) {
    if (
        lexer->get_column(lexer) != 0
        && is_horizontal_whitespace(lexer->lookahead)
    ) {
        lexer->advance(lexer, false);
        emit_token(lexer, scanner, NIH_WHITESPACE);
        return true;
    }
    return false;
}


bool tree_sitter_cleancopy_external_scanner_scan(
        /* TODO: we need to fix the EOF handling here, because it currently,
        I'm pretty sure, will result in infinite loops if you need to pop off
        multiple nodes at the end of the file. The reason is that you have
        exactly two passes through the end, but you can only emit one token
        at a time, so you need to repeatedly pass through here an indeterminate
        number of times before you **actually** hit the eof.

        Additionally, the EoF sentinel doesn't appear to do anything, so...
        maybe consider removing it? or emit it earlier to force an error
        condition or something? you might be able to tie that into the above,
        so that if you're done with any node_ends that might have come up at
        eof, but you still see nodes, then emit an early eof to force an error
        condition?
        */
        void *payload,
        TSLexer *lexer,
        const bool *valid_symbols
) {
    printf("!!! in scanner\n");
    Scanner *scanner = (Scanner *)payload;
    // As per treesitter docs, the first thing that happens when treesitter
    // encounters a parse error is to call the external scanner with all tokens
    // valid. We're not currently set up to handle that, so simply return false.
    // NOTE: if you see an infinite loop during parsing, and this line isn't up
    // top, THIS MIGHT BE THE CAUSE!
    if (valid_symbols[_ERROR_SENTINEL]) { 
        printf("!!! ERROR SENTINEL!\n");
        return false; }

    // This is purely defensive against infinite loops, though it doesn't seem
    // to really help for many of them... ^^le sigh^^
    if (scanner->post_eof) {
        printf("!!! after post eof!!!\n");
        return false; }

    // This needs to be first, but otherwise, order shouldn't (I don't think?)
    // matter.
    if (
        includes_sol_symbols(valid_symbols)
        && parse_start_of_line(lexer, scanner, valid_symbols)
    ) { return true; }

    // Only three token types are permissible at the EoF:
    // ++  a maximum of one empty-line token
    // ++  a maximum of one EoL
    // ++  all remaining node-end tokens
    // Therefore, we set at_eof AFTER handling start-of-line symbols and EoL,
    // allowing any EoF empty-line token (and the **mandatory** EoL) to be
    // emitted exactly once. Then, the internal parse_start_of_line logic will
    // prevent it from being issued again, based on the ``at_eof`` flag.

    if (
        valid_symbols[EOL]
        && parse_eol(lexer, scanner, valid_symbols)
    ) { return true; }

    // Just because we're at the EoF, doesn't mean we're out of tokens.
    // We still have a number of possible zero-width tokens. However, we need
    // to be REALLY careful here, or we'll end up in an infinite loop at the
    // end of parsing.
    if (lexer->eof(lexer)) {
        // The first time we hit the EoF, we won't have marked it yet, because
        // we'll just have issued the EoF EoL.
        // Note that we can't fold this into the parse_eol check, because
        // that advances the parse cursor. That will cause us to always skip
        // an EoF empty line, which isn't what we want.
        if (!scanner->at_eof){
            printf("!!! at eof, setting at_eof!!!\n");
            scanner->at_eof = true;

        // The whole point of post_eof is to mark the fact that we've successfully
        // emitted all of the zero-width tokens that could possibly show up.
        // Therefore, this **needs** to be after all of the rest of the parsing.
        } else {
            scanner->post_eof = true;
        }

        if (valid_symbols[_EOD_SENTINEL]){
            printf("!!! eod sentinel\n");
            emit_token(lexer, scanner, _EOD_SENTINEL);
            return true;
        }

    // But do note that if we're at_eof, all other tokens are invalid, and
    // should be skipped (to help avoid errors and weird states)
    } else {
        if (
            valid_symbols[FLAG_NODE_DEF]
            && parse_flag_node_def(lexer, scanner, valid_symbols)
        ) { return true; }

        if (
            valid_symbols[NIH_WHITESPACE]
            && parse_nih_whitespace(lexer, scanner, valid_symbols)
        ) { return true; }
    }

    return false;
}


//////////////////////////////////////////////////////////////////////////////
// STATE DE/SERIALIZATION
//////////////////////////////////////////////////////////////////////////////
unsigned tree_sitter_cleancopy_external_scanner_serialize(
        void *payload,
        char *buffer
) {
    Scanner *scanner = (Scanner *)payload;
    size_t buffer_offset = 0;

    memcpy(
        &buffer[buffer_offset],
        &scanner->indentation_char,
        _SCANNER_FIELD_LENGTHS[0]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[0];

    memcpy(
        &buffer[buffer_offset],
        &scanner->indentation_char_repetitions,
        _SCANNER_FIELD_LENGTHS[1]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[1];

    memcpy(
        &buffer[buffer_offset],
        &scanner->any_token_emitted,
        _SCANNER_FIELD_LENGTHS[2]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[2];

    memcpy(
        &buffer[buffer_offset],
        &scanner->eof_eol_emitted,
        _SCANNER_FIELD_LENGTHS[3]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[3];

    memcpy(
        &buffer[buffer_offset],
        &scanner->at_eof,
        _SCANNER_FIELD_LENGTHS[4]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[4];

    memcpy(
        &buffer[buffer_offset],
        &scanner->post_eof,
        _SCANNER_FIELD_LENGTHS[5]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[5];

    memcpy(
        &buffer[buffer_offset],
        &scanner->previous_token,
        _SCANNER_FIELD_LENGTHS[6]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[6];

    unsigned node_stack_count = scanner->node_stack->size;
    size_t node_size = sizeof(Node);
    size_t node_stack_size = node_size * node_stack_count;
    memcpy(
        &buffer[buffer_offset],
        &node_stack_size,
        sizeof(size_t));

    for (
        unsigned node_index = 0;
        node_index < node_stack_count;
        ++node_index
    ) {
        Node *node = *array_get(scanner->node_stack, node_index);
        memcpy(
            &buffer[buffer_offset],
            node,
            node_size);
        buffer_offset += node_size;
    }
    return buffer_offset;
}


void tree_sitter_cleancopy_external_scanner_deserialize(
        void *payload,
        char *buffer,
        unsigned length
) {
    Scanner *scanner = (Scanner *)payload;
    array_init(scanner->node_stack);

    if (length == 0) { return; }

    size_t buffer_offset = 0;

    memcpy(
        &scanner->indentation_char,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[0]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[0];

    memcpy(
        &scanner->indentation_char_repetitions,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[1]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[1];

    memcpy(
        &scanner->any_token_emitted,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[2]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[2];

    memcpy(
        &scanner->eof_eol_emitted,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[3]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[3];

    memcpy(
        &scanner->at_eof,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[4]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[4];

    memcpy(
        &scanner->post_eof,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[5]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[5];

    memcpy(
        &scanner->previous_token,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[6]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[6];

    unsigned node_stack_count = scanner->node_stack->size;
    size_t node_size = sizeof(Node);
    size_t node_stack_size = node_size * node_stack_count;
    memcpy(
        &node_stack_size,
        &buffer[buffer_offset],
        sizeof(size_t));

    // TODO: we're not currently using the stack size for anything, so... we
    // could omit it, use it for a sanity check, etc
    while (buffer_offset < length) {
        Node *copied_node = ts_malloc(node_size);
        memcpy(
            copied_node,
            &buffer[buffer_offset],
            node_size);
        array_push(scanner->node_stack, copied_node);
        buffer_offset += node_size;
    }
}


//////////////////////////////////////////////////////////////////////////////
// GC
//////////////////////////////////////////////////////////////////////////////


static uint8_t _peek_node_depth(
        /* Use this to check what the node depth of the upcoming/current
        line is **without consuming any of the parse buffer.**

        Note that this requires the indentation info to already be set
        on the scanner.
        */
        TSLexer *lexer,
        Scanner *scanner
) {
    lexer->mark_end(lexer);

    uint8_t indentation_chars_found = 0;
    while (
        !lexer->eof(lexer)
        && lexer->lookahead == scanner->indentation_char
    ) {
        ++indentation_chars_found;
        lexer->advance(lexer, false);
    }

    // Note that, since we're working with integers, this will round towards
    // 0, meaning that we'll automatically round down to the nearest FULL
    // indentation level -- which is exactly what we want
    return indentation_chars_found / scanner->indentation_char_repetitions;
}


static bool _consume_indentation(
        TSLexer *lexer,
        Scanner *scanner,
        uint8_t node_depth
) {
    // Because we're about to be advancing the lexer, in case we don't find
    // the correct indentation, we do this first, so we don't consume anything
    // in the error case (note: I'm not 100% sure this is necessary!)
    lexer->mark_end(lexer);

    uint8_t indentation_chars_consumed = 0;
    uint8_t indentation_depth = (
        scanner->indentation_char_repetitions * node_depth);
    while (indentation_chars_consumed < indentation_depth) {
        if (lexer->eof(lexer)) {
            return false;
        } else if (lexer->lookahead == scanner->indentation_char) {
            lexer->advance(lexer, false);
            ++indentation_chars_consumed;
        } else {
            return false;
        }
    }

    // We got this far. We consumed all of the indentation we expected without
    // error, so we can update the endpoint and return true.
    lexer->mark_end(lexer);
    return true;
}
