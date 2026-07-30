#ifndef SIMDJSON_GENERIC_ATOMPARSING_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ATOMPARSING_H
#include "simdjson/generic/base.h"
#include "simdjson/generic/jsoncharutils.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <cstring>

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
/// @private
namespace atomparsing {

// The string_to_uint32 is exclusively used to map literal strings to 32-bit values.
// We use memcpy instead of a pointer cast to avoid undefined behaviors since we cannot
// be certain that the character pointer will be properly aligned.
// You might think that using memcpy makes this function expensive, but you'd be wrong.
// All decent optimizing compilers (GCC, clang, Visual Studio) will compile string_to_uint32("false");
// to the compile-time constant 1936482662.
simdjson_inline uint32_t string_to_uint32(const char* str) { __builtin_trap() /* STUB: not implemented */; }

// Acts on the same principle as string_to_uint32, but on an 8-byte block of memory
simdjson_inline uint64_t string_to_uint64(const char* str) { __builtin_trap() /* STUB: not implemented */; }


// Again in str4ncmp we use a memcpy to avoid undefined behavior. The memcpy may appear expensive.
// Yet all decent optimizing compilers will compile memcpy to a single instruction, just about.
simdjson_warn_unused
simdjson_inline uint32_t str4ncmp(const uint8_t *src, const char* atom) { __builtin_trap() /* STUB: not implemented */; }

// Checks that the first 8 characters of the input string match the given atom in a case-insensitive manner.
//
// 'atom' must consist of only lowercase letters.
simdjson_warn_unused
simdjson_inline uint64_t str8ncmp_case_insensitive(const uint8_t *src, const char* atom) { __builtin_trap() /* STUB: not implemented */; }

// Checks that the first 3 characters of 'src' match 'atom' in a case-insensitive way.
//
// 'atom' must consist of only lowercase letters.
simdjson_warn_unused
simdjson_inline uint32_t str3ncmp_case_insensitive(const uint8_t *src, const char* atom) { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused
simdjson_inline bool is_valid_true_atom(const uint8_t *src) { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused
simdjson_inline bool is_valid_true_atom(const uint8_t *src, size_t len) { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused
simdjson_inline bool is_valid_false_atom(const uint8_t *src) { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused
simdjson_inline bool is_valid_false_atom(const uint8_t *src, size_t len) { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused
simdjson_inline bool is_valid_null_atom(const uint8_t *src) { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused
simdjson_inline bool is_valid_null_atom(const uint8_t *src, size_t len) { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_ENABLE_NAN_INF
// "nan" is 3 bytes; we check characters and then verify the next
// character is structural or whitespace. We accept both "nan" and "NaN".
simdjson_warn_unused
simdjson_inline bool is_valid_nan_atom(const uint8_t *src) { __builtin_trap() /* STUB: not implemented */; }

// checks that the next four characters of a string are 'nan"', where the 'nan'
// is checked in a case-insensitive way.
simdjson_warn_unused
simdjson_inline bool is_valid_nan_in_string(const uint8_t *src) { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused
simdjson_inline bool is_valid_nan_atom(const uint8_t *src, size_t len) { __builtin_trap() /* STUB: not implemented */; }

// This function will accept any case-insensitive 3-character spelling of
// infinity: 'inf', 'INF', and 'Inf' are all accepted.
//
// Any capitalization of 'infinity' is also accepted.
simdjson_warn_unused
simdjson_inline bool is_valid_inf_atom(const uint8_t *src) { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused
simdjson_inline bool is_valid_inf_in_string(const uint8_t *src) { __builtin_trap() /* STUB: not implemented */; }


// This function will accept any case-insensitive 3-character spelling of
// infinity: 'inf', 'INF', and 'Inf' are all accepted.
//
// Any capitalization of 'infinity' is also accepted.
simdjson_warn_unused
simdjson_inline bool is_valid_inf_atom(const uint8_t *src, size_t len) { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_ENABLE_NAN_INF

} // namespace atomparsing
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_GENERIC_ATOMPARSING_H
