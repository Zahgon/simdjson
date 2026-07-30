#ifndef SIMDJSON_GENERIC_JSONCHARUTILS_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_JSONCHARUTILS_H
#include "simdjson/generic/base.h"
#include "simdjson/internal/jsoncharutils_tables.h"
#include "simdjson/internal/numberparsing_tables.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace jsoncharutils {

// return non-zero if not a structural or whitespace char
// zero otherwise
simdjson_inline uint32_t is_not_structural_or_whitespace(uint8_t c) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline uint32_t is_structural_or_whitespace(uint8_t c) { __builtin_trap() /* STUB: not implemented */; }

// returns a value with the high 16 bits set if not valid
// otherwise returns the conversion of the 4 hex digits at src into the bottom
// 16 bits of the 32-bit return register
//
// see
// https://lemire.me/blog/2019/04/17/parsing-short-hexadecimal-strings-efficiently/
static inline uint32_t hex_to_u32_nocheck(
    const uint8_t *src) { __builtin_trap() /* STUB: not implemented */; }

// given a code point cp, writes to c
// the utf-8 code, outputting the length in
// bytes, if the length is zero, the code point
// is invalid
//
// This can possibly be made faster using pdep
// and clz and table lookups, but JSON documents
// have few escaped code points, and the following
// function looks cheap.
//
// Note: we assume that surrogates are treated separately
//
simdjson_inline size_t codepoint_to_utf8(uint32_t cp, uint8_t *c) { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_IS_32BITS // _umul128 for x86, arm
// this is a slow emulation routine for 32-bit
//
static simdjson_inline uint64_t __emulu(uint32_t x, uint32_t y) { __builtin_trap() /* STUB: not implemented */; }
static simdjson_inline uint64_t _umul128(uint64_t ab, uint64_t cd, uint64_t *hi) { __builtin_trap() /* STUB: not implemented */; }
#endif

} // namespace jsoncharutils
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_GENERIC_JSONCHARUTILS_H