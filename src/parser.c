#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 147
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 55
#define ALIAS_COUNT 0
#define TOKEN_COUNT 25
#define EXTERNAL_TOKEN_COUNT 13
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 7

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
  sym__node_metadata_sentinel = 13,
  sym__empty_node_sentinel = 14,
  sym__ext_flag_embed = 15,
  sym__ext_flag_node_def = 16,
  sym__ext_eol = 17,
  sym__ext_empty_line = 18,
  sym__ext_nih_whitespace = 19,
  sym__ext_node_continue = 20,
  sym__ext_node_begin = 21,
  sym__ext_node_end = 22,
  sym__ext_eof = 23,
  sym_autoclose_warning = 24,
  sym_document = 25,
  sym__eol = 26,
  sym_nih_whitespace = 27,
  sym_empty_line = 28,
  sym_version_comment = 29,
  sym__node_segments = 30,
  sym__embedding_segments = 31,
  sym_node = 32,
  sym_node_title = 33,
  sym_node_metadata = 34,
  sym_node_title_line = 35,
  sym_node_metadata_declaration_line = 36,
  sym_content_line = 37,
  sym_embedding_line = 38,
  sym_inline_richtext = 39,
  sym_inline_embedding = 40,
  sym_metadata_value = 41,
  sym__string = 42,
  sym__string_single = 43,
  sym__string_double = 44,
  aux_sym_document_repeat1 = 45,
  aux_sym__eol_repeat1 = 46,
  aux_sym_nih_whitespace_repeat1 = 47,
  aux_sym__node_segments_repeat1 = 48,
  aux_sym__embedding_segments_repeat1 = 49,
  aux_sym_node_title_repeat1 = 50,
  aux_sym_node_metadata_repeat1 = 51,
  aux_sym_node_title_line_repeat1 = 52,
  aux_sym__string_single_repeat1 = 53,
  aux_sym__string_double_repeat1 = 54,
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
  [sym__node_metadata_sentinel] = "_node_metadata_sentinel",
  [sym__empty_node_sentinel] = "_empty_node_sentinel",
  [sym__ext_flag_embed] = "_ext_flag_embed",
  [sym__ext_flag_node_def] = "_ext_flag_node_def",
  [sym__ext_eol] = "_ext_eol",
  [sym__ext_empty_line] = "_ext_empty_line",
  [sym__ext_nih_whitespace] = "_ext_nih_whitespace",
  [sym__ext_node_continue] = "_ext_node_continue",
  [sym__ext_node_begin] = "_ext_node_begin",
  [sym__ext_node_end] = "_ext_node_end",
  [sym__ext_eof] = "_ext_eof",
  [sym_autoclose_warning] = "autoclose_warning",
  [sym_document] = "document",
  [sym__eol] = "_eol",
  [sym_nih_whitespace] = "nih_whitespace",
  [sym_empty_line] = "empty_line",
  [sym_version_comment] = "version_comment",
  [sym__node_segments] = "_node_segments",
  [sym__embedding_segments] = "_embedding_segments",
  [sym_node] = "node",
  [sym_node_title] = "node_title",
  [sym_node_metadata] = "node_metadata",
  [sym_node_title_line] = "node_title_line",
  [sym_node_metadata_declaration_line] = "node_metadata_declaration_line",
  [sym_content_line] = "content_line",
  [sym_embedding_line] = "embedding_line",
  [sym_inline_richtext] = "inline_richtext",
  [sym_inline_embedding] = "inline_embedding",
  [sym_metadata_value] = "metadata_value",
  [sym__string] = "_string",
  [sym__string_single] = "_string_single",
  [sym__string_double] = "_string_double",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym__eol_repeat1] = "_eol_repeat1",
  [aux_sym_nih_whitespace_repeat1] = "nih_whitespace_repeat1",
  [aux_sym__node_segments_repeat1] = "_node_segments_repeat1",
  [aux_sym__embedding_segments_repeat1] = "_embedding_segments_repeat1",
  [aux_sym_node_title_repeat1] = "node_title_repeat1",
  [aux_sym_node_metadata_repeat1] = "node_metadata_repeat1",
  [aux_sym_node_title_line_repeat1] = "node_title_line_repeat1",
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
  [sym__node_metadata_sentinel] = sym__node_metadata_sentinel,
  [sym__empty_node_sentinel] = sym__empty_node_sentinel,
  [sym__ext_flag_embed] = sym__ext_flag_embed,
  [sym__ext_flag_node_def] = sym__ext_flag_node_def,
  [sym__ext_eol] = sym__ext_eol,
  [sym__ext_empty_line] = sym__ext_empty_line,
  [sym__ext_nih_whitespace] = sym__ext_nih_whitespace,
  [sym__ext_node_continue] = sym__ext_node_continue,
  [sym__ext_node_begin] = sym__ext_node_begin,
  [sym__ext_node_end] = sym__ext_node_end,
  [sym__ext_eof] = sym__ext_eof,
  [sym_autoclose_warning] = sym_autoclose_warning,
  [sym_document] = sym_document,
  [sym__eol] = sym__eol,
  [sym_nih_whitespace] = sym_nih_whitespace,
  [sym_empty_line] = sym_empty_line,
  [sym_version_comment] = sym_version_comment,
  [sym__node_segments] = sym__node_segments,
  [sym__embedding_segments] = sym__embedding_segments,
  [sym_node] = sym_node,
  [sym_node_title] = sym_node_title,
  [sym_node_metadata] = sym_node_metadata,
  [sym_node_title_line] = sym_node_title_line,
  [sym_node_metadata_declaration_line] = sym_node_metadata_declaration_line,
  [sym_content_line] = sym_content_line,
  [sym_embedding_line] = sym_embedding_line,
  [sym_inline_richtext] = sym_inline_richtext,
  [sym_inline_embedding] = sym_inline_embedding,
  [sym_metadata_value] = sym_metadata_value,
  [sym__string] = sym__string,
  [sym__string_single] = sym__string_single,
  [sym__string_double] = sym__string_double,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym__eol_repeat1] = aux_sym__eol_repeat1,
  [aux_sym_nih_whitespace_repeat1] = aux_sym_nih_whitespace_repeat1,
  [aux_sym__node_segments_repeat1] = aux_sym__node_segments_repeat1,
  [aux_sym__embedding_segments_repeat1] = aux_sym__embedding_segments_repeat1,
  [aux_sym_node_title_repeat1] = aux_sym_node_title_repeat1,
  [aux_sym_node_metadata_repeat1] = aux_sym_node_metadata_repeat1,
  [aux_sym_node_title_line_repeat1] = aux_sym_node_title_line_repeat1,
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
  [sym__node_metadata_sentinel] = {
    .visible = false,
    .named = true,
  },
  [sym__empty_node_sentinel] = {
    .visible = false,
    .named = true,
  },
  [sym__ext_flag_embed] = {
    .visible = false,
    .named = true,
  },
  [sym__ext_flag_node_def] = {
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
  [sym__ext_node_begin] = {
    .visible = false,
    .named = true,
  },
  [sym__ext_node_end] = {
    .visible = false,
    .named = true,
  },
  [sym__ext_eof] = {
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
  [sym__node_segments] = {
    .visible = false,
    .named = true,
  },
  [sym__embedding_segments] = {
    .visible = false,
    .named = true,
  },
  [sym_node] = {
    .visible = true,
    .named = true,
  },
  [sym_node_title] = {
    .visible = true,
    .named = true,
  },
  [sym_node_metadata] = {
    .visible = true,
    .named = true,
  },
  [sym_node_title_line] = {
    .visible = true,
    .named = true,
  },
  [sym_node_metadata_declaration_line] = {
    .visible = true,
    .named = true,
  },
  [sym_content_line] = {
    .visible = true,
    .named = true,
  },
  [sym_embedding_line] = {
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
  [aux_sym__node_segments_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__embedding_segments_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_node_title_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_node_metadata_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_node_title_line_repeat1] = {
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

enum ts_field_identifiers {
  field_content = 1,
  field_embed = 2,
  field_metadata = 3,
  field_title = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_content] = "content",
  [field_embed] = "embed",
  [field_metadata] = "metadata",
  [field_title] = "title",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 1},
  [3] = {.index = 3, .length = 3},
  [4] = {.index = 6, .length = 3},
  [5] = {.index = 9, .length = 2},
  [6] = {.index = 11, .length = 4},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_content, 2},
    {field_title, 0},
  [2] =
    {field_title, 0},
  [3] =
    {field_embed, 2},
    {field_embed, 3},
    {field_title, 0},
  [6] =
    {field_content, 3},
    {field_metadata, 1},
    {field_title, 0},
  [9] =
    {field_metadata, 1},
    {field_title, 0},
  [11] =
    {field_embed, 3},
    {field_embed, 4},
    {field_metadata, 1},
    {field_title, 0},
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
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 9,
  [11] = 5,
  [12] = 7,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 15,
  [18] = 16,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 19,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 40,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 42,
  [46] = 46,
  [47] = 47,
  [48] = 44,
  [49] = 49,
  [50] = 36,
  [51] = 51,
  [52] = 37,
  [53] = 46,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 57,
  [63] = 63,
  [64] = 64,
  [65] = 63,
  [66] = 60,
  [67] = 63,
  [68] = 68,
  [69] = 69,
  [70] = 63,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 72,
  [76] = 73,
  [77] = 77,
  [78] = 78,
  [79] = 61,
  [80] = 80,
  [81] = 55,
  [82] = 78,
  [83] = 77,
  [84] = 71,
  [85] = 69,
  [86] = 63,
  [87] = 64,
  [88] = 88,
  [89] = 72,
  [90] = 56,
  [91] = 91,
  [92] = 73,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 72,
  [102] = 98,
  [103] = 103,
  [104] = 99,
  [105] = 105,
  [106] = 73,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 72,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 120,
  [123] = 123,
  [124] = 124,
  [125] = 119,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 124,
  [131] = 120,
  [132] = 132,
  [133] = 120,
  [134] = 128,
  [135] = 135,
  [136] = 127,
  [137] = 137,
  [138] = 117,
  [139] = 139,
  [140] = 140,
  [141] = 135,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 118,
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
      if (eof) ADVANCE(20);
      if (lookahead == '\r') SKIP(0);
      if (lookahead == '"') ADVANCE(42);
      if (lookahead == '\'') ADVANCE(41);
      if (lookahead == ':') ADVANCE(38);
      if (lookahead == '<') ADVANCE(40);
      if (lookahead == '>') ADVANCE(37);
      if (lookahead == '_') ADVANCE(28);
      if (lookahead == 'e') ADVANCE(26);
      if (set_contains(sym_metadata_key_character_set_1, 431, lookahead)) ADVANCE(27);
      END_STATE();
    case 1:
      if (lookahead == '\r') SKIP(1);
      if (lookahead == '<') ADVANCE(6);
      if (lookahead == '_') ADVANCE(28);
      if (set_contains(sym_metadata_key_character_set_1, 431, lookahead)) ADVANCE(27);
      END_STATE();
    case 2:
      if (lookahead == '\r') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(22);
      END_STATE();
    case 3:
      if (lookahead == '\r') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(31);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(30);
      END_STATE();
    case 4:
      if (lookahead == '\r') ADVANCE(32);
      if (lookahead == '\\') ADVANCE(34);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(33);
      END_STATE();
    case 5:
      if (lookahead == '\r') SKIP(5);
      if (lookahead == '<') ADVANCE(39);
      END_STATE();
    case 6:
      if (lookahead == '<') ADVANCE(7);
      END_STATE();
    case 7:
      if (lookahead == '<') ADVANCE(12);
      END_STATE();
    case 8:
      if (lookahead == '>') ADVANCE(35);
      END_STATE();
    case 9:
      if (lookahead == '>') ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == '>') ADVANCE(9);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(16);
      END_STATE();
    case 12:
      if (lookahead == 'c') ADVANCE(15);
      END_STATE();
    case 13:
      if (lookahead == 'c') ADVANCE(17);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 15:
      if (lookahead == 'l') ADVANCE(14);
      END_STATE();
    case 16:
      if (lookahead == 'n') ADVANCE(13);
      END_STATE();
    case 17:
      if (lookahead == 'o') ADVANCE(18);
      END_STATE();
    case 18:
      if (lookahead == 'p') ADVANCE(19);
      END_STATE();
    case 19:
      if (lookahead == 'y') ADVANCE(10);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_inline_richtext_token1);
      if (lookahead == '\r') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(22);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_inline_richtext_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == 'b') ADVANCE(25);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(28);
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
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(27);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(27);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == 'd') ADVANCE(36);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(28);
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
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(27);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(27);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == 'e') ADVANCE(24);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(28);
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
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(27);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(27);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == 'm') ADVANCE(23);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(28);
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
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(27);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(27);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(28);
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
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(27);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_metadata_key);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(28);
      if (set_contains(sym_metadata_key_character_set_2, 433, lookahead)) ADVANCE(27);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_STRING1);
      if (lookahead == '\r') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(31);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(30);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_STRING1);
      if (lookahead == '\\') ADVANCE(31);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_STRING1);
      if (lookahead == '\\') ADVANCE(31);
      if (lookahead != 0) ADVANCE(30);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_STRING2);
      if (lookahead == '\r') ADVANCE(32);
      if (lookahead == '\\') ADVANCE(34);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(33);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_STRING2);
      if (lookahead == '\\') ADVANCE(34);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_STRING2);
      if (lookahead == '\\') ADVANCE(34);
      if (lookahead != 0) ADVANCE(33);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym__LITERAL_VERSION_COMMENT);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__LITERAL_NODE_EMBED_DECLARATION);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(28);
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
          (0x10376 <= lookahead && lookahead <= 0x1037a)) ADVANCE(27);
      if (set_contains(sym_metadata_key_character_set_3, 462, lookahead)) ADVANCE(27);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym__SYMBOL_NODE_DEF);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym__SYMBOL_METADATA_ASSIGNMENT);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_SYMBOL_EMPTY_NODE);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_SYMBOL_EMPTY_NODE);
      if (lookahead == '<') ADVANCE(7);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym__SYMBOL_SINGLE_QUOTE);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym__SYMBOL_DOUBLE_QUOTE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 1, .external_lex_state = 2},
  [2] = {.lex_state = 0, .external_lex_state = 2},
  [3] = {.lex_state = 2, .external_lex_state = 3},
  [4] = {.lex_state = 0, .external_lex_state = 2},
  [5] = {.lex_state = 0, .external_lex_state = 4},
  [6] = {.lex_state = 0, .external_lex_state = 2},
  [7] = {.lex_state = 0, .external_lex_state = 4},
  [8] = {.lex_state = 2, .external_lex_state = 3},
  [9] = {.lex_state = 0, .external_lex_state = 5},
  [10] = {.lex_state = 0, .external_lex_state = 4},
  [11] = {.lex_state = 0, .external_lex_state = 5},
  [12] = {.lex_state = 0, .external_lex_state = 5},
  [13] = {.lex_state = 0, .external_lex_state = 6},
  [14] = {.lex_state = 0, .external_lex_state = 6},
  [15] = {.lex_state = 0, .external_lex_state = 7},
  [16] = {.lex_state = 0, .external_lex_state = 7},
  [17] = {.lex_state = 0, .external_lex_state = 7},
  [18] = {.lex_state = 0, .external_lex_state = 7},
  [19] = {.lex_state = 2, .external_lex_state = 3},
  [20] = {.lex_state = 0, .external_lex_state = 8},
  [21] = {.lex_state = 0, .external_lex_state = 8},
  [22] = {.lex_state = 0, .external_lex_state = 5},
  [23] = {.lex_state = 0, .external_lex_state = 6},
  [24] = {.lex_state = 0, .external_lex_state = 3},
  [25] = {.lex_state = 0, .external_lex_state = 8},
  [26] = {.lex_state = 0, .external_lex_state = 3},
  [27] = {.lex_state = 0, .external_lex_state = 8},
  [28] = {.lex_state = 0, .external_lex_state = 8},
  [29] = {.lex_state = 0, .external_lex_state = 5},
  [30] = {.lex_state = 0, .external_lex_state = 3},
  [31] = {.lex_state = 0, .external_lex_state = 3},
  [32] = {.lex_state = 0, .external_lex_state = 8},
  [33] = {.lex_state = 0, .external_lex_state = 3},
  [34] = {.lex_state = 0, .external_lex_state = 3},
  [35] = {.lex_state = 0, .external_lex_state = 5},
  [36] = {.lex_state = 0, .external_lex_state = 3},
  [37] = {.lex_state = 0, .external_lex_state = 3},
  [38] = {.lex_state = 0, .external_lex_state = 3},
  [39] = {.lex_state = 0, .external_lex_state = 3},
  [40] = {.lex_state = 0, .external_lex_state = 9},
  [41] = {.lex_state = 0, .external_lex_state = 9},
  [42] = {.lex_state = 0, .external_lex_state = 3},
  [43] = {.lex_state = 0, .external_lex_state = 2},
  [44] = {.lex_state = 0, .external_lex_state = 6},
  [45] = {.lex_state = 0, .external_lex_state = 3},
  [46] = {.lex_state = 0, .external_lex_state = 6},
  [47] = {.lex_state = 0, .external_lex_state = 3},
  [48] = {.lex_state = 2, .external_lex_state = 3},
  [49] = {.lex_state = 0, .external_lex_state = 3},
  [50] = {.lex_state = 0, .external_lex_state = 3},
  [51] = {.lex_state = 0, .external_lex_state = 3},
  [52] = {.lex_state = 0, .external_lex_state = 3},
  [53] = {.lex_state = 2, .external_lex_state = 3},
  [54] = {.lex_state = 0, .external_lex_state = 3},
  [55] = {.lex_state = 0, .external_lex_state = 4},
  [56] = {.lex_state = 0, .external_lex_state = 4},
  [57] = {.lex_state = 2, .external_lex_state = 10},
  [58] = {.lex_state = 2, .external_lex_state = 3},
  [59] = {.lex_state = 0, .external_lex_state = 8},
  [60] = {.lex_state = 0, .external_lex_state = 11},
  [61] = {.lex_state = 0, .external_lex_state = 11},
  [62] = {.lex_state = 2, .external_lex_state = 10},
  [63] = {.lex_state = 0, .external_lex_state = 3},
  [64] = {.lex_state = 0, .external_lex_state = 4},
  [65] = {.lex_state = 0, .external_lex_state = 3},
  [66] = {.lex_state = 0, .external_lex_state = 11},
  [67] = {.lex_state = 0, .external_lex_state = 3},
  [68] = {.lex_state = 0, .external_lex_state = 8},
  [69] = {.lex_state = 0, .external_lex_state = 4},
  [70] = {.lex_state = 0, .external_lex_state = 3},
  [71] = {.lex_state = 0, .external_lex_state = 4},
  [72] = {.lex_state = 0, .external_lex_state = 5},
  [73] = {.lex_state = 0, .external_lex_state = 5},
  [74] = {.lex_state = 0, .external_lex_state = 8},
  [75] = {.lex_state = 0, .external_lex_state = 8},
  [76] = {.lex_state = 0, .external_lex_state = 8},
  [77] = {.lex_state = 0, .external_lex_state = 5},
  [78] = {.lex_state = 0, .external_lex_state = 5},
  [79] = {.lex_state = 0, .external_lex_state = 11},
  [80] = {.lex_state = 0, .external_lex_state = 5},
  [81] = {.lex_state = 0, .external_lex_state = 5},
  [82] = {.lex_state = 0, .external_lex_state = 4},
  [83] = {.lex_state = 0, .external_lex_state = 4},
  [84] = {.lex_state = 0, .external_lex_state = 5},
  [85] = {.lex_state = 0, .external_lex_state = 5},
  [86] = {.lex_state = 0, .external_lex_state = 3},
  [87] = {.lex_state = 0, .external_lex_state = 5},
  [88] = {.lex_state = 0, .external_lex_state = 8},
  [89] = {.lex_state = 0, .external_lex_state = 4},
  [90] = {.lex_state = 0, .external_lex_state = 5},
  [91] = {.lex_state = 0, .external_lex_state = 3},
  [92] = {.lex_state = 0, .external_lex_state = 4},
  [93] = {.lex_state = 0, .external_lex_state = 3},
  [94] = {.lex_state = 0, .external_lex_state = 3},
  [95] = {.lex_state = 0, .external_lex_state = 8},
  [96] = {.lex_state = 0, .external_lex_state = 3},
  [97] = {.lex_state = 3},
  [98] = {.lex_state = 0, .external_lex_state = 9},
  [99] = {.lex_state = 0, .external_lex_state = 12},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 0, .external_lex_state = 2},
  [102] = {.lex_state = 0, .external_lex_state = 9},
  [103] = {.lex_state = 0, .external_lex_state = 3},
  [104] = {.lex_state = 0, .external_lex_state = 12},
  [105] = {.lex_state = 0, .external_lex_state = 3},
  [106] = {.lex_state = 0, .external_lex_state = 2},
  [107] = {.lex_state = 0, .external_lex_state = 3},
  [108] = {.lex_state = 0, .external_lex_state = 2},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 0, .external_lex_state = 11},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0, .external_lex_state = 13},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 1},
  [117] = {.lex_state = 5},
  [118] = {.lex_state = 0, .external_lex_state = 14},
  [119] = {.lex_state = 0, .external_lex_state = 15},
  [120] = {.lex_state = 0, .external_lex_state = 16},
  [121] = {.lex_state = 3},
  [122] = {.lex_state = 0, .external_lex_state = 16},
  [123] = {.lex_state = 4},
  [124] = {.lex_state = 0, .external_lex_state = 15},
  [125] = {.lex_state = 0, .external_lex_state = 15},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0, .external_lex_state = 15},
  [128] = {.lex_state = 0, .external_lex_state = 15},
  [129] = {.lex_state = 0, .external_lex_state = 13},
  [130] = {.lex_state = 0, .external_lex_state = 15},
  [131] = {.lex_state = 0, .external_lex_state = 16},
  [132] = {.lex_state = 0, .external_lex_state = 11},
  [133] = {.lex_state = 0, .external_lex_state = 16},
  [134] = {.lex_state = 0, .external_lex_state = 15},
  [135] = {.lex_state = 5},
  [136] = {.lex_state = 0, .external_lex_state = 15},
  [137] = {.lex_state = 0, .external_lex_state = 13},
  [138] = {.lex_state = 5},
  [139] = {.lex_state = 0, .external_lex_state = 11},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 5},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0, .external_lex_state = 17},
  [145] = {.lex_state = 0, .external_lex_state = 10},
  [146] = {.lex_state = 0, .external_lex_state = 14},
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
    [sym__node_metadata_sentinel] = ACTIONS(1),
    [sym__empty_node_sentinel] = ACTIONS(1),
    [sym__ext_flag_embed] = ACTIONS(1),
    [sym__ext_flag_node_def] = ACTIONS(1),
    [sym__ext_eol] = ACTIONS(1),
    [sym__ext_empty_line] = ACTIONS(1),
    [sym__ext_nih_whitespace] = ACTIONS(1),
    [sym__ext_node_continue] = ACTIONS(1),
    [sym__ext_node_begin] = ACTIONS(1),
    [sym__ext_node_end] = ACTIONS(1),
    [sym__ext_eof] = ACTIONS(1),
    [sym_autoclose_warning] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(140),
    [sym_empty_line] = STATE(6),
    [sym_version_comment] = STATE(4),
    [sym__node_segments] = STATE(137),
    [sym_node] = STATE(5),
    [sym_node_title] = STATE(41),
    [sym_node_title_line] = STATE(32),
    [sym_content_line] = STATE(5),
    [aux_sym_document_repeat1] = STATE(6),
    [sym__LITERAL_VERSION_COMMENT] = ACTIONS(3),
    [sym__ext_empty_line] = ACTIONS(5),
    [sym__ext_node_continue] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(5), 1,
      sym__ext_empty_line,
    ACTIONS(7), 1,
      sym__ext_node_continue,
    STATE(32), 1,
      sym_node_title_line,
    STATE(41), 1,
      sym_node_title,
    STATE(114), 1,
      sym__node_segments,
    STATE(5), 2,
      sym_node,
      sym_content_line,
    STATE(43), 2,
      sym_empty_line,
      aux_sym_document_repeat1,
  [24] = 8,
    ACTIONS(9), 1,
      aux_sym_inline_richtext_token1,
    ACTIONS(11), 1,
      sym__ext_eol,
    ACTIONS(13), 1,
      sym__ext_nih_whitespace,
    STATE(48), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(54), 1,
      sym_inline_richtext,
    STATE(67), 1,
      aux_sym__eol_repeat1,
    STATE(68), 1,
      sym__eol,
    STATE(19), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [50] = 7,
    ACTIONS(5), 1,
      sym__ext_empty_line,
    ACTIONS(7), 1,
      sym__ext_node_continue,
    STATE(32), 1,
      sym_node_title_line,
    STATE(41), 1,
      sym_node_title,
    STATE(129), 1,
      sym__node_segments,
    STATE(2), 2,
      sym_empty_line,
      aux_sym_document_repeat1,
    STATE(5), 2,
      sym_node,
      sym_content_line,
  [74] = 6,
    ACTIONS(7), 1,
      sym__ext_node_continue,
    ACTIONS(15), 1,
      sym__ext_empty_line,
    ACTIONS(17), 1,
      sym__ext_eof,
    STATE(32), 1,
      sym_node_title_line,
    STATE(41), 1,
      sym_node_title,
    STATE(10), 4,
      sym_empty_line,
      sym_node,
      sym_content_line,
      aux_sym__node_segments_repeat1,
  [96] = 7,
    ACTIONS(5), 1,
      sym__ext_empty_line,
    ACTIONS(7), 1,
      sym__ext_node_continue,
    STATE(32), 1,
      sym_node_title_line,
    STATE(41), 1,
      sym_node_title,
    STATE(129), 1,
      sym__node_segments,
    STATE(5), 2,
      sym_node,
      sym_content_line,
    STATE(43), 2,
      sym_empty_line,
      aux_sym_document_repeat1,
  [120] = 6,
    ACTIONS(19), 1,
      sym__ext_empty_line,
    ACTIONS(22), 1,
      sym__ext_node_continue,
    ACTIONS(25), 1,
      sym__ext_eof,
    STATE(32), 1,
      sym_node_title_line,
    STATE(41), 1,
      sym_node_title,
    STATE(7), 4,
      sym_empty_line,
      sym_node,
      sym_content_line,
      aux_sym__node_segments_repeat1,
  [142] = 8,
    ACTIONS(9), 1,
      aux_sym_inline_richtext_token1,
    ACTIONS(13), 1,
      sym__ext_nih_whitespace,
    ACTIONS(27), 1,
      sym__ext_eol,
    STATE(47), 1,
      sym_inline_richtext,
    STATE(48), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(59), 1,
      sym__eol,
    STATE(67), 1,
      aux_sym__eol_repeat1,
    STATE(3), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [168] = 6,
    ACTIONS(29), 1,
      sym__ext_empty_line,
    ACTIONS(31), 1,
      sym__ext_node_continue,
    ACTIONS(33), 1,
      sym__ext_node_end,
    STATE(32), 1,
      sym_node_title_line,
    STATE(40), 1,
      sym_node_title,
    STATE(12), 4,
      sym_empty_line,
      sym_node,
      sym_content_line,
      aux_sym__node_segments_repeat1,
  [190] = 6,
    ACTIONS(7), 1,
      sym__ext_node_continue,
    ACTIONS(15), 1,
      sym__ext_empty_line,
    ACTIONS(33), 1,
      sym__ext_eof,
    STATE(32), 1,
      sym_node_title_line,
    STATE(41), 1,
      sym_node_title,
    STATE(7), 4,
      sym_empty_line,
      sym_node,
      sym_content_line,
      aux_sym__node_segments_repeat1,
  [212] = 6,
    ACTIONS(17), 1,
      sym__ext_node_end,
    ACTIONS(29), 1,
      sym__ext_empty_line,
    ACTIONS(31), 1,
      sym__ext_node_continue,
    STATE(32), 1,
      sym_node_title_line,
    STATE(40), 1,
      sym_node_title,
    STATE(9), 4,
      sym_empty_line,
      sym_node,
      sym_content_line,
      aux_sym__node_segments_repeat1,
  [234] = 6,
    ACTIONS(25), 1,
      sym__ext_node_end,
    ACTIONS(35), 1,
      sym__ext_empty_line,
    ACTIONS(38), 1,
      sym__ext_node_continue,
    STATE(32), 1,
      sym_node_title_line,
    STATE(40), 1,
      sym_node_title,
    STATE(12), 4,
      sym_empty_line,
      sym_node,
      sym_content_line,
      aux_sym__node_segments_repeat1,
  [256] = 7,
    ACTIONS(41), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(43), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(45), 1,
      sym__ext_nih_whitespace,
    STATE(38), 1,
      sym_metadata_value,
    STATE(44), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(96), 1,
      sym__string,
    STATE(14), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [279] = 7,
    ACTIONS(41), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(43), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(45), 1,
      sym__ext_nih_whitespace,
    STATE(39), 1,
      sym_metadata_value,
    STATE(44), 1,
      aux_sym_nih_whitespace_repeat1,
    STATE(96), 1,
      sym__string,
    STATE(23), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [302] = 6,
    ACTIONS(31), 1,
      sym__ext_node_continue,
    ACTIONS(47), 1,
      sym__ext_flag_embed,
    STATE(32), 1,
      sym_node_title_line,
    STATE(40), 1,
      sym_node_title,
    STATE(128), 1,
      sym__node_segments,
    STATE(11), 2,
      sym_node,
      sym_content_line,
  [322] = 6,
    ACTIONS(31), 1,
      sym__ext_node_continue,
    ACTIONS(49), 1,
      sym__ext_flag_embed,
    STATE(32), 1,
      sym_node_title_line,
    STATE(40), 1,
      sym_node_title,
    STATE(125), 1,
      sym__node_segments,
    STATE(11), 2,
      sym_node,
      sym_content_line,
  [342] = 6,
    ACTIONS(31), 1,
      sym__ext_node_continue,
    ACTIONS(51), 1,
      sym__ext_flag_embed,
    STATE(32), 1,
      sym_node_title_line,
    STATE(40), 1,
      sym_node_title,
    STATE(134), 1,
      sym__node_segments,
    STATE(11), 2,
      sym_node,
      sym_content_line,
  [362] = 6,
    ACTIONS(31), 1,
      sym__ext_node_continue,
    ACTIONS(53), 1,
      sym__ext_flag_embed,
    STATE(32), 1,
      sym_node_title_line,
    STATE(40), 1,
      sym_node_title,
    STATE(119), 1,
      sym__node_segments,
    STATE(11), 2,
      sym_node,
      sym_content_line,
  [382] = 4,
    ACTIONS(57), 1,
      sym__ext_nih_whitespace,
    STATE(48), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(55), 2,
      sym__ext_eol,
      aux_sym_inline_richtext_token1,
    STATE(19), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [397] = 4,
    ACTIONS(60), 1,
      sym__ext_empty_line,
    ACTIONS(63), 1,
      sym__ext_node_continue,
    ACTIONS(66), 1,
      sym__ext_node_begin,
    STATE(20), 3,
      sym_empty_line,
      sym_node_title_line,
      aux_sym_node_title_repeat1,
  [412] = 4,
    ACTIONS(68), 1,
      sym__ext_empty_line,
    ACTIONS(71), 1,
      sym__ext_node_continue,
    ACTIONS(74), 1,
      sym__ext_node_begin,
    STATE(21), 3,
      sym_empty_line,
      sym_node_metadata_declaration_line,
      aux_sym_node_metadata_repeat1,
  [427] = 4,
    ACTIONS(29), 1,
      sym__ext_empty_line,
    ACTIONS(76), 1,
      sym__ext_node_continue,
    ACTIONS(78), 1,
      sym__ext_node_end,
    STATE(35), 3,
      sym_empty_line,
      sym_embedding_line,
      aux_sym__embedding_segments_repeat1,
  [442] = 4,
    ACTIONS(80), 1,
      sym__ext_nih_whitespace,
    STATE(44), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(55), 2,
      sym__SYMBOL_SINGLE_QUOTE,
      sym__SYMBOL_DOUBLE_QUOTE,
    STATE(23), 2,
      sym_nih_whitespace,
      aux_sym_node_title_line_repeat1,
  [457] = 6,
    ACTIONS(83), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(85), 1,
      sym__ext_eol,
    ACTIONS(88), 1,
      sym__ext_nih_whitespace,
    STATE(24), 1,
      aux_sym__string_double_repeat1,
    STATE(63), 1,
      aux_sym__eol_repeat1,
    STATE(139), 1,
      sym__eol,
  [476] = 4,
    ACTIONS(91), 1,
      sym__ext_empty_line,
    ACTIONS(93), 1,
      sym__ext_node_continue,
    ACTIONS(96), 1,
      sym__ext_node_begin,
    STATE(28), 3,
      sym_empty_line,
      sym_node_metadata_declaration_line,
      aux_sym_node_metadata_repeat1,
  [491] = 6,
    ACTIONS(98), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(100), 1,
      sym__ext_eol,
    ACTIONS(103), 1,
      sym__ext_nih_whitespace,
    STATE(26), 1,
      aux_sym__string_single_repeat1,
    STATE(63), 1,
      aux_sym__eol_repeat1,
    STATE(132), 1,
      sym__eol,
  [510] = 4,
    ACTIONS(91), 1,
      sym__ext_empty_line,
    ACTIONS(106), 1,
      sym__ext_node_continue,
    ACTIONS(109), 1,
      sym__ext_node_begin,
    STATE(20), 3,
      sym_empty_line,
      sym_node_title_line,
      aux_sym_node_title_repeat1,
  [525] = 4,
    ACTIONS(91), 1,
      sym__ext_empty_line,
    ACTIONS(111), 1,
      sym__ext_node_continue,
    ACTIONS(114), 1,
      sym__ext_node_begin,
    STATE(21), 3,
      sym_empty_line,
      sym_node_metadata_declaration_line,
      aux_sym_node_metadata_repeat1,
  [540] = 4,
    ACTIONS(29), 1,
      sym__ext_empty_line,
    ACTIONS(76), 1,
      sym__ext_node_continue,
    ACTIONS(116), 1,
      sym__ext_node_end,
    STATE(22), 3,
      sym_empty_line,
      sym_embedding_line,
      aux_sym__embedding_segments_repeat1,
  [555] = 6,
    ACTIONS(118), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    ACTIONS(120), 1,
      sym__ext_eol,
    ACTIONS(122), 1,
      sym__ext_nih_whitespace,
    STATE(24), 1,
      aux_sym__string_double_repeat1,
    STATE(63), 1,
      aux_sym__eol_repeat1,
    STATE(139), 1,
      sym__eol,
  [574] = 6,
    ACTIONS(122), 1,
      sym__ext_nih_whitespace,
    ACTIONS(124), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    ACTIONS(126), 1,
      sym__ext_eol,
    STATE(26), 1,
      aux_sym__string_single_repeat1,
    STATE(63), 1,
      aux_sym__eol_repeat1,
    STATE(132), 1,
      sym__eol,
  [593] = 4,
    ACTIONS(91), 1,
      sym__ext_empty_line,
    ACTIONS(128), 1,
      sym__ext_node_continue,
    ACTIONS(131), 1,
      sym__ext_node_begin,
    STATE(27), 3,
      sym_empty_line,
      sym_node_title_line,
      aux_sym_node_title_repeat1,
  [608] = 6,
    ACTIONS(120), 1,
      sym__ext_eol,
    ACTIONS(122), 1,
      sym__ext_nih_whitespace,
    ACTIONS(133), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
    STATE(30), 1,
      aux_sym__string_double_repeat1,
    STATE(63), 1,
      aux_sym__eol_repeat1,
    STATE(139), 1,
      sym__eol,
  [627] = 6,
    ACTIONS(122), 1,
      sym__ext_nih_whitespace,
    ACTIONS(126), 1,
      sym__ext_eol,
    ACTIONS(135), 1,
      sym__SYMBOL_SINGLE_QUOTE,
    STATE(31), 1,
      aux_sym__string_single_repeat1,
    STATE(63), 1,
      aux_sym__eol_repeat1,
    STATE(132), 1,
      sym__eol,
  [646] = 4,
    ACTIONS(137), 1,
      sym__ext_empty_line,
    ACTIONS(140), 1,
      sym__ext_node_continue,
    ACTIONS(143), 1,
      sym__ext_node_end,
    STATE(35), 3,
      sym_empty_line,
      sym_embedding_line,
      aux_sym__embedding_segments_repeat1,
  [661] = 4,
    ACTIONS(145), 1,
      sym__ext_eol,
    ACTIONS(147), 1,
      sym__ext_nih_whitespace,
    STATE(65), 1,
      aux_sym__eol_repeat1,
    STATE(90), 1,
      sym__eol,
  [674] = 4,
    ACTIONS(147), 1,
      sym__ext_nih_whitespace,
    ACTIONS(149), 1,
      sym__ext_eol,
    STATE(65), 1,
      aux_sym__eol_repeat1,
    STATE(85), 1,
      sym__eol,
  [687] = 4,
    ACTIONS(151), 1,
      sym__ext_eol,
    ACTIONS(153), 1,
      sym__ext_nih_whitespace,
    STATE(67), 1,
      aux_sym__eol_repeat1,
    STATE(88), 1,
      sym__eol,
  [700] = 4,
    ACTIONS(153), 1,
      sym__ext_nih_whitespace,
    ACTIONS(155), 1,
      sym__ext_eol,
    STATE(67), 1,
      aux_sym__eol_repeat1,
    STATE(95), 1,
      sym__eol,
  [713] = 4,
    ACTIONS(157), 1,
      sym__ext_node_continue,
    ACTIONS(159), 1,
      sym__ext_node_begin,
    STATE(25), 1,
      sym_node_metadata_declaration_line,
    STATE(98), 1,
      sym_node_metadata,
  [726] = 4,
    ACTIONS(161), 1,
      sym__ext_node_continue,
    ACTIONS(163), 1,
      sym__ext_node_begin,
    STATE(25), 1,
      sym_node_metadata_declaration_line,
    STATE(102), 1,
      sym_node_metadata,
  [739] = 4,
    ACTIONS(147), 1,
      sym__ext_nih_whitespace,
    ACTIONS(165), 1,
      sym__ext_eol,
    STATE(65), 1,
      aux_sym__eol_repeat1,
    STATE(78), 1,
      sym__eol,
  [752] = 3,
    ACTIONS(167), 1,
      sym__ext_empty_line,
    ACTIONS(170), 1,
      sym__ext_node_continue,
    STATE(43), 2,
      sym_empty_line,
      aux_sym_document_repeat1,
  [763] = 3,
    ACTIONS(174), 1,
      sym__ext_nih_whitespace,
    STATE(46), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(172), 2,
      sym__SYMBOL_SINGLE_QUOTE,
      sym__SYMBOL_DOUBLE_QUOTE,
  [774] = 4,
    ACTIONS(176), 1,
      sym__ext_eol,
    ACTIONS(178), 1,
      sym__ext_nih_whitespace,
    STATE(70), 1,
      aux_sym__eol_repeat1,
    STATE(82), 1,
      sym__eol,
  [787] = 3,
    ACTIONS(182), 1,
      sym__ext_nih_whitespace,
    STATE(46), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(180), 2,
      sym__SYMBOL_SINGLE_QUOTE,
      sym__SYMBOL_DOUBLE_QUOTE,
  [798] = 4,
    ACTIONS(11), 1,
      sym__ext_eol,
    ACTIONS(153), 1,
      sym__ext_nih_whitespace,
    STATE(67), 1,
      aux_sym__eol_repeat1,
    STATE(68), 1,
      sym__eol,
  [811] = 3,
    ACTIONS(185), 1,
      sym__ext_nih_whitespace,
    STATE(53), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(172), 2,
      sym__ext_eol,
      aux_sym_inline_richtext_token1,
  [822] = 4,
    ACTIONS(187), 1,
      sym__ext_eol,
    ACTIONS(189), 1,
      sym__ext_nih_whitespace,
    STATE(86), 1,
      aux_sym__eol_repeat1,
    STATE(108), 1,
      sym__eol,
  [835] = 4,
    ACTIONS(178), 1,
      sym__ext_nih_whitespace,
    ACTIONS(191), 1,
      sym__ext_eol,
    STATE(56), 1,
      sym__eol,
    STATE(70), 1,
      aux_sym__eol_repeat1,
  [848] = 4,
    ACTIONS(147), 1,
      sym__ext_nih_whitespace,
    ACTIONS(193), 1,
      sym__ext_eol,
    STATE(65), 1,
      aux_sym__eol_repeat1,
    STATE(80), 1,
      sym__eol,
  [861] = 4,
    ACTIONS(178), 1,
      sym__ext_nih_whitespace,
    ACTIONS(195), 1,
      sym__ext_eol,
    STATE(69), 1,
      sym__eol,
    STATE(70), 1,
      aux_sym__eol_repeat1,
  [874] = 3,
    ACTIONS(197), 1,
      sym__ext_nih_whitespace,
    STATE(53), 1,
      aux_sym_nih_whitespace_repeat1,
    ACTIONS(180), 2,
      sym__ext_eol,
      aux_sym_inline_richtext_token1,
  [885] = 4,
    ACTIONS(153), 1,
      sym__ext_nih_whitespace,
    ACTIONS(200), 1,
      sym__ext_eol,
    STATE(67), 1,
      aux_sym__eol_repeat1,
    STATE(74), 1,
      sym__eol,
  [898] = 1,
    ACTIONS(202), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_eof,
  [904] = 1,
    ACTIONS(204), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_eof,
  [910] = 3,
    ACTIONS(9), 1,
      aux_sym_inline_richtext_token1,
    ACTIONS(206), 1,
      sym__ext_flag_node_def,
    STATE(50), 1,
      sym_inline_richtext,
  [920] = 2,
    ACTIONS(208), 1,
      aux_sym_inline_richtext_token1,
    ACTIONS(210), 2,
      sym__ext_eol,
      sym__ext_nih_whitespace,
  [928] = 1,
    ACTIONS(212), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [934] = 3,
    ACTIONS(76), 1,
      sym__ext_node_continue,
    STATE(29), 1,
      sym_embedding_line,
    STATE(130), 1,
      sym__embedding_segments,
  [944] = 3,
    ACTIONS(76), 1,
      sym__ext_node_continue,
    STATE(29), 1,
      sym_embedding_line,
    STATE(127), 1,
      sym__embedding_segments,
  [954] = 3,
    ACTIONS(9), 1,
      aux_sym_inline_richtext_token1,
    ACTIONS(206), 1,
      sym__ext_flag_node_def,
    STATE(36), 1,
      sym_inline_richtext,
  [964] = 3,
    ACTIONS(214), 1,
      sym__ext_eol,
    ACTIONS(216), 1,
      sym__ext_nih_whitespace,
    STATE(91), 1,
      aux_sym__eol_repeat1,
  [974] = 1,
    ACTIONS(218), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_eof,
  [980] = 3,
    ACTIONS(216), 1,
      sym__ext_nih_whitespace,
    ACTIONS(220), 1,
      sym__ext_eol,
    STATE(91), 1,
      aux_sym__eol_repeat1,
  [990] = 3,
    ACTIONS(76), 1,
      sym__ext_node_continue,
    STATE(29), 1,
      sym_embedding_line,
    STATE(124), 1,
      sym__embedding_segments,
  [1000] = 3,
    ACTIONS(216), 1,
      sym__ext_nih_whitespace,
    ACTIONS(222), 1,
      sym__ext_eol,
    STATE(91), 1,
      aux_sym__eol_repeat1,
  [1010] = 1,
    ACTIONS(224), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1016] = 1,
    ACTIONS(226), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_eof,
  [1022] = 3,
    ACTIONS(216), 1,
      sym__ext_nih_whitespace,
    ACTIONS(228), 1,
      sym__ext_eol,
    STATE(91), 1,
      aux_sym__eol_repeat1,
  [1032] = 1,
    ACTIONS(230), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_eof,
  [1038] = 1,
    ACTIONS(232), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1044] = 1,
    ACTIONS(234), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1050] = 1,
    ACTIONS(236), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1056] = 1,
    ACTIONS(232), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1062] = 1,
    ACTIONS(234), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1068] = 1,
    ACTIONS(238), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1074] = 1,
    ACTIONS(240), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1080] = 3,
    ACTIONS(76), 1,
      sym__ext_node_continue,
    STATE(29), 1,
      sym_embedding_line,
    STATE(136), 1,
      sym__embedding_segments,
  [1090] = 1,
    ACTIONS(242), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1096] = 1,
    ACTIONS(202), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1102] = 1,
    ACTIONS(240), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_eof,
  [1108] = 1,
    ACTIONS(238), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_eof,
  [1114] = 1,
    ACTIONS(230), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1120] = 1,
    ACTIONS(226), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1126] = 3,
    ACTIONS(216), 1,
      sym__ext_nih_whitespace,
    ACTIONS(244), 1,
      sym__ext_eol,
    STATE(91), 1,
      aux_sym__eol_repeat1,
  [1136] = 1,
    ACTIONS(218), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1142] = 1,
    ACTIONS(246), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1148] = 1,
    ACTIONS(232), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_eof,
  [1154] = 1,
    ACTIONS(204), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_end,
  [1160] = 3,
    ACTIONS(248), 1,
      sym__ext_eol,
    ACTIONS(250), 1,
      sym__ext_nih_whitespace,
    STATE(91), 1,
      aux_sym__eol_repeat1,
  [1170] = 1,
    ACTIONS(234), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_eof,
  [1176] = 1,
    ACTIONS(253), 3,
      sym__ext_eol,
      sym__ext_nih_whitespace,
      sym__SYMBOL_DOUBLE_QUOTE,
  [1182] = 1,
    ACTIONS(255), 3,
      sym__ext_eol,
      sym__ext_nih_whitespace,
      sym__SYMBOL_SINGLE_QUOTE,
  [1188] = 1,
    ACTIONS(257), 3,
      sym__ext_empty_line,
      sym__ext_node_continue,
      sym__ext_node_begin,
  [1194] = 1,
    ACTIONS(259), 2,
      sym__ext_eol,
      sym__ext_nih_whitespace,
  [1199] = 2,
    ACTIONS(261), 1,
      sym_STRING1,
    STATE(115), 1,
      sym__string_single,
  [1206] = 2,
    ACTIONS(263), 1,
      sym__ext_node_continue,
    ACTIONS(265), 1,
      sym__ext_node_begin,
  [1213] = 2,
    ACTIONS(267), 1,
      sym__node_metadata_sentinel,
    ACTIONS(269), 1,
      sym__empty_node_sentinel,
  [1220] = 2,
    ACTIONS(271), 1,
      aux_sym_inline_richtext_token1,
    STATE(51), 1,
      sym_inline_embedding,
  [1227] = 1,
    ACTIONS(232), 2,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1232] = 2,
    ACTIONS(273), 1,
      sym__ext_node_continue,
    ACTIONS(275), 1,
      sym__ext_node_begin,
  [1239] = 1,
    ACTIONS(277), 2,
      sym__ext_eol,
      sym__ext_nih_whitespace,
  [1244] = 2,
    ACTIONS(267), 1,
      sym__node_metadata_sentinel,
    ACTIONS(279), 1,
      sym__empty_node_sentinel,
  [1251] = 1,
    ACTIONS(281), 2,
      sym__ext_eol,
      sym__ext_nih_whitespace,
  [1256] = 1,
    ACTIONS(234), 2,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1261] = 1,
    ACTIONS(283), 2,
      sym__ext_eol,
      sym__ext_nih_whitespace,
  [1266] = 1,
    ACTIONS(285), 2,
      sym__ext_empty_line,
      sym__ext_node_continue,
  [1271] = 2,
    ACTIONS(287), 1,
      sym_STRING2,
    STATE(113), 1,
      sym__string_double,
  [1278] = 1,
    ACTIONS(232), 1,
      sym__ext_node_continue,
  [1282] = 1,
    ACTIONS(289), 1,
      ts_builtin_sym_end,
  [1286] = 1,
    ACTIONS(291), 1,
      ts_builtin_sym_end,
  [1290] = 1,
    ACTIONS(293), 1,
      sym__SYMBOL_DOUBLE_QUOTE,
  [1294] = 1,
    ACTIONS(295), 1,
      sym__ext_eof,
  [1298] = 1,
    ACTIONS(293), 1,
      sym__SYMBOL_SINGLE_QUOTE,
  [1302] = 1,
    ACTIONS(297), 1,
      sym_metadata_key,
  [1306] = 1,
    ACTIONS(299), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1310] = 1,
    ACTIONS(301), 1,
      sym__empty_node_sentinel,
  [1314] = 1,
    ACTIONS(303), 1,
      sym__ext_node_end,
  [1318] = 1,
    ACTIONS(305), 1,
      sym__ext_eol,
  [1322] = 1,
    ACTIONS(307), 1,
      sym_STRING1,
  [1326] = 1,
    ACTIONS(309), 1,
      sym__ext_eol,
  [1330] = 1,
    ACTIONS(311), 1,
      sym_STRING2,
  [1334] = 1,
    ACTIONS(313), 1,
      sym__ext_node_end,
  [1338] = 1,
    ACTIONS(315), 1,
      sym__ext_node_end,
  [1342] = 1,
    ACTIONS(317), 1,
      sym__SYMBOL_NODE_DEF,
  [1346] = 1,
    ACTIONS(319), 1,
      sym__ext_node_end,
  [1350] = 1,
    ACTIONS(321), 1,
      sym__ext_node_end,
  [1354] = 1,
    ACTIONS(323), 1,
      sym__ext_eof,
  [1358] = 1,
    ACTIONS(325), 1,
      sym__ext_node_end,
  [1362] = 1,
    ACTIONS(327), 1,
      sym__ext_eol,
  [1366] = 1,
    ACTIONS(329), 1,
      sym__ext_node_continue,
  [1370] = 1,
    ACTIONS(331), 1,
      sym__ext_eol,
  [1374] = 1,
    ACTIONS(333), 1,
      sym__ext_node_end,
  [1378] = 1,
    ACTIONS(335), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1382] = 1,
    ACTIONS(337), 1,
      sym__ext_node_end,
  [1386] = 1,
    ACTIONS(339), 1,
      sym__ext_eof,
  [1390] = 1,
    ACTIONS(341), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1394] = 1,
    ACTIONS(343), 1,
      sym__ext_node_continue,
  [1398] = 1,
    ACTIONS(345), 1,
      ts_builtin_sym_end,
  [1402] = 1,
    ACTIONS(347), 1,
      sym_SYMBOL_EMPTY_NODE,
  [1406] = 1,
    ACTIONS(349), 1,
      sym__SYMBOL_METADATA_ASSIGNMENT,
  [1410] = 1,
    ACTIONS(351), 1,
      ts_builtin_sym_end,
  [1414] = 1,
    ACTIONS(267), 1,
      sym__node_metadata_sentinel,
  [1418] = 1,
    ACTIONS(206), 1,
      sym__ext_flag_node_def,
  [1422] = 1,
    ACTIONS(353), 1,
      sym__empty_node_sentinel,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 50,
  [SMALL_STATE(5)] = 74,
  [SMALL_STATE(6)] = 96,
  [SMALL_STATE(7)] = 120,
  [SMALL_STATE(8)] = 142,
  [SMALL_STATE(9)] = 168,
  [SMALL_STATE(10)] = 190,
  [SMALL_STATE(11)] = 212,
  [SMALL_STATE(12)] = 234,
  [SMALL_STATE(13)] = 256,
  [SMALL_STATE(14)] = 279,
  [SMALL_STATE(15)] = 302,
  [SMALL_STATE(16)] = 322,
  [SMALL_STATE(17)] = 342,
  [SMALL_STATE(18)] = 362,
  [SMALL_STATE(19)] = 382,
  [SMALL_STATE(20)] = 397,
  [SMALL_STATE(21)] = 412,
  [SMALL_STATE(22)] = 427,
  [SMALL_STATE(23)] = 442,
  [SMALL_STATE(24)] = 457,
  [SMALL_STATE(25)] = 476,
  [SMALL_STATE(26)] = 491,
  [SMALL_STATE(27)] = 510,
  [SMALL_STATE(28)] = 525,
  [SMALL_STATE(29)] = 540,
  [SMALL_STATE(30)] = 555,
  [SMALL_STATE(31)] = 574,
  [SMALL_STATE(32)] = 593,
  [SMALL_STATE(33)] = 608,
  [SMALL_STATE(34)] = 627,
  [SMALL_STATE(35)] = 646,
  [SMALL_STATE(36)] = 661,
  [SMALL_STATE(37)] = 674,
  [SMALL_STATE(38)] = 687,
  [SMALL_STATE(39)] = 700,
  [SMALL_STATE(40)] = 713,
  [SMALL_STATE(41)] = 726,
  [SMALL_STATE(42)] = 739,
  [SMALL_STATE(43)] = 752,
  [SMALL_STATE(44)] = 763,
  [SMALL_STATE(45)] = 774,
  [SMALL_STATE(46)] = 787,
  [SMALL_STATE(47)] = 798,
  [SMALL_STATE(48)] = 811,
  [SMALL_STATE(49)] = 822,
  [SMALL_STATE(50)] = 835,
  [SMALL_STATE(51)] = 848,
  [SMALL_STATE(52)] = 861,
  [SMALL_STATE(53)] = 874,
  [SMALL_STATE(54)] = 885,
  [SMALL_STATE(55)] = 898,
  [SMALL_STATE(56)] = 904,
  [SMALL_STATE(57)] = 910,
  [SMALL_STATE(58)] = 920,
  [SMALL_STATE(59)] = 928,
  [SMALL_STATE(60)] = 934,
  [SMALL_STATE(61)] = 944,
  [SMALL_STATE(62)] = 954,
  [SMALL_STATE(63)] = 964,
  [SMALL_STATE(64)] = 974,
  [SMALL_STATE(65)] = 980,
  [SMALL_STATE(66)] = 990,
  [SMALL_STATE(67)] = 1000,
  [SMALL_STATE(68)] = 1010,
  [SMALL_STATE(69)] = 1016,
  [SMALL_STATE(70)] = 1022,
  [SMALL_STATE(71)] = 1032,
  [SMALL_STATE(72)] = 1038,
  [SMALL_STATE(73)] = 1044,
  [SMALL_STATE(74)] = 1050,
  [SMALL_STATE(75)] = 1056,
  [SMALL_STATE(76)] = 1062,
  [SMALL_STATE(77)] = 1068,
  [SMALL_STATE(78)] = 1074,
  [SMALL_STATE(79)] = 1080,
  [SMALL_STATE(80)] = 1090,
  [SMALL_STATE(81)] = 1096,
  [SMALL_STATE(82)] = 1102,
  [SMALL_STATE(83)] = 1108,
  [SMALL_STATE(84)] = 1114,
  [SMALL_STATE(85)] = 1120,
  [SMALL_STATE(86)] = 1126,
  [SMALL_STATE(87)] = 1136,
  [SMALL_STATE(88)] = 1142,
  [SMALL_STATE(89)] = 1148,
  [SMALL_STATE(90)] = 1154,
  [SMALL_STATE(91)] = 1160,
  [SMALL_STATE(92)] = 1170,
  [SMALL_STATE(93)] = 1176,
  [SMALL_STATE(94)] = 1182,
  [SMALL_STATE(95)] = 1188,
  [SMALL_STATE(96)] = 1194,
  [SMALL_STATE(97)] = 1199,
  [SMALL_STATE(98)] = 1206,
  [SMALL_STATE(99)] = 1213,
  [SMALL_STATE(100)] = 1220,
  [SMALL_STATE(101)] = 1227,
  [SMALL_STATE(102)] = 1232,
  [SMALL_STATE(103)] = 1239,
  [SMALL_STATE(104)] = 1244,
  [SMALL_STATE(105)] = 1251,
  [SMALL_STATE(106)] = 1256,
  [SMALL_STATE(107)] = 1261,
  [SMALL_STATE(108)] = 1266,
  [SMALL_STATE(109)] = 1271,
  [SMALL_STATE(110)] = 1278,
  [SMALL_STATE(111)] = 1282,
  [SMALL_STATE(112)] = 1286,
  [SMALL_STATE(113)] = 1290,
  [SMALL_STATE(114)] = 1294,
  [SMALL_STATE(115)] = 1298,
  [SMALL_STATE(116)] = 1302,
  [SMALL_STATE(117)] = 1306,
  [SMALL_STATE(118)] = 1310,
  [SMALL_STATE(119)] = 1314,
  [SMALL_STATE(120)] = 1318,
  [SMALL_STATE(121)] = 1322,
  [SMALL_STATE(122)] = 1326,
  [SMALL_STATE(123)] = 1330,
  [SMALL_STATE(124)] = 1334,
  [SMALL_STATE(125)] = 1338,
  [SMALL_STATE(126)] = 1342,
  [SMALL_STATE(127)] = 1346,
  [SMALL_STATE(128)] = 1350,
  [SMALL_STATE(129)] = 1354,
  [SMALL_STATE(130)] = 1358,
  [SMALL_STATE(131)] = 1362,
  [SMALL_STATE(132)] = 1366,
  [SMALL_STATE(133)] = 1370,
  [SMALL_STATE(134)] = 1374,
  [SMALL_STATE(135)] = 1378,
  [SMALL_STATE(136)] = 1382,
  [SMALL_STATE(137)] = 1386,
  [SMALL_STATE(138)] = 1390,
  [SMALL_STATE(139)] = 1394,
  [SMALL_STATE(140)] = 1398,
  [SMALL_STATE(141)] = 1402,
  [SMALL_STATE(142)] = 1406,
  [SMALL_STATE(143)] = 1410,
  [SMALL_STATE(144)] = 1414,
  [SMALL_STATE(145)] = 1418,
  [SMALL_STATE(146)] = 1422,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__node_segments, 1, 0, 0),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__node_segments_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__node_segments_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__node_segments_repeat1, 2, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__node_segments, 2, 0, 0),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__node_segments_repeat1, 2, 0, 0), SHIFT_REPEAT(133),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__node_segments_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_node_title_line_repeat1, 2, 0, 0),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_node_title_line_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_node_title_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_node_title_repeat1, 2, 0, 0), SHIFT_REPEAT(145),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_node_title_repeat1, 2, 0, 0),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_node_metadata_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_node_metadata_repeat1, 2, 0, 0), SHIFT_REPEAT(144),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_node_metadata_repeat1, 2, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__embedding_segments, 2, 0, 0),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_node_title_line_repeat1, 2, 0, 0), SHIFT_REPEAT(44),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__string_double_repeat1, 2, 0, 0),
  [85] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__string_double_repeat1, 2, 0, 0), SHIFT_REPEAT(139),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__string_double_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_node_metadata, 1, 0, 0), SHIFT(144),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_metadata, 1, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__string_single_repeat1, 2, 0, 0),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__string_single_repeat1, 2, 0, 0), SHIFT_REPEAT(132),
  [103] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__string_single_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_node_title, 2, 0, 0), SHIFT(145),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_title, 2, 0, 0),
  [111] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_node_metadata, 2, 0, 0), SHIFT(144),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_metadata, 2, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__embedding_segments, 1, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__string_double, 2, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__string_single, 2, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_node_title, 1, 0, 0), SHIFT(145),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_title, 1, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__string_double, 1, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__string_single, 1, 0, 0),
  [137] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__embedding_segments_repeat1, 2, 0, 0), SHIFT_REPEAT(133),
  [140] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__embedding_segments_repeat1, 2, 0, 0), SHIFT_REPEAT(100),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__embedding_segments_repeat1, 2, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [167] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(120),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nih_whitespace, 1, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_nih_whitespace_repeat1, 2, 0, 0),
  [182] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_nih_whitespace_repeat1, 2, 0, 0), SHIFT_REPEAT(46),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [197] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_nih_whitespace_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 5, 0, 4),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_content_line, 3, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_nih_whitespace_repeat1, 1, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__eol_repeat1, 1, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_title_line, 4, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 4, 0, 1),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_title_line, 5, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 5, 0, 2),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 5, 0, 3),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__eol, 2, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_empty_line, 2, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_title_line, 6, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 6, 0, 6),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 6, 0, 5),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_embedding_line, 3, 0, 0),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_metadata_declaration_line, 6, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__eol_repeat1, 2, 0, 0),
  [250] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__eol_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__string_double_repeat1, 3, 0, 0),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__string_single_repeat1, 3, 0, 0),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_metadata_declaration_line, 7, 0, 0),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_metadata_value, 1, 0, 0),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_embedding, 1, 0, 0),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__string, 3, 0, 0),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_richtext, 1, 0, 0),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_version_comment, 2, 0, 0),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 2, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 3, 0, 0),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [345] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 4, 0, 0),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__error_sentinel = 0,
  ts_external_token__node_metadata_sentinel = 1,
  ts_external_token__empty_node_sentinel = 2,
  ts_external_token__ext_flag_embed = 3,
  ts_external_token__ext_flag_node_def = 4,
  ts_external_token__ext_eol = 5,
  ts_external_token__ext_empty_line = 6,
  ts_external_token__ext_nih_whitespace = 7,
  ts_external_token__ext_node_continue = 8,
  ts_external_token__ext_node_begin = 9,
  ts_external_token__ext_node_end = 10,
  ts_external_token__ext_eof = 11,
  ts_external_token_autoclose_warning = 12,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__error_sentinel] = sym__error_sentinel,
  [ts_external_token__node_metadata_sentinel] = sym__node_metadata_sentinel,
  [ts_external_token__empty_node_sentinel] = sym__empty_node_sentinel,
  [ts_external_token__ext_flag_embed] = sym__ext_flag_embed,
  [ts_external_token__ext_flag_node_def] = sym__ext_flag_node_def,
  [ts_external_token__ext_eol] = sym__ext_eol,
  [ts_external_token__ext_empty_line] = sym__ext_empty_line,
  [ts_external_token__ext_nih_whitespace] = sym__ext_nih_whitespace,
  [ts_external_token__ext_node_continue] = sym__ext_node_continue,
  [ts_external_token__ext_node_begin] = sym__ext_node_begin,
  [ts_external_token__ext_node_end] = sym__ext_node_end,
  [ts_external_token__ext_eof] = sym__ext_eof,
  [ts_external_token_autoclose_warning] = sym_autoclose_warning,
};

