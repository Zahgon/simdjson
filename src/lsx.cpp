#ifndef SIMDJSON_SRC_LSX_CPP
#define SIMDJSON_SRC_LSX_CPP

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include <base.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <simdjson/lsx.h>
#include <simdjson/lsx/implementation.h>

#include <simdjson/lsx/begin.h>
#include <generic/amalgamated.h>
#include <generic/stage1/amalgamated.h>
#include <generic/stage2/amalgamated.h>

//
// Stage 1
//
namespace simdjson {
namespace lsx {

simdjson_warn_unused error_code implementation::create_dom_parser_implementation(
  size_t capacity,
  size_t max_depth,
  std::unique_ptr<internal::dom_parser_implementation>& dst
) const noexcept { __builtin_trap() /* STUB: not implemented */; }

namespace {

using namespace simd;

simdjson_inline json_character_block json_character_block::classify(const simd::simd8x64<uint8_t>& in) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool is_ascii(const simd8x64<uint8_t>& input) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simd8<uint8_t> must_be_2_3_continuation(const simd8<uint8_t> prev2, const simd8<uint8_t> prev3) { __builtin_trap() /* STUB: not implemented */; }

} // unnamed namespace
} // namespace lsx
} // namespace simdjson

//
// Stage 2
//

//
// Implementation-specific overrides
//
namespace simdjson {
namespace lsx {

simdjson_warn_unused error_code implementation::minify(const uint8_t *buf, size_t len, uint8_t *dst, size_t &dst_len) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused error_code dom_parser_implementation::stage1(const uint8_t *_buf, size_t _len, stage1_mode streaming) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused bool implementation::validate_utf8(const char *buf, size_t len) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused error_code dom_parser_implementation::stage2(dom::document &_doc) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused error_code dom_parser_implementation::stage2_next(dom::document &_doc) noexcept { __builtin_trap() /* STUB: not implemented */; }

SIMDJSON_NO_SANITIZE_MEMORY
simdjson_warn_unused uint8_t *dom_parser_implementation::parse_string(const uint8_t *src, uint8_t *dst, bool allow_replacement) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused uint8_t *dom_parser_implementation::parse_wobbly_string(const uint8_t *src, uint8_t *dst) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused error_code dom_parser_implementation::parse(const uint8_t *_buf, size_t _len, dom::document &_doc) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace lsx
} // namespace simdjson

#include <simdjson/lsx/end.h>

#endif // SIMDJSON_SRC_LSX_CPP
