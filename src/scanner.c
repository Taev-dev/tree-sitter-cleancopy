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
    _TOKEN_ERROR_SENTINEL,
    // We use this to force examination of metadata declarations to figure out
    // if it's an embed node
    TOKEN_METADATA_KEY,
    // We use this for state management re: pending nodes
    TOKEN_NODE_EMPTY,
    TOKEN_FLAG_EMBED,
    TOKEN_NODE_DEF,
    TOKEN_EOL,
    TOKEN_EMPTY_LINE,
    TOKEN_NIH_WHITESPACE,
    TOKEN_NODE_CONTINUE,
    TOKEN_NODE_BEGIN,
    TOKEN_NODE_END,
    TOKEN_LIST_CONTINUE,
    TOKEN_LIST_HANGAR,
    TOKEN_LIST_BEGIN,
    TOKEN_LIST_END,
    TOKEN_MARKER_OL_INDEX,
    TOKEN_MARKER_OL,
    TOKEN_MARKER_UNOL,
    TOKEN_MARKER_ANNOTATION,
    TOKEN_EOF,
    TOKEN_AUTOCLOSE_WARNING,
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
    "LIST_CONTINUE",
    "LIST_HANGAR",
    "LIST_BEGIN",
    "LIST_END",
    "MARKER_OL_INDEX",
    "MARKER_OL",
    "MARKER_UNOL",
    "MARKER_ANNOTATION",
    "EoF",
    "AUTOCLOSE_WARNING"};


const TokenType SOL_SYMBOLS[] = {
    TOKEN_EMPTY_LINE,
    TOKEN_NODE_CONTINUE,
    TOKEN_NODE_BEGIN,
    TOKEN_NODE_END
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
        int32_t codepoint_to_detect
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


typedef enum {
    LSTAT_NO_LIST,
    LSTAT_OL,
    LSTAT_UNOL
} ListStatus;


// IMPORTANT: if you change anything here, YOU MUST ALSO UPDATE SERIALIZATION!
typedef struct {
    // Note: because we use contexts for both nodes and lists, this isn't always
    // the same as the index in the context stack!
    uint8_t node_level;
    // The marker level is the list "depth" -- in other words, how many
    // indents we're past the node level **at the marker**
    uint8_t list_marker_level;
    bool is_embed;
    ListStatus list_status;
} Context;
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
    // We use this to note what kind of list is pending
    ListStatus pending_list_status;
    // We use this to take the rest of a line out-of-band (for annotations,
    // so we don't emit a bunch of erroneous NIH whitespace)
    bool out_of_band_until_eol;

    // We use this to denote that we've already processed the EoF and added
    // any trailing zero-length tokens to the backlog. If this is true, and
    // the token backlog is consumed, then parsing is finished.
    bool post_eof;

    Array(Context *) * context_stack;
    Array(PendingToken *) * token_backlog;
} Scanner;


size_t _SCANNER_FIELD_LENGTHS[] = {
    sizeof(int32_t),
    sizeof(uint8_t),
    sizeof(uint8_t),
    sizeof(bool),
    sizeof(ListStatus),
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
    // hmm, this emits a compiler warning because the Array(Context *) is used as
    // a throwaway type to calculate a size.
    scanner->context_stack = ts_malloc(sizeof(Array(Context *)));
    scanner->token_backlog = ts_malloc(sizeof(Array(PendingToken *)));
    scanner->indentation_char = 0;
    scanner->indentation_char_repetitions = 0;
    scanner->token_backlog_index = 0;
    scanner->pending_embed_node = false;
    scanner->pending_list_status = LSTAT_NO_LIST;
    scanner->post_eof = false;
    scanner->out_of_band_until_eol = false;
    array_init(scanner->context_stack);
    array_init(scanner->token_backlog);

    return scanner;
}


