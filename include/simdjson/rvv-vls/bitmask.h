#ifndef SIMDJSON_RVV_VLS_BITMASK_H
#define SIMDJSON_RVV_VLS_BITMASK_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/rvv-vls/base.h"
#include "simdjson/rvv-vls/intrinsics.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace rvv_vls {
namespace {

//
// Perform a "cumulative bitwise xor," flipping bits each time a 1 is encountered.
//
// For example, prefix_xor(00100100) == 00011100
//
simdjson_inline uint64_t prefix_xor(uint64_t bitmask) { __builtin_trap() /* STUB: not implemented */; }

} // unnamed namespace
} // namespace rvv_vls
} // namespace simdjson

#endif // SIMDJSON_RVV_VLS_BITMASK_H

