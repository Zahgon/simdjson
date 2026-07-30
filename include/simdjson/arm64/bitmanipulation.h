#ifndef SIMDJSON_ARM64_BITMANIPULATION_H
#define SIMDJSON_ARM64_BITMANIPULATION_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/arm64/base.h"
#include "simdjson/arm64/intrinsics.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace arm64 {
namespace {

// We sometimes call trailing_zero on inputs that are zero,
// but the algorithms do not end up using the returned value.
// Sadly, sanitizers are not smart enough to figure it out.
SIMDJSON_NO_SANITIZE_UNDEFINED
// This function can be used safely even if not all bytes have been
// initialized.
// See issue https://github.com/simdjson/simdjson/issues/1965
SIMDJSON_NO_SANITIZE_MEMORY
simdjson_inline int trailing_zeroes(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }

/* result might be undefined when input_num is zero */
simdjson_inline uint64_t clear_lowest_bit(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }

// We sometimes call leading_zeroes on inputs that are zero,
// but the algorithms do not end up using the returned value.
// Sadly, sanitizers are not smart enough to figure it out.
// Applies only when SIMDJSON_PREFER_REVERSE_BITS is defined and true.
// (See below.)
SIMDJSON_NO_SANITIZE_UNDEFINED
/* result might be undefined when input_num is zero */
simdjson_inline int leading_zeroes(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }

/* result might be undefined when input_num is zero */
simdjson_inline int count_ones(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }


#if defined(__GNUC__) // catches clang and gcc
/**
 * ARM has a fast 64-bit "bit reversal function" that is handy. However,
 * it is not generally available as an intrinsic function under Visual
 * Studio (though this might be changing). Even under clang/gcc, we
 * apparently need to invoke inline assembly.
 */
/*
 * We use SIMDJSON_PREFER_REVERSE_BITS as a hint that algorithms that
 * work well with bit reversal may use it.
 */
#define SIMDJSON_PREFER_REVERSE_BITS 1

/* reverse the bits */
simdjson_inline uint64_t reverse_bits(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }

/**
 * Flips bit at index 63 - lz. Thus if you have 'leading_zeroes' leading zeroes,
 * then this will set to zero the leading bit. It is possible for leading_zeroes to be
 * greating or equal to 63 in which case we trigger undefined behavior, but the output
 * of such undefined behavior is never used.
 **/
SIMDJSON_NO_SANITIZE_UNDEFINED
simdjson_inline uint64_t zero_leading_bit(uint64_t rev_bits, int leading_zeroes) { __builtin_trap() /* STUB: not implemented */; }

#endif

simdjson_inline bool add_overflow(uint64_t value1, uint64_t value2, uint64_t *result) { __builtin_trap() /* STUB: not implemented */; }

} // unnamed namespace
} // namespace arm64
} // namespace simdjson

#endif // SIMDJSON_ARM64_BITMANIPULATION_H
