#ifndef SIMDJSON_ERROR_INL_H
#define SIMDJSON_ERROR_INL_H

#include "simdjson/error.h"

#include <iostream>

namespace simdjson {

inline bool is_fatal(error_code error) noexcept { __builtin_trap() /* STUB: not implemented */; }

namespace internal {
  // We store the error code so we can validate the error message is associated with the right code
  struct error_code_info {
    error_code code;
    const char* message; // do not use a fancy std::string where a simple C string will do (no alloc, no destructor)
  };
  // These MUST match the codes in error_code. We check this constraint in basictests.
  extern SIMDJSON_DLLIMPORTEXPORT const error_code_info error_codes[];
} // namespace internal


inline const char *error_message(error_code error) noexcept { __builtin_trap() /* STUB: not implemented */; }

// deprecated function
#ifndef SIMDJSON_DISABLE_DEPRECATED_API
inline const std::string error_message(int error) noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_DISABLE_DEPRECATED_API

inline std::ostream& operator<<(std::ostream& out, error_code error) noexcept { __builtin_trap() /* STUB: not implemented */; }

namespace internal {

//
// internal::simdjson_result_base<T> inline implementation
//

template<typename T>
simdjson_inline void simdjson_result_base<T>::tie(T &value, error_code &error) && noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_warn_unused simdjson_inline error_code simdjson_result_base<T>::get(T &value) && noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline error_code simdjson_result_base<T>::error() const noexcept { __builtin_trap() /* STUB: not implemented */; }


template<typename T>
simdjson_inline bool simdjson_result_base<T>::has_value() const noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS


template<typename T>
simdjson_inline T& simdjson_result_base<T>::operator*() &  noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T&& simdjson_result_base<T>::operator*() &&  noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T* simdjson_result_base<T>::operator->() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }


template<typename T>
simdjson_inline const T* simdjson_result_base<T>::operator->() const noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T& simdjson_result_base<T>::value() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T&& simdjson_result_base<T>::value() && noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T&& simdjson_result_base<T>::take_value() && noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline simdjson_result_base<T>::operator T&&() && noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_EXCEPTIONS


template<typename T>
simdjson_inline const T& simdjson_result_base<T>::value_unsafe() const& noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T&& simdjson_result_base<T>::value_unsafe() && noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline simdjson_result_base<T>::simdjson_result_base(T &&value, error_code error) noexcept
    : std::pair<T, error_code>(std::forward<T>(value), error) { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_inline simdjson_result_base<T>::simdjson_result_base(error_code error) noexcept
    : simdjson_result_base(T{}, error) {}
template<typename T>
simdjson_inline simdjson_result_base<T>::simdjson_result_base(T &&value) noexcept
    : simdjson_result_base(std::forward<T>(value), SUCCESS) { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_inline simdjson_result_base<T>::simdjson_result_base() noexcept
    : simdjson_result_base(T{}, UNINITIALIZED) {}

} // namespace internal

///
/// simdjson_result<T> inline implementation
///

template<typename T>
simdjson_inline void simdjson_result<T>::tie(T &value, error_code &error) && noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_warn_unused simdjson_inline error_code
simdjson_result<T>::get(T &value) && noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline error_code simdjson_result<T>::error() const noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS

template<typename T>
simdjson_inline T& simdjson_result<T>::value() & noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T&& simdjson_result<T>::value() && noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T&& simdjson_result<T>::take_value() && noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline simdjson_result<T>::operator T&&() && noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_EXCEPTIONS

template<typename T>
simdjson_inline const T& simdjson_result<T>::value_unsafe() const& noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T&& simdjson_result<T>::value_unsafe() && noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline simdjson_result<T>::simdjson_result(T &&value, error_code error) noexcept
    : internal::simdjson_result_base<T>(std::forward<T>(value), error) { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_inline simdjson_result<T>::simdjson_result(error_code error) noexcept
    : internal::simdjson_result_base<T>(error) { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_inline simdjson_result<T>::simdjson_result(T &&value) noexcept
    : internal::simdjson_result_base<T>(std::forward<T>(value)) { __builtin_trap() /* STUB: not implemented */; }
template<typename T>
simdjson_inline simdjson_result<T>::simdjson_result() noexcept
    : internal::simdjson_result_base<T>() { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson

#endif // SIMDJSON_ERROR_INL_H
