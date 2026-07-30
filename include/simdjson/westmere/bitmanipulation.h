#ifndef SIMDJSON_WESTMERE_BITMANIPULATION_H
#define SIMDJSON_WESTMERE_BITMANIPULATION_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/westmere/base.h"
#include "simdjson/westmere/intrinsics.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace westmere {
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

#if SIMDJSON_REGULAR_VISUAL_STUDIO
simdjson_inline unsigned __int64 count_ones(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }
#else
simdjson_inline long long int count_ones(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }
#endif

simdjson_inline bool add_overflow(uint64_t value1, uint64_t value2,
                                uint64_t *result) { __builtin_trap() /* STUB: not implemented */; }

} // unnamed namespace
} // namespace westmere
} // namespace simdjson

#endif // SIMDJSON_WESTMERE_BITMANIPULATION_H
