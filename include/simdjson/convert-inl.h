
#ifndef SIMDJSON_CONVERT_INL_H
#define SIMDJSON_CONVERT_INL_H

#include "simdjson/convert.h"
#if SIMDJSON_SUPPORTS_CONCEPTS
namespace simdjson {
namespace convert {
namespace internal {
// auto_parser method definitions
template <typename parser_type>
inline auto_parser<parser_type>::auto_parser(parser_type &&parser, ondemand::document &&doc) noexcept requires(!std::is_pointer_v<parser_type>)
  : m_parser{std::move(parser)}, m_doc{std::move(doc)} { __builtin_trap() /* STUB: not implemented */; }

template <typename parser_type>
inline auto_parser<parser_type>::auto_parser(parser_type &&parser, padded_string_view const str) noexcept requires(!std::is_pointer_v<parser_type>)
  : m_parser{std::move(parser)}, m_doc{}, m_error{SUCCESS} { __builtin_trap() /* STUB: not implemented */; }

template <typename parser_type>
inline auto_parser<parser_type>::auto_parser(std::remove_pointer_t<parser_type> &parser, ondemand::document &&doc) noexcept requires(std::is_pointer_v<parser_type>)
  : m_parser{&parser}, m_doc{std::move(doc)} { __builtin_trap() /* STUB: not implemented */; }

template <typename parser_type>
inline auto_parser<parser_type>::auto_parser(std::remove_pointer_t<parser_type> &parser, padded_string_view const str) noexcept requires(std::is_pointer_v<parser_type>)
  : m_parser{&parser}, m_doc{}, m_error{SUCCESS} { __builtin_trap() /* STUB: not implemented */; }

template <typename parser_type>
inline auto_parser<parser_type>::auto_parser(padded_string_view const str) noexcept requires(std::is_pointer_v<parser_type>)
  : auto_parser{ondemand::parser::get_parser(), str} { __builtin_trap() /* STUB: not implemented */; }

template <typename parser_type>
inline auto_parser<parser_type>::auto_parser(parser_type parser, ondemand::document &&doc) noexcept requires(std::is_pointer_v<parser_type>)
  : auto_parser{*parser, std::move(doc)} { __builtin_trap() /* STUB: not implemented */; }


template <typename parser_type>
inline std::remove_pointer_t<parser_type> &auto_parser<parser_type>::parser() noexcept { __builtin_trap() /* STUB: not implemented */; }

template <typename parser_type>
template <typename T>
inline simdjson_result<T> auto_parser<parser_type>::result() noexcept(is_nothrow_gettable<T>) { __builtin_trap() /* STUB: not implemented */; }

template <typename parser_type>
template <typename T>
simdjson_warn_unused simdjson_inline error_code auto_parser<parser_type>::get(T &value) && noexcept(is_nothrow_gettable<T>) { __builtin_trap() /* STUB: not implemented */; }

template <typename parser_type>
inline simdjson_result<ondemand::array> auto_parser<parser_type>::array() noexcept { __builtin_trap() /* STUB: not implemented */; }

template <typename parser_type>
inline simdjson_result<ondemand::object> auto_parser<parser_type>::object() noexcept { __builtin_trap() /* STUB: not implemented */; }

template <typename parser_type>
inline simdjson_result<ondemand::number> auto_parser<parser_type>::number() noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS
template <typename parser_type>
template <typename T>
inline auto_parser<parser_type>::operator T() noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_EXCEPTIONS

template <typename parser_type>
template <typename T>
inline std::optional<T> auto_parser<parser_type>::optional() noexcept(is_nothrow_gettable<T>) { __builtin_trap() /* STUB: not implemented */; }

// to_adaptor method definitions
template <typename T>
inline T to_adaptor<T>::operator()(simdjson_result<ondemand::value> &val) const noexcept { __builtin_trap() /* STUB: not implemented */; }

template <typename T>
inline auto to_adaptor<T>::operator()(padded_string_view const str) const noexcept { __builtin_trap() /* STUB: not implemented */; }

template <typename T>
inline auto to_adaptor<T>::operator()(ondemand::parser &parser, padded_string_view const str) const noexcept { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal
} // namespace convert
} // namespace simdjson
#endif // SIMDJSON_SUPPORTS_CONCEPTS
#endif // SIMDJSON_CONVERT_INL_H
