#ifndef SIMDJSON_SRC_GENERIC_STAGE1_JSON_SCANNER_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE1_JSON_SCANNER_H
#include <generic/stage1/base.h>
#include <generic/json_character_block.h>
#include <generic/stage1/json_string_scanner.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace stage1 {

/**
 * A block of scanned json, with information on operators and scalars.
 *
 * We seek to identify pseudo-structural characters. Anything that is inside
 * a string must be omitted (hence  & ~_string.string_tail()).
 * Otherwise, pseudo-structural characters come in two forms.
 * 1. We have the structural characters ([,],{,},:, comma). The
 *    term 'structural character' is from the JSON RFC.
 * 2. We have the 'scalar pseudo-structural characters'.
 *    Scalars are quotes, and any character except structural characters and white space.
 *
 * To identify the scalar pseudo-structural characters, we must look at what comes
 * before them: it must be a space, a quote or a structural characters.
 * Starting with simdjson v0.3, we identify them by
 * negation: we identify everything that is followed by a non-quote scalar,
 * and we negate that. Whatever remains must be a 'scalar pseudo-structural character'.
 */
struct json_block {
public:
  // We spell out the constructors in the hope of resolving inlining issues with Visual Studio 2017
  simdjson_inline json_block(json_string_block&& string, json_character_block characters, uint64_t follows_potential_nonquote_scalar) :
  _string(std::move(string)), _characters(characters), _follows_potential_nonquote_scalar(follows_potential_nonquote_scalar) {}
  simdjson_inline json_block(json_string_block string, json_character_block characters, uint64_t follows_potential_nonquote_scalar) :
  _string(string), _characters(characters), _follows_potential_nonquote_scalar(follows_potential_nonquote_scalar) {}

  /**
   * The start of structurals.
   * In simdjson prior to v0.3, these were called the pseudo-structural characters.
   **/
  simdjson_inline uint64_t structural_start() const noexcept { __builtin_trap() /* STUB: not implemented */; }
  /** All JSON whitespace (i.e. not in a string) */
  simdjson_inline uint64_t whitespace() const noexcept { __builtin_trap() /* STUB: not implemented */; }

  // Helpers

  /** Whether the given characters are inside a string (only works on non-quotes) */
  simdjson_inline uint64_t non_quote_inside_string(uint64_t mask) const noexcept { __builtin_trap() /* STUB: not implemented */; }
  /** Whether the given characters are outside a string (only works on non-quotes) */
  simdjson_inline uint64_t non_quote_outside_string(uint64_t mask) const noexcept { __builtin_trap() /* STUB: not implemented */; }

  // string and escape characters
  json_string_block _string;
  // whitespace, structural characters ('operators'), scalars
  json_character_block _characters;
  // whether the previous character was a scalar
  uint64_t _follows_potential_nonquote_scalar;
private:
  // Potential structurals (i.e. disregarding strings)

  /**
   * structural elements ([,],{,},:, comma) plus scalar starts like 123, true and "abc".
   * They may reside inside a string.
   **/
  simdjson_inline uint64_t potential_structural_start() const noexcept { __builtin_trap() /* STUB: not implemented */; }
  /**
   * The start of non-operator runs, like 123, true and "abc".
   * It main reside inside a string.
   **/
  simdjson_inline uint64_t potential_scalar_start() const noexcept { __builtin_trap() /* STUB: not implemented */; }
  /**
   * Whether the given character is immediately after a non-operator like 123, true.
   * The characters following a quote are not included.
   */
  simdjson_inline uint64_t follows_potential_scalar() const noexcept { __builtin_trap() /* STUB: not implemented */; }
};

/**
 * Scans JSON for important bits: structural characters or 'operators', strings, and scalars.
 *
 * The scanner starts by calculating two distinct things:
 * - string characters (taking \" into account)
 * - structural characters or 'operators' ([]{},:, comma)
 *   and scalars (runs of non-operators like 123, true and "abc")
 *
 * To minimize data dependency (a key component of the scanner's speed), it finds these in parallel:
 * in particular, the operator/scalar bit will find plenty of things that are actually part of
 * strings. When we're done, json_block will fuse the two together by masking out tokens that are
 * part of a string.
 */
class json_scanner {
public:
  json_scanner() = default;
  simdjson_inline json_block next(const simd::simd8x64<uint8_t>& in);
  // Returns either UNCLOSED_STRING or SUCCESS
  simdjson_warn_unused simdjson_inline error_code finish();

private:
  // Whether the last character of the previous iteration is part of a scalar token
  // (anything except whitespace or a structural character/'operator').
  uint64_t prev_scalar = 0ULL;
  json_string_scanner string_scanner{};
};


//
// Check if the current character immediately follows a matching character.
//
// For example, this checks for quotes with backslashes in front of them:
//
//     const uint64_t backslashed_quote = in.eq('"') & immediately_follows(in.eq('\'), prev_backslash);
//
simdjson_inline uint64_t follows(const uint64_t match, uint64_t &overflow) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline json_block json_scanner::next(const simd::simd8x64<uint8_t>& in) { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code json_scanner::finish() { __builtin_trap() /* STUB: not implemented */; }

} // namespace stage1
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SRC_GENERIC_STAGE1_JSON_SCANNER_H