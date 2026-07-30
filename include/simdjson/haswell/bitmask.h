#ifndef SIMDJSON_HASWELL_BITMASK_H
#define SIMDJSON_HASWELL_BITMASK_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/haswell/base.h"
#include "simdjson/haswell/intrinsics.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace haswell {
namespace {

//
// Perform a "cumulative bitwise xor," flipping bits each time a 1 is encountered.
//
// For example, prefix_xor(00100100) == 00011100
//
simdjson_inline uint64_t prefix_xor(const uint64_t bitmask) { __builtin_trap() /* STUB: not implemented */; }

} // unnamed namespace
} // namespace haswell
} // namespace simdjson

#endif // SIMDJSON_HASWELL_BITMASK_H