void tree_sitter_cleancopy_external_scanner_destroy(
        void *payload
) {
    Scanner *scanner = (Scanner *)payload;

    // We need to free the contexts themselves before clearing the array, because
    // it doesn't handle this.
    for (size_t i = 0; i < scanner->context_stack->size; ++i) {
        printf("!!! WARNING: context_stack had contexts on destruction!\n");
        ts_free(*array_get(scanner->context_stack, i));
    }
    array_delete(scanner->context_stack);
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
    debug("...Scheduling %s\n", _TokenNames[token]);

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

    if (token == TOKEN_NODE_BEGIN) {
        uint8_t current_node_level;
        if (scanner->context_stack->size > 0){
            current_node_level = (
                (Context *)*array_back(scanner->context_stack))->node_level;
        } else {
            current_node_level = 0;
        }

        Context *context = ts_malloc(sizeof(Context));
        context->node_level = current_node_level + 1;
        context->is_embed = scanner->pending_embed_node;
        context->list_status = LSTAT_NO_LIST;
        context->list_marker_level = 0;
        array_push(scanner->context_stack, context);

        scanner->pending_embed_node = false;
        if (scanner->pending_list_status != LSTAT_NO_LIST) {
            debug(
                "^^^ NOTE: expecting a list as the first row in the new node!\n");
        }

    } else if (token == TOKEN_LIST_BEGIN) {
        assert(scanner->pending_list_status != LSTAT_NO_LIST);
        uint8_t current_node_level;
        uint8_t next_marker_level;
        if (scanner->context_stack->size > 0){
            Context *active_context = *array_back(scanner->context_stack);
            current_node_level = active_context->node_level;

            // The marker level is the list "depth" -- in other words, how many
            // indents we're past the node level **at the marker**. Therefore,
            // it always needs to start at zero, but needs to increment by 1
            // every time we start a list
            if (active_context->list_status != LSTAT_NO_LIST) {
                debug("^^^ Beginning nested list\n");
                next_marker_level = active_context->list_marker_level + 1;
            } else {
                debug("^^^ Beginning new list\n");
                next_marker_level = 0;
            }

        } else {
            current_node_level = 0;
            next_marker_level = 0;
        }

        Context *context = ts_malloc(sizeof(Context));
        context->node_level = current_node_level;
        context->is_embed = false;
        context->list_status = scanner->pending_list_status;
        context->list_marker_level = next_marker_level;
        array_push(scanner->context_stack, context);
        scanner->pending_list_status = LSTAT_NO_LIST;

        assert(!scanner->pending_embed_node);

    } else if (token == TOKEN_NODE_EMPTY) {
        scanner->pending_embed_node = false;

    } else if (token == TOKEN_NODE_END) {
        assert(scanner->context_stack->size > 0);
        assert(!scanner->pending_embed_node);
        assert(scanner->pending_list_status == LSTAT_NO_LIST);
        Context *context_to_end = array_pop(scanner->context_stack);
        assert(context_to_end->list_status == LSTAT_NO_LIST);
        ts_free(context_to_end);

    } else if (token == TOKEN_LIST_END) {
        assert(scanner->context_stack->size > 0);
        assert(!scanner->pending_embed_node);
        // Note: we might have this set to something, if we're swapping out
        // one list type for another
        // assert(scanner->pending_list_status == LSTAT_NO_LIST);
        Context *context_to_end = array_pop(scanner->context_stack);
        assert(context_to_end->list_status != LSTAT_NO_LIST);
        ts_free(context_to_end);

    // These are workarounds for tree-sitter not having PEG-like ordering and
    // also not understanding ambiguous tokens
    } else if (token == TOKEN_MARKER_ANNOTATION) {
        scanner->out_of_band_until_eol = true;
    } else if (token == TOKEN_EOL) {
        scanner->out_of_band_until_eol = false;
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
    SOL_INDENT_HELD,
    SOL_INDENT_INCREASED,
    SOL_INDENT_DECREASED,
    SOL_IS_EOF
} SoLIndentation;


typedef enum {
    MARKER_OL,
    MARKER_UNOL,
    MARKER_ANNOTATION
} SoLMarker;


typedef struct {
    SoLIndentation sol_indent_action;
    uint8_t sol_indentation_level;
} SoLIndentationClassification;


typedef struct {
    SoLMarker marker;
    bool detected;
    uint8_t chars_advanced;
    uint8_t marker_payload_charcount;
} SoLMarkerDetection;


static SoLMarkerDetection *detect_and_advance_through_annotation_marker(
        /* This detects the marker for annotation lines (comments).
        */
        TSLexer *lexer
) {
    SoLMarkerDetection *detection = ts_malloc(sizeof(SoLMarkerDetection));
    detection->marker = MARKER_ANNOTATION;
    detection->chars_advanced = 0;
    detection->detected = false;
    detection->marker_payload_charcount = 0;

    if (lexer->lookahead == UNICHR_HASH) {
        detection->chars_advanced += 1;
        lexer->advance(lexer, false);

        if (lexer->lookahead == UNICHR_HASH) {
            detection->chars_advanced += 1;
            lexer->advance(lexer, false);
            detection->detected = true;
        }
    }
    return detection;
}


static SoLMarkerDetection *detect_and_advance_through_ol_marker(
        /* This detects the marker for an ordered list.
        */
        TSLexer *lexer
) {
    SoLMarkerDetection *detection = ts_malloc(sizeof(SoLMarkerDetection));
    detection->marker = MARKER_OL;
    detection->chars_advanced = 0;
    detection->detected = false;
    detection->marker_payload_charcount = 0;

    uint8_t digit_index = 0;
    while (CHAR_WITHIN(UNIRAN_DIGIT, lexer->lookahead)){
        lexer->advance(lexer, false);
        detection->chars_advanced += 1;
        detection->marker_payload_charcount += 1;
    }

    if (detection->chars_advanced){
        if (lexer->lookahead == UNICHR_DOT) {
            detection->chars_advanced += 1;
            lexer->advance(lexer, false);

            if (lexer->lookahead == UNICHR_DOT) {
                detection->chars_advanced += 1;
                lexer->advance(lexer, false);
                detection->detected = true;
            }
        }
    }
    return detection;
}


static SoLMarkerDetection *detect_and_advance_through_unol_marker(
        /* This detects the marker for an unordered list.
        */
        TSLexer *lexer
) {
    SoLMarkerDetection *detection = ts_malloc(sizeof(SoLMarkerDetection));
    detection->marker = MARKER_UNOL;
    detection->chars_advanced = 0;
    detection->detected = false;
    detection->marker_payload_charcount = 0;

    if (lexer->lookahead == UNICHR_PLUS) {
        detection->chars_advanced += 1;
        lexer->advance(lexer, false);

        if (lexer->lookahead == UNICHR_PLUS) {
            detection->chars_advanced += 1;
            lexer->advance(lexer, false);
            detection->detected = true;
        }
    }
    return detection;
}


static SoLMarkerDetection *detect_and_advance_through_SoL_marker(
        /* This detects any start-of-line markers. Note that they **must**
        be mutually exclusive; otherwise, we'll get into a situation where
        one is partially consumed by an earlier marker.

        Note that, if no marker is found, we'll return a null pointer.
        */
        TSLexer *lexer
) {
    SoLMarkerDetection *detection;

    detection = detect_and_advance_through_unol_marker(lexer);
    if (detection->detected) {
        return detection;
    } else if (detection->chars_advanced) {
        debug(
            "... chars_advanced within SoL marker detection (unol); "
            "returning null\n");
        ts_free(detection);
        return NULL;
    } else {
        ts_free(detection);
    }

    detection = detect_and_advance_through_ol_marker(lexer);
    if (detection->detected) {
        return detection;
    } else if (detection->chars_advanced) {
        debug(
            "... chars_advanced within SoL marker detection (ol); "
            "returning null\n");
        ts_free(detection);
        return NULL;
    } else {
        ts_free(detection);
    }

    detection = detect_and_advance_through_annotation_marker(lexer);
    if (detection->detected) {
        return detection;
    } else if (detection->chars_advanced) {
        debug(
            "... chars_advanced within SoL marker detection (annotation); "
            "returning null\n");
        ts_free(detection);
        return NULL;
    } else {
        ts_free(detection);
    }

    // Note: we already freed the detection! We don't need to do it again!
    return NULL;
}


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


static SoLIndentationClassification *classify_sol_indentation(
        /* Determines if the StartOfLine is a NODE_CONTINUE, NODE_BEGIN,
        or NODE_END (or the equivalent for lists). Keep in mind that we
        have more to consider than ^^just^^ the number of indentation
        characters, since embeds modify whether or not we detect
        increased indentation at all, and lists change the "setpoint"
        of the indentation level.

        Also note: this is ONLY concerned with classifying the
        indentation level! We're NOT trying to figure out which tokens
        we should emit.
        */
        Scanner *scanner,
        Context *active_context,
        SoLWhitespace *first_nonempty_line,
        SoLMarkerDetection *marker_detection
) {
    SoLIndentationClassification *classification = ts_malloc(
        sizeof(SoLIndentationClassification));

    // Note: towards-zero rounding, but this is unsigned, so im endeffekt,
    // this is floor division
    uint8_t indentation_level_found;
    uint8_t active_node_level;
    uint8_t active_list_level;
    bool is_embed;
    ListStatus list_status;
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
    classification->sol_indentation_level = indentation_level_found;

    if (active_context == NULL) {
        active_node_level = 0;
        active_list_level = 0;
        is_embed = false;
        list_status = LSTAT_NO_LIST;
    } else {
        active_node_level = active_context->node_level;
        active_list_level = active_context->list_marker_level;
        is_embed = active_context->is_embed;
        list_status = active_context->list_status;
    }

    if (is_embed) {
        assert(list_status == LSTAT_NO_LIST);
        // This is maximally permissive; the extra whitespace will be converted
        // into embed content
        if (indentation_level_found >= active_node_level) {
            classification->sol_indent_action = SOL_INDENT_HELD;
        } else {
            classification->sol_indent_action = SOL_INDENT_DECREASED;
        }

    // NOTE: this means we're **already** within a list -- **not** that we're
    // about to start one! In this case, we need to add the list level to the
    // node level to figure out what indentation to expect
    } else if (list_status != LSTAT_NO_LIST) {
        uint8_t absolute_marker_level = active_node_level + active_list_level;

        // This is kinda complicated, but the idea is that we always have a
        // hanging indent for lists. That means we need to check the first row
        // (where a marker was detected) against the marker level, and any
        // subsequent rows against one more than the marker level. This block
        // is for the marker-detected line...
        if (
            marker_detection != NULL
            && marker_detection->detected
            && (marker_detection->marker == MARKER_OL
                || marker_detection->marker == MARKER_UNOL)
        ) {
            if (indentation_level_found > absolute_marker_level) {
                classification->sol_indent_action = SOL_INDENT_INCREASED;
            } else if (indentation_level_found == absolute_marker_level) {
                classification->sol_indent_action = SOL_INDENT_HELD;
            } else {
                classification->sol_indent_action = SOL_INDENT_DECREASED;
            }

        // ... and this block is for the hanging-indent continuation line
        } else {
            uint8_t absolute_hanging_indent_level = absolute_marker_level + 1;
            if (indentation_level_found > absolute_hanging_indent_level) {
                classification->sol_indent_action = SOL_INDENT_INCREASED;
            } else if (indentation_level_found == absolute_hanging_indent_level) {
                classification->sol_indent_action = SOL_INDENT_HELD;
            } else {
                classification->sol_indent_action = SOL_INDENT_DECREASED;
            }
        }

    // Note: we're not in a list yet, which means any marker detection is the
    // START of the marker state. Therefore, we should expect the existing
    // indentation level (at least at first), and let the parent deal with
    // the start. Again, these are about the indentation classification,
    // NOT about the token to schedule!
    } else {
        if (indentation_level_found > active_node_level) {
            classification->sol_indent_action = SOL_INDENT_INCREASED;

        // This is deliberately going to match even if there's a partial indent
        // **less than** the required amount for a node_begin;
        // peek_and_schedule_sol will only consume the correct amount of
        // indentation, and the rest will be turned into an error in the parser
        } else if (indentation_level_found == active_node_level) {
            classification->sol_indent_action = SOL_INDENT_HELD;

        } else {
            classification->sol_indent_action = SOL_INDENT_DECREASED;
        }
    }

    debug(
        "... Nonempty line classified as %d\n", classification->sol_indent_action);
    return classification;
}


//////////////////////////////////////////////////////////////////////////////
// SCANNING
//////////////////////////////////////////////////////////////////////////////


static void handle_eof_after_nonempty_line(
        /* Treesitter doesn't give us a formal EoF token, but we may
        need to do a bunch of zero-width tokens here. Therefore, we call
        this as soon as we detect an EoF, and handle everything here.

        Originally, this logic was spread out between the other parsers,
        but that got **very** unwieldy and bug-prone. So instead, I've
        centralized it here, so that it's clear what's going on. It
        doesn't feel particularly DRY, but it's ^^just different enough^^
        that is was causing a ton of headaches trying to implement it
        elsewhere.

        **Note that this is only responsible for EoFs that happen at the
        end of a nonempty line!** Otherwise, it gets handled by
        peek_and_schedule.
        */
        TSLexer *lexer,
        Scanner *scanner,
        ScanState *scan_state
) {
    // This prevents infinite loops of zero-width tokens at EoF.
    // It also prevents accidentally calling handle_eof twice after processing
    // an empty line immediately preceeding the EoF.
    scanner->post_eof = true;

    if (scanner->context_stack->size > 0) {
        for (
            // NOTE: important that this is signed; otherwise we'll never get
            // to the halting condition, because we'll wrap around to the max
            // unsigned value, since the condition is checked AFTER the
            // modification. We could also offset everything by one, and then
            // un-offset it in the loop, but... this just seems cleaner tbh,
            // even though it forces us to use 8 extra bits on the stack
            int16_t context_index = scanner->context_stack->size - 1;
            context_index >= 0;
            --context_index
        ) {
            debug("... scheduling next token from EoF: --v\n");
            Context *context_to_popschedule = *array_get(
                scanner->context_stack, context_index);
            if (context_to_popschedule->list_status == LSTAT_NO_LIST) {
                schedule_token(scanner, scan_state, TOKEN_NODE_END, 0, true);
            } else {
                schedule_token(scanner, scan_state, TOKEN_LIST_END, 0, true);
            }
        }
    }
}


static void schedule_empty_lines(
        Scanner *scanner,
        ScanState *scan_state,
        Array(SoLWhitespace *) * empty_lines
) {
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
            TOKEN_EMPTY_LINE,
            empty_line_length,
            false);
        schedule_token(
            scanner,
            scan_state,
            TOKEN_EOL,
            empty_line->empty_line_eol_length,
            false);
        ts_free(empty_line);
    }
}


static void schedule_indentation_increased(
        /* Here, we're handling scheduling any time the indentation has
        increased.

        Note that lists cannot be ^^started^^ by an indentation increase --
        unless the list is the first line of a nested node! Otherwise, they
        must always be started with an indentation hold. But we might be
        dropping into a deeper list level -- if and **only if** we're already
        within a list.
        */
        Scanner *scanner,
        ScanState *scan_state,
        Context *active_context,
        SoLIndentationClassification *classification,
        SoLMarkerDetection *marker_detection,
        Array(SoLWhitespace *) * empty_lines
){
    debug("... scheduling indentation increased\n");
    // Note: empty lines go before any node/list beginnings, but -- when we implement
    // formatting -- we'll also need to schedule any formatting pops if
    // an empty line was detected (und zwar, **before** the empty lines!)
    schedule_empty_lines(scanner, scan_state, empty_lines);

    // Note: NOT the same as the first_nonempty_line, because we might have
    // an erroneously long indentation (or be within an embedding)
    uint16_t np_indentation_level;
    uint16_t np1_indentation_level;
    uint8_t np1_list_marker_level;
    ListStatus list_status;
    if (active_context == NULL) {
        np_indentation_level = 0;
        np1_indentation_level = 1;
        list_status = LSTAT_NO_LIST;
        np1_list_marker_level = 0;
    } else {
        np_indentation_level = active_context->node_level;
        np1_indentation_level = np_indentation_level + 1;
        list_status = active_context->list_status;

        // Note that list marker levels always start at 0! In theory, this
        // shouldn't be possible here, but since we're doing all of our state
        // normalization up front, we want to be thorough (and let later code
        // assert and/or schedule an error sentinel).
        if (active_context->list_status == LSTAT_NO_LIST) {
            np1_list_marker_level = 0;
        } else {
            np1_list_marker_level = active_context->list_marker_level + 1;
        }
    }

    // Easy peasy lemon squeezy: we're not in a list, so this can only be the
    // start of a new node.
    if (list_status == LSTAT_NO_LIST) {
        schedule_token(scanner, scan_state, TOKEN_NODE_BEGIN, 0, true);

        if (scanner->pending_embed_node) {
            schedule_token(scanner, scan_state, TOKEN_FLAG_EMBED, 0, true);

        // We need to be careful here! Yes, we just had a node start. But
        // we might also have a list as the first line in the node. So we
        // still need to check for a marker, and we might still need to handle
        // a new list starting.
        } else if (
            marker_detection != NULL && marker_detection->detected
            && (
                marker_detection->marker == MARKER_OL
                || marker_detection->marker == MARKER_UNOL)
        ) {
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_BEGIN,
                0,
                true);
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                np1_indentation_level * scanner->indentation_char_repetitions,
                false);
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                // By definition, we're starting a new list, so we know this is
                // a zero
                0,
                false);

            if (marker_detection->marker == MARKER_OL) {
                // And finally, the list index and then marker and then we can get
                // on with our lives
                scanner->pending_list_status = LSTAT_OL;
                schedule_token(
                    scanner,
                    scan_state,
                    TOKEN_MARKER_OL_INDEX,
                    marker_detection->marker_payload_charcount,
                    false);
                schedule_token(
                    scanner,
                    scan_state,
                    TOKEN_MARKER_OL,
                    2,
                    false);

            } else {
                // Here defensively in case we change the above if/else block,
                // but also for documentation
                assert(marker_detection->marker == MARKER_UNOL);
                scanner->pending_list_status = LSTAT_UNOL;

                // And finally, the list marker and then we can get
                // on with our lives
                schedule_token(
                    scanner,
                    scan_state,
                    TOKEN_MARKER_UNOL,
                    2,
                    false);
            } 

        // Up until now, it's been zero-length tokens to handle indentation
        // changes, but we can (must!) also schedule the node_continue from
        // the beginning of the next line
        } else {
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                np1_indentation_level * scanner->indentation_char_repetitions,
                false);
            
            if (
                marker_detection != NULL && marker_detection->detected
                && marker_detection->marker == MARKER_ANNOTATION
            ) {
                schedule_token(
                    scanner,
                    scan_state,
                    TOKEN_MARKER_ANNOTATION,
                    2,
                    false);
            }
        }

    // Note that it actually doesn't matter what the existing list type is;
    // a nested list doesn't have any inherent connection to the parent list,
    // so we can jump between list types at will. We just need to make sure
    // it matches the marker detection.
    } else {
        // If we didn't detect a marker, this is invalid.
        assert(marker_detection != NULL && marker_detection->detected);

        // Regardless of list type, we need to schedule a nested list begin,
        // then a node continue for the current node level, and a list continue
        // for the NEXT list (marker) level. ^^Then^^ comes the marker itself.
        schedule_token(
            scanner,
            scan_state,
            TOKEN_LIST_BEGIN,
            0,
            true);
        schedule_token(
            scanner,
            scan_state,
            TOKEN_NODE_CONTINUE,
            np_indentation_level * scanner->indentation_char_repetitions,
            false);
        // The list_continue consumes any indentation up to the marker
        // level; this might be zero-width!
        schedule_token(
            scanner,
            scan_state,
            TOKEN_LIST_CONTINUE,
            np1_list_marker_level * scanner->indentation_char_repetitions,
            false);

        if (marker_detection->marker == MARKER_OL) {
            // And finally, the list index and then marker and then we can get
            // on with our lives
            scanner->pending_list_status = LSTAT_OL;
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_OL_INDEX,
                marker_detection->marker_payload_charcount,
                false);
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_OL,
                2,
                false);

        } else if (marker_detection->marker == MARKER_UNOL) {
            scanner->pending_list_status = LSTAT_UNOL;

            // And finally, the list marker and then we can get
            // on with our lives
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_UNOL,
                2,
                false);

        } else {
            assert(marker_detection->marker == MARKER_ANNOTATION);
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_ANNOTATION,
                2,
                false);
        }
    }
}


