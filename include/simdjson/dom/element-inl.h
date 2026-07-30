#ifndef SIMDJSON_ELEMENT_INL_H
#define SIMDJSON_ELEMENT_INL_H

#include "simdjson/dom/base.h"
#include "simdjson/dom/element.h"
#include "simdjson/dom/document.h"
#include "simdjson/dom/object.h"
#include "simdjson/internal/tape_type.h"

#include "simdjson/dom/object-inl.h"
#include "simdjson/error-inl.h"
#include "simdjson/jsonpathutil.h"

#include <ostream>
#include <limits>

namespace simdjson {

//
// simdjson_result<dom::element> inline implementation
//
simdjson_inline simdjson_result<dom::element>::simdjson_result() noexcept
    : internal::simdjson_result_base<dom::element>() { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element>::simdjson_result(dom::element &&value) noexcept
    : internal::simdjson_result_base<dom::element>(std::forward<dom::element>(value)) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element>::simdjson_result(error_code error) noexcept
    : internal::simdjson_result_base<dom::element>(error) { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<dom::element_type> simdjson_result<dom::element>::type() const noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline bool simdjson_result<dom::element>::is() const noexcept { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_inline simdjson_result<T> simdjson_result<dom::element>::get() const noexcept { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_warn_unused simdjson_inline error_code simdjson_result<dom::element>::get(T &value) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<dom::array> simdjson_result<dom::element>::get_array() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::object> simdjson_result<dom::element>::get_object() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<const char *> simdjson_result<dom::element>::get_c_str() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<size_t> simdjson_result<dom::element>::get_string_length() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> simdjson_result<dom::element>::get_string() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> simdjson_result<dom::element>::get_int64() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint64_t> simdjson_result<dom::element>::get_uint64() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> simdjson_result<dom::element>::get_double() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<dom::element>::get_bool() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> simdjson_result<dom::element>::get_bigint() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool simdjson_result<dom::element>::is_array() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool simdjson_result<dom::element>::is_object() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool simdjson_result<dom::element>::is_string() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool simdjson_result<dom::element>::is_int64() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool simdjson_result<dom::element>::is_uint64() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool simdjson_result<dom::element>::is_double() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool simdjson_result<dom::element>::is_number() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool simdjson_result<dom::element>::is_bool() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool simdjson_result<dom::element>::is_null() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool simdjson_result<dom::element>::is_bigint() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<dom::element> simdjson_result<dom::element>::operator[](std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element> simdjson_result<dom::element>::operator[](const char *key) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element> simdjson_result<dom::element>::at_pointer(const std::string_view json_pointer) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element> simdjson_result<dom::element>::at_path(const std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::vector<dom::element>> simdjson_result<dom::element>::at_path_with_wildcard(const std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }

#ifndef SIMDJSON_DISABLE_DEPRECATED_API
[[deprecated("For standard compliance, use at_pointer instead, and prefix your pointers with a slash '/', see RFC6901 ")]]
simdjson_inline simdjson_result<dom::element> simdjson_result<dom::element>::at(const std::string_view json_pointer) const noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_DISABLE_DEPRECATED_API
simdjson_inline simdjson_result<dom::element> simdjson_result<dom::element>::at(size_t index) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element> simdjson_result<dom::element>::at_key(std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element> simdjson_result<dom::element>::at_key_case_insensitive(std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS

simdjson_inline simdjson_result<dom::element>::operator bool() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element>::operator const char *() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element>::operator std::string_view() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element>::operator uint64_t() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element>::operator int64_t() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element>::operator double() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element>::operator dom::array() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::element>::operator dom::object() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline dom::array::iterator simdjson_result<dom::element>::begin() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline dom::array::iterator simdjson_result<dom::element>::end() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_EXCEPTIONS

namespace dom {

//
// element inline implementation
//
simdjson_inline element::element() noexcept : tape{ __builtin_trap() /* STUB: not implemented */; } {}
simdjson_inline element::element(const internal::tape_ref &_tape) noexcept : tape{_tape} { }

inline element_type element::type() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<bool> element::get_bool() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<std::string_view> element::get_bigint() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<const char *> element::get_c_str() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<size_t> element::get_string_length() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<std::string_view> element::get_string() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<uint64_t> element::get_uint64() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<int64_t> element::get_int64() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<double> element::get_double() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<array> element::get_array() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<object> element::get_object() const noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_warn_unused simdjson_inline error_code element::get(T &value) const noexcept { __builtin_trap() /* STUB: not implemented */; }
// An element-specific version prevents recursion with simdjson_result::get<element>(value)
template<>
simdjson_warn_unused simdjson_inline error_code element::get<element>(element &value) const noexcept { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
inline void element::tie(T &value, error_code &error) && noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline bool element::is() const noexcept { __builtin_trap() /* STUB: not implemented */; }

template<> inline simdjson_result<array> element::get<array>() const noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> inline simdjson_result<object> element::get<object>() const noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> inline simdjson_result<const char *> element::get<const char *>() const noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> inline simdjson_result<std::string_view> element::get<std::string_view>() const noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> inline simdjson_result<int64_t> element::get<int64_t>() const noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> inline simdjson_result<uint64_t> element::get<uint64_t>() const noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> inline simdjson_result<double> element::get<double>() const noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> inline simdjson_result<bool> element::get<bool>() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool element::is_array() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool element::is_object() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool element::is_string() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool element::is_int64() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool element::is_uint64() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool element::is_double() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool element::is_bool() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool element::is_number() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool element::is_null() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool element::is_bigint() const noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS

inline element::operator bool() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline element::operator const char*() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline element::operator std::string_view() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline element::operator uint64_t() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline element::operator int64_t() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline element::operator double() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline element::operator array() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline element::operator object() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

inline array::iterator element::begin() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline array::iterator element::end() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_EXCEPTIONS

inline simdjson_result<element> element::operator[](std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<element> element::operator[](const char *key) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool is_pointer_well_formed(std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> element::at_pointer(std::string_view json_pointer) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::vector<element>> element::at_path_with_wildcard(std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> element::at_path(std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }
#ifndef SIMDJSON_DISABLE_DEPRECATED_API
[[deprecated("For standard compliance, use at_pointer instead, and prefix your pointers with a slash '/', see RFC6901 ")]]
inline simdjson_result<element> element::at(std::string_view json_pointer) const noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_DISABLE_DEPRECATED_API

inline simdjson_result<element> element::at(size_t index) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<element> element::at_key(std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<element> element::at_key_case_insensitive(std::string_view key) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool element::operator<(const element &other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool element::operator==(const element &other) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool element::dump_raw_tape(std::ostream &out) const noexcept { __builtin_trap() /* STUB: not implemented */; }


inline std::ostream& operator<<(std::ostream& out, element_type type) { __builtin_trap() /* STUB: not implemented */; }

} // namespace dom

} // namespace simdjson

#endif // SIMDJSON_ELEMENT_INL_H
