#ifndef SIMDJSON_HASWELL_NUMBERPARSING_DEFS_H
#define SIMDJSON_HASWELL_NUMBERPARSING_DEFS_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/haswell/base.h"
#include "simdjson/haswell/intrinsics.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/internal/numberparsing_tables.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace haswell {
namespace numberparsing {

/** @private */
static simdjson_inline uint32_t parse_eight_digits_unrolled(const uint8_t *chars) { __builtin_trap() /* STUB: not implemented */; }

/** @private */
simdjson_inline internal::value128 full_multiplication(uint64_t value1, uint64_t value2) { __builtin_trap() /* STUB: not implemented */; }

} // namespace numberparsing
} // namespace haswell
} // namespace simdjson

#define SIMDJSON_SWAR_NUMBER_PARSING 1

#endif // SIMDJSON_HASWELL_NUMBERPARSING_DEFS_H
