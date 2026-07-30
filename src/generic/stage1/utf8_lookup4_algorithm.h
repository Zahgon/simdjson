#ifndef SIMDJSON_SRC_GENERIC_STAGE1_UTF8_LOOKUP4_ALGORITHM_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE1_UTF8_LOOKUP4_ALGORITHM_H
#include <generic/stage1/base.h>
#include <generic/dom_parser_implementation.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace utf8_validation {

using namespace simd;

  simdjson_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) { __builtin_trap() /* STUB: not implemented */; }

  //
  // Return nonzero if there are incomplete multibyte characters at the end of the block:
  // e.g. if there is a 4-byte character, but it's 3 bytes from the end.
  //
  simdjson_inline simd8<uint8_t> is_incomplete(const simd8<uint8_t> input) { __builtin_trap() /* STUB: not implemented */; }

  struct utf8_checker {
    // If this is nonzero, there has been a UTF-8 error.
    simd8<uint8_t> error;
    // The last input we received
    simd8<uint8_t> prev_input_block;
    // Whether the last input we received was incomplete (used for ASCII fast path)
    simd8<uint8_t> prev_incomplete;

    //
    // Check whether the current bytes are valid UTF-8.
    //
    simdjson_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) { __builtin_trap() /* STUB: not implemented */; }

    // The only problem that can happen at EOF is that a multibyte character is too short
    // or a byte value too large in the last bytes: check_special_cases only checks for bytes
    // too large in the first of two bytes.
    simdjson_inline void check_eof() { __builtin_trap() /* STUB: not implemented */; }

    simdjson_inline void check_next_input(const simd8x64<uint8_t>& input) { __builtin_trap() /* STUB: not implemented */; }
    // do not forget to call check_eof!
    simdjson_warn_unused simdjson_inline error_code errors() { __builtin_trap() /* STUB: not implemented */; }

  }; // struct utf8_checker
} // namespace utf8_validation

} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SRC_GENERIC_STAGE1_UTF8_LOOKUP4_ALGORITHM_H
