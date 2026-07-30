#ifndef SIMDJSON_INTERNAL_JSONFORMATUTILS_H
#define SIMDJSON_INTERNAL_JSONFORMATUTILS_H

#include "simdjson/base.h"
#include <iomanip>
#include <ostream>
#include <sstream>

namespace simdjson {
namespace internal {

inline std::ostream& operator<<(std::ostream& out, const escape_json_string &str);

class escape_json_string {
public:
  escape_json_string(std::string_view _str) noexcept : str{_str} { __builtin_trap() /* STUB: not implemented */; }
  operator std::string() const noexcept { __builtin_trap() /* STUB: not implemented */; }
private:
  std::string_view str;
  friend std::ostream& operator<<(std::ostream& out, const escape_json_string &unescaped);
};

inline std::ostream& operator<<(std::ostream& out, const escape_json_string &unescaped) { __builtin_trap() /* STUB: not implemented */; }

} // namespace internal
} // namespace simdjson

#endif // SIMDJSON_INTERNAL_JSONFORMATUTILS_H