static void schedule_indentation_decreased(
        /* When an indentation decrease has been detected, this is
        responsible for scheduling all of the list/node/formatting ends
        that are associated with it.

        Note: we want to let ``emit_token`` deal with popping the actual
        contexts. This is just figuring out how many to schedule, and
        scheduling them.
        */
        Scanner *scanner,
        ScanState *scan_state,
        Context *active_context,
        SoLIndentationClassification *classification,
        SoLMarkerDetection *marker_detection,
        Array(SoLWhitespace *) * empty_lines
){
    debug("... scheduling indentation decreased\n");
    assert(
        classification->sol_indent_action == SOL_INDENT_DECREASED
        || classification->sol_indent_action == SOL_IS_EOF);

    // Note: when formatting gets added, this will still need to unwrap any
    // active formatting, even though there's no context
    if (active_context == NULL) {
        assert(classification->sol_indent_action == SOL_IS_EOF);
        schedule_empty_lines(scanner, scan_state, empty_lines);

    } else {
        // MUST BE SIGNED! We're expecting this to be negative, so we need to
        // avoid wraparound errors!
        int16_t context_index = scanner->context_stack->size - 1;
        Context *context_to_check = *array_get(scanner->context_stack, context_index);
        uint8_t combined_indentation_level = (
                context_to_check->node_level + context_to_check->list_marker_level); 

        // Here's the easy part: all list levels that are deeper than the
        // combined marker indentation level cannot possibly be part of that
        // list level, and can immediately be scheduled for popping.
        while (
            context_to_check->list_status != LSTAT_NO_LIST
            && classification->sol_indentation_level < combined_indentation_level
        ) {
            schedule_token(scanner, scan_state, TOKEN_LIST_END, 0, true);
            context_index -= 1;
            if (context_index >= 0) {
                context_to_check = *array_get(
                    scanner->context_stack, context_index);
                combined_indentation_level = (
                    context_to_check->node_level
                    + context_to_check->list_marker_level);
            } else {
                context_to_check = NULL;
                combined_indentation_level = 0;
            }
        }

        // Now the tricky part: if we're still in a list, AND that was exactly
        // the end of the dedentation, then we have some decisions to make.
        // List markers happen at their parent node's indentation level, so we
        // need to check the detection, and we also need to make sure the list
        // didn't change type. And if we stayed in the list, we also have some
        // other bookkeeping tokens to emit before we're done.
        // NOTE THAT THERE MIGHT STILL BE MORE LIST LEVELS ABOVE US!
        if (
            context_to_check->list_status != LSTAT_NO_LIST
            && classification->sol_indentation_level == combined_indentation_level
        ) {
            // We backed out to the lowest level of the list, and then we didn't
            // follow that up with a new list item. That means we're back to
            // normal node content at the same indentation level as the
            // now-obsolete marker. Note that this also handles the EoF case!
            if (
                marker_detection == NULL
                || !marker_detection->detected
                || (
                    marker_detection->marker != MARKER_OL
                    && marker_detection->marker != MARKER_UNOL)
            ) {
                schedule_token(scanner, scan_state, TOKEN_LIST_END, 0, true);
                // We need these in just a minute to do the bookkeeping for
                // the next line
                context_index -= 1;
                if (context_index >= 0) {
                    context_to_check = *array_get(
                        scanner->context_stack, context_index);
                    combined_indentation_level = (
                        context_to_check->node_level
                        + context_to_check->list_marker_level);
                } else {
                    context_to_check = NULL;
                    combined_indentation_level = 0;
                }

            // We backed out to the lowest level of the list, and then swapped
            // the list type. We need to create a new list!
            } else if (
                marker_detection->marker == MARKER_OL
                && context_to_check->list_status != LSTAT_OL
            ) {
                // Note: no change to the context yet; the final bookkeeping
                // will be purely based on the list_status and marker detection,
                // so it doesn't matter that we're holding off until emit_token
                // to update the actual context
                schedule_token(scanner, scan_state, TOKEN_LIST_END, 0, true);
                scanner->pending_list_status = LSTAT_OL;
                schedule_token(scanner, scan_state, TOKEN_LIST_BEGIN, 0, true);
            // Same as above, but the other swap
            } else if (
                marker_detection->marker == MARKER_UNOL
                && context_to_check->list_status != LSTAT_UNOL
            ) {
                // Note: no change to the context yet; the final bookkeeping
                // will be purely based on the list_status and marker detection,
                // so it doesn't matter that we're holding off until emit_token
                // to update the actual context
                schedule_token(scanner, scan_state, TOKEN_LIST_END, 0, true);
                scanner->pending_list_status = LSTAT_UNOL;
                schedule_token(scanner, scan_state, TOKEN_LIST_BEGIN, 0, true);
            }
            // Note that if we didn't swap the list type, we can just wait
            // until the final bookkeeping to sort out continuations and the
            // new marker (see below)
        }

        // Back to simple stuff: we're all the way out of the list, but we
        // still have nodes to end!
        while (
            classification->sol_indentation_level < combined_indentation_level
        ) {
            schedule_token(scanner, scan_state, TOKEN_NODE_END, 0, true);
            context_index -= 1;
            if (context_index >= 0) {
                context_to_check = *array_get(
                    scanner->context_stack, context_index);
                combined_indentation_level = context_to_check->node_level;
            } else {
                context_to_check = NULL;
                combined_indentation_level = 0;
            }
        }

        // Okay, now that we've got all of the node/list ends sorted out, we
        // need to figure out the rest of the bookkeeping for the upcoming
        // (nonempty) line -- just as soon as we schedule the empty ones.
        schedule_empty_lines(scanner, scan_state, empty_lines);

        // If the SoL is the EoF, we're going to end up emitting an empty line,
        // which doesn't need a node_continue. Note that, this is NOT redundant
        // with the top-level if (active_context == NULL), since we just went
        // through a bunch of manipulations of the active context!
        if (classification->sol_indent_action != SOL_IS_EOF) {
            // In this case we don't even need to worry about list stuff; it's
            // not possible!
            if (context_to_check == NULL) {
                schedule_token(
                    scanner,
                    scan_state,
                    TOKEN_NODE_CONTINUE,
                    0,
                    true);

                if (
                    marker_detection != NULL && marker_detection->detected
                    && marker_detection->marker == MARKER_ANNOTATION
                ) {
                    schedule_token(
                        scanner,
                        scan_state,
                        TOKEN_MARKER_ANNOTATION,
                        2,
                        false);
                }

            // Here, though, all we can say is that there IS still a context;
            // we don't know yet if it's a list or a regular node
            } else {
                // Node continues only consume the node indentation, so we
                // still don't need to check about the list yet. BUT, be
                // careful: 
                schedule_token(
                    scanner,
                    scan_state,
                    TOKEN_NODE_CONTINUE,
                    context_to_check->node_level
                        * scanner->indentation_char_repetitions,
                    false);

                if (context_to_check->list_status == LSTAT_NO_LIST) {
                    if (
                        marker_detection != NULL && marker_detection->detected
                        && marker_detection->marker == MARKER_ANNOTATION
                    ) {
                        schedule_token(
                            scanner,
                            scan_state,
                            TOKEN_MARKER_ANNOTATION,
                            2,
                            false);
                    }

                // That's the node continuation, but we might still have some
                // LIST continuations (and also maybe markers!) depending on what
                // the last context we found was.
                } else {
                    schedule_token(
                        scanner,
                        scan_state,
                        TOKEN_LIST_CONTINUE,
                        context_to_check->list_marker_level
                            * scanner->indentation_char_repetitions,
                        false);

                    // No marker, but we're still in a list. That means that this
                    // is a continuation of a previous list level. So we need a
                    // list continue AND a list hangar, and they'll split the
                    // indentation
                    if (
                        marker_detection == NULL
                        || !marker_detection->detected
                    ) {
                        schedule_token(
                            scanner,
                            scan_state,
                            TOKEN_LIST_HANGAR,
                            scanner->indentation_char_repetitions,
                            false);
                        
                    // We've already dealt with list switches, so we just need
                    // to take care of scheduling the marker here
                    } else if (marker_detection->marker == MARKER_OL) {
                        schedule_token(
                            scanner,
                            scan_state,
                            TOKEN_MARKER_OL_INDEX,
                            marker_detection->marker_payload_charcount,
                            false);
                        schedule_token(
                            scanner,
                            scan_state,
                            TOKEN_MARKER_OL,
                            2,
                            false);

                    // We've already dealt with list switches, so we just need
                    // to take care of scheduling the marker here
                    } else if (marker_detection->marker == MARKER_UNOL) {
                        schedule_token(
                            scanner,
                            scan_state,
                            TOKEN_MARKER_UNOL,
                            2,
                            false);

                    } else {
                        assert(marker_detection != NULL);
                        assert(marker_detection->detected);
                        assert(marker_detection->marker == MARKER_ANNOTATION);
                        schedule_token(
                            scanner,
                            scan_state,
                            TOKEN_MARKER_ANNOTATION,
                            2,
                            false);
                    }
                }
            }
        }
    }
}


