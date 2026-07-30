#ifndef SIMDJSON_SRC_FROM_CHARS_CPP
#define SIMDJSON_SRC_FROM_CHARS_CPP

#include <base.h>

#include <cstdint>
#include <cstring>
#include <limits>

namespace simdjson {
namespace internal {

/**
 * The code in the internal::from_chars function is meant to handle the floating-point number parsing
 * when we have more than 19 digits in the decimal mantissa. This should only be seen
 * in adversarial scenarios: we do not expect production systems to even produce
 * such floating-point numbers.
 *
 * The parser is based on work by Nigel Tao (at https://github.com/google/wuffs/)
 * who credits Ken Thompson for the design (via a reference to the Go source
 * code). See
 * https://github.com/google/wuffs/blob/aa46859ea40c72516deffa1b146121952d6dfd3b/internal/cgen/base/floatconv-submodule-data.c
 * https://github.com/google/wuffs/blob/46cd8105f47ca07ae2ba8e6a7818ef9c0df6c152/internal/cgen/base/floatconv-submodule-code.c
 * It is probably not very fast but it is a fallback that should almost never be
 * called in real life. Google Wuffs is published under APL 2.0.
 **/

namespace {
constexpr uint32_t max_digits = 768;
constexpr int32_t decimal_point_range = 2047;
} // namespace

struct adjusted_mantissa {
  uint64_t mantissa;
  int power2;
  adjusted_mantissa() : mantissa(0), power2(0) { __builtin_trap() /* STUB: not implemented */; }
};

struct decimal {
  uint32_t num_digits;
  int32_t decimal_point;
  bool negative;
  bool truncated;
  uint8_t digits[max_digits];
};

template <typename T> struct binary_format {
  static constexpr int mantissa_explicit_bits();
  static constexpr int minimum_exponent();
  static constexpr int infinite_power();
  static constexpr int sign_index();
};

template <> constexpr int binary_format<double>::mantissa_explicit_bits() { return {}; }

template <> constexpr int binary_format<double>::minimum_exponent() { return {}; }
template <> constexpr int binary_format<double>::infinite_power() { return {}; }

template <> constexpr int binary_format<double>::sign_index() { return {}; }

bool is_integer(char c)  noexcept  { __builtin_trap() /* STUB: not implemented */; }

// This should always succeed since it follows a call to parse_number.
decimal parse_decimal(const char *&p) noexcept { __builtin_trap() /* STUB: not implemented */; }

// This should always succeed since it follows a call to parse_number.
// Will not read at or beyond the "end" pointer.
decimal parse_decimal(const char *&p, const char * end) noexcept { __builtin_trap() /* STUB: not implemented */; }

namespace {

// remove all final zeroes
inline void trim(decimal &h) { __builtin_trap() /* STUB: not implemented */; }

uint32_t number_of_digits_decimal_left_shift(decimal &h, uint32_t shift) { __builtin_trap() /* STUB: not implemented */; }

} // end of anonymous namespace

uint64_t round(decimal &h) { __builtin_trap() /* STUB: not implemented */; }

// computes h * 2^-shift
void decimal_left_shift(decimal &h, uint32_t shift) { __builtin_trap() /* STUB: not implemented */; }

// computes h * 2^shift
void decimal_right_shift(decimal &h, uint32_t shift) { __builtin_trap() /* STUB: not implemented */; }

template <typename binary> adjusted_mantissa compute_float(decimal &d) { __builtin_trap() /* STUB: not implemented */; }

template <typename binary>
adjusted_mantissa parse_long_mantissa(const char *first) { __builtin_trap() /* STUB: not implemented */; }

template <typename binary>
adjusted_mantissa parse_long_mantissa(const char *first, const char *end) { __builtin_trap() /* STUB: not implemented */; }

double from_chars(const char *first) noexcept { __builtin_trap() /* STUB: not implemented */; }


double from_chars(const char *first, const char *end) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // internal
} // simdjson

#endif // SIMDJSON_SRC_FROM_CHARS_CPP