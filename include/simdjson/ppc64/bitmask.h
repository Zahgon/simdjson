#ifndef SIMDJSON_PPC64_BITMASK_H
#define SIMDJSON_PPC64_BITMASK_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/ppc64/base.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace ppc64 {
namespace {

//
// Perform a "cumulative bitwise xor," flipping bits each time a 1 is
// encountered.
//
// For example, prefix_xor(00100100) == 00011100
//
simdjson_inline uint64_t prefix_xor(uint64_t bitmask) { __builtin_trap() /* STUB: not implemented */; }

} // unnamed namespace
} // namespace ppc64
} // namespace simdjson

#endif
