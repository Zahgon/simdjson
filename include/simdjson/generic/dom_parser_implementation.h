#ifndef SIMDJSON_GENERIC_DOM_PARSER_IMPLEMENTATION_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_DOM_PARSER_IMPLEMENTATION_H
#include "simdjson/generic/base.h"
#include "simdjson/internal/dom_parser_implementation.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {

// expectation: sizeof(open_container) = 64/8.
struct open_container {
  uint32_t tape_index; // where, on the tape, does the scope ([,{) begins
  uint32_t count; // how many elements in the scope
}; // struct open_container

static_assert(sizeof(open_container) == 64/8, "Open container must be 64 bits");

class dom_parser_implementation final : public internal::dom_parser_implementation {
public:
  /** Tape location of each open { or [ */
  std::unique_ptr<open_container[]> open_containers{};
  /** Whether each open container is a [ or { */
  std::unique_ptr<bool[]> is_array{};
  /** Buffer passed to stage 1 */
  const uint8_t *buf{};
  /** Length passed to stage 1 */
  size_t len{0};
  /** Document passed to stage 2 */
  dom::document *doc{};

  inline dom_parser_implementation() noexcept;
  inline dom_parser_implementation(dom_parser_implementation &&other) noexcept;
  inline dom_parser_implementation &operator=(dom_parser_implementation &&other) noexcept;
  dom_parser_implementation(const dom_parser_implementation &) = delete;
  dom_parser_implementation &operator=(const dom_parser_implementation &) = delete;

  simdjson_warn_unused error_code parse(const uint8_t *buf, size_t len, dom::document &doc) noexcept final;
  simdjson_warn_unused error_code stage1(const uint8_t *buf, size_t len, stage1_mode partial) noexcept final;
  simdjson_warn_unused error_code stage2(dom::document &doc) noexcept final;
  simdjson_warn_unused error_code stage2_next(dom::document &doc) noexcept final;
  simdjson_warn_unused uint8_t *parse_string(const uint8_t *src, uint8_t *dst, bool allow_replacement) const noexcept final;
  simdjson_warn_unused uint8_t *parse_wobbly_string(const uint8_t *src, uint8_t *dst) const noexcept final;
  inline simdjson_warn_unused error_code set_capacity(size_t capacity) noexcept final;
  inline simdjson_warn_unused error_code set_max_depth(size_t max_depth) noexcept final;
private:
  simdjson_inline simdjson_warn_unused error_code set_capacity_stage1(size_t capacity);

};

} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {

inline dom_parser_implementation::dom_parser_implementation() noexcept = default;
inline dom_parser_implementation::dom_parser_implementation(dom_parser_implementation &&other) noexcept = default;
inline dom_parser_implementation &dom_parser_implementation::operator=(dom_parser_implementation &&other) noexcept = default;

// Leaving these here so they can be inlined if so desired
inline simdjson_warn_unused error_code dom_parser_implementation::set_capacity(size_t capacity) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_warn_unused error_code dom_parser_implementation::set_max_depth(size_t max_depth) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_GENERIC_DOM_PARSER_IMPLEMENTATION_H