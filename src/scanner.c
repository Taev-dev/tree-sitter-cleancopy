#include <assert.h>
#include <stdio.h>
#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include "cleancopy_chars.h"
#include "cleancopy_utils.h"

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
    METADATA_KEY,
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
    "METADATA_KEY",
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


static bool is_space(
        int32_t lookahead
) {
    for (
        size_t i = 0;
        i < (sizeof(UNICHR_SPACE_CHAR) / sizeof(UNICHR_SPACE_CHAR[0]));
        ++i
    ) {
        if (UNICHR_SPACE_CHAR[i] == lookahead) {
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
        i < (sizeof(UNICHR_TAB_CHAR) / sizeof(UNICHR_TAB_CHAR[0]));
        ++i
    ) {
        if (UNICHR_TAB_CHAR[i] == lookahead) {
            return true;
        }
    }

    return false;
}


static bool is_horizontal_whitespace(
        int32_t lookahead
) {
    return (
        is_space(lookahead)
        || is_tab(lookahead)
        || (lookahead == UNICHR_ZWNBSP)
        || (lookahead == UNICHR_ZWSP));
}


static bool is_indentation_or_eol(
        int32_t lookahead
) {
    return lookahead == UNICHR_NEWLINE || is_space(lookahead) || is_tab(lookahead);
}


static uint8_t detect_and_advance_through_letter(
        /* This detects a letter (including any following modifier
        codepoints) and returns the number of characters consumed as
        part of it, or 0 if no letter was found.
        */
        TSLexer *lexer
) {
    uint8_t charcount = 0;
    
    // Note: the way this works in unicode is that you have one letter
    // character followed by zero or more modifiers, so that's exactly what
    // we have here
    if (CHAR_WITHIN(UNIRAN_LETTER, lexer->lookahead)){
        charcount += 1;
        lexer->advance(lexer, false);

        while (
            !lexer->eof(lexer)
            && CHAR_WITHIN(UNIRAN_LETTER_MODIFIER, lexer->lookahead)
        ) {
            charcount += 1;
            lexer->advance(lexer, false);
        }
    }

    return charcount;
}


static uint8_t detect_and_advance_through_digit(
        /* This detects a unicode digit and returns the number of
        characters consumed as part of it, or 0 if no digit was found.
        */
        TSLexer *lexer
) {
    if (CHAR_WITHIN(UNIRAN_DIGIT, lexer->lookahead)){
        lexer->advance(lexer, false);
        return 1;
    }

    return 0;
}


static uint8_t detect_and_advance_through_codepoint(
        /* This detects a specific single character, returning 1 if
        found or 0 if not. If found, it also advances the lexer.
        */
        TSLexer *lexer,
        uint32_t codepoint_to_detect
) {
    if (lexer->lookahead == codepoint_to_detect){
        lexer->advance(lexer, false);
        return 1;
    }

    return 0;
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

    // UNUSED. TODO: REMOVE!
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
    debug("##### PARSE START #####\n\n");
    Scanner *scanner = (Scanner *)ts_malloc(sizeof(Scanner));

    assert(!CHAR_WITHIN(UNIRAN_DIGIT, ' '));
    assert(!CHAR_WITHIN(UNIRAN_LETTER, ' '));
    assert(!CHAR_WITHIN(UNIRAN_LETTER_MODIFIER, ' '));
    assert(CHAR_WITHIN(UNIRAN_DIGIT, '1'));
    assert(CHAR_WITHIN(UNIRAN_LETTER, 'a'));
    assert(CHAR_WITHIN(UNIRAN_LETTER_MODIFIER, 0x300));

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
    debug("\n\n##### PARSE END #####\n");
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
        emit a token, **including all state mutation associated with the
        token. **Note that the caller is still responsible for
        advancing the lexer if required!!!**
        */
        TSLexer *lexer,
        Scanner *scanner,
        TokenType token
) {
    assert(lexer->result_symbol == 0);
    debug("... emitting %s\n", _TokenNames[token]);
    lexer->result_symbol = token;

    if (token == NODE_BEGIN) {
        uint8_t current_node_level;
        if (scanner->node_stack->size > 0){
            current_node_level = (
                (Node *)*array_back(scanner->node_stack))->node_level;
        } else {
            current_node_level = 0;
        }

        Node *node = ts_malloc(sizeof(Node));
        node->node_level = current_node_level + 1;
        node->is_embed = scanner->pending_embed_node;
        array_push(scanner->node_stack, node);

        scanner->pending_embed_node = false;
    } else if (token == NODE_EMPTY) {
        scanner->pending_embed_node = false;
    } else if (token == NODE_END) {
        assert(scanner->node_stack->size > 0);
        Node *node_to_end = array_pop(scanner->node_stack);
        // We'll need a helper at some point to close out any misc richtext
        // formatting that might be open still; that will go right here
        ts_free(node_to_end);

        assert(!scanner->pending_embed_node);
    }
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
                debug(
                    "!!! backlog token not valid at position (%s); forcing "
                    "backtrack\n",
                    _TokenNames[pending_token->token]);
            }

            // printf(
            //     "!!! processing token backlog %d: %d\n",
            //     token_backlog_index, pending_token->token);
            scanner->token_backlog_index += 1;

            if (!pending_token->skip_mark){
                for (size_t i = 0; i < pending_token->advance_count; ++i) {
                    // Carriage returns are literally the only thing we mark
                    // as whitespace in the entire grammar, because it's the
                    // only kind of whitespace we deem semantically meaningless
                    if (lexer->lookahead == UNICHR_CR) {
                        lexer->advance(lexer, true);
                    } else {
                        lexer->advance(lexer, false);
                    }
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


typedef struct {
    uint16_t indentation_char_count;
    uint16_t nih_whitespace_char_count;
    uint8_t empty_line_eol_length;
} SoLWhitespace;


typedef enum {
    SOL_NODE_CONTINUE,
    SOL_NODE_BEGIN,
    SOL_NODE_END,
    SOL_IS_EOF
} SoLNodeState;


typedef struct {
    SoLNodeState sol_node_state;
    uint8_t level_delta;
} SoLNodeStateClassification;


static uint8_t detect_and_advance_through_eol(
        /* This detects a newline (and any optional carriage returns)
        and returns the number of characters consumed as part of it, or
        0 if no EoL was found.
        */
        TSLexer *lexer
) {
    uint8_t charcount = 0;

    if (lexer->lookahead == UNICHR_CR) {
        charcount += 1;
        lexer->advance(lexer, true);
    }
    if (lexer->lookahead == UNICHR_NEWLINE) {
        charcount += 1;
        lexer->advance(lexer, false);
    }
    return charcount;
}


static SoLWhitespace *advance_through_empty_lines(
        /* This advances through the lexer lookahead until we come to
        the first non-empty line. It pushes an SoLWhitespace struct
        onto the passed empty_lines array for every empty line
        encountered, and returns the SoLWhitespace for the first
        non-empty line.

        Note that, if we encounter the EoF, we'll still return an
        SoLWhitespace!
        */
        TSLexer *lexer,
        Scanner *scanner,
        Array(SoLWhitespace *) * empty_lines
) {
    uint16_t indentation_char_count = 0;
    uint16_t nih_whitespace_char_count = 0;

    while (!lexer->eof(lexer)) {
        // If we've never encountered indentation in the file, ever, AND the
        // next character isn't indentation, then we can skip indentation
        // checking and just do empty line checks
        if (_ensure_indent_info(scanner, lexer->lookahead)){
            while (
                !lexer->eof(lexer)
                && lexer->lookahead == scanner->indentation_char
            ) {
                indentation_char_count += 1;
                lexer->advance(lexer, false);}
        }
        while (
            !lexer->eof(lexer)
            && is_horizontal_whitespace(lexer->lookahead)
        ) {
            nih_whitespace_char_count += 1;
            lexer->advance(lexer, false);
        }

        // Note: we don't want to add an extra empty line if we hit EoF. That
        // gets detected in the caller and simply added to empty_lines
        uint8_t maybe_eol_characters = detect_and_advance_through_eol(lexer);
        if (maybe_eol_characters){
            SoLWhitespace *empty_line = ts_malloc(sizeof(SoLWhitespace));
            empty_line->indentation_char_count = indentation_char_count;
            empty_line->nih_whitespace_char_count = nih_whitespace_char_count;
            empty_line->empty_line_eol_length = maybe_eol_characters;
            array_push(empty_lines, empty_line);
            indentation_char_count = 0;
            nih_whitespace_char_count = 0;

        // Keep in mind that we're only advancing through horizontal whitespace
        // here. So by definition, if the next character isn't a newline or the
        // EoF, then it's no longer an empty line.
        } else {
            break;
        }
    }

    SoLWhitespace *nonempty_line = ts_malloc(sizeof(SoLWhitespace));
    nonempty_line->indentation_char_count = indentation_char_count;
    nonempty_line->nih_whitespace_char_count = nih_whitespace_char_count;
    nonempty_line->empty_line_eol_length = 0;
    return nonempty_line;
}


static SoLNodeStateClassification classify_sol_node_state(
        /* Determines if the StartOfLine is a NODE_CONTINUE, NODE_BEGIN,
        or NODE_END. Keep in mind that we have more to consider than
        ^^just^^ the indentation level -- specifically, lists and embeds.
        */
        Scanner *scanner,
        Node *active_node,
        SoLWhitespace *first_nonempty_line
) {
    // Note: towards-zero rounding, but this is unsigned, so im endeffekt,
    // this is floor division
    uint8_t indentation_level_found;
    uint8_t active_node_level;
    bool is_embed;
    uint8_t maybe_indentation_char_repetitions = (
        scanner->indentation_char_repetitions);
    // Note that this gets called literally on the first line, which means
    // it'll be a minute (until the first indent) until we know how big an
    // indentation is. But good news: in that case, we don't care!
    if (maybe_indentation_char_repetitions) {
        indentation_level_found = (
            first_nonempty_line->indentation_char_count
            / maybe_indentation_char_repetitions);
    } else {
        indentation_level_found = 0;
    }

    if (active_node == NULL) {
        active_node_level = 0;
        is_embed = false;
    } else {
        active_node_level = active_node->node_level;
        is_embed = active_node->is_embed;
    }

    if (is_embed) {
        // This is maximally permissive; the extra whitespace will be converted
        // into embed content
        if (indentation_level_found >= active_node_level) {
            return (SoLNodeStateClassification){SOL_NODE_CONTINUE, 0};
        } else {
            return (SoLNodeStateClassification){
                SOL_NODE_END, active_node_level - indentation_level_found};
        }

    } else {
        if (indentation_level_found > active_node_level) {
            return (SoLNodeStateClassification){SOL_NODE_BEGIN, 1};

        // This is deliberately going to match even if there's a partial indent
        // **less than** the required amount for a node_begin;
        // peek_and_schedule_sol will only consume the correct amount of
        // indentation, and the rest will be turned into an error in the parser
        } else if (indentation_level_found == active_node_level) {
            return (SoLNodeStateClassification){SOL_NODE_CONTINUE, 0};

        } else {
            return (SoLNodeStateClassification){
                SOL_NODE_END, active_node_level - indentation_level_found};
        }
    }
}


//////////////////////////////////////////////////////////////////////////////
// SCANNING
//////////////////////////////////////////////////////////////////////////////


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
    // This prevents infinite loops by marking handle_eof as already called.
    // It also prevents accidentally calling handle_eof twice after processing
    // an empty line immediately preceeding the EoF.
    scanner->post_eof = true;

    // If you decide you want to make empty lines part of the parent block
    // instead of the child block, you can simply slide this before the above
    // EoF empty-and/or-EoL block
    if (scanner->node_stack->size > 0) {
        uint8_t current_node_level = (
            ((Node *)*array_back(scanner->node_stack))->node_level);

        for (
            uint8_t node_index = 0;
            node_index < current_node_level;
            ++node_index
        ) {
            debug("... scheduling node end from EoF\n");
            schedule_token(scanner, scan_state, NODE_END, 0, true);
        }
    }
}


static void peek_and_schedule_start_of_line(
        /* The challenge, should you choose to accept it, is:
        ++  treesitter only gives us a single character of lookahead
        ++  we can't rewind
        ++  we can't retry/replay/redo stuff, without altering the state
            of treesitter's internals
        ++  we have a mix of zero-length and consuming tokens at the
            start of the line
        ++  we need to defer emitting empty line tokens (Which can be
            consuming or zero-length) until after we know what comes
            after the empty line

        Additionally:
        ++  the lexer always returns a column of 0 at EoF
        ++  start-of-line handling gets skipped at EoF

        This challenge seems insurmountable, ^^except:^^ instead of
        doing this at the beginning of the line (like a sane
        architecture would allow), we can do it after scheduling the
        EOL token ^^at the end of the preceeding line.^^ This lets us
        consume the 1-character newline, and then do as much
        non-mutating lookahead as we want. Then, we rely on the backlog
        to re-consume the lookahead.

        It's a little awkward, yes, but it works! And it affords us a
        lot of flexibility in handling the start of the line, without
        a bunch of hacky workarounds for treesitter. Well, other than
        the hacky workaround of parsing the next line at the end of
        the preceeding one.
        */
        TSLexer *lexer,
        Scanner *scanner,
        ScanState *scan_state
) {
    Array(SoLWhitespace *) * empty_lines = ts_malloc(
        sizeof(Array(SoLWhitespace *)));
    array_init(empty_lines);
    // Default to SOL_NODE_CONTINUE; this only gets used where no indentation
    // was found at all, which can only be zeroth level node continuation
    SoLNodeState sol_node_state = SOL_NODE_CONTINUE;
    Node *active_node = NULL;
    if (scanner->node_stack->size > 0) {
        active_node = (Node *)*array_back(scanner->node_stack);
    }
    uint8_t level_delta = 0;

    // If we've never encountered indentation in the file, ever, AND the next
    // character isn't indentation, then we can skip indentation checking
    // and just do empty line checks
    SoLWhitespace *first_nonempty_line = advance_through_empty_lines(
        lexer, scanner, empty_lines);

    // Note that if we hit this, that means the first non-empty line... was,
    // in fact, actually empty, because it terminated in the EoF. Which means
    // we need an extra empty line, but not until after we handle the rest
    // of the empty lines
    if (lexer->eof(lexer)){
        handle_eof(lexer, scanner, scan_state, true);
        sol_node_state = SOL_IS_EOF;
        array_push(empty_lines, first_nonempty_line);

    // Note that classify_sol_node_state is perfectly capable of handling a
    // null active_node!
    } else {
        // These can't do anything more than detection, because we might need
        // to reorder some empty lines first
        // Note that these aren't completely trivial because we have embeddings
        // and lists to worry about
        SoLNodeStateClassification classification = classify_sol_node_state(
            scanner, active_node, first_nonempty_line);

        sol_node_state = classification.sol_node_state;
        level_delta = classification.level_delta;
    }

    // Empty lines go AFTER a node_end, including implicit ones at EoF
    if (sol_node_state == SOL_NODE_END || sol_node_state == SOL_IS_EOF) {
        for (
            uint8_t node_ends_scheduled = 0;
            node_ends_scheduled < level_delta;
            ++node_ends_scheduled
        ) {
            schedule_token(scanner, scan_state, NODE_END, 0, true);
        }

        for (
            uint8_t empty_line_index = 0;
            empty_line_index < empty_lines->size;
            ++empty_line_index
        ) {
            SoLWhitespace *empty_line = *array_get(
                empty_lines, empty_line_index);
            uint16_t empty_line_length = (
                empty_line->indentation_char_count
                + empty_line->nih_whitespace_char_count);
            schedule_token(
                scanner,
                scan_state,
                EMPTY_LINE,
                empty_line_length,
                false);
            schedule_token(
                scanner,
                scan_state,
                EOL,
                empty_line->empty_line_eol_length,
                false);
            ts_free(empty_line);
        }

        // If the SoL is the EoF, we want to have an empty line, which doesn't
        // get a node_continue. But otherwise, we can (and should!) already
        // queue up the next node_continue
        if (sol_node_state != SOL_IS_EOF) {
            uint8_t post_dedent_node_level = (
                first_nonempty_line->indentation_char_count
                / scanner->indentation_char_repetitions);

            schedule_token(
                scanner,
                scan_state,
                NODE_CONTINUE,
                // Yes, this looks redundant -- but it isn't. We're actually
                // rounding it to the whole indentation level, so we don't
                // consume too much whitespace if there's a partial indentation
                post_dedent_node_level * scanner->indentation_char_repetitions,
                false);
        }

    // Empty lines go BEFORE node_continue and node_begin
    } else {
        for (
            uint8_t empty_line_index = 0;
            empty_line_index < empty_lines->size;
            ++empty_line_index
        ) {
            SoLWhitespace *empty_line = *array_get(
                empty_lines, empty_line_index);
            uint16_t empty_line_length = (
                empty_line->indentation_char_count
                + empty_line->nih_whitespace_char_count);
            schedule_token(
                scanner,
                scan_state,
                EMPTY_LINE,
                empty_line_length,
                false);
            schedule_token(
                scanner,
                scan_state,
                EOL,
                empty_line->empty_line_eol_length,
                false);
            ts_free(empty_line);
        }

        // Note: NOT the same as the first_nonempty_line, because we might have
        // an erroneously long indentation (or be within an embedding)
        uint16_t np1_indentation_chars;
        uint16_t n_indentation_chars;
        if (active_node == NULL) {
            n_indentation_chars = 0;
            np1_indentation_chars = scanner->indentation_char_repetitions;
        } else {
            n_indentation_chars = (
                active_node->node_level * scanner->indentation_char_repetitions);
            np1_indentation_chars = (
                n_indentation_chars + scanner->indentation_char_repetitions);
        }

        // If it's a node_begin, we can also schedule the node_continue from
        // the beginning of the line
        if (sol_node_state == SOL_NODE_BEGIN) {
            schedule_token(scanner, scan_state, NODE_BEGIN, 0, true);

            if (scanner->pending_embed_node) {
                schedule_token(scanner, scan_state, FLAG_EMBED, 0, true);
            }

            schedule_token(
                scanner,
                scan_state,
                NODE_CONTINUE,
                np1_indentation_chars,
                false);

        } else {
            schedule_token(
                scanner,
                scan_state,
                NODE_CONTINUE,
                n_indentation_chars,
                false);
        }
    }

    array_delete(empty_lines);
}


static void detect_and_schedule_eol(
        /* We need to parse the EoL externally for three reasons:
        1.. the interplay with empty lines -- which might be a
            zero-length token between two newlines -- is very tricky.
        2.. we need to detect in advance if an EoF immediately follows
            an EoL, indicating a trailing empty line for the entire file
        3.. since we can't backtrack at the start of the line, and we need
            to parse empty lines until we see the first content line (to
            decide in which order the empty line should be scheduled -- for
            example, before a node_continue but after a node_end), we need a
            way to advance the lookahead without consuming characters. we can
            do that as part of the EoL, at the small cost of forcing us to
            re-advance when we need to emit the actual tokens

        TODO: this needs to deal with optional carriage returns!
        */
        TSLexer *lexer,
        Scanner *scanner,
        ScanState *scan_state
) {
    uint8_t maybe_eol_characters = detect_and_advance_through_eol(lexer);
    if (maybe_eol_characters) {
        // NOTE: we actually **need** to advance here, because we need to
        // check for the immediately following EoF immediately after
        // scheduling!
        consume_advances_from_lexer(lexer, scan_state, false);
        schedule_token(scanner, scan_state, EOL, maybe_eol_characters, true);

        debug("... peeking ahead; don't mind me!\n");
        // The docstring for peek_and_schedule_SoL explains this thoroughly
        peek_and_schedule_start_of_line(lexer, scanner, scan_state);
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
    if (lexer->lookahead == UNICHR_NODEDEF_SYMBOL) {
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
    if (lexer->lookahead == UNICHR_EMPTY_NODE_SYMBOL) {
        scanner->pending_embed_node = false;
        schedule_token(scanner, scan_state, NODE_EMPTY, 1, false);
    }
}


static void detect_and_schedule_node_metadata_key(
        /* This checks for a valid metadata identifier **on a node**.
        Note that this cannot be used on inline metadata keys (without
        modification), because we're doing the pending embedding
        detection here, which is invalid in an inline context.

        To that end: if the metadata key matches the EMBED_MAGIC, we set the
        correct state on the scanner to indicate that the upcoming node
        is an embedded one, but we don't yet emit the token itself.

        Metadata keys can either be strings (as in SQL; this lets you
        do whatever clever namespacing you want) or values approximately
        of the form ``[A-z_]([A-z0-9_\-])*``. By "approximately" I mean,
        like that, except replace the character ranges with "unicode
        letters" and "unicode digits".

        TODO: this needs to support strings! And they need to be handled
        here, because we still need to do the pending embedding marking.
        */
        TSLexer *lexer,
        Scanner *scanner,
        ScanState *scan_state
) {
    uint16_t charcount = 0;
    uint8_t embed_magic_comparison_sum = 0;
    embed_magic_comparison_sum += (lexer->lookahead == UNICHR_EMBED_MAGIC[0]);
    uint8_t comparison_index = 1;

    // This is a little bit "clever", so just to be clear: this
    // code takes advantage of the fact that the result of an assignment
    // expression in C (augmented or otherwise) is the value itself.
    if (
        (charcount += detect_and_advance_through_codepoint(
            lexer, UNICHR_UNDERSCORE))
        || (charcount += detect_and_advance_through_letter(lexer))
    ) {
        // This is effectively a while true, so we need to be careful about
        // having a break condition within the loop
        while (!lexer->eof(lexer)) {
            // Okay, keep in mind that anything here could advance us further
            // than a single codepoint. BUT the magic is expressed explicitly
            // in terms of codepoints. So we need to make sure both that the
            // charcount matches the comparison index, AND that the values
            // match, for this to be flagged as an embed.
            if (
                comparison_index == charcount
                // Also don't forget that the metadata key might have more
                // characters than the magic!
                && charcount < COUNT_OF(UNICHR_EMBED_MAGIC)
                && lexer->lookahead == UNICHR_EMBED_MAGIC[comparison_index]
            ) {
                embed_magic_comparison_sum += 1;
                comparison_index += 1;
            }

            uint8_t charcount_with_advance = 0;
            uint16_t loop_charcount = 0;
            // Again, we're using the return value of the assignment expression
            // as the boolean condition, but also the value itself
            if (
                (loop_charcount = detect_and_advance_through_codepoint(
                    lexer, UNICHR_UNDERSCORE))
                || (loop_charcount = detect_and_advance_through_codepoint(
                    lexer, UNICHR_HYPHEN))
                || (loop_charcount = detect_and_advance_through_letter(lexer))
                || (loop_charcount = detect_and_advance_through_digit(lexer))
            ) {
                charcount += loop_charcount;
                
            } else {
                break;
            }
        }
    }

    // Sanity check: we're making sure the length of the characters detected
    // matches the same length of the UNICHR_EMBED_MAGIC, and also that all
    // of the characters themselves matched. Therefore, this is the metadata
    // key to mark it as embedded.
    if (
        charcount == COUNT_OF(UNICHR_EMBED_MAGIC)
        && embed_magic_comparison_sum == COUNT_OF(UNICHR_EMBED_MAGIC)
    ) {
        debug("... pending embed node detected!\n");
        scanner->pending_embed_node = true;
    } else {
        debug("... NO pending embed node detected!\n",
            charcount, embed_magic_comparison_sum);
    }

    if (charcount) {
        consume_advances_from_lexer(lexer, scan_state, false);
        schedule_token(scanner, scan_state, METADATA_KEY, charcount, true);
    }
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
        debug("!!! ERROR SENTINEL!\n");
        return false; }

    if (emit_from_backlog(lexer, scanner, valid_symbols)) {
        debug("<<< from backlog!\n");
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

        // If we hit the EoF after an empty line, this will be handled via
        // peek_and_schedule_start_of_line. If we hit the EoF at the end of
        // a normal line, we need to handle it here.
        if (lexer->eof(lexer)) {
            schedule_token(scanner, scan_state, EOL, 0, true);
            handle_eof(lexer, scanner, scan_state, false);

        // But do note that if we're at the EoF, all other tokens are invalid, and
        // should be skipped (to help avoid errors and weird states)
        } else {
            // debug("--- checkpoint1. valid symbols:\n");
            // for (
            //     size_t i = _ERROR_SENTINEL;
            //     i <= AUTOCLOSE_WARNING;
            //     i++
            // ) {
            //     debug("    %s: %d\n", _TokenNames[i], valid_symbols[i]);
            // }

            // The start-of-line handler always needs to be called first, since
            // it's dependent on being, well, at the start of the line.
            // Note that, except at the very beginning of the document (as in,
            // literally the first line) this is tacked on to the EoL handling
            // for the previous line
            if (can_parse(scan_state, SOL_SYMBOLS)) {
                peek_and_schedule_start_of_line(lexer, scanner, scan_state);}
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
            if (can_parse(scan_state, (TokenType[1]){METADATA_KEY})){
                detect_and_schedule_node_metadata_key(lexer, scanner, scan_state);}

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
}
