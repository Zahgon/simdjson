#ifndef SIMDJSON_SRC_FALLBACK_CPP
#define SIMDJSON_SRC_FALLBACK_CPP

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include <base.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <simdjson/fallback.h>
#include <simdjson/fallback/implementation.h>

#include <simdjson/fallback/begin.h>
#include <generic/stage1/find_next_document_index.h>
#include <generic/stage2/stringparsing.h>
#include <generic/stage2/logger.h>
#include <generic/stage2/json_iterator.h>
#include <generic/stage2/tape_writer.h>
#include <generic/stage2/tape_builder.h>

//
// Stage 1
//

namespace simdjson {
namespace fallback {

simdjson_warn_unused error_code implementation::create_dom_parser_implementation(
  size_t capacity,
  size_t max_depth,
  std::unique_ptr<internal::dom_parser_implementation>& dst
) const noexcept { __builtin_trap() /* STUB: not implemented */; }

namespace {
namespace stage1 {

class structural_scanner {
public:

simdjson_inline structural_scanner(dom_parser_implementation &_parser, stage1_mode _partial)
  : buf{_parser.buf},
    next_structural_index{_parser.structural_indexes.get()},
    parser{_parser},
    len{static_cast<uint32_t>(_parser.len)},
    partial{_partial} {
}

simdjson_inline void add_structural() {
  *next_structural_index = idx;
  next_structural_index++;
}

simdjson_inline bool is_continuation(uint8_t c) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void validate_utf8_character() { __builtin_trap() /* STUB: not implemented */; }

static const uint8_t CHAR_TYPE_SPACE     = 1 << 0;
static const uint8_t CHAR_TYPE_OPERATOR  = 1 << 1;
static const uint8_t CHAR_TYPE_ESC_ASCII = 1 << 2;
static const uint8_t CHAR_TYPE_NON_ASCII = 1 << 3;

const uint8_t char_table[256] = {
  0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
  0x04, 0x05, 0x05, 0x04, 0x04, 0x05, 0x04, 0x04,
  0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
  0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
  0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x02, 0x04, 0x02, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08
};

simdjson_inline bool char_is_type(uint8_t c, uint8_t type) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool char_is_space(uint8_t c) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool char_is_operator(uint8_t c) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool char_is_space_or_operator(uint8_t c) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool char_is_ascii_stop(uint8_t c) { __builtin_trap() /* STUB: not implemented */; }

// Returns true if the string is unclosed.
simdjson_inline bool validate_string() { __builtin_trap() /* STUB: not implemented */; }

//
// Parse the entire input in STEP_SIZE-byte chunks.
//
simdjson_warn_unused simdjson_inline error_code scan() { __builtin_trap() /* STUB: not implemented */; }

private:
  const uint8_t *buf;
  uint32_t *next_structural_index;
  dom_parser_implementation &parser;
  uint32_t len;
  uint32_t idx{0};
  error_code error{SUCCESS};
  stage1_mode partial;
}; // structural_scanner

} // namespace stage1
} // unnamed namespace

simdjson_warn_unused error_code dom_parser_implementation::stage1(const uint8_t *_buf, size_t _len, stage1_mode partial) noexcept { __builtin_trap() /* STUB: not implemented */; }

// big table for the minifier
static uint8_t jump_table[256 * 3] = {
    0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
    1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
    0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0,
    1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
    0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
    1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
    0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
    1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
    1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
    0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
    1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
    0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
    1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
    0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
    1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
    0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
    1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
    0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
    1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
    0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
    1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
    0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
};

simdjson_warn_unused error_code implementation::minify(const uint8_t *buf, size_t len, uint8_t *dst, size_t &dst_len) const noexcept { __builtin_trap() /* STUB: not implemented */; }

// credit: based on code from Google Fuchsia (Apache Licensed)
simdjson_warn_unused bool implementation::validate_utf8(const char *buf, size_t len) const noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace fallback
} // namespace simdjson

//
// Stage 2
//

namespace simdjson {
namespace fallback {

simdjson_warn_unused error_code dom_parser_implementation::stage2(dom::document &_doc) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused error_code dom_parser_implementation::stage2_next(dom::document &_doc) noexcept { __builtin_trap() /* STUB: not implemented */; }

SIMDJSON_NO_SANITIZE_MEMORY
simdjson_warn_unused uint8_t *dom_parser_implementation::parse_string(const uint8_t *src, uint8_t *dst, bool replacement_char) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused uint8_t *dom_parser_implementation::parse_wobbly_string(const uint8_t *src, uint8_t *dst) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused error_code dom_parser_implementation::parse(const uint8_t *_buf, size_t _len, dom::document &_doc) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace fallback
} // namespace simdjson

#include <simdjson/fallback/end.h>

#endif // SIMDJSON_SRC_FALLBACK_CPP
