#ifndef SIMDJSON_GENERIC_IMPLEMENTATION_SIMDJSON_RESULT_BASE_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_IMPLEMENTATION_SIMDJSON_RESULT_BASE_INL_H
#include "simdjson/generic/base.h"
#include "simdjson/generic/implementation_simdjson_result_base.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {

//
// internal::implementation_simdjson_result_base<T> inline implementation
//

template<typename T>
simdjson_inline void implementation_simdjson_result_base<T>::tie(T &value, error_code &error) && noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_warn_unused simdjson_inline error_code implementation_simdjson_result_base<T>::get(T &value) && noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_warn_unused simdjson_inline error_code implementation_simdjson_result_base<T>::error() const noexcept { __builtin_trap() /* STUB: not implemented */; }


template<typename T>
simdjson_warn_unused simdjson_inline bool implementation_simdjson_result_base<T>::has_value() const noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS

template<typename T>
simdjson_inline T& implementation_simdjson_result_base<T>::operator*() &  noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T&& implementation_simdjson_result_base<T>::operator*() &&  noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T* implementation_simdjson_result_base<T>::operator->() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }


template<typename T>
simdjson_inline const T* implementation_simdjson_result_base<T>::operator->() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T& implementation_simdjson_result_base<T>::value() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T&& implementation_simdjson_result_base<T>::value() && noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T&& implementation_simdjson_result_base<T>::take_value() && noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline implementation_simdjson_result_base<T>::operator T&&() && noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_EXCEPTIONS

template<typename T>
simdjson_inline const T& implementation_simdjson_result_base<T>::value_unsafe() const& noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T& implementation_simdjson_result_base<T>::value_unsafe() & noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T&& implementation_simdjson_result_base<T>::value_unsafe() && noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline implementation_simdjson_result_base<T>::implementation_simdjson_result_base(T &&value, error_code error) noexcept
    : first{std::forward<T>(value)}, second{error} {}
template<typename T>
simdjson_inline implementation_simdjson_result_base<T>::implementation_simdjson_result_base(error_code error) noexcept
    : implementation_simdjson_result_base(T{}, error) {}
template<typename T>
simdjson_inline implementation_simdjson_result_base<T>::implementation_simdjson_result_base(T &&value) noexcept
    : implementation_simdjson_result_base(std::forward<T>(value), SUCCESS) { __builtin_trap() /* STUB: not implemented */; }

} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_GENERIC_IMPLEMENTATION_SIMDJSON_RESULT_BASE_INL_H