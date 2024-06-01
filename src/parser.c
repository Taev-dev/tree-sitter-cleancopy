#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 178
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 52
#define ALIAS_COUNT 0
#define TOKEN_COUNT 22
#define EXTERNAL_TOKEN_COUNT 10
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  aux_sym_inline_richtext_token1 = 1,
  sym_metadata_key = 2,
  sym_STRING1 = 3,
  sym_STRING2 = 4,
  sym__LITERAL_VERSION_COMMENT = 5,
  sym__LITERAL_NODE_EMBED_DECLARATION = 6,
  sym__SYMBOL_NODE_DEF = 7,
  sym__SYMBOL_METADATA_ASSIGNMENT = 8,
  sym_SYMBOL_EMPTY_NODE = 9,
  sym__SYMBOL_SINGLE_QUOTE = 10,
  sym__SYMBOL_DOUBLE_QUOTE = 11,
  sym__error_sentinel = 12,
  sym__eod_sentinel = 13,
  sym__ext_eol = 14,
  sym__ext_empty_line = 15,
  sym__ext_nih_whitespace = 16,
  sym__ext_node_continue = 17,
  sym__ext_flag_node_def = 18,
  sym__ext_node_begin = 19,
  sym__ext_node_end = 20,
  sym_autoclose_warning = 21,
  sym_document = 22,
  sym__eol = 23,
  sym_nih_whitespace = 24,
  sym_empty_line = 25,
  sym_version_comment = 26,
  sym__node_segment = 27,
  sym_content_line = 28,
  sym_node = 29,
  sym_node_title_line = 30,
  sym_inline_richtext = 31,
  sym_inline_embedding = 32,
  sym__pending_regular_node = 33,
  sym__pending_embed_node = 34,
  sym_node_embed_declaration = 35,
  sym_node_metadata_declaration = 36,
  sym_embed_type = 37,
  sym_metadata_value = 38,
  sym__string = 39,
  sym__string_single = 40,
  sym__string_double = 41,
  aux_sym_document_repeat1 = 42,
  aux_sym__eol_repeat1 = 43,
  aux_sym_nih_whitespace_repeat1 = 44,
  aux_sym_node_repeat1 = 45,
  aux_sym_node_title_line_repeat1 = 46,
  aux_sym__pending_regular_node_repeat1 = 47,
  aux_sym__pending_embed_node_repeat1 = 48,
  aux_sym__pending_embed_node_repeat2 = 49,
  aux_sym__string_single_repeat1 = 50,
  aux_sym__string_double_repeat1 = 51,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_inline_richtext_token1] = "inline_richtext_token1",
  [sym_metadata_key] = "metadata_key",
  [sym_STRING1] = "STRING1",
  [sym_STRING2] = "STRING2",
  [sym__LITERAL_VERSION_COMMENT] = "_LITERAL_VERSION_COMMENT",
  [sym__LITERAL_NODE_EMBED_DECLARATION] = "_LITERAL_NODE_EMBED_DECLARATION",
  [sym__SYMBOL_NODE_DEF] = "_SYMBOL_NODE_DEF",
  [sym__SYMBOL_METADATA_ASSIGNMENT] = "_SYMBOL_METADATA_ASSIGNMENT",
  [sym_SYMBOL_EMPTY_NODE] = "SYMBOL_EMPTY_NODE",
  [sym__SYMBOL_SINGLE_QUOTE] = "_SYMBOL_SINGLE_QUOTE",
  [sym__SYMBOL_DOUBLE_QUOTE] = "_SYMBOL_DOUBLE_QUOTE",
  [sym__error_sentinel] = "_error_sentinel",
  [sym__eod_sentinel] = "_eod_sentinel",
  [sym__ext_eol] = "_ext_eol",
  [sym__ext_empty_line] = "_ext_empty_line",
  [sym__ext_nih_whitespace] = "_ext_nih_whitespace",
  [sym__ext_node_continue] = "_ext_node_continue",
  [sym__ext_flag_node_def] = "_ext_flag_node_def",
  [sym__ext_node_begin] = "_ext_node_begin",
  [sym__ext_node_end] = "_ext_node_end",
  [sym_autoclose_warning] = "autoclose_warning",
  [sym_document] = "document",
  [sym__eol] = "_eol",
  [sym_nih_whitespace] = "nih_whitespace",
  [sym_empty_line] = "empty_line",
  [sym_version_comment] = "version_comment",
  [sym__node_segment] = "_node_segment",
  [sym_content_line] = "content_line",
  [sym_node] = "node",
  [sym_node_title_line] = "node_title_line",
  [sym_inline_richtext] = "inline_richtext",
  [sym_inline_embedding] = "inline_embedding",
  [sym__pending_regular_node] = "_pending_regular_node",
  [sym__pending_embed_node] = "_pending_embed_node",
  [sym_node_embed_declaration] = "node_embed_declaration",
  [sym_node_metadata_declaration] = "node_metadata_declaration",
  [sym_embed_type] = "embed_type",
  [sym_metadata_value] = "metadata_value",
  [sym__string] = "_string",
  [sym__string_single] = "_string_single",
  [sym__string_double] = "_string_double",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym__eol_repeat1] = "_eol_repeat1",
  [aux_sym_nih_whitespace_repeat1] = "nih_whitespace_repeat1",
  [aux_sym_node_repeat1] = "node_repeat1",
  [aux_sym_node_title_line_repeat1] = "node_title_line_repeat1",
  [aux_sym__pending_regular_node_repeat1] = "_pending_regular_node_repeat1",
  [aux_sym__pending_embed_node_repeat1] = "_pending_embed_node_repeat1",
  [aux_sym__pending_embed_node_repeat2] = "_pending_embed_node_repeat2",
  [aux_sym__string_single_repeat1] = "_string_single_repeat1",
  [aux_sym__string_double_repeat1] = "_string_double_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_inline_richtext_token1] = aux_sym_inline_richtext_token1,
  [sym_metadata_key] = sym_metadata_key,
  [sym_STRING1] = sym_STRING1,
  [sym_STRING2] = sym_STRING2,
  [sym__LITERAL_VERSION_COMMENT] = sym__LITERAL_VERSION_COMMENT,
  [sym__LITERAL_NODE_EMBED_DECLARATION] = sym__LITERAL_NODE_EMBED_DECLARATION,
  [sym__SYMBOL_NODE_DEF] = sym__SYMBOL_NODE_DEF,
  [sym__SYMBOL_METADATA_ASSIGNMENT] = sym__SYMBOL_METADATA_ASSIGNMENT,
  [sym_SYMBOL_EMPTY_NODE] = sym_SYMBOL_EMPTY_NODE,
  [sym__SYMBOL_SINGLE_QUOTE] = sym__SYMBOL_SINGLE_QUOTE,
  [sym__SYMBOL_DOUBLE_QUOTE] = sym__SYMBOL_DOUBLE_QUOTE,
  [sym__error_sentinel] = sym__error_sentinel,
  [sym__eod_sentinel] = sym__eod_sentinel,
  [sym__ext_eol] = sym__ext_eol,
  [sym__ext_empty_line] = sym__ext_empty_line,
  [sym__ext_nih_whitespace] = sym__ext_nih_whitespace,
  [sym__ext_node_continue] = sym__ext_node_continue,
  [sym__ext_flag_node_def] = sym__ext_flag_node_def,
  [sym__ext_node_begin] = sym__ext_node_begin,
  [sym__ext_node_end] = sym__ext_node_end,
  [sym_autoclose_warning] = sym_autoclose_warning,
  [sym_document] = sym_document,
  [sym__eol] = sym__eol,
  [sym_nih_whitespace] = sym_nih_whitespace,
  [sym_empty_line] = sym_empty_line,
  [sym_version_comment] = sym_version_comment,
  [sym__node_segment] = sym__node_segment,
  [sym_content_line] = sym_content_line,
  [sym_node] = sym_node,
  [sym_node_title_line] = sym_node_title_line,
  [sym_inline_richtext] = sym_inline_richtext,
  [sym_inline_embedding] = sym_inline_embedding,
  [sym__pending_regular_node] = sym__pending_regular_node,
  [sym__pending_embed_node] = sym__pending_embed_node,
  [sym_node_embed_declaration] = sym_node_embed_declaration,
  [sym_node_metadata_declaration] = sym_node_metadata_declaration,
  [sym_embed_type] = sym_embed_type,
  [sym_metadata_value] = sym_metadata_value,
  [sym__string] = sym__string,
  [sym__string_single] = sym__string_single,
  [sym__string_double] = sym__string_double,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym__eol_repeat1] = aux_sym__eol_repeat1,
  [aux_sym_nih_whitespace_repeat1] = aux_sym_nih_whitespace_repeat1,
  [aux_sym_node_repeat1] = aux_sym_node_repeat1,
  [aux_sym_node_title_line_repeat1] = aux_sym_node_title_line_repeat1,
  [aux_sym__pending_regular_node_repeat1] = aux_sym__pending_regular_node_repeat1,
  [aux_sym__pending_embed_node_repeat1] = aux_sym__pending_embed_node_repeat1,
  [aux_sym__pending_embed_node_repeat2] = aux_sym__pending_embed_node_repeat2,
  [aux_sym__string_single_repeat1] = aux_sym__string_single_repeat1,
  [aux_sym__string_double_repeat1] = aux_sym__string_double_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_inline_richtext_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_metadata_key] = {
    .visible = true,
    .named = true,
  },
  [sym_STRING1] = {
    .visible = true,
    .named = true,
  },
  [sym_STRING2] = {
    .visible = true,
    .named = true,
  },
  [sym__LITERAL_VERSION_COMMENT] = {
    .visible = false,
    .named = true,
  },
  [sym__LITERAL_NODE_EMBED_DECLARATION] = {
    .visible = false,
    .named = true,
  },
  [sym__SYMBOL_NODE_DEF] = {
    .visible = false,
    .named = true,
  },
  [sym__SYMBOL_METADATA_ASSIGNMENT] = {
    .visible = false,
    .named = true,
  },
  [sym_SYMBOL_EMPTY_NODE] = {
    .visible = true,
    .named = true,
  },
  [sym__SYMBOL_SINGLE_QUOTE] = {
    .visible = false,
    .named = true,
  },
  [sym__SYMBOL_DOUBLE_QUOTE] = {
    .visible = false,
    .named = true,
  },
  [sym__error_sentinel] = {
    .visible = false,
    .named = true,
  },
  [sym__eod_sentinel] = {
    .visible = false,
    .named = true,
  },
  [sym__ext_eol] = {
    .visible = false,
    .named = true,
  },
  [sym__ext_empty_line] = {
    .visible = false,
    .named = true,
  },
  [sym__ext_nih_whitespace] = {
    .visible = false,
    .named = true,
  },
  [sym__ext_node_continue] = {
    .visible = false,
    .named = true,
  },
  [sym__ext_flag_node_def] = {
    .visible = false,
    .named = true,
  },
  [sym__ext_node_begin] = {
    .visible = false,
    .named = true,
  },
  [sym__ext_node_end] = {
    .visible = false,
    .named = true,
  },
  [sym_autoclose_warning] = {
    .visible = true,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym__eol] = {
    .visible = false,
    .named = true,
  },
  [sym_nih_whitespace] = {
    .visible = true,
    .named = true,
  },
  [sym_empty_line] = {
    .visible = true,
    .named = true,
  },
  [sym_version_comment] = {
    .visible = true,
    .named = true,
  },
  [sym__node_segment] = {
    .visible = false,
    .named = true,
  },
  [sym_content_line] = {
    .visible = true,
    .named = true,
  },
  [sym_node] = {
    .visible = true,
    .named = true,
  },
  [sym_node_title_line] = {
    .visible = true,
    .named = true,
  },
  [sym_inline_richtext] = {
    .visible = true,
    .named = true,
  },
  [sym_inline_embedding] = {
    .visible = true,
    .named = true,
  },
  [sym__pending_regular_node] = {
    .visible = false,
    .named = true,
  },
  [sym__pending_embed_node] = {
    .visible = false,
    .named = true,
  },
  [sym_node_embed_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_node_metadata_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_embed_type] = {
    .visible = true,
    .named = true,
  },
  [sym_metadata_value] = {
    .visible = true,
    .named = true,
  },
  [sym__string] = {
    .visible = false,
    .named = true,
  },
  [sym__string_single] = {
    .visible = false,
    .named = true,
  },
  [sym__string_double] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__eol_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_nih_whitespace_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_node_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_node_title_line_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__pending_regular_node_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__pending_embed_node_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__pending_embed_node_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__string_single_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__string_double_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 2,
  [4] = 4,
  [5] = 4,
  [6] = 6,
  [7] = 6,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 8,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 12,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 17,
  [20] = 20,
  [21] = 21,
  [22] = 18,
  [23] = 23,
  [24] = 24,
  [25] = 21,
  [26] = 23,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 28,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 32,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 31,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 41,
  [45] = 37,
  [46] = 34,
  [47] = 47,
  [48] = 47,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 50,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 59,
  [62] = 62,
  [63] = 57,
  [64] = 64,
  [65] = 55,
  [66] = 66,
  [67] = 64,
  [68] = 68,
  [69] = 69,
  [70] = 52,
  [71] = 53,
  [72] = 72,
  [73] = 56,
  [74] = 60,
  [75] = 75,
  [76] = 75,
  [77] = 68,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 81,
  [92] = 92,
  [93] = 86,
  [94] = 86,
  [95] = 79,
  [96] = 86,
  [97] = 97,
  [98] = 86,
  [99] = 97,
  [100] = 83,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 86,
  [110] = 110,
  [111] = 111,
  [112] = 85,
  [113] = 88,
  [114] = 114,
  [115] = 101,
  [116] = 78,
  [117] = 108,
  [118] = 78,
  [119] = 119,
  [120] = 107,
  [121] = 85,
  [122] = 119,
  [123] = 80,
  [124] = 84,
  [125] = 105,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 90,
  [130] = 130,
  [131] = 131,
  [132] = 85,
  [133] = 133,
  [134] = 78,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 127,
  [142] = 142,
  [143] = 143,
  [144] = 136,
  [145] = 133,
  [146] = 131,
  [147] = 147,
  [148] = 78,
  [149] = 138,
  [150] = 150,
  [151] = 103,
  [152] = 147,
  [153] = 142,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 159,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 159,
  [167] = 167,
  [168] = 168,
  [169] = 165,
  [170] = 163,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 159,
  [176] = 176,
  [177] = 78,
};

static TSCharacterRange sym_metadata_key_character_set_1[] = {
  {'A', 'Z'}, {'_', '_'}, {'a', 'z'}, {0xaa, 0xaa}, {0xb5, 0xb5}, {0xba, 0xba}, {0xc0, 0xd6}, {0xd8, 0xf6},
  {0xf8, 0x2c1}, {0x2c6, 0x2d1}, {0x2e0, 0x2e4}, {0x2ec, 0x2ec}, {0x2ee, 0x2ee}, {0x370, 0x374}, {0x376, 0x377}, {0x37a, 0x37d},
  {0x37f, 0x37f}, {0x386, 0x386}, {0x388, 0x38a}, {0x38c, 0x38c}, {0x38e, 0x3a1}, {0x3a3, 0x3f5}, {0x3f7, 0x481}, {0x48a, 0x52f},
  {0x531, 0x556}, {0x559, 0x559}, {0x560, 0x588}, {0x5d0, 0x5ea}, {0x5ef, 0x5f2}, {0x620, 0x64a}, {0x66e, 0x66f}, {0x671, 0x6d3},
  {0x6d5, 0x6d5}, {0x6e5, 0x6e6}, {0x6ee, 0x6ef}, {0x6fa, 0x6fc}, {0x6ff, 0x6ff}, {0x710, 0x710}, {0x712, 0x72f}, {0x74d, 0x7a5},
  {0x7b1, 0x7b1}, {0x7ca, 0x7ea}, {0x7f4, 0x7f5}, {0x7fa, 0x7fa}, {0x800, 0x815}, {0x81a, 0x81a}, {0x824, 0x824}, {0x828, 0x828},
  {0x840, 0x858}, {0x860, 0x86a}, {0x870, 0x887}, {0x889, 0x88e}, {0x8a0, 0x8c9}, {0x904, 0x939}, {0x93d, 0x93d}, {0x950, 0x950},
  {0x958, 0x961}, {0x971, 0x980}, {0x985, 0x98c}, {0x98f, 0x990}, {0x993, 0x9a8}, {0x9aa, 0x9b0}, {0x9b2, 0x9b2}, {0x9b6, 0x9b9},
  {0x9bd, 0x9bd}, {0x9ce, 0x9ce}, {0x9dc, 0x9dd}, {0x9df, 0x9e1}, {0x9f0, 0x9f1}, {0x9fc, 0x9fc}, {0xa05, 0xa0a}, {0xa0f, 0xa10},
  {0xa13, 0xa28}, {0xa2a, 0xa30}, {0xa32, 0xa33}, {0xa35, 0xa36}, {0xa38, 0xa39}, {0xa59, 0xa5c}, {0xa5e, 0xa5e}, {0xa72, 0xa74},
  {0xa85, 0xa8d}, {0xa8f, 0xa91}, {0xa93, 0xaa8}, {0xaaa, 0xab0}, {0xab2, 0xab3}, {0xab5, 0xab9}, {0xabd, 0xabd}, {0xad0, 0xad0},
  {0xae0, 0xae1}, {0xaf9, 0xaf9}, {0xb05, 0xb0c}, {0xb0f, 0xb10}, {0xb13, 0xb28}, {0xb2a, 0xb30}, {0xb32, 0xb33}, {0xb35, 0xb39},
  {0xb3d, 0xb3d}, {0xb5c, 0xb5d}, {0xb5f, 0xb61}, {0xb71, 0xb71}, {0xb83, 0xb83}, {0xb85, 0xb8a}, {0xb8e, 0xb90}, {0xb92, 0xb95},
  {0xb99, 0xb9a}, {0xb9c, 0xb9c}, {0xb9e, 0xb9f}, {0xba3, 0xba4}, {0xba8, 0xbaa}, {0xbae, 0xbb9}, {0xbd0, 0xbd0}, {0xc05, 0xc0c},
  {0xc0e, 0xc10}, {0xc12, 0xc28}, {0xc2a, 0xc39}, {0xc3d, 0xc3d}, {0xc58, 0xc5a}, {0xc5d, 0xc5d}, {0xc60, 0xc61}, {0xc80, 0xc80},
  {0xc85, 0xc8c}, {0xc8e, 0xc90}, {0xc92, 0xca8}, {0xcaa, 0xcb3}, {0xcb5, 0xcb9}, {0xcbd, 0xcbd}, {0xcdd, 0xcde}, {0xce0, 0xce1},
  {0xcf1, 0xcf2}, {0xd04, 0xd0c}, {0xd0e, 0xd10}, {0xd12, 0xd3a}, {0xd3d, 0xd3d}, {0xd4e, 0xd4e}, {0xd54, 0xd56}, {0xd5f, 0xd61},
  {0xd7a, 0xd7f}, {0xd85, 0xd96}, {0xd9a, 0xdb1}, {0xdb3, 0xdbb}, {0xdbd, 0xdbd}, {0xdc0, 0xdc6}, {0xe01, 0xe30}, {0xe32, 0xe33},
  {0xe40, 0xe46}, {0xe81, 0xe82}, {0xe84, 0xe84}, {0xe86, 0xe8a}, {0xe8c, 0xea3}, {0xea5, 0xea5}, {0xea7, 0xeb0}, {0xeb2, 0xeb3},
  {0xebd, 0xebd}, {0xec0, 0xec4}, {0xec6, 0xec6}, {0xedc, 0xedf}, {0xf00, 0xf00}, {0xf40, 0xf47}, {0xf49, 0xf6c}, {0xf88, 0xf8c},
  {0x1000, 0x102a}, {0x103f, 0x103f}, {0x1050, 0x1055}, {0x105a, 0x105d}, {0x1061, 0x1061}, {0x1065, 0x1066}, {0x106e, 0x1070}, {0x1075, 0x1081},
  {0x108e, 0x108e}, {0x10a0, 0x10c5}, {0x10c7, 0x10c7}, {0x10cd, 0x10cd}, {0x10d0, 0x10fa}, {0x10fc, 0x1248}, {0x124a, 0x124d}, {0x1250, 0x1256},
  {0x1258, 0x1258}, {0x125a, 0x125d}, {0x1260, 0x1288}, {0x128a, 0x128d}, {0x1290, 0x12b0}, {0x12b2, 0x12b5}, {0x12b8, 0x12be}, {0x12c0, 0x12c0},
  {0x12c2, 0x12c5}, {0x12c8, 0x12d6}, {0x12d8, 0x1310}, {0x1312, 0x1315}, {0x1318, 0x135a}, {0x1380, 0x138f}, {0x13a0, 0x13f5}, {0x13f8, 0x13fd},
  {0x1401, 0x166c}, {0x166f, 0x167f}, {0x1681, 0x169a}, {0x16a0, 0x16ea}, {0x16f1, 0x16f8}, {0x1700, 0x1711}, {0x171f, 0x1731}, {0x1740, 0x1751},
  {0x1760, 0x176c}, {0x176e, 0x1770}, {0x1780, 0x17b3}, {0x17d7, 0x17d7}, {0x17dc, 0x17dc}, {0x1820, 0x1878}, {0x1880, 0x1884}, {0x1887, 0x18a8},
  {0x18aa, 0x18aa}, {0x18b0, 0x18f5}, {0x1900, 0x191e}, {0x1950, 0x196d}, {0x1970, 0x1974}, {0x1980, 0x19ab}, {0x19b0, 0x19c9}, {0x1a00, 0x1a16},
  {0x1a20, 0x1a54}, {0x1aa7, 0x1aa7}, {0x1b05, 0x1b33}, {0x1b45, 0x1b4c}, {0x1b83, 0x1ba0}, {0x1bae, 0x1baf}, {0x1bba, 0x1be5}, {0x1c00, 0x1c23},
  {0x1c4d, 0x1c4f}, {0x1c5a, 0x1c7d}, {0x1c80, 0x1c88}, {0x1c90, 0x1cba}, {0x1cbd, 0x1cbf}, {0x1ce9, 0x1cec}, {0x1cee, 0x1cf3}, {0x1cf5, 0x1cf6},
  {0x1cfa, 0x1cfa}, {0x1d00, 0x1dbf}, {0x1e00, 0x1f15}, {0x1f18, 0x1f1d}, {0x1f20, 0x1f45}, {0x1f48, 0x1f4d}, {0x1f50, 0x1f57}, {0x1f59, 0x1f59},
  {0x1f5b, 0x1f5b}, {0x1f5d, 0x1f5d}, {0x1f5f, 0x1f7d}, {0x1f80, 0x1fb4}, {0x1fb6, 0x1fbc}, {0x1fbe, 0x1fbe}, {0x1fc2, 0x1fc4}, {0x1fc6, 0x1fcc},
  {0x1fd0, 0x1fd3}, {0x1fd6, 0x1fdb}, {0x1fe0, 0x1fec}, {0x1ff2, 0x1ff4}, {0x1ff6, 0x1ffc}, {0x2071, 0x2071}, {0x207f, 0x207f}, {0x2090, 0x209c},
  {0x2102, 0x2102}, {0x2107, 0x2107}, {0x210a, 0x2113}, {0x2115, 0x2115}, {0x2119, 0x211d}, {0x2124, 0x2124}, {0x2126, 0x2126}, {0x2128, 0x2128},
  {0x212a, 0x212d}, {0x212f, 0x2139}, {0x213c, 0x213f}, {0x2145, 0x2149}, {0x214e, 0x214e}, {0x2183, 0x2184}, {0x2c00, 0x2ce4}, {0x2ceb, 0x2cee},
  {0x2cf2, 0x2cf3}, {0x2d00, 0x2d25}, {0x2d27, 0x2d27}, {0x2d2d, 0x2d2d}, {0x2d30, 0x2d67}, {0x2d6f, 0x2d6f}, {0x2d80, 0x2d96}, {0x2da0, 0x2da6},
  {0x2da8, 0x2dae}, {0x2db0, 0x2db6}, {0x2db8, 0x2dbe}, {0x2dc0, 0x2dc6}, {0x2dc8, 0x2dce}, {0x2dd0, 0x2dd6}, {0x2dd8, 0x2dde}, {0x2e2f, 0x2e2f},
  {0x3005, 0x3006}, {0x3031, 0x3035}, {0x303b, 0x303c}, {0x3041, 0x3096}, {0x309d, 0x309f}, {0x30a1, 0x30fa}, {0x30fc, 0x30ff}, {0x3105, 0x312f},
  {0x3131, 0x318e}, {0x31a0, 0x31bf}, {0x31f0, 0x31ff}, {0x3400, 0x3400}, {0x4dbf, 0x4dbf}, {0x4e00, 0x4e00}, {0x9fff, 0xa48c}, {0xa4d0, 0xa4fd},
  {0xa500, 0xa60c}, {0xa610, 0xa61f}, {0xa62a, 0xa62b}, {0xa640, 0xa66e}, {0xa67f, 0xa69d}, {0xa6a0, 0xa6e5}, {0xa717, 0xa71f}, {0xa722, 0xa788},
  {0xa78b, 0xa7ca}, {0xa7d0, 0xa7d1}, {0xa7d3, 0xa7d3}, {0xa7d5, 0xa7d9}, {0xa7f2, 0xa801}, {0xa803, 0xa805}, {0xa807, 0xa80a}, {0xa80c, 0xa822},
  {0xa840, 0xa873}, {0xa882, 0xa8b3}, {0xa8f2, 0xa8f7}, {0xa8fb, 0xa8fb}, {0xa8fd, 0xa8fe}, {0xa90a, 0xa925}, {0xa930, 0xa946}, {0xa960, 0xa97c},
  {0xa984, 0xa9b2}, {0xa9cf, 0xa9cf}, {0xa9e0, 0xa9e4}, {0xa9e6, 0xa9ef}, {0xa9fa, 0xa9fe}, {0xaa00, 0xaa28}, {0xaa40, 0xaa42}, {0xaa44, 0xaa4b},
  {0xaa60, 0xaa76}, {0xaa7a, 0xaa7a}, {0xaa7e, 0xaaaf}, {0xaab1, 0xaab1}, {0xaab5, 0xaab6}, {0xaab9, 0xaabd}, {0xaac0, 0xaac0}, {0xaac2, 0xaac2},
  {0xaadb, 0xaadd}, {0xaae0, 0xaaea}, {0xaaf2, 0xaaf4}, {0xab01, 0xab06}, {0xab09, 0xab0e}, {0xab11, 0xab16}, {0xab20, 0xab26}, {0xab28, 0xab2e},
  {0xab30, 0xab5a}, {0xab5c, 0xab69}, {0xab70, 0xabe2}, {0xac00, 0xac00}, {0xd7a3, 0xd7a3}, {0xd7b0, 0xd7c6}, {0xd7cb, 0xd7fb}, {0xf900, 0xfa6d},
  {0xfa70, 0xfad9}, {0xfb00, 0xfb06}, {0xfb13, 0xfb17}, {0xfb1d, 0xfb1d}, {0xfb1f, 0xfb28}, {0xfb2a, 0xfb36}, {0xfb38, 0xfb3c}, {0xfb3e, 0xfb3e},
  {0xfb40, 0xfb41}, {0xfb43, 0xfb44}, {0xfb46, 0xfbb1}, {0xfbd3, 0xfd3d}, {0xfd50, 0xfd8f}, {0xfd92, 0xfdc7}, {0xfdf0, 0xfdfb}, {0xfe70, 0xfe74},
  {0xfe76, 0xfefc}, {0xff21, 0xff3a}, {0xff41, 0xff5a}, {0xff66, 0xffbe}, {0xffc2, 0xffc7}, {0xffca, 0xffcf}, {0xffd2, 0xffd7}, {0xffda, 0xffdc},
  {0x10000, 0x1000b}, {0x1000d, 0x10026}, {0x10028, 0x1003a}, {0x1003c, 0x1003d}, {0x1003f, 0x1004d}, {0x10050, 0x1005d}, {0x10080, 0x100fa}, {0x10280, 0x1029c},
  {0x102a0, 0x102d0}, {0x10300, 0x1031f}, {0x1032d, 0x10340}, {0x10342, 0x10349}, {0x10350, 0x10375}, {0x10380, 0x1039d}, {0x103a0, 0x103c3}, {0x103c8, 0x103cf},
  {0x10400, 0x1049d}, {0x104b0, 0x104d3}, {0x104d8, 0x104fb}, {0x10500, 0x10527}, {0x10530, 0x10563}, {0x10570, 0x1057a}, {0x1057c, 0x1058a}, {0x1058c, 0x10592},
  {0x10594, 0x10595}, {0x10597, 0x105a1}, {0x105a3, 0x105b1}, {0x105b3, 0x105b9}, {0x105bb, 0x105bc}, {0x10600, 0x10736}, {0x10740, 0x10755}, {0x10760, 0x10767},
  {0x10780, 0x10785}, {0x10787, 0x107b0}, {0x107b2, 0x107ba}, {0x10800, 0x10805}, {0x10808, 0x10808}, {0x1080a, 0x10835}, {0x10837, 0x10838}, {0x1083c, 0x1083c},
  {0x1083f, 0x10855}, {0x10860, 0x10876}, {0x10880, 0x1089e}, {0x108e0, 0x108f2}, {0x108f4, 0x108f5}, {0x10900, 0x10915}, {0x10920, 0x1092b},
};

