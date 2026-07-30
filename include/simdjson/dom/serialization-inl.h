
#ifndef SIMDJSON_SERIALIZATION_INL_H
#define SIMDJSON_SERIALIZATION_INL_H

#include "simdjson/dom/base.h"
#include "simdjson/dom/parser.h"
#include "simdjson/dom/serialization.h"
#include "simdjson/internal/tape_type.h"

#include "simdjson/dom/array-inl.h"
#include "simdjson/dom/object-inl.h"
#include "simdjson/internal/tape_ref-inl.h"

#include <cmath>
#include <cstring>

namespace simdjson {
namespace dom {
inline bool parser::print_json(std::ostream &os) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline std::ostream &operator<<(std::ostream &out,
                                simdjson::dom::element value) { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_EXCEPTIONS
inline std::ostream &
operator<<(std::ostream &out,
           simdjson::simdjson_result<simdjson::dom::element> x) { __builtin_trap() /* STUB: not implemented */; }
#endif
inline std::ostream &operator<<(std::ostream &out, simdjson::dom::array value) { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_EXCEPTIONS
inline std::ostream &
operator<<(std::ostream &out,
           simdjson::simdjson_result<simdjson::dom::array> x) { __builtin_trap() /* STUB: not implemented */; }
#endif
inline std::ostream &operator<<(std::ostream &out,
                                simdjson::dom::object value) { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_EXCEPTIONS
inline std::ostream &
operator<<(std::ostream &out,
           simdjson::simdjson_result<simdjson::dom::object> x) { __builtin_trap() /* STUB: not implemented */; }
#endif

} // namespace dom

/***
 * Number utility functions
 **/
namespace {
/**@private
 * Escape sequence like \b or \u0001
 * We expect that most compilers will use 8 bytes for this data structure.
 **/
struct escape_sequence {
  uint8_t length;
  const char
      string[7]; // technically, we only ever need 6 characters, we pad to 8
};
/**@private
 * This converts a signed integer into a character sequence.
 * The caller is responsible for providing enough memory (at least
 * 20 characters.)
 * Though various runtime libraries provide itoa functions,
 * it is not part of the C++ standard. The C++17 standard
 * adds the to_chars functions which would do as well, but
 * we want to support C++11.
 */
static char *fast_itoa(char *output, int64_t value) noexcept { __builtin_trap() /* STUB: not implemented */; }
/**@private
 * This converts an unsigned integer into a character sequence.
 * The caller is responsible for providing enough memory (at least
 * 19 characters.)
 * Though various runtime libraries provide itoa functions,
 * it is not part of the C++ standard. The C++17 standard
 * adds the to_chars functions which would do as well, but
 * we want to support C++11.
 */
static char *fast_itoa(char *output, uint64_t value) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // anonymous namespace
namespace internal {

/***
 * Minifier/formatter code.
 **/

template <class formatter>
simdjson_inline void base_formatter<formatter>::number(uint64_t x) { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::number(int64_t x) { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::number(double x) { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::start_array() { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::end_array() { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::start_object() { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::end_object() { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::comma() { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::true_atom() { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::false_atom() { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::null_atom() { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::one_char(char c) { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void base_formatter<formatter>::chars(const char *begin,
                                                      const char *end) { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void
base_formatter<formatter>::key(std::string_view unescaped) { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline void
base_formatter<formatter>::string(std::string_view unescaped) { __builtin_trap() /* STUB: not implemented */; }

template <class formatter> inline void base_formatter<formatter>::clear() { __builtin_trap() /* STUB: not implemented */; }

template <class formatter>
simdjson_inline std::string_view base_formatter<formatter>::str() const { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void mini_formatter::print_newline() { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void mini_formatter::print_indents(size_t depth) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void mini_formatter::print_space() { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void pretty_formatter::print_newline() { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void pretty_formatter::print_indents(size_t depth) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void pretty_formatter::print_space() { __builtin_trap() /* STUB: not implemented */; }

/***
 * String building code.
 **/

template <class serializer>
inline void string_builder<serializer>::append(simdjson::dom::element value) { __builtin_trap() /* STUB: not implemented */; }

template <class serializer>
inline void string_builder<serializer>::append(simdjson::dom::object value) { __builtin_trap() /* STUB: not implemented */; }

template <class serializer>
inline void string_builder<serializer>::append(simdjson::dom::array value) { __builtin_trap() /* STUB: not implemented */; }

template <class serializer>
simdjson_inline void
string_builder<serializer>::append(simdjson::dom::key_value_pair kv) { __builtin_trap() /* STUB: not implemented */; }

template <class serializer>
simdjson_inline void string_builder<serializer>::clear() { __builtin_trap() /* STUB: not implemented */; }

template <class serializer>
simdjson_inline std::string_view string_builder<serializer>::str() const { __builtin_trap() /* STUB: not implemented */; }

} // namespace internal
} // namespace simdjson

#endif
