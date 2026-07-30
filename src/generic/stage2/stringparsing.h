#include <cstdint>
#ifndef SIMDJSON_SRC_GENERIC_STAGE2_STRINGPARSING_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE2_STRINGPARSING_H
#include <generic/stage2/base.h>
#include <simdjson/generic/jsoncharutils.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

// This file contains the common code every implementation uses
// It is intended to be included multiple times and compiled multiple times

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
/// @private
namespace stringparsing {

// begin copypasta
// These chars yield themselves: " \ /
// b -> backspace, f -> formfeed, n -> newline, r -> cr, t -> horizontal tab
// u not handled in this table as it's complex
static const uint8_t escape_map[256] = {
    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0, // 0x0.
    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0,
    0, 0, 0x22, 0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0x2f,
    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0,

    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0, // 0x4.
    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0x5c, 0, 0,    0, // 0x5.
    0, 0, 0x08, 0, 0,    0, 0x0c, 0, 0, 0, 0, 0, 0,    0, 0x0a, 0, // 0x6.
    0, 0, 0x0d, 0, 0x09, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0, // 0x7.

    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0,
    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0,
    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0,
    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0,

    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0,
    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0,
    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0,
    0, 0, 0,    0, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0,    0,
};

// handle a unicode codepoint
// write appropriate values into dest
// src will advance 6 bytes or 12 bytes
// dest will advance a variable amount (return via pointer)
// return true if the unicode codepoint was valid
// We work in little-endian then swap at write time
simdjson_warn_unused
simdjson_inline bool handle_unicode_codepoint(const uint8_t **src_ptr,
                                            uint8_t **dst_ptr, bool allow_replacement) { __builtin_trap() /* STUB: not implemented */; }


// handle a unicode codepoint using the wobbly convention
// https://simonsapin.github.io/wtf-8/
// write appropriate values into dest
// src will advance 6 bytes or 12 bytes
// dest will advance a variable amount (return via pointer)
// return true if the unicode codepoint was valid
// We work in little-endian then swap at write time
simdjson_warn_unused
simdjson_inline bool handle_unicode_codepoint_wobbly(const uint8_t **src_ptr,
                                            uint8_t **dst_ptr) { __builtin_trap() /* STUB: not implemented */; }


/**
 * Unescape a valid UTF-8 string from src to dst, stopping at a final unescaped quote. There
 * must be an unescaped quote terminating the string. It returns the final output
 * position as pointer. In case of error (e.g., the string has bad escaped codes),
 * then null_ptr is returned. It is assumed that the output buffer is large
 * enough. E.g., if src points at 'joe"', then dst needs to have four free bytes +
 * SIMDJSON_PADDING bytes.
 */
simdjson_warn_unused simdjson_inline uint8_t *parse_string(const uint8_t *src, uint8_t *dst, bool allow_replacement) { __builtin_trap() /* STUB: not implemented */; }

/**
 * Bounds-safe variant of parse_string for input buffers that are NOT padded to
 * len + SIMDJSON_PADDING bytes. `buf_end` is one past the last readable input
 * byte (buf + len). It behaves exactly like parse_string while we are at least
 * SIMDJSON_PADDING bytes away from buf_end (so every speculative SIMD read stays
 * in bounds); once within the final SIMDJSON_PADDING bytes it copies the few
 * remaining bytes into a space-padded scratch buffer and finishes with the
 * regular parse_string. This keeps the delicate escape/Unicode handling in one
 * place (the proven parse_string) rather than duplicating it.
 *
 * Correctness relies on stage 1 having validated the string, i.e. there is an
 * unescaped closing quote within [src, buf_end); that quote is therefore inside
 * the copied scratch, so parse_string finds it without running off the scratch.
 */
simdjson_warn_unused simdjson_inline uint8_t *parse_string_safe(const uint8_t *src, uint8_t *dst, bool allow_replacement, const uint8_t *buf_end) { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline uint8_t *parse_wobbly_string(const uint8_t *src, uint8_t *dst) { __builtin_trap() /* STUB: not implemented */; }

} // namespace stringparsing

} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SRC_GENERIC_STAGE2_STRINGPARSING_H