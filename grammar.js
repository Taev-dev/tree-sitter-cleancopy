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
    conflicts: ($) => [[$.node_title], [$.node_metadata]],

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
            choice($.content_line, $.node),
            repeat(choice($.empty_line, $.content_line, $.node))),

        _embedding_segments: $ => seq(
            $.embedding_line,
            repeat(choice($.embedding_line, $.empty_line))),

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
            $._node_metadata_sentinel,
            $.metadata_key,
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

        _SYMBOL_METADATA_ASSIGNMENT: $ => ':',
        _SYMBOL_SINGLE_QUOTE: $ => "'",
        _SYMBOL_DOUBLE_QUOTE: $ => '"'
    },

    externals: $ => [
        $._error_sentinel,
        $._node_metadata_sentinel,
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
        $._ext_eof,
        $.autoclose_warning
    ],
});
