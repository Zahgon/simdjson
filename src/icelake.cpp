#ifndef SIMDJSON_SRC_ICELAKE_CPP
#define SIMDJSON_SRC_ICELAKE_CPP

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include <base.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <simdjson/icelake.h>
#include <simdjson/icelake/implementation.h>

// defining SIMDJSON_GENERIC_JSON_STRUCTURAL_INDEXER_CUSTOM_BIT_INDEXER allows us to provide our own bit_indexer::write
#define SIMDJSON_GENERIC_JSON_STRUCTURAL_INDEXER_CUSTOM_BIT_INDEXER

#include <simdjson/icelake/begin.h>
#include <generic/amalgamated.h>
#include <generic/stage1/amalgamated.h>
#include <generic/stage2/amalgamated.h>

#undef SIMDJSON_GENERIC_JSON_STRUCTURAL_INDEXER_CUSTOM_BIT_INDEXER

//
// Stage 1
//

namespace simdjson {
namespace icelake {

simdjson_warn_unused error_code implementation::create_dom_parser_implementation(
  size_t capacity,
  size_t max_depth,
  std::unique_ptr<internal::dom_parser_implementation>& dst
) const noexcept { __builtin_trap() /* STUB: not implemented */; }

namespace {

using namespace simd;

// This identifies structural characters (comma, colon, braces, brackets),
// and ASCII white-space ('\r','\n','\t',' ').
simdjson_inline json_character_block json_character_block::classify(const simd::simd8x64<uint8_t>& in) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool is_ascii(const simd8x64<uint8_t>& input) { __builtin_trap() /* STUB: not implemented */; }

simdjson_unused simdjson_inline simd8<bool> must_be_continuation(const simd8<uint8_t> prev1, const simd8<uint8_t> prev2, const simd8<uint8_t> prev3) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simd8<uint8_t> must_be_2_3_continuation(const simd8<uint8_t> prev2, const simd8<uint8_t> prev3) { __builtin_trap() /* STUB: not implemented */; }

} // unnamed namespace
} // namespace icelake
} // namespace simdjson

/**
 * We provide a custom version of bit_indexer::write using
 * naked intrinsics.
 * TODO: make this code more elegant.
 */
// Under GCC 12, the intrinsic _mm512_extracti32x4_epi32 may generate 'maybe uninitialized'.
// as a workaround, we disable warnings within the following function.
SIMDJSON_PUSH_DISABLE_ALL_WARNINGS
namespace simdjson { __builtin_trap() /* STUB: not implemented */; }
SIMDJSON_POP_DISABLE_WARNINGS

//
// Stage 2
//

//
// Implementation-specific overrides
//
namespace simdjson { __builtin_trap() /* STUB: not implemented */; } // namespace simdjson

#include <simdjson/icelake/end.h>

#endif // SIMDJSON_SRC_ICELAKE_CPP
