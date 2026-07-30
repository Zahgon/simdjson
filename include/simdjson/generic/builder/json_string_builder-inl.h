#include <array>
#include <cmath>
#include <cstring>
#include <limits>
#include <type_traits>
#ifndef SIMDJSON_GENERIC_STRING_BUILDER_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_STRING_BUILDER_INL_H
#include "simdjson/generic/builder/json_string_builder.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

/*
 * Empirically, we have found that an inlined optimization is important for
 * performance. The following macros are not ideal. We should find a better
 * way to inline the code.
 */

#if defined(__SSE2__) || defined(__x86_64__) || defined(__x86_64) ||           \
    (defined(_M_AMD64) || defined(_M_X64) ||                                   \
     (defined(_M_IX86_FP) && _M_IX86_FP == 2))
#ifndef SIMDJSON_EXPERIMENTAL_HAS_SSE2
#define SIMDJSON_EXPERIMENTAL_HAS_SSE2 1
#endif
#endif

#if defined(__aarch64__) || defined(_M_ARM64)
#ifndef SIMDJSON_EXPERIMENTAL_HAS_NEON
#define SIMDJSON_EXPERIMENTAL_HAS_NEON 1
#endif
#endif
#if defined(__loongarch_sx)
#ifndef SIMDJSON_EXPERIMENTAL_HAS_LSX
#define SIMDJSON_EXPERIMENTAL_HAS_LSX 1
#endif
#endif
#if defined(__loongarch_asx)
#ifndef SIMDJSON_EXPERIMENTAL_HAS_LASX
#define SIMDJSON_EXPERIMENTAL_HAS_LASX 1
#endif
#endif
#if defined(__riscv_v_intrinsic) && __riscv_v_intrinsic >= 11000 &&            \
    defined(__riscv_vector)
#ifndef SIMDJSON_EXPERIMENTAL_HAS_RVV
#define SIMDJSON_EXPERIMENTAL_HAS_RVV 1
#endif
#endif
#if (defined(__PPC64__) || defined(_M_PPC64)) && defined(__ALTIVEC__)
#ifndef SIMDJSON_EXPERIMENTAL_HAS_PPC64
#define SIMDJSON_EXPERIMENTAL_HAS_PPC64 1
#endif
#endif
#if SIMDJSON_EXPERIMENTAL_HAS_NEON
#include <arm_neon.h>
#ifdef _MSC_VER
#include <intrin.h>
#endif
#endif
#if SIMDJSON_EXPERIMENTAL_HAS_SSE2
#include <emmintrin.h>
#ifdef _MSC_VER
#include <intrin.h>
#endif
#endif
#if SIMDJSON_EXPERIMENTAL_HAS_LSX
#include <lsxintrin.h>
#endif
#if SIMDJSON_EXPERIMENTAL_HAS_LASX
#include <lasxintrin.h>
#endif
#if SIMDJSON_EXPERIMENTAL_HAS_RVV
#include <riscv_vector.h>
#endif
#if SIMDJSON_EXPERIMENTAL_HAS_PPC64
#include <altivec.h>
#ifdef bool
#undef bool
#endif
#ifdef vector
#undef vector
#endif
#endif


namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace builder {

static SIMDJSON_CONSTEXPR_LAMBDA std::array<uint8_t, 256>
    json_quotable_character = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/**

A possible SWAR implementation of has_json_escapable_byte. It is not used
because it is slower than the current implementation. It is kept here for
reference (to show that we tried it).

inline bool has_json_escapable_byte(uint64_t x) {
  uint64_t is_ascii = 0x8080808080808080ULL & ~x;
  uint64_t xor2 = x ^ 0x0202020202020202ULL;
  uint64_t lt32_or_eq34 = xor2 - 0x2121212121212121ULL;
  uint64_t sub92 = x ^ 0x5C5C5C5C5C5C5C5CULL;
  uint64_t eq92 = (sub92 - 0x0101010101010101ULL);
  return ((lt32_or_eq34 | eq92) & is_ascii) != 0;
}

**/

SIMDJSON_CONSTEXPR_LAMBDA simdjson_inline bool
simple_needs_escaping(std::string_view v) { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXPERIMENTAL_HAS_NEON
simdjson_inline bool fast_needs_escaping(std::string_view view) { __builtin_trap() /* STUB: not implemented */; }
#elif SIMDJSON_EXPERIMENTAL_HAS_SSE2
simdjson_inline bool fast_needs_escaping(std::string_view view) { __builtin_trap() /* STUB: not implemented */; }
#elif SIMDJSON_EXPERIMENTAL_HAS_LASX
simdjson_inline bool fast_needs_escaping(std::string_view view) { __builtin_trap() /* STUB: not implemented */; }
#elif SIMDJSON_EXPERIMENTAL_HAS_LSX
simdjson_inline bool fast_needs_escaping(std::string_view view) { __builtin_trap() /* STUB: not implemented */; }
#elif SIMDJSON_EXPERIMENTAL_HAS_PPC64
simdjson_inline bool fast_needs_escaping(std::string_view view) { __builtin_trap() /* STUB: not implemented */; }
#else
simdjson_inline bool fast_needs_escaping(std::string_view view) { __builtin_trap() /* STUB: not implemented */; }
#endif

// Scalar fallback for finding next quotable character
SIMDJSON_CONSTEXPR_LAMBDA simdjson_inline size_t
find_next_json_quotable_character_scalar(const std::string_view view,
                                         size_t location) noexcept { __builtin_trap() /* STUB: not implemented */; }

// SIMD-accelerated position finding that directly locates the first quotable
// character, combining detection and position extraction in a single pass to
// minimize redundant work.
#if SIMDJSON_EXPERIMENTAL_HAS_NEON
simdjson_inline size_t
find_next_json_quotable_character(const std::string_view view,
                                  size_t location) noexcept { __builtin_trap() /* STUB: not implemented */; }
#elif SIMDJSON_EXPERIMENTAL_HAS_SSE2
simdjson_inline size_t
find_next_json_quotable_character(const std::string_view view,
                                  size_t location) noexcept { __builtin_trap() /* STUB: not implemented */; }
#elif SIMDJSON_EXPERIMENTAL_HAS_LASX
simdjson_inline size_t
find_next_json_quotable_character(const std::string_view view,
                                  size_t location) noexcept { __builtin_trap() /* STUB: not implemented */; }
#elif SIMDJSON_EXPERIMENTAL_HAS_LSX
simdjson_inline size_t
find_next_json_quotable_character(const std::string_view view,
                                  size_t location) noexcept { __builtin_trap() /* STUB: not implemented */; }
#elif SIMDJSON_EXPERIMENTAL_HAS_RVV
simdjson_inline size_t
find_next_json_quotable_character(const std::string_view view,
                                  size_t location) noexcept { __builtin_trap() /* STUB: not implemented */; }
#elif SIMDJSON_EXPERIMENTAL_HAS_PPC64
simdjson_inline size_t
find_next_json_quotable_character(const std::string_view view,
                                  size_t location) noexcept { __builtin_trap() /* STUB: not implemented */; }
#else
SIMDJSON_CONSTEXPR_LAMBDA simdjson_inline size_t
find_next_json_quotable_character(const std::string_view view,
                                  size_t location) noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif

SIMDJSON_CONSTEXPR_LAMBDA static std::string_view control_chars[] = {
    "\\u0000", "\\u0001", "\\u0002", "\\u0003", "\\u0004", "\\u0005", "\\u0006",
    "\\u0007", "\\b",     "\\t",     "\\n",     "\\u000b", "\\f",     "\\r",
    "\\u000e", "\\u000f", "\\u0010", "\\u0011", "\\u0012", "\\u0013", "\\u0014",
    "\\u0015", "\\u0016", "\\u0017", "\\u0018", "\\u0019", "\\u001a", "\\u001b",
    "\\u001c", "\\u001d", "\\u001e", "\\u001f"};

// All Unicode characters may be placed within the quotation marks, except for
// the characters that MUST be escaped: quotation mark, reverse solidus, and the
// control characters (U+0000 through U+001F). There are two-character sequence
// escape representations of some popular characters:
// \", \\, \b, \f, \n, \r, \t.
SIMDJSON_CONSTEXPR_LAMBDA simdjson_inline void escape_json_char(char c, char *&out) { __builtin_trap() /* STUB: not implemented */; }

// Writes the escaped version of input to out, returning the number of bytes
// written. Uses SIMD position finding to locate quotable characters efficiently.
inline size_t write_string_escaped(const std::string_view input, char *out) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline string_builder::string_builder(size_t initial_capacity)
    : buffer(new(std::nothrow) char[initial_capacity]), position(0),
      capacity(buffer.get() != nullptr ? initial_capacity : 0),
      is_valid(buffer.get() != nullptr) {}

simdjson_inline bool string_builder::capacity_check(size_t upcoming_bytes) { __builtin_trap() /* STUB: not implemented */; }

inline void string_builder::grow_buffer(size_t desired_capacity) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void string_builder::set_valid(bool valid) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline size_t string_builder::size() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void string_builder::append(char c) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void string_builder::append_null() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void string_builder::clear() noexcept { __builtin_trap() /* STUB: not implemented */; }

namespace internal {

static const char decimal_table[200] = {
    0x30, 0x30, 0x30, 0x31, 0x30, 0x32, 0x30, 0x33, 0x30, 0x34, 0x30, 0x35,
    0x30, 0x36, 0x30, 0x37, 0x30, 0x38, 0x30, 0x39, 0x31, 0x30, 0x31, 0x31,
    0x31, 0x32, 0x31, 0x33, 0x31, 0x34, 0x31, 0x35, 0x31, 0x36, 0x31, 0x37,
    0x31, 0x38, 0x31, 0x39, 0x32, 0x30, 0x32, 0x31, 0x32, 0x32, 0x32, 0x33,
    0x32, 0x34, 0x32, 0x35, 0x32, 0x36, 0x32, 0x37, 0x32, 0x38, 0x32, 0x39,
    0x33, 0x30, 0x33, 0x31, 0x33, 0x32, 0x33, 0x33, 0x33, 0x34, 0x33, 0x35,
    0x33, 0x36, 0x33, 0x37, 0x33, 0x38, 0x33, 0x39, 0x34, 0x30, 0x34, 0x31,
    0x34, 0x32, 0x34, 0x33, 0x34, 0x34, 0x34, 0x35, 0x34, 0x36, 0x34, 0x37,
    0x34, 0x38, 0x34, 0x39, 0x35, 0x30, 0x35, 0x31, 0x35, 0x32, 0x35, 0x33,
    0x35, 0x34, 0x35, 0x35, 0x35, 0x36, 0x35, 0x37, 0x35, 0x38, 0x35, 0x39,
    0x36, 0x30, 0x36, 0x31, 0x36, 0x32, 0x36, 0x33, 0x36, 0x34, 0x36, 0x35,
    0x36, 0x36, 0x36, 0x37, 0x36, 0x38, 0x36, 0x39, 0x37, 0x30, 0x37, 0x31,
    0x37, 0x32, 0x37, 0x33, 0x37, 0x34, 0x37, 0x35, 0x37, 0x36, 0x37, 0x37,
    0x37, 0x38, 0x37, 0x39, 0x38, 0x30, 0x38, 0x31, 0x38, 0x32, 0x38, 0x33,
    0x38, 0x34, 0x38, 0x35, 0x38, 0x36, 0x38, 0x37, 0x38, 0x38, 0x38, 0x39,
    0x39, 0x30, 0x39, 0x31, 0x39, 0x32, 0x39, 0x33, 0x39, 0x34, 0x39, 0x35,
    0x39, 0x36, 0x39, 0x37, 0x39, 0x38, 0x39, 0x39,
};

// Forward unsigned-int writer (cascade-on-magnitude, no upfront digit_count).
// Built from a non-recursive DAG of always_inline helpers — gcc and MSVC
// refuse to inline recursive `always_inline`/`__forceinline` functions.
// Caller must guarantee at least 20 bytes available at p. All helpers
// return pointer past the last digit written.

// Caller guarantees v < 100. Writes 1-2 digits.
simdjson_really_inline char* write_lt100(char* p, uint64_t v) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Caller guarantees v < 10000. Writes 1-4 digits.
simdjson_really_inline char* write_lt10000(char* p, uint64_t v) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Caller guarantees v < 10000. Always writes exactly 4 digits.
simdjson_really_inline void write_4_digits(char* p, uint64_t v) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Caller guarantees v < 10^8. Writes 1-8 digits.
simdjson_really_inline char* write_lt1e8(char* p, uint64_t v) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_really_inline char* write_uint_jeaiii(char* p, uint64_t v) noexcept { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal

template <typename number_type, typename>
simdjson_inline void string_builder::append(number_type v) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void
string_builder::escape_and_append(std::string_view input) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void
string_builder::escape_and_append_with_quotes(std::string_view input) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void
string_builder::escape_and_append_with_quotes(char input) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void
string_builder::escape_and_append_with_quotes(const char *input) noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_SUPPORTS_CONCEPTS
template <constevalutil::fixed_string key>
simdjson_inline void string_builder::escape_and_append_with_quotes() noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif

simdjson_inline void string_builder::append_raw(const char *c) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void
string_builder::append_raw(std::string_view input) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void string_builder::append_raw(const char *str,
                                                size_t len) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <size_t N>
simdjson_inline void string_builder::append_raw_n(const char *str) noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_SUPPORTS_CONCEPTS
// Support for optional types (std::optional, etc.)
template <concepts::optional_type T>
  requires(!require_custom_serialization<T>)
simdjson_inline void string_builder::append(const T &opt) { __builtin_trap() /* STUB: not implemented */; }

template <typename T>
  requires(require_custom_serialization<T>)
simdjson_inline void string_builder::append(T &&val) { __builtin_trap() /* STUB: not implemented */; }

template <typename T>
  requires(std::is_convertible<T, std::string_view>::value ||
           std::is_same<T, const char *>::value)
simdjson_inline void string_builder::append(const T &value) { __builtin_trap() /* STUB: not implemented */; }
#endif

#if SIMDJSON_SUPPORTS_RANGES && SIMDJSON_SUPPORTS_CONCEPTS
// Support for range-based appending (std::ranges::view, etc.)
template <std::ranges::range R>
  requires(!std::is_convertible<R, std::string_view>::value && !concepts::optional_type<R> && !require_custom_serialization<R>)
simdjson_inline void string_builder::append(const R &range) noexcept { __builtin_trap() /* STUB: not implemented */; }

#endif

#if SIMDJSON_EXCEPTIONS
simdjson_inline string_builder::operator std::string() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline string_builder::operator std::string_view() const
    noexcept(false) simdjson_lifetime_bound { __builtin_trap() /* STUB: not implemented */; }
#endif

simdjson_inline simdjson_result<std::string_view>
string_builder::view() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<const char *> string_builder::c_str() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool string_builder::validate_unicode() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void string_builder::start_object() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void string_builder::end_object() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void string_builder::start_array() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void string_builder::end_array() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void string_builder::append_comma() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void string_builder::append_colon() noexcept { __builtin_trap() /* STUB: not implemented */; }

template <typename key_type, typename value_type>
simdjson_inline void
string_builder::append_key_value(key_type key, value_type value) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS
template <constevalutil::fixed_string key, typename value_type>
simdjson_inline void
string_builder::append_key_value(value_type value) noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif

} // namespace builder
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_GENERIC_STRING_BUILDER_INL_H