static TSCharacterRange sym_metadata_key_character_set_2[] = {
  {'-', '.'}, {'0', '9'}, {'A', 'Z'}, {'_', '_'}, {'a', 'z'}, {0xaa, 0xaa}, {0xb5, 0xb5}, {0xba, 0xba},
  {0xc0, 0xd6}, {0xd8, 0xf6}, {0xf8, 0x2c1}, {0x2c6, 0x2d1}, {0x2e0, 0x2e4}, {0x2ec, 0x2ec}, {0x2ee, 0x2ee}, {0x370, 0x374},
  {0x376, 0x377}, {0x37a, 0x37d}, {0x37f, 0x37f}, {0x386, 0x386}, {0x388, 0x38a}, {0x38c, 0x38c}, {0x38e, 0x3a1}, {0x3a3, 0x3f5},
  {0x3f7, 0x481}, {0x48a, 0x52f}, {0x531, 0x556}, {0x559, 0x559}, {0x560, 0x588}, {0x5d0, 0x5ea}, {0x5ef, 0x5f2}, {0x620, 0x64a},
  {0x66e, 0x66f}, {0x671, 0x6d3}, {0x6d5, 0x6d5}, {0x6e5, 0x6e6}, {0x6ee, 0x6ef}, {0x6fa, 0x6fc}, {0x6ff, 0x6ff}, {0x710, 0x710},
  {0x712, 0x72f}, {0x74d, 0x7a5}, {0x7b1, 0x7b1}, {0x7ca, 0x7ea}, {0x7f4, 0x7f5}, {0x7fa, 0x7fa}, {0x800, 0x815}, {0x81a, 0x81a},
  {0x824, 0x824}, {0x828, 0x828}, {0x840, 0x858}, {0x860, 0x86a}, {0x870, 0x887}, {0x889, 0x88e}, {0x8a0, 0x8c9}, {0x904, 0x939},
  {0x93d, 0x93d}, {0x950, 0x950}, {0x958, 0x961}, {0x971, 0x980}, {0x985, 0x98c}, {0x98f, 0x990}, {0x993, 0x9a8}, {0x9aa, 0x9b0},
  {0x9b2, 0x9b2}, {0x9b6, 0x9b9}, {0x9bd, 0x9bd}, {0x9ce, 0x9ce}, {0x9dc, 0x9dd}, {0x9df, 0x9e1}, {0x9f0, 0x9f1}, {0x9fc, 0x9fc},
  {0xa05, 0xa0a}, {0xa0f, 0xa10}, {0xa13, 0xa28}, {0xa2a, 0xa30}, {0xa32, 0xa33}, {0xa35, 0xa36}, {0xa38, 0xa39}, {0xa59, 0xa5c},
  {0xa5e, 0xa5e}, {0xa72, 0xa74}, {0xa85, 0xa8d}, {0xa8f, 0xa91}, {0xa93, 0xaa8}, {0xaaa, 0xab0}, {0xab2, 0xab3}, {0xab5, 0xab9},
  {0xabd, 0xabd}, {0xad0, 0xad0}, {0xae0, 0xae1}, {0xaf9, 0xaf9}, {0xb05, 0xb0c}, {0xb0f, 0xb10}, {0xb13, 0xb28}, {0xb2a, 0xb30},
  {0xb32, 0xb33}, {0xb35, 0xb39}, {0xb3d, 0xb3d}, {0xb5c, 0xb5d}, {0xb5f, 0xb61}, {0xb71, 0xb71}, {0xb83, 0xb83}, {0xb85, 0xb8a},
  {0xb8e, 0xb90}, {0xb92, 0xb95}, {0xb99, 0xb9a}, {0xb9c, 0xb9c}, {0xb9e, 0xb9f}, {0xba3, 0xba4}, {0xba8, 0xbaa}, {0xbae, 0xbb9},
  {0xbd0, 0xbd0}, {0xc05, 0xc0c}, {0xc0e, 0xc10}, {0xc12, 0xc28}, {0xc2a, 0xc39}, {0xc3d, 0xc3d}, {0xc58, 0xc5a}, {0xc5d, 0xc5d},
  {0xc60, 0xc61}, {0xc80, 0xc80}, {0xc85, 0xc8c}, {0xc8e, 0xc90}, {0xc92, 0xca8}, {0xcaa, 0xcb3}, {0xcb5, 0xcb9}, {0xcbd, 0xcbd},
  {0xcdd, 0xcde}, {0xce0, 0xce1}, {0xcf1, 0xcf2}, {0xd04, 0xd0c}, {0xd0e, 0xd10}, {0xd12, 0xd3a}, {0xd3d, 0xd3d}, {0xd4e, 0xd4e},
  {0xd54, 0xd56}, {0xd5f, 0xd61}, {0xd7a, 0xd7f}, {0xd85, 0xd96}, {0xd9a, 0xdb1}, {0xdb3, 0xdbb}, {0xdbd, 0xdbd}, {0xdc0, 0xdc6},
  {0xe01, 0xe30}, {0xe32, 0xe33}, {0xe40, 0xe46}, {0xe81, 0xe82}, {0xe84, 0xe84}, {0xe86, 0xe8a}, {0xe8c, 0xea3}, {0xea5, 0xea5},
  {0xea7, 0xeb0}, {0xeb2, 0xeb3}, {0xebd, 0xebd}, {0xec0, 0xec4}, {0xec6, 0xec6}, {0xedc, 0xedf}, {0xf00, 0xf00}, {0xf40, 0xf47},
  {0xf49, 0xf6c}, {0xf88, 0xf8c}, {0x1000, 0x102a}, {0x103f, 0x103f}, {0x1050, 0x1055}, {0x105a, 0x105d}, {0x1061, 0x1061}, {0x1065, 0x1066},
  {0x106e, 0x1070}, {0x1075, 0x1081}, {0x108e, 0x108e}, {0x10a0, 0x10c5}, {0x10c7, 0x10c7}, {0x10cd, 0x10cd}, {0x10d0, 0x10fa}, {0x10fc, 0x1248},
  {0x124a, 0x124d}, {0x1250, 0x1256}, {0x1258, 0x1258}, {0x125a, 0x125d}, {0x1260, 0x1288}, {0x128a, 0x128d}, {0x1290, 0x12b0}, {0x12b2, 0x12b5},
  {0x12b8, 0x12be}, {0x12c0, 0x12c0}, {0x12c2, 0x12c5}, {0x12c8, 0x12d6}, {0x12d8, 0x1310}, {0x1312, 0x1315}, {0x1318, 0x135a}, {0x1380, 0x138f},
  {0x13a0, 0x13f5}, {0x13f8, 0x13fd}, {0x1401, 0x166c}, {0x166f, 0x167f}, {0x1681, 0x169a}, {0x16a0, 0x16ea}, {0x16f1, 0x16f8}, {0x1700, 0x1711},
  {0x171f, 0x1731}, {0x1740, 0x1751}, {0x1760, 0x176c}, {0x176e, 0x1770}, {0x1780, 0x17b3}, {0x17d7, 0x17d7}, {0x17dc, 0x17dc}, {0x1820, 0x1878},
  {0x1880, 0x1884}, {0x1887, 0x18a8}, {0x18aa, 0x18aa}, {0x18b0, 0x18f5}, {0x1900, 0x191e}, {0x1950, 0x196d}, {0x1970, 0x1974}, {0x1980, 0x19ab},
  {0x19b0, 0x19c9}, {0x1a00, 0x1a16}, {0x1a20, 0x1a54}, {0x1aa7, 0x1aa7}, {0x1b05, 0x1b33}, {0x1b45, 0x1b4c}, {0x1b83, 0x1ba0}, {0x1bae, 0x1baf},
  {0x1bba, 0x1be5}, {0x1c00, 0x1c23}, {0x1c4d, 0x1c4f}, {0x1c5a, 0x1c7d}, {0x1c80, 0x1c88}, {0x1c90, 0x1cba}, {0x1cbd, 0x1cbf}, {0x1ce9, 0x1cec},
  {0x1cee, 0x1cf3}, {0x1cf5, 0x1cf6}, {0x1cfa, 0x1cfa}, {0x1d00, 0x1dbf}, {0x1e00, 0x1f15}, {0x1f18, 0x1f1d}, {0x1f20, 0x1f45}, {0x1f48, 0x1f4d},
  {0x1f50, 0x1f57}, {0x1f59, 0x1f59}, {0x1f5b, 0x1f5b}, {0x1f5d, 0x1f5d}, {0x1f5f, 0x1f7d}, {0x1f80, 0x1fb4}, {0x1fb6, 0x1fbc}, {0x1fbe, 0x1fbe},
  {0x1fc2, 0x1fc4}, {0x1fc6, 0x1fcc}, {0x1fd0, 0x1fd3}, {0x1fd6, 0x1fdb}, {0x1fe0, 0x1fec}, {0x1ff2, 0x1ff4}, {0x1ff6, 0x1ffc}, {0x2071, 0x2071},
  {0x207f, 0x207f}, {0x2090, 0x209c}, {0x2102, 0x2102}, {0x2107, 0x2107}, {0x210a, 0x2113}, {0x2115, 0x2115}, {0x2119, 0x211d}, {0x2124, 0x2124},
  {0x2126, 0x2126}, {0x2128, 0x2128}, {0x212a, 0x212d}, {0x212f, 0x2139}, {0x213c, 0x213f}, {0x2145, 0x2149}, {0x214e, 0x214e}, {0x2183, 0x2184},
  {0x2c00, 0x2ce4}, {0x2ceb, 0x2cee}, {0x2cf2, 0x2cf3}, {0x2d00, 0x2d25}, {0x2d27, 0x2d27}, {0x2d2d, 0x2d2d}, {0x2d30, 0x2d67}, {0x2d6f, 0x2d6f},
  {0x2d80, 0x2d96}, {0x2da0, 0x2da6}, {0x2da8, 0x2dae}, {0x2db0, 0x2db6}, {0x2db8, 0x2dbe}, {0x2dc0, 0x2dc6}, {0x2dc8, 0x2dce}, {0x2dd0, 0x2dd6},
  {0x2dd8, 0x2dde}, {0x2e2f, 0x2e2f}, {0x3005, 0x3006}, {0x3031, 0x3035}, {0x303b, 0x303c}, {0x3041, 0x3096}, {0x309d, 0x309f}, {0x30a1, 0x30fa},
  {0x30fc, 0x30ff}, {0x3105, 0x312f}, {0x3131, 0x318e}, {0x31a0, 0x31bf}, {0x31f0, 0x31ff}, {0x3400, 0x3400}, {0x4dbf, 0x4dbf}, {0x4e00, 0x4e00},
  {0x9fff, 0xa48c}, {0xa4d0, 0xa4fd}, {0xa500, 0xa60c}, {0xa610, 0xa61f}, {0xa62a, 0xa62b}, {0xa640, 0xa66e}, {0xa67f, 0xa69d}, {0xa6a0, 0xa6e5},
  {0xa717, 0xa71f}, {0xa722, 0xa788}, {0xa78b, 0xa7ca}, {0xa7d0, 0xa7d1}, {0xa7d3, 0xa7d3}, {0xa7d5, 0xa7d9}, {0xa7f2, 0xa801}, {0xa803, 0xa805},
  {0xa807, 0xa80a}, {0xa80c, 0xa822}, {0xa840, 0xa873}, {0xa882, 0xa8b3}, {0xa8f2, 0xa8f7}, {0xa8fb, 0xa8fb}, {0xa8fd, 0xa8fe}, {0xa90a, 0xa925},
  {0xa930, 0xa946}, {0xa960, 0xa97c}, {0xa984, 0xa9b2}, {0xa9cf, 0xa9cf}, {0xa9e0, 0xa9e4}, {0xa9e6, 0xa9ef}, {0xa9fa, 0xa9fe}, {0xaa00, 0xaa28},
  {0xaa40, 0xaa42}, {0xaa44, 0xaa4b}, {0xaa60, 0xaa76}, {0xaa7a, 0xaa7a}, {0xaa7e, 0xaaaf}, {0xaab1, 0xaab1}, {0xaab5, 0xaab6}, {0xaab9, 0xaabd},
  {0xaac0, 0xaac0}, {0xaac2, 0xaac2}, {0xaadb, 0xaadd}, {0xaae0, 0xaaea}, {0xaaf2, 0xaaf4}, {0xab01, 0xab06}, {0xab09, 0xab0e}, {0xab11, 0xab16},
  {0xab20, 0xab26}, {0xab28, 0xab2e}, {0xab30, 0xab5a}, {0xab5c, 0xab69}, {0xab70, 0xabe2}, {0xac00, 0xac00}, {0xd7a3, 0xd7a3}, {0xd7b0, 0xd7c6},
  {0xd7cb, 0xd7fb}, {0xf900, 0xfa6d}, {0xfa70, 0xfad9}, {0xfb00, 0xfb06}, {0xfb13, 0xfb17}, {0xfb1d, 0xfb1d}, {0xfb1f, 0xfb28}, {0xfb2a, 0xfb36},
  {0xfb38, 0xfb3c}, {0xfb3e, 0xfb3e}, {0xfb40, 0xfb41}, {0xfb43, 0xfb44}, {0xfb46, 0xfbb1}, {0xfbd3, 0xfd3d}, {0xfd50, 0xfd8f}, {0xfd92, 0xfdc7},
  {0xfdf0, 0xfdfb}, {0xfe70, 0xfe74}, {0xfe76, 0xfefc}, {0xff21, 0xff3a}, {0xff41, 0xff5a}, {0xff66, 0xffbe}, {0xffc2, 0xffc7}, {0xffca, 0xffcf},
  {0xffd2, 0xffd7}, {0xffda, 0xffdc}, {0x10000, 0x1000b}, {0x1000d, 0x10026}, {0x10028, 0x1003a}, {0x1003c, 0x1003d}, {0x1003f, 0x1004d}, {0x10050, 0x1005d},
  {0x10080, 0x100fa}, {0x10280, 0x1029c}, {0x102a0, 0x102d0}, {0x10300, 0x1031f}, {0x1032d, 0x10340}, {0x10342, 0x10349}, {0x10350, 0x10375}, {0x10380, 0x1039d},
  {0x103a0, 0x103c3}, {0x103c8, 0x103cf}, {0x10400, 0x1049d}, {0x104b0, 0x104d3}, {0x104d8, 0x104fb}, {0x10500, 0x10527}, {0x10530, 0x10563}, {0x10570, 0x1057a},
  {0x1057c, 0x1058a}, {0x1058c, 0x10592}, {0x10594, 0x10595}, {0x10597, 0x105a1}, {0x105a3, 0x105b1}, {0x105b3, 0x105b9}, {0x105bb, 0x105bc}, {0x10600, 0x10736},
  {0x10740, 0x10755}, {0x10760, 0x10767}, {0x10780, 0x10785}, {0x10787, 0x107b0}, {0x107b2, 0x107ba}, {0x10800, 0x10805}, {0x10808, 0x10808}, {0x1080a, 0x10835},
  {0x10837, 0x10838}, {0x1083c, 0x1083c}, {0x1083f, 0x10855}, {0x10860, 0x10876}, {0x10880, 0x1089e}, {0x108e0, 0x108f2}, {0x108f4, 0x108f5}, {0x10900, 0x10915},
  {0x10920, 0x1092b},
};

