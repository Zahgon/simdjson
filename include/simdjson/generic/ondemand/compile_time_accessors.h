/**
 * Compile-time JSON Path and JSON Pointer accessors using C++26 reflection (P2996)
 *
 * This file validates JSON paths/pointers against struct definitions at compile time
 * and generates optimized accessor code with zero runtime overhead.
 *
 * ## How It Works
 *
 * **Compile Time**: Path is parsed, validated against struct, types are checked
 * **Runtime**: Direct navigation with no parsing or validation overhead
 *
 * Example:
 * ```cpp
 * struct User { std::string name; std::vector<std::string> emails; };
 *
 * std::string email;
 * path_accessor<User, ".emails[0]">::extract_field(doc, email);
 *
 * // Compile time validates:
 * // 1. User has "emails" field
 * // 2. "emails" is array-like
 * // 3. Element type is std::string
 * // 4. static_assert(^^std::string == ^^std::string)
 *
 * // Runtime just navigates:
 * // doc.get_object().find_field("emails").get_array().at(0).get(email)
 * ```
 *
 * ## Key Reflection APIs
 *
 * - `^^Type`: Reflect operator, converts type to std::meta::info
 * - `std::meta::nonstatic_data_members_of(type)`: Get all fields of a struct
 * - `std::meta::identifier_of(member)`: Get field name as string_view
 * - `std::meta::type_of(member)`: Get reflected type of a field
 * - `std::meta::is_array_type(type)`: Check if C-style array
 * - `std::meta::remove_extent(array)`: Extract element type from array
 * - `std::meta::members_of(type)`: Get all members including typedefs
 * - `std::meta::is_type(member)`: Check if member is a type (vs field)
 *
 * All operations execute at compile time in consteval contexts.
 */
#ifndef SIMDJSON_GENERIC_ONDEMAND_COMPILE_TIME_ACCESSORS_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_COMPILE_TIME_ACCESSORS_H

#endif // SIMDJSON_CONDITIONAL_INCLUDE

// Arguably, we should just check SIMDJSON_STATIC_REFLECTION since it
// is unlikely that we will have reflection support without concepts support.
#if SIMDJSON_SUPPORTS_CONCEPTS && SIMDJSON_STATIC_REFLECTION

