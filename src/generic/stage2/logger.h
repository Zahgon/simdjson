#ifndef SIMDJSON_SRC_GENERIC_STAGE2_LOGGER_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE2_LOGGER_H
#include <generic/stage2/base.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <cstring>


// This is for an internal-only stage 2 specific logger.
// Set LOG_ENABLED = true to log what stage 2 is doing!
namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace logger {

  static constexpr const char * DASHES = "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

#if SIMDJSON_VERBOSE_LOGGING
  static constexpr const bool LOG_ENABLED = true;
#else
  static constexpr const bool LOG_ENABLED = false;
#endif
  static constexpr const int LOG_EVENT_LEN = 20;
  static constexpr const int LOG_BUFFER_LEN = 30;
  static constexpr const int LOG_SMALL_BUFFER_LEN = 10;
  static constexpr const int LOG_INDEX_LEN = 5;

  static int log_depth; // Not threadsafe. Log only.

  // Helper to turn unprintable or newline characters into spaces
  static simdjson_inline char printable_char(char c) { __builtin_trap() /* STUB: not implemented */; }

  // Print the header and set up log_start
  static simdjson_inline void log_start() { __builtin_trap() /* STUB: not implemented */; }

  simdjson_unused static simdjson_inline void log_string(const char *message) { __builtin_trap() /* STUB: not implemented */; }

  // Logs a single line from the stage 2 DOM parser
  template<typename S>
  static simdjson_inline void log_line(S &structurals, const char *title_prefix, const char *title, const char *detail) { __builtin_trap() /* STUB: not implemented */; }

} // namespace logger
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SRC_GENERIC_STAGE2_LOGGER_H