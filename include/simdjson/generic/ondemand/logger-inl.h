#ifndef SIMDJSON_GENERIC_ONDEMAND_LOGGER_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_LOGGER_INL_H
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/logger.h"
#include "simdjson/generic/ondemand/json_iterator.h"
#include "simdjson/generic/ondemand/value_iterator.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <memory>
#include <cstring>

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {
namespace logger {

static constexpr const char * DASHES = "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
static constexpr const int LOG_EVENT_LEN = 20;
static constexpr const int LOG_BUFFER_LEN = 30;
static constexpr const int LOG_SMALL_BUFFER_LEN = 10;
static int log_depth = 0; // Not threadsafe. Log only.

// Helper to turn unprintable or newline characters into spaces
static inline char printable_char(char c) { __builtin_trap() /* STUB: not implemented */; }

template<typename... Args>
static inline std::string string_format(const std::string& format, const Args&... args)
{ __builtin_trap() /* STUB: not implemented */; }

static inline log_level get_log_level_from_env()
{ __builtin_trap() /* STUB: not implemented */; }

static inline log_level log_threshold()
{ __builtin_trap() /* STUB: not implemented */; }

static inline bool should_log(log_level level)
{ __builtin_trap() /* STUB: not implemented */; }

inline void log_event(const json_iterator &iter, const char *type, std::string_view detail, int delta, int depth_delta) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void log_value(const json_iterator &iter, token_position index, depth_t depth, const char *type, std::string_view detail) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline void log_value(const json_iterator &iter, const char *type, std::string_view detail, int delta, int depth_delta) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void log_start_value(const json_iterator &iter, token_position index, depth_t depth, const char *type, std::string_view detail) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline void log_start_value(const json_iterator &iter, const char *type, int delta, int depth_delta) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void log_end_value(const json_iterator &iter, const char *type, int delta, int depth_delta) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void log_error(const json_iterator &iter, const char *error, const char *detail, int delta, int depth_delta) noexcept { __builtin_trap() /* STUB: not implemented */; }
inline void log_error(const json_iterator &iter, token_position index, depth_t depth, const char *error, const char *detail) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void log_event(const value_iterator &iter, const char *type, std::string_view detail, int delta, int depth_delta) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void log_value(const value_iterator &iter, const char *type, std::string_view detail, int delta, int depth_delta) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void log_start_value(const value_iterator &iter, const char *type, int delta, int depth_delta) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void log_end_value(const value_iterator &iter, const char *type, int delta, int depth_delta) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void log_error(const value_iterator &iter, const char *error, const char *detail, int delta, int depth_delta) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void log_headers() noexcept { __builtin_trap() /* STUB: not implemented */; }

template <typename... Args>
inline void log_line(const json_iterator &iter, const char *title_prefix, const char *title, std::string_view detail, int delta, int depth_delta, log_level level, Args&&... args) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <typename... Args>
inline void log_line(const json_iterator &iter, token_position index, depth_t depth, const char *title_prefix, const char *title, std::string_view detail, log_level level, Args&&... args) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace logger
} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_LOGGER_INL_H