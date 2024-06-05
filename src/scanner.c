#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include <assert.h>
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
    // We use this to force examination of metadata declarations to figure out
    // if it's an embed node
    _NODE_METADATA_SENTINEL,
    // We use this for state management re: pending nodes
    NODE_EMPTY,
    FLAG_EMBED,
    NODE_DEF,
    EOL,
    EMPTY_LINE,
    NIH_WHITESPACE,
    NODE_CONTINUE,
    NODE_BEGIN,
    NODE_END,
    EoF,
    AUTOCLOSE_WARNING,
} TokenType;
const char* _TokenNames[] = {
    "_ERROR_SENTINEL",
    "_NODE_METADATA_SENTINEL",
    "NODE_EMPTY",
    "FLAG_EMBED",
    "NODE_DEF",
    "EOL",
    "EMPTY_LINE",
    "NIH_WHITESPACE",
    "NODE_CONTINUE",
    "NODE_BEGIN",
    "NODE_END",
    "EoF",
    "AUTOCLOSE_WARNING"};


const TokenType SOL_SYMBOLS[] = {
    EMPTY_LINE,
    NODE_CONTINUE,
    NODE_BEGIN,
    NODE_END
};


//////////////////////////////////////////////////////////////////////////////
// STRING/UNICODE HELPERS
//////////////////////////////////////////////////////////////////////////////
static const int32_t SPACE_CHAR[] = {
    // See https://www.fileformat.info/info/unicode/category/Zs/list.htm
    0x0020,
    0x00A0,
    0x1680,
    0x2000,
    0x2001,
    0x2002,
    0x2003,
    0x2004,
    0x2005,
    0x2006,
    0x2007,
    0x2008,
    0x2009,
    0x200A,
    0x202F,
    0x205F,
    0x3000,};
static const int32_t TAB_CHAR[] = {
    0x0009,};
static const int32_t NEWLINE = 0x000A;
static const int32_t ZWSP = 0x200B;
static const int32_t ZWNBSP = 0xFEFF;
static const int32_t NODEDEF_SYMBOL = 0x003E;
static const int32_t EMPTY_NODE_SYMBOL = 0x003C;

static const int32_t EMBED_MAGIC[] = {  // __embed__
    0x005F, 0x005F,
    0x0065, 0x006D, 0x0062, 0x0065, 0x0064,
    0x005F, 0x005F,};
static const int32_t METADATA_ASSIGNMENT_SYMBOL = 0x003A;


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
    uint8_t node_level;
    bool is_embed;
} Node;
// SUPER IMPORTANT: if you add anything here with a variable length, you'll
// need to make significant changes to de/serialization! We currently rely
// upon knowing the node size in advance before even starting to serialize the
// node stack, so that we can preface it with a total size (though I'm not
// actually sure the total size is needed, so maybe you can skip that? or,
// I suppose you could store the node COUNT first, and then the size of each
// node immediately before serializing it)


typedef struct {
    TokenType token;
    size_t advance_count;
    bool skip_mark;
} PendingToken;


// IMPORTANT: if you change anything here, YOU MUST ALSO UPDATE SERIALIZATION!
typedef struct {
    // Together, these determine how indentation is determined for a file. It
    // must always be the same indentation character used, and it must always
    // be repeated the same number of times.
    int32_t indentation_char;
    uint8_t indentation_char_repetitions;

    // The token backlog is FIFO, but the array we're using is a stack.
    // Therefore, when we have a token backlog, instead of creating a new copy
    // of it every time we need to pop from the LEFT of the array, we simply
    // advance this counter. Once we've processed the whole backlog, we can
    // set this to zero and clear the backlog.
    uint8_t token_backlog_index;

    // We use this to emit the embedded node flag out-of-order with the
    // rest of the node metadata, which solves a bunch of problems with how
    // treesitter expects the grammar to be
    bool pending_embed_node;

    // We use this to indicate to the EoF handler that we detected an empty
    // line before this. We can't rely on the lexer to tell us this is the
    // case, because it always reports a column of 0 at EoF.
    bool eof_detected_immediately_after_eol;
    // We use this to denote that we've already processed the EoF and added
    // any trailing zero-length tokens to the backlog. If this is true, and
    // the token backlog is consumed, then parsing is finished.
    bool post_eof;

    Array(Node *) * node_stack;
    Array(PendingToken *) * token_backlog;
} Scanner;


size_t _SCANNER_FIELD_LENGTHS[] = {
    sizeof(int32_t),
    sizeof(uint8_t),
    sizeof(uint8_t),
    sizeof(bool),
    sizeof(bool),
    sizeof(bool)};


