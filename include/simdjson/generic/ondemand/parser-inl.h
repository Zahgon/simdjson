#ifndef SIMDJSON_GENERIC_ONDEMAND_PARSER_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_PARSER_INL_H
#include "simdjson/padded_string.h"
#include "simdjson/padded_string_view.h"
#include "simdjson/implementation.h"
#include "simdjson/internal/dom_parser_implementation.h"
#include "simdjson/dom/base.h" // for MINIMAL_DOCUMENT_CAPACITY
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/document_stream.h"
#include "simdjson/generic/ondemand/parser.h"
#include "simdjson/generic/ondemand/raw_json_string.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

simdjson_inline parser::parser(size_t max_capacity) noexcept
  : _max_capacity{max_capacity} {
}

simdjson_warn_unused simdjson_inline error_code parser::allocate(size_t new_capacity, size_t new_max_depth) noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_DEVELOPMENT_CHECKS
simdjson_inline simdjson_warn_unused bool parser::string_buffer_overflow(const uint8_t *string_buf_loc) const noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif

simdjson_warn_unused simdjson_inline simdjson_result<document> parser::iterate(padded_string_view json) & noexcept { __builtin_trap() /* STUB: not implemented */; }

#ifdef SIMDJSON_EXPERIMENTAL_ALLOW_INCOMPLETE_JSON
simdjson_warn_unused simdjson_inline simdjson_result<document> parser::iterate_allow_incomplete_json(padded_string_view json) & noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_EXPERIMENTAL_ALLOW_INCOMPLETE_JSON

simdjson_warn_unused simdjson_inline simdjson_result<document> parser::iterate(const char *json, size_t len, size_t allocated) & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<document> parser::iterate(const uint8_t *json, size_t len, size_t allocated) & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<document> parser::iterate(std::string_view json, size_t allocated) & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<document> parser::iterate(std::string &json) & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<document> parser::iterate(const std::string &json) & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<document> parser::iterate(const simdjson_result<padded_string_view> &result) & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<document> parser::iterate(const simdjson_result<padded_string> &result) & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline simdjson_result<json_iterator> parser::iterate_raw(padded_string_view json) & noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<document_stream> parser::iterate_many(const uint8_t *buf, size_t len, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(const char *buf, size_t len, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(padded_string_view s, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(const padded_string &s, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(const std::string &s, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(std::string &s, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }

#ifndef SIMDJSON_DISABLE_DEPRECATED_API
SIMDJSON_PUSH_DISABLE_WARNINGS
SIMDJSON_DISABLE_DEPRECATED_WARNING
inline simdjson_result<document_stream> parser::iterate_many(const uint8_t *buf, size_t len, size_t batch_size, bool allow_comma_separated) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<document_stream> parser::iterate_many(const char *buf, size_t len, size_t batch_size, bool allow_comma_separated) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(padded_string_view s, size_t batch_size, bool allow_comma_separated) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(const padded_string &s, size_t batch_size, bool allow_comma_separated) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(const std::string &s, size_t batch_size, bool allow_comma_separated) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(std::string &s, size_t batch_size, bool allow_comma_separated) noexcept { __builtin_trap() /* STUB: not implemented */; }
SIMDJSON_POP_DISABLE_WARNINGS
#endif // SIMDJSON_DISABLE_DEPRECATED_API

inline simdjson_result<document_stream> parser::iterate_many(const uint8_t *buf, size_t len, size_t batch_size, stream_format format) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(const char *buf, size_t len, size_t batch_size, stream_format format) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(padded_string_view s, size_t batch_size, stream_format format) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(const std::string &s, size_t batch_size, stream_format format) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::iterate_many(const padded_string &s, size_t batch_size, stream_format format) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_pure simdjson_inline size_t parser::capacity() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_pure simdjson_inline size_t parser::max_capacity() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_pure simdjson_inline size_t parser::max_depth() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void parser::set_max_capacity(size_t max_capacity) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_warn_unused simdjson_result<std::string_view> parser::unescape(raw_json_string in, uint8_t *&dst, bool allow_replacement) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_warn_unused simdjson_result<std::string_view> parser::unescape_wobbly(raw_json_string in, uint8_t *&dst) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_warn_unused ondemand::parser& parser::get_parser() { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool parser::release_parser() { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_warn_unused std::unique_ptr<ondemand::parser>& parser::get_parser_instance() { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_warn_unused std::unique_ptr<ondemand::parser>& parser::get_threadlocal_parser_if_exists() { __builtin_trap() /* STUB: not implemented */; }


} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::parser>::simdjson_result(SIMDJSON_IMPLEMENTATION::ondemand::parser &&value) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::parser>(std::forward<SIMDJSON_IMPLEMENTATION::ondemand::parser>(value)) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::parser>::simdjson_result(error_code error) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::parser>(error) { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_PARSER_INL_H
