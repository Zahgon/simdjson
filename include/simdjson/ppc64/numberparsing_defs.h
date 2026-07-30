#ifndef SIMDJSON_PPC64_NUMBERPARSING_DEFS_H
#define SIMDJSON_PPC64_NUMBERPARSING_DEFS_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/ppc64/base.h"
#include "simdjson/ppc64/intrinsics.h"
#include "simdjson/internal/numberparsing_tables.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <cstring>

#if defined(__linux__)
#include <byteswap.h>
#elif defined(__FreeBSD__)
#include <sys/endian.h>
#endif

namespace simdjson {
namespace ppc64 {
namespace numberparsing {

// we don't have appropriate instructions, so let us use a scalar function
// credit: https://johnnylee-sde.github.io/Fast-numeric-string-to-int/
/** @private */
static simdjson_inline uint32_t parse_eight_digits_unrolled(const uint8_t *chars) { __builtin_trap() /* STUB: not implemented */; }

/** @private */
simdjson_inline internal::value128 full_multiplication(uint64_t value1, uint64_t value2) { __builtin_trap() /* STUB: not implemented */; }

} // namespace numberparsing
} // namespace ppc64
} // namespace simdjson

#ifndef SIMDJSON_SWAR_NUMBER_PARSING
#if SIMDJSON_IS_BIG_ENDIAN
#define SIMDJSON_SWAR_NUMBER_PARSING 0
#else
#define SIMDJSON_SWAR_NUMBER_PARSING 1
#endif
#endif

#endif // SIMDJSON_PPC64_NUMBERPARSING_DEFS_H
