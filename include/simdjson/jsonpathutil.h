#ifndef SIMDJSON_JSONPATHUTIL_H
#define SIMDJSON_JSONPATHUTIL_H

#include "simdjson/error.h"
#include <string>
#include "simdjson/common_defs.h"

#include <limits>
#include <utility>

namespace simdjson {
namespace internal {
/**
 * Parses the next JSON Pointer array index token.
 *
 * The caller passes a pointer fragment with no leading '/', such as "123/foo".
 * On success, array_index receives the parsed index and token_length receives
 * the number of bytes consumed before the next '/' or the end of the fragment.
 */
simdjson_inline error_code parse_json_pointer_array_index(std::string_view json_pointer,
                                                          size_t &array_index,
                                                          size_t &token_length) noexcept { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal

/**
 * Converts JSONPath to JSON Pointer.
 * @param json_path The JSONPath string to be converted.
 * @return A string containing the equivalent JSON Pointer.
 */
inline std::string json_path_to_pointer_conversion(std::string_view json_path) { __builtin_trap() /* STUB: not implemented */; }

inline std::pair<std::string_view, std::string_view> get_next_key_and_json_path(std::string_view& json_path) { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson
#endif // SIMDJSON_JSONPATHUTIL_H
