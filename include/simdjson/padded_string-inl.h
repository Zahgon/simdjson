#ifndef SIMDJSON_PADDED_STRING_INL_H
#define SIMDJSON_PADDED_STRING_INL_H

#include "simdjson/padded_string.h"
#include "simdjson/padded_string_view.h"

#include "simdjson/error-inl.h"
#include "simdjson/padded_string_view-inl.h"

#include <climits>
#include <cwchar>

#if SIMDJSON_HAS_UNISTD_H
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
// On Windows, `padded_memory_map` (when it is enabled) depends on types and
// functions declared in <windows.h>. We deliberately do NOT include that
// header here: users of simdjson who want `padded_memory_map` on Windows
// must include <windows.h> themselves *before* including this header. See
// padded_string.h for the detection logic.

namespace simdjson {
namespace internal {

// The allocate_padded_buffer function is a low-level function to allocate memory
// with padding so we can read past the "length" bytes safely. It is used by
// the padded_string class automatically. It returns nullptr in case
// of error: the caller should check for a null pointer.
// The length parameter is the maximum size in bytes of the string.
// The caller is responsible to free the memory (e.g., delete[] (...)).
inline char *allocate_padded_buffer(size_t length) noexcept { __builtin_trap() /* STUB: not implemented */; } // allocate_padded_buffer()

} // namespace internal


inline padded_string::padded_string() noexcept = default;
inline padded_string::padded_string(size_t length) noexcept
    : viable_size(length), data_ptr(internal::allocate_padded_buffer(length)) { __builtin_trap() /* STUB: not implemented */; }
inline padded_string::padded_string(const char *data, size_t length) noexcept
    : viable_size(length), data_ptr(internal::allocate_padded_buffer(length)) { __builtin_trap() /* STUB: not implemented */; }
#ifdef __cpp_char8_t
inline padded_string::padded_string(const char8_t *data, size_t length) noexcept
    : viable_size(length), data_ptr(internal::allocate_padded_buffer(length)) { __builtin_trap() /* STUB: not implemented */; }
#endif
// note: do not pass std::string arguments by value
inline padded_string::padded_string(const std::string & str_ ) noexcept
    : viable_size(str_.size()), data_ptr(internal::allocate_padded_buffer(str_.size())) { __builtin_trap() /* STUB: not implemented */; }
// note: do pass std::string_view arguments by value
inline padded_string::padded_string(std::string_view sv_) noexcept
    : viable_size(sv_.size()), data_ptr(internal::allocate_padded_buffer(sv_.size())) { __builtin_trap() /* STUB: not implemented */; }
inline padded_string::padded_string(padded_string &&o) noexcept
    : viable_size(o.viable_size), data_ptr(o.data_ptr) { __builtin_trap() /* STUB: not implemented */; }

inline padded_string &padded_string::operator=(padded_string &&o) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void padded_string::swap(padded_string &o) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline padded_string::~padded_string() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline size_t padded_string::size() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline size_t padded_string::length() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline const char *padded_string::data() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline char *padded_string::data() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool padded_string::append(const char *data, size_t length) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline padded_string::operator std::string_view() const simdjson_lifetime_bound { __builtin_trap() /* STUB: not implemented */; }

inline padded_string::operator padded_string_view() const noexcept simdjson_lifetime_bound { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<padded_string> padded_string::load(std::string_view filename) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if defined(_WIN32) && SIMDJSON_CPLUSPLUS17
inline simdjson_result<padded_string> padded_string::load(std::wstring_view filename) noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif

// padded_string_builder implementations

inline padded_string_builder::padded_string_builder() noexcept = default;

inline padded_string_builder::padded_string_builder(size_t new_capacity) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline padded_string_builder::padded_string_builder(padded_string_builder &&o) noexcept
    : size(o.size), capacity(o.capacity), data(o.data) { __builtin_trap() /* STUB: not implemented */; }

inline padded_string_builder &padded_string_builder::operator=(padded_string_builder &&o) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline padded_string_builder::~padded_string_builder() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool padded_string_builder::append(const char *newdata, size_t length) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool padded_string_builder::append(std::string_view sv) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline size_t padded_string_builder::length() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline padded_string padded_string_builder::build() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline padded_string padded_string_builder::convert() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool padded_string_builder::reserve(size_t additional) noexcept { __builtin_trap() /* STUB: not implemented */; }


#if SIMDJSON_HAS_PADDED_MEMORY_MAP

#if SIMDJSON_HAS_UNISTD_H
simdjson_inline padded_memory_map::padded_memory_map(const char *filename) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline padded_memory_map::~padded_memory_map() noexcept { __builtin_trap() /* STUB: not implemented */; }
#elif defined(_WIN32)
// Windows zero-copy implementation using placeholder virtual memory.
//
// We use the modern Windows memory APIs (VirtualAlloc2, CreateFileMapping2,
// MapViewOfFile3 — available since Windows 10 1803) to map the file into a
// contiguous virtual address range that includes at least SIMDJSON_PADDING
// zero bytes after the file content, with no data copies.
//
// Strategy:
//   1. If rounding the file size up to the allocation granularity already
//      exceeds file_size + SIMDJSON_PADDING, the OS page zero-fill provides
//      the padding and we use a simple MapViewOfFile3 call.
//   2. Otherwise we reserve a contiguous placeholder region via VirtualAlloc2,
//      split it at the granularity-aligned file boundary, map the file into
//      the first part, and commit zero pages for the second part (padding).
simdjson_inline padded_memory_map::padded_memory_map(const char *filename) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline padded_memory_map::~padded_memory_map() noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // POSIX or _WIN32

simdjson_inline simdjson::padded_string_view padded_memory_map::view() const noexcept simdjson_lifetime_bound { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool padded_memory_map::is_valid() const noexcept { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_HAS_PADDED_MEMORY_MAP

} // namespace simdjson

inline simdjson::padded_string operator ""_padded(const char *str, size_t len) { __builtin_trap() /* STUB: not implemented */; }
#ifdef __cpp_char8_t
inline simdjson::padded_string operator ""_padded(const char8_t *str, size_t len) { __builtin_trap() /* STUB: not implemented */; }
#endif

#endif // SIMDJSON_PADDED_STRING_INL_H
