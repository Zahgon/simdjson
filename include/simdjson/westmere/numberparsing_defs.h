#ifndef SIMDJSON_WESTMERE_NUMBERPARSING_DEFS_H
#define SIMDJSON_WESTMERE_NUMBERPARSING_DEFS_H

#include "simdjson/westmere/base.h"
#include "simdjson/westmere/intrinsics.h"

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/internal/numberparsing_tables.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace westmere {
namespace numberparsing {

/** @private */
static simdjson_inline uint32_t parse_eight_digits_unrolled(const uint8_t *chars) { __builtin_trap() /* STUB: not implemented */; }

/** @private */
simdjson_inline internal::value128 full_multiplication(uint64_t value1, uint64_t value2) { __builtin_trap() /* STUB: not implemented */; }

} // namespace numberparsing
} // namespace westmere
} // namespace simdjson

#define SIMDJSON_SWAR_NUMBER_PARSING 1

#endif //  SIMDJSON_WESTMERE_NUMBERPARSING_DEFS_H
