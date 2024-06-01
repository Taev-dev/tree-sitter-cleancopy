/* NAMING CONVENTIONS:

++  ``*_line`` includes the leading whitespace and trailing EOL
++  ``inline_*`` does not
*/
module.exports = grammar({
    name: 'cleancopy',

    // Skip carriage returns (should normalize the line endings)
    // Note that, because treesitter supports neither the start-of-line
    // assertion nor zero-width matches, we cannot include empty line here
    extras: ($) => ['\r'],

    conflicts: $ => [
        [$._pending_regular_node, $._pending_embed_node]],

    rules: {
        document: $ => seq(
            optional($.version_comment),
            // Note that a completely empty file will still emit an empty line
            // token, so this counts as repeat1
            prec.left(repeat1($._node_segment)),
            $._eod_sentinel),
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

        _node_segment: $ => choice(
            $.empty_line,
            $.content_line,
            $.node),

        content_line: $ => seq(
            $._ext_node_continue, $.inline_richtext, $._eol),

        // Note that the node title marker is ambiguous with the node line
        // content
        node: $ => seq(
            $.node_title_line,
            repeat(choice(
                prec(4, $.empty_line),
                $.node_title_line)),
            choice($._pending_embed_node, $._pending_regular_node)),

        node_title_line: $ => seq(
            $._ext_node_continue,
            // THIS IS REQUIRED! Tree sitter expects two terminals to be
            // mutually exclusive, evidently. At any rate, it has no way to
            // notice that the content line includes the node def, unless you
            // let the external scanner force it to do so.
            $._ext_flag_node_def,
            $._SYMBOL_NODE_DEF,
            repeat($.nih_whitespace),
            optional($.inline_richtext),
            $._eol),

        // Note: this gets used in both content lines and in titles, however,
        // it **does not** include lists!
        // TODO: this should be a non-terminal, and support all of the
        // formatting etc
        inline_richtext: $ => /[^\n]+/,
        inline_embedding: $ => /[^\n]+/,


        // ... I'm not entirely sure if these two prec(1, ...) and prec(2, ...)
        // are correct?
        _pending_regular_node: $ => seq(
            // Word to the wise: don't try and enforce only-1-ID-line here.
            // You'll regret it! Do it when converting the CST -> AST.
            repeat(choice(
                $.node_metadata_declaration,
                prec(3, $.empty_line))),
            choice(
                seq(
                    $._ext_node_begin,
                    repeat1($._node_segment),
                    $._ext_node_end),
                seq(
                    $._ext_node_continue,
                    $.SYMBOL_EMPTY_NODE,
                    $._eol))),
        // Higher precedence because otherwise the embed could be matched in
        // the regular
        _pending_embed_node: $ => seq(
            // Word to the wise: don't try and enforce only-1-ID-line here.
            // You'll regret it! Do it when converting the CST -> AST.
            repeat(choice(
                $.node_metadata_declaration,
                prec(2, $.empty_line))),
            prec(3, $.node_embed_declaration),
            repeat(choice(
                $.node_metadata_declaration,
                prec(3, $.empty_line))),
            choice(
                seq(
                    $._ext_node_begin,
                    repeat1(seq(
                        $._ext_node_continue,
                        $.inline_embedding,
                        $._eol)),
                    $._ext_node_end),
                seq(
                    $._ext_node_continue,
                    $.SYMBOL_EMPTY_NODE,
                    $._eol))),

        node_embed_declaration: $ => seq(
            $._ext_node_continue,
            $._LITERAL_NODE_EMBED_DECLARATION,
            $._SYMBOL_METADATA_ASSIGNMENT,
            repeat($.nih_whitespace),
            $.embed_type,
            $._eol),
        node_metadata_declaration: $ => seq(
            $._ext_node_continue,
            $.metadata_key,
            $._SYMBOL_METADATA_ASSIGNMENT,
            repeat($.nih_whitespace),
            $.metadata_value,
            $._eol),



        embed_type: $ => $._string,
        // This looks way more complicated than it is; we want to support
        // unicode letters (including letters with marks on them) and the
        // underscore as the first character, and then add in the -, ., and
        // 0-9 as following characters
        metadata_key: $ => /(\p{L}\p{M}*|_)(\p{L}\p{M}*|[0-9_\-\.])*/u,
        metadata_value: $ => choice(
            $._string
            // TODO: other metadata values go here!
            ),




        _string: $ => choice(
            seq(
                $._SYMBOL_SINGLE_QUOTE,
                $._string_single,
                $._SYMBOL_SINGLE_QUOTE),

            seq(
                $._SYMBOL_DOUBLE_QUOTE,
                $._string_double,
                $._SYMBOL_DOUBLE_QUOTE)),
        _string_single: $ => seq(
            $.STRING1,
            repeat(seq($._eol, $._ext_node_continue, $.STRING1))),
        _string_double: $ => seq(
            $.STRING2,
            repeat(seq($._eol, $._ext_node_continue, $.STRING2))),

        STRING1: $ => /(\\'|[^'])+/,
        STRING2: $ => /(\\"|[^"])+/,


        _LITERAL_VERSION_COMMENT: $ => '<<<cleancopy>>>',
        // _LITERAL_NODE_ID_DECLARATION: $ => 'id',
        _LITERAL_NODE_EMBED_DECLARATION: $ => 'embed',

        // Note that this includes any trailing whitespace
        // Also note: this character class is whitespace EXCEPT newlines (see
        // https://stackoverflow.com/a/3469155). We do this so that we don't
        // accidentally consume empty lines following an EOL.
        _LITERAL_EOL: $ => /[^\S\r\n]*\n/,

        _SYMBOL_NODE_DEF: $ => '>',
        _SYMBOL_METADATA_ASSIGNMENT: $ => ':',
        SYMBOL_EMPTY_NODE: $ => '<',
        _SYMBOL_SINGLE_QUOTE: $ => "'",
        _SYMBOL_DOUBLE_QUOTE: $ => '"'
    },

    externals: $ => [
        $._error_sentinel,
        $._eod_sentinel,
        $._ext_eol,
        $._ext_empty_line,
        $._ext_nih_whitespace,
        $._ext_node_continue,
        $._ext_flag_node_def,
        $._ext_node_begin,
        $._ext_node_end,
        $.autoclose_warning
    ],
});