static TSCharacterRange sym_metadata_key_character_set_3[] = {
  {'-', '.'}, {'0', '9'}, {'A', 'Z'}, {'_', '_'}, {'a', 'z'}, {0xaa, 0xaa}, {0xb5, 0xb5}, {0xba, 0xba},
  {0xc0, 0xd6}, {0xd8, 0xf6}, {0xf8, 0x2c1}, {0x2c6, 0x2d1}, {0x2e0, 0x2e4}, {0x2ec, 0x2ec}, {0x2ee, 0x2ee}, {0x300, 0x374},
  {0x376, 0x377}, {0x37a, 0x37d}, {0x37f, 0x37f}, {0x386, 0x386}, {0x388, 0x38a}, {0x38c, 0x38c}, {0x38e, 0x3a1}, {0x3a3, 0x3f5},
  {0x3f7, 0x481}, {0x483, 0x52f}, {0x531, 0x556}, {0x559, 0x559}, {0x560, 0x588}, {0x591, 0x5bd}, {0x5bf, 0x5bf}, {0x5c1, 0x5c2},
  {0x5c4, 0x5c5}, {0x5c7, 0x5c7}, {0x5d0, 0x5ea}, {0x5ef, 0x5f2}, {0x610, 0x61a}, {0x620, 0x65f}, {0x66e, 0x6d3}, {0x6d5, 0x6dc},
  {0x6df, 0x6e8}, {0x6ea, 0x6ef}, {0x6fa, 0x6fc}, {0x6ff, 0x6ff}, {0x710, 0x74a}, {0x74d, 0x7b1}, {0x7ca, 0x7f5}, {0x7fa, 0x7fa},
  {0x7fd, 0x7fd}, {0x800, 0x82d}, {0x840, 0x85b}, {0x860, 0x86a}, {0x870, 0x887}, {0x889, 0x88e}, {0x898, 0x8e1}, {0x8e3, 0x963},
  {0x971, 0x983}, {0x985, 0x98c}, {0x98f, 0x990}, {0x993, 0x9a8}, {0x9aa, 0x9b0}, {0x9b2, 0x9b2}, {0x9b6, 0x9b9}, {0x9bc, 0x9c4},
  {0x9c7, 0x9c8}, {0x9cb, 0x9ce}, {0x9d7, 0x9d7}, {0x9dc, 0x9dd}, {0x9df, 0x9e3}, {0x9f0, 0x9f1}, {0x9fc, 0x9fc}, {0x9fe, 0x9fe},
  {0xa01, 0xa03}, {0xa05, 0xa0a}, {0xa0f, 0xa10}, {0xa13, 0xa28}, {0xa2a, 0xa30}, {0xa32, 0xa33}, {0xa35, 0xa36}, {0xa38, 0xa39},
  {0xa3c, 0xa3c}, {0xa3e, 0xa42}, {0xa47, 0xa48}, {0xa4b, 0xa4d}, {0xa51, 0xa51}, {0xa59, 0xa5c}, {0xa5e, 0xa5e}, {0xa70, 0xa75},
  {0xa81, 0xa83}, {0xa85, 0xa8d}, {0xa8f, 0xa91}, {0xa93, 0xaa8}, {0xaaa, 0xab0}, {0xab2, 0xab3}, {0xab5, 0xab9}, {0xabc, 0xac5},
  {0xac7, 0xac9}, {0xacb, 0xacd}, {0xad0, 0xad0}, {0xae0, 0xae3}, {0xaf9, 0xaff}, {0xb01, 0xb03}, {0xb05, 0xb0c}, {0xb0f, 0xb10},
  {0xb13, 0xb28}, {0xb2a, 0xb30}, {0xb32, 0xb33}, {0xb35, 0xb39}, {0xb3c, 0xb44}, {0xb47, 0xb48}, {0xb4b, 0xb4d}, {0xb55, 0xb57},
  {0xb5c, 0xb5d}, {0xb5f, 0xb63}, {0xb71, 0xb71}, {0xb82, 0xb83}, {0xb85, 0xb8a}, {0xb8e, 0xb90}, {0xb92, 0xb95}, {0xb99, 0xb9a},
  {0xb9c, 0xb9c}, {0xb9e, 0xb9f}, {0xba3, 0xba4}, {0xba8, 0xbaa}, {0xbae, 0xbb9}, {0xbbe, 0xbc2}, {0xbc6, 0xbc8}, {0xbca, 0xbcd},
  {0xbd0, 0xbd0}, {0xbd7, 0xbd7}, {0xc00, 0xc0c}, {0xc0e, 0xc10}, {0xc12, 0xc28}, {0xc2a, 0xc39}, {0xc3c, 0xc44}, {0xc46, 0xc48},
  {0xc4a, 0xc4d}, {0xc55, 0xc56}, {0xc58, 0xc5a}, {0xc5d, 0xc5d}, {0xc60, 0xc63}, {0xc80, 0xc83}, {0xc85, 0xc8c}, {0xc8e, 0xc90},
  {0xc92, 0xca8}, {0xcaa, 0xcb3}, {0xcb5, 0xcb9}, {0xcbc, 0xcc4}, {0xcc6, 0xcc8}, {0xcca, 0xccd}, {0xcd5, 0xcd6}, {0xcdd, 0xcde},
  {0xce0, 0xce3}, {0xcf1, 0xcf2}, {0xd00, 0xd0c}, {0xd0e, 0xd10}, {0xd12, 0xd44}, {0xd46, 0xd48}, {0xd4a, 0xd4e}, {0xd54, 0xd57},
  {0xd5f, 0xd63}, {0xd7a, 0xd7f}, {0xd81, 0xd83}, {0xd85, 0xd96}, {0xd9a, 0xdb1}, {0xdb3, 0xdbb}, {0xdbd, 0xdbd}, {0xdc0, 0xdc6},
  {0xdca, 0xdca}, {0xdcf, 0xdd4}, {0xdd6, 0xdd6}, {0xdd8, 0xddf}, {0xdf2, 0xdf3}, {0xe01, 0xe3a}, {0xe40, 0xe4e}, {0xe81, 0xe82},
  {0xe84, 0xe84}, {0xe86, 0xe8a}, {0xe8c, 0xea3}, {0xea5, 0xea5}, {0xea7, 0xebd}, {0xec0, 0xec4}, {0xec6, 0xec6}, {0xec8, 0xecd},
  {0xedc, 0xedf}, {0xf00, 0xf00}, {0xf18, 0xf19}, {0xf35, 0xf35}, {0xf37, 0xf37}, {0xf39, 0xf39}, {0xf3e, 0xf47}, {0xf49, 0xf6c},
  {0xf71, 0xf84}, {0xf86, 0xf97}, {0xf99, 0xfbc}, {0xfc6, 0xfc6}, {0x1000, 0x103f}, {0x1050, 0x108f}, {0x109a, 0x109d}, {0x10a0, 0x10c5},
  {0x10c7, 0x10c7}, {0x10cd, 0x10cd}, {0x10d0, 0x10fa}, {0x10fc, 0x1248}, {0x124a, 0x124d}, {0x1250, 0x1256}, {0x1258, 0x1258}, {0x125a, 0x125d},
  {0x1260, 0x1288}, {0x128a, 0x128d}, {0x1290, 0x12b0}, {0x12b2, 0x12b5}, {0x12b8, 0x12be}, {0x12c0, 0x12c0}, {0x12c2, 0x12c5}, {0x12c8, 0x12d6},
  {0x12d8, 0x1310}, {0x1312, 0x1315}, {0x1318, 0x135a}, {0x135d, 0x135f}, {0x1380, 0x138f}, {0x13a0, 0x13f5}, {0x13f8, 0x13fd}, {0x1401, 0x166c},
  {0x166f, 0x167f}, {0x1681, 0x169a}, {0x16a0, 0x16ea}, {0x16f1, 0x16f8}, {0x1700, 0x1715}, {0x171f, 0x1734}, {0x1740, 0x1753}, {0x1760, 0x176c},
  {0x176e, 0x1770}, {0x1772, 0x1773}, {0x1780, 0x17d3}, {0x17d7, 0x17d7}, {0x17dc, 0x17dd}, {0x180b, 0x180d}, {0x180f, 0x180f}, {0x1820, 0x1878},
  {0x1880, 0x18aa}, {0x18b0, 0x18f5}, {0x1900, 0x191e}, {0x1920, 0x192b}, {0x1930, 0x193b}, {0x1950, 0x196d}, {0x1970, 0x1974}, {0x1980, 0x19ab},
  {0x19b0, 0x19c9}, {0x1a00, 0x1a1b}, {0x1a20, 0x1a5e}, {0x1a60, 0x1a7c}, {0x1a7f, 0x1a7f}, {0x1aa7, 0x1aa7}, {0x1ab0, 0x1ace}, {0x1b00, 0x1b4c},
  {0x1b6b, 0x1b73}, {0x1b80, 0x1baf}, {0x1bba, 0x1bf3}, {0x1c00, 0x1c37}, {0x1c4d, 0x1c4f}, {0x1c5a, 0x1c7d}, {0x1c80, 0x1c88}, {0x1c90, 0x1cba},
  {0x1cbd, 0x1cbf}, {0x1cd0, 0x1cd2}, {0x1cd4, 0x1cfa}, {0x1d00, 0x1f15}, {0x1f18, 0x1f1d}, {0x1f20, 0x1f45}, {0x1f48, 0x1f4d}, {0x1f50, 0x1f57},
  {0x1f59, 0x1f59}, {0x1f5b, 0x1f5b}, {0x1f5d, 0x1f5d}, {0x1f5f, 0x1f7d}, {0x1f80, 0x1fb4}, {0x1fb6, 0x1fbc}, {0x1fbe, 0x1fbe}, {0x1fc2, 0x1fc4},
  {0x1fc6, 0x1fcc}, {0x1fd0, 0x1fd3}, {0x1fd6, 0x1fdb}, {0x1fe0, 0x1fec}, {0x1ff2, 0x1ff4}, {0x1ff6, 0x1ffc}, {0x2071, 0x2071}, {0x207f, 0x207f},
  {0x2090, 0x209c}, {0x20d0, 0x20f0}, {0x2102, 0x2102}, {0x2107, 0x2107}, {0x210a, 0x2113}, {0x2115, 0x2115}, {0x2119, 0x211d}, {0x2124, 0x2124},
  {0x2126, 0x2126}, {0x2128, 0x2128}, {0x212a, 0x212d}, {0x212f, 0x2139}, {0x213c, 0x213f}, {0x2145, 0x2149}, {0x214e, 0x214e}, {0x2183, 0x2184},
  {0x2c00, 0x2ce4}, {0x2ceb, 0x2cf3}, {0x2d00, 0x2d25}, {0x2d27, 0x2d27}, {0x2d2d, 0x2d2d}, {0x2d30, 0x2d67}, {0x2d6f, 0x2d6f}, {0x2d7f, 0x2d96},
  {0x2da0, 0x2da6}, {0x2da8, 0x2dae}, {0x2db0, 0x2db6}, {0x2db8, 0x2dbe}, {0x2dc0, 0x2dc6}, {0x2dc8, 0x2dce}, {0x2dd0, 0x2dd6}, {0x2dd8, 0x2dde},
  {0x2de0, 0x2dff}, {0x2e2f, 0x2e2f}, {0x3005, 0x3006}, {0x302a, 0x302f}, {0x3031, 0x3035}, {0x303b, 0x303c}, {0x3041, 0x3096}, {0x3099, 0x309a},
  {0x309d, 0x309f}, {0x30a1, 0x30fa}, {0x30fc, 0x30ff}, {0x3105, 0x312f}, {0x3131, 0x318e}, {0x31a0, 0x31bf}, {0x31f0, 0x31ff}, {0x3400, 0x3400},
  {0x4dbf, 0x4dbf}, {0x4e00, 0x4e00}, {0x9fff, 0xa48c}, {0xa4d0, 0xa4fd}, {0xa500, 0xa60c}, {0xa610, 0xa61f}, {0xa62a, 0xa62b}, {0xa640, 0xa672},
  {0xa674, 0xa67d}, {0xa67f, 0xa6e5}, {0xa6f0, 0xa6f1}, {0xa717, 0xa71f}, {0xa722, 0xa788}, {0xa78b, 0xa7ca}, {0xa7d0, 0xa7d1}, {0xa7d3, 0xa7d3},
  {0xa7d5, 0xa7d9}, {0xa7f2, 0xa827}, {0xa82c, 0xa82c}, {0xa840, 0xa873}, {0xa880, 0xa8c5}, {0xa8e0, 0xa8f7}, {0xa8fb, 0xa8fb}, {0xa8fd, 0xa8ff},
  {0xa90a, 0xa92d}, {0xa930, 0xa953}, {0xa960, 0xa97c}, {0xa980, 0xa9c0}, {0xa9cf, 0xa9cf}, {0xa9e0, 0xa9ef}, {0xa9fa, 0xa9fe}, {0xaa00, 0xaa36},
  {0xaa40, 0xaa4d}, {0xaa60, 0xaa76}, {0xaa7a, 0xaac2}, {0xaadb, 0xaadd}, {0xaae0, 0xaaef}, {0xaaf2, 0xaaf6}, {0xab01, 0xab06}, {0xab09, 0xab0e},
  {0xab11, 0xab16}, {0xab20, 0xab26}, {0xab28, 0xab2e}, {0xab30, 0xab5a}, {0xab5c, 0xab69}, {0xab70, 0xabea}, {0xabec, 0xabed}, {0xac00, 0xac00},
  {0xd7a3, 0xd7a3}, {0xd7b0, 0xd7c6}, {0xd7cb, 0xd7fb}, {0xf900, 0xfa6d}, {0xfa70, 0xfad9}, {0xfb00, 0xfb06}, {0xfb13, 0xfb17}, {0xfb1d, 0xfb28},
  {0xfb2a, 0xfb36}, {0xfb38, 0xfb3c}, {0xfb3e, 0xfb3e}, {0xfb40, 0xfb41}, {0xfb43, 0xfb44}, {0xfb46, 0xfbb1}, {0xfbd3, 0xfd3d}, {0xfd50, 0xfd8f},
  {0xfd92, 0xfdc7}, {0xfdf0, 0xfdfb}, {0xfe00, 0xfe0f}, {0xfe20, 0xfe2f}, {0xfe70, 0xfe74}, {0xfe76, 0xfefc}, {0xff21, 0xff3a}, {0xff41, 0xff5a},
  {0xff66, 0xffbe}, {0xffc2, 0xffc7}, {0xffca, 0xffcf}, {0xffd2, 0xffd7}, {0xffda, 0xffdc}, {0x10000, 0x1000b}, {0x1000d, 0x10026}, {0x10028, 0x1003a},
  {0x1003c, 0x1003d}, {0x1003f, 0x1004d}, {0x10050, 0x1005d}, {0x10080, 0x100fa}, {0x101fd, 0x101fd}, {0x10280, 0x1029c}, {0x102a0, 0x102d0}, {0x102e0, 0x102e0},
  {0x10300, 0x1031f}, {0x1032d, 0x10340}, {0x10342, 0x10349}, {0x10350, 0x1037a}, {0x10380, 0x1039d}, {0x103a0, 0x103c3}, {0x103c8, 0x103cf}, {0x10400, 0x1049d},
  {0x104b0, 0x104d3}, {0x104d8, 0x104fb}, {0x10500, 0x10527}, {0x10530, 0x10563}, {0x10570, 0x1057a}, {0x1057c, 0x1058a}, {0x1058c, 0x10592}, {0x10594, 0x10595},
  {0x10597, 0x105a1}, {0x105a3, 0x105b1}, {0x105b3, 0x105b9}, {0x105bb, 0x105bc}, {0x10600, 0x10736}, {0x10740, 0x10755}, {0x10760, 0x10767}, {0x10780, 0x10785},
  {0x10787, 0x107b0}, {0x107b2, 0x107ba}, {0x10800, 0x10805}, {0x10808, 0x10808}, {0x1080a, 0x10835}, {0x10837, 0x10838}, {0x1083c, 0x1083c}, {0x1083f, 0x10855},
  {0x10860, 0x10876}, {0x10880, 0x1089e}, {0x108e0, 0x108f2}, {0x108f4, 0x108f5}, {0x10900, 0x10915}, {0x10920, 0x1092b},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(21);
      if (lookahead == '\r') SKIP(0);
      if (lookahead == '"') ADVANCE(43);
      if (lookahead == '\'') ADVANCE(42);
      if (lookahead == ':') ADVANCE(39);
      if (lookahead == '<') ADVANCE(41);
      if (lookahead == '>') ADVANCE(38);
      if (lookahead == '_') ADVANCE(29);
      if (lookahead == 'e') ADVANCE(27);
      if (set_contains(sym_metadata_key_character_set_1, 431, lookahead)) ADVANCE(28);
      END_STATE();
    case 1:
      if (lookahead == '\r') SKIP(1);
      if (lookahead == '<') ADVANCE(7);
      if (lookahead == '_') ADVANCE(29);
      if (set_contains(sym_metadata_key_character_set_1, 431, lookahead)) ADVANCE(28);
      END_STATE();
    case 2:
      if (lookahead == '\r') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(23);
      END_STATE();
    case 3:
      if (lookahead == '\r') SKIP(3);
      if (lookahead == '<') ADVANCE(40);
      if (lookahead == '_') ADVANCE(29);
      if (lookahead == 'e') ADVANCE(27);
      if (set_contains(sym_metadata_key_character_set_1, 431, lookahead)) ADVANCE(28);
      END_STATE();
    case 4:
      if (lookahead == '\r') ADVANCE(30);
      if (lookahead == '\\') ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(31);
      END_STATE();
    case 5:
      if (lookahead == '\r') ADVANCE(33);
      if (lookahead == '\\') ADVANCE(35);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(34);
      END_STATE();
    case 6:
      if (lookahead == '\r') SKIP(6);
      if (lookahead == '<') ADVANCE(40);
      if (lookahead == '_') ADVANCE(29);
      if (set_contains(sym_metadata_key_character_set_1, 431, lookahead)) ADVANCE(28);
      END_STATE();
    case 7:
      if (lookahead == '<') ADVANCE(8);
      END_STATE();
    case 8:
      if (lookahead == '<') ADVANCE(13);
      END_STATE();
    case 9:
      if (lookahead == '>') ADVANCE(36);
      END_STATE();
    case 10:
      if (lookahead == '>') ADVANCE(9);
      END_STATE();
    case 11:
      if (lookahead == '>') ADVANCE(10);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(17);
      END_STATE();
    case 13:
      if (lookahead == 'c') ADVANCE(16);
      END_STATE();
    case 14:
      if (lookahead == 'c') ADVANCE(18);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 16:
      if (lookahead == 'l') ADVANCE(15);
      END_STATE();
    case 17:
      if (lookahead == 'n') ADVANCE(14);
      END_STATE();
    case 18:
      if (lookahead == 'o') ADVANCE(19);
      END_STATE();
    case 19:
      if (lookahead == 'p') ADVANCE(20);
      END_STATE();
    case 20:
      if (lookahead == 'y') ADVANCE(11);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_inline_richtext_token1);
      if (lookahead == '\r') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(23);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_inline_richtext_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == 'b') ADVANCE(26);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(29);
      if ((0x300 <= lookahead && lookahead <= 0x36f) ||
          (0x483 <= lookahead && lookahead <= 0x489) ||
          (0x591 <= lookahead && lookahead <= 0x5bd) ||
          lookahead == 0x5bf ||
          lookahead == 0x5c1 ||
          lookahead == 0x5c2 ||
          lookahead == 0x5c4 ||
          lookahead == 0x5c5 ||
          lookahead == 0x5c7 ||
          (0x610 <= lookahead && lookahead <= 0x61a) ||
          (0x64b <= lookahead && lookahead <= 0x65f) ||
          lookahead == 0x670 ||
          (0x6d6 <= lookahead && lookahead <= 0x6dc) ||
          (0x6df <= lookahead && lookahead <= 0x6e4) ||
          lookahead == 0x6e7 ||
          lookahead == 0x6e8 ||
          (0x6ea <= lookahead && lookahead <= 0x6ed) ||
          lookahead == 0x711 ||
          (0x730 <= lookahead && lookahead <= 0x74a) ||
          (0x7a6 <= lookahead && lookahead <= 0x7b0) ||
          (0x7eb <= lookahead && lookahead <= 0x7f3) ||
          lookahead == 0x7fd ||
          (0x816 <= lookahead && lookahead <= 0x819) ||
          (0x81b <= lookahead && lookahead <= 0x823) ||
          (0x825 <= lookahead && lookahead <= 0x827) ||
          (0x829 <= lookahead && lookahead <= 0x82d) ||
          (0x859 <= lookahead && lookahead <= 0x85b) ||
          (0x898 <= lookahead && lookahead <= 0x89f) ||
          (0x8ca <= lookahead && lookahead <= 0x8e1) ||
          (0x8e3 <= lookahead && lookahead <= 0x903) ||
          (0x93a <= lookahead && lookahead <= 0x93c) ||
          (0x93e <= lookahead && lookahead <= 0x94f) ||
          (0x951 <= lookahead && lookahead <= 0x957) ||
          lookahead == 0x962 ||
          lookahead == 0x963 ||
          (0x981 <= lookahead && lookahead <= 0x983) ||
          lookahead == 0x9bc ||
          (0x9be <= lookahead && lookahead <= 0x9c4) ||
          lookahead == 0x9c7 ||
          lookahead == 0x9c8 ||
          (0x9cb <= lookahead && lookahead <= 0x9cd) ||
          lookahead == 0x9d7 ||
          lookahead == 0x9e2 ||
          lookahead == 0x9e3 ||
          lookahead == 0x9fe ||
          (0xa01 <= lookahead && lookahead <= 0xa03) ||
          lookahead == 0xa3c ||
          (0xa3e <= lookahead && lookahead <= 0xa42) ||
          lookahead == 0xa47 ||
          lookahead == 0xa48 ||
          (0xa4b <= lookahead && lookahead <= 0xa4d) ||
          lookahead == 0xa51 ||
          lookahead == 0xa70 ||
          lookahead == 0xa71 ||
          lookahead == 0xa75 ||
          (0xa81 <= lookahead && lookahead <= 0xa83) ||
          lookahead == 0xabc ||
          (0xabe <= lookahead && lookahead <= 0xac5) ||
          (0xac7 <= lookahead && lookahead <= 0xac9) ||
          (0xacb <= lookahead && lookahead <= 0xacd) ||
          lookahead == 0xae2 ||
          lookahead == 0xae3 ||
          (0xafa <= lookahead && lookahead <= 0xaff) ||
          (0xb01 <= lookahead && lookahead <= 0xb03) ||
          lookahead == 0xb3c ||
          (0xb3e <= lookahead && lookahead <= 0xb44) ||
          lookahead == 0xb47 ||
          lookahead == 0xb48 ||
          (0xb4b <= lookahead && lookahead <= 0xb4d) ||
          (0xb55 <= lookahead && lookahead <= 0xb57) ||
          lookahead == 0xb62 ||
          lookahead == 0xb63 ||
          lookahead == 0xb82 ||
          (0xbbe <= lookahead && lookahead <= 0xbc2) ||
          (0xbc6 <= lookahead && lookahead <= 0xbc8) ||
          (0xbca <= lookahead && lookahead <= 0xbcd) ||
          lookahead == 0xbd7 ||
          (0xc00 <= lookahead && lookahead <= 0xc04) ||
          lookahead == 0xc3c ||
          (0xc3e <= lookahead && lookahead <= 0xc44) ||
          (0xc46 <= lookahead && lookahead <= 0xc48) ||
          (0xc4a <= lookahead && lookahead <= 0xc4d) ||
          lookahead == 0xc55 ||
          lookahead == 0xc56 ||
          lookahead == 0xc62 ||
          lookahead == 0xc63 ||
          (0xc81 <= lookahead && lookahead <= 0xc83) ||
          lookahead == 0xcbc ||
          (0xcbe <= lookahead && lookahead <= 0xcc4) ||
          (0xcc6 <= lookahead && lookahead <= 0xcc8) ||
          (0xcca <= lookahead && lookahead <= 0xccd) ||
          lookahead == 0xcd5 ||
          lookahead == 0xcd6 ||
          lookahead == 0xce2 ||
          lookahead == 0xce3 ||
          (0xd00 <= lookahead && lookahead <= 0xd03) ||
          lookahead == 0xd3b ||
          lookahead == 0xd3c ||
          (0xd3e <= lookahead && lookahead <= 0xd44) ||
          (0xd46 <= lookahead && lookahead <= 0xd48) ||
          (0xd4a <= lookahead && lookahead <= 0xd4d) ||
          lookahead == 0xd57 ||
          lookahead == 0xd62 ||
          lookahead == 0xd63 ||
          (0xd81 <= lookahead && lookahead <= 0xd83) ||
          lookahead == 0xdca ||
          (0xdcf <= lookahead && lookahead <= 0xdd4) ||
          lookahead == 0xdd6 ||
          (0xdd8 <= lookahead && lookahead <= 0xddf) ||
          lookahead == 0xdf2 ||
          lookahead == 0xdf3 ||
          lookahead == 0xe31 ||
          (0xe34 <= lookahead && lookahead <= 0xe3a) ||
          (0xe47 <= lookahead && lookahead <= 0xe4e) ||
          lookahead == 0xeb1 ||
          (0xeb4 <= lookahead && lookahead <= 0xebc) ||
          (0xec8 <= lookahead && lookahead <= 0xecd) ||
          lookahead == 0xf18 ||
          lookahead == 0xf19 ||
          lookahead == 0xf35 ||
          lookahead == 0xf37 ||
          lookahead == 0xf39 ||
          lookahead == 0xf3e ||
          lookahead == 0xf3f ||
          (0xf71 <= lookahead && lookahead <= 0xf84) ||
          lookahead == 0xf86 ||
          lookahead == 0xf87 ||
          (0xf8d <= lookahead && lookahead <= 0xf97) ||
          (0xf99 <= lookahead && lookahead <= 0xfbc) ||
          lookahead == 0xfc6 ||
          (0x102b <= lookahead && lookahead <= 0x103e) ||
          (0x1056 <= lookahead && lookahead <= 0x1059) ||
          (0x105e <= lookahead && lookahead <= 0x1060) ||
          (0x1062 <= lookahead && lookahead <= 0x1064) ||
          (0x1067 <= lookahead && lookahead <= 0x106d) ||
          (0x1071 <= lookahead && lookahead <= 0x1074) ||
          (0x1082 <= lookahead && lookahead <= 0x108d) ||
          lookahead == 0x108f ||
          (0x109a <= lookahead && lookahead <= 0x109d) ||
          (0x135d <= lookahead && lookahead <= 0x135f) ||
          (0x1712 <= lookahead && lookahead <= 0x1715) ||
          (0x1732 <= lookahead && lookahead <= 0x1734) ||
          lookahead == 0x1752 ||
          lookahead == 0x1753 ||
          lookahead == 0x1772 ||
          lookahead == 0x1773 ||
          (0x17b4 <= lookahead && lookahead <= 0x17d3) ||
          lookahead == 0x17dd ||
          (0x180b <= lookahead && lookahead <= 0x180d) ||
          lookahead == 0x180f ||
          lookahead == 0x1885 ||
          lookahead == 0x1886 ||
          lookahead == 0x18a9 ||
          (0x1920 <= lookahead && lookahead <= 0x192b) ||
          (0x1930 <= lookahead && lookahead <= 0x193b) ||
          (0x1a17 <= lookahead && lookahead <= 0x1a1b) ||
          (0x1a55 <= lookahead && lookahead <= 0x1a5e) ||
          (0x1a60 <= lookahead && lookahead <= 0x1a7c) ||
          lookahead == 0x1a7f ||
          (0x1ab0 <= lookahead && lookahead <= 0x1ace) ||
          (0x1b00 <= lookahead && lookahead <= 0x1b04) ||
          (0x1b34 <= lookahead && lookahead <= 0x1b44) ||
          (0x1b6b <= lookahead && lookahead <= 0x1b73) ||
          (0x1b80 <= lookahead && lookahead <= 0x1b82) ||
          (0x1ba1 <= lookahead && lookahead <= 0x1bad) ||
          (0x1be6 <= lookahead && lookahead <= 0x1bf3) ||
          (0x1c24 <= lookahead && lookahead <= 0x1c37) ||
          (0x1cd0 <= lookahead && lookahead <= 0x1cd2) ||
          (0x1cd4 <= lookahead && lookahead <= 0x1ce8) ||
          lookahead == 0x1ced ||
          lookahead == 0x1cf4 ||
          (0x1cf7 <= lookahead && lookahead <= 0x1cf9) ||
          (0x1dc0 <= lookahead && lookahead <= 0x1dff) ||
          (0x20d0 <= lookahead && lookahead <= 0x20f0) ||
          (0x2cef <= lookahead && lookahead <= 0x2cf1) ||
          lookahead == 0x2d7f ||
          (0x2de0 <= lookahead && lookahead <= 0x2dff) ||
          (0x302a <= lookahead && lookahead <= 0x302f) ||
          lookahead == 0x3099 ||
          lookahead == 0x309a ||
          (0xa66f <= lookahead && lookahead <= 0xa672) ||
          (0xa674 <= lookahead && lookahead <= 0xa67d) ||
          lookahead == 0xa69e ||
          lookahead == 0xa69f ||
          lookahead == 0xa6f0 ||
          lookahead == 0xa6f1 ||
          lookahead == 0xa802 ||
          lookahead == 0xa806 ||
          lookahead == 0xa80b ||
          (0xa823 <= lookahead && lookahead <= 0xa827) ||
          lookahead == 0xa82c ||
          lookahead == 0xa880 ||
          lookahead == 0xa881 ||
          (0xa8b4 <= lookahead && lookahead <= 0xa8c5) ||
          (0xa8e0 <= lookahead && lookahead <= 0xa8f1) ||
          lookahead == 0xa8ff ||
          (0xa926 <= lookahead && lookahead <= 0xa92d) ||
          (0xa947 <= lookahead && lookahead <= 0xa953) ||
          (0xa980 <= lookahead && lookahead <= 0xa983) ||
          (0xa9b3 <= lookahead && lookahead <= 0xa9c0) ||
          lookahead == 0xa9e5 ||
          (0xaa29 <= lookahead && lookahead <= 0xaa36) ||
          lookahead == 0xaa43 ||
          lookahead == 0xaa4c ||
          lookahead == 0xaa4d ||
          (0xaa7b <= lookahead && lookahead <= 0xaa7d) ||
          lookahead == 0xaab0 ||
          (0xaab2 <= lookahead && lookahead <= 0xaab4) ||
          lookahead == 0xaab7 ||
          lookahead == 0xaab8 ||
          lookahead == 0xaabe ||
          lookahead == 0xaabf ||
          lookahead == 0xaac1 ||
          (0xaaeb <= lookahead && lookahead <= 0xaaef) ||
          lookahead == 0xaaf5 ||
          lookahead == 0xaaf6 ||
          (0xabe3 <= lookahead && lookahead <= 0xabea) ||
          lookahead == 0xabec ||
          lookahead == 0xabed ||
          lookahead == 0xfb1e ||
          (0xfe00 <= lookahead && lookahead <= 0xfe0f) ||
          (0xfe20 <= lookahead && lookahead <= 0xfe2f) ||
          lookahead == 0x101fd ||
          lookahead == 0x102e0 ||
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(28);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(28);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == 'd') ADVANCE(37);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(29);
      if ((0x300 <= lookahead && lookahead <= 0x36f) ||
          (0x483 <= lookahead && lookahead <= 0x489) ||
          (0x591 <= lookahead && lookahead <= 0x5bd) ||
          lookahead == 0x5bf ||
          lookahead == 0x5c1 ||
          lookahead == 0x5c2 ||
          lookahead == 0x5c4 ||
          lookahead == 0x5c5 ||
          lookahead == 0x5c7 ||
          (0x610 <= lookahead && lookahead <= 0x61a) ||
          (0x64b <= lookahead && lookahead <= 0x65f) ||
          lookahead == 0x670 ||
          (0x6d6 <= lookahead && lookahead <= 0x6dc) ||
          (0x6df <= lookahead && lookahead <= 0x6e4) ||
          lookahead == 0x6e7 ||
          lookahead == 0x6e8 ||
          (0x6ea <= lookahead && lookahead <= 0x6ed) ||
          lookahead == 0x711 ||
          (0x730 <= lookahead && lookahead <= 0x74a) ||
          (0x7a6 <= lookahead && lookahead <= 0x7b0) ||
          (0x7eb <= lookahead && lookahead <= 0x7f3) ||
          lookahead == 0x7fd ||
          (0x816 <= lookahead && lookahead <= 0x819) ||
          (0x81b <= lookahead && lookahead <= 0x823) ||
          (0x825 <= lookahead && lookahead <= 0x827) ||
          (0x829 <= lookahead && lookahead <= 0x82d) ||
          (0x859 <= lookahead && lookahead <= 0x85b) ||
          (0x898 <= lookahead && lookahead <= 0x89f) ||
          (0x8ca <= lookahead && lookahead <= 0x8e1) ||
          (0x8e3 <= lookahead && lookahead <= 0x903) ||
          (0x93a <= lookahead && lookahead <= 0x93c) ||
          (0x93e <= lookahead && lookahead <= 0x94f) ||
          (0x951 <= lookahead && lookahead <= 0x957) ||
          lookahead == 0x962 ||
          lookahead == 0x963 ||
          (0x981 <= lookahead && lookahead <= 0x983) ||
          lookahead == 0x9bc ||
          (0x9be <= lookahead && lookahead <= 0x9c4) ||
          lookahead == 0x9c7 ||
          lookahead == 0x9c8 ||
          (0x9cb <= lookahead && lookahead <= 0x9cd) ||
          lookahead == 0x9d7 ||
          lookahead == 0x9e2 ||
          lookahead == 0x9e3 ||
          lookahead == 0x9fe ||
          (0xa01 <= lookahead && lookahead <= 0xa03) ||
          lookahead == 0xa3c ||
          (0xa3e <= lookahead && lookahead <= 0xa42) ||
          lookahead == 0xa47 ||
          lookahead == 0xa48 ||
          (0xa4b <= lookahead && lookahead <= 0xa4d) ||
          lookahead == 0xa51 ||
          lookahead == 0xa70 ||
          lookahead == 0xa71 ||
          lookahead == 0xa75 ||
          (0xa81 <= lookahead && lookahead <= 0xa83) ||
          lookahead == 0xabc ||
          (0xabe <= lookahead && lookahead <= 0xac5) ||
          (0xac7 <= lookahead && lookahead <= 0xac9) ||
          (0xacb <= lookahead && lookahead <= 0xacd) ||
          lookahead == 0xae2 ||
          lookahead == 0xae3 ||
          (0xafa <= lookahead && lookahead <= 0xaff) ||
          (0xb01 <= lookahead && lookahead <= 0xb03) ||
          lookahead == 0xb3c ||
          (0xb3e <= lookahead && lookahead <= 0xb44) ||
          lookahead == 0xb47 ||
          lookahead == 0xb48 ||
          (0xb4b <= lookahead && lookahead <= 0xb4d) ||
          (0xb55 <= lookahead && lookahead <= 0xb57) ||
          lookahead == 0xb62 ||
          lookahead == 0xb63 ||
          lookahead == 0xb82 ||
          (0xbbe <= lookahead && lookahead <= 0xbc2) ||
          (0xbc6 <= lookahead && lookahead <= 0xbc8) ||
          (0xbca <= lookahead && lookahead <= 0xbcd) ||
          lookahead == 0xbd7 ||
          (0xc00 <= lookahead && lookahead <= 0xc04) ||
          lookahead == 0xc3c ||
          (0xc3e <= lookahead && lookahead <= 0xc44) ||
          (0xc46 <= lookahead && lookahead <= 0xc48) ||
          (0xc4a <= lookahead && lookahead <= 0xc4d) ||
          lookahead == 0xc55 ||
          lookahead == 0xc56 ||
          lookahead == 0xc62 ||
          lookahead == 0xc63 ||
          (0xc81 <= lookahead && lookahead <= 0xc83) ||
          lookahead == 0xcbc ||
          (0xcbe <= lookahead && lookahead <= 0xcc4) ||
          (0xcc6 <= lookahead && lookahead <= 0xcc8) ||
          (0xcca <= lookahead && lookahead <= 0xccd) ||
          lookahead == 0xcd5 ||
          lookahead == 0xcd6 ||
          lookahead == 0xce2 ||
          lookahead == 0xce3 ||
          (0xd00 <= lookahead && lookahead <= 0xd03) ||
          lookahead == 0xd3b ||
          lookahead == 0xd3c ||
          (0xd3e <= lookahead && lookahead <= 0xd44) ||
          (0xd46 <= lookahead && lookahead <= 0xd48) ||
          (0xd4a <= lookahead && lookahead <= 0xd4d) ||
          lookahead == 0xd57 ||
          lookahead == 0xd62 ||
          lookahead == 0xd63 ||
          (0xd81 <= lookahead && lookahead <= 0xd83) ||
          lookahead == 0xdca ||
          (0xdcf <= lookahead && lookahead <= 0xdd4) ||
          lookahead == 0xdd6 ||
          (0xdd8 <= lookahead && lookahead <= 0xddf) ||
          lookahead == 0xdf2 ||
          lookahead == 0xdf3 ||
          lookahead == 0xe31 ||
          (0xe34 <= lookahead && lookahead <= 0xe3a) ||
          (0xe47 <= lookahead && lookahead <= 0xe4e) ||
          lookahead == 0xeb1 ||
          (0xeb4 <= lookahead && lookahead <= 0xebc) ||
          (0xec8 <= lookahead && lookahead <= 0xecd) ||
          lookahead == 0xf18 ||
          lookahead == 0xf19 ||
          lookahead == 0xf35 ||
          lookahead == 0xf37 ||
          lookahead == 0xf39 ||
          lookahead == 0xf3e ||
          lookahead == 0xf3f ||
          (0xf71 <= lookahead && lookahead <= 0xf84) ||
          lookahead == 0xf86 ||
          lookahead == 0xf87 ||
          (0xf8d <= lookahead && lookahead <= 0xf97) ||
          (0xf99 <= lookahead && lookahead <= 0xfbc) ||
          lookahead == 0xfc6 ||
          (0x102b <= lookahead && lookahead <= 0x103e) ||
          (0x1056 <= lookahead && lookahead <= 0x1059) ||
          (0x105e <= lookahead && lookahead <= 0x1060) ||
          (0x1062 <= lookahead && lookahead <= 0x1064) ||
          (0x1067 <= lookahead && lookahead <= 0x106d) ||
          (0x1071 <= lookahead && lookahead <= 0x1074) ||
          (0x1082 <= lookahead && lookahead <= 0x108d) ||
          lookahead == 0x108f ||
          (0x109a <= lookahead && lookahead <= 0x109d) ||
          (0x135d <= lookahead && lookahead <= 0x135f) ||
          (0x1712 <= lookahead && lookahead <= 0x1715) ||
          (0x1732 <= lookahead && lookahead <= 0x1734) ||
          lookahead == 0x1752 ||
          lookahead == 0x1753 ||
          lookahead == 0x1772 ||
          lookahead == 0x1773 ||
          (0x17b4 <= lookahead && lookahead <= 0x17d3) ||
          lookahead == 0x17dd ||
          (0x180b <= lookahead && lookahead <= 0x180d) ||
          lookahead == 0x180f ||
          lookahead == 0x1885 ||
          lookahead == 0x1886 ||
          lookahead == 0x18a9 ||
          (0x1920 <= lookahead && lookahead <= 0x192b) ||
          (0x1930 <= lookahead && lookahead <= 0x193b) ||
          (0x1a17 <= lookahead && lookahead <= 0x1a1b) ||
          (0x1a55 <= lookahead && lookahead <= 0x1a5e) ||
          (0x1a60 <= lookahead && lookahead <= 0x1a7c) ||
          lookahead == 0x1a7f ||
          (0x1ab0 <= lookahead && lookahead <= 0x1ace) ||
          (0x1b00 <= lookahead && lookahead <= 0x1b04) ||
          (0x1b34 <= lookahead && lookahead <= 0x1b44) ||
          (0x1b6b <= lookahead && lookahead <= 0x1b73) ||
          (0x1b80 <= lookahead && lookahead <= 0x1b82) ||
          (0x1ba1 <= lookahead && lookahead <= 0x1bad) ||
          (0x1be6 <= lookahead && lookahead <= 0x1bf3) ||
          (0x1c24 <= lookahead && lookahead <= 0x1c37) ||
          (0x1cd0 <= lookahead && lookahead <= 0x1cd2) ||
          (0x1cd4 <= lookahead && lookahead <= 0x1ce8) ||
          lookahead == 0x1ced ||
          lookahead == 0x1cf4 ||
          (0x1cf7 <= lookahead && lookahead <= 0x1cf9) ||
          (0x1dc0 <= lookahead && lookahead <= 0x1dff) ||
          (0x20d0 <= lookahead && lookahead <= 0x20f0) ||
          (0x2cef <= lookahead && lookahead <= 0x2cf1) ||
          lookahead == 0x2d7f ||
          (0x2de0 <= lookahead && lookahead <= 0x2dff) ||
          (0x302a <= lookahead && lookahead <= 0x302f) ||
          lookahead == 0x3099 ||
          lookahead == 0x309a ||
          (0xa66f <= lookahead && lookahead <= 0xa672) ||
          (0xa674 <= lookahead && lookahead <= 0xa67d) ||
          lookahead == 0xa69e ||
          lookahead == 0xa69f ||
          lookahead == 0xa6f0 ||
          lookahead == 0xa6f1 ||
          lookahead == 0xa802 ||
          lookahead == 0xa806 ||
          lookahead == 0xa80b ||
          (0xa823 <= lookahead && lookahead <= 0xa827) ||
          lookahead == 0xa82c ||
          lookahead == 0xa880 ||
          lookahead == 0xa881 ||
          (0xa8b4 <= lookahead && lookahead <= 0xa8c5) ||
          (0xa8e0 <= lookahead && lookahead <= 0xa8f1) ||
          lookahead == 0xa8ff ||
          (0xa926 <= lookahead && lookahead <= 0xa92d) ||
          (0xa947 <= lookahead && lookahead <= 0xa953) ||
          (0xa980 <= lookahead && lookahead <= 0xa983) ||
          (0xa9b3 <= lookahead && lookahead <= 0xa9c0) ||
          lookahead == 0xa9e5 ||
          (0xaa29 <= lookahead && lookahead <= 0xaa36) ||
          lookahead == 0xaa43 ||
          lookahead == 0xaa4c ||
          lookahead == 0xaa4d ||
          (0xaa7b <= lookahead && lookahead <= 0xaa7d) ||
          lookahead == 0xaab0 ||
          (0xaab2 <= lookahead && lookahead <= 0xaab4) ||
          lookahead == 0xaab7 ||
          lookahead == 0xaab8 ||
          lookahead == 0xaabe ||
          lookahead == 0xaabf ||
          lookahead == 0xaac1 ||
          (0xaaeb <= lookahead && lookahead <= 0xaaef) ||
          lookahead == 0xaaf5 ||
          lookahead == 0xaaf6 ||
          (0xabe3 <= lookahead && lookahead <= 0xabea) ||
          lookahead == 0xabec ||
          lookahead == 0xabed ||
          lookahead == 0xfb1e ||
          (0xfe00 <= lookahead && lookahead <= 0xfe0f) ||
          (0xfe20 <= lookahead && lookahead <= 0xfe2f) ||
          lookahead == 0x101fd ||
          lookahead == 0x102e0 ||
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(28);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(28);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == 'e') ADVANCE(25);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(29);
      if ((0x300 <= lookahead && lookahead <= 0x36f) ||
          (0x483 <= lookahead && lookahead <= 0x489) ||
          (0x591 <= lookahead && lookahead <= 0x5bd) ||
          lookahead == 0x5bf ||
          lookahead == 0x5c1 ||
          lookahead == 0x5c2 ||
          lookahead == 0x5c4 ||
          lookahead == 0x5c5 ||
          lookahead == 0x5c7 ||
          (0x610 <= lookahead && lookahead <= 0x61a) ||
          (0x64b <= lookahead && lookahead <= 0x65f) ||
          lookahead == 0x670 ||
          (0x6d6 <= lookahead && lookahead <= 0x6dc) ||
          (0x6df <= lookahead && lookahead <= 0x6e4) ||
          lookahead == 0x6e7 ||
          lookahead == 0x6e8 ||
          (0x6ea <= lookahead && lookahead <= 0x6ed) ||
          lookahead == 0x711 ||
          (0x730 <= lookahead && lookahead <= 0x74a) ||
          (0x7a6 <= lookahead && lookahead <= 0x7b0) ||
          (0x7eb <= lookahead && lookahead <= 0x7f3) ||
          lookahead == 0x7fd ||
          (0x816 <= lookahead && lookahead <= 0x819) ||
          (0x81b <= lookahead && lookahead <= 0x823) ||
          (0x825 <= lookahead && lookahead <= 0x827) ||
          (0x829 <= lookahead && lookahead <= 0x82d) ||
          (0x859 <= lookahead && lookahead <= 0x85b) ||
          (0x898 <= lookahead && lookahead <= 0x89f) ||
          (0x8ca <= lookahead && lookahead <= 0x8e1) ||
          (0x8e3 <= lookahead && lookahead <= 0x903) ||
          (0x93a <= lookahead && lookahead <= 0x93c) ||
          (0x93e <= lookahead && lookahead <= 0x94f) ||
          (0x951 <= lookahead && lookahead <= 0x957) ||
          lookahead == 0x962 ||
          lookahead == 0x963 ||
          (0x981 <= lookahead && lookahead <= 0x983) ||
          lookahead == 0x9bc ||
          (0x9be <= lookahead && lookahead <= 0x9c4) ||
          lookahead == 0x9c7 ||
          lookahead == 0x9c8 ||
          (0x9cb <= lookahead && lookahead <= 0x9cd) ||
          lookahead == 0x9d7 ||
          lookahead == 0x9e2 ||
          lookahead == 0x9e3 ||
          lookahead == 0x9fe ||
          (0xa01 <= lookahead && lookahead <= 0xa03) ||
          lookahead == 0xa3c ||
          (0xa3e <= lookahead && lookahead <= 0xa42) ||
          lookahead == 0xa47 ||
          lookahead == 0xa48 ||
          (0xa4b <= lookahead && lookahead <= 0xa4d) ||
          lookahead == 0xa51 ||
          lookahead == 0xa70 ||
          lookahead == 0xa71 ||
          lookahead == 0xa75 ||
          (0xa81 <= lookahead && lookahead <= 0xa83) ||
          lookahead == 0xabc ||
          (0xabe <= lookahead && lookahead <= 0xac5) ||
          (0xac7 <= lookahead && lookahead <= 0xac9) ||
          (0xacb <= lookahead && lookahead <= 0xacd) ||
          lookahead == 0xae2 ||
          lookahead == 0xae3 ||
          (0xafa <= lookahead && lookahead <= 0xaff) ||
          (0xb01 <= lookahead && lookahead <= 0xb03) ||
          lookahead == 0xb3c ||
          (0xb3e <= lookahead && lookahead <= 0xb44) ||
          lookahead == 0xb47 ||
          lookahead == 0xb48 ||
          (0xb4b <= lookahead && lookahead <= 0xb4d) ||
          (0xb55 <= lookahead && lookahead <= 0xb57) ||
          lookahead == 0xb62 ||
          lookahead == 0xb63 ||
          lookahead == 0xb82 ||
          (0xbbe <= lookahead && lookahead <= 0xbc2) ||
          (0xbc6 <= lookahead && lookahead <= 0xbc8) ||
          (0xbca <= lookahead && lookahead <= 0xbcd) ||
          lookahead == 0xbd7 ||
          (0xc00 <= lookahead && lookahead <= 0xc04) ||
          lookahead == 0xc3c ||
          (0xc3e <= lookahead && lookahead <= 0xc44) ||
          (0xc46 <= lookahead && lookahead <= 0xc48) ||
          (0xc4a <= lookahead && lookahead <= 0xc4d) ||
          lookahead == 0xc55 ||
          lookahead == 0xc56 ||
          lookahead == 0xc62 ||
          lookahead == 0xc63 ||
          (0xc81 <= lookahead && lookahead <= 0xc83) ||
          lookahead == 0xcbc ||
          (0xcbe <= lookahead && lookahead <= 0xcc4) ||
          (0xcc6 <= lookahead && lookahead <= 0xcc8) ||
          (0xcca <= lookahead && lookahead <= 0xccd) ||
          lookahead == 0xcd5 ||
          lookahead == 0xcd6 ||
          lookahead == 0xce2 ||
          lookahead == 0xce3 ||
          (0xd00 <= lookahead && lookahead <= 0xd03) ||
          lookahead == 0xd3b ||
          lookahead == 0xd3c ||
          (0xd3e <= lookahead && lookahead <= 0xd44) ||
          (0xd46 <= lookahead && lookahead <= 0xd48) ||
          (0xd4a <= lookahead && lookahead <= 0xd4d) ||
          lookahead == 0xd57 ||
          lookahead == 0xd62 ||
          lookahead == 0xd63 ||
          (0xd81 <= lookahead && lookahead <= 0xd83) ||
          lookahead == 0xdca ||
          (0xdcf <= lookahead && lookahead <= 0xdd4) ||
          lookahead == 0xdd6 ||
          (0xdd8 <= lookahead && lookahead <= 0xddf) ||
          lookahead == 0xdf2 ||
          lookahead == 0xdf3 ||
          lookahead == 0xe31 ||
          (0xe34 <= lookahead && lookahead <= 0xe3a) ||
          (0xe47 <= lookahead && lookahead <= 0xe4e) ||
          lookahead == 0xeb1 ||
          (0xeb4 <= lookahead && lookahead <= 0xebc) ||
          (0xec8 <= lookahead && lookahead <= 0xecd) ||
          lookahead == 0xf18 ||
          lookahead == 0xf19 ||
          lookahead == 0xf35 ||
          lookahead == 0xf37 ||
          lookahead == 0xf39 ||
          lookahead == 0xf3e ||
          lookahead == 0xf3f ||
          (0xf71 <= lookahead && lookahead <= 0xf84) ||
          lookahead == 0xf86 ||
          lookahead == 0xf87 ||
          (0xf8d <= lookahead && lookahead <= 0xf97) ||
          (0xf99 <= lookahead && lookahead <= 0xfbc) ||
          lookahead == 0xfc6 ||
          (0x102b <= lookahead && lookahead <= 0x103e) ||
          (0x1056 <= lookahead && lookahead <= 0x1059) ||
          (0x105e <= lookahead && lookahead <= 0x1060) ||
          (0x1062 <= lookahead && lookahead <= 0x1064) ||
          (0x1067 <= lookahead && lookahead <= 0x106d) ||
          (0x1071 <= lookahead && lookahead <= 0x1074) ||
          (0x1082 <= lookahead && lookahead <= 0x108d) ||
          lookahead == 0x108f ||
          (0x109a <= lookahead && lookahead <= 0x109d) ||
          (0x135d <= lookahead && lookahead <= 0x135f) ||
          (0x1712 <= lookahead && lookahead <= 0x1715) ||
          (0x1732 <= lookahead && lookahead <= 0x1734) ||
          lookahead == 0x1752 ||
          lookahead == 0x1753 ||
          lookahead == 0x1772 ||
          lookahead == 0x1773 ||
          (0x17b4 <= lookahead && lookahead <= 0x17d3) ||
          lookahead == 0x17dd ||
          (0x180b <= lookahead && lookahead <= 0x180d) ||
          lookahead == 0x180f ||
          lookahead == 0x1885 ||
          lookahead == 0x1886 ||
          lookahead == 0x18a9 ||
          (0x1920 <= lookahead && lookahead <= 0x192b) ||
          (0x1930 <= lookahead && lookahead <= 0x193b) ||
          (0x1a17 <= lookahead && lookahead <= 0x1a1b) ||
          (0x1a55 <= lookahead && lookahead <= 0x1a5e) ||
          (0x1a60 <= lookahead && lookahead <= 0x1a7c) ||
          lookahead == 0x1a7f ||
          (0x1ab0 <= lookahead && lookahead <= 0x1ace) ||
          (0x1b00 <= lookahead && lookahead <= 0x1b04) ||
          (0x1b34 <= lookahead && lookahead <= 0x1b44) ||
          (0x1b6b <= lookahead && lookahead <= 0x1b73) ||
          (0x1b80 <= lookahead && lookahead <= 0x1b82) ||
          (0x1ba1 <= lookahead && lookahead <= 0x1bad) ||
          (0x1be6 <= lookahead && lookahead <= 0x1bf3) ||
          (0x1c24 <= lookahead && lookahead <= 0x1c37) ||
          (0x1cd0 <= lookahead && lookahead <= 0x1cd2) ||
          (0x1cd4 <= lookahead && lookahead <= 0x1ce8) ||
          lookahead == 0x1ced ||
          lookahead == 0x1cf4 ||
          (0x1cf7 <= lookahead && lookahead <= 0x1cf9) ||
          (0x1dc0 <= lookahead && lookahead <= 0x1dff) ||
          (0x20d0 <= lookahead && lookahead <= 0x20f0) ||
          (0x2cef <= lookahead && lookahead <= 0x2cf1) ||
          lookahead == 0x2d7f ||
          (0x2de0 <= lookahead && lookahead <= 0x2dff) ||
          (0x302a <= lookahead && lookahead <= 0x302f) ||
          lookahead == 0x3099 ||
          lookahead == 0x309a ||
          (0xa66f <= lookahead && lookahead <= 0xa672) ||
          (0xa674 <= lookahead && lookahead <= 0xa67d) ||
          lookahead == 0xa69e ||
          lookahead == 0xa69f ||
          lookahead == 0xa6f0 ||
          lookahead == 0xa6f1 ||
          lookahead == 0xa802 ||
          lookahead == 0xa806 ||
          lookahead == 0xa80b ||
          (0xa823 <= lookahead && lookahead <= 0xa827) ||
          lookahead == 0xa82c ||
          lookahead == 0xa880 ||
          lookahead == 0xa881 ||
          (0xa8b4 <= lookahead && lookahead <= 0xa8c5) ||
          (0xa8e0 <= lookahead && lookahead <= 0xa8f1) ||
          lookahead == 0xa8ff ||
          (0xa926 <= lookahead && lookahead <= 0xa92d) ||
          (0xa947 <= lookahead && lookahead <= 0xa953) ||
          (0xa980 <= lookahead && lookahead <= 0xa983) ||
          (0xa9b3 <= lookahead && lookahead <= 0xa9c0) ||
          lookahead == 0xa9e5 ||
          (0xaa29 <= lookahead && lookahead <= 0xaa36) ||
          lookahead == 0xaa43 ||
          lookahead == 0xaa4c ||
          lookahead == 0xaa4d ||
          (0xaa7b <= lookahead && lookahead <= 0xaa7d) ||
          lookahead == 0xaab0 ||
          (0xaab2 <= lookahead && lookahead <= 0xaab4) ||
          lookahead == 0xaab7 ||
          lookahead == 0xaab8 ||
          lookahead == 0xaabe ||
          lookahead == 0xaabf ||
          lookahead == 0xaac1 ||
          (0xaaeb <= lookahead && lookahead <= 0xaaef) ||
          lookahead == 0xaaf5 ||
          lookahead == 0xaaf6 ||
          (0xabe3 <= lookahead && lookahead <= 0xabea) ||
          lookahead == 0xabec ||
          lookahead == 0xabed ||
          lookahead == 0xfb1e ||
          (0xfe00 <= lookahead && lookahead <= 0xfe0f) ||
          (0xfe20 <= lookahead && lookahead <= 0xfe2f) ||
          lookahead == 0x101fd ||
          lookahead == 0x102e0 ||
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(28);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(28);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == 'm') ADVANCE(24);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(29);
      if ((0x300 <= lookahead && lookahead <= 0x36f) ||
          (0x483 <= lookahead && lookahead <= 0x489) ||
          (0x591 <= lookahead && lookahead <= 0x5bd) ||
          lookahead == 0x5bf ||
          lookahead == 0x5c1 ||
          lookahead == 0x5c2 ||
          lookahead == 0x5c4 ||
          lookahead == 0x5c5 ||
          lookahead == 0x5c7 ||
          (0x610 <= lookahead && lookahead <= 0x61a) ||
          (0x64b <= lookahead && lookahead <= 0x65f) ||
          lookahead == 0x670 ||
          (0x6d6 <= lookahead && lookahead <= 0x6dc) ||
          (0x6df <= lookahead && lookahead <= 0x6e4) ||
          lookahead == 0x6e7 ||
          lookahead == 0x6e8 ||
          (0x6ea <= lookahead && lookahead <= 0x6ed) ||
          lookahead == 0x711 ||
          (0x730 <= lookahead && lookahead <= 0x74a) ||
          (0x7a6 <= lookahead && lookahead <= 0x7b0) ||
          (0x7eb <= lookahead && lookahead <= 0x7f3) ||
          lookahead == 0x7fd ||
          (0x816 <= lookahead && lookahead <= 0x819) ||
          (0x81b <= lookahead && lookahead <= 0x823) ||
          (0x825 <= lookahead && lookahead <= 0x827) ||
          (0x829 <= lookahead && lookahead <= 0x82d) ||
          (0x859 <= lookahead && lookahead <= 0x85b) ||
          (0x898 <= lookahead && lookahead <= 0x89f) ||
          (0x8ca <= lookahead && lookahead <= 0x8e1) ||
          (0x8e3 <= lookahead && lookahead <= 0x903) ||
          (0x93a <= lookahead && lookahead <= 0x93c) ||
          (0x93e <= lookahead && lookahead <= 0x94f) ||
          (0x951 <= lookahead && lookahead <= 0x957) ||
          lookahead == 0x962 ||
          lookahead == 0x963 ||
          (0x981 <= lookahead && lookahead <= 0x983) ||
          lookahead == 0x9bc ||
          (0x9be <= lookahead && lookahead <= 0x9c4) ||
          lookahead == 0x9c7 ||
          lookahead == 0x9c8 ||
          (0x9cb <= lookahead && lookahead <= 0x9cd) ||
          lookahead == 0x9d7 ||
          lookahead == 0x9e2 ||
          lookahead == 0x9e3 ||
          lookahead == 0x9fe ||
          (0xa01 <= lookahead && lookahead <= 0xa03) ||
          lookahead == 0xa3c ||
          (0xa3e <= lookahead && lookahead <= 0xa42) ||
          lookahead == 0xa47 ||
          lookahead == 0xa48 ||
          (0xa4b <= lookahead && lookahead <= 0xa4d) ||
          lookahead == 0xa51 ||
          lookahead == 0xa70 ||
          lookahead == 0xa71 ||
          lookahead == 0xa75 ||
          (0xa81 <= lookahead && lookahead <= 0xa83) ||
          lookahead == 0xabc ||
          (0xabe <= lookahead && lookahead <= 0xac5) ||
          (0xac7 <= lookahead && lookahead <= 0xac9) ||
          (0xacb <= lookahead && lookahead <= 0xacd) ||
          lookahead == 0xae2 ||
          lookahead == 0xae3 ||
          (0xafa <= lookahead && lookahead <= 0xaff) ||
          (0xb01 <= lookahead && lookahead <= 0xb03) ||
          lookahead == 0xb3c ||
          (0xb3e <= lookahead && lookahead <= 0xb44) ||
          lookahead == 0xb47 ||
          lookahead == 0xb48 ||
          (0xb4b <= lookahead && lookahead <= 0xb4d) ||
          (0xb55 <= lookahead && lookahead <= 0xb57) ||
          lookahead == 0xb62 ||
          lookahead == 0xb63 ||
          lookahead == 0xb82 ||
          (0xbbe <= lookahead && lookahead <= 0xbc2) ||
          (0xbc6 <= lookahead && lookahead <= 0xbc8) ||
          (0xbca <= lookahead && lookahead <= 0xbcd) ||
          lookahead == 0xbd7 ||
          (0xc00 <= lookahead && lookahead <= 0xc04) ||
          lookahead == 0xc3c ||
          (0xc3e <= lookahead && lookahead <= 0xc44) ||
          (0xc46 <= lookahead && lookahead <= 0xc48) ||
          (0xc4a <= lookahead && lookahead <= 0xc4d) ||
          lookahead == 0xc55 ||
          lookahead == 0xc56 ||
          lookahead == 0xc62 ||
          lookahead == 0xc63 ||
          (0xc81 <= lookahead && lookahead <= 0xc83) ||
          lookahead == 0xcbc ||
          (0xcbe <= lookahead && lookahead <= 0xcc4) ||
          (0xcc6 <= lookahead && lookahead <= 0xcc8) ||
          (0xcca <= lookahead && lookahead <= 0xccd) ||
          lookahead == 0xcd5 ||
          lookahead == 0xcd6 ||
          lookahead == 0xce2 ||
          lookahead == 0xce3 ||
          (0xd00 <= lookahead && lookahead <= 0xd03) ||
          lookahead == 0xd3b ||
          lookahead == 0xd3c ||
          (0xd3e <= lookahead && lookahead <= 0xd44) ||
          (0xd46 <= lookahead && lookahead <= 0xd48) ||
          (0xd4a <= lookahead && lookahead <= 0xd4d) ||
          lookahead == 0xd57 ||
          lookahead == 0xd62 ||
          lookahead == 0xd63 ||
          (0xd81 <= lookahead && lookahead <= 0xd83) ||
          lookahead == 0xdca ||
          (0xdcf <= lookahead && lookahead <= 0xdd4) ||
          lookahead == 0xdd6 ||
          (0xdd8 <= lookahead && lookahead <= 0xddf) ||
          lookahead == 0xdf2 ||
          lookahead == 0xdf3 ||
          lookahead == 0xe31 ||
          (0xe34 <= lookahead && lookahead <= 0xe3a) ||
          (0xe47 <= lookahead && lookahead <= 0xe4e) ||
          lookahead == 0xeb1 ||
          (0xeb4 <= lookahead && lookahead <= 0xebc) ||
          (0xec8 <= lookahead && lookahead <= 0xecd) ||
          lookahead == 0xf18 ||
          lookahead == 0xf19 ||
          lookahead == 0xf35 ||
          lookahead == 0xf37 ||
          lookahead == 0xf39 ||
          lookahead == 0xf3e ||
          lookahead == 0xf3f ||
          (0xf71 <= lookahead && lookahead <= 0xf84) ||
          lookahead == 0xf86 ||
          lookahead == 0xf87 ||
          (0xf8d <= lookahead && lookahead <= 0xf97) ||
          (0xf99 <= lookahead && lookahead <= 0xfbc) ||
          lookahead == 0xfc6 ||
          (0x102b <= lookahead && lookahead <= 0x103e) ||
          (0x1056 <= lookahead && lookahead <= 0x1059) ||
          (0x105e <= lookahead && lookahead <= 0x1060) ||
          (0x1062 <= lookahead && lookahead <= 0x1064) ||
          (0x1067 <= lookahead && lookahead <= 0x106d) ||
          (0x1071 <= lookahead && lookahead <= 0x1074) ||
          (0x1082 <= lookahead && lookahead <= 0x108d) ||
          lookahead == 0x108f ||
          (0x109a <= lookahead && lookahead <= 0x109d) ||
          (0x135d <= lookahead && lookahead <= 0x135f) ||
          (0x1712 <= lookahead && lookahead <= 0x1715) ||
          (0x1732 <= lookahead && lookahead <= 0x1734) ||
          lookahead == 0x1752 ||
          lookahead == 0x1753 ||
          lookahead == 0x1772 ||
          lookahead == 0x1773 ||
          (0x17b4 <= lookahead && lookahead <= 0x17d3) ||
          lookahead == 0x17dd ||
          (0x180b <= lookahead && lookahead <= 0x180d) ||
          lookahead == 0x180f ||
          lookahead == 0x1885 ||
          lookahead == 0x1886 ||
          lookahead == 0x18a9 ||
          (0x1920 <= lookahead && lookahead <= 0x192b) ||
          (0x1930 <= lookahead && lookahead <= 0x193b) ||
          (0x1a17 <= lookahead && lookahead <= 0x1a1b) ||
          (0x1a55 <= lookahead && lookahead <= 0x1a5e) ||
          (0x1a60 <= lookahead && lookahead <= 0x1a7c) ||
          lookahead == 0x1a7f ||
          (0x1ab0 <= lookahead && lookahead <= 0x1ace) ||
          (0x1b00 <= lookahead && lookahead <= 0x1b04) ||
          (0x1b34 <= lookahead && lookahead <= 0x1b44) ||
          (0x1b6b <= lookahead && lookahead <= 0x1b73) ||
          (0x1b80 <= lookahead && lookahead <= 0x1b82) ||
          (0x1ba1 <= lookahead && lookahead <= 0x1bad) ||
          (0x1be6 <= lookahead && lookahead <= 0x1bf3) ||
          (0x1c24 <= lookahead && lookahead <= 0x1c37) ||
          (0x1cd0 <= lookahead && lookahead <= 0x1cd2) ||
          (0x1cd4 <= lookahead && lookahead <= 0x1ce8) ||
          lookahead == 0x1ced ||
          lookahead == 0x1cf4 ||
          (0x1cf7 <= lookahead && lookahead <= 0x1cf9) ||
          (0x1dc0 <= lookahead && lookahead <= 0x1dff) ||
          (0x20d0 <= lookahead && lookahead <= 0x20f0) ||
          (0x2cef <= lookahead && lookahead <= 0x2cf1) ||
          lookahead == 0x2d7f ||
          (0x2de0 <= lookahead && lookahead <= 0x2dff) ||
          (0x302a <= lookahead && lookahead <= 0x302f) ||
          lookahead == 0x3099 ||
          lookahead == 0x309a ||
          (0xa66f <= lookahead && lookahead <= 0xa672) ||
          (0xa674 <= lookahead && lookahead <= 0xa67d) ||
          lookahead == 0xa69e ||
          lookahead == 0xa69f ||
          lookahead == 0xa6f0 ||
          lookahead == 0xa6f1 ||
          lookahead == 0xa802 ||
          lookahead == 0xa806 ||
          lookahead == 0xa80b ||
          (0xa823 <= lookahead && lookahead <= 0xa827) ||
          lookahead == 0xa82c ||
          lookahead == 0xa880 ||
          lookahead == 0xa881 ||
          (0xa8b4 <= lookahead && lookahead <= 0xa8c5) ||
          (0xa8e0 <= lookahead && lookahead <= 0xa8f1) ||
          lookahead == 0xa8ff ||
          (0xa926 <= lookahead && lookahead <= 0xa92d) ||
          (0xa947 <= lookahead && lookahead <= 0xa953) ||
          (0xa980 <= lookahead && lookahead <= 0xa983) ||
          (0xa9b3 <= lookahead && lookahead <= 0xa9c0) ||
          lookahead == 0xa9e5 ||
          (0xaa29 <= lookahead && lookahead <= 0xaa36) ||
          lookahead == 0xaa43 ||
          lookahead == 0xaa4c ||
          lookahead == 0xaa4d ||
          (0xaa7b <= lookahead && lookahead <= 0xaa7d) ||
          lookahead == 0xaab0 ||
          (0xaab2 <= lookahead && lookahead <= 0xaab4) ||
          lookahead == 0xaab7 ||
          lookahead == 0xaab8 ||
          lookahead == 0xaabe ||
          lookahead == 0xaabf ||
          lookahead == 0xaac1 ||
          (0xaaeb <= lookahead && lookahead <= 0xaaef) ||
          lookahead == 0xaaf5 ||
          lookahead == 0xaaf6 ||
          (0xabe3 <= lookahead && lookahead <= 0xabea) ||
          lookahead == 0xabec ||
          lookahead == 0xabed ||
          lookahead == 0xfb1e ||
          (0xfe00 <= lookahead && lookahead <= 0xfe0f) ||
          (0xfe20 <= lookahead && lookahead <= 0xfe2f) ||
          lookahead == 0x101fd ||
          lookahead == 0x102e0 ||
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(28);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(28);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(29);
      if ((0x300 <= lookahead && lookahead <= 0x36f) ||
          (0x483 <= lookahead && lookahead <= 0x489) ||
          (0x591 <= lookahead && lookahead <= 0x5bd) ||
          lookahead == 0x5bf ||
          lookahead == 0x5c1 ||
          lookahead == 0x5c2 ||
          lookahead == 0x5c4 ||
          lookahead == 0x5c5 ||
          lookahead == 0x5c7 ||
          (0x610 <= lookahead && lookahead <= 0x61a) ||
          (0x64b <= lookahead && lookahead <= 0x65f) ||
          lookahead == 0x670 ||
          (0x6d6 <= lookahead && lookahead <= 0x6dc) ||
          (0x6df <= lookahead && lookahead <= 0x6e4) ||
          lookahead == 0x6e7 ||
          lookahead == 0x6e8 ||
          (0x6ea <= lookahead && lookahead <= 0x6ed) ||
          lookahead == 0x711 ||
          (0x730 <= lookahead && lookahead <= 0x74a) ||
          (0x7a6 <= lookahead && lookahead <= 0x7b0) ||
          (0x7eb <= lookahead && lookahead <= 0x7f3) ||
          lookahead == 0x7fd ||
          (0x816 <= lookahead && lookahead <= 0x819) ||
          (0x81b <= lookahead && lookahead <= 0x823) ||
          (0x825 <= lookahead && lookahead <= 0x827) ||
          (0x829 <= lookahead && lookahead <= 0x82d) ||
          (0x859 <= lookahead && lookahead <= 0x85b) ||
          (0x898 <= lookahead && lookahead <= 0x89f) ||
          (0x8ca <= lookahead && lookahead <= 0x8e1) ||
          (0x8e3 <= lookahead && lookahead <= 0x903) ||
          (0x93a <= lookahead && lookahead <= 0x93c) ||
          (0x93e <= lookahead && lookahead <= 0x94f) ||
          (0x951 <= lookahead && lookahead <= 0x957) ||
          lookahead == 0x962 ||
          lookahead == 0x963 ||
          (0x981 <= lookahead && lookahead <= 0x983) ||
          lookahead == 0x9bc ||
          (0x9be <= lookahead && lookahead <= 0x9c4) ||
          lookahead == 0x9c7 ||
          lookahead == 0x9c8 ||
          (0x9cb <= lookahead && lookahead <= 0x9cd) ||
          lookahead == 0x9d7 ||
          lookahead == 0x9e2 ||
          lookahead == 0x9e3 ||
          lookahead == 0x9fe ||
          (0xa01 <= lookahead && lookahead <= 0xa03) ||
          lookahead == 0xa3c ||
          (0xa3e <= lookahead && lookahead <= 0xa42) ||
          lookahead == 0xa47 ||
          lookahead == 0xa48 ||
          (0xa4b <= lookahead && lookahead <= 0xa4d) ||
          lookahead == 0xa51 ||
          lookahead == 0xa70 ||
          lookahead == 0xa71 ||
          lookahead == 0xa75 ||
          (0xa81 <= lookahead && lookahead <= 0xa83) ||
          lookahead == 0xabc ||
          (0xabe <= lookahead && lookahead <= 0xac5) ||
          (0xac7 <= lookahead && lookahead <= 0xac9) ||
          (0xacb <= lookahead && lookahead <= 0xacd) ||
          lookahead == 0xae2 ||
          lookahead == 0xae3 ||
          (0xafa <= lookahead && lookahead <= 0xaff) ||
          (0xb01 <= lookahead && lookahead <= 0xb03) ||
          lookahead == 0xb3c ||
          (0xb3e <= lookahead && lookahead <= 0xb44) ||
          lookahead == 0xb47 ||
          lookahead == 0xb48 ||
          (0xb4b <= lookahead && lookahead <= 0xb4d) ||
          (0xb55 <= lookahead && lookahead <= 0xb57) ||
          lookahead == 0xb62 ||
          lookahead == 0xb63 ||
          lookahead == 0xb82 ||
          (0xbbe <= lookahead && lookahead <= 0xbc2) ||
          (0xbc6 <= lookahead && lookahead <= 0xbc8) ||
          (0xbca <= lookahead && lookahead <= 0xbcd) ||
          lookahead == 0xbd7 ||
          (0xc00 <= lookahead && lookahead <= 0xc04) ||
          lookahead == 0xc3c ||
          (0xc3e <= lookahead && lookahead <= 0xc44) ||
          (0xc46 <= lookahead && lookahead <= 0xc48) ||
          (0xc4a <= lookahead && lookahead <= 0xc4d) ||
          lookahead == 0xc55 ||
          lookahead == 0xc56 ||
          lookahead == 0xc62 ||
          lookahead == 0xc63 ||
          (0xc81 <= lookahead && lookahead <= 0xc83) ||
          lookahead == 0xcbc ||
          (0xcbe <= lookahead && lookahead <= 0xcc4) ||
          (0xcc6 <= lookahead && lookahead <= 0xcc8) ||
          (0xcca <= lookahead && lookahead <= 0xccd) ||
          lookahead == 0xcd5 ||
          lookahead == 0xcd6 ||
          lookahead == 0xce2 ||
          lookahead == 0xce3 ||
          (0xd00 <= lookahead && lookahead <= 0xd03) ||
          lookahead == 0xd3b ||
          lookahead == 0xd3c ||
          (0xd3e <= lookahead && lookahead <= 0xd44) ||
          (0xd46 <= lookahead && lookahead <= 0xd48) ||
          (0xd4a <= lookahead && lookahead <= 0xd4d) ||
          lookahead == 0xd57 ||
          lookahead == 0xd62 ||
          lookahead == 0xd63 ||
          (0xd81 <= lookahead && lookahead <= 0xd83) ||
          lookahead == 0xdca ||
          (0xdcf <= lookahead && lookahead <= 0xdd4) ||
          lookahead == 0xdd6 ||
          (0xdd8 <= lookahead && lookahead <= 0xddf) ||
          lookahead == 0xdf2 ||
          lookahead == 0xdf3 ||
          lookahead == 0xe31 ||
          (0xe34 <= lookahead && lookahead <= 0xe3a) ||
          (0xe47 <= lookahead && lookahead <= 0xe4e) ||
          lookahead == 0xeb1 ||
          (0xeb4 <= lookahead && lookahead <= 0xebc) ||
          (0xec8 <= lookahead && lookahead <= 0xecd) ||
          lookahead == 0xf18 ||
          lookahead == 0xf19 ||
          lookahead == 0xf35 ||
          lookahead == 0xf37 ||
          lookahead == 0xf39 ||
          lookahead == 0xf3e ||
          lookahead == 0xf3f ||
          (0xf71 <= lookahead && lookahead <= 0xf84) ||
          lookahead == 0xf86 ||
          lookahead == 0xf87 ||
          (0xf8d <= lookahead && lookahead <= 0xf97) ||
          (0xf99 <= lookahead && lookahead <= 0xfbc) ||
          lookahead == 0xfc6 ||
          (0x102b <= lookahead && lookahead <= 0x103e) ||
          (0x1056 <= lookahead && lookahead <= 0x1059) ||
          (0x105e <= lookahead && lookahead <= 0x1060) ||
          (0x1062 <= lookahead && lookahead <= 0x1064) ||
          (0x1067 <= lookahead && lookahead <= 0x106d) ||
          (0x1071 <= lookahead && lookahead <= 0x1074) ||
          (0x1082 <= lookahead && lookahead <= 0x108d) ||
          lookahead == 0x108f ||
          (0x109a <= lookahead && lookahead <= 0x109d) ||
          (0x135d <= lookahead && lookahead <= 0x135f) ||
          (0x1712 <= lookahead && lookahead <= 0x1715) ||
          (0x1732 <= lookahead && lookahead <= 0x1734) ||
          lookahead == 0x1752 ||
          lookahead == 0x1753 ||
          lookahead == 0x1772 ||
          lookahead == 0x1773 ||
          (0x17b4 <= lookahead && lookahead <= 0x17d3) ||
          lookahead == 0x17dd ||
          (0x180b <= lookahead && lookahead <= 0x180d) ||
          lookahead == 0x180f ||
          lookahead == 0x1885 ||
          lookahead == 0x1886 ||
          lookahead == 0x18a9 ||
          (0x1920 <= lookahead && lookahead <= 0x192b) ||
          (0x1930 <= lookahead && lookahead <= 0x193b) ||
          (0x1a17 <= lookahead && lookahead <= 0x1a1b) ||
          (0x1a55 <= lookahead && lookahead <= 0x1a5e) ||
          (0x1a60 <= lookahead && lookahead <= 0x1a7c) ||
          lookahead == 0x1a7f ||
          (0x1ab0 <= lookahead && lookahead <= 0x1ace) ||
          (0x1b00 <= lookahead && lookahead <= 0x1b04) ||
          (0x1b34 <= lookahead && lookahead <= 0x1b44) ||
          (0x1b6b <= lookahead && lookahead <= 0x1b73) ||
          (0x1b80 <= lookahead && lookahead <= 0x1b82) ||
          (0x1ba1 <= lookahead && lookahead <= 0x1bad) ||
          (0x1be6 <= lookahead && lookahead <= 0x1bf3) ||
          (0x1c24 <= lookahead && lookahead <= 0x1c37) ||
          (0x1cd0 <= lookahead && lookahead <= 0x1cd2) ||
          (0x1cd4 <= lookahead && lookahead <= 0x1ce8) ||
          lookahead == 0x1ced ||
          lookahead == 0x1cf4 ||
          (0x1cf7 <= lookahead && lookahead <= 0x1cf9) ||
          (0x1dc0 <= lookahead && lookahead <= 0x1dff) ||
          (0x20d0 <= lookahead && lookahead <= 0x20f0) ||
          (0x2cef <= lookahead && lookahead <= 0x2cf1) ||
          lookahead == 0x2d7f ||
          (0x2de0 <= lookahead && lookahead <= 0x2dff) ||
          (0x302a <= lookahead && lookahead <= 0x302f) ||
          lookahead == 0x3099 ||
          lookahead == 0x309a ||
          (0xa66f <= lookahead && lookahead <= 0xa672) ||
          (0xa674 <= lookahead && lookahead <= 0xa67d) ||
          lookahead == 0xa69e ||
          lookahead == 0xa69f ||
          lookahead == 0xa6f0 ||
          lookahead == 0xa6f1 ||
          lookahead == 0xa802 ||
          lookahead == 0xa806 ||
          lookahead == 0xa80b ||
          (0xa823 <= lookahead && lookahead <= 0xa827) ||
          lookahead == 0xa82c ||
          lookahead == 0xa880 ||
          lookahead == 0xa881 ||
          (0xa8b4 <= lookahead && lookahead <= 0xa8c5) ||
          (0xa8e0 <= lookahead && lookahead <= 0xa8f1) ||
          lookahead == 0xa8ff ||
          (0xa926 <= lookahead && lookahead <= 0xa92d) ||
          (0xa947 <= lookahead && lookahead <= 0xa953) ||
          (0xa980 <= lookahead && lookahead <= 0xa983) ||
          (0xa9b3 <= lookahead && lookahead <= 0xa9c0) ||
          lookahead == 0xa9e5 ||
          (0xaa29 <= lookahead && lookahead <= 0xaa36) ||
          lookahead == 0xaa43 ||
          lookahead == 0xaa4c ||
          lookahead == 0xaa4d ||
          (0xaa7b <= lookahead && lookahead <= 0xaa7d) ||
          lookahead == 0xaab0 ||
          (0xaab2 <= lookahead && lookahead <= 0xaab4) ||
          lookahead == 0xaab7 ||
          lookahead == 0xaab8 ||
          lookahead == 0xaabe ||
          lookahead == 0xaabf ||
          lookahead == 0xaac1 ||
          (0xaaeb <= lookahead && lookahead <= 0xaaef) ||
          lookahead == 0xaaf5 ||
          lookahead == 0xaaf6 ||
          (0xabe3 <= lookahead && lookahead <= 0xabea) ||
          lookahead == 0xabec ||
          lookahead == 0xabed ||
          lookahead == 0xfb1e ||
          (0xfe00 <= lookahead && lookahead <= 0xfe0f) ||
          (0xfe20 <= lookahead && lookahead <= 0xfe2f) ||
          lookahead == 0x101fd ||
          lookahead == 0x102e0 ||
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(28);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(29);
      if (set_contains(sym_metadata_key_character_set_2, 433, lookahead)) ADVANCE(28);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_STRING1);
      if (lookahead == '\r') ADVANCE(30);
      if (lookahead == '\\') ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(31);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_STRING1);
      if (lookahead == '\\') ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_STRING1);
      if (lookahead == '\\') ADVANCE(32);
      if (lookahead != 0) ADVANCE(31);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_STRING2);
      if (lookahead == '\r') ADVANCE(33);
      if (lookahead == '\\') ADVANCE(35);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(34);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_STRING2);
      if (lookahead == '\\') ADVANCE(35);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_STRING2);
      if (lookahead == '\\') ADVANCE(35);
      if (lookahead != 0) ADVANCE(34);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__LITERAL_VERSION_COMMENT);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym__LITERAL_NODE_EMBED_DECLARATION);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(29);
      if ((0x300 <= lookahead && lookahead <= 0x36f) ||
          (0x483 <= lookahead && lookahead <= 0x489) ||
          (0x591 <= lookahead && lookahead <= 0x5bd) ||
          lookahead == 0x5bf ||
          lookahead == 0x5c1 ||
          lookahead == 0x5c2 ||
          lookahead == 0x5c4 ||
          lookahead == 0x5c5 ||
          lookahead == 0x5c7 ||
          (0x610 <= lookahead && lookahead <= 0x61a) ||
          (0x64b <= lookahead && lookahead <= 0x65f) ||
          lookahead == 0x670 ||
          (0x6d6 <= lookahead && lookahead <= 0x6dc) ||
          (0x6df <= lookahead && lookahead <= 0x6e4) ||
          lookahead == 0x6e7 ||
          lookahead == 0x6e8 ||
          (0x6ea <= lookahead && lookahead <= 0x6ed) ||
          lookahead == 0x711 ||
          (0x730 <= lookahead && lookahead <= 0x74a) ||
          (0x7a6 <= lookahead && lookahead <= 0x7b0) ||
          (0x7eb <= lookahead && lookahead <= 0x7f3) ||
          lookahead == 0x7fd ||
          (0x816 <= lookahead && lookahead <= 0x819) ||
          (0x81b <= lookahead && lookahead <= 0x823) ||
          (0x825 <= lookahead && lookahead <= 0x827) ||
          (0x829 <= lookahead && lookahead <= 0x82d) ||
          (0x859 <= lookahead && lookahead <= 0x85b) ||
          (0x898 <= lookahead && lookahead <= 0x89f) ||
          (0x8ca <= lookahead && lookahead <= 0x8e1) ||
          (0x8e3 <= lookahead && lookahead <= 0x903) ||
          (0x93a <= lookahead && lookahead <= 0x93c) ||
          (0x93e <= lookahead && lookahead <= 0x94f) ||
          (0x951 <= lookahead && lookahead <= 0x957) ||
          lookahead == 0x962 ||
          lookahead == 0x963 ||
          (0x981 <= lookahead && lookahead <= 0x983) ||
          lookahead == 0x9bc ||
          (0x9be <= lookahead && lookahead <= 0x9c4) ||
          lookahead == 0x9c7 ||
          lookahead == 0x9c8 ||
          (0x9cb <= lookahead && lookahead <= 0x9cd) ||
          lookahead == 0x9d7 ||
          lookahead == 0x9e2 ||
          lookahead == 0x9e3 ||
          lookahead == 0x9fe ||
          (0xa01 <= lookahead && lookahead <= 0xa03) ||
          lookahead == 0xa3c ||
          (0xa3e <= lookahead && lookahead <= 0xa42) ||
          lookahead == 0xa47 ||
          lookahead == 0xa48 ||
          (0xa4b <= lookahead && lookahead <= 0xa4d) ||
          lookahead == 0xa51 ||
          lookahead == 0xa70 ||
          lookahead == 0xa71 ||
          lookahead == 0xa75 ||
          (0xa81 <= lookahead && lookahead <= 0xa83) ||
          lookahead == 0xabc ||
          (0xabe <= lookahead && lookahead <= 0xac5) ||
          (0xac7 <= lookahead && lookahead <= 0xac9) ||
          (0xacb <= lookahead && lookahead <= 0xacd) ||
          lookahead == 0xae2 ||
          lookahead == 0xae3 ||
          (0xafa <= lookahead && lookahead <= 0xaff) ||
          (0xb01 <= lookahead && lookahead <= 0xb03) ||
          lookahead == 0xb3c ||
          (0xb3e <= lookahead && lookahead <= 0xb44) ||
          lookahead == 0xb47 ||
          lookahead == 0xb48 ||
          (0xb4b <= lookahead && lookahead <= 0xb4d) ||
          (0xb55 <= lookahead && lookahead <= 0xb57) ||
          lookahead == 0xb62 ||
          lookahead == 0xb63 ||
          lookahead == 0xb82 ||
          (0xbbe <= lookahead && lookahead <= 0xbc2) ||
          (0xbc6 <= lookahead && lookahead <= 0xbc8) ||
          (0xbca <= lookahead && lookahead <= 0xbcd) ||
          lookahead == 0xbd7 ||
          (0xc00 <= lookahead && lookahead <= 0xc04) ||
          lookahead == 0xc3c ||
          (0xc3e <= lookahead && lookahead <= 0xc44) ||
          (0xc46 <= lookahead && lookahead <= 0xc48) ||
          (0xc4a <= lookahead && lookahead <= 0xc4d) ||
          lookahead == 0xc55 ||
          lookahead == 0xc56 ||
          lookahead == 0xc62 ||
          lookahead == 0xc63 ||
          (0xc81 <= lookahead && lookahead <= 0xc83) ||
          lookahead == 0xcbc ||
          (0xcbe <= lookahead && lookahead <= 0xcc4) ||
          (0xcc6 <= lookahead && lookahead <= 0xcc8) ||
          (0xcca <= lookahead && lookahead <= 0xccd) ||
          lookahead == 0xcd5 ||
          lookahead == 0xcd6 ||
          lookahead == 0xce2 ||
          lookahead == 0xce3 ||
          (0xd00 <= lookahead && lookahead <= 0xd03) ||
          lookahead == 0xd3b ||
          lookahead == 0xd3c ||
          (0xd3e <= lookahead && lookahead <= 0xd44) ||
          (0xd46 <= lookahead && lookahead <= 0xd48) ||
          (0xd4a <= lookahead && lookahead <= 0xd4d) ||
          lookahead == 0xd57 ||
          lookahead == 0xd62 ||
          lookahead == 0xd63 ||
          (0xd81 <= lookahead && lookahead <= 0xd83) ||
          lookahead == 0xdca ||
          (0xdcf <= lookahead && lookahead <= 0xdd4) ||
          lookahead == 0xdd6 ||
          (0xdd8 <= lookahead && lookahead <= 0xddf) ||
          lookahead == 0xdf2 ||
          lookahead == 0xdf3 ||
          lookahead == 0xe31 ||
          (0xe34 <= lookahead && lookahead <= 0xe3a) ||
          (0xe47 <= lookahead && lookahead <= 0xe4e) ||
          lookahead == 0xeb1 ||
          (0xeb4 <= lookahead && lookahead <= 0xebc) ||
          (0xec8 <= lookahead && lookahead <= 0xecd) ||
          lookahead == 0xf18 ||
          lookahead == 0xf19 ||
          lookahead == 0xf35 ||
          lookahead == 0xf37 ||
          lookahead == 0xf39 ||
          lookahead == 0xf3e ||
          lookahead == 0xf3f ||
          (0xf71 <= lookahead && lookahead <= 0xf84) ||
          lookahead == 0xf86 ||
          lookahead == 0xf87 ||
          (0xf8d <= lookahead && lookahead <= 0xf97) ||
          (0xf99 <= lookahead && lookahead <= 0xfbc) ||
          lookahead == 0xfc6 ||
          (0x102b <= lookahead && lookahead <= 0x103e) ||
          (0x1056 <= lookahead && lookahead <= 0x1059) ||
          (0x105e <= lookahead && lookahead <= 0x1060) ||
          (0x1062 <= lookahead && lookahead <= 0x1064) ||
          (0x1067 <= lookahead && lookahead <= 0x106d) ||
          (0x1071 <= lookahead && lookahead <= 0x1074) ||
          (0x1082 <= lookahead && lookahead <= 0x108d) ||
          lookahead == 0x108f ||
          (0x109a <= lookahead && lookahead <= 0x109d) ||
          (0x135d <= lookahead && lookahead <= 0x135f) ||
          (0x1712 <= lookahead && lookahead <= 0x1715) ||
          (0x1732 <= lookahead && lookahead <= 0x1734) ||
          lookahead == 0x1752 ||
          lookahead == 0x1753 ||
          lookahead == 0x1772 ||
          lookahead == 0x1773 ||
          (0x17b4 <= lookahead && lookahead <= 0x17d3) ||
          lookahead == 0x17dd ||
          (0x180b <= lookahead && lookahead <= 0x180d) ||
          lookahead == 0x180f ||
          lookahead == 0x1885 ||
          lookahead == 0x1886 ||
          lookahead == 0x18a9 ||
          (0x1920 <= lookahead && lookahead <= 0x192b) ||
          (0x1930 <= lookahead && lookahead <= 0x193b) ||
          (0x1a17 <= lookahead && lookahead <= 0x1a1b) ||
          (0x1a55 <= lookahead && lookahead <= 0x1a5e) ||
          (0x1a60 <= lookahead && lookahead <= 0x1a7c) ||
          lookahead == 0x1a7f ||
          (0x1ab0 <= lookahead && lookahead <= 0x1ace) ||
          (0x1b00 <= lookahead && lookahead <= 0x1b04) ||
          (0x1b34 <= lookahead && lookahead <= 0x1b44) ||
          (0x1b6b <= lookahead && lookahead <= 0x1b73) ||
          (0x1b80 <= lookahead && lookahead <= 0x1b82) ||
          (0x1ba1 <= lookahead && lookahead <= 0x1bad) ||
          (0x1be6 <= lookahead && lookahead <= 0x1bf3) ||
          (0x1c24 <= lookahead && lookahead <= 0x1c37) ||
          (0x1cd0 <= lookahead && lookahead <= 0x1cd2) ||
          (0x1cd4 <= lookahead && lookahead <= 0x1ce8) ||
          lookahead == 0x1ced ||
          lookahead == 0x1cf4 ||
          (0x1cf7 <= lookahead && lookahead <= 0x1cf9) ||
          (0x1dc0 <= lookahead && lookahead <= 0x1dff) ||
          (0x20d0 <= lookahead && lookahead <= 0x20f0) ||
          (0x2cef <= lookahead && lookahead <= 0x2cf1) ||
          lookahead == 0x2d7f ||
          (0x2de0 <= lookahead && lookahead <= 0x2dff) ||
          (0x302a <= lookahead && lookahead <= 0x302f) ||
          lookahead == 0x3099 ||
          lookahead == 0x309a ||
          (0xa66f <= lookahead && lookahead <= 0xa672) ||
          (0xa674 <= lookahead && lookahead <= 0xa67d) ||
          lookahead == 0xa69e ||
          lookahead == 0xa69f ||
          lookahead == 0xa6f0 ||
          lookahead == 0xa6f1 ||
          lookahead == 0xa802 ||
          lookahead == 0xa806 ||
          lookahead == 0xa80b ||
          (0xa823 <= lookahead && lookahead <= 0xa827) ||
          lookahead == 0xa82c ||
          lookahead == 0xa880 ||
          lookahead == 0xa881 ||
          (0xa8b4 <= lookahead && lookahead <= 0xa8c5) ||
          (0xa8e0 <= lookahead && lookahead <= 0xa8f1) ||
          lookahead == 0xa8ff ||
          (0xa926 <= lookahead && lookahead <= 0xa92d) ||
          (0xa947 <= lookahead && lookahead <= 0xa953) ||
          (0xa980 <= lookahead && lookahead <= 0xa983) ||
          (0xa9b3 <= lookahead && lookahead <= 0xa9c0) ||
          lookahead == 0xa9e5 ||
          (0xaa29 <= lookahead && lookahead <= 0xaa36) ||
          lookahead == 0xaa43 ||
          lookahead == 0xaa4c ||
          lookahead == 0xaa4d ||
          (0xaa7b <= lookahead && lookahead <= 0xaa7d) ||
          lookahead == 0xaab0 ||
          (0xaab2 <= lookahead && lookahead <= 0xaab4) ||
          lookahead == 0xaab7 ||
          lookahead == 0xaab8 ||
          lookahead == 0xaabe ||
          lookahead == 0xaabf ||
          lookahead == 0xaac1 ||
          (0xaaeb <= lookahead && lookahead <= 0xaaef) ||
          lookahead == 0xaaf5 ||
          lookahead == 0xaaf6 ||
          (0xabe3 <= lookahead && lookahead <= 0xabea) ||
          lookahead == 0xabec ||
          lookahead == 0xabed ||
          lookahead == 0xfb1e ||
          (0xfe00 <= lookahead && lookahead <= 0xfe0f) ||
          (0xfe20 <= lookahead && lookahead <= 0xfe2f) ||
          lookahead == 0x101fd ||
          lookahead == 0x102e0 ||
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(28);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(28);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym__SYMBOL_NODE_DEF);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym__SYMBOL_METADATA_ASSIGNMENT);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_SYMBOL_EMPTY_NODE);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_SYMBOL_EMPTY_NODE);
      if (lookahead == '<') ADVANCE(8);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym__SYMBOL_SINGLE_QUOTE);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym__SYMBOL_DOUBLE_QUOTE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 1, .external_lex_state = 2},
  [2] = {.lex_state = 0, .external_lex_state = 3},
  [3] = {.lex_state = 0, .external_lex_state = 3},
  [4] = {.lex_state = 0, .external_lex_state = 3},
  [5] = {.lex_state = 0, .external_lex_state = 3},
  [6] = {.lex_state = 0, .external_lex_state = 4},
  [7] = {.lex_state = 0, .external_lex_state = 4},
  [8] = {.lex_state = 0, .external_lex_state = 4},
  [9] = {.lex_state = 2, .external_lex_state = 5},
  [10] = {.lex_state = 0, .external_lex_state = 6},
  [11] = {.lex_state = 0, .external_lex_state = 6},
  [12] = {.lex_state = 0, .external_lex_state = 4},
  [13] = {.lex_state = 2, .external_lex_state = 5},
  [14] = {.lex_state = 0, .external_lex_state = 6},
  [15] = {.lex_state = 0, .external_lex_state = 4},
  [16] = {.lex_state = 0, .external_lex_state = 7},
  [17] = {.lex_state = 0, .external_lex_state = 2},
  [18] = {.lex_state = 0, .external_lex_state = 7},
  [19] = {.lex_state = 0, .external_lex_state = 2},
  [20] = {.lex_state = 0, .external_lex_state = 2},
  [21] = {.lex_state = 0, .external_lex_state = 7},
  [22] = {.lex_state = 0, .external_lex_state = 7},
  [23] = {.lex_state = 0, .external_lex_state = 2},
  [24] = {.lex_state = 0, .external_lex_state = 7},
  [25] = {.lex_state = 0, .external_lex_state = 7},
  [26] = {.lex_state = 0, .external_lex_state = 2},
  [27] = {.lex_state = 0, .external_lex_state = 5},
  [28] = {.lex_state = 0, .external_lex_state = 3},
  [29] = {.lex_state = 0, .external_lex_state = 5},
  [30] = {.lex_state = 0, .external_lex_state = 3},
  [31] = {.lex_state = 0, .external_lex_state = 2},
  [32] = {.lex_state = 0, .external_lex_state = 3},
  [33] = {.lex_state = 0, .external_lex_state = 5},
  [34] = {.lex_state = 2, .external_lex_state = 5},
  [35] = {.lex_state = 0, .external_lex_state = 5},
  [36] = {.lex_state = 0, .external_lex_state = 3},
  [37] = {.lex_state = 0, .external_lex_state = 3},
  [38] = {.lex_state = 0, .external_lex_state = 5},
  [39] = {.lex_state = 0, .external_lex_state = 3},
  [40] = {.lex_state = 0, .external_lex_state = 2},
  [41] = {.lex_state = 0, .external_lex_state = 3},
  [42] = {.lex_state = 0, .external_lex_state = 3},
  [43] = {.lex_state = 0, .external_lex_state = 5},
  [44] = {.lex_state = 0, .external_lex_state = 3},
  [45] = {.lex_state = 0, .external_lex_state = 3},
  [46] = {.lex_state = 0, .external_lex_state = 7},
  [47] = {.lex_state = 0, .external_lex_state = 3},
  [48] = {.lex_state = 0, .external_lex_state = 3},
  [49] = {.lex_state = 0, .external_lex_state = 2},
  [50] = {.lex_state = 0, .external_lex_state = 5},
  [51] = {.lex_state = 0, .external_lex_state = 5},
  [52] = {.lex_state = 0, .external_lex_state = 5},
  [53] = {.lex_state = 0, .external_lex_state = 5},
  [54] = {.lex_state = 0, .external_lex_state = 5},
  [55] = {.lex_state = 0, .external_lex_state = 7},
  [56] = {.lex_state = 0, .external_lex_state = 7},
  [57] = {.lex_state = 0, .external_lex_state = 5},
  [58] = {.lex_state = 0, .external_lex_state = 5},
  [59] = {.lex_state = 3, .external_lex_state = 8},
  [60] = {.lex_state = 0, .external_lex_state = 5},
  [61] = {.lex_state = 3, .external_lex_state = 8},
  [62] = {.lex_state = 0, .external_lex_state = 5},
  [63] = {.lex_state = 0, .external_lex_state = 5},
  [64] = {.lex_state = 0, .external_lex_state = 5},
  [65] = {.lex_state = 2, .external_lex_state = 5},
  [66] = {.lex_state = 0, .external_lex_state = 5},
  [67] = {.lex_state = 0, .external_lex_state = 5},
  [68] = {.lex_state = 0, .external_lex_state = 5},
  [69] = {.lex_state = 0, .external_lex_state = 5},
  [70] = {.lex_state = 0, .external_lex_state = 5},
  [71] = {.lex_state = 0, .external_lex_state = 5},
  [72] = {.lex_state = 0, .external_lex_state = 5},
  [73] = {.lex_state = 2, .external_lex_state = 5},
  [74] = {.lex_state = 0, .external_lex_state = 5},
  [75] = {.lex_state = 0, .external_lex_state = 5},
  [76] = {.lex_state = 0, .external_lex_state = 5},
  [77] = {.lex_state = 0, .external_lex_state = 5},
  [78] = {.lex_state = 0, .external_lex_state = 4},
  [79] = {.lex_state = 0, .external_lex_state = 4},
  [80] = {.lex_state = 0, .external_lex_state = 6},
  [81] = {.lex_state = 2, .external_lex_state = 8},
  [82] = {.lex_state = 0, .external_lex_state = 9},
  [83] = {.lex_state = 0, .external_lex_state = 9},
  [84] = {.lex_state = 0, .external_lex_state = 6},
  [85] = {.lex_state = 0, .external_lex_state = 6},
  [86] = {.lex_state = 0, .external_lex_state = 5},
  [87] = {.lex_state = 0, .external_lex_state = 3},
  [88] = {.lex_state = 0, .external_lex_state = 6},
  [89] = {.lex_state = 0, .external_lex_state = 3},
  [90] = {.lex_state = 0, .external_lex_state = 3},
  [91] = {.lex_state = 2, .external_lex_state = 8},
  [92] = {.lex_state = 0, .external_lex_state = 3},
  [93] = {.lex_state = 0, .external_lex_state = 5},
  [94] = {.lex_state = 0, .external_lex_state = 5},
  [95] = {.lex_state = 0, .external_lex_state = 6},
  [96] = {.lex_state = 0, .external_lex_state = 5},
  [97] = {.lex_state = 0, .external_lex_state = 9},
  [98] = {.lex_state = 0, .external_lex_state = 5},
  [99] = {.lex_state = 0, .external_lex_state = 9},
  [100] = {.lex_state = 0, .external_lex_state = 9},
  [101] = {.lex_state = 0, .external_lex_state = 6},
  [102] = {.lex_state = 0, .external_lex_state = 3},
  [103] = {.lex_state = 0, .external_lex_state = 3},
  [104] = {.lex_state = 0, .external_lex_state = 3},
  [105] = {.lex_state = 0, .external_lex_state = 6},
  [106] = {.lex_state = 0, .external_lex_state = 5},
  [107] = {.lex_state = 0, .external_lex_state = 9},
  [108] = {.lex_state = 0, .external_lex_state = 6},
  [109] = {.lex_state = 0, .external_lex_state = 5},
  [110] = {.lex_state = 0, .external_lex_state = 5},
  [111] = {.lex_state = 0, .external_lex_state = 5},
  [112] = {.lex_state = 0, .external_lex_state = 3},
  [113] = {.lex_state = 0, .external_lex_state = 4},
  [114] = {.lex_state = 2, .external_lex_state = 5},
  [115] = {.lex_state = 0, .external_lex_state = 4},
  [116] = {.lex_state = 0, .external_lex_state = 6},
  [117] = {.lex_state = 0, .external_lex_state = 4},
  [118] = {.lex_state = 0, .external_lex_state = 3},
  [119] = {.lex_state = 0, .external_lex_state = 4},
  [120] = {.lex_state = 0, .external_lex_state = 9},
  [121] = {.lex_state = 0, .external_lex_state = 4},
  [122] = {.lex_state = 0, .external_lex_state = 6},
  [123] = {.lex_state = 0, .external_lex_state = 4},
  [124] = {.lex_state = 0, .external_lex_state = 4},
  [125] = {.lex_state = 0, .external_lex_state = 4},
  [126] = {.lex_state = 0, .external_lex_state = 3},
  [127] = {.lex_state = 0, .external_lex_state = 10},
  [128] = {.lex_state = 0, .external_lex_state = 5},
  [129] = {.lex_state = 0, .external_lex_state = 2},
  [130] = {.lex_state = 2},
  [131] = {.lex_state = 6},
  [132] = {.lex_state = 0, .external_lex_state = 2},
  [133] = {.lex_state = 0, .external_lex_state = 10},
  [134] = {.lex_state = 0, .external_lex_state = 9},
  [135] = {.lex_state = 0, .external_lex_state = 5},
  [136] = {.lex_state = 6},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 6},
  [139] = {.lex_state = 0, .external_lex_state = 5},
  [140] = {.lex_state = 0, .external_lex_state = 2},
  [141] = {.lex_state = 0, .external_lex_state = 10},
  [142] = {.lex_state = 6},
  [143] = {.lex_state = 4},
  [144] = {.lex_state = 6},
  [145] = {.lex_state = 0, .external_lex_state = 10},
  [146] = {.lex_state = 6},
  [147] = {.lex_state = 0, .external_lex_state = 10},
  [148] = {.lex_state = 0, .external_lex_state = 2},
  [149] = {.lex_state = 6},
  [150] = {.lex_state = 0, .external_lex_state = 5},
  [151] = {.lex_state = 0, .external_lex_state = 2},
  [152] = {.lex_state = 0, .external_lex_state = 10},
  [153] = {.lex_state = 6},
  [154] = {.lex_state = 0, .external_lex_state = 5},
  [155] = {.lex_state = 0, .external_lex_state = 9},
  [156] = {.lex_state = 5},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0, .external_lex_state = 10},
  [159] = {.lex_state = 0, .external_lex_state = 11},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0, .external_lex_state = 11},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 1},
  [166] = {.lex_state = 0, .external_lex_state = 11},
  [167] = {.lex_state = 4},
  [168] = {.lex_state = 0, .external_lex_state = 10},
  [169] = {.lex_state = 1},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 5},
  [173] = {.lex_state = 0, .external_lex_state = 8},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 0, .external_lex_state = 11},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0, .external_lex_state = 10},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_metadata_key] = ACTIONS(1),
    [sym__LITERAL_VERSION_COMMENT] = ACTIONS(1),
    [sym__LITERAL_NODE_EMBED_DECLARATION] = ACTIONS(1),
    [sym__SYMBOL_NODE_DEF] = ACTIONS(1),
    [sym__SYMBOL_METADATA_ASSIGNMENT] = ACTIONS(1),
    [sym_SYMBOL_EMPTY_NODE] = ACTIONS(1),
    [sym__SYMBOL_SINGLE_QUOTE] = ACTIONS(1),
    [sym__SYMBOL_DOUBLE_QUOTE] = ACTIONS(1),
    [sym__error_sentinel] = ACTIONS(1),
    [sym__eod_sentinel] = ACTIONS(1),
    [sym__ext_eol] = ACTIONS(1),
    [sym__ext_empty_line] = ACTIONS(1),
    [sym__ext_nih_whitespace] = ACTIONS(1),
    [sym__ext_node_continue] = ACTIONS(1),
    [sym__ext_flag_node_def] = ACTIONS(1),
    [sym__ext_node_begin] = ACTIONS(1),
    [sym__ext_node_end] = ACTIONS(1),
    [sym_autoclose_warning] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(176),
    [sym_empty_line] = STATE(10),
    [sym_version_comment] = STATE(20),
    [sym__node_segment] = STATE(10),
    [sym_content_line] = STATE(10),
    [sym_node] = STATE(10),
    [sym_node_title_line] = STATE(3),
    [aux_sym_document_repeat1] = STATE(10),
    [sym__LITERAL_VERSION_COMMENT] = ACTIONS(3),
    [sym__ext_empty_line] = ACTIONS(5),
    [sym__ext_node_continue] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(11), 1,
      sym__ext_node_continue,
    ACTIONS(13), 1,
      sym__ext_node_begin,
    STATE(28), 1,
      aux_sym__pending_regular_node_repeat1,
    STATE(40), 1,
      aux_sym__pending_embed_node_repeat1,
    STATE(48), 1,
      sym_node_embed_declaration,
    STATE(89), 1,
      sym_node_metadata_declaration,
    STATE(113), 2,
      sym__pending_regular_node,
      sym__pending_embed_node,
    STATE(5), 3,
      sym_empty_line,
      sym_node_title_line,
      aux_sym_node_repeat1,
  [31] = 9,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(15), 1,
      sym__ext_node_continue,
    ACTIONS(17), 1,
      sym__ext_node_begin,
    STATE(30), 1,
      aux_sym__pending_regular_node_repeat1,
    STATE(31), 1,
      aux_sym__pending_embed_node_repeat1,
    STATE(47), 1,
      sym_node_embed_declaration,
    STATE(89), 1,
      sym_node_metadata_declaration,
    STATE(88), 2,
      sym__pending_regular_node,
      sym__pending_embed_node,
    STATE(4), 3,
      sym_empty_line,
      sym_node_title_line,
      aux_sym_node_repeat1,
  [62] = 9,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(15), 1,
      sym__ext_node_continue,
    ACTIONS(17), 1,
      sym__ext_node_begin,
    STATE(30), 1,
      aux_sym__pending_regular_node_repeat1,
    STATE(31), 1,
      aux_sym__pending_embed_node_repeat1,
    STATE(47), 1,
      sym_node_embed_declaration,
    STATE(89), 1,
      sym_node_metadata_declaration,
    STATE(108), 2,
      sym__pending_regular_node,
      sym__pending_embed_node,
    STATE(39), 3,
      sym_empty_line,
      sym_node_title_line,
      aux_sym_node_repeat1,
  [93] = 9,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(11), 1,
      sym__ext_node_continue,
    ACTIONS(13), 1,
      sym__ext_node_begin,
    STATE(28), 1,
      aux_sym__pending_regular_node_repeat1,
    STATE(40), 1,
      aux_sym__pending_embed_node_repeat1,
    STATE(48), 1,
      sym_node_embed_declaration,
    STATE(89), 1,
      sym_node_metadata_declaration,
    STATE(117), 2,
      sym__pending_regular_node,
      sym__pending_embed_node,
    STATE(39), 3,
      sym_empty_line,
      sym_node_title_line,
      aux_sym_node_repeat1,
  [124] = 5,
    ACTIONS(19), 1,
      sym__ext_empty_line,
    ACTIONS(21), 1,
      sym__ext_node_continue,
    ACTIONS(23), 1,
      sym__ext_node_end,
    STATE(2), 1,
      sym_node_title_line,
    STATE(8), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [144] = 5,
    ACTIONS(19), 1,
      sym__ext_empty_line,
    ACTIONS(21), 1,
      sym__ext_node_continue,
    ACTIONS(25), 1,
      sym__ext_node_end,
    STATE(2), 1,
      sym_node_title_line,
    STATE(8), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [164] = 5,
    ACTIONS(27), 1,
      sym__ext_empty_line,
    ACTIONS(30), 1,
      sym__ext_node_continue,
    ACTIONS(33), 1,
      sym__ext_node_end,
    STATE(2), 1,
      sym_node_title_line,
    STATE(8), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [184] = 8,
    ACTIONS(35), 1,
      aux_sym_inline_richtext_token1,
    ACTIONS(37), 1,
      sym__ext_eol,
    ACTIONS(39), 1,
      sym__ext_nih_whitespace,
    STATE(62), 1,
      sym_inline_richtext,
    STATE(73), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(98), 1,
      aux_sym__eol_repeat1,
    STATE(126), 1,
      sym__eol,
    STATE(13), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [210] = 5,
    ACTIONS(5), 1,
      sym__ext_empty_line,
    ACTIONS(7), 1,
      sym__ext_node_continue,
    ACTIONS(41), 1,
      sym__eod_sentinel,
    STATE(3), 1,
      sym_node_title_line,
    STATE(11), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [230] = 5,
    ACTIONS(33), 1,
      sym__eod_sentinel,
    ACTIONS(43), 1,
      sym__ext_empty_line,
    ACTIONS(46), 1,
      sym__ext_node_continue,
    STATE(3), 1,
      sym_node_title_line,
    STATE(11), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [250] = 5,
    ACTIONS(19), 1,
      sym__ext_empty_line,
    ACTIONS(21), 1,
      sym__ext_node_continue,
    ACTIONS(49), 1,
      sym__ext_node_end,
    STATE(2), 1,
      sym_node_title_line,
    STATE(8), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [270] = 8,
    ACTIONS(35), 1,
      aux_sym_inline_richtext_token1,
    ACTIONS(39), 1,
      sym__ext_nih_whitespace,
    ACTIONS(51), 1,
      sym__ext_eol,
    STATE(66), 1,
      sym_inline_richtext,
    STATE(73), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(98), 1,
      aux_sym__eol_repeat1,
    STATE(102), 1,
      sym__eol,
    STATE(34), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [296] = 5,
    ACTIONS(5), 1,
      sym__ext_empty_line,
    ACTIONS(7), 1,
      sym__ext_node_continue,
    ACTIONS(53), 1,
      sym__eod_sentinel,
    STATE(3), 1,
      sym_node_title_line,
    STATE(11), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [316] = 5,
    ACTIONS(19), 1,
      sym__ext_empty_line,
    ACTIONS(21), 1,
      sym__ext_node_continue,
    ACTIONS(55), 1,
      sym__ext_node_end,
    STATE(2), 1,
      sym_node_title_line,
    STATE(8), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [336] = 7,
    ACTIONS(57), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(59), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(61), 1,
      sym__ext_nih_whitespace,
    STATE(51), 1,
      sym_embed_type,
    STATE(56), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(128), 1,
      sym__string,
    STATE(24), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [359] = 4,
    ACTIONS(19), 1,
      sym__ext_empty_line,
    ACTIONS(21), 1,
      sym__ext_node_continue,
    STATE(2), 1,
      sym_node_title_line,
    STATE(15), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [376] = 7,
    ACTIONS(57), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(59), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(61), 1,
      sym__ext_nih_whitespace,
    STATE(53), 1,
      sym_metadata_value,
    STATE(56), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(154), 1,
      sym__string,
    STATE(46), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [399] = 4,
    ACTIONS(19), 1,
      sym__ext_empty_line,
    ACTIONS(21), 1,
      sym__ext_node_continue,
    STATE(2), 1,
      sym_node_title_line,
    STATE(12), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [416] = 4,
    ACTIONS(5), 1,
      sym__ext_empty_line,
    ACTIONS(7), 1,
      sym__ext_node_continue,
    STATE(3), 1,
      sym_node_title_line,
    STATE(14), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [433] = 7,
    ACTIONS(57), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(59), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(61), 1,
      sym__ext_nih_whitespace,
    STATE(52), 1,
      sym_metadata_value,
    STATE(56), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(154), 1,
      sym__string,
    STATE(18), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [456] = 7,
    ACTIONS(57), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(59), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(61), 1,
      sym__ext_nih_whitespace,
    STATE(56), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(71), 1,
      sym_metadata_value,
    STATE(154), 1,
      sym__string,
    STATE(46), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [479] = 4,
    ACTIONS(19), 1,
      sym__ext_empty_line,
    ACTIONS(21), 1,
      sym__ext_node_continue,
    STATE(2), 1,
      sym_node_title_line,
    STATE(6), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [496] = 7,
    ACTIONS(57), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(59), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(61), 1,
      sym__ext_nih_whitespace,
    STATE(56), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(69), 1,
      sym_embed_type,
    STATE(128), 1,
      sym__string,
    STATE(46), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [519] = 7,
    ACTIONS(57), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(59), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(61), 1,
      sym__ext_nih_whitespace,
    STATE(56), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(70), 1,
      sym_metadata_value,
    STATE(154), 1,
      sym__string,
    STATE(22), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [542] = 4,
    ACTIONS(19), 1,
      sym__ext_empty_line,
    ACTIONS(21), 1,
      sym__ext_node_continue,
    STATE(2), 1,
      sym_node_title_line,
    STATE(7), 5,
      sym_empty_line,
      sym__node_segment,
      sym_content_line,
      sym_node,
      aux_sym_document_repeat1,
  [559] = 6,
    ACTIONS(63), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(65), 1,
      sym__ext_eol,
    ACTIONS(68), 1,
      sym__ext_nih_whitespace,
    STATE(27), 1,
      aux_sym__string_double_repeat1,
    STATE(93), 1,
      aux_sym__eol_repeat1,
    STATE(168), 1,
      sym__eol,
  [578] = 4,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(71), 1,
      sym__ext_node_continue,
    ACTIONS(73), 1,
      sym__ext_node_begin,
    STATE(42), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_regular_node_repeat1,
  [593] = 6,
    ACTIONS(75), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(77), 1,
      sym__ext_eol,
    ACTIONS(79), 1,
      sym__ext_nih_whitespace,
    STATE(38), 1,
      aux_sym__string_double_repeat1,
    STATE(93), 1,
      aux_sym__eol_repeat1,
    STATE(168), 1,
      sym__eol,
  [612] = 4,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(81), 1,
      sym__ext_node_continue,
    ACTIONS(83), 1,
      sym__ext_node_begin,
    STATE(42), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_regular_node_repeat1,
  [627] = 4,
    ACTIONS(85), 1,
      sym__ext_empty_line,
    ACTIONS(87), 1,
      sym__ext_node_continue,
    STATE(44), 1,
      sym_node_embed_declaration,
    STATE(49), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_embed_node_repeat1,
  [642] = 4,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(89), 1,
      sym__ext_node_continue,
    ACTIONS(91), 1,
      sym__ext_node_begin,
    STATE(42), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_regular_node_repeat1,
  [657] = 6,
    ACTIONS(79), 1,
      sym__ext_nih_whitespace,
    ACTIONS(93), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(95), 1,
      sym__ext_eol,
    STATE(35), 1,
      aux_sym__string_single_repeat1,
    STATE(93), 1,
      aux_sym__eol_repeat1,
    STATE(158), 1,
      sym__eol,
  [676] = 4,
    ACTIONS(99), 1,
      sym__ext_nih_whitespace,
    STATE(73), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(97), 2,
      sym__ext_eol,
      aux_sym_inline_richtext_token1,
    STATE(34), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [691] = 6,
    ACTIONS(79), 1,
      sym__ext_nih_whitespace,
    ACTIONS(95), 1,
      sym__ext_eol,
    ACTIONS(102), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    STATE(43), 1,
      aux_sym__string_single_repeat1,
    STATE(93), 1,
      aux_sym__eol_repeat1,
    STATE(158), 1,
      sym__eol,
  [710] = 4,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(104), 1,
      sym__ext_node_continue,
    ACTIONS(106), 1,
      sym__ext_node_begin,
    STATE(42), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_regular_node_repeat1,
  [725] = 4,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(108), 1,
      sym__ext_node_continue,
    ACTIONS(110), 1,
      sym__ext_node_begin,
    STATE(42), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_regular_node_repeat1,
  [740] = 6,
    ACTIONS(77), 1,
      sym__ext_eol,
    ACTIONS(79), 1,
      sym__ext_nih_whitespace,
    ACTIONS(112), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    STATE(27), 1,
      aux_sym__string_double_repeat1,
    STATE(93), 1,
      aux_sym__eol_repeat1,
    STATE(168), 1,
      sym__eol,
  [759] = 4,
    ACTIONS(114), 1,
      sym__ext_empty_line,
    ACTIONS(117), 1,
      sym__ext_node_continue,
    ACTIONS(120), 1,
      sym__ext_node_begin,
    STATE(39), 3,
      sym_empty_line,
      sym_node_title_line,
      aux_sym_node_repeat1,
  [774] = 4,
    ACTIONS(85), 1,
      sym__ext_empty_line,
    ACTIONS(87), 1,
      sym__ext_node_continue,
    STATE(41), 1,
      sym_node_embed_declaration,
    STATE(49), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_embed_node_repeat1,
  [789] = 4,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(122), 1,
      sym__ext_node_continue,
    ACTIONS(124), 1,
      sym__ext_node_begin,
    STATE(32), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_regular_node_repeat1,
  [804] = 4,
    ACTIONS(126), 1,
      sym__ext_empty_line,
    ACTIONS(129), 1,
      sym__ext_node_continue,
    ACTIONS(132), 1,
      sym__ext_node_begin,
    STATE(42), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_regular_node_repeat1,
  [819] = 6,
    ACTIONS(134), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(136), 1,
      sym__ext_eol,
    ACTIONS(139), 1,
      sym__ext_nih_whitespace,
    STATE(43), 1,
      aux_sym__string_single_repeat1,
    STATE(93), 1,
      aux_sym__eol_repeat1,
    STATE(158), 1,
      sym__eol,
  [838] = 4,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(108), 1,
      sym__ext_node_continue,
    ACTIONS(110), 1,
      sym__ext_node_begin,
    STATE(36), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_regular_node_repeat1,
  [853] = 4,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(122), 1,
      sym__ext_node_continue,
    ACTIONS(124), 1,
      sym__ext_node_begin,
    STATE(42), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_regular_node_repeat1,
  [868] = 4,
    ACTIONS(142), 1,
      sym__ext_nih_whitespace,
    STATE(56), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(97), 2,
      sym__SYMBOL_SINGLE_QUOTE,
      sym__SYMBOL_DOUBLE_QUOTE,
    STATE(46), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [883] = 4,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(145), 1,
      sym__ext_node_continue,
    ACTIONS(147), 1,
      sym__ext_node_begin,
    STATE(37), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_regular_node_repeat1,
  [898] = 4,
    ACTIONS(9), 1,
      sym__ext_empty_line,
    ACTIONS(149), 1,
      sym__ext_node_continue,
    ACTIONS(151), 1,
      sym__ext_node_begin,
    STATE(45), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_regular_node_repeat1,
  [913] = 3,
    ACTIONS(153), 1,
      sym__ext_empty_line,
    ACTIONS(156), 1,
      sym__ext_node_continue,
    STATE(49), 3,
      sym_empty_line,
      sym_node_metadata_declaration,
      aux_sym__pending_embed_node_repeat1,
  [925] = 4,
    ACTIONS(49), 1,
      sym__ext_eol,
    ACTIONS(159), 1,
      sym__ext_nih_whitespace,
    STATE(96), 1,
      aux_sym__eol_repeat1,
    STATE(119), 1,
      sym__eol,
  [938] = 4,
    ACTIONS(161), 1,
      sym__ext_eol,
    ACTIONS(163), 1,
      sym__ext_nih_whitespace,
    STATE(92), 1,
      sym__eol,
    STATE(98), 1,
      aux_sym__eol_repeat1,
  [951] = 4,
    ACTIONS(165), 1,
      sym__ext_eol,
    ACTIONS(167), 1,
      sym__ext_nih_whitespace,
    STATE(86), 1,
      aux_sym__eol_repeat1,
    STATE(129), 1,
      sym__eol,
  [964] = 4,
    ACTIONS(167), 1,
      sym__ext_nih_whitespace,
    ACTIONS(169), 1,
      sym__ext_eol,
    STATE(86), 1,
      aux_sym__eol_repeat1,
    STATE(151), 1,
      sym__eol,
  [977] = 4,
    ACTIONS(55), 1,
      sym__ext_eol,
    ACTIONS(171), 1,
      sym__ext_nih_whitespace,
    STATE(109), 1,
      aux_sym__eol_repeat1,
    STATE(122), 1,
      sym__eol,
  [990] = 3,
    ACTIONS(175), 1,
      sym__ext_nih_whitespace,
    STATE(55), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(173), 2,
      sym__SYMBOL_SINGLE_QUOTE,
      sym__SYMBOL_DOUBLE_QUOTE,
  [1001] = 3,
    ACTIONS(180), 1,
      sym__ext_nih_whitespace,
    STATE(55), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(178), 2,
      sym__SYMBOL_SINGLE_QUOTE,
      sym__SYMBOL_DOUBLE_QUOTE,
  [1012] = 4,
    ACTIONS(171), 1,
      sym__ext_nih_whitespace,
    ACTIONS(182), 1,
      sym__ext_eol,
    STATE(101), 1,
      sym__eol,
    STATE(109), 1,
      aux_sym__eol_repeat1,
  [1025] = 4,
    ACTIONS(184), 1,
      sym__ext_eol,
    ACTIONS(186), 1,
      sym__ext_nih_whitespace,
    STATE(94), 1,
      aux_sym__eol_repeat1,
    STATE(155), 1,
      sym__eol,
  [1038] = 4,
    ACTIONS(188), 1,
      sym_metadata_key,
    ACTIONS(190), 1,
      sym__LITERAL_NODE_EMBED_DECLARATION,
    ACTIONS(192), 1,
      sym_SYMBOL_EMPTY_NODE,
    ACTIONS(194), 1,
      sym__ext_flag_node_def,
  [1051] = 4,
    ACTIONS(25), 1,
      sym__ext_eol,
    ACTIONS(171), 1,
      sym__ext_nih_whitespace,
    STATE(84), 1,
      sym__eol,
    STATE(109), 1,
      aux_sym__eol_repeat1,
  [1064] = 4,
    ACTIONS(188), 1,
      sym_metadata_key,
    ACTIONS(190), 1,
      sym__LITERAL_NODE_EMBED_DECLARATION,
    ACTIONS(194), 1,
      sym__ext_flag_node_def,
    ACTIONS(196), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1077] = 4,
    ACTIONS(51), 1,
      sym__ext_eol,
    ACTIONS(163), 1,
      sym__ext_nih_whitespace,
    STATE(98), 1,
      aux_sym__eol_repeat1,
    STATE(102), 1,
      sym__eol,
  [1090] = 4,
    ACTIONS(159), 1,
      sym__ext_nih_whitespace,
    ACTIONS(198), 1,
      sym__ext_eol,
    STATE(96), 1,
      aux_sym__eol_repeat1,
    STATE(115), 1,
      sym__eol,
  [1103] = 4,
    ACTIONS(171), 1,
      sym__ext_nih_whitespace,
    ACTIONS(200), 1,
      sym__ext_eol,
    STATE(80), 1,
      sym__eol,
    STATE(109), 1,
      aux_sym__eol_repeat1,
  [1116] = 3,
    ACTIONS(202), 1,
      sym__ext_nih_whitespace,
    STATE(65), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(173), 2,
      sym__ext_eol,
      aux_sym_inline_richtext_token1,
  [1127] = 4,
    ACTIONS(163), 1,
      sym__ext_nih_whitespace,
    ACTIONS(205), 1,
      sym__ext_eol,
    STATE(87), 1,
      sym__eol,
    STATE(98), 1,
      aux_sym__eol_repeat1,
  [1140] = 4,
    ACTIONS(159), 1,
      sym__ext_nih_whitespace,
    ACTIONS(207), 1,
      sym__ext_eol,
    STATE(96), 1,
      aux_sym__eol_repeat1,
    STATE(123), 1,
      sym__eol,
  [1153] = 4,
    ACTIONS(171), 1,
      sym__ext_nih_whitespace,
    ACTIONS(209), 1,
      sym__ext_eol,
    STATE(105), 1,
      sym__eol,
    STATE(109), 1,
      aux_sym__eol_repeat1,
  [1166] = 4,
    ACTIONS(163), 1,
      sym__ext_nih_whitespace,
    ACTIONS(211), 1,
      sym__ext_eol,
    STATE(98), 1,
      aux_sym__eol_repeat1,
    STATE(104), 1,
      sym__eol,
  [1179] = 4,
    ACTIONS(163), 1,
      sym__ext_nih_whitespace,
    ACTIONS(213), 1,
      sym__ext_eol,
    STATE(90), 1,
      sym__eol,
    STATE(98), 1,
      aux_sym__eol_repeat1,
  [1192] = 4,
    ACTIONS(163), 1,
      sym__ext_nih_whitespace,
    ACTIONS(215), 1,
      sym__ext_eol,
    STATE(98), 1,
      aux_sym__eol_repeat1,
    STATE(103), 1,
      sym__eol,
  [1205] = 4,
    ACTIONS(167), 1,
      sym__ext_nih_whitespace,
    ACTIONS(217), 1,
      sym__ext_eol,
    STATE(86), 1,
      aux_sym__eol_repeat1,
    STATE(140), 1,
      sym__eol,
  [1218] = 3,
    ACTIONS(219), 1,
      sym__ext_nih_whitespace,
    STATE(65), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(178), 2,
      sym__ext_eol,
      aux_sym_inline_richtext_token1,
  [1229] = 4,
    ACTIONS(23), 1,
      sym__ext_eol,
    ACTIONS(159), 1,
      sym__ext_nih_whitespace,
    STATE(96), 1,
      aux_sym__eol_repeat1,
    STATE(124), 1,
      sym__eol,
  [1242] = 4,
    ACTIONS(159), 1,
      sym__ext_nih_whitespace,
    ACTIONS(221), 1,
      sym__ext_eol,
    STATE(79), 1,
      sym__eol,
    STATE(96), 1,
      aux_sym__eol_repeat1,
  [1255] = 4,
    ACTIONS(171), 1,
      sym__ext_nih_whitespace,
    ACTIONS(223), 1,
      sym__ext_eol,
    STATE(95), 1,
      sym__eol,
    STATE(109), 1,
      aux_sym__eol_repeat1,
  [1268] = 4,
    ACTIONS(159), 1,
      sym__ext_nih_whitespace,
    ACTIONS(225), 1,
      sym__ext_eol,
    STATE(96), 1,
      aux_sym__eol_repeat1,
    STATE(125), 1,
      sym__eol,
  [1281] = 1,
    ACTIONS(227), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1287] = 1,
    ACTIONS(229), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1293] = 1,
    ACTIONS(231), 3,
      sym__eod_sentinel,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1299] = 3,
    ACTIONS(35), 1,
      aux_sym_inline_richtext_token1,
    ACTIONS(194), 1,
      sym__ext_flag_node_def,
    STATE(57), 1,
      sym_inline_richtext,
  [1309] = 3,
    ACTIONS(233), 1,
      sym__ext_node_continue,
    ACTIONS(236), 1,
      sym__ext_node_end,
    STATE(82), 1,
      aux_sym__pending_embed_node_repeat2,
  [1319] = 3,
    ACTIONS(223), 1,
      sym__ext_node_end,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(82), 1,
      aux_sym__pending_embed_node_repeat2,
  [1329] = 1,
    ACTIONS(240), 3,
      sym__eod_sentinel,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1335] = 1,
    ACTIONS(242), 3,
      sym__eod_sentinel,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1341] = 3,
    ACTIONS(244), 1,
      sym__ext_eol,
    ACTIONS(246), 1,
      sym__ext_nih_whitespace,
    STATE(106), 1,
      aux_sym__eol_repeat1,
  [1351] = 1,
    ACTIONS(248), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1357] = 1,
    ACTIONS(250), 3,
      sym__eod_sentinel,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1363] = 2,
    ACTIONS(255), 1,
      sym__ext_node_begin,
    ACTIONS(252), 2,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1371] = 1,
    ACTIONS(257), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1377] = 3,
    ACTIONS(35), 1,
      aux_sym_inline_richtext_token1,
    ACTIONS(194), 1,
      sym__ext_flag_node_def,
    STATE(63), 1,
      sym_inline_richtext,
  [1387] = 1,
    ACTIONS(259), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1393] = 3,
    ACTIONS(246), 1,
      sym__ext_nih_whitespace,
    ACTIONS(261), 1,
      sym__ext_eol,
    STATE(106), 1,
      aux_sym__eol_repeat1,
  [1403] = 3,
    ACTIONS(246), 1,
      sym__ext_nih_whitespace,
    ACTIONS(263), 1,
      sym__ext_eol,
    STATE(106), 1,
      aux_sym__eol_repeat1,
  [1413] = 1,
    ACTIONS(229), 3,
      sym__eod_sentinel,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1419] = 3,
    ACTIONS(246), 1,
      sym__ext_nih_whitespace,
    ACTIONS(265), 1,
      sym__ext_eol,
    STATE(106), 1,
      aux_sym__eol_repeat1,
  [1429] = 3,
    ACTIONS(209), 1,
      sym__ext_node_end,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(82), 1,
      aux_sym__pending_embed_node_repeat2,
  [1439] = 3,
    ACTIONS(246), 1,
      sym__ext_nih_whitespace,
    ACTIONS(267), 1,
      sym__ext_eol,
    STATE(106), 1,
      aux_sym__eol_repeat1,
  [1449] = 3,
    ACTIONS(225), 1,
      sym__ext_node_end,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(82), 1,
      aux_sym__pending_embed_node_repeat2,
  [1459] = 3,
    ACTIONS(221), 1,
      sym__ext_node_end,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(82), 1,
      aux_sym__pending_embed_node_repeat2,
  [1469] = 1,
    ACTIONS(269), 3,
      sym__eod_sentinel,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1475] = 1,
    ACTIONS(271), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1481] = 1,
    ACTIONS(273), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1487] = 1,
    ACTIONS(275), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1493] = 1,
    ACTIONS(277), 3,
      sym__eod_sentinel,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1499] = 3,
    ACTIONS(279), 1,
      sym__ext_eol,
    ACTIONS(281), 1,
      sym__ext_nih_whitespace,
    STATE(106), 1,
      aux_sym__eol_repeat1,
  [1509] = 3,
    ACTIONS(207), 1,
      sym__ext_node_end,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(82), 1,
      aux_sym__pending_embed_node_repeat2,
  [1519] = 1,
    ACTIONS(284), 3,
      sym__eod_sentinel,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1525] = 3,
    ACTIONS(246), 1,
      sym__ext_nih_whitespace,
    ACTIONS(286), 1,
      sym__ext_eol,
    STATE(106), 1,
      aux_sym__eol_repeat1,
  [1535] = 1,
    ACTIONS(288), 3,
      sym__ext_eol,
      sym__ext_nih_whitespace,
      sym__SYMBOL_SINGLE_QUOTE,
  [1541] = 1,
    ACTIONS(290), 3,
      sym__ext_eol,
      sym__ext_nih_whitespace,
      sym__SYMBOL_DOUBLE_QUOTE,
  [1547] = 1,
    ACTIONS(242), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1553] = 1,
    ACTIONS(250), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1559] = 2,
    ACTIONS(292), 1,
      aux_sym_inline_richtext_token1,
    ACTIONS(294), 2,
      sym__ext_eol,
      sym__ext_nih_whitespace,
  [1567] = 1,
    ACTIONS(269), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1573] = 1,
    ACTIONS(227), 3,
      sym__eod_sentinel,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1579] = 1,
    ACTIONS(284), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1585] = 1,
    ACTIONS(227), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1591] = 1,
    ACTIONS(296), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1597] = 3,
    ACTIONS(200), 1,
      sym__ext_node_end,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(82), 1,
      aux_sym__pending_embed_node_repeat2,
  [1607] = 1,
    ACTIONS(242), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1613] = 1,
    ACTIONS(296), 3,
      sym__eod_sentinel,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1619] = 1,
    ACTIONS(231), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1625] = 1,
    ACTIONS(240), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1631] = 1,
    ACTIONS(277), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1637] = 1,
    ACTIONS(298), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1643] = 2,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(107), 1,
      aux_sym__pending_embed_node_repeat2,
  [1650] = 1,
    ACTIONS(300), 2,
      sym__ext_eol,
      sym__ext_nih_whitespace,
  [1655] = 1,
    ACTIONS(257), 2,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1660] = 2,
    ACTIONS(302), 1,
      aux_sym_inline_richtext_token1,
    STATE(58), 1,
      sym_inline_embedding,
  [1667] = 2,
    ACTIONS(304), 1,
      sym_metadata_key,
    ACTIONS(306), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1674] = 1,
    ACTIONS(242), 2,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1679] = 2,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(83), 1,
      aux_sym__pending_embed_node_repeat2,
  [1686] = 1,
    ACTIONS(227), 2,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1691] = 1,
    ACTIONS(308), 2,
      sym__ext_eol,
      sym__ext_nih_whitespace,
  [1696] = 2,
    ACTIONS(304), 1,
      sym_metadata_key,
    ACTIONS(310), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1703] = 2,
    ACTIONS(190), 1,
      sym__LITERAL_NODE_EMBED_DECLARATION,
    ACTIONS(312), 1,
      sym_metadata_key,
  [1710] = 2,
    ACTIONS(304), 1,
      sym_metadata_key,
    ACTIONS(314), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1717] = 1,
    ACTIONS(316), 2,
      sym__ext_eol,
      sym__ext_nih_whitespace,
  [1722] = 1,
    ACTIONS(318), 2,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1727] = 2,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(120), 1,
      aux_sym__pending_embed_node_repeat2,
  [1734] = 2,
    ACTIONS(304), 1,
      sym_metadata_key,
    ACTIONS(320), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1741] = 2,
    ACTIONS(322), 1,
      sym_STRING1,
    STATE(161), 1,
      sym__string_single,
  [1748] = 2,
    ACTIONS(304), 1,
      sym_metadata_key,
    ACTIONS(324), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1755] = 2,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(100), 1,
      aux_sym__pending_embed_node_repeat2,
  [1762] = 2,
    ACTIONS(304), 1,
      sym_metadata_key,
    ACTIONS(326), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1769] = 2,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(97), 1,
      aux_sym__pending_embed_node_repeat2,
  [1776] = 1,
    ACTIONS(227), 2,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1781] = 2,
    ACTIONS(304), 1,
      sym_metadata_key,
    ACTIONS(328), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1788] = 1,
    ACTIONS(330), 2,
      sym__ext_eol,
      sym__ext_nih_whitespace,
  [1793] = 1,
    ACTIONS(273), 2,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1798] = 2,
    ACTIONS(238), 1,
      sym__ext_node_continue,
    STATE(99), 1,
      aux_sym__pending_embed_node_repeat2,
  [1805] = 2,
    ACTIONS(304), 1,
      sym_metadata_key,
    ACTIONS(332), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1812] = 1,
    ACTIONS(334), 2,
      sym__ext_eol,
      sym__ext_nih_whitespace,
  [1817] = 1,
    ACTIONS(336), 2,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1822] = 2,
    ACTIONS(338), 1,
      sym_STRING2,
    STATE(160), 1,
      sym__string_double,
  [1829] = 1,
    ACTIONS(340), 1,
      ts_builtin_sym_end,
  [1833] = 1,
    ACTIONS(342), 1,
      sym__ext_node_continue,
  [1837] = 1,
    ACTIONS(344), 1,
      sym__ext_eol,
  [1841] = 1,
    ACTIONS(346), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
  [1845] = 1,
    ACTIONS(346), 1,
      sym__SYMBOL_SINGLE_QUOTE,
  [1849] = 1,
    ACTIONS(348), 1,
      sym__ext_eol,
  [1853] = 1,
    ACTIONS(350), 1,
      sym__SYMBOL_METADATA_ASSIGNMENT,
  [1857] = 1,
    ACTIONS(352), 1,
      ts_builtin_sym_end,
  [1861] = 1,
    ACTIONS(304), 1,
      sym_metadata_key,
  [1865] = 1,
    ACTIONS(354), 1,
      sym__ext_eol,
  [1869] = 1,
    ACTIONS(356), 1,
      sym_STRING1,
  [1873] = 1,
    ACTIONS(358), 1,
      sym__ext_node_continue,
  [1877] = 1,
    ACTIONS(360), 1,
      sym_metadata_key,
  [1881] = 1,
    ACTIONS(362), 1,
      sym__SYMBOL_METADATA_ASSIGNMENT,
  [1885] = 1,
    ACTIONS(364), 1,
      sym__SYMBOL_METADATA_ASSIGNMENT,
  [1889] = 1,
    ACTIONS(366), 1,
      sym_STRING2,
  [1893] = 1,
    ACTIONS(194), 1,
      sym__ext_flag_node_def,
  [1897] = 1,
    ACTIONS(368), 1,
      sym__SYMBOL_NODE_DEF,
  [1901] = 1,
    ACTIONS(370), 1,
      sym__ext_eol,
  [1905] = 1,
    ACTIONS(372), 1,
      ts_builtin_sym_end,
  [1909] = 1,
    ACTIONS(227), 1,
      sym__ext_node_continue,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 31,
  [SMALL_STATE(4)] = 62,
  [SMALL_STATE(5)] = 93,
  [SMALL_STATE(6)] = 124,
  [SMALL_STATE(7)] = 144,
  [SMALL_STATE(8)] = 164,
  [SMALL_STATE(9)] = 184,
  [SMALL_STATE(10)] = 210,
  [SMALL_STATE(11)] = 230,
  [SMALL_STATE(12)] = 250,
  [SMALL_STATE(13)] = 270,
  [SMALL_STATE(14)] = 296,
  [SMALL_STATE(15)] = 316,
  [SMALL_STATE(16)] = 336,
  [SMALL_STATE(17)] = 359,
  [SMALL_STATE(18)] = 376,
  [SMALL_STATE(19)] = 399,
  [SMALL_STATE(20)] = 416,
  [SMALL_STATE(21)] = 433,
  [SMALL_STATE(22)] = 456,
  [SMALL_STATE(23)] = 479,
  [SMALL_STATE(24)] = 496,
  [SMALL_STATE(25)] = 519,
  [SMALL_STATE(26)] = 542,
  [SMALL_STATE(27)] = 559,
  [SMALL_STATE(28)] = 578,
  [SMALL_STATE(29)] = 593,
  [SMALL_STATE(30)] = 612,
  [SMALL_STATE(31)] = 627,
  [SMALL_STATE(32)] = 642,
  [SMALL_STATE(33)] = 657,
  [SMALL_STATE(34)] = 676,
  [SMALL_STATE(35)] = 691,
  [SMALL_STATE(36)] = 710,
  [SMALL_STATE(37)] = 725,
  [SMALL_STATE(38)] = 740,
  [SMALL_STATE(39)] = 759,
  [SMALL_STATE(40)] = 774,
  [SMALL_STATE(41)] = 789,
  [SMALL_STATE(42)] = 804,
  [SMALL_STATE(43)] = 819,
  [SMALL_STATE(44)] = 838,
  [SMALL_STATE(45)] = 853,
  [SMALL_STATE(46)] = 868,
  [SMALL_STATE(47)] = 883,
  [SMALL_STATE(48)] = 898,
  [SMALL_STATE(49)] = 913,
  [SMALL_STATE(50)] = 925,
  [SMALL_STATE(51)] = 938,
  [SMALL_STATE(52)] = 951,
  [SMALL_STATE(53)] = 964,
  [SMALL_STATE(54)] = 977,
  [SMALL_STATE(55)] = 990,
  [SMALL_STATE(56)] = 1001,
  [SMALL_STATE(57)] = 1012,
  [SMALL_STATE(58)] = 1025,
  [SMALL_STATE(59)] = 1038,
  [SMALL_STATE(60)] = 1051,
  [SMALL_STATE(61)] = 1064,
  [SMALL_STATE(62)] = 1077,
  [SMALL_STATE(63)] = 1090,
  [SMALL_STATE(64)] = 1103,
  [SMALL_STATE(65)] = 1116,
  [SMALL_STATE(66)] = 1127,
  [SMALL_STATE(67)] = 1140,
  [SMALL_STATE(68)] = 1153,
  [SMALL_STATE(69)] = 1166,
  [SMALL_STATE(70)] = 1179,
  [SMALL_STATE(71)] = 1192,
  [SMALL_STATE(72)] = 1205,
  [SMALL_STATE(73)] = 1218,
  [SMALL_STATE(74)] = 1229,
  [SMALL_STATE(75)] = 1242,
  [SMALL_STATE(76)] = 1255,
  [SMALL_STATE(77)] = 1268,
  [SMALL_STATE(78)] = 1281,
  [SMALL_STATE(79)] = 1287,
  [SMALL_STATE(80)] = 1293,
  [SMALL_STATE(81)] = 1299,
  [SMALL_STATE(82)] = 1309,
  [SMALL_STATE(83)] = 1319,
  [SMALL_STATE(84)] = 1329,
  [SMALL_STATE(85)] = 1335,
  [SMALL_STATE(86)] = 1341,
  [SMALL_STATE(87)] = 1351,
  [SMALL_STATE(88)] = 1357,
  [SMALL_STATE(89)] = 1363,
  [SMALL_STATE(90)] = 1371,
  [SMALL_STATE(91)] = 1377,
  [SMALL_STATE(92)] = 1387,
  [SMALL_STATE(93)] = 1393,
  [SMALL_STATE(94)] = 1403,
  [SMALL_STATE(95)] = 1413,
  [SMALL_STATE(96)] = 1419,
  [SMALL_STATE(97)] = 1429,
  [SMALL_STATE(98)] = 1439,
  [SMALL_STATE(99)] = 1449,
  [SMALL_STATE(100)] = 1459,
  [SMALL_STATE(101)] = 1469,
  [SMALL_STATE(102)] = 1475,
  [SMALL_STATE(103)] = 1481,
  [SMALL_STATE(104)] = 1487,
  [SMALL_STATE(105)] = 1493,
  [SMALL_STATE(106)] = 1499,
  [SMALL_STATE(107)] = 1509,
  [SMALL_STATE(108)] = 1519,
  [SMALL_STATE(109)] = 1525,
  [SMALL_STATE(110)] = 1535,
  [SMALL_STATE(111)] = 1541,
  [SMALL_STATE(112)] = 1547,
  [SMALL_STATE(113)] = 1553,
  [SMALL_STATE(114)] = 1559,
  [SMALL_STATE(115)] = 1567,
  [SMALL_STATE(116)] = 1573,
  [SMALL_STATE(117)] = 1579,
  [SMALL_STATE(118)] = 1585,
  [SMALL_STATE(119)] = 1591,
  [SMALL_STATE(120)] = 1597,
  [SMALL_STATE(121)] = 1607,
  [SMALL_STATE(122)] = 1613,
  [SMALL_STATE(123)] = 1619,
  [SMALL_STATE(124)] = 1625,
  [SMALL_STATE(125)] = 1631,
  [SMALL_STATE(126)] = 1637,
  [SMALL_STATE(127)] = 1643,
  [SMALL_STATE(128)] = 1650,
  [SMALL_STATE(129)] = 1655,
  [SMALL_STATE(130)] = 1660,
  [SMALL_STATE(131)] = 1667,
  [SMALL_STATE(132)] = 1674,
  [SMALL_STATE(133)] = 1679,
  [SMALL_STATE(134)] = 1686,
  [SMALL_STATE(135)] = 1691,
  [SMALL_STATE(136)] = 1696,
  [SMALL_STATE(137)] = 1703,
  [SMALL_STATE(138)] = 1710,
  [SMALL_STATE(139)] = 1717,
  [SMALL_STATE(140)] = 1722,
  [SMALL_STATE(141)] = 1727,
  [SMALL_STATE(142)] = 1734,
  [SMALL_STATE(143)] = 1741,
  [SMALL_STATE(144)] = 1748,
  [SMALL_STATE(145)] = 1755,
  [SMALL_STATE(146)] = 1762,
  [SMALL_STATE(147)] = 1769,
  [SMALL_STATE(148)] = 1776,
  [SMALL_STATE(149)] = 1781,
  [SMALL_STATE(150)] = 1788,
  [SMALL_STATE(151)] = 1793,
  [SMALL_STATE(152)] = 1798,
  [SMALL_STATE(153)] = 1805,
  [SMALL_STATE(154)] = 1812,
  [SMALL_STATE(155)] = 1817,
  [SMALL_STATE(156)] = 1822,
  [SMALL_STATE(157)] = 1829,
  [SMALL_STATE(158)] = 1833,
  [SMALL_STATE(159)] = 1837,
  [SMALL_STATE(160)] = 1841,
  [SMALL_STATE(161)] = 1845,
  [SMALL_STATE(162)] = 1849,
  [SMALL_STATE(163)] = 1853,
  [SMALL_STATE(164)] = 1857,
  [SMALL_STATE(165)] = 1861,
  [SMALL_STATE(166)] = 1865,
  [SMALL_STATE(167)] = 1869,
  [SMALL_STATE(168)] = 1873,
  [SMALL_STATE(169)] = 1877,
  [SMALL_STATE(170)] = 1881,
  [SMALL_STATE(171)] = 1885,
  [SMALL_STATE(172)] = 1889,
  [SMALL_STATE(173)] = 1893,
  [SMALL_STATE(174)] = 1897,
  [SMALL_STATE(175)] = 1901,
  [SMALL_STATE(176)] = 1905,
  [SMALL_STATE(177)] = 1909,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [27] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(162),
  [30] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(159),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__string_double_repeat1, 2, 0, 0),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__string_double_repeat1, 2, 0, 0), SHIFT_REPEAT(168),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__string_double_repeat1, 2, 0, 0), SHIFT_REPEAT(93),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__string_double, 1, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__string_single, 1, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_node_title_line_repeat1, 2, 0, 0),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_node_title_line_repeat1, 2, 0, 0), SHIFT_REPEAT(73),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__string_single, 2, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__string_double, 2, 0, 0),
  [114] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_node_repeat1, 2, 0, 0), SHIFT_REPEAT(175),
  [117] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_node_repeat1, 2, 0, 0), SHIFT_REPEAT(173),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_node_repeat1, 2, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [126] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__pending_regular_node_repeat1, 2, 0, 0), SHIFT_REPEAT(175),
  [129] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__pending_regular_node_repeat1, 2, 0, 0), SHIFT_REPEAT(165),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__pending_regular_node_repeat1, 2, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__string_single_repeat1, 2, 0, 0),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__string_single_repeat1, 2, 0, 0), SHIFT_REPEAT(158),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__string_single_repeat1, 2, 0, 0), SHIFT_REPEAT(93),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_node_title_line_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [153] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__pending_embed_node_repeat1, 2, 0, 0), SHIFT_REPEAT(166),
  [156] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__pending_embed_node_repeat1, 2, 0, 0), SHIFT_REPEAT(169),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_nih_whitespace_repeat1, 2, 0, 0),
  [175] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_nih_whitespace_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nih_whitespace, 1, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [188] = {.entry = {.count = 1, .reusable = false}}, SHIFT(170),
  [190] = {.entry = {.count = 1, .reusable = false}}, SHIFT(171),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [202] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_nih_whitespace_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__eol, 2, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__pending_embed_node, 5, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__pending_embed_node, 4, 0, 0),
  [233] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__pending_embed_node_repeat2, 2, 0, 0), SHIFT_REPEAT(130),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__pending_embed_node_repeat2, 2, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__pending_regular_node, 4, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_empty_line, 2, 0, 0),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_title_line, 6, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2, 0, 0),
  [252] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__pending_regular_node_repeat1, 1, 0, 0), REDUCE(aux_sym__pending_embed_node_repeat1, 1, 0, 0),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__pending_regular_node_repeat1, 1, 0, 0),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_metadata_declaration, 5, 0, 0),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_embed_declaration, 5, 0, 0),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_content_line, 3, 0, 0),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_title_line, 5, 0, 0),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_metadata_declaration, 6, 0, 0),
  [275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_embed_declaration, 6, 0, 0),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__pending_embed_node, 6, 0, 0),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__eol_repeat1, 2, 0, 0),
  [281] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__eol_repeat1, 2, 0, 0), SHIFT_REPEAT(106),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3, 0, 0),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__string_single_repeat1, 3, 0, 0),
  [290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__string_double_repeat1, 3, 0, 0),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_nih_whitespace_repeat1, 1, 0, 0),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__eol_repeat1, 1, 0, 0),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__pending_regular_node, 3, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_title_line, 4, 0, 0),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_embed_type, 1, 0, 0),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_embedding, 1, 0, 0),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [312] = {.entry = {.count = 1, .reusable = false}}, SHIFT(163),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_richtext, 1, 0, 0),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_version_comment, 2, 0, 0),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__string, 3, 0, 0),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [334] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_metadata_value, 1, 0, 0),
  [336] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__pending_embed_node_repeat2, 3, 0, 0),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 3, 0, 0),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [352] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 2, 0, 0),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [372] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__error_sentinel = 0,
  ts_external_token__eod_sentinel = 1,
  ts_external_token__ext_eol = 2,
  ts_external_token__ext_empty_line = 3,
  ts_external_token__ext_nih_whitespace = 4,
  ts_external_token__ext_node_continue = 5,
  ts_external_token__ext_flag_node_def = 6,
  ts_external_token__ext_node_begin = 7,
  ts_external_token__ext_node_end = 8,
  ts_external_token_autoclose_warning = 9,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__error_sentinel] = sym__error_sentinel,
  [ts_external_token__eod_sentinel] = sym__eod_sentinel,
  [ts_external_token__ext_eol] = sym__ext_eol,
  [ts_external_token__ext_empty_line] = sym__ext_empty_line,
  [ts_external_token__ext_nih_whitespace] = sym__ext_nih_whitespace,
  [ts_external_token__ext_node_continue] = sym__ext_node_continue,
  [ts_external_token__ext_flag_node_def] = sym__ext_flag_node_def,
  [ts_external_token__ext_node_begin] = sym__ext_node_begin,
  [ts_external_token__ext_node_end] = sym__ext_node_end,
  [ts_external_token_autoclose_warning] = sym_autoclose_warning,
};

