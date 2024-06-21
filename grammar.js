/* NAMING CONVENTIONS:

++  ``*_line`` includes the leading whitespace and trailing EOL
++  ``inline_*`` does not
*/
module.exports = grammar({
    name: 'cleancopy',

    extras: ($) => [],

    // I can't, no matter how hard I try, get these conflicts to resolve within
    // the grammar. I've even tried grammars I'm 99% sure are conflict-free.
    // It just doesn't work. But for whatever fucking reason, this does the
    // trick.
    conflicts: ($) => [
        [$.node_title],
        [$.node_metadata],
        [$.unordered_list_item],
        [$.ordered_list_item]],

    rules: {
        document: $ => seq(
            optional($.version_comment),
            repeat($.empty_line),
            prec.left($._node_segments),
            $._ext_eof),
        // Sometimes we have situations where some optional stuff results in
        // other nih whitespace being next to the EoL. One example is if you
        // have a node title line with whitespace but no title. In this case,
        // we want the EoL to swallow the whitespace.
        _eol: $ => seq(repeat(prec(2, $._ext_trailing_whitespace)), $._ext_eol),
        // Note: _ext_eol is intentional here; we don't want to twice consume
        // optional trailing whitespace
        empty_line: $ => seq($._ext_empty_line, $._ext_eol),

        version_comment: $ => seq($._LITERAL_VERSION_COMMENT, $._eol),

        _node_segments: $ => seq(
            choice(
                $._annotation_line_incl_ws,
                $._richtext_line_incl_ws, $._list, $.node),
            repeat(choice(
                $.empty_line, $._annotation_line_incl_ws,
                $._richtext_line_incl_ws, $._list, $.node))),

        _embedding_segments: $ => seq(
            $._embedding_line_incl_ws,
            repeat(choice($._embedding_line_incl_ws, $.empty_line))),

        _list: $ => seq(
            $._ext_list_begin,
            choice($.ordered_list, $.unordered_list),
            $._ext_list_end),

        ordered_list: $ => repeat1($.ordered_list_item),
        unordered_list: $ => repeat1($.unordered_list_item),

        ordered_list_item: $ => seq(
            $._ext_node_continue,
            $._ext_list_continue,
            field('index', $._ext_ol_index),
            $._ext_ol_marker,
            repeat($._ext_nih_whitespace),
            $.richtext_line,
            $._eol,
            repeat(choice(
                seq(
                    $._ext_node_continue,
                    $._ext_list_continue,
                    $._ext_list_hangar,
                    choice($.richtext_line, $.annotation_line),
                    $._eol),
                $._list))),

        unordered_list_item: $ => seq(
            $._ext_node_continue,
            $._ext_list_continue,
            $._ext_ul_marker,
            repeat($._ext_nih_whitespace),
            $.richtext_line,
            $._eol,
            repeat(choice(
                seq(
                    $._ext_node_continue,
                    $._ext_list_continue,
                    $._ext_list_hangar,
                    choice($.richtext_line, $.annotation_line),
                    $._eol),
                $._list))),

        node: $ => seq(
            field('title', $.node_title),
            field('metadata', optional($.node_metadata)),
            // This is messy, and forces us to do out-of-order zero-width
            // tokens to flag embedded nodes, but... I tried a lot of other
            // stuff and couldn't get it to work.
            choice(
                seq(
                    $._ext_node_begin,
                    choice(
                        field('embed', seq(
                            $._ext_flag_embed, $._embedding_segments)),
                        field('content', $._node_segments)),
                    $._ext_node_end),
                seq(
                    $._ext_node_continue,
                    $._ext_empty_node,
                    $._eol))),

        node_title: $ => seq(
            $.node_title_line,
            repeat(choice($.empty_line, $.node_title_line))),

        // Word to the wise: don't try and enforce only-1-ID-line here.
        // You'll regret it! Do it when converting the CST -> AST.
        node_metadata: $ => seq(
            choice($._annotation_line_incl_ws, $.node_metadata_declaration_line),
            repeat(choice(
                $.empty_line,
                $.node_metadata_declaration_line,
                $._annotation_line_incl_ws))),

        // Note that the node title marker is ambiguous with the node line
        // content
        node_title_line: $ => seq(
            $._ext_node_continue,
            $._ext_node_def_symbol,
            repeat($._ext_nih_whitespace),
            optional($.richtext_line),
            $._eol),

        node_metadata_declaration_line: $ => seq(
            $._ext_node_continue,
            $.node_metadata_key,
            $._SYMBOL_METADATA_ASSIGNMENT,
            repeat($._ext_nih_whitespace),
            $.metadata_value,
            $._eol),

        inline_metadata_declaration: $ => seq(
            $.node_metadata_key,
            $._SYMBOL_METADATA_ASSIGNMENT,
            repeat($._ext_nih_whitespace),
            $.metadata_value),

        inline_metadata: $ => seq(
            $.inline_metadata_declaration,
            repeat(seq(
                $._SYMBOL_METADATA_SEPARATOR,
                repeat($._ext_nih_whitespace),
                $.inline_metadata_declaration))),

        _richtext_line_incl_ws: $ => seq(
            $._ext_node_continue, $.richtext_line, $._eol),

        _embedding_line_incl_ws: $ => seq(
            $._ext_node_continue, alias($.plaintext, $.embedding_line), $._eol),
        _annotation_line_incl_ws: $ => seq(
            $._ext_node_continue, $.annotation_line, $._eol),

        // Note: this gets used in both content lines and in titles, however,
        // it **does not** include lists!
        // TODO: this should be a non-terminal, and support all of the
        // formatting etc
        richtext_line: $ => repeat1(choice(
            // Note: We can't use the existing $.plaintext rule because we'd
            // then need a prec.right in $.plaintext, but the prec.right would
            // then screw up all of the other rules that use plaintext. So
            // instead we alias it like this. Suuuuper annoying. And then, to
            // add insult to injury, we **also** need to force external scanning
            // for it, because otherwise treesitter gets hyper-focused on the
            // plaintext char and never triggers discovery of any of the
            // formatting. FFS.
            alias(prec.right(repeat1($._ext_richtext_char)), $.plaintext),
            $._ext_fmt_unescape,
            $._fmt_bracket)),

        plaintext: $ => repeat1($._plaintext_char),
        // Plaintext chars ... explicitly forbid newline, though I guess
        // because of the way we're always throwing things to the external
        // scanner, this probably isn't necessary? At any rate, we can't really
        // have duplicate terminals in tree-sitter, so this gets used anywhere
        // we need plaintext
        _plaintext_char: $ => /[^\n]/,
        annotation_line: $ => seq(
            $._ext_annotation_marker,
            repeat($._ext_nih_whitespace),
            field('comment', repeat($._plaintext_char))),

        // This is a (semi-deliberate) bug / departure from the spec, in
        // the interests of substantially simplifying parsing (by allowing
        // treesitter to handle all strings, instead of the external scanner)
        node_metadata_key: $ => choice($._ext_metadata_key, $._string_multiline),

        // This looks way more complicated than it is; we want to support
        // unicode letters (including letters with marks on them) and the
        // underscore as the first character, and then add in the -, ., and
        // 0-9 as following characters
        metadata_value: $ => choice(
            $._string_multiline,
            $._boolean,
            $.integer,
            $.decimal,
            $.NULL,
            $.MISSING,
            $.mention,
            $.tag,
            $.variable,
            $.ref
            // TODO: mappings and sequences!
            ),
        // uni_letter: $ => /\p{L}/u,
        // uni_modifier: $ => /\p{M}/u,
        // uni_number: $ => /\p{N}/u,
        // uni_underscore: $ => '_',
        // uni_hyphen: $ => '-',
        // uni_dot: $ => '.',
        // uni_fslash: $ => '/',
        // uni_bslash: $ => '\\',
        // uni_pipe: $ => '|',
        // uni_bracket_sq1: $ => '[',
        // uni_bracket_sq2: $ => ']',
        // uni_bracket_cur1: $ => '{',
        // uni_bracket_cur2: $ => '}',
        // uni_hash: $ => '#',
        // uni_dollar: $ => '$',
        // uni_at: $ => '@',
        // uni_ampersand: $ => '&',
        // uni_caret: $ => '^',
        // uni_backtick: $ => '`',
        // uni_asterisk: $ => '*',

        _string: $ => choice(
            seq(
                $._SYMBOL_SINGLE_QUOTE,
                $.STRING1,
                $._SYMBOL_SINGLE_QUOTE),
            seq(
                $._SYMBOL_DOUBLE_QUOTE,
                $.STRING2,
                $._SYMBOL_DOUBLE_QUOTE)),
        _string_multiline: $ => choice(
            seq(
                $._SYMBOL_SINGLE_QUOTE,
                $._string1_multiline,
                $._SYMBOL_SINGLE_QUOTE),

            seq(
                $._SYMBOL_DOUBLE_QUOTE,
                $._string2_multiline,
                $._SYMBOL_DOUBLE_QUOTE)),
        _string1_multiline: $ => seq(
            $.STRING1,
            repeat(seq($._eol, $._ext_node_continue, $.STRING1))),
        _string2_multiline: $ => seq(
            $.STRING2,
            repeat(seq($._eol, $._ext_node_continue, $.STRING2))),

        _boolean: $ => choice($.TRUE, $.FALSE),
        integer: $ => repeat1($._DIGIT),
        decimal: $ => seq(
            repeat1($._DIGIT), $._DECIMAL_SEPARATOR, repeat($._DIGIT)),

        mention: $ => seq(
            '@', field('target', choice($._string, $._sugared_string))),
        tag: $ => seq(
            '#', field('target', choice($._string, $._sugared_string))),
        variable: $ => seq(
            '$', field('target', choice($._string, $._sugared_string))),
        ref: $ => seq(
            '&', field('target', choice($._string, $._sugared_string))),
        // Note: these are only valid in brackets, NOT as a normal metadata
        // value!
        uri: $ => field('target', choice($._string, $._sugared_uri)),

        // These are used for @mentions, #tags, etc
        _sugared_string: $ => /[^\s'"\[\]\{\}\(\)@#$&;]+/,
        // RFC 2396, Appendix A describes valid characters for the schema,
        // which we use to force non-collision with @mentions, #tags, etc
        _sugared_uri: $ => /[A-z]([A-z0-9\+\-\.])*:[A-Za-z0-9-._~:/?#@!$&*+,%=]+/,

        // TODO: these aren't working right for multiline strings; it's
        // consuming the newline and I'm not sure how. Unfortunately I think
        // we'll need to move this into the external scanner for it to work
        // completely right. The problem is that it's erroneously collapsing
        // multiline strings into a single string, including the newline and
        // continuation etc
        STRING1: $ => /([^\\\n]\\'|[^\n'])+/,
        STRING2: $ => /([^\\\n]\\"|[^\n"])+/,

        TRUE: $ => 'true',
        FALSE: $ => 'false',
        NULL: $ => 'null',
        MISSING: $ => '__missing__',
        // TODO: move these into the external scanner (for consistency w/
        // identifiers and greater flexibility)
        _DIGIT: $ => /[0-9]/,
        _DECIMAL_SEPARATOR: $ => '.',


        _LITERAL_VERSION_COMMENT: $ => '<<<cleancopy>>>',

        _SYMBOL_METADATA_ASSIGNMENT: $ => ':',
        _SYMBOL_METADATA_SEPARATOR: $ => ';',
        _SYMBOL_SINGLE_QUOTE: $ => "'",
        _SYMBOL_DOUBLE_QUOTE: $ => '"',

        _fmt_bracket: $ => seq(
            $._ext_fmt_bracket_open,
            choice(
                prec.dynamic(3, $.fmt_bracket_anon_link),
                prec.dynamic(2, $.fmt_bracket_named_link),
                prec.dynamic(1, $.fmt_bracket_metadata))),

        fmt_bracket_anon_link: $ => seq(
            $.richtext_line,
            // choice($.mention, $.tag, $.variable, $.ref, $.uri),
            $._ext_fmt_bracket_close_anon_link),
        fmt_bracket_named_link: $ => seq(
            $.richtext_line,
            $._ext_fmt_bracket_delimit_named_link,
            $.richtext_line,
            // choice($.mention, $.tag, $.variable, $.ref, $.uri),
            $._ext_fmt_bracket_close_named_link),
        fmt_bracket_metadata: $ => seq(
            $.richtext_line,
            $._ext_fmt_bracket_delimit_metadata,
            $.inline_metadata,
            $._ext_fmt_bracket_close_metadata)
    },

    externals: $ => [
        $._treesitter_error_sentinel,
        $._ext_metadata_key,
        // Note that we need this to be external so that we can manage the
        // internal state for the scanner -- we may have previously marked
        // the pending node as an embedded one, and that needs to be cleared
        // so we don't accidentally mark the next one as embedded
        $._ext_empty_node,
        $._ext_flag_embed,
        // Note that this MUST be external for lexing to happen correctly.
        // The problem is: treesitter doesn't have a robust mechanism for
        // defining terminal precedence. So we can't say "try the node def
        // symbol before trying anything else". Because an entire empty
        // node declaration could also be parsed as plain node content of the
        // parent node, that means we have to trigger something to preempt the
        // internal lexer -- which we can simply do by handling the node def
        // symbol in the external scanner.
        $._ext_node_def_symbol,
        $._ext_eol,
        $._ext_empty_line,
        $._ext_nih_whitespace,
        $._ext_trailing_whitespace,
        $._ext_node_continue,
        $._ext_node_begin,
        $._ext_node_end,
        $._ext_list_continue,
        $._ext_list_hangar,
        $._ext_list_begin,
        $._ext_list_end,
        $._ext_ol_index,
        $._ext_ol_marker,
        $._ext_ul_marker,
        $._ext_annotation_marker,
        $._ext_eof,
        $._ext_fmt_escape_pipe,
        $._ext_fmt_escape_backslash,
        $._ext_fmt_unescape,
        $._ext_fmt_code,
        $._ext_fmt_underline,
        $._ext_fmt_strong,
        $._ext_fmt_emphasis,
        $._ext_fmt_strike,
        $._ext_fmt_bracket_open,
        $._ext_fmt_bracket_delimit_named_link,
        $._ext_fmt_bracket_delimit_metadata,
        $._ext_fmt_bracket_close_anon_link,
        $._ext_fmt_bracket_close_named_link,
        $._ext_fmt_bracket_close_metadata,
        $._ext_richtext_char,
        $._scanner_error_sentinel
    ],
});
