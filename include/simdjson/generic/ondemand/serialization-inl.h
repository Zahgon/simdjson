#ifndef SIMDJSON_GENERIC_ONDEMAND_SERIALIZATION_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_SERIALIZATION_INL_H
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/array.h"
#include "simdjson/generic/ondemand/document-inl.h"
#include "simdjson/generic/ondemand/json_type.h"
#include "simdjson/generic/ondemand/object.h"
#include "simdjson/generic/ondemand/serialization.h"
#include "simdjson/generic/ondemand/value.h"
#if SIMDJSON_STATIC_REFLECTION
#include "simdjson/generic/builder/json_builder.h"
#endif
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {

inline std::string_view trim(const std::string_view str) noexcept { __builtin_trap() /* STUB: not implemented */; }


inline simdjson_result<std::string_view> to_json_string(SIMDJSON_IMPLEMENTATION::ondemand::document& x) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::string_view> to_json_string(SIMDJSON_IMPLEMENTATION::ondemand::document_reference& x) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::string_view> to_json_string(SIMDJSON_IMPLEMENTATION::ondemand::value& x) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::string_view> to_json_string(SIMDJSON_IMPLEMENTATION::ondemand::object& x) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::string_view> to_json_string(SIMDJSON_IMPLEMENTATION::ondemand::array& x) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::string_view> to_json_string(simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document> x) { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::string_view> to_json_string(simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_reference> x) { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::string_view> to_json_string(simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> x) { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::string_view> to_json_string(simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::object> x) { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<std::string_view> to_json_string(simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array> x) { __builtin_trap() /* STUB: not implemented */; }
} // namespace simdjson

namespace simdjson { namespace SIMDJSON_IMPLEMENTATION { namespace ondemand {

#if SIMDJSON_EXCEPTIONS
inline std::ostream& operator<<(std::ostream& out, simdjson::SIMDJSON_IMPLEMENTATION::ondemand::value x) { __builtin_trap() /* STUB: not implemented */; }
inline std::ostream& operator<<(std::ostream& out, simdjson::simdjson_result<simdjson::SIMDJSON_IMPLEMENTATION::ondemand::value> x) { __builtin_trap() /* STUB: not implemented */; }
#else
inline std::ostream& operator<<(std::ostream& out, simdjson::SIMDJSON_IMPLEMENTATION::ondemand::value x) { __builtin_trap() /* STUB: not implemented */; }
#endif

#if SIMDJSON_EXCEPTIONS
inline std::ostream& operator<<(std::ostream& out, simdjson::SIMDJSON_IMPLEMENTATION::ondemand::array value) { __builtin_trap() /* STUB: not implemented */; }
inline std::ostream& operator<<(std::ostream& out, simdjson::simdjson_result<simdjson::SIMDJSON_IMPLEMENTATION::ondemand::array> x) { __builtin_trap() /* STUB: not implemented */; }
#else
inline std::ostream& operator<<(std::ostream& out, simdjson::SIMDJSON_IMPLEMENTATION::ondemand::array value) { __builtin_trap() /* STUB: not implemented */; }
#endif

#if SIMDJSON_EXCEPTIONS
inline std::ostream& operator<<(std::ostream& out, simdjson::SIMDJSON_IMPLEMENTATION::ondemand::document& value)  { __builtin_trap() /* STUB: not implemented */; }
inline std::ostream& operator<<(std::ostream& out, simdjson::SIMDJSON_IMPLEMENTATION::ondemand::document_reference& value)  { __builtin_trap() /* STUB: not implemented */; }
inline std::ostream& operator<<(std::ostream& out, simdjson::simdjson_result<simdjson::SIMDJSON_IMPLEMENTATION::ondemand::document>&& x) { __builtin_trap() /* STUB: not implemented */; }
inline std::ostream& operator<<(std::ostream& out, simdjson::simdjson_result<simdjson::SIMDJSON_IMPLEMENTATION::ondemand::document_reference>&& x) { __builtin_trap() /* STUB: not implemented */; }
#else
inline std::ostream& operator<<(std::ostream& out, simdjson::SIMDJSON_IMPLEMENTATION::ondemand::document& value)  { __builtin_trap() /* STUB: not implemented */; }
#endif

#if SIMDJSON_EXCEPTIONS
inline std::ostream& operator<<(std::ostream& out, simdjson::SIMDJSON_IMPLEMENTATION::ondemand::object value) { __builtin_trap() /* STUB: not implemented */; }
inline std::ostream& operator<<(std::ostream& out,  simdjson::simdjson_result<simdjson::SIMDJSON_IMPLEMENTATION::ondemand::object> x) { __builtin_trap() /* STUB: not implemented */; }
#else
inline std::ostream& operator<<(std::ostream& out, simdjson::SIMDJSON_IMPLEMENTATION::ondemand::object value) { __builtin_trap() /* STUB: not implemented */; }
#endif
}}} // namespace simdjson::SIMDJSON_IMPLEMENTATION::ondemand

#endif // SIMDJSON_GENERIC_ONDEMAND_SERIALIZATION_INL_H