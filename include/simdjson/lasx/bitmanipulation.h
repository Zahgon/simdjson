#ifndef SIMDJSON_LASX_BITMANIPULATION_H
#define SIMDJSON_LASX_BITMANIPULATION_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/lasx/base.h"
#include "simdjson/lasx/intrinsics.h"
#include "simdjson/lasx/bitmask.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace lasx {
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

/* result might be undefined when input_num is zero */
simdjson_inline int leading_zeroes(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }

/* result might be undefined when input_num is zero */
simdjson_inline int count_ones(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool add_overflow(uint64_t value1, uint64_t value2, uint64_t *result) { __builtin_trap() /* STUB: not implemented */; }

} // unnamed namespace
} // namespace lasx
} // namespace simdjson

#endif // SIMDJSON_LASX_BITMANIPULATION_H