static void schedule_indentation_held(
        Scanner *scanner,
        ScanState *scan_state,
        Context *active_context,
        SoLIndentationClassification *classification,
        SoLMarkerDetection *marker_detection,
        Array(SoLWhitespace *) * empty_lines
){
    debug("... scheduling indentation held\n");

    // Note: NOT the same as the first_nonempty_line, because we might have
    // an erroneously long indentation (or be within an embedding)
    uint16_t n_indentation_chars;
    uint8_t active_list_marker_level;
    ListStatus list_status;
    if (active_context == NULL) {
        n_indentation_chars = 0;
        list_status = LSTAT_NO_LIST;
        active_list_marker_level = 0;
    } else {
        n_indentation_chars = (
            active_context->node_level * scanner->indentation_char_repetitions);
        list_status = active_context->list_status;
        active_list_marker_level = active_context->list_marker_level;
    }

    // Empty lines break up the list into a new list
    if (list_status != LSTAT_NO_LIST && empty_lines->size != 0) {
        assert(marker_detection != NULL && marker_detection->detected);
        schedule_token(
            scanner,
            scan_state,
            TOKEN_LIST_END,
            0,
            true);
        schedule_empty_lines(scanner, scan_state, empty_lines);

        if (marker_detection->marker == MARKER_OL) {
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_BEGIN,
                0,
                true);

            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);
            // The list_continue consumes any indentation up to the marker level
            // (which might be zero-width)
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);

            // And finally, the list index and then marker and then we can get
            // on with our lives
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_OL_INDEX,
                marker_detection->marker_payload_charcount,
                false);
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_OL,
                2,
                false);

        } else {
            assert(marker_detection->marker == MARKER_UNOL);
            scanner->pending_list_status = LSTAT_UNOL;
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_BEGIN,
                0,
                true);

            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);
            // The list_continue consumes any indentation up to the marker level
            // (which might be zero-width)
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);

            // And finally, the list marker and then we can get
            // on with our lives
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_UNOL,
                2,
                false);
        }
        
    } else if (list_status == LSTAT_OL) {
        // We're currently in an ordered list, found no marker, but got
        // classified as an indentation held. That means we're still in a list
        // item, but we're after the first line, so we need both a list
        // continue and a list hangar.
        if (marker_detection == NULL) {
            assert(scanner->indentation_char_repetitions);

            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);
            // The list continue consumes everything up to the marker level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);
            // And the list hangar consumes the hanging indent
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_HANGAR,
                scanner->indentation_char_repetitions,
                false);

        // We're currently in an ordered list and found a marker for an
        // ordered list. Since this was also classified as an indentation held,
        // that means this is simply a new list row.
        } else if (marker_detection->marker == MARKER_OL) {
            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);

            // The list_continue consumes any indentation up to the marker
            // level; this might be zero-width!
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);

            // And finally, the list index and then marker and then we can get
            // on with our lives
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_OL_INDEX,
                marker_detection->marker_payload_charcount,
                false);
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_OL,
                2,
                false);

        // We're currently in an ordered list and found a marker for an
        // UNordered list. Cleancopy doesn't allow mixing the two, so, since
        // this was also classified as an indentation held, we need to close
        // the previous ordered list and start a new unordered list.
        } else if (marker_detection->marker == MARKER_UNOL) {
            // These are both zero-width. Positionally, they're at the very
            // beginning of the first nonempty line.
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_END,
                0,
                true);
            scanner->pending_list_status = LSTAT_UNOL;
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_BEGIN,
                0,
                true);

            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);
            // The list_continue consumes any indentation up to the marker level
            // (which might be zero-width)
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);

            // And finally, the list marker and then we can get
            // on with our lives
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_UNOL,
                2,
                false);

        } else {
            assert(marker_detection->marker == MARKER_ANNOTATION);

            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);
            // The list_continue consumes any indentation up to the marker level
            // (which might be zero-width)
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);
            // And the list hangar consumes the hanging indent
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_HANGAR,
                scanner->indentation_char_repetitions,
                false);
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_ANNOTATION,
                2,
                false);
        }

    } else if (list_status == LSTAT_UNOL) {
        // We're currently in an unordered list, found no marker, but got
        // classified as an indentation held. That means we're still in a list
        // item, but we're after the first line, so we need both a list
        // continue and a list hangar.
        if (marker_detection == NULL) {
            assert(scanner->indentation_char_repetitions);

            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);
            // The list continue consumes everything up to the marker level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);
            // And the list hangar consumes the hanging indent
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_HANGAR,
                scanner->indentation_char_repetitions,
                false);
            
        // We're currently in an unordered list and found a marker for an
        // unordered list. Since this was also classified as an indentation held,
        // that means this is simply a new list row.
        } else if (marker_detection->marker == MARKER_UNOL) {
            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);

            // The list_continue consumes any indentation up to the marker
            // level; this might be zero-width!
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);

            // And finally, the list marker and then we can get
            // on with our lives
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_UNOL,
                2,
                false);
            
        // We're currently in an UNordered list and found a marker for an
        // ordered list. Cleancopy doesn't allow mixing the two, so, since
        // this was also classified as an indentation held, we need to close
        // the previous ordered list and start a new ordered list.
        } else if (marker_detection->marker == MARKER_OL) {
            // These are both zero-width. Positionally, they're at the very
            // beginning of the first nonempty line.
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_END,
                0,
                true);
                scanner->pending_list_status = LSTAT_OL;
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_BEGIN,
                0,
                true);

            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);
            // The list_continue consumes any indentation up to the marker level
            // (which might be zero-width)
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);

            // And finally, the list index and then marker and then we can get
            // on with our lives
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_OL_INDEX,
                marker_detection->marker_payload_charcount,
                false);
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_OL,
                2,
                false);

        } else {
            assert(marker_detection->marker == MARKER_ANNOTATION);

            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);
            // The list_continue consumes any indentation up to the marker level
            // (which might be zero-width)
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);
            // And the list hangar consumes the hanging indent
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_HANGAR,
                scanner->indentation_char_repetitions,
                false);
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_ANNOTATION,
                2,
                false);
        }

    // We're not in a list (yet), but we found a marker at the beginning of
    // the line
    } else if (marker_detection != NULL) {
        schedule_empty_lines(scanner, scan_state, empty_lines);

        // Starting an ordered list
        if (marker_detection->marker == MARKER_OL) {
            scanner->pending_list_status = LSTAT_OL;
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_BEGIN,
                0,
                true);

            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);
            // The list_continue consumes any indentation up to the marker level
            // (which might be zero-width)
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);

            // And finally, the list index and then marker and then we can get
            // on with our lives
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_OL_INDEX,
                marker_detection->marker_payload_charcount,
                false);
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_OL,
                2,
                false);

        // Starting an unordered list
        } else if (marker_detection->marker == MARKER_UNOL) {
            scanner->pending_list_status = LSTAT_UNOL;
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_BEGIN,
                0,
                true);

            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);
            // The list_continue consumes any indentation up to the marker level
            // (which might be zero-width)
            schedule_token(
                scanner,
                scan_state,
                TOKEN_LIST_CONTINUE,
                active_list_marker_level * scanner->indentation_char_repetitions,
                false);

            // And finally, the marker and then we can get on with our lives
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_UNOL,
                2,
                false);

        // Starting an annotation line
        } else {
            assert(marker_detection->marker == MARKER_ANNOTATION);

            // The node_continue consumes any indentation up to the node level
            schedule_token(
                scanner,
                scan_state,
                TOKEN_NODE_CONTINUE,
                n_indentation_chars,
                false);
            // The list_continue consumes any indentation up to the marker level
            // (which might be zero-width)
            schedule_token(
                scanner,
                scan_state,
                TOKEN_MARKER_ANNOTATION,
                2,
                false);
        }

    // No markers, no lists, no nuttin'. That means this is a plain-jane
    // content line, and all we need is the NODE_CONTINUE.
    } else {
        // Note: empty lines go before any continuations, but we need to be
        // careful about auto-closing any formatting state, when we get to that
        // point
        schedule_empty_lines(scanner, scan_state, empty_lines);
        // This consumes any indentation up to the node level.
        schedule_token(
            scanner,
            scan_state,
            TOKEN_NODE_CONTINUE,
            n_indentation_chars,
            false);
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
    Context *active_context = NULL;
    if (scanner->context_stack->size > 0) {
        active_context = (Context *)*array_back(scanner->context_stack);
    }

    // If we've never encountered indentation in the file, ever, AND the next
    // character isn't indentation, then we can skip indentation checking
    // and just do empty line checks
    SoLWhitespace *first_nonempty_line = advance_through_empty_lines(
        lexer, scanner, empty_lines);
    SoLMarkerDetection *marker_detection = NULL;
    SoLIndentationClassification *classification;

    // Note that if we hit this, that means the first non-empty line... was,
    // in fact, actually empty, because it terminated in the EoF. Which means
    // we need an extra empty line, but not until after we handle the rest
    // of the empty lines
    if (lexer->eof(lexer)){
        // This prevents infinite loops of zero-width tokens at EoF.
        // It also prevents accidentally calling handle_eof twice after processing
        // an empty line immediately preceeding the EoF.
        scanner->post_eof = true;
        array_push(empty_lines, first_nonempty_line);
        classification = ts_malloc(sizeof(SoLIndentationClassification));
        classification->sol_indent_action = SOL_IS_EOF;
        classification->sol_indentation_level = 0;

    // Note that classify_sol_indentation is perfectly capable of handling a
    // null active_context!
    } else {
        marker_detection = detect_and_advance_through_SoL_marker(lexer);
        // These can't do anything more than detection, because we might need
        // to reorder some empty lines first
        // Note that these aren't completely trivial because we have embeddings
        // and lists to worry about
        classification = classify_sol_indentation(
            scanner, active_context, first_nonempty_line, marker_detection);
    }

    if (
        classification->sol_indent_action == SOL_INDENT_INCREASED
    ) {
        schedule_indentation_increased(
            scanner, scan_state, active_context, classification,
            marker_detection, empty_lines);

    } else if (classification->sol_indent_action == SOL_INDENT_HELD) {
        schedule_indentation_held(
            scanner, scan_state, active_context, classification,
            marker_detection, empty_lines);

    } else {
        assert(
            classification->sol_indent_action == SOL_IS_EOF
            || classification->sol_indent_action == SOL_INDENT_DECREASED);
        schedule_indentation_decreased(
            scanner, scan_state, active_context, classification,
            marker_detection, empty_lines);
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
        schedule_token(scanner, scan_state, TOKEN_EOL, maybe_eol_characters, true);

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
        schedule_token(scanner, scan_state, TOKEN_NODE_DEF, 1, false);
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
        schedule_token(scanner, scan_state, TOKEN_NODE_EMPTY, 1, false);
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
        schedule_token(scanner, scan_state, TOKEN_METADATA_KEY, charcount, true);
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
    // Fffff yet again: this is a workaround for treesitter not having a
    // concept of PEG-style precedence. It's asking us to look for whitespace
    // characters (because they're valid as part of the EoL), but then it
    // doesn't understand that the whitespace character could also be a valid
    // embedding character. So when it asks us to find a whitespace character,
    // and we do, it gets stuck, and errors out.
    bool is_embed = false;
    if (scanner->context_stack->size > 0) {
        Context *active_context = (Context *)*array_back(
            scanner->context_stack);
        is_embed = active_context->is_embed;
    }

    if (
        !is_embed
        && !scanner->out_of_band_until_eol
        && lexer->get_column(lexer) != 0
        && is_horizontal_whitespace(lexer->lookahead)
    ) {
        schedule_token(scanner, scan_state, TOKEN_NIH_WHITESPACE, 1, false);
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
    if (valid_symbols[_TOKEN_ERROR_SENTINEL]) { 
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
        schedule_token(scanner, scan_state, TOKEN_EOF, 0, false);

    } else {

        // If we hit the EoF after an empty line, this will be handled via
        // peek_and_schedule_start_of_line. If we hit the EoF at the end of
        // a normal line, we need to handle it here.
        if (lexer->eof(lexer)) {
            schedule_token(scanner, scan_state, TOKEN_EOL, 0, true);
            handle_eof_after_nonempty_line(lexer, scanner, scan_state, false);

        // But do note that if we're at the EoF, all other tokens are invalid, and
        // should be skipped (to help avoid errors and weird states)
        } else {
            // debug("--- checkpoint1. valid symbols:\n");
            // for (
            //     size_t i = _TOKEN_ERROR_SENTINEL;
            //     i <= TOKEN_AUTOCLOSE_WARNING;
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
            if (can_parse(scan_state, (TokenType[1]){TOKEN_NODE_EMPTY})){
                detect_and_schedule_empty_node(lexer, scanner, scan_state);}
            // We use this sentinel to force treesitter into our external scanner,
            // so we can examine the metadata key, and decide whether it indicates
            // a pending embed node
            if (can_parse(scan_state, (TokenType[1]){TOKEN_METADATA_KEY})){
                detect_and_schedule_node_metadata_key(lexer, scanner, scan_state);}

            if (can_parse(scan_state, (TokenType[1]){TOKEN_EOL})){
                detect_and_schedule_eol(lexer, scanner, scan_state);}
            if (can_parse(scan_state, (TokenType[1]){TOKEN_NODE_DEF})){
                detect_and_schedule_node_def(lexer, scanner, scan_state);}
            if (can_parse(scan_state, (TokenType[1]){TOKEN_NIH_WHITESPACE})){
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
        &scanner->pending_list_status,
        _SCANNER_FIELD_LENGTHS[4]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[4];

    memcpy(
        &buffer[buffer_offset],
        &scanner->out_of_band_until_eol,
        _SCANNER_FIELD_LENGTHS[5]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[5];

    memcpy(
        &buffer[buffer_offset],
        &scanner->post_eof,
        _SCANNER_FIELD_LENGTHS[6]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[6];

    unsigned context_stack_count = scanner->context_stack->size;
    size_t context_size = sizeof(Context);
    size_t context_stack_size = context_size * context_stack_count;
    memcpy(
        &buffer[buffer_offset],
        &context_stack_size,
        sizeof(size_t));
    buffer_offset += sizeof(size_t);

    for (
        unsigned context_index = 0;
        context_index < context_stack_count;
        ++context_index
    ) {
        Context *context = *array_get(scanner->context_stack, context_index);
        memcpy(
            &buffer[buffer_offset],
            context,
            context_size);
        buffer_offset += context_size;
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
    array_init(scanner->context_stack);
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
        &scanner->pending_list_status,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[4]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[4];

    memcpy(
        &scanner->out_of_band_until_eol,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[5]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[5];

    memcpy(
        &scanner->post_eof,
        &buffer[buffer_offset],
        _SCANNER_FIELD_LENGTHS[6]);
    buffer_offset += _SCANNER_FIELD_LENGTHS[6];

    size_t context_size = sizeof(Context);
    size_t context_stack_size;
    memcpy(
        &context_stack_size,
        &buffer[buffer_offset],
        sizeof(size_t));
    buffer_offset += sizeof(size_t);

    size_t context_stack_end = buffer_offset + context_stack_size;
    while (buffer_offset < context_stack_end) {
        Context *copied_context = ts_malloc(context_size);
        memcpy(
            copied_context,
            &buffer[buffer_offset],
            context_size);
        array_push(scanner->context_stack, copied_context);
        buffer_offset += context_size;
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
