#ifndef SIMDJSON_GENERIC_ONDEMAND_VALUE_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_VALUE_INL_H
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/array.h"
#include "simdjson/generic/ondemand/array_iterator.h"
#include "simdjson/generic/ondemand/json_iterator.h"
#include "simdjson/generic/ondemand/json_type.h"
#include "simdjson/generic/ondemand/object.h"
#include "simdjson/generic/ondemand/raw_json_string.h"
#include "simdjson/generic/ondemand/value.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <limits>

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

simdjson_inline value::value(const value_iterator &_iter) noexcept
  : iter{_iter}
{
}
simdjson_inline value value::start(const value_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline value value::resume(const value_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<array> value::get_array() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<object> value::get_object() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<object> value::start_or_resume_object() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<raw_json_string> value::get_raw_json_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> value::get_string(bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <typename string_type>
simdjson_warn_unused simdjson_inline error_code value::get_string(string_type& receiver, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> value::get_wobbly_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> value::get_double() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> value::get_double_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint64_t> value::get_uint64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint64_t> value::get_uint64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> value::get_int64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> value::get_int64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint32_t> value::get_uint32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int32_t> value::get_int32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> value::get_bool() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> value::is_null() noexcept { __builtin_trap() /* STUB: not implemented */; }

template<> simdjson_inline simdjson_result<array> value::get() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<object> value::get() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<raw_json_string> value::get() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<std::string_view> value::get() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<number> value::get() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<double> value::get() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<uint64_t> value::get() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<int64_t> value::get() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<uint32_t> value::get() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<int32_t> value::get() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<bool> value::get() noexcept { __builtin_trap() /* STUB: not implemented */; }


template<> simdjson_warn_unused simdjson_inline error_code value::get(array& out) noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code value::get(object& out) noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code value::get(raw_json_string& out) noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code value::get(std::string_view& out) noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code value::get(number& out) noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code value::get(double& out) noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code value::get(uint64_t& out) noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code value::get(int64_t& out) noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code value::get(uint32_t& out) noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code value::get(int32_t& out) noexcept { __builtin_trap() /* STUB: not implemented */; }
template<>  simdjson_warn_unused simdjson_inline error_code value::get(bool& out) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS
template <class T>
simdjson_inline value::operator T() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline value::operator array() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline value::operator object() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline value::operator uint64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline value::operator int64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline value::operator double() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline value::operator std::string_view() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline value::operator raw_json_string() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline value::operator bool() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
#endif

simdjson_inline simdjson_result<array_iterator> value::begin() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<array_iterator> value::end() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<size_t> value::count_elements() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<size_t> value::count_fields() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> value::at(size_t index) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<value> value::find_field(std::string_view key) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> value::find_field(const char *key) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<value> value::find_field_unordered(std::string_view key) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> value::find_field_unordered(const char *key) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<value> value::operator[](std::string_view key) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> value::operator[](const char *key) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<json_type> value::type() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> value::is_scalar() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> value::is_string() noexcept { __builtin_trap() /* STUB: not implemented */; }


simdjson_inline bool value::is_negative() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> value::is_integer() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<number_type> value::get_number_type() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<number> value::get_number() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline std::string_view value::raw_json_token() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> value::raw_json() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<const char *> value::current_location() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline int32_t value::current_depth() const noexcept{ __builtin_trap() /* STUB: not implemented */; }

inline bool is_pointer_well_formed(std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<value> value::at_pointer(std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<value> value::at_path(std::string_view json_path) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Func>
  requires std::invocable<Func, value>
#else
template <typename Func>
#endif
inline error_code value::for_each_at_path_with_wildcard(std::string_view json_path, Func&& callback) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::simdjson_result(
  SIMDJSON_IMPLEMENTATION::ondemand::value &&value
) noexcept :
    implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::value>(
      std::forward<SIMDJSON_IMPLEMENTATION::ondemand::value>(value)
    )
{ __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::simdjson_result(
  error_code error
) noexcept :
    implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::value>(error)
{ __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<size_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::count_elements() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<size_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::count_fields() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::at(size_t index) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::begin() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::end() & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::find_field(std::string_view key) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::find_field(const char *key) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::find_field_unordered(std::string_view key) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::find_field_unordered(const char *key) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::operator[](std::string_view key) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::operator[](const char *key) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_array() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_object() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_uint64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_uint64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_int64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_int64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint32_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_uint32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int32_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_int32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_double() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_double_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_string(bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <typename string_type>
simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_string(string_type& receiver, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_wobbly_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_raw_json_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_bool() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::is_null() noexcept { __builtin_trap() /* STUB: not implemented */; }

template<> simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get<SIMDJSON_IMPLEMENTATION::ondemand::value>(SIMDJSON_IMPLEMENTATION::ondemand::value &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T> simdjson_inline simdjson_result<T> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<typename T> simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get(T &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

template<> simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get<SIMDJSON_IMPLEMENTATION::ondemand::value>() noexcept  { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::json_type> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::type() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::is_scalar() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::is_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::is_negative() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::is_integer() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::number_type> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_number_type() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::number> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::get_number() noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_EXCEPTIONS
template <class T>
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::operator T() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::operator SIMDJSON_IMPLEMENTATION::ondemand::array() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::operator SIMDJSON_IMPLEMENTATION::ondemand::object() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::operator uint64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::operator int64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::operator double() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::operator std::string_view() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::operator SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::operator bool() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
#endif

simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::raw_json_token() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::raw_json() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<const char *> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::current_location() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<int32_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::current_depth() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::at_pointer(
    std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::at_path(
      std::string_view json_path) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Func>
  requires std::invocable<Func, SIMDJSON_IMPLEMENTATION::ondemand::value>
#else
template <typename Func>
#endif
inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value>::for_each_at_path_with_wildcard(
      std::string_view json_path, Func&& callback) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_VALUE_INL_H
