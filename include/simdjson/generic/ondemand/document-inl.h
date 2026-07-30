#ifndef SIMDJSON_GENERIC_ONDEMAND_DOCUMENT_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_DOCUMENT_INL_H
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/array_iterator.h"
#include "simdjson/generic/ondemand/document.h"
#include "simdjson/generic/ondemand/json_type.h"
#include "simdjson/generic/ondemand/raw_json_string.h"
#include "simdjson/generic/ondemand/value.h"
#include "simdjson/generic/ondemand/value-inl.h"
#include "simdjson/generic/ondemand/array-inl.h"
#include "simdjson/generic/ondemand/json_iterator-inl.h"
#include "simdjson/generic/ondemand/object-inl.h"
#include "simdjson/generic/ondemand/value_iterator-inl.h"
#include "simdjson/generic/ondemand/deserialize.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <limits>

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

simdjson_inline document::document(ondemand::json_iterator &&_iter) noexcept
  : iter{std::forward<json_iterator>(_iter)}
{
  logger::log_start_value(iter, "document");
}

simdjson_inline document document::start(json_iterator &&iter) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void document::rewind() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline std::string document::to_debug_string() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<const char *> document::current_location() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline int32_t document::current_depth() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool document::at_end() const noexcept { __builtin_trap() /* STUB: not implemented */; }


inline bool document::is_alive() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline value_iterator document::resume_value_iterator() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline value_iterator document::get_root_value_iterator() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<object> document::start_or_resume_object() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document::get_value() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<array> document::get_array() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<object> document::get_object() & noexcept { __builtin_trap() /* STUB: not implemented */; }

/**
 * We decided that calling 'get_double()' on the JSON document '1.233 blabla' should
 * give an error, so we check for trailing content. We want to disallow trailing
 * content.
 * Thus, in several implementations below, we pass a 'true' parameter value to
 * a get_root_value_iterator() method: this indicates that we disallow trailing content.
 */

simdjson_inline simdjson_result<uint64_t> document::get_uint64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint64_t> document::get_uint64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> document::get_int64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> document::get_int64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint32_t> document::get_uint32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int32_t> document::get_int32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> document::get_double() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> document::get_double_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> document::get_string(bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <typename string_type>
simdjson_warn_unused simdjson_inline error_code document::get_string(string_type& receiver, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> document::get_wobbly_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<raw_json_string> document::get_raw_json_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> document::get_bool() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> document::is_null() noexcept { __builtin_trap() /* STUB: not implemented */; }

template<> simdjson_inline simdjson_result<array> document::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<object> document::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<raw_json_string> document::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<std::string_view> document::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<double> document::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<uint64_t> document::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<int64_t> document::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<uint32_t> document::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<int32_t> document::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<bool> document::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<value> document::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }

template<> simdjson_warn_unused simdjson_inline error_code document::get(array& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code document::get(object& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code document::get(raw_json_string& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code document::get(std::string_view& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code document::get(double& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code document::get(uint64_t& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code document::get(int64_t& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code document::get(uint32_t& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code document::get(int32_t& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code document::get(bool& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code document::get(value& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }

template<> simdjson_deprecated simdjson_inline simdjson_result<raw_json_string> document::get() && noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_deprecated simdjson_inline simdjson_result<std::string_view> document::get() && noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_deprecated simdjson_inline simdjson_result<double> document::get() && noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_deprecated simdjson_inline simdjson_result<uint64_t> document::get() && noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_deprecated simdjson_inline simdjson_result<int64_t> document::get() && noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_deprecated simdjson_inline simdjson_result<bool> document::get() && noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_deprecated simdjson_inline simdjson_result<value> document::get() && noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS
template <class T>
simdjson_deprecated simdjson_inline document::operator T() && noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
template <class T>
simdjson_inline document::operator T() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document::operator array() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document::operator object() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document::operator uint64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document::operator int64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document::operator double() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document::operator std::string_view() noexcept(false) simdjson_lifetime_bound { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document::operator raw_json_string() noexcept(false) simdjson_lifetime_bound { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document::operator bool() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document::operator value() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

#endif
simdjson_inline simdjson_result<size_t> document::count_elements() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<size_t> document::count_fields() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document::at(size_t index) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<array_iterator> document::begin() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<array_iterator> document::end() & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<value> document::find_field(std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document::find_field(const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document::find_field_unordered(std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document::find_field_unordered(const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document::operator[](std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document::operator[](const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code document::consume() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> document::raw_json() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<json_type> document::type() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> document::is_scalar() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> document::is_string() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool document::is_negative() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> document::is_integer() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<number_type> document::get_number_type() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<number> document::get_number() noexcept { __builtin_trap() /* STUB: not implemented */; }


simdjson_inline simdjson_result<std::string_view> document::raw_json_token() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<value> document::at_pointer(std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<value> document::at_path(std::string_view json_path) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Func>
  requires std::invocable<Func, value>
#else
template <typename Func>
#endif
simdjson_inline error_code document::for_each_at_path_with_wildcard(std::string_view json_path, Func&& callback) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS && SIMDJSON_STATIC_REFLECTION

template<constevalutil::fixed_string... FieldNames, typename T>
  requires(std::is_class_v<T> && (sizeof...(FieldNames) > 0))
simdjson_warn_unused simdjson_inline error_code document::extract_into(T& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_SUPPORTS_CONCEPTS && SIMDJSON_STATIC_REFLECTION

} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::simdjson_result(
  SIMDJSON_IMPLEMENTATION::ondemand::document &&value
) noexcept :
    implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::document>(
      std::forward<SIMDJSON_IMPLEMENTATION::ondemand::document>(value)
    )
{ __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::simdjson_result(
  error_code error
) noexcept :
    implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::document>(
      error
    )
{ __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<size_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::count_elements() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<size_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::count_fields() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::at(size_t index) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::rewind() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::begin() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::end() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::find_field_unordered(std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::find_field_unordered(const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator[](std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator[](const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::find_field(std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::find_field(const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_array() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_object() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_uint64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_uint64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_int64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_int64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint32_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_uint32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int32_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_int32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_double() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_double_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_string(bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <typename string_type>
simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_string(string_type& receiver, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_wobbly_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_raw_json_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_bool() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_value() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::is_null() noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline simdjson_result<T> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_deprecated simdjson_inline simdjson_result<T> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get() && noexcept { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get(T &out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get(T &out) && noexcept { __builtin_trap() /* STUB: not implemented */; }

template<> simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get<SIMDJSON_IMPLEMENTATION::ondemand::document>() & noexcept = delete;
template<> simdjson_deprecated simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get<SIMDJSON_IMPLEMENTATION::ondemand::document>() && noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get<SIMDJSON_IMPLEMENTATION::ondemand::document>(SIMDJSON_IMPLEMENTATION::ondemand::document &out) & noexcept = delete;
template<> simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get<SIMDJSON_IMPLEMENTATION::ondemand::document>(SIMDJSON_IMPLEMENTATION::ondemand::document &out) && noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::json_type> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::type() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::is_scalar() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::is_string() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::is_negative() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::is_integer() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::number_type> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_number_type() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::number> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::get_number() noexcept { __builtin_trap() /* STUB: not implemented */; }


#if SIMDJSON_EXCEPTIONS
template <class T, typename std::enable_if<std::is_same<T, SIMDJSON_IMPLEMENTATION::ondemand::document>::value == false>::type>
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator T() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator SIMDJSON_IMPLEMENTATION::ondemand::array() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator SIMDJSON_IMPLEMENTATION::ondemand::object() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator uint64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator int64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator double() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator std::string_view() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator bool() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::operator SIMDJSON_IMPLEMENTATION::ondemand::value() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
#endif


simdjson_inline simdjson_result<const char *> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::current_location() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::at_end() const noexcept { __builtin_trap() /* STUB: not implemented */; }


simdjson_inline int32_t simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::current_depth() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::raw_json_token() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::at_pointer(std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::at_path(std::string_view json_path) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Func>
  requires std::invocable<Func, SIMDJSON_IMPLEMENTATION::ondemand::value>
#else
template <typename Func>
#endif
simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::for_each_at_path_with_wildcard(std::string_view json_path, Func&& callback) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_STATIC_REFLECTION
template<constevalutil::fixed_string... FieldNames, typename T>
  requires(std::is_class_v<T> && (sizeof...(FieldNames) > 0))
simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document>::extract_into(T& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_STATIC_REFLECTION

} // namespace simdjson


namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

simdjson_inline document_reference::document_reference() noexcept : doc{nullptr} {}
simdjson_inline document_reference::document_reference(document &d) noexcept : doc(&d) {}
simdjson_inline void document_reference::rewind() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<array> document_reference::get_array() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<object> document_reference::get_object() & noexcept { __builtin_trap() /* STUB: not implemented */; }
/**
 * The document_reference instances are used primarily/solely for streams of JSON
 * documents.
 * We decided that calling 'get_double()' on the JSON document '1.233 blabla' should
 * give an error, so we check for trailing content.
 *
 * However, for streams of JSON documents, we want to be able to start from
 * "321" "321" "321"
 * and parse it successfully as a stream of JSON documents, calling get_uint64_in_string()
 * successfully each time.
 *
 * To achieve this result, we pass a 'false' to a get_root_value_iterator() method:
 * this indicates that we allow trailing content.
 */
simdjson_inline simdjson_result<uint64_t> document_reference::get_uint64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint64_t> document_reference::get_uint64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> document_reference::get_int64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> document_reference::get_int64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint32_t> document_reference::get_uint32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int32_t> document_reference::get_int32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> document_reference::get_double() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> document_reference::get_double_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> document_reference::get_string(bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <typename string_type>
simdjson_warn_unused simdjson_inline error_code document_reference::get_string(string_type& receiver, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> document_reference::get_wobbly_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<raw_json_string> document_reference::get_raw_json_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> document_reference::get_bool() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document_reference::get_value() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> document_reference::is_null() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<array> document_reference::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<object> document_reference::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<raw_json_string> document_reference::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<std::string_view> document_reference::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<double> document_reference::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<uint64_t> document_reference::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<int64_t> document_reference::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<uint32_t> document_reference::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<int32_t> document_reference::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<bool> document_reference::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<> simdjson_inline simdjson_result<value> document_reference::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_EXCEPTIONS
template <class T>
simdjson_inline document_reference::operator T() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document_reference::operator array() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document_reference::operator object() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document_reference::operator uint64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document_reference::operator int64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document_reference::operator double() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document_reference::operator std::string_view() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document_reference::operator raw_json_string() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document_reference::operator bool() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document_reference::operator value() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
#endif
simdjson_inline simdjson_result<size_t> document_reference::count_elements() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<size_t> document_reference::count_fields() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document_reference::at(size_t index) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<array_iterator> document_reference::begin() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<array_iterator> document_reference::end() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document_reference::find_field(std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document_reference::find_field(const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document_reference::operator[](std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document_reference::operator[](const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document_reference::find_field_unordered(std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document_reference::find_field_unordered(const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<json_type> document_reference::type() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> document_reference::is_scalar() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> document_reference::is_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<const char *> document_reference::current_location() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline int32_t document_reference::current_depth() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool document_reference::is_negative() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> document_reference::is_integer() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<number_type> document_reference::get_number_type() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<number> document_reference::get_number() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> document_reference::raw_json_token() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document_reference::at_pointer(std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> document_reference::at_path(std::string_view json_path) noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Func>
  requires std::invocable<Func, value>
#else
template <typename Func>
#endif
simdjson_inline error_code document_reference::for_each_at_path_with_wildcard(std::string_view json_path, Func&& callback) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> document_reference::raw_json() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline document_reference::operator document&() const noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_SUPPORTS_CONCEPTS && SIMDJSON_STATIC_REFLECTION
template<constevalutil::fixed_string... FieldNames, typename T>
  requires(std::is_class_v<T> && (sizeof...(FieldNames) > 0))
simdjson_warn_unused simdjson_inline error_code document_reference::extract_into(T& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_SUPPORTS_CONCEPTS && SIMDJSON_STATIC_REFLECTION
} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson



namespace simdjson {
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::simdjson_result(SIMDJSON_IMPLEMENTATION::ondemand::document_reference value, error_code error)
  noexcept : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>(std::forward<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>(value), error) { __builtin_trap() /* STUB: not implemented */; }


simdjson_inline simdjson_result<size_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::count_elements() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<size_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::count_fields() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::at(size_t index) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::rewind() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::begin() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::end() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::find_field_unordered(std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::find_field_unordered(const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator[](std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator[](const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::find_field(std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::find_field(const char *key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_array() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_object() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_uint64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_uint64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_int64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int64_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_int64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<uint32_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_uint32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<int32_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_int32() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_double() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<double> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_double_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_string(bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <typename string_type>
simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_string(string_type& receiver, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_wobbly_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_raw_json_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_bool() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_value() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::is_null() noexcept { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_inline simdjson_result<T> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get() & noexcept { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_inline simdjson_result<T> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get() && noexcept { __builtin_trap() /* STUB: not implemented */; }
template <class T>
simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get(T &out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template <class T>
simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get(T &out) && noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::json_type> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::type() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::is_scalar() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::is_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
template <>
simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get(SIMDJSON_IMPLEMENTATION::ondemand::document_reference &out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
template <>
simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get(SIMDJSON_IMPLEMENTATION::ondemand::document_reference &out) && noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::is_negative() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::is_integer() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::number_type> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_number_type() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::number> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::get_number() noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_EXCEPTIONS
template <class T>
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator T() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator SIMDJSON_IMPLEMENTATION::ondemand::array() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator SIMDJSON_IMPLEMENTATION::ondemand::object() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator uint64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator int64_t() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator double() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator std::string_view() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator bool() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::operator SIMDJSON_IMPLEMENTATION::ondemand::value() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
#endif

simdjson_inline simdjson_result<const char *> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::current_location() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::raw_json_token() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::at_pointer(std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::at_path(std::string_view json_path) noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Func>
  requires std::invocable<Func, SIMDJSON_IMPLEMENTATION::ondemand::value>
#else
template <typename Func>
#endif
simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::for_each_at_path_with_wildcard(std::string_view json_path, Func&& callback) noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_STATIC_REFLECTION
template<constevalutil::fixed_string... FieldNames, typename T>
  requires(std::is_class_v<T> && (sizeof...(FieldNames) > 0))
simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference>::extract_into(T& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_STATIC_REFLECTION
} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_DOCUMENT_INL_H
