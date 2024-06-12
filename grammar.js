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
        _eol: $ => seq(repeat(prec(2, $._ext_nih_whitespace)), $._ext_eol),
        nih_whitespace: $ => prec.right(repeat1(prec(1, $._ext_nih_whitespace))),
        // Note: _ext_eol is intentional here; we don't want to twice consume
        // optional trailing whitespace
        empty_line: $ => seq($._ext_empty_line, $._ext_eol),

        version_comment: $ => seq($._LITERAL_VERSION_COMMENT, $._eol),

        _node_segments: $ => seq(
            choice($.content_line, $._list, $.node),
            repeat(choice($.empty_line, $.content_line, $._list, $.node))),

        _embedding_segments: $ => seq(
            $.embedding_line,
            repeat(choice($.embedding_line, $.empty_line))),

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
            $.inline_richtext,
            $._eol,
            repeat(choice(
                seq(
                    $._ext_node_continue,
                    $._ext_list_continue,
                    $._ext_list_hangar,
                    $.inline_richtext,
                    $._eol),
                $._list))),

        unordered_list_item: $ => seq(
            $._ext_node_continue,
            $._ext_list_continue,
            $._ext_ul_marker,
            repeat($._ext_nih_whitespace),
            $.inline_richtext,
            $._eol,
            repeat(choice(
                seq(
                    $._ext_node_continue,
                    $._ext_list_continue,
                    $._ext_list_hangar,
                    $.inline_richtext,
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
            $.node_metadata_declaration_line,
            repeat(choice($.empty_line, $.node_metadata_declaration_line))),

        // Note that the node title marker is ambiguous with the node line
        // content
        node_title_line: $ => seq(
            $._ext_node_continue,
            $._ext_node_def_symbol,
            repeat($.nih_whitespace),
            optional($.inline_richtext),
            $._eol),

        node_metadata_declaration_line: $ => seq(
            $._ext_node_continue,
            $.node_metadata_key,
            $._SYMBOL_METADATA_ASSIGNMENT,
            repeat($.nih_whitespace),
            $.metadata_value,
            $._eol),

        content_line: $ => seq(
            $._ext_node_continue, $.inline_richtext, $._eol),

        embedding_line: $ => seq(
            $._ext_node_continue, $.inline_embedding, $._eol),

        // Note: this gets used in both content lines and in titles, however,
        // it **does not** include lists!
        // TODO: this should be a non-terminal, and support all of the
        // formatting etc
        inline_richtext: $ => /[^\n]+/,
        inline_embedding: $ => /[^\n]+/,

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
            $.MISSING
            // TODO: mappings and sequences!
            ),
        uni_letter: $ => /\p{L}/u,
        uni_modifier: $ => /\p{M}/u,
        uni_number: $ => /\p{N}/u,
        uni_underscore: $ => '_',
        uni_hyphen: $ => '-',
        uni_dot: $ => '.',
        uni_fslash: $ => '/',
        uni_bslash: $ => '\\',
        uni_pipe: $ => '|',
        uni_bracket_sq1: $ => '[',
        uni_bracket_sq2: $ => ']',
        uni_bracket_cur1: $ => '{',
        uni_bracket_cur2: $ => '}',
        uni_hash: $ => '#',
        uni_dollar: $ => '$',
        uni_at: $ => '@',
        uni_ampersand: $ => '&',
        uni_caret: $ => '^',
        uni_backtick: $ => '`',
        uni_asterisk: $ => '*',

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
        _SYMBOL_SINGLE_QUOTE: $ => "'",
        _SYMBOL_DOUBLE_QUOTE: $ => '"'
    },

    externals: $ => [
        $._error_sentinel,
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

        $._ext_eof,
        $.autoclose_warning
    ],
});