#include <string_view>
#include <cstddef>
#include <array>

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {
/***
 * JSONPath implementation for compile-time access
 * RFC 9535 JSONPath: Query Expressions for JSON, https://www.rfc-editor.org/rfc/rfc9535
 */
namespace json_path {

// Note: value type must be fully defined before this header is included
// This is ensured by including this in amalgamated.h after value-inl.h

using ::simdjson::SIMDJSON_IMPLEMENTATION::ondemand::value;

// Path step types
enum class step_type {
  field,        // .field_name or ["field_name"]
  array_index   // [index]
};

// Represents a single step in a JSON path
template<std::size_t N>
struct path_step {
  step_type type;
  char key[N];  // Field name (empty for array indices)
  std::size_t index;  // Array index (0 for field access)

  constexpr path_step(step_type t, const char (&k)[N], std::size_t idx = 0)
    : type(t), index(idx) { }

  constexpr std::string_view key_view() const { return {}; }
};

// Helper to create field step
template<std::size_t N>
consteval auto make_field_step(const char (&name)[N]) { return {}; }

// Helper to create array index step
consteval auto make_index_step(std::size_t idx) { return {}; }

// Parse state for compile-time JSON path parsing
struct parse_result {
  bool success;
  std::size_t pos;
  std::string_view error_msg;
};

// Compile-time JSON path parser
// Supports subset: .field, ["field"], [index], nested combinations
template<constevalutil::fixed_string Path>
struct json_path_parser {
  static constexpr std::string_view path_str = Path.view();

  // Skip leading $ if present
  static consteval std::size_t skip_root() { return {}; }

  // Count the number of steps in the path at compile time
  static consteval std::size_t count_steps() { return {}; }

  // Parse a field name at compile time
  static consteval std::size_t parse_field_name(std::size_t start, char* out, std::size_t max_len) { return {}; }

  // Parse an array index at compile time
  static consteval std::pair<std::size_t, std::size_t> parse_array_index(std::size_t start) { return {}; }
};

// Compile-time path accessor generator
template<typename T, constevalutil::fixed_string Path>
struct path_accessor {
  using value = ::simdjson::SIMDJSON_IMPLEMENTATION::ondemand::value;

  static constexpr auto parser = json_path_parser<Path>();
  static constexpr std::size_t num_steps = parser.count_steps();
  static constexpr std::string_view path_view = Path.view();

  // Compile-time accessor generation
  // If T is a struct, validates the path at compile time
  // If T is void, skips validation
  template<typename DocOrValue>
  static inline simdjson_result<value> access(DocOrValue& doc_or_val) noexcept { __builtin_trap() /* STUB: not implemented */; }

  // Extract value at path directly into target with compile-time type validation
  // Example: std::string name; path_accessor<User, ".name">::extract_field(doc, name);
  template<typename DocOrValue, typename FieldType>
  static inline error_code extract_field(DocOrValue& doc_or_val, FieldType& target) noexcept { __builtin_trap() /* STUB: not implemented */; }

private:
  // Get the final type by walking the path through the struct type
  template<typename U = T>
  static consteval std::enable_if_t<std::is_class_v<U>, std::meta::info> get_final_type() { return {}; }

private:
  // Walk path and extract directly into final field using compile-time reflection
  template<std::meta::info CurrentType, std::size_t PathPos, typename TargetType>
  static inline error_code extract_with_reflection(simdjson_result<value> current, TargetType& target_ref) noexcept { __builtin_trap() /* STUB: not implemented */; }

  // Find member by name in reflected type
  static consteval std::meta::info find_member_by_name(std::meta::info type_refl, std::string_view name) { return {}; }

  // Generate compile-time accessor code by walking the path
  template<std::size_t PathPos>
  static inline simdjson_result<value> access_impl(simdjson_result<value> current) noexcept { __builtin_trap() /* STUB: not implemented */; }

  // Parse next field name
  static consteval auto parse_next_field(std::size_t start) { return {}; }

  // Parse bracket notation: returns (is_field, field_name, next_pos, index)
  static consteval auto parse_bracket(std::size_t start) { return {}; }

public:
  // Check if reflected type is array-like (C-style array or indexable container)
  // Uses reflection to test: 1) std::meta::is_array_type() for C arrays
  //                          2) std::meta::substitute() to test concepts::indexable_container concept
  static consteval bool is_array_like_reflected(std::meta::info type_reflection) { return {}; }

  // Extract element type from reflected array or container
  // For C arrays: uses std::meta::remove_extent()
  // For containers: finds value_type member using std::meta::members_of()
  static consteval std::meta::info get_element_type_reflected(std::meta::info type_reflection) { return {}; }

private:
  // Check if type has member with given name
  template<typename Type>
  static consteval bool has_member(std::string_view member_name) { return {}; }

  // Get type of member by name
  template<typename Type>
  static consteval auto get_member_type(std::string_view member_name) { return {}; }

  // Check if non-reflected type is array-like
  template<typename Type>
  static consteval bool is_container_type() { return {}; }

  // Extract element type from non-reflected container
  template<typename Type>
  using extract_element_type = std::conditional_t<
    requires { typename std::remove_cvref_t<Type>::value_type; },
    typename std::remove_cvref_t<Type>::value_type,
    std::conditional_t<
      std::is_array_v<std::remove_cvref_t<Type>>,
      std::remove_extent_t<std::remove_cvref_t<Type>>,
      void
    >
  >;

  // Validate path matches struct definition
  static consteval bool validate_path() { return {}; }
};

// Compile-time path accessor with validation
template<typename T, constevalutil::fixed_string Path, typename DocOrValue>
inline simdjson_result<::simdjson::SIMDJSON_IMPLEMENTATION::ondemand::value> at_path_compiled(DocOrValue& doc_or_val) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Overload without type parameter (no validation)
template<constevalutil::fixed_string Path, typename DocOrValue>
inline simdjson_result<::simdjson::SIMDJSON_IMPLEMENTATION::ondemand::value> at_path_compiled(DocOrValue& doc_or_val) noexcept { __builtin_trap() /* STUB: not implemented */; }

// ============================================================================
// JSON Pointer Compile-Time Support (RFC 6901)
// ============================================================================

// JSON Pointer parser: /field/0/nested (slash-separated)
template<constevalutil::fixed_string Pointer>
struct json_pointer_parser {
  static constexpr std::string_view pointer_str = Pointer.view();

  // Unescape token: ~0 -> ~, ~1 -> /
  static consteval void unescape_token(std::string_view src, char* dest, std::size_t& out_len) { }

  // Check if token is numeric
  static consteval bool is_numeric(std::string_view token) { return {}; }

  // Parse numeric token to index
  static consteval std::size_t parse_index(std::string_view token) { return {}; }

  // Count tokens in pointer
  static consteval std::size_t count_tokens() { return {}; }

  // Get Nth token
  static consteval std::string_view get_token(std::size_t token_index) { return {}; }
};

// JSON Pointer accessor
template<typename T, constevalutil::fixed_string Pointer>
struct pointer_accessor {
  using parser = json_pointer_parser<Pointer>;
  static constexpr std::string_view pointer_view = Pointer.view();
  static constexpr std::size_t token_count = parser::count_tokens();

  // Validate pointer against struct definition
  static consteval bool validate_pointer() { return {}; }

  // Recursive accessor
  template<std::size_t TokenIndex>
  static inline simdjson_result<value> access_impl(simdjson_result<value> current) noexcept { __builtin_trap() /* STUB: not implemented */; }

  // Access JSON value at pointer
  template<typename DocOrValue>
  static inline simdjson_result<value> access(DocOrValue& doc_or_val) noexcept { __builtin_trap() /* STUB: not implemented */; }

  // Extract value at pointer directly into target with type validation
  template<typename DocOrValue, typename FieldType>
  static inline error_code extract_field(DocOrValue& doc_or_val, FieldType& target) noexcept { __builtin_trap() /* STUB: not implemented */; }

private:
  // Get final type by walking pointer through struct
  template<typename U = T>
  static consteval std::enable_if_t<std::is_class_v<U>, std::meta::info> get_final_type() { return {}; }
};

// Compile-time JSON Pointer accessor with validation
template<typename T, constevalutil::fixed_string Pointer, typename DocOrValue>
inline simdjson_result<::simdjson::SIMDJSON_IMPLEMENTATION::ondemand::value> at_pointer_compiled(DocOrValue& doc_or_val) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Overload without type parameter (no validation)
template<constevalutil::fixed_string Pointer, typename DocOrValue>
inline simdjson_result<::simdjson::SIMDJSON_IMPLEMENTATION::ondemand::value> at_pointer_compiled(DocOrValue& doc_or_val) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace json_path
} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SUPPORTS_CONCEPTS && SIMDJSON_STATIC_REFLECTION
#endif // SIMDJSON_GENERIC_ONDEMAND_COMPILE_TIME_ACCESSORS_H

