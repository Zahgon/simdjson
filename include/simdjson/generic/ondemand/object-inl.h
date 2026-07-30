#ifndef SIMDJSON_GENERIC_ONDEMAND_OBJECT_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_OBJECT_INL_H
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/field.h"
#include "simdjson/generic/ondemand/object.h"
#include "simdjson/generic/ondemand/object_iterator.h"
#include "simdjson/generic/ondemand/raw_json_string.h"
#include "simdjson/generic/ondemand/json_iterator.h"
#include "simdjson/generic/ondemand/value-inl.h"
#include "simdjson/jsonpathutil.h"
#include <utility>
#if SIMDJSON_SUPPORTS_CONCEPTS
#include <tuple> // std::forward_as_tuple/get for the variadic for_each adapter
#endif
#if SIMDJSON_STATIC_REFLECTION
#include "simdjson/generic/ondemand/json_string_builder.h"  // for constevalutil::fixed_string
#include <meta>
#endif
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

simdjson_inline simdjson_result<value> object::find_field_unordered(const std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> object::find_field_unordered(const std::string_view key) && noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> object::operator[](const std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> object::operator[](const std::string_view key) && noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> object::find_field(const std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<value> object::find_field(const std::string_view key) && noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Selector, typename Func>
  requires key_selector_type<Selector> &&
           std::is_invocable_v<Func&, std::size_t, value>
simdjson_flatten simdjson_inline for_each_result object::for_each(Func&& on_match)
    noexcept(std::is_nothrow_invocable_v<Func&, std::size_t, value>) { __builtin_trap() /* STUB: not implemented */; }

namespace key_selector_for_each_detail {

// Dispatch a matched value to the I-th handler in the tuple (0-based). A handler
// is either an invocable taking the value (void- or error_code-returning) or a
// deserialization target, in which case we assign via value::get. We always
// return error_code so the core (index, value) for_each can treat the adapter
// uniformly.
template <typename Tuple, std::size_t... Is>
simdjson_really_inline error_code dispatch_value(
    std::size_t idx, Tuple& handlers, value v, std::index_sequence<Is...>) { __builtin_trap() /* STUB: not implemented */; }

} // namespace key_selector_for_each_detail

template <typename Selector, typename... Handlers>
  requires key_selector_type<Selector> &&
           (sizeof...(Handlers) == Selector::size()) &&
           (key_selector_for_each_detail::field_handler<Handlers> && ...)
simdjson_flatten simdjson_inline for_each_result object::for_each(Handlers&&... on_match)
    noexcept(key_selector_for_each_detail::nothrow_field_handlers_v<Handlers...>) { __builtin_trap() /* STUB: not implemented */; }

template <constevalutil::fixed_string... Keys, typename... Handlers>
  requires (sizeof...(Handlers) == sizeof...(Keys)) &&
           (sizeof...(Keys) >= 1) && (sizeof...(Keys) <= 255) &&
           (key_selector_for_each_detail::field_handler<Handlers> && ...)
simdjson_inline for_each_result object::for_each(Handlers&&... on_match)
    noexcept(key_selector_for_each_detail::nothrow_field_handlers_v<Handlers...>) { __builtin_trap() /* STUB: not implemented */; }
#endif

simdjson_inline simdjson_result<object> object::start(value_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<object> object::start_root(value_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline error_code object::consume() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> object::raw_json() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<object> object::started(value_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline object object::resume(const value_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline object::object(const value_iterator &_iter) noexcept
  : iter{_iter}
{
}

simdjson_inline simdjson_result<object_iterator> object::begin() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<object_iterator> object::end() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<value> object::at_pointer(std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<value> object::at_path(std::string_view json_path) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Func>
  requires std::invocable<Func, value>
#else
template <typename Func>
#endif
inline error_code object::for_each_at_path_with_wildcard(std::string_view json_path, Func&& callback) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<size_t> object::count_fields() & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> object::is_empty() & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> object::reset() & noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS && SIMDJSON_STATIC_REFLECTION

template<constevalutil::fixed_string... FieldNames, typename T>
  requires(std::is_class_v<T> && (sizeof...(FieldNames) > 0))
simdjson_warn_unused simdjson_inline error_code object::extract_into(T& out) & noexcept { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_SUPPORTS_CONCEPTS && SIMDJSON_STATIC_REFLECTION

} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::simdjson_result(SIMDJSON_IMPLEMENTATION::ondemand::object &&value) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::object>(std::forward<SIMDJSON_IMPLEMENTATION::ondemand::object>(value)) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::simdjson_result(error_code error) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::object>(error) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object_iterator> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::begin() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object_iterator> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::end() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::find_field_unordered(std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::find_field_unordered(std::string_view key) && noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::operator[](std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::operator[](std::string_view key) && noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::find_field(std::string_view key) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::find_field(std::string_view key) && noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::at_pointer(std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::at_path(
    std::string_view json_path) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Func>
  requires std::invocable<Func, SIMDJSON_IMPLEMENTATION::ondemand::value>
#else
template <typename Func>
#endif
simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::for_each_at_path_with_wildcard(std::string_view json_path, Func&& callback) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Selector, typename Func>
  requires SIMDJSON_IMPLEMENTATION::ondemand::key_selector_type<Selector> &&
           std::is_invocable_v<Func&, std::size_t, SIMDJSON_IMPLEMENTATION::ondemand::value>
simdjson_inline SIMDJSON_IMPLEMENTATION::ondemand::for_each_result
simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::for_each(Func&& on_match)
    noexcept(std::is_nothrow_invocable_v<Func&, std::size_t, SIMDJSON_IMPLEMENTATION::ondemand::value>) { __builtin_trap() /* STUB: not implemented */; }

template <typename Selector, typename... Handlers>
  requires SIMDJSON_IMPLEMENTATION::ondemand::key_selector_type<Selector> &&
           (sizeof...(Handlers) == Selector::size()) &&
           (SIMDJSON_IMPLEMENTATION::ondemand::key_selector_for_each_detail::field_handler<Handlers> && ...)
simdjson_inline SIMDJSON_IMPLEMENTATION::ondemand::for_each_result
simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::for_each(Handlers&&... on_match)
    noexcept(SIMDJSON_IMPLEMENTATION::ondemand::key_selector_for_each_detail::nothrow_field_handlers_v<Handlers...>) { __builtin_trap() /* STUB: not implemented */; }

template <constevalutil::fixed_string... Keys, typename... Handlers>
  requires (sizeof...(Handlers) == sizeof...(Keys)) &&
           (sizeof...(Keys) >= 1) && (sizeof...(Keys) <= 255) &&
           (SIMDJSON_IMPLEMENTATION::ondemand::key_selector_for_each_detail::field_handler<Handlers> && ...)
simdjson_inline SIMDJSON_IMPLEMENTATION::ondemand::for_each_result
simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::for_each(Handlers&&... on_match)
    noexcept(SIMDJSON_IMPLEMENTATION::ondemand::key_selector_for_each_detail::nothrow_field_handlers_v<Handlers...>) { __builtin_trap() /* STUB: not implemented */; }
#endif

inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::reset() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::is_empty() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline  simdjson_result<size_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::count_fields() & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline  simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object>::raw_json() noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_OBJECT_INL_H
