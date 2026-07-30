#ifndef SIMDJSON_FALLBACK_BITMANIPULATION_H
#define SIMDJSON_FALLBACK_BITMANIPULATION_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/fallback/base.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace fallback {
namespace {

#if defined(_MSC_VER) && !defined(_M_ARM64) && !defined(_M_X64)
static inline unsigned char _BitScanForward64(unsigned long* ret, uint64_t x) { __builtin_trap() /* STUB: not implemented */; }
static unsigned char _BitScanReverse64(unsigned long* ret, uint64_t x) { __builtin_trap() /* STUB: not implemented */; }
#endif

/* result might be undefined when input_num is zero */
simdjson_inline int leading_zeroes(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline int trailing_zeroes(uint64_t input_num) { __builtin_trap() /* STUB: not implemented */; }

} // unnamed namespace
} // namespace fallback
} // namespace simdjson

#endif // SIMDJSON_FALLBACK_BITMANIPULATION_H
