#ifndef SIMDJSON_FALLBACK_NUMBERPARSING_DEFS_H
#define SIMDJSON_FALLBACK_NUMBERPARSING_DEFS_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/fallback/base.h"
#include "simdjson/internal/numberparsing_tables.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <cstring>

#ifdef JSON_TEST_NUMBERS // for unit testing
void found_invalid_number(const uint8_t *buf);
void found_integer(int64_t result, const uint8_t *buf);
void found_unsigned_integer(uint64_t result, const uint8_t *buf);
void found_float(double result, const uint8_t *buf);
#endif

namespace simdjson {
namespace fallback {
namespace numberparsing {

// credit: https://johnnylee-sde.github.io/Fast-numeric-string-to-int/
/** @private */
static simdjson_inline uint32_t parse_eight_digits_unrolled(const char *chars) { __builtin_trap() /* STUB: not implemented */; }

/** @private */
static simdjson_inline uint32_t parse_eight_digits_unrolled(const uint8_t *chars) { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_IS_32BITS // _umul128 for x86, arm
// this is a slow emulation routine for 32-bit
//
static simdjson_inline uint64_t __emulu(uint32_t x, uint32_t y) { __builtin_trap() /* STUB: not implemented */; }
static simdjson_inline uint64_t _umul128(uint64_t ab, uint64_t cd, uint64_t *hi) { __builtin_trap() /* STUB: not implemented */; }
#endif

/** @private */
simdjson_inline internal::value128 full_multiplication(uint64_t value1, uint64_t value2) { __builtin_trap() /* STUB: not implemented */; }

} // namespace numberparsing
} // namespace fallback
} // namespace simdjson

#ifndef SIMDJSON_SWAR_NUMBER_PARSING
#if SIMDJSON_IS_BIG_ENDIAN
#define SIMDJSON_SWAR_NUMBER_PARSING 0
#else
#define SIMDJSON_SWAR_NUMBER_PARSING 1
#endif
#endif

#endif // SIMDJSON_FALLBACK_NUMBERPARSING_DEFS_H
