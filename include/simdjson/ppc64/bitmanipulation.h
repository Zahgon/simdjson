#ifndef SIMDJSON_PPC64_BITMANIPULATION_H
#define SIMDJSON_PPC64_BITMANIPULATION_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/ppc64/base.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace ppc64 {
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
simdjson_inline int count_ones(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }
#else
simdjson_inline int count_ones(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }
#endif

simdjson_inline bool add_overflow(uint64_t value1, uint64_t value2,
                                         uint64_t *result) { __builtin_trap() /* STUB: not implemented */; }

} // unnamed namespace
} // namespace ppc64
} // namespace simdjson

#endif // SIMDJSON_PPC64_BITMANIPULATION_H