static const bool ts_external_scanner_states[18][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__error_sentinel] = true,
    [ts_external_token__node_metadata_sentinel] = true,
    [ts_external_token__empty_node_sentinel] = true,
    [ts_external_token__ext_flag_embed] = true,
    [ts_external_token__ext_flag_node_def] = true,
    [ts_external_token__ext_eol] = true,
    [ts_external_token__ext_empty_line] = true,
    [ts_external_token__ext_nih_whitespace] = true,
    [ts_external_token__ext_node_continue] = true,
    [ts_external_token__ext_node_begin] = true,
    [ts_external_token__ext_node_end] = true,
    [ts_external_token__ext_eof] = true,
    [ts_external_token_autoclose_warning] = true,
  },
  [2] = {
    [ts_external_token__ext_empty_line] = true,
    [ts_external_token__ext_node_continue] = true,
  },
  [3] = {
    [ts_external_token__ext_eol] = true,
    [ts_external_token__ext_nih_whitespace] = true,
  },
  [4] = {
    [ts_external_token__ext_empty_line] = true,
    [ts_external_token__ext_node_continue] = true,
    [ts_external_token__ext_eof] = true,
  },
  [5] = {
    [ts_external_token__ext_empty_line] = true,
    [ts_external_token__ext_node_continue] = true,
    [ts_external_token__ext_node_end] = true,
  },
  [6] = {
    [ts_external_token__ext_nih_whitespace] = true,
  },
  [7] = {
    [ts_external_token__ext_flag_embed] = true,
    [ts_external_token__ext_node_continue] = true,
  },
  [8] = {
    [ts_external_token__ext_empty_line] = true,
    [ts_external_token__ext_node_continue] = true,
    [ts_external_token__ext_node_begin] = true,
  },
  [9] = {
    [ts_external_token__ext_node_continue] = true,
    [ts_external_token__ext_node_begin] = true,
  },
  [10] = {
    [ts_external_token__ext_flag_node_def] = true,
  },
  [11] = {
    [ts_external_token__ext_node_continue] = true,
  },
  [12] = {
    [ts_external_token__node_metadata_sentinel] = true,
    [ts_external_token__empty_node_sentinel] = true,
  },
  [13] = {
    [ts_external_token__ext_eof] = true,
  },
  [14] = {
    [ts_external_token__empty_node_sentinel] = true,
  },
  [15] = {
    [ts_external_token__ext_node_end] = true,
  },
  [16] = {
    [ts_external_token__ext_eol] = true,
  },
  [17] = {
    [ts_external_token__node_metadata_sentinel] = true,
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
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
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
