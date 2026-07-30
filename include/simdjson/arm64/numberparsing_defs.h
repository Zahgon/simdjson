#ifndef SIMDJSON_ARM64_NUMBERPARSING_DEFS_H
#define SIMDJSON_ARM64_NUMBERPARSING_DEFS_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/arm64/base.h"
#include "simdjson/arm64/intrinsics.h"
#include "simdjson/internal/numberparsing_tables.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <cstring>

#if SIMDJSON_REGULAR_VISUAL_STUDIO && SIMDJSON_IS_ARM64
// __umulh requires intrin.h
#include <intrin.h>
#endif // SIMDJSON_REGULAR_VISUAL_STUDIO && SIMDJSON_IS_ARM64

namespace simdjson {
namespace arm64 {
namespace numberparsing {

// we don't have SSE, so let us use a scalar function
// credit: https://johnnylee-sde.github.io/Fast-numeric-string-to-int/
/** @private */
static simdjson_inline uint32_t parse_eight_digits_unrolled(const uint8_t *chars) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline internal::value128 full_multiplication(uint64_t value1, uint64_t value2) { __builtin_trap() /* STUB: not implemented */; }

} // namespace numberparsing
} // namespace arm64
} // namespace simdjson

#ifndef SIMDJSON_SWAR_NUMBER_PARSING
#if SIMDJSON_IS_BIG_ENDIAN
#define SIMDJSON_SWAR_NUMBER_PARSING 0
#else
#define SIMDJSON_SWAR_NUMBER_PARSING 1
#endif
#endif

#endif // SIMDJSON_ARM64_NUMBERPARSING_DEFS_H
