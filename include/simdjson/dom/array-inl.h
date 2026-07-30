#ifndef SIMDJSON_ARRAY_INL_H
#define SIMDJSON_ARRAY_INL_H

#include <utility>

#include "simdjson/dom/base.h"
#include "simdjson/dom/array.h"
#include "simdjson/dom/element.h"
#include "simdjson/error-inl.h"
#include "simdjson/jsonpathutil.h"
#include "simdjson/internal/tape_ref-inl.h"

#include <limits>

namespace simdjson {

//
// simdjson_result<dom::array> inline implementation
//
simdjson_inline simdjson_result<dom::array>::simdjson_result() noexcept
    : internal::simdjson_result_base<dom::array>() { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::array>::simdjson_result(dom::array value) noexcept
    : internal::simdjson_result_base<dom::array>(std::forward<dom::array>(value)) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<dom::array>::simdjson_result(error_code error) noexcept
    : internal::simdjson_result_base<dom::array>(error) { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS

inline dom::array::iterator simdjson_result<dom::array>::begin() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline dom::array::iterator simdjson_result<dom::array>::end() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
inline size_t simdjson_result<dom::array>::size() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_EXCEPTIONS

inline simdjson_result<dom::element> simdjson_result<dom::array>::at_pointer(std::string_view json_pointer) const noexcept { __builtin_trap() /* STUB: not implemented */; }

 inline simdjson_result<dom::element> simdjson_result<dom::array>::at_path(std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::vector<dom::element>> simdjson_result<dom::array>::at_path_with_wildcard(std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<dom::element> simdjson_result<dom::array>::at(size_t index) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline std::vector<dom::element>& simdjson_result<dom::array>::get_values(std::vector<dom::element>& out) const noexcept { __builtin_trap() /* STUB: not implemented */; }

namespace dom {

//
// array inline implementation
//
simdjson_inline array::array() noexcept : tape{ __builtin_trap() /* STUB: not implemented */; } {}
simdjson_inline array::array(const internal::tape_ref &_tape) noexcept : tape{_tape} {}
inline array::iterator array::begin() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline array::iterator array::end() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline size_t array::size() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline size_t array::number_of_slots() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<element> array::at_pointer(std::string_view json_pointer) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> array::at_path(std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void array::process_json_path_of_child_elements(std::vector<element>::iterator& current, std::vector<element>::iterator& end, const std::string_view& path_suffix, std::vector<element>& accumulator) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::vector<element>> array::at_path_with_wildcard(std::string_view json_path) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> array::at(size_t index) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline std::vector<element>& array::get_values(std::vector<element>& out) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline array::operator element() const noexcept { __builtin_trap() /* STUB: not implemented */; }

//
// array::iterator inline implementation
//
simdjson_inline array::iterator::iterator(const internal::tape_ref &_tape) noexcept : tape{_tape} { }
inline element array::iterator::operator*() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline array::iterator& array::iterator::operator++() noexcept { __builtin_trap() /* STUB: not implemented */; }
inline array::iterator array::iterator::operator++(int) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool array::iterator::operator!=(const array::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool array::iterator::operator==(const array::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool array::iterator::operator<(const array::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool array::iterator::operator<=(const array::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool array::iterator::operator>=(const array::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline bool array::iterator::operator>(const array::iterator& other) const noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace dom


} // namespace simdjson

#include "simdjson/dom/element-inl.h"

#if SIMDJSON_SUPPORTS_RANGES
static_assert(std::ranges::view<simdjson::dom::array>);
static_assert(std::ranges::sized_range<simdjson::dom::array>);
#if SIMDJSON_EXCEPTIONS
static_assert(std::ranges::view<simdjson::simdjson_result<simdjson::dom::array>>);
static_assert(std::ranges::sized_range<simdjson::simdjson_result<simdjson::dom::array>>);
#endif // SIMDJSON_EXCEPTIONS
#endif // SIMDJSON_SUPPORTS_RANGES

#endif // SIMDJSON_ARRAY_INL_H
