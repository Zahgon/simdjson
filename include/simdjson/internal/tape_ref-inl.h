#ifndef SIMDJSON_TAPE_REF_INL_H
#define SIMDJSON_TAPE_REF_INL_H

#include "simdjson/dom/document.h"
#include "simdjson/internal/tape_ref.h"
#include "simdjson/internal/tape_type.h"

#include <cstring>

namespace simdjson {
namespace internal {

constexpr const uint64_t JSON_VALUE_MASK = 0x00FFFFFFFFFFFFFF;
constexpr const uint32_t JSON_COUNT_MASK = 0xFFFFFF;

//
// tape_ref inline implementation
//
simdjson_inline tape_ref::tape_ref() noexcept : doc{nullptr}, json_index{0} {}
simdjson_inline tape_ref::tape_ref(const dom::document *_doc, size_t _json_index) noexcept : doc{_doc}, json_index{_json_index} {}


simdjson_inline bool tape_ref::is_document_root() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool tape_ref::usable() const noexcept { __builtin_trap() /* STUB: not implemented */; }
// Some value types have a specific on-tape word value. It can be faster
// to check the type by doing a word-to-word comparison instead of extracting the
// most significant 8 bits.

simdjson_inline bool tape_ref::is_double() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool tape_ref::is_int64() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool tape_ref::is_uint64() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool tape_ref::is_false() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool tape_ref::is_true() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool tape_ref::is_null_on_tape() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline size_t tape_ref::after_element() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline tape_type tape_ref::tape_ref_type() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline uint64_t internal::tape_ref::tape_value() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline uint32_t internal::tape_ref::matching_brace_index() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline uint32_t internal::tape_ref::scope_count() const noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline T tape_ref::next_tape_value() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline uint32_t internal::tape_ref::get_string_length() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline const char * internal::tape_ref::get_c_str() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline std::string_view internal::tape_ref::get_string_view() const noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace internal
} // namespace simdjson

#endif // SIMDJSON_TAPE_REF_INL_H
