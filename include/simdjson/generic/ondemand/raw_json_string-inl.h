#ifndef SIMDJSON_GENERIC_ONDEMAND_RAW_JSON_STRING_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_RAW_JSON_STRING_INL_H
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/raw_json_string.h"
#include "simdjson/generic/ondemand/json_iterator-inl.h"
#include "simdjson/generic/implementation_simdjson_result_base-inl.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {

namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

simdjson_inline raw_json_string::raw_json_string(const uint8_t * _buf) noexcept : buf{_buf} {}

simdjson_inline const char * raw_json_string::raw() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline char raw_json_string::operator[](size_t i) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool raw_json_string::is_free_from_unescaped_quote(std::string_view target) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool raw_json_string::is_free_from_unescaped_quote(const char* target) noexcept { __builtin_trap() /* STUB: not implemented */; }


simdjson_inline bool raw_json_string::unsafe_is_equal(size_t length, std::string_view target) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool raw_json_string::unsafe_is_equal(std::string_view target) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool raw_json_string::is_equal(std::string_view target) const noexcept { __builtin_trap() /* STUB: not implemented */; }


simdjson_inline bool raw_json_string::unsafe_is_equal(const char * target) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool raw_json_string::is_equal(const char* target) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline bool operator==(const raw_json_string &a, std::string_view c) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline bool operator==(std::string_view c, const raw_json_string &a) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline bool operator!=(const raw_json_string &a, std::string_view c) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline bool operator!=(std::string_view c, const raw_json_string &a) noexcept { __builtin_trap() /* STUB: not implemented */; }


simdjson_inline simdjson_warn_unused simdjson_result<std::string_view> raw_json_string::unescape(json_iterator &iter, bool allow_replacement) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_warn_unused simdjson_result<std::string_view> raw_json_string::unescape_wobbly(json_iterator &iter) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline std::ostream &operator<<(std::ostream &out, const raw_json_string &str) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string>::simdjson_result(SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string &&value) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string>(std::forward<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string>(value)) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string>::simdjson_result(error_code error) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string>(error) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<const char *> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string>::raw() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline char simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string>::operator[](size_t i) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_warn_unused simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string>::unescape(SIMDJSON_IMPLEMENTATION::ondemand::json_iterator &iter, bool allow_replacement) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_warn_unused simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::raw_json_string>::unescape_wobbly(SIMDJSON_IMPLEMENTATION::ondemand::json_iterator &iter) const noexcept { __builtin_trap() /* STUB: not implemented */; }
} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_RAW_JSON_STRING_INL_H