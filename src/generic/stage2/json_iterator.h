#ifndef SIMDJSON_SRC_GENERIC_STAGE2_JSON_ITERATOR_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE2_JSON_ITERATOR_H
#include <generic/stage2/base.h>
#include <generic/stage2/logger.h>
#include <simdjson/generic/dom_parser_implementation.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace stage2 {

class json_iterator {
public:
  const uint8_t* const buf;
  uint32_t *next_structural;
  dom_parser_implementation &dom_parser;
  uint32_t depth{0};

  /**
   * Walk the JSON document.
   *
   * The visitor receives callbacks when values are encountered. All callbacks pass the iterator as
   * the first parameter; some callbacks have other parameters as well:
   *
   * - visit_document_start() - at the beginning.
   * - visit_document_end() - at the end (if things were successful).
   *
   * - visit_array_start() - at the start `[` of a non-empty array.
   * - visit_array_end() - at the end `]` of a non-empty array.
   * - visit_empty_array() - when an empty array is encountered.
   *
   * - visit_object_end() - at the start `]` of a non-empty object.
   * - visit_object_start() - at the end `]` of a non-empty object.
   * - visit_empty_object() - when an empty object is encountered.
   * - visit_key(const uint8_t *key) - when a key in an object field is encountered. key is
   *                                   guaranteed to point at the first quote of the string (`"key"`).
   * - visit_primitive(const uint8_t *value) - when a value is a string, number, boolean or null.
   * - visit_root_primitive(iter, uint8_t *value) - when the top-level value is a string, number, boolean or null.
   *
   * - increment_count(iter) - each time a value is found in an array or object.
   */
  template<bool STREAMING, typename V>
  simdjson_warn_unused simdjson_inline error_code walk_document(V &visitor) noexcept;

  /**
   * Create an iterator capable of walking a JSON document.
   *
   * The document must have already passed through stage 1.
   */
  simdjson_inline json_iterator(dom_parser_implementation &_dom_parser, size_t start_structural_index);

  /**
   * Look at the next token.
   *
   * Tokens can be strings, numbers, booleans, null, or operators (`[{]},:`)).
   *
   * They may include invalid JSON as well (such as `1.2.3` or `ture`).
   */
  simdjson_inline const uint8_t *peek() const noexcept;
  /**
   * Advance to the next token.
   *
   * Tokens can be strings, numbers, booleans, null, or operators (`[{]},:`)).
   *
   * They may include invalid JSON as well (such as `1.2.3` or `ture`).
   */
  simdjson_inline const uint8_t *advance() noexcept;
  /**
   * Get the remaining length of the document, from the start of the current token.
   */
  simdjson_inline size_t remaining_len() const noexcept;
  /**
   * Check if we are at the end of the document.
   *
   * If this is true, there are no more tokens.
   */
  simdjson_inline bool at_eof() const noexcept;
  /**
   * Check if we are at the beginning of the document.
   */
  simdjson_inline bool at_beginning() const noexcept;
  simdjson_inline uint8_t last_structural() const noexcept;

  /**
   * Log that a value has been found.
   *
   * Set LOG_ENABLED=true in logger.h to see logging.
   */
  simdjson_inline void log_value(const char *type) const noexcept;
  /**
   * Log the start of a multipart value.
   *
   * Set LOG_ENABLED=true in logger.h to see logging.
   */
  simdjson_inline void log_start_value(const char *type) const noexcept;
  /**
   * Log the end of a multipart value.
   *
   * Set LOG_ENABLED=true in logger.h to see logging.
   */
  simdjson_inline void log_end_value(const char *type) const noexcept;
  /**
   * Log an error.
   *
   * Set LOG_ENABLED=true in logger.h to see logging.
   */
  simdjson_inline void log_error(const char *error) const noexcept;

  template<typename V>
  simdjson_warn_unused simdjson_inline error_code visit_root_primitive(V &visitor, const uint8_t *value) noexcept;
  template<typename V>
  simdjson_warn_unused simdjson_inline error_code visit_primitive(V &visitor, const uint8_t *value) noexcept;
};

template<bool STREAMING, typename V>
simdjson_warn_unused simdjson_inline error_code json_iterator::walk_document(V &visitor) noexcept { __builtin_trap() /* STUB: not implemented */; } // walk_document()

simdjson_inline json_iterator::json_iterator(dom_parser_implementation &_dom_parser, size_t start_structural_index)
  : buf{_dom_parser.buf},
    next_structural{&_dom_parser.structural_indexes[start_structural_index]},
    dom_parser{_dom_parser} {
}

simdjson_inline const uint8_t *json_iterator::peek() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline const uint8_t *json_iterator::advance() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline size_t json_iterator::remaining_len() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool json_iterator::at_eof() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool json_iterator::at_beginning() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline uint8_t json_iterator::last_structural() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::log_value(const char *type) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::log_start_value(const char *type) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::log_end_value(const char *type) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_iterator::log_error(const char *error) const noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename V>
simdjson_warn_unused simdjson_inline error_code json_iterator::visit_root_primitive(V &visitor, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }
template<typename V>
simdjson_warn_unused simdjson_inline error_code json_iterator::visit_primitive(V &visitor, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace stage2
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SRC_GENERIC_STAGE2_JSON_ITERATOR_H
