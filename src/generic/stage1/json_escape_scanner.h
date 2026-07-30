#ifndef SIMDJSON_SRC_GENERIC_STAGE1_JSON_ESCAPE_SCANNER_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE1_JSON_ESCAPE_SCANNER_H
#include <generic/stage1/base.h>
#include <generic/stage1/buf_block_reader.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace stage1 {

/**
 * Scans for escape characters in JSON, taking care with multiple backslashes (\\n vs. \n).
 */
struct json_escape_scanner {
  /** The actual escape characters (the backslashes themselves). */
  uint64_t next_is_escaped = 0ULL;

  struct escaped_and_escape {
    /**
     * Mask of escaped characters.
     *
     * ```
     * \n \\n \\\n \\\\n \
     * 0100100010100101000
     *  n  \   \ n  \ \
     * ```
     */
    uint64_t escaped;
    /**
     * Mask of escape characters.
     *
     * ```
     * \n \\n \\\n \\\\n \
     * 1001000101001010001
     * \  \   \ \  \ \   \
     * ```
     */
    uint64_t escape;
  };

  /**
   * Get a mask of both escape and escaped characters (the characters following a backslash).
   *
   * @param potential_escape A mask of the character that can escape others (but could be
   *        escaped itself). e.g. block.eq('\\')
   */
  simdjson_really_inline escaped_and_escape next(uint64_t backslash) noexcept { __builtin_trap() /* STUB: not implemented */; }

private:
  static constexpr const uint64_t ODD_BITS = 0xAAAAAAAAAAAAAAAAULL;

  simdjson_really_inline uint64_t next_escaped_without_backslashes() noexcept { __builtin_trap() /* STUB: not implemented */; }

  /**
   * Returns a mask of the next escape characters (masking out escaped backslashes), along with
   * any non-backslash escape codes.
   *
   * \n \\n \\\n \\\\n returns:
   * \n \   \ \n \ \
   * 11 100 1011 10100
   *
   * You are expected to mask out the first bit yourself if the previous block had a trailing
   * escape.
   *
   * & the result with potential_escape to get just the escape characters.
   * ^ the result with (potential_escape | first_is_escaped) to get escaped characters.
   */
  static simdjson_really_inline uint64_t next_escape_and_terminal_code(uint64_t potential_escape) noexcept { __builtin_trap() /* STUB: not implemented */; }
};

} // namespace stage1
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SRC_GENERIC_STAGE1_JSON_STRING_SCANNER_H