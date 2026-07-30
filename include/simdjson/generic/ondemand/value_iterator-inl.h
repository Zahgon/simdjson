#ifndef SIMDJSON_GENERIC_ONDEMAND_VALUE_ITERATOR_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_VALUE_ITERATOR_INL_H
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/atomparsing.h"
#include "simdjson/generic/numberparsing.h"
#include "simdjson/generic/ondemand/json_iterator.h"
#include "simdjson/generic/ondemand/value_iterator.h"
#include "simdjson/generic/ondemand/json_type-inl.h"
#include "simdjson/generic/ondemand/raw_json_string-inl.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

#ifdef SIMDJSON_EXPERIMENTAL_ALLOW_INCOMPLETE_JSON
simdjson_inline bool raw_json_string_is_quote_terminated(const uint8_t *json, uint32_t max_len) noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_EXPERIMENTAL_ALLOW_INCOMPLETE_JSON

simdjson_inline value_iterator::value_iterator(
  json_iterator *json_iter,
  depth_t depth,
  token_position start_position
) noexcept : _json_iter{json_iter}, _depth{depth}, _start_position{start_position}
{
}

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::start_object() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::start_root_object() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::started_object() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code value_iterator::check_root_object() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::started_root_object() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code value_iterator::end_container() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::has_next_field() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::find_field_raw(const std::string_view key) noexcept { __builtin_trap() /* STUB: not implemented */; }

SIMDJSON_PUSH_DISABLE_WARNINGS
SIMDJSON_DISABLE_STRICT_OVERFLOW_WARNING
simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::find_field_unordered_raw(const std::string_view key) noexcept { __builtin_trap() /* STUB: not implemented */; }
SIMDJSON_POP_DISABLE_WARNINGS

simdjson_warn_unused simdjson_inline simdjson_result<raw_json_string> value_iterator::field_key() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code value_iterator::field_key_with_length(raw_json_string &key, std::size_t &len) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code value_iterator::field_value() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::start_array() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::start_root_array() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline std::string value_iterator::to_string() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::started_array() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code value_iterator::check_root_array() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::started_root_array() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::has_next_element() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::parse_bool(const uint8_t *json) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::parse_null(const uint8_t *json) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<std::string_view> value_iterator::get_string(bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <typename string_type>
simdjson_warn_unused simdjson_inline error_code value_iterator::get_string(string_type& receiver, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<std::string_view> value_iterator::get_wobbly_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<raw_json_string> value_iterator::get_raw_json_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<uint64_t> value_iterator::get_uint64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<uint64_t> value_iterator::get_uint64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<int64_t> value_iterator::get_int64() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<int64_t> value_iterator::get_int64_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<double> value_iterator::get_double() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<double> value_iterator::get_double_in_string() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::get_bool() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> value_iterator::is_null() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool value_iterator::is_negative() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool value_iterator::is_root_negative() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<bool> value_iterator::is_integer() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<number_type> value_iterator::get_number_type() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<number> value_iterator::get_number() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> value_iterator::is_root_integer(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::number_type> value_iterator::get_root_number_type(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<number> value_iterator::get_root_number(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<std::string_view> value_iterator::get_root_string(bool check_trailing, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <typename string_type>
simdjson_warn_unused simdjson_inline error_code value_iterator::get_root_string(string_type& receiver, bool check_trailing, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<std::string_view> value_iterator::get_root_wobbly_string(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<raw_json_string> value_iterator::get_root_raw_json_string(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<uint64_t> value_iterator::get_root_uint64(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<uint64_t> value_iterator::get_root_uint64_in_string(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<int64_t> value_iterator::get_root_int64(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<int64_t> value_iterator::get_root_int64_in_string(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline simdjson_result<double> value_iterator::get_root_double(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<double> value_iterator::get_root_double_in_string(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<bool> value_iterator::get_root_bool(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> value_iterator::is_root_null(bool check_trailing) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code value_iterator::skip_child() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline value_iterator value_iterator::child() const noexcept { __builtin_trap() /* STUB: not implemented */; }

// GCC 7 warns when the first line of this function is inlined away into oblivion due to the caller
// relating depth and iterator depth, which is a desired effect. It does not happen if is_open is
// marked non-inline.
SIMDJSON_PUSH_DISABLE_WARNINGS
SIMDJSON_DISABLE_STRICT_OVERFLOW_WARNING
simdjson_inline bool value_iterator::is_open() const noexcept { __builtin_trap() /* STUB: not implemented */; }
SIMDJSON_POP_DISABLE_WARNINGS

simdjson_inline bool value_iterator::at_end() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool value_iterator::at_start() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool value_iterator::at_first_field() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void value_iterator::abandon() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline depth_t value_iterator::depth() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline error_code value_iterator::error() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline uint8_t *&value_iterator::string_buf_loc() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline const json_iterator &value_iterator::json_iter() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_inline json_iterator &value_iterator::json_iter() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline const uint8_t *value_iterator::peek_start() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline uint32_t value_iterator::peek_start_length() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline uint32_t value_iterator::peek_root_length() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline const uint8_t *value_iterator::peek_scalar(const char *type) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void value_iterator::advance_scalar(const char *type) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code value_iterator::start_container(uint8_t start_char, const char *incorrect_type_message, const char *type) noexcept { __builtin_trap() /* STUB: not implemented */; }


simdjson_inline const uint8_t *value_iterator::peek_root_scalar(const char *type) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline const uint8_t *value_iterator::peek_non_root_scalar(const char *type) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void value_iterator::advance_root_scalar(const char *type) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline void value_iterator::advance_non_root_scalar(const char *type) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline error_code value_iterator::incorrect_type_error(const char *message) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool value_iterator::is_at_start() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool value_iterator::is_at_key() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool value_iterator::is_at_iterator_start() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void value_iterator::assert_at_start() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void value_iterator::assert_at_container_start() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void value_iterator::assert_at_next() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void value_iterator::move_at_start() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void value_iterator::move_at_container_start() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> value_iterator::reset_array() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<bool> value_iterator::reset_object() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void value_iterator::assert_at_child() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void value_iterator::assert_at_root() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void value_iterator::assert_at_non_root_start() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void value_iterator::assert_is_valid() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool value_iterator::is_valid() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<json_type> value_iterator::type() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline token_position value_iterator::start_position() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline token_position value_iterator::position() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline token_position value_iterator::end_position() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline token_position value_iterator::last_position() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline error_code value_iterator::report_error(error_code error, const char *message) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value_iterator>::simdjson_result(SIMDJSON_IMPLEMENTATION::ondemand::value_iterator &&value) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::value_iterator>(std::forward<SIMDJSON_IMPLEMENTATION::ondemand::value_iterator>(value)) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value_iterator>::simdjson_result(error_code error) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::value_iterator>(error) { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_VALUE_ITERATOR_INL_H
