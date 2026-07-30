#ifndef SIMDJSON_RVV_VLS_NUMBERPARSING_DEFS_H
#define SIMDJSON_RVV_VLS_NUMBERPARSING_DEFS_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/rvv-vls/base.h"
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
namespace rvv_vls {
namespace numberparsing {

// credit: https://johnnylee-sde.github.io/Fast-numeric-string-to-int/
/** @private */
static simdjson_inline uint32_t parse_eight_digits_unrolled(const char *chars) { __builtin_trap() /* STUB: not implemented */; }

/** @private */
static simdjson_inline uint32_t parse_eight_digits_unrolled(const uint8_t *chars) { __builtin_trap() /* STUB: not implemented */; }

/** @private */
simdjson_inline internal::value128 full_multiplication(uint64_t value1, uint64_t value2) { __builtin_trap() /* STUB: not implemented */; }

} // namespace numberparsing
} // namespace rvv_vls
} // namespace simdjson

#define SIMDJSON_SWAR_NUMBER_PARSING 1

#endif // SIMDJSON_RVV_VLS_NUMBERPARSING_DEFS_H
