#ifndef SIMDJSON_GENERIC_ONDEMAND_JSON_TYPE_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_JSON_TYPE_INL_H
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/json_type.h"
#include "simdjson/generic/implementation_simdjson_result_base-inl.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

inline std::ostream& operator<<(std::ostream& out, json_type type) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS
inline std::ostream& operator<<(std::ostream& out, simdjson_result<json_type> &type) noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
#endif



simdjson_inline number_type number::get_number_type() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool number::is_uint64() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline uint64_t number::get_uint64() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline number::operator uint64_t() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool number::is_int64() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline int64_t number::get_int64() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline number::operator int64_t() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool number::is_double() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline double number::get_double() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline number::operator double() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline double number::as_double() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void number::append_s64(int64_t value) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void number::append_u64(uint64_t value) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void number::append_double(double value) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void number::skip_double() noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::json_type>::simdjson_result(SIMDJSON_IMPLEMENTATION::ondemand::json_type &&value) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::json_type>(std::forward<SIMDJSON_IMPLEMENTATION::ondemand::json_type>(value)) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::json_type>::simdjson_result(error_code error) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::json_type>(error) { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_JSON_TYPE_INL_H