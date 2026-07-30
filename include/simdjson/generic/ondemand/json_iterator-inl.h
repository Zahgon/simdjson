#ifndef SIMDJSON_GENERIC_ONDEMAND_JSON_ITERATOR_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_JSON_ITERATOR_INL_H
#include "simdjson/internal/dom_parser_implementation.h"
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/json_iterator.h"
#include "simdjson/generic/ondemand/parser.h"
#include "simdjson/generic/ondemand/raw_json_string.h"
#include "simdjson/generic/ondemand/logger-inl.h"
#include "simdjson/generic/ondemand/parser-inl.h"
#include "simdjson/generic/ondemand/token_iterator-inl.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

simdjson_inline json_iterator::json_iterator(json_iterator &&other) noexcept
  : token(std::forward<token_iterator>(other.token)),
    parser{other.parser},
    _string_buf_loc{other._string_buf_loc},
    error{other.error},
    _depth{other._depth},
    _root{other._root},
    _streaming{other._streaming}
#ifdef SIMDJSON_EXPERIMENTAL_ALLOW_INCOMPLETE_JSON
    , _allow_incomplete_json{other._allow_incomplete_json}
#endif
{
  other.parser = nullptr;
}
simdjson_inline json_iterator &json_iterator::operator=(json_iterator &&other) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline json_iterator::json_iterator(const uint8_t *buf, ondemand::parser *_parser) noexcept
  : token(buf, &_parser->implementation->structural_indexes[0]),
    parser{_parser},
    _string_buf_loc{parser->string_buf.get()},
    _depth{1},
    _root{parser->implementation->structural_indexes.get()},
    _streaming{false}

{
  logger::log_headers();
#if SIMDJSON_CHECK_EOF
  assert_more_tokens();
#endif
}

#ifdef SIMDJSON_EXPERIMENTAL_ALLOW_INCOMPLETE_JSON
simdjson_inline json_iterator::json_iterator(const uint8_t *buf, ondemand::parser *_parser, bool streaming) noexcept
    : token(buf, &_parser->implementation->structural_indexes[0]),
      parser{_parser},
      _string_buf_loc{parser->string_buf.get()},
      _depth{1},
      _root{parser->implementation->structural_indexes.get()},
      _streaming{streaming},
      _allow_incomplete_json{true}

{
  logger::log_headers();
#if SIMDJSON_CHECK_EOF
  assert_more_tokens();
#endif
}
#endif // SIMDJSON_EXPERIMENTAL_ALLOW_INCOMPLETE_JSON

inline void json_iterator::rewind() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool json_iterator::balanced() const noexcept { __builtin_trap() /* STUB: not implemented */; }


// GCC 7 warns when the first line of this function is inlined away into oblivion due to the caller
// relating depth and parent_depth, which is a desired effect. The warning does not show up if the
// skip_child() function is not marked inline).
SIMDJSON_PUSH_DISABLE_WARNINGS
SIMDJSON_DISABLE_STRICT_OVERFLOW_WARNING
simdjson_warn_unused simdjson_inline error_code json_iterator::skip_child(depth_t parent_depth) noexcept { __builtin_trap() /* STUB: not implemented */; }

SIMDJSON_POP_DISABLE_WARNINGS

simdjson_inline bool json_iterator::at_root() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool json_iterator::is_single_token() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool json_iterator::streaming() const noexcept { __builtin_trap() /* STUB: not implemented */; }

#ifdef SIMDJSON_EXPERIMENTAL_ALLOW_INCOMPLETE_JSON
simdjson_inline bool json_iterator::allow_incomplete_json() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline size_t json_iterator::remaining_input_length(const uint8_t *json) const noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_EXPERIMENTAL_ALLOW_INCOMPLETE_JSON

simdjson_inline token_position json_iterator::root_position() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::assert_at_document_depth() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::assert_at_root() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::assert_more_tokens(uint32_t required_tokens) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::assert_valid_position(token_position position) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool json_iterator::at_end() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline token_position json_iterator::end_position() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline std::string json_iterator::to_string() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<const char *> json_iterator::current_location() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool json_iterator::is_alive() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::abandon() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline const uint8_t *json_iterator::return_current_and_advance() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline const uint8_t *json_iterator::unsafe_pointer() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline const uint8_t *json_iterator::peek(int32_t delta) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline uint32_t json_iterator::peek_length(int32_t delta) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline const uint8_t *json_iterator::peek(token_position position) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline uint32_t json_iterator::peek_length(token_position position) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline uint32_t json_iterator::peek_root_length(token_position position) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline token_position json_iterator::last_position() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline const uint8_t *json_iterator::peek_last() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::ascend_to(depth_t parent_depth) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::descend_to(depth_t child_depth) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline depth_t json_iterator::depth() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline uint8_t *&json_iterator::string_buf_loc() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code json_iterator::report_error(error_code _error, const char *message) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline token_position json_iterator::position() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> json_iterator::unescape(raw_json_string in, bool allow_replacement) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> json_iterator::unescape_wobbly(raw_json_string in) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::reenter_child(token_position position, depth_t child_depth) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code json_iterator::consume_character(char c) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_DEVELOPMENT_CHECKS

simdjson_inline token_position json_iterator::start_position(depth_t depth) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::set_start_position(depth_t depth, token_position position) noexcept { __builtin_trap() /* STUB: not implemented */; }

#endif


simdjson_warn_unused simdjson_inline error_code json_iterator::optional_error(error_code _error, const char *message) noexcept { __builtin_trap() /* STUB: not implemented */; }


simdjson_warn_unused simdjson_inline bool json_iterator::copy_to_buffer(const uint8_t *json, uint32_t max_len, uint8_t *tmpbuf, size_t N) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::json_iterator>::simdjson_result(SIMDJSON_IMPLEMENTATION::ondemand::json_iterator &&value) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::json_iterator>(std::forward<SIMDJSON_IMPLEMENTATION::ondemand::json_iterator>(value)) { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::json_iterator>::simdjson_result(error_code error) noexcept
    : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::json_iterator>(error) { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_JSON_ITERATOR_INL_H
