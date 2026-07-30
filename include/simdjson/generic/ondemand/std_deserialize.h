#if SIMDJSON_SUPPORTS_CONCEPTS

#ifndef SIMDJSON_ONDEMAND_DESERIALIZE_H
#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_ONDEMAND_DESERIALIZE_H
#include "simdjson/generic/ondemand/object.h"
#include "simdjson/generic/ondemand/array.h"
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/annotations.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <concepts>
#include <limits>
#if SIMDJSON_STATIC_REFLECTION
#include <meta>
#include <vector>
// #include <static_reflection> // for std::define_static_string - header not available yet
#endif

namespace simdjson {

//////////////////////////////
// Number deserialization
//////////////////////////////

template <std::unsigned_integral T>
error_code tag_invoke(deserialize_tag, auto &val, T &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <std::floating_point T>
error_code tag_invoke(deserialize_tag, auto &val, T &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <std::signed_integral T>
error_code tag_invoke(deserialize_tag, auto &val, T &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

//////////////////////////////
// String deserialization
//////////////////////////////

// just a character!
error_code tag_invoke(deserialize_tag, auto &val, char &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

// any string-like type (can be constructed from std::string_view)
template <concepts::constructible_from_string_view T, typename ValT>
error_code tag_invoke(deserialize_tag, ValT &val, T &out) noexcept(std::is_nothrow_constructible_v<T, std::string_view>) { __builtin_trap() /* STUB: not implemented */; }


/**
 * STL containers have several constructors including one that takes a single
 * size argument. Thus, some compilers (Visual Studio) will not be able to
 * disambiguate between the size and container constructor. Users should
 * explicitly specify the type of the container as needed: e.g.,
 * doc.get<std::vector<int>>().
 */
template <concepts::appendable_containers T, typename ValT>
error_code tag_invoke(deserialize_tag, ValT &val, T &out) noexcept(false) { __builtin_trap() /* STUB: not implemented */; }


/**
 * We want to support std::map and std::unordered_map but only for
 * string-keyed types.
 */
 template <concepts::string_view_keyed_map T, typename ValT>
error_code tag_invoke(deserialize_tag, ValT &val, T &out) noexcept(false) { __builtin_trap() /* STUB: not implemented */; }

template <concepts::string_view_keyed_map T>
error_code tag_invoke(deserialize_tag, SIMDJSON_IMPLEMENTATION::ondemand::object &obj, T &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <concepts::string_view_keyed_map T>
error_code tag_invoke(deserialize_tag, SIMDJSON_IMPLEMENTATION::ondemand::value &val, T &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <concepts::string_view_keyed_map T>
error_code tag_invoke(deserialize_tag, SIMDJSON_IMPLEMENTATION::ondemand::document &doc, T &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <concepts::string_view_keyed_map T>
error_code tag_invoke(deserialize_tag, SIMDJSON_IMPLEMENTATION::ondemand::document_reference &doc, T &out) noexcept { __builtin_trap() /* STUB: not implemented */; }


/**
 * This CPO (Customization Point Object) will help deserialize into
 * smart pointers.
 *
 * If constructing T is nothrow, this conversion should be nothrow as well since
 * we return MEMALLOC if we're not able to allocate memory instead of throwing
 * the error message.
 *
 * @tparam T The type inside the smart pointer
 * @tparam ValT document/value type
 * @param val document/value
 * @param out a reference to the smart pointer
 * @return status of the conversion
 */
template <concepts::smart_pointer T, typename ValT>
error_code tag_invoke(deserialize_tag, ValT &val, T &out) noexcept(nothrow_deserializable<typename std::remove_cvref_t<T>::element_type, ValT>) { __builtin_trap() /* STUB: not implemented */; }

/**
 * This CPO (Customization Point Object) will help deserialize into optional types.
 */
template <concepts::optional_type T>
error_code tag_invoke(deserialize_tag, auto &val, T &out) noexcept(nothrow_deserializable<typename std::remove_cvref_t<T>::value_type, decltype(val)>) { __builtin_trap() /* STUB: not implemented */; }


#if SIMDJSON_STATIC_REFLECTION


template <typename T>
constexpr bool user_defined_type = (std::is_class_v<T>
&& !std::is_same_v<T, std::string> && !std::is_same_v<T, std::string_view> && !concepts::optional_type<T> &&
!concepts::appendable_containers<T>);


// key_selector_reflection_detail is defined unconditionally (it only requires
// static reflection). It provides both the compile-time machinery for building a
// key_selector from a struct's members and the ordered per-member fallback used
// by the opt-out build and as an automatic fallback (see deserialize_struct_ordered
// and keys_fit_selector below).
namespace key_selector_reflection_detail {

// A member participates if it is public, non-const, and not annotated to skip.
consteval bool is_eligible_member(std::meta::info mem) { return {}; }

// JSON key name for `mem`, as a constevalutil::fixed_string usable as an NTTP.
template <auto mem>
consteval auto member_key_fixed_string() { return {}; }

// key_selector template arguments (one fixed_string per eligible member), in
// declaration order.
template <typename T>
consteval std::vector<std::meta::info> selector_key_args() { return {}; }

// key_selector whose keys are exactly T's eligible members (index i <-> i-th).
template <typename T>
using selector_for = typename [: std::meta::substitute(
    ^^SIMDJSON_IMPLEMENTATION::ondemand::key_selector, selector_key_args<T>()) :];

// Number of members that participate in deserialization. A class can have zero
// eligible members (e.g. std::chrono::time_point, whose only data member is
// private): an empty key_selector cannot be built, so the tag_invoke below
// special-cases this count.
template <typename T>
consteval std::size_t eligible_member_count() { return {}; }

// True when none of T's eligible members is an optional type, i.e. every member
// is required. In that case presence can be checked with a single match count
// instead of a per-member "seen" array.
template <typename T>
consteval bool all_eligible_members_required() { return {}; }

// True when T's eligible member keys satisfy every key_selector requirement, so
// a key_selector can be built for T without a compile-time error. This mirrors
// the key_selector limits (see key_selector.h): at most 255 keys, each key
// non-empty and at most 63 characters, no backslash / double-quote / null byte,
// and all keys distinct. When this returns false the deserializer falls back to
// the ordered per-member path instead of failing to compile.
template <typename T>
consteval bool keys_fit_selector() { return {}; }

// Ordered, per-member deserialization: one obj[key] lookup per eligible member.
// This is the opt-out path (-DSIMDJSON_DISABLE_KEY_SELECTOR_REFLECTION=1) and the
// automatic fallback for structs whose keys do not fit the key_selector limits
// (see keys_fit_selector).
template <typename T>
simdjson_warn_unused error_code deserialize_struct_ordered(
    SIMDJSON_IMPLEMENTATION::ondemand::object &obj, T &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace key_selector_reflection_detail

// Deserialize a reflected struct. By default this builds a compile-time
// key_selector from the struct's members and walks each object once with
// object::for_each (perfect-hash key matching), instead of one obj[key] lookup
// per member. There are two ways the ordered per-member path is used instead:
//   - globally, by defining -DSIMDJSON_DISABLE_KEY_SELECTOR_REFLECTION=1;
//   - automatically and per-type, when the struct's member keys do not fit the
//     key_selector limits (see keys_fit_selector), so that long member names and
//     the like keep compiling rather than tripping a static_assert.
template <typename T, typename ValT>
  requires(user_defined_type<T> && std::is_class_v<T>)
error_code tag_invoke(deserialize_tag, ValT &val, T &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Support for enum deserialization - deserialize from string representation using expand approach from P2996R12
template <typename T, typename ValT>
  requires(std::is_enum_v<T>)
error_code tag_invoke(deserialize_tag, ValT &val, T &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <typename simdjson_value, typename T>
  requires(user_defined_type<std::remove_cvref_t<T>>)
error_code tag_invoke(deserialize_tag, simdjson_value &val, std::unique_ptr<T> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <typename simdjson_value, typename T>
  requires(user_defined_type<std::remove_cvref_t<T>>)
error_code tag_invoke(deserialize_tag, simdjson_value &val, std::shared_ptr<T> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_STATIC_REFLECTION

////////////////////////////////////////
// Unique pointers
////////////////////////////////////////
error_code tag_invoke(deserialize_tag, auto &val, std::unique_ptr<bool> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

error_code tag_invoke(deserialize_tag, auto &val, std::unique_ptr<int64_t> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

error_code tag_invoke(deserialize_tag, auto &val, std::unique_ptr<uint64_t> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

error_code tag_invoke(deserialize_tag, auto &val, std::unique_ptr<double> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

error_code tag_invoke(deserialize_tag, auto &val, std::unique_ptr<std::string_view> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }


////////////////////////////////////////
// Shared pointers
////////////////////////////////////////
error_code tag_invoke(deserialize_tag, auto &val, std::shared_ptr<bool> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

error_code tag_invoke(deserialize_tag, auto &val, std::shared_ptr<int64_t> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

error_code tag_invoke(deserialize_tag, auto &val, std::shared_ptr<uint64_t> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

error_code tag_invoke(deserialize_tag, auto &val, std::shared_ptr<double> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

error_code tag_invoke(deserialize_tag, auto &val, std::shared_ptr<std::string_view> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }


////////////////////////////////////////
// Explicit optional specializations
////////////////////////////////////////

////////////////////////////////////////
// Explicit smart pointer specializations for string and int types
////////////////////////////////////////
error_code tag_invoke(deserialize_tag, auto &val, std::unique_ptr<std::string> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

error_code tag_invoke(deserialize_tag, auto &val, std::shared_ptr<std::string> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

error_code tag_invoke(deserialize_tag, auto &val, std::unique_ptr<int> &out) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson

#endif // SIMDJSON_ONDEMAND_DESERIALIZE_H
#endif // SIMDJSON_SUPPORTS_CONCEPTS
