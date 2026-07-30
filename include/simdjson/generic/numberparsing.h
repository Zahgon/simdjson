#ifndef SIMDJSON_GENERIC_NUMBERPARSING_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_NUMBERPARSING_H
#include "simdjson/generic/base.h"
#include "simdjson/generic/jsoncharutils.h"
#include "simdjson/generic/atomparsing.h"
#include "simdjson/internal/numberparsing_tables.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <limits>
#include <ostream>
#include <cstring>

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace numberparsing {

#ifdef JSON_TEST_NUMBERS
#define INVALID_NUMBER(SRC) (found_invalid_number((SRC)), NUMBER_ERROR)
#define WRITE_INTEGER(VALUE, SRC, WRITER) (found_integer((VALUE), (SRC)), (WRITER).append_s64((VALUE)))
#define WRITE_UNSIGNED(VALUE, SRC, WRITER) (found_unsigned_integer((VALUE), (SRC)), (WRITER).append_u64((VALUE)))
#define WRITE_DOUBLE(VALUE, SRC, WRITER) (found_float((VALUE), (SRC)), (WRITER).append_double((VALUE)))
#define BIGINT_NUMBER(SRC) (found_invalid_number((SRC)), BIGINT_ERROR)
#else
#define INVALID_NUMBER(SRC) (NUMBER_ERROR)
#define WRITE_INTEGER(VALUE, SRC, WRITER) (WRITER).append_s64((VALUE))
#define WRITE_UNSIGNED(VALUE, SRC, WRITER) (WRITER).append_u64((VALUE))
#define WRITE_DOUBLE(VALUE, SRC, WRITER) (WRITER).append_double((VALUE))
#define BIGINT_NUMBER(SRC) (BIGINT_ERROR)
#endif

namespace {

// Convert a mantissa, an exponent and a sign bit into an ieee64 double.
// The real_exponent needs to be in [0, 2046] (technically real_exponent = 2047 would be acceptable).
// The mantissa should be in [0,1<<53). The bit at index (1ULL << 52) while be zeroed.
simdjson_inline double to_double(uint64_t mantissa, uint64_t real_exponent, bool negative) { __builtin_trap() /* STUB: not implemented */; }

// Attempts to compute i * 10^(power) exactly; and if "negative" is
// true, negate the result.
// This function will only work in some cases, when it does not work, success is
// set to false. This should work *most of the time* (like 99% of the time).
// We assume that power is in the [smallest_power,
// largest_power] interval: the caller is responsible for this check.
simdjson_inline bool compute_float_64(int64_t power, uint64_t i, bool negative, double &d) { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_ENABLE_NAN_INF
// Parses a nan or infinity. Returns true on success, false on failure.
simdjson_unused simdjson_inline bool compute_nan_inf(const uint8_t* src, bool negative, double& d) noexcept {
  if (atomparsing::is_valid_inf_atom(src)) {
    double inf = std::numeric_limits<double>::infinity();
    d = negative ? -inf : inf;
    return true;
  }

  if (atomparsing::is_valid_nan_atom(src)) {
    d = std::numeric_limits<double>::quiet_NaN();
    return true;
  }

  return false;
}
#endif

// We call a fallback floating-point parser that might be slow. Note
// it will accept JSON numbers, but the JSON spec. is more restrictive so
// before you call parse_float_fallback, you need to have validated the input
// string with the JSON grammar.
// It will return an error (false) if the parsed number is infinite.
// The string parsing itself always succeeds. We know that there is at least
// one digit.
static bool parse_float_fallback(const uint8_t *ptr, double *outDouble) {
  *outDouble = simdjson::internal::from_chars(reinterpret_cast<const char *>(ptr));
  // We do not accept infinite values.

  // Detecting finite values in a portable manner is ridiculously hard, ideally
  // we would want to do:
  // return !std::isfinite(*outDouble);
  // but that mysteriously fails under legacy/old libc++ libraries, see
  // https://github.com/simdjson/simdjson/issues/1286
  //
  // Therefore, fall back to this solution (the extra parens are there
  // to handle that max may be a macro on windows).
  return !(*outDouble > (std::numeric_limits<double>::max)() || *outDouble < std::numeric_limits<double>::lowest());
}

static bool parse_float_fallback(const uint8_t *ptr, const uint8_t *end_ptr, double *outDouble) {
  *outDouble = simdjson::internal::from_chars(reinterpret_cast<const char *>(ptr), reinterpret_cast<const char *>(end_ptr));
  // We do not accept infinite values.

  // Detecting finite values in a portable manner is ridiculously hard, ideally
  // we would want to do:
  // return !std::isfinite(*outDouble);
  // but that mysteriously fails under legacy/old libc++ libraries, see
  // https://github.com/simdjson/simdjson/issues/1286
  //
  // Therefore, fall back to this solution (the extra parens are there
  // to handle that max may be a macro on windows).
  return !(*outDouble > (std::numeric_limits<double>::max)() || *outDouble < std::numeric_limits<double>::lowest());
}

// check quickly whether the next 8 chars are made of digits
// at a glance, it looks better than Mula's
// http://0x80.pl/articles/swar-digits-validate.html
simdjson_inline bool is_made_of_eight_digits_fast(const uint8_t *chars) {
  uint64_t val;
  // this can read up to 7 bytes beyond the buffer size, but we require
  // SIMDJSON_PADDING of padding
  static_assert(7 <= SIMDJSON_PADDING, "SIMDJSON_PADDING must be bigger than 7");
  std::memcpy(&val, chars, 8);
  // a branchy method might be faster:
  // return (( val & 0xF0F0F0F0F0F0F0F0 ) == 0x3030303030303030)
  //  && (( (val + 0x0606060606060606) & 0xF0F0F0F0F0F0F0F0 ) ==
  //  0x3030303030303030);
  return (((val & 0xF0F0F0F0F0F0F0F0) |
           (((val + 0x0606060606060606) & 0xF0F0F0F0F0F0F0F0) >> 4)) ==
          0x3333333333333333);
}

template<typename I>
SIMDJSON_NO_SANITIZE_UNDEFINED // We deliberately allow overflow here and check later
simdjson_inline bool parse_digit(const uint8_t c, I &i) {
  const uint8_t digit = static_cast<uint8_t>(c - '0');
  if (digit > 9) {
    return false;
  }
  // PERF NOTE: multiplication by 10 is cheaper than arbitrary integer multiplication
  i = 10 * i + digit; // might overflow, we will handle the overflow later
  return true;
}

simdjson_inline bool is_digit(const uint8_t c) {
  return static_cast<uint8_t>(c - '0') <= 9;
}

simdjson_warn_unused simdjson_inline error_code parse_decimal_after_separator(simdjson_unused const uint8_t *const src, const uint8_t *&p, uint64_t &i, int64_t &exponent) {
  // we continue with the fiction that we have an integer. If the
  // floating point number is representable as x * 10^z for some integer
  // z that fits in 53 bits, then we will be able to convert back the
  // the integer into a float in a lossless manner.
  const uint8_t *const first_after_period = p;

#ifdef SIMDJSON_SWAR_NUMBER_PARSING
#if SIMDJSON_SWAR_NUMBER_PARSING
  // this helps if we have lots of decimals!
  // this turns out to be frequent enough.
  if (is_made_of_eight_digits_fast(p)) {
    i = i * 100000000 + parse_eight_digits_unrolled(p);
    p += 8;
  }
#endif // SIMDJSON_SWAR_NUMBER_PARSING
#endif // #ifdef SIMDJSON_SWAR_NUMBER_PARSING
  // Unrolling the first digit makes a small difference on some implementations (e.g. westmere)
  if (parse_digit(*p, i)) { ++p; }
  while (parse_digit(*p, i)) { p++; }
  exponent = first_after_period - p;
  // Decimal without digits (123.) is illegal
  if (exponent == 0) {
    return INVALID_NUMBER(src);
  }
  return SUCCESS;
}

simdjson_warn_unused simdjson_inline error_code parse_exponent(simdjson_unused const uint8_t *const src, const uint8_t *&p, int64_t &exponent) {
  // Exp Sign: -123.456e[-]78
  bool neg_exp = ('-' == *p);
  if (neg_exp || '+' == *p) { p++; } // Skip + as well

  // Exponent: -123.456e-[78]
  auto start_exp = p;
  int64_t exp_number = 0;
  while (parse_digit(*p, exp_number)) { ++p; }
  // It is possible for parse_digit to overflow.
  // In particular, it could overflow to INT64_MIN, and we cannot do - INT64_MIN.
  // Thus we *must* check for possible overflow before we negate exp_number.

  // Performance notes: it may seem like combining the two "simdjson_unlikely checks" below into
  // a single simdjson_unlikely path would be faster. The reasoning is sound, but the compiler may
  // not oblige and may, in fact, generate two distinct paths in any case. It might be
  // possible to do uint64_t(p - start_exp - 1) >= 18 but it could end up trading off
  // instructions for a simdjson_likely branch, an unconclusive gain.

  // If there were no digits, it's an error.
  if (simdjson_unlikely(p == start_exp)) {
    return INVALID_NUMBER(src);
  }
  // We have a valid positive exponent in exp_number at this point, except that
  // it may have overflowed.

  // If there were more than 18 digits, we may have overflowed the integer. We have to do
  // something!!!!
  if (simdjson_unlikely(p > start_exp+18)) {
    // Skip leading zeroes: 1e000000000000000000001 is technically valid and does not overflow
    while (*start_exp == '0') { start_exp++; }
    // 19 digits could overflow int64_t and is kind of absurd anyway. We don't
    // support exponents smaller than -999,999,999,999,999,999 and bigger
    // than 999,999,999,999,999,999.
    // We can truncate.
    // Note that 999999999999999999 is assuredly too large. The maximal ieee64 value before
    // infinity is ~1.8e308. The smallest subnormal is ~5e-324. So, actually, we could
    // truncate at 324.
    // Note that there is no reason to fail per se at this point in time.
    // E.g., 0e999999999999999999999 is a fine number.
    if (p > start_exp+18) { exp_number = 999999999999999999; }
  }
  // At this point, we know that exp_number is a sane, positive, signed integer.
  // It is <= 999,999,999,999,999,999. As long as 'exponent' is in
  // [-8223372036854775808, 8223372036854775808], we won't overflow. Because 'exponent'
  // is bounded in magnitude by the size of the JSON input, we are fine in this universe.
  // To sum it up: the next line should never overflow.
  exponent += (neg_exp ? -exp_number : exp_number);
  return SUCCESS;
}

simdjson_inline bool check_if_integer(const uint8_t *const src, size_t max_length) {
  const uint8_t *const srcend = src + max_length;
  bool negative = (*src == '-'); // we can always read at least one character after the '-'
  const uint8_t *p = src + uint8_t(negative);
  if(p == srcend) { return false; }
  if(*p == '0') {
    ++p;
    if(p == srcend) { return true; }
    if(jsoncharutils::is_not_structural_or_whitespace(*p)) { return false; }
    return true;
  }
  while(p != srcend && is_digit(*p)) { ++p; }
  if(p == srcend) { return true; }
  if(jsoncharutils::is_not_structural_or_whitespace(*p)) { return false; }
  return true;
}

simdjson_inline size_t significant_digits(const uint8_t * start_digits, size_t digit_count) {
  // It is possible that the integer had an overflow.
  // We have to handle the case where we have 0.0000somenumber.
  const uint8_t *start = start_digits;
  while ((*start == '0') || (*start == '.')) { ++start; }
  // we over-decrement by one when there is a '.'
  return digit_count - size_t(start - start_digits);
}

} // unnamed namespace

/** @private */
inline error_code slow_float_parsing(simdjson_unused const uint8_t * src, double* answer) { __builtin_trap() /* STUB: not implemented */; }

/** @private */
template<typename W>
simdjson_warn_unused simdjson_inline error_code write_float(const uint8_t *const src, bool negative, uint64_t i, const uint8_t * start_digits, size_t digit_count, int64_t exponent, W &writer) { __builtin_trap() /* STUB: not implemented */; }

// parse the number at src
// define JSON_TEST_NUMBERS for unit testing
//
// It is assumed that the number is followed by a structural ({,},],[) character
// or a white space character. If that is not the case (e.g., when the JSON
// document is made of a single number), then it is necessary to copy the
// content and append a space before calling this function.
//
// Our objective is accurate parsing (ULP of 0) at high speed.
template<typename W>
simdjson_warn_unused simdjson_inline error_code parse_number(const uint8_t *const src, W &writer);

// for performance analysis, it is sometimes  useful to skip parsing
#ifdef SIMDJSON_SKIPNUMBERPARSING

template<typename W>
simdjson_warn_unused simdjson_inline error_code parse_number(const uint8_t *const, W &writer) { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline simdjson_result<uint64_t> parse_unsigned(const uint8_t * const src) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_unused simdjson_inline simdjson_result<int64_t> parse_integer(const uint8_t * const src) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_unused simdjson_inline simdjson_result<double> parse_double(const uint8_t * const src) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_unused simdjson_inline simdjson_result<uint64_t> parse_unsigned_in_string(const uint8_t * const src) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_unused simdjson_inline simdjson_result<int64_t> parse_integer_in_string(const uint8_t * const src) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_unused simdjson_inline simdjson_result<double> parse_double_in_string(const uint8_t * const src) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_unused simdjson_inline bool is_negative(const uint8_t * src) noexcept  { __builtin_trap() /* STUB: not implemented */; }
simdjson_unused simdjson_inline simdjson_result<bool> is_integer(const uint8_t * src) noexcept  { __builtin_trap() /* STUB: not implemented */; }
simdjson_unused simdjson_inline simdjson_result<number_type> get_number_type(const uint8_t * src) noexcept { __builtin_trap() /* STUB: not implemented */; }
#else

// parse the number at src
// define JSON_TEST_NUMBERS for unit testing
//
// It is assumed that the number is followed by a structural ({,},],[) character
// or a white space character. If that is not the case (e.g., when the JSON
// document is made of a single number), then it is necessary to copy the
// content and append a space before calling this function.
//
// Our objective is accurate parsing (ULP of 0) at high speed.
template<typename W>
simdjson_warn_unused simdjson_inline error_code parse_number(const uint8_t *const src, W &writer) { __builtin_trap() /* STUB: not implemented */; }

// Inlineable functions
namespace {

// This table can be used to characterize the final character of an integer
// string. For JSON structural character and allowable white space characters,
// we return SUCCESS. For 'e', '.' and 'E', we return INCORRECT_TYPE. Otherwise
// we return NUMBER_ERROR.
// Optimization note: we could easily reduce the size of the table by half (to 128)
// at the cost of an extra branch.
// Optimization note: we want the values to use at most 8 bits (not, e.g., 32 bits):
static_assert(error_code(uint8_t(NUMBER_ERROR))== NUMBER_ERROR, "bad NUMBER_ERROR cast");
static_assert(error_code(uint8_t(SUCCESS))== SUCCESS, "bad NUMBER_ERROR cast");
static_assert(error_code(uint8_t(INCORRECT_TYPE))== INCORRECT_TYPE, "bad NUMBER_ERROR cast");

const uint8_t integer_string_finisher[256] = {
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, SUCCESS,
    SUCCESS,      NUMBER_ERROR,   NUMBER_ERROR, SUCCESS,      NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   SUCCESS,      NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, SUCCESS,
    NUMBER_ERROR, INCORRECT_TYPE, NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, SUCCESS,      NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, INCORRECT_TYPE,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, SUCCESS,        NUMBER_ERROR, SUCCESS,      NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, INCORRECT_TYPE, NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, SUCCESS,      NUMBER_ERROR,
    SUCCESS,      NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR, NUMBER_ERROR,   NUMBER_ERROR, NUMBER_ERROR, NUMBER_ERROR,
    NUMBER_ERROR};

// Parse any number from 0 to 18,446,744,073,709,551,615
simdjson_unused simdjson_inline simdjson_result<uint64_t> parse_unsigned(const uint8_t * const src) noexcept { __builtin_trap() /* STUB: not implemented */; }


// Parse any number from 0 to 18,446,744,073,709,551,615
// Never read at src_end or beyond
simdjson_unused simdjson_inline simdjson_result<uint64_t> parse_unsigned(const uint8_t * const src, const uint8_t * const src_end) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Parse any number from 0 to 18,446,744,073,709,551,615
simdjson_unused simdjson_inline simdjson_result<uint64_t> parse_unsigned_in_string(const uint8_t * const src) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Parse any number from  -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
simdjson_unused simdjson_inline simdjson_result<int64_t> parse_integer(const uint8_t *src) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Parse any number from  -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
// Never read at src_end or beyond
simdjson_unused simdjson_inline simdjson_result<int64_t> parse_integer(const uint8_t * const src, const uint8_t * const src_end) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Parse any number from  -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
simdjson_unused simdjson_inline simdjson_result<int64_t> parse_integer_in_string(const uint8_t *src) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline simdjson_result<double> parse_double(const uint8_t * src) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline bool is_negative(const uint8_t * src) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline simdjson_result<bool> is_integer(const uint8_t * src) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline simdjson_result<number_type> get_number_type(const uint8_t * src) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Never read at src_end or beyond
simdjson_unused simdjson_inline simdjson_result<double> parse_double(const uint8_t * src, const uint8_t * const src_end) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline simdjson_result<double> parse_double_in_string(const uint8_t * src) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // unnamed namespace
#endif // SIMDJSON_SKIPNUMBERPARSING

} // namespace numberparsing

inline std::ostream& operator<<(std::ostream& out, number_type type) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_GENERIC_NUMBERPARSING_H
