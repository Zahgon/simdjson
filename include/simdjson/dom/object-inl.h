#ifndef SIMDJSON_OBJECT_INL_H
#define SIMDJSON_OBJECT_INL_H

#include "simdjson/dom/base.h"
#include "simdjson/dom/object.h"
#include "simdjson/dom/document.h"

#include "simdjson/dom/element-inl.h"
#include "simdjson/error-inl.h"
#include "simdjson/jsonpathutil.h"

#include <cstring>

namespace simdjson {

//
// simdjson_result<dom::object> inline implementation
//
simdjson_inline simdjson_result<dom::object>::simdjson_result() noexcept
    : internal::simdjson_result_base<dom::object>() { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::object>::simdjson_result(dom::object value) noexcept
    : internal::simdjson_result_base<dom::object>(std::forward<dom::object>(value)) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::object>::simdjson_result(error_code error) noexcept
    : internal::simdjson_result_base<dom::object>(error) { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<dom::element> simdjson_result<dom::object>::operator[](std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<dom::element> simdjson_result<dom::object>::operator[](const char *key) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<dom::element> simdjson_result<dom::object>::at_pointer(std::string_view json_pointer) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<dom::element> simdjson_result<dom::object>::at_path(std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<std::vector<dom::element>> simdjson_result<dom::object>::at_path_with_wildcard(std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<dom::element> simdjson_result<dom::object>::at_key(std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline std::vector<dom::element>& simdjson_result<dom::object>::get_values(std::vector<dom::element>& out) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<dom::element> simdjson_result<dom::object>::at_key_case_insensitive(std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS

inline dom::object::iterator simdjson_result<dom::object>::begin() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline dom::object::iterator simdjson_result<dom::object>::end() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline size_t simdjson_result<dom::object>::size() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_EXCEPTIONS

namespace dom {

//
// object inline implementation
//
simdjson_inline object::object() noexcept : tape{ __builtin_trap() /* STUB: not implemented */; } {}
simdjson_inline object::object(const internal::tape_ref &_tape) noexcept : tape{_tape} { }
inline object::iterator object::begin() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline object::iterator object::end() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline size_t object::size() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> object::operator[](std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<element> object::operator[](const char *key) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<element> object::at_pointer(std::string_view json_pointer) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> object::at_path(std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void object::process_json_path_of_child_elements(std::vector<element>::iterator& current, std::vector<element>::iterator& end, const std::string_view& path_suffix, std::vector<element>& accumulator) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::vector<element>> object::at_path_with_wildcard(std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> object::at_key(std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline std::vector<element>& object::get_values(std::vector<element>& out) const noexcept { __builtin_trap() /* STUB: not implemented */; }
// In case you wonder why we need this, please see
// https://github.com/simdjson/simdjson/issues/323
// People do seek keys in a case-insensitive manner.
inline simdjson_result<element> object::at_key_case_insensitive(std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline object::operator element() const noexcept { __builtin_trap() /* STUB: not implemented */; }

//
// object::iterator inline implementation
//
simdjson_inline object::iterator::iterator(const internal::tape_ref &_tape) noexcept : tape{_tape} { }
inline const key_value_pair object::iterator::operator*() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool object::iterator::operator!=(const object::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool object::iterator::operator==(const object::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool object::iterator::operator<(const object::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool object::iterator::operator<=(const object::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool object::iterator::operator>=(const object::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool object::iterator::operator>(const object::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline object::iterator& object::iterator::operator++() noexcept { __builtin_trap() /* STUB: not implemented */; }
inline object::iterator object::iterator::operator++(int) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline std::string_view object::iterator::key() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline uint32_t object::iterator::key_length() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline const char* object::iterator::key_c_str() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline element object::iterator::value() const noexcept { __builtin_trap() /* STUB: not implemented */; }

/**
 * Design notes:
 * Instead of constructing a string_view and then comparing it with a
 * user-provided strings, it is probably more performant to have dedicated
 * functions taking as a parameter the string we want to compare against
 * and return true when they are equal. That avoids the creation of a temporary
 * std::string_view. Though it is possible for the compiler to avoid entirely
 * any overhead due to string_view, relying too much on compiler magic is
 * problematic: compiler magic sometimes fail, and then what do you do?
 * Also, enticing users to rely on high-performance function is probably better
 * on the long run.
 */

inline bool object::iterator::key_equals(std::string_view o) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool object::iterator::key_equals_case_insensitive(std::string_view o) const noexcept { __builtin_trap() /* STUB: not implemented */; }
//
// key_value_pair inline implementation
//
inline key_value_pair::key_value_pair(std::string_view _key, element _value) noexcept :
  key(_key), value(_value) { __builtin_trap() /* STUB: not implemented */; }

} // namespace dom

} // namespace simdjson

#if SIMDJSON_SUPPORTS_RANGES
static_assert(std::ranges::view<simdjson::dom::object>);
static_assert(std::ranges::sized_range<simdjson::dom::object>);
#if SIMDJSON_EXCEPTIONS
static_assert(std::ranges::view<simdjson::simdjson_result<simdjson::dom::object>>);
static_assert(std::ranges::sized_range<simdjson::simdjson_result<simdjson::dom::object>>);
#endif // SIMDJSON_EXCEPTIONS
#endif // SIMDJSON_SUPPORTS_RANGES

#endif // SIMDJSON_OBJECT_INL_H