//////////////////////////////////////////////////////////////////////////////
// MEMORY MANAGEMENT
//////////////////////////////////////////////////////////////////////////////
void *tree_sitter_cleancopy_external_scanner_create(
        void
) {
    // printf("##### PARSE START #####\n\n");
    Scanner *scanner = (Scanner *)ts_malloc(sizeof(Scanner));

    // This is how you create an empty array
    // hmm, this emits a compiler warning because the Array(Node *) is used as
    // a throwaway type to calculate a size.
    scanner->node_stack = ts_malloc(sizeof(Array(Node *)));
    scanner->token_backlog = ts_malloc(sizeof(Array(PendingToken *)));
    scanner->indentation_char = 0;
    scanner->indentation_char_repetitions = 0;
    scanner->token_backlog_index = 0;
    scanner->pending_embed_node = false;
    scanner->eof_detected_immediately_after_eol = false;
    scanner->post_eof = false;
    array_init(scanner->node_stack);
    array_init(scanner->token_backlog);

    return scanner;
}


void tree_sitter_cleancopy_external_scanner_destroy(
        void *payload
) {
    Scanner *scanner = (Scanner *)payload;

    // We need to free the nodes themselves before clearing the array, because
    // it doesn't handle this.
    for (size_t i = 0; i < scanner->node_stack->size; ++i) {
        printf("!!! WARNING: node_stack had nodes on destruction!\n");
        ts_free(*array_get(scanner->node_stack, i));
    }
    array_delete(scanner->node_stack);
    // Same goes for the token backlog.
    for (size_t i = 0; i < scanner->token_backlog->size; ++i) {
        // Note that, because the token backlog only gets cleared if we call
        // emit_from_backlog ^^with an empty backlog^^, we can expect that the
        // backlog will have token(s) on destruction. However, they should
        // already have been emitted -- otherwise we should definitely warn!
        if (i > scanner->token_backlog_index) {
            printf("!!! WARNING: token backlog not empty on destruction!\n");
        }

        ts_free(*array_get(scanner->token_backlog, i));
    }
    array_delete(scanner->token_backlog);

    ts_free(scanner);
    // printf("\n\n##### PARSE END #####\n");
}


//////////////////////////////////////////////////////////////////////////////
// HELPERS
//////////////////////////////////////////////////////////////////////////////


typedef struct {
    // Positive matches: found a specific token
    bool positive_match_found;
    // Negative matches: we know no token can be found
    bool negative_match_found;
    // Together, these describe which mutations we've done to the lexer.
    // Mostly (only?) useful for sanity-check assertions
    uint16_t lexer_col_at_start;
    bool lexer_marked;
    uint16_t lexer_last_marked_col;

    const bool *valid_symbols;
} ScanState;


static void push_node(
        /* Adds a new node to the scanner's node stack, growing the stack
        automatically.
        */
        Scanner *scanner,
        uint8_t node_level,
        bool is_embed
) {
    Node *node = ts_malloc(sizeof(Node));
    node->node_level = node_level;
    node->is_embed = is_embed;

    array_push(scanner->node_stack, node);
}


static void reset_backlog(
        /* One would think you could simply call
        array_clear(scanner->token_backlog) for this, but this appears
        to somehow break the scanner_destroy cleanup method (when we try
        to call ``array_delete``.) No idea why, but... hey, where there's
        a will, there's a workaround. I think this might be cleaner anyways.
        */
        Scanner *scanner
) {
    scanner->token_backlog_index = 0;

    // We can't do this one-at-a-time as we process, because it would
    // get resurrected on the next deserialization call. We have to
    // do it at the same time we clear the array.
    while (scanner->token_backlog->size > 0) {
        ts_free(array_pop(scanner->token_backlog));
    }
}


static void schedule_token(
        /* Frequently, consuming some character(s) will result in
        multiple tokens, each of which may or may not be zero-length.
        Tree-sitter, however, only supports returning a single token at
        a time. Therefore, if you find yourself needing to return
        multiple tokens, call this, and the scanner will automatically
        handle it the next time it gets called.

        **Note that you still need to emit the first token, though!**
        */
        Scanner *scanner,
        ScanState *scan_state,
        TokenType token,
        size_t advance_count,
        bool already_consumed
) {
    // Note that all of these are checking the pre-existing state; NOT the
    // current scheduling call. That's why we then immediately update
    // everything. This is all defensive against bugs we've written elsewhere.
    assert(advance_count == 0 || scanner->token_backlog->size == 0 || !already_consumed);
    assert(advance_count == 0 || !scan_state->positive_match_found | !already_consumed);
    assert(!scan_state->negative_match_found);
    assert(advance_count == 0 || !already_consumed || scan_state->lexer_marked);

    scan_state->positive_match_found = true;
    PendingToken *pending_token = ts_malloc(sizeof(PendingToken));
    pending_token->token = token;

    if (already_consumed){
        pending_token->advance_count = 0;
        pending_token->skip_mark = true;

    } else {
        pending_token->advance_count = advance_count;
        pending_token->skip_mark = false;
    }

    array_push(scanner->token_backlog, pending_token);
}


static void consume_advances_from_lexer(
        /* The way we have things set up, we need to explicitly call
        mark_end any time we want to consume characters from the lexer
        during scanning. This helper does that, along with a few
        bookkeeping tasks and sanity checks.
        */
        TSLexer *lexer,
        ScanState *scan_state,
        bool allow_existing_consumption
) {
    if (!allow_existing_consumption) {
        assert(
            scan_state->lexer_last_marked_col
            == scan_state->lexer_col_at_start);
    }

    lexer->mark_end(lexer);
    scan_state->lexer_last_marked_col = lexer->get_column(lexer);
    scan_state->lexer_marked = true;
}


static bool can_parse(
        /* Returns True if the scan_state allows parsing **any** of the
        passed token_types.
        */
        ScanState *scan_state,
        TokenType token_types[]
) {
    if (
        scan_state->negative_match_found
        || scan_state->positive_match_found
    ) {
        return false;
    }

    TokenType this_token;
    for (
        size_t i = 0;
        i < (sizeof(token_types) / sizeof(TokenType));
        ++i
    ) {
        this_token = token_types[i];
        if (scan_state->valid_symbols[this_token]) {
            return true;
        }
    }

    return false;
}


static void emit_token(
        /* Helper for all the bookkeeping we need to do any time we
        emit a token. **Note that the caller is still responsible for
        advancing the lexer if required!!!**
        */
        TSLexer *lexer,
        Scanner *scanner,
        TokenType token
) {
    assert(lexer->result_symbol == 0);
    printf("... emitting %s\n", _TokenNames[token]);
    lexer->result_symbol = token;
}


static bool emit_from_backlog(
        /* This works through the backlog (one token per scan pass),
        returning True if there was a token to emit.
        */
        TSLexer *lexer,
        Scanner *scanner,
        const bool *valid_symbols
) {
    uint8_t token_backlog_size = scanner->token_backlog->size;
    if (token_backlog_size > 0) {
        uint8_t token_backlog_index = scanner->token_backlog_index;
        // We've worked through the whole backlog; time to reset it
        // Note: >= is purely defensive here; should only ever be ==
        if (token_backlog_index >= token_backlog_size) {
            // printf("!!! token backlog processed; clearing\n");
            reset_backlog(scanner);

            // NOTE NO RETURN HERE! We want to continue processing as usual.

        } else {
            PendingToken *pending_token = *array_get(
                scanner->token_backlog, token_backlog_index);

            // Note that, because of how treesitter works -- try impossible
            // branches and then backtrack on failure -- we may find ourselves
            // in situations where the pending token isn't a valid symbol. In
            // that case... well, we can just return the wrong token, I guess,
            // and let tree sitter deal with its own mess
            if (!valid_symbols[pending_token->token]) {
                printf(
                    "!!! backlog token not valid at position; forcing backtrack\n");
            }

            // printf(
            //     "!!! processing token backlog %d: %d\n",
            //     token_backlog_index, pending_token->token);
            scanner->token_backlog_index += 1;

            if (!pending_token->skip_mark){
                for (size_t i = 0; i < pending_token->advance_count; ++i) {
                    lexer->advance(lexer, false);
                }
                lexer->mark_end(lexer);
            }
            emit_token(lexer, scanner, pending_token->token);

            // Note that we can't free the memory for each individual pending
            // token here, since it would just get re-allocated on the next
            // deserialization, because we're not mutating the actual array
            // until the whole thing is consumed.

            return true;
        }
    }

    return false;
}

//////////////////////////////////////////////////////////////////////////////
// SCANNING
//////////////////////////////////////////////////////////////////////////////


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
    
    uint8_t current_node_level = (
        ((Node *)*array_back(scanner->node_stack))->node_level);
    if (current_node_level == 0) { return false; }

    // Keep in mind that we might be dedenting multiple levels, so this might
    // be less than this
    uint16_t max_indentation_char_count = (
        scanner->indentation_char_repetitions * (current_node_level - 1));
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
        || ((Node *)*array_back(scanner->node_stack))->node_level == 0
    ) {
        // We want to make sure that the next character **is NOT** indentation;
        // otherwise, it's not a valid node continue. That will either be a
        // node_begin or an error state; either way, we don't want to mark a
        // preliminary token. But assuming that's not the case, we can just
        // continue on.
        // If the next "character" is an EoF, then technically this is
        // redundant with the emptyline handling, but we can be defensive and
        // also not set the preliminary token in that case.
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
        Node *current_node = *array_back(scanner->node_stack);

        uint16_t max_indentation_char_count = (
            current_node->node_level * scanner->indentation_char_repetitions);

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
            || (
                // Note: if this is an embedded node, we don't care about extra
                // indentation
                !current_node->is_embed
                && lexer->lookahead == scanner->indentation_char
            )
        ) { return false; }

        parse_state->preliminary_indentation_depth = current_node->node_level;
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

        bool is_embed;
        uint8_t current_node_level;
        if (scanner->node_stack->size > 0) {
            Node *current_node = *array_back(scanner->node_stack);

            // This should be obvious, but if we're embedded, we definitely don't
            // want to be creating new nodes every time there's an indentation
            if (current_node->is_embed) { 
                printf("ret false for node begin\n");
                return false; }

            current_node_level = current_node->node_level;
            is_embed = current_node->is_embed;
        } else {
            current_node_level = 0;
            is_embed = false;
        }

        uint16_t indentation_chars_found = parse_state->indentation_chars_found;
        uint16_t max_indentation_char_count = (
            (current_node_level + 1) * scanner->indentation_char_repetitions);

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

        parse_state->preliminary_indentation_depth = current_node_level + 1;
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
    // through ONLY whitespace characters either until we reached the EoF
    // or until we found the first character that wasn't horizontal whitespace.
    // Therefore, if the next character is a newline (or EoF), then we know
    // the whole line was empty, and we should preempt all of the rest of the
    // start-of-line whitespace processing.
    // Note that we don't want to consume a newline; that's handled within the
    // EoL parser (or injected by the EoF parser as a zero-width token).
    if (lexer->lookahead == NEWLINE || lexer->eof(lexer)) {
        return true;
    }

    return false;
}


