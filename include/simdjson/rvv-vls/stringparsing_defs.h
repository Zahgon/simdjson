#ifndef SIMDJSON_RVV_VLS_STRINGPARSING_DEFS_H
#define SIMDJSON_RVV_VLS_STRINGPARSING_DEFS_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/rvv-vls/base.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace rvv_vls {
namespace {

using namespace simd;

// Holds backslashes and quotes locations.
struct backslash_and_quote {
public:
  static constexpr uint64_t BYTES_PROCESSED = sizeof(simd8<uint8_t>);
  simdjson_inline backslash_and_quote copy_and_find(const uint8_t *src, uint8_t *dst);

  simdjson_inline bool has_quote_first() { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline bool has_backslash() { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline int quote_index() { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline int backslash_index() { __builtin_trap() /* STUB: not implemented */; }

  uint64_t bs_bits;
  uint64_t quote_bits;
}; // struct backslash_and_quote

simdjson_inline backslash_and_quote backslash_and_quote::copy_and_find(const uint8_t *src, uint8_t *dst) { __builtin_trap() /* STUB: not implemented */; }

struct escaping {
  static constexpr uint64_t BYTES_PROCESSED = sizeof(simd8<uint8_t>);
  simdjson_inline static escaping copy_and_find(const uint8_t *src, uint8_t *dst);

  simdjson_inline bool has_escape() { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline int escape_index() { __builtin_trap() /* STUB: not implemented */; }

  uint64_t escape_bits;
}; // struct escaping

simdjson_inline escaping escaping::copy_and_find(const uint8_t *src, uint8_t *dst) { __builtin_trap() /* STUB: not implemented */; }


} // unnamed namespace
} // namespace rvv_vls
} // namespace simdjson

#endif // SIMDJSON_RVV_VLS_STRINGPARSING_DEFS_H
