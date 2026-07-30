#ifndef SIMDJSON_SRC_GENERIC_STAGE2_TAPE_BUILDER_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE2_TAPE_BUILDER_H
#include <generic/stage2/base.h>
#include <generic/stage2/json_iterator.h>
#include <generic/stage2/stringparsing.h>
#include <generic/stage2/tape_writer.h>
#include <simdjson/dom/document.h>
#include <simdjson/generic/atomparsing.h>
#include <simdjson/generic/dom_parser_implementation.h>
#include <simdjson/generic/numberparsing.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE


namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace stage2 {

template <bool UNPADDED>
struct tape_builder_impl {
  /** Called when a non-empty document starts. */
  simdjson_warn_unused simdjson_inline error_code visit_document_start(json_iterator &iter) noexcept;
  /** Called when a non-empty document ends without error. */
  simdjson_warn_unused simdjson_inline error_code visit_document_end(json_iterator &iter) noexcept;

  /** Called when a non-empty array starts. */
  simdjson_warn_unused simdjson_inline error_code visit_array_start(json_iterator &iter) noexcept;
  /** Called when a non-empty array ends. */
  simdjson_warn_unused simdjson_inline error_code visit_array_end(json_iterator &iter) noexcept;
  /** Called when an empty array is found. */
  simdjson_warn_unused simdjson_inline error_code visit_empty_array(json_iterator &iter) noexcept;

  /** Called when a non-empty object starts. */
  simdjson_warn_unused simdjson_inline error_code visit_object_start(json_iterator &iter) noexcept;
  /**
   * Called when a key in a field is encountered.
   *
   * primitive, visit_object_start, visit_empty_object, visit_array_start, or visit_empty_array
   * will be called after this with the field value.
   */
  simdjson_warn_unused simdjson_inline error_code visit_key(json_iterator &iter, const uint8_t *key) noexcept;
  /** Called when a non-empty object ends. */
  simdjson_warn_unused simdjson_inline error_code visit_object_end(json_iterator &iter) noexcept;
  /** Called when an empty object is found. */
  simdjson_warn_unused simdjson_inline error_code visit_empty_object(json_iterator &iter) noexcept;

  /**
   * Called when a string, number, boolean or null is found.
   */
  simdjson_warn_unused simdjson_inline error_code visit_primitive(json_iterator &iter, const uint8_t *value) noexcept;
  /**
   * Called when a string, number, boolean or null is found at the top level of a document (i.e.
   * when there is no array or object and the entire document is a single string, number, boolean or
   * null.
   *
   * This is separate from primitive() because simdjson's normal primitive parsing routines assume
   * there is at least one more token after the value, which is only true in an array or object.
   */
  simdjson_warn_unused simdjson_inline error_code visit_root_primitive(json_iterator &iter, const uint8_t *value) noexcept;

  simdjson_warn_unused simdjson_inline error_code visit_string(json_iterator &iter, const uint8_t *value, bool key = false) noexcept;
  simdjson_warn_unused simdjson_inline error_code visit_number(json_iterator &iter, const uint8_t *value) noexcept;
  simdjson_warn_unused simdjson_inline error_code visit_true_atom(json_iterator &iter, const uint8_t *value) noexcept;
  simdjson_warn_unused simdjson_inline error_code visit_false_atom(json_iterator &iter, const uint8_t *value) noexcept;
  simdjson_warn_unused simdjson_inline error_code visit_null_atom(json_iterator &iter, const uint8_t *value) noexcept;

  simdjson_warn_unused simdjson_inline error_code visit_root_string(json_iterator &iter, const uint8_t *value) noexcept;
  simdjson_warn_unused simdjson_inline error_code visit_root_number(json_iterator &iter, const uint8_t *value) noexcept;
  simdjson_warn_unused simdjson_inline error_code visit_root_true_atom(json_iterator &iter, const uint8_t *value) noexcept;
  simdjson_warn_unused simdjson_inline error_code visit_root_false_atom(json_iterator &iter, const uint8_t *value) noexcept;
  simdjson_warn_unused simdjson_inline error_code visit_root_null_atom(json_iterator &iter, const uint8_t *value) noexcept;

#if SIMDJSON_ENABLE_NAN_INF
  simdjson_warn_unused simdjson_inline error_code visit_nan_atom(json_iterator &iter, const uint8_t *value, error_code errc) noexcept;
  simdjson_warn_unused simdjson_inline error_code visit_root_nan_atom(json_iterator &iter, const uint8_t *value, error_code errc) noexcept;
  // Attempts to parse 'inf' or 'infinity' (case insensitive). Because neither are canonical atoms,
  // this returns a tape error on failure.
  simdjson_warn_unused simdjson_inline error_code visit_inf_atom(json_iterator &iter, const uint8_t *value) noexcept;
  simdjson_warn_unused simdjson_inline error_code visit_root_inf_atom(json_iterator &iter, const uint8_t *value) noexcept;
#endif

  /** Called each time a new field or element in an array or object is found. */
  simdjson_warn_unused simdjson_inline error_code increment_count(json_iterator &iter) noexcept;

  /** Next location to write to tape */
  tape_writer tape;
public:
  simdjson_inline tape_builder_impl(dom::document &doc) noexcept;
private:
  /** Next write location in the string buf for stage 2 parsing */
  uint8_t *current_string_buf_loc;

  simdjson_inline uint32_t next_tape_index(json_iterator &iter) const noexcept;
  simdjson_inline void start_container(json_iterator &iter) noexcept;
  simdjson_warn_unused simdjson_inline error_code end_container(json_iterator &iter, internal::tape_type start, internal::tape_type end) noexcept;
  simdjson_warn_unused simdjson_inline error_code empty_container(json_iterator &iter, internal::tape_type start, internal::tape_type end) noexcept;
  simdjson_inline uint8_t *on_start_string(json_iterator &iter) noexcept;
  simdjson_inline void on_end_string(uint8_t *dst) noexcept;
}; // struct tape_builder_impl

// Thin, non-templated entry so each architecture's stage2() keeps calling
// tape_builder::parse_document<STREAMING> unchanged. It chooses the bounds-safe
// (unpadded) or the regular (padded) tape_builder_impl ONCE per document, so the
// choice is a compile-time constant inside the walk: the padded path carries no
// extra branch or load (see tape_builder_impl::visit_string).
struct tape_builder {
  template<bool STREAMING>
  simdjson_warn_unused static simdjson_inline error_code parse_document(
      dom_parser_implementation &dom_parser, dom::document &doc) noexcept { __builtin_trap() /* STUB: not implemented */; }
};

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_root_primitive(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_primitive(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_empty_object(json_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_empty_array(json_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_document_start(json_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_object_start(json_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_array_start(json_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_object_end(json_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_array_end(json_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_document_end(json_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }
template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_key(json_iterator &iter, const uint8_t *key) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::increment_count(json_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_inline tape_builder_impl<UNPADDED>::tape_builder_impl(dom::document &doc) noexcept : tape{doc.tape.get()}, current_string_buf_loc{doc.string_buf.get()} {}

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_string(json_iterator &iter, const uint8_t *value, bool key) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_root_string(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_number(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_root_number(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_true_atom(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_root_true_atom(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_false_atom(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_root_false_atom(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_null_atom(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_root_null_atom(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_ENABLE_NAN_INF
template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_nan_atom(json_iterator &iter, const uint8_t *value, error_code errc) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_root_nan_atom(json_iterator &iter, const uint8_t *value, error_code errc) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_inf_atom(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::visit_root_inf_atom(json_iterator &iter, const uint8_t *value) noexcept { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_ENABLE_NAN_INF

// private:

template <bool UNPADDED>
simdjson_inline uint32_t tape_builder_impl<UNPADDED>::next_tape_index(json_iterator &iter) const noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::empty_container(json_iterator &iter, internal::tape_type start, internal::tape_type end) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_inline void tape_builder_impl<UNPADDED>::start_container(json_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_warn_unused simdjson_inline error_code tape_builder_impl<UNPADDED>::end_container(json_iterator &iter, internal::tape_type start, internal::tape_type end) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_inline uint8_t *tape_builder_impl<UNPADDED>::on_start_string(json_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }

template <bool UNPADDED>
simdjson_inline void tape_builder_impl<UNPADDED>::on_end_string(uint8_t *dst) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace stage2
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SRC_GENERIC_STAGE2_TAPE_BUILDER_H
