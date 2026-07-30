#ifndef SIMDJSON_PADDED_STRING_VIEW_INL_H
#define SIMDJSON_PADDED_STRING_VIEW_INL_H

#include "simdjson/padded_string_view.h"
#include "simdjson/error-inl.h"

#include <cstring> /* memcmp */

// for page size computation.
#if SIMDJSON_HAS_UNISTD_H
  #include <unistd.h>
  #if defined(__APPLE__)
    #include <sys/sysctl.h>
  #endif
#endif


namespace simdjson {

inline padded_string_view::padded_string_view(const char* s, size_t len, size_t capacity) noexcept
  : std::string_view(s, len), _capacity(capacity)
{ __builtin_trap() /* STUB: not implemented */; }

inline padded_string_view::padded_string_view(const uint8_t* s, size_t len, size_t capacity) noexcept
  : padded_string_view(reinterpret_cast<const char*>(s), len, capacity)
{ __builtin_trap() /* STUB: not implemented */; }
#ifdef __cpp_char8_t
inline padded_string_view::padded_string_view(const char8_t* s, size_t len, size_t capacity) noexcept
  : padded_string_view(reinterpret_cast<const char*>(s), len, capacity)
{ __builtin_trap() /* STUB: not implemented */; }
#endif
inline padded_string_view::padded_string_view(const std::string &s) noexcept
  : std::string_view(s), _capacity(s.capacity())
{ __builtin_trap() /* STUB: not implemented */; }

inline padded_string_view::padded_string_view(std::string_view s, size_t capacity) noexcept
  : std::string_view(s), _capacity(capacity)
{ __builtin_trap() /* STUB: not implemented */; }

inline bool padded_string_view::has_sufficient_padding() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline size_t padded_string_view::capacity() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline size_t padded_string_view::padding() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool padded_string_view::remove_utf8_bom() noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS
inline std::ostream& operator<<(std::ostream& out, simdjson_result<padded_string_view> &s) noexcept(false) { __builtin_trap() /* STUB: not implemented */; }
#endif

inline padded_string_view pad(std::string& s) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline padded_string_view pad_with_reserve(std::string& s) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline uint32_t get_page_size() noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_CPLUSPLUS17

inline padded_input::padded_input(std::string_view sv)
    : storage(simdjson::padded_string_view{}) { __builtin_trap() /* STUB: not implemented */; }

inline padded_input::padded_input(const char *data, size_t length)
    : storage(simdjson::padded_string_view{}) { __builtin_trap() /* STUB: not implemented */; }

inline padded_input::padded_input(const std::string &s)
    : storage(simdjson::padded_string_view{}) { __builtin_trap() /* STUB: not implemented */; }

inline bool padded_input::is_view() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline padded_input::operator simdjson::padded_string_view() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool padded_input::needs_allocation(const char* buf, size_t len, size_t padding) noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_CPLUSPLUS17

} // namespace simdjson


#endif // SIMDJSON_PADDED_STRING_VIEW_INL_H
