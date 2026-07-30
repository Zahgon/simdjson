#ifndef SIMDJSON_PARSER_INL_H
#define SIMDJSON_PARSER_INL_H

#include "simdjson/dom/base.h"
#include "simdjson/dom/document_stream.h"
#include "simdjson/implementation.h"
#include "simdjson/internal/dom_parser_implementation.h"

#include "simdjson/error-inl.h"
#include "simdjson/padded_string-inl.h"
#include "simdjson/dom/document_stream-inl.h"
#include "simdjson/dom/element-inl.h"

#include <climits>
#include <cstring> /* memcmp */

namespace simdjson {
namespace dom {

//
// parser inline implementation
//
simdjson_inline parser::parser(size_t max_capacity) noexcept
  : _max_capacity{max_capacity},
    loaded_bytes(nullptr) {
}
simdjson_inline parser::parser(parser &&other) noexcept = default;
simdjson_inline parser &parser::operator=(parser &&other) noexcept = default;

inline bool parser::is_valid() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline int parser::get_error_code() const noexcept { __builtin_trap() /* STUB: not implemented */; }
inline std::string parser::get_error_message() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool parser::dump_raw_tape(std::ostream &os) const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<size_t> parser::read_file(std::string_view path) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> parser::load(std::string_view path) & noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> parser::load_into_document(document& provided_doc, std::string_view path) & noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<document_stream> parser::load_many(std::string_view path, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> parser::parse_into_document(document& provided_doc, const uint8_t *buf, size_t len, bool realloc_if_needed) & noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> parser::parse_into_document_unpadded(document& provided_doc, const uint8_t *buf, size_t len) & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<element> parser::parse_into_document(document& provided_doc, const char *buf, size_t len, bool realloc_if_needed) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<element> parser::parse_into_document(document& provided_doc, const std::string &s) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<element> parser::parse_into_document(document& provided_doc, const padded_string &s) & noexcept { __builtin_trap() /* STUB: not implemented */; }


inline simdjson_result<element> parser::parse(const uint8_t *buf, size_t len, bool realloc_if_needed) & noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<element> parser::parse(const char *buf, size_t len, bool realloc_if_needed) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<element> parser::parse(const std::string &s) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<element> parser::parse(const padded_string &s) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<element> parser::parse(const padded_string_view &v) & noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<element> parser::parse_unpadded(const uint8_t *buf, size_t len) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<element> parser::parse_unpadded(const char *buf, size_t len) & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<element> parser::parse_unpadded(std::string_view s) & noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<document_stream> parser::parse_many(const uint8_t *buf, size_t len, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::parse_many(const char *buf, size_t len, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::parse_many(const std::string &s, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::parse_many(const padded_string &s, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::parse_many(const padded_string_view &v, size_t batch_size) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<document_stream> parser::parse_many(const uint8_t *buf, size_t len, size_t batch_size, stream_format format) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::parse_many(const char *buf, size_t len, size_t batch_size, stream_format format) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::parse_many(const std::string &s, size_t batch_size, stream_format format) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::parse_many(const padded_string &s, size_t batch_size, stream_format format) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline simdjson_result<document_stream> parser::parse_many(const padded_string_view &v, size_t batch_size, stream_format format) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline size_t parser::capacity() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline size_t parser::max_capacity() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_pure simdjson_inline size_t parser::max_depth() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused
inline error_code parser::allocate(size_t capacity, size_t max_depth) noexcept { __builtin_trap() /* STUB: not implemented */; }

#ifndef SIMDJSON_DISABLE_DEPRECATED_API
simdjson_warn_unused
inline bool parser::allocate_capacity(size_t capacity, size_t max_depth) noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_DISABLE_DEPRECATED_API

inline error_code parser::ensure_capacity(size_t desired_capacity) noexcept { __builtin_trap() /* STUB: not implemented */; }


inline error_code parser::ensure_capacity(document& target_document, size_t desired_capacity) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void parser::set_max_capacity(size_t max_capacity) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace dom
} // namespace simdjson

#endif // SIMDJSON_PARSER_INL_H
