#ifndef SIMDJSON_GENERIC_ONDEMAND_FIELD_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_FIELD_INL_H
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/field.h"
#include "simdjson/generic/ondemand/value-inl.h"
#include "simdjson/generic/ondemand/value_iterator-inl.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

// clang 6 does not think the default constructor can be noexcept, so we make it explicit
simdjson_inline field::field() noexcept : std::pair<raw_json_string, ondemand::value>() { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline field::field(raw_json_string key, ondemand::value &&value) noexcept
  : std::pair<raw_json_string, ondemand::value>(key, std::forward<ondemand::value>(value))
{ __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<field> field::start(value_iterator &parent_iter) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<field> field::start(const value_iterator &parent_iter, raw_json_string key) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_warn_unused simdjson_result<std::string_view> field::unescaped_key(bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <typename string_type>
simdjson_inline simdjson_warn_unused error_code field::unescaped_key(string_type& receiver, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline raw_json_string field::key() const noexcept { __builtin_trap() /* STUB: not implemented */; }


simdjson_inline std::string_view field::key_raw_json_token() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline std::string_view field::escaped_key() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline value &field::value() & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline value field::value() && noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::field>::simdjson_result(
  SIMDJSON_IMPLEMENTATION::ondemand::field &&value
) noexcept :
    implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::field>(
      std::forward<SIMDJSON_IMPLEMENTATION::ondemand::field>(value)
    )
{ __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::field>::simdjson_result(
  error_code error
) noexcept :
    implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::field>(error)
{ __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::field>::key() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::field>::key_raw_json_token() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::field>::escaped_key() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::field>::unescaped_key(bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename string_type>
simdjson_warn_unused simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::field>::unescaped_key(string_type &receiver, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::field>::value() noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_FIELD_INL_H