static void handle_start_of_line(
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

        Note that EoF node closing is handled within the dedicated EoF
        parser, ie, ^^NOT here.^^
        */
        TSLexer *lexer,
        Scanner *scanner,
        ScanState *scan_state
) {
    // This should be obvious, but if we aren't at the beginning of the line,
    // these aren't the droids you're looking for. This should be redundant
    // WRT the grammar, but the interplay between the different moving parts
    // can be a little hard to reason about
    if (
        lexer->get_column(lexer) != 0
        || lexer->eof(lexer)
    ) { return; }

    _SolParseState *parse_state = ts_malloc(sizeof(_SolParseState));
    parse_state->preliminary_token_found = false;
    parse_state->preliminary_indentation_depth = 0;
    parse_state->indentation_chars_found = 0;
    parse_state->lookahead_at_line_start = lexer->lookahead;

    // NOTE: order matters here! We need to go in order from least to most
    // indentation.
    if (scan_state->valid_symbols[NODE_END]) {
        advance_to_maybe_node_end(lexer, scanner, parse_state);
    }
    if (scan_state->valid_symbols[NODE_CONTINUE]) {
        advance_to_maybe_node_continue(lexer, scanner, parse_state);
    }
    if (scan_state->valid_symbols[NODE_BEGIN]) {
        advance_to_maybe_node_begin(lexer, scanner, parse_state);
    }

    // Note that, based on our grammar, indentation (used to find
    // node_continue) isn't the same as horizontal whitespace (used to find
    // empty lines), so we need to call mark_end BEFORE checking for an empty
    // line if we found a preliminary NODE_CONTINUE, so that we keep its
    // position in case of non-indentation whitespace that doesn't last until
    // the end of the line.
    // Important: this depends upon node_continue checking for
    // whitespace ahead of the last lookahead character. Otherwise,
    // you could accidentally have consumed more whitespace during
    // check_for_empty_line, and get into an error state.
    if (
        parse_state->preliminary_token_found
        && parse_state->preliminary_token == NODE_CONTINUE
    ) {
        consume_advances_from_lexer(lexer, scan_state, false);
    }

    // We may or may not have found a preliminary token, but we still need to
    // check to see if the whole line is empty, since this could have more
    // (or less!) whitespace than any of the above.
    if (
        scan_state->valid_symbols[EMPTY_LINE]
        && check_for_empty_line(lexer, scanner, parse_state)
    ){
        // Early return here, to override the preliminary token found. Also
        // be sure to mark the end, so that we advance until the start of the
        // next line, and don't get stuck in an infinite loop. DO NOT schedule
        // the newline here, even if at EoF -- let the EoF handler do that!
        consume_advances_from_lexer(lexer, scan_state, true);
        schedule_token(
            scanner,
            scan_state,
            EMPTY_LINE,
            scan_state->lexer_last_marked_col - scan_state->lexer_col_at_start,
            true);

    // No empty line. If we found any other token, we might have some
    // additional bookkeeping to do before scheduling it.
    } else if (parse_state->preliminary_token_found) {
        // Schedule the relevant token first, do the bookkeeping afterwards.
        // This allows us to emit, for example, the FLAG_EMBED **after** the
        // NODE_BEGIN, which makes the grammar simpler.
        // Note: we consumed advances for the NODE_CONTINUE already!
        schedule_token(
            scanner,
            scan_state,
            parse_state->preliminary_token,
            scan_state->lexer_last_marked_col - scan_state->lexer_col_at_start,
            true);

        // We need to be really careful that these are ALWAYS emitted at the
        // EoF, regardless of what happens, so we handle these separately.
        if (parse_state->preliminary_token == NODE_END) {
            assert(scanner->node_stack->size > 0);
            Node *node_to_end = array_pop(scanner->node_stack);
            // We'll need a helper at some point to close out any misc richtext
            // formatting that might be open still; that will go right here
            ts_free(node_to_end);

        // For all other zero-width tokens, however, we need to make sure that
        // we haven't already processed the EoF, lest we get stuck in an
        // infinite loop of mismatched expectations between scanner and parser
        } else if (parse_state->preliminary_token == NODE_BEGIN) {
            push_node(
                scanner,
                parse_state->preliminary_indentation_depth,
                scanner->pending_embed_node);

            // We may have previously detected a metadata assignment for an
            // __embed__ node, which means we need to now, finally, schedule
            // the delayed token for it
            if (scanner->pending_embed_node) {
                schedule_token(scanner, scan_state, FLAG_EMBED, 0, true);
            }

            scanner->pending_embed_node = false;
        }
    }

    ts_free(parse_state);
}


static void handle_eof(
        /* Treesitter doesn't give us a formal EoF token, but we may
        need to do a bunch of zero-width tokens here. Therefore, we call
        this as soon as we detect an EoF, and handle everything here.

        Originally, this logic was spread out between the other parsers,
        but that got **very** unwieldy and bug-prone. So instead, I've
        centralized it here, so that it's clear what's going on. It
        doesn't feel particularly DRY, but it's ^^just different enough^^
        that is was causing a ton of headaches trying to implement it
        elsewhere.
        */
        TSLexer *lexer,
        Scanner *scanner,
        ScanState *scan_state
) {
    // We use this in exactly one place: in the EoL handler, if we -- as the
    // name suggests -- find the EoF immediately after the EoL. In that case,
    // we emit the EoL, **but hold off on the empty line** so that it can be
    // reordered after closing stuff. However, in all other cases, we need to
    // close out the current line first.
    if (!scanner->eof_detected_immediately_after_eol){
        schedule_token(scanner, scan_state, EOL, 0, true);
    }

    // If you decide you want to make empty lines part of the parent block
    // instead of the child block, you can simply slide this before the above
    // EoF empty-and/or-EoL block
    if (scanner->node_stack->size > 0) {
        uint8_t current_indentation_level = (
            ((Node *)*array_back(scanner->node_stack))->node_level);

        while (current_indentation_level > 0) {
            Node *node_to_end = array_pop(scanner->node_stack);
            assert(node_to_end->node_level == current_indentation_level);
            schedule_token(scanner, scan_state, NODE_END, 0, true);
            ts_free(node_to_end);
            current_indentation_level -= 1;
        }
    }

    assert(scanner->node_stack->size == 0);

    // There are 3 ways an EoF can be spelled:
    // ++  abruptly, at the end of a line with content
    // ++  the traditional way, with an empty line
    // ++  the "it looks traditional but it isn't" way, with one last line
    //     full just of whitespace
    // The first case doesn't need an empty line, just an EoL.
    // The second case needs an empty line + EoL. This is detected by the
    // EoL handler ^^for the previous EoL^^, and the empty line token is
    // scheduled there. So in that case, we just need an EoL.
    // The third case gets the empty line from the start-of-line handler, and
    // then a newline from here.
    // Note: lexer->get_column **always returns 0 at EoF!**
    if (scanner->eof_detected_immediately_after_eol) {
        schedule_token(scanner, scan_state, EMPTY_LINE, 0, true);
        schedule_token(scanner, scan_state, EOL, 0, true);
    }
}


static void detect_and_schedule_eol(
        /* We need to parse the EoL externally for two reasons: first of
        all, the interplay with empty lines -- which might be a
        zero-length token between two newlines -- is very tricky.
        Second, we need to detect in advance if an EoF immediately follows
        an EoL, indicating a trailing empty line.
        */
        TSLexer *lexer,
        Scanner *scanner,
        ScanState *scan_state
) {
    if (lexer->lookahead == NEWLINE) {
        // NOTE: we actually **need** to advance here, because we need to
        // check for the immediately following EoF immediately after
        // scheduling!
        lexer->advance(lexer, false);
        consume_advances_from_lexer(lexer, scan_state, false);
        schedule_token(scanner, scan_state, EOL, 1, true);

        // Note:
        // ++  the EoF handler can't read backwards
        // ++  the lexer always returns a column of 0 at EoF
        // ++  start-of-line handling gets skipped at EoF
        // Therefore, we need to store this on the scanner, so that it knows
        // to emit an empty line (but we don't want to schedule it here,
        // because the EoF handler can reorder it with respect to other
        // zero-width tokens, ex node_ends)
        if (lexer->eof(lexer)) {
            scanner->eof_detected_immediately_after_eol = true;
        }
    }
}


static void detect_and_schedule_node_def(
        /* So... the problem is, treesitter doesn't have a robust
        mechanism for defining terminal precedence. So we can't say
        "try the node def symbol before trying anything else". And
        because an empty node declaration is indistinguishable from
        normal node content without that preemption, it means that
        treesitter never detects that it's down the wrong branch of the
        parse tree. Therefore, we need a way to define terminal
        precedence.

        Luckily, the external scanner is always called first, before any
        internal lexing. This lets us hard-code the precedence within
        the order of detection calls within the external_scan entrypoint.
        */
        TSLexer *lexer,
        Scanner *scanner,
        ScanState *scan_state
) {
    if (lexer->lookahead == NODEDEF_SYMBOL) {
        schedule_token(scanner, scan_state, NODE_DEF, 1, false);
    }
}


static void detect_and_schedule_empty_node(
        /* Because of the way we handle embedded nodes -- where we need to
        store scanner state of "pending embedded node" and then replay the
        embedded node flag ^^out of order^^ -- we need to store the upcoming
        node state on the scanner. However, we also need to clear it in case
        of an empty node, or the next child node could erroneously be marked
        as an embedded node. Therefore, we handle the entire empty node
        marker here.
        */
        TSLexer *lexer,
        Scanner *scanner,
        ScanState *scan_state
) {
    if (lexer->lookahead == EMPTY_NODE_SYMBOL) {
        scanner->pending_embed_node = false;
        schedule_token(scanner, scan_state, NODE_EMPTY, 1, false);
    }
}


static void mark_if_pending_embedding(
        /* This takes advantage of our metadata sentinel to examine the
        upcoming metadata key. If it matches the EMBED_MAGIC, we set the
        correct state on the scanner to indicate that the upcoming node
        is an embedded one, but we don't yet emit the token itself.
        */
        TSLexer *lexer,
        Scanner *scanner,
        ScanState *scan_state
) {
    for (
        size_t i = 0;
        i < (sizeof(EMBED_MAGIC) / sizeof(EMBED_MAGIC[0]));
        ++i
    ) {
        printf("checking char %d\n", i);
        if (lexer->lookahead != EMBED_MAGIC[i]) {
            printf("no embed found\n");
            return; }
        lexer->advance(lexer, false);
    }

    if (lexer->lookahead == METADATA_ASSIGNMENT_SYMBOL) {
        printf("embed found\n");
        scanner->pending_embed_node = true;
    }

    schedule_token(scanner, scan_state, _NODE_METADATA_SENTINEL, 0, true);
}


static void detect_and_schedule_nih_whitespace(
        /* Non-indentation horizontal whitespace is used in various
        places, typically as an optional visual divider. We keep it
        within the external scanner so that we always have an exact and
        consistent definition of horizontal whitespace characters, but
        note that it doesn't (strictly speaking) need to be the same as
        the indentation character.
        */
        TSLexer *lexer,
        Scanner *scanner,
        ScanState *scan_state
) {
    if (
        lexer->get_column(lexer) != 0
        && is_horizontal_whitespace(lexer->lookahead)
    ) {
        schedule_token(scanner, scan_state, NIH_WHITESPACE, 1, false);
    }
}


bool tree_sitter_cleancopy_external_scanner_scan(
        /* TODO: refactor start-of-line flags into separate mechanism within
        the SoL handler that schedules tokens, instead of parsing them
        separately
        */
        void *payload,
        TSLexer *lexer,
        const bool *valid_symbols
) {
    Scanner *scanner = (Scanner *)payload;

    // As per treesitter docs, the first thing that happens when treesitter
    // encounters a parse error is to call the external scanner with all tokens
    // valid. We're not currently set up to handle that, so simply return false.
    // NOTE: if you see an infinite loop during parsing, and this line isn't up
    // top, THIS MIGHT BE THE CAUSE!
    if (valid_symbols[_ERROR_SENTINEL]) { 
        printf("!!! ERROR SENTINEL!\n");
        return false; }

    if (emit_from_backlog(lexer, scanner, valid_symbols)) {
        printf("<<< from backlog!\n");
        return true; }

    ScanState *scan_state = ts_malloc(sizeof(ScanState));
    scan_state->positive_match_found = false;
    scan_state->negative_match_found = false;
    scan_state->lexer_col_at_start = lexer->get_column(lexer);
    scan_state->lexer_marked = false;
    scan_state->valid_symbols = valid_symbols;
    scan_state->lexer_last_marked_col = scan_state->lexer_col_at_start;
    lexer->mark_end(lexer);

    // Once we hit this, we've scheduled **and emitted** all of the meaningful
    // tokens. The only thing we have left to do is emit the _EOD sentinel to
    // conclude the document.
    // Note: post_eof is set in the FOLLOWING block, when we first encounter
    // the eof.
    if (scanner->post_eof) {
        // printf(">>> found post_eof\n");
        schedule_token(scanner, scan_state, EoF, 0, false);

    } else {

        // Just because we're at the EoF, doesn't mean we're out of tokens.
        // We still have a number of possible zero-width tokens. However, we need
        // to be REALLY careful here, or we'll end up in an infinite loop at the
        // end of parsing. This is our last chance to schedule any remaining
        // tokens; we can't come back to this block without having an infinite
        // loop at the EoF.
        if (lexer->eof(lexer)) {
            scanner->post_eof = true;
            handle_eof(lexer, scanner, scan_state);

        // But do note that if we're at the EoF, all other tokens are invalid, and
        // should be skipped (to help avoid errors and weird states)
        } else {
            // printf("--- checkpoint1. valid symbols:\n");
            // for (
            //     size_t i = _ERROR_SENTINEL;
            //     i <= AUTOCLOSE_WARNING;
            //     i++
            // ) {
            //     printf("    %s: %d\n", _TokenNames[i], valid_symbols[i]);
            // }

            // The start-of-line handler always needs to be called first, since
            // it's dependent on being, well, at the start of the line.
            if (can_parse(scan_state, SOL_SYMBOLS)) {
                handle_start_of_line(lexer, scanner, scan_state);}
            // The actual empty node symbol is handled by the treesitter-internal
            // lexer, but we need to do some state cleanup (to remove the pending
            // node info from the scanner).
            // I'm not 100% sure why, but currently this needs to be before the
            // node metadata sentinel.
            if (can_parse(scan_state, (TokenType[1]){NODE_EMPTY})){
                detect_and_schedule_empty_node(lexer, scanner, scan_state);}
            // We use this sentinel to force treesitter into our external scanner,
            // so we can examine the metadata key, and decide whether it indicates
            // a pending embed node
            if (can_parse(scan_state, (TokenType[1]){_NODE_METADATA_SENTINEL})){
                mark_if_pending_embedding(lexer, scanner, scan_state);}

            if (can_parse(scan_state, (TokenType[1]){EOL})){
                detect_and_schedule_eol(lexer, scanner, scan_state);}
            if (can_parse(scan_state, (TokenType[1]){NODE_DEF})){
                detect_and_schedule_node_def(lexer, scanner, scan_state);}
            if (can_parse(scan_state, (TokenType[1]){NIH_WHITESPACE})){
                detect_and_schedule_nih_whitespace(lexer, scanner, scan_state);}
        }
    }

    if (scan_state->positive_match_found) {
        emit_from_backlog(lexer, scanner, valid_symbols);
        ts_free(scan_state);
        return true;
    }

    ts_free(scan_state);
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
        &scanner->token_backlog_index,
        _SCANNER_FIELD_LENGTHS[2]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[2];

    memcpy(
        &buffer[buffer_offset],
        &scanner->pending_embed_node,
        _SCANNER_FIELD_LENGTHS[3]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[3];

    memcpy(
        &buffer[buffer_offset],
        &scanner->eof_detected_immediately_after_eol,
        _SCANNER_FIELD_LENGTHS[4]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[4];

    memcpy(
        &buffer[buffer_offset],
        &scanner->post_eof,
        _SCANNER_FIELD_LENGTHS[5]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[5];

    unsigned node_stack_count = scanner->node_stack->size;
    size_t node_size = sizeof(Node);
    size_t node_stack_size = node_size * node_stack_count;
    memcpy(
        &buffer[buffer_offset],
        &node_stack_size,
        sizeof(size_t));
    buffer_offset += sizeof(size_t);

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

    unsigned token_backlog_count = scanner->token_backlog->size;
    size_t pending_token_size = sizeof(PendingToken);
    size_t backlog_size = pending_token_size * token_backlog_count;
    memcpy(
        &buffer[buffer_offset],
        &backlog_size,
        sizeof(size_t));
    buffer_offset += sizeof(size_t);

    for (
        unsigned backlog_index = 0;
        backlog_index < token_backlog_count;
        ++backlog_index
    ) {
        PendingToken *pending_token = *array_get(
            scanner->token_backlog, backlog_index);
        memcpy(
            &buffer[buffer_offset],
            pending_token,
            pending_token_size);
        buffer_offset += pending_token_size;
    }

    // printf(">>> ser backlog size %d\n", scanner->token_backlog->size);
    // printf(">>> ser post_eof %d\n", scanner->post_eof);
    // for (int i = 0; i < buffer_offset; i++) {
    //     printf("%x", buffer[i]);
    // }
    // printf("\n\n");
    return buffer_offset;
}


void tree_sitter_cleancopy_external_scanner_deserialize(
        void *payload,
        char *buffer,
        unsigned length
) {
    Scanner *scanner = (Scanner *)payload;
    array_init(scanner->node_stack);
    array_init(scanner->token_backlog);

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
        &scanner->token_backlog_index,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[2]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[2];

    memcpy(
        &scanner->pending_embed_node,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[3]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[3];

    memcpy(
        &scanner->eof_detected_immediately_after_eol,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[4]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[4];

    memcpy(
        &scanner->post_eof,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[5]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[5];

    size_t node_size = sizeof(Node);
    size_t node_stack_size;
    memcpy(
        &node_stack_size,
        &buffer[buffer_offset],
        sizeof(size_t));
    buffer_offset += sizeof(size_t);

    size_t node_stack_end = buffer_offset + node_stack_size;
    while (buffer_offset < node_stack_end) {
        Node *copied_node = ts_malloc(node_size);
        memcpy(
            copied_node,
            &buffer[buffer_offset],
            node_size);
        array_push(scanner->node_stack, copied_node);
        buffer_offset += node_size;
    }

    size_t pending_token_size = sizeof(PendingToken);
    size_t backlog_size;
    memcpy(
        &backlog_size,
        &buffer[buffer_offset],
        sizeof(size_t));
    buffer_offset += sizeof(size_t);

    size_t backlog_end = buffer_offset + backlog_size;
    while (buffer_offset < backlog_end) {
        PendingToken *pending_token = ts_malloc(pending_token_size);
        memcpy(
            pending_token,
            &buffer[buffer_offset],
            pending_token_size);
        array_push(scanner->token_backlog, pending_token);
        buffer_offset += pending_token_size;
    }

    // This is currently the only real use of storing the backlog size in the
    // serialized payload -- so we can use it as a sanity check during
    // deserialization.
    assert(buffer_offset == length);
    assert(backlog_end == length);
    // printf("\n\n");
    // printf(">>> deser backlog size %d\n", scanner->token_backlog->size);
    // printf(">>> deser post_eof %d\n", scanner->post_eof);
    // for (int i = 0; i < buffer_offset; i++) {
    //     printf("%x", buffer[i]);
    // }
    // printf("\n");
}