static const bool ts_external_scanner_states[12][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__error_sentinel] = true,
    [ts_external_token__eod_sentinel] = true,
    [ts_external_token__ext_eol] = true,
    [ts_external_token__ext_empty_line] = true,
    [ts_external_token__ext_nih_whitespace] = true,
    [ts_external_token__ext_node_continue] = true,
    [ts_external_token__ext_flag_node_def] = true,
    [ts_external_token__ext_node_begin] = true,
    [ts_external_token__ext_node_end] = true,
    [ts_external_token_autoclose_warning] = true,
  },
  [2] = {
    [ts_external_token__ext_empty_line] = true,
    [ts_external_token__ext_node_continue] = true,
  },
  [3] = {
    [ts_external_token__ext_empty_line] = true,
    [ts_external_token__ext_node_continue] = true,
    [ts_external_token__ext_node_begin] = true,
  },
  [4] = {
    [ts_external_token__ext_empty_line] = true,
    [ts_external_token__ext_node_continue] = true,
    [ts_external_token__ext_node_end] = true,
  },
  [5] = {
    [ts_external_token__ext_eol] = true,
    [ts_external_token__ext_nih_whitespace] = true,
  },
  [6] = {
    [ts_external_token__eod_sentinel] = true,
    [ts_external_token__ext_empty_line] = true,
    [ts_external_token__ext_node_continue] = true,
  },
  [7] = {
    [ts_external_token__ext_nih_whitespace] = true,
  },
  [8] = {
    [ts_external_token__ext_flag_node_def] = true,
  },
  [9] = {
    [ts_external_token__ext_node_continue] = true,
    [ts_external_token__ext_node_end] = true,
  },
  [10] = {
    [ts_external_token__ext_node_continue] = true,
  },
  [11] = {
    [ts_external_token__ext_eol] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_cleancopy_external_scanner_create(void);
void tree_sitter_cleancopy_external_scanner_destroy(void *);
bool tree_sitter_cleancopy_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_cleancopy_external_scanner_serialize(void *, char *);
void tree_sitter_cleancopy_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_cleancopy(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_cleancopy_external_scanner_create,
      tree_sitter_cleancopy_external_scanner_destroy,
      tree_sitter_cleancopy_external_scanner_scan,
      tree_sitter_cleancopy_external_scanner_serialize,
      tree_sitter_cleancopy_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
