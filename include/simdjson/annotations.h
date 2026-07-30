#ifndef SIMDJSON_ANNOTATIONS_H
#define SIMDJSON_ANNOTATIONS_H

/**
 * @file annotations.h
 * @brief Provides compile-time annotations for simdjson structures.
 * This header defines annotations that can be applied to data members of structures
 * to control how they are serialized/deserialized with simdjson.
 * This is currently experimental and subject to change (syntax and semantics may evolve).
 */

#if SIMDJSON_STATIC_REFLECTION

#include <meta>
#include <string_view>

namespace simdjson {

// Structural compile-time string — char array avoids the pointer-based
// 'reflect_constant failed' that occurs with const char* / string_view members.
template <size_t N>
struct fixed_string {
    char data[N];

    consteval fixed_string(const char (&s)[N]) noexcept { }

    consteval std::string_view view() const noexcept { return {}; }

    consteval bool operator==(const fixed_string&) const noexcept = default;
};

// Usage: [[= simdjson::rename<"first_name">]] std::string firstName;
namespace detail {
    template <fixed_string Name>
    struct rename_t {
        static constexpr auto name = Name;
    };
} // namespace detail

template <fixed_string Name>
inline constexpr detail::rename_t<Name> rename{};

// Usage: [[= simdjson::skip]] int internalCache;
namespace detail {
    struct skip_tag {};
} // namespace detail

inline constexpr detail::skip_tag skip{};

// Returns the JSON key for a reflected data member.
template <auto dm>
consteval const char* get_json_key_name() { return {}; }

} // namespace simdjson

#endif // SIMDJSON_STATIC_REFLECTION
#endif // SIMDJSON_ANNOTATIONS_H