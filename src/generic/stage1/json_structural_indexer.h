#ifndef SIMDJSON_SRC_GENERIC_STAGE1_JSON_STRUCTURAL_INDEXER_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE1_JSON_STRUCTURAL_INDEXER_H
#include <generic/stage1/base.h>
#include <generic/stage1/utf8_lookup4_algorithm.h>
#include <generic/stage1/buf_block_reader.h>
#include <generic/stage1/json_string_scanner.h>
#include <generic/stage1/json_scanner.h>
#include <generic/stage1/json_minifier.h>
#include <generic/stage1/find_next_document_index.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

// This file contains the common code every implementation uses in stage1
// It is intended to be included multiple times and compiled multiple times
// We assume the file in which it is included already includes
// "simdjson/stage1.h" (this simplifies amalgation)

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace stage1 {

class bit_indexer {
public:
  uint32_t *tail;

  simdjson_inline bit_indexer(uint32_t *index_buf) : tail(index_buf) { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_PREFER_REVERSE_BITS
  /**
    * ARM lacks a fast trailing zero instruction, but it has a fast
    * bit reversal instruction and a fast leading zero instruction.
    * Thus it may be profitable to reverse the bits (once) and then
    * to rely on a sequence of instructions that call the leading
    * zero instruction.
    *
    * Performance notes:
    * The chosen routine is not optimal in terms of data dependency
    * since zero_leading_bit might require two instructions. However,
    * it tends to minimize the total number of instructions which is
    * beneficial.
    */
  simdjson_inline void write_index(uint32_t idx, uint64_t& rev_bits, int i) { __builtin_trap() /* STUB: not implemented */; }
#else
  /**
    * Under recent x64 systems, we often have both a fast trailing zero
    * instruction and a fast 'clear-lower-bit' instruction so the following
    * algorithm can be competitive.
    */

  simdjson_inline void write_index(uint32_t idx, uint64_t& bits, int i) { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_PREFER_REVERSE_BITS

  template <int START, int N>
  simdjson_inline int write_indexes(uint32_t idx, uint64_t& bits) { __builtin_trap() /* STUB: not implemented */; }

  template <int START, int END, int STEP>
  simdjson_inline int write_indexes_stepped(uint32_t idx, uint64_t& bits, int cnt) { __builtin_trap() /* STUB: not implemented */; }

  // flatten out values in 'bits' assuming that they are are to have values of idx
  // plus their position in the bitvector, and store these indexes at
  // base_ptr[base] incrementing base as we go
  // will potentially store extra values beyond end of valid bits, so base_ptr
  // needs to be large enough to handle this
  //
  // If the kernel sets SIMDJSON_GENERIC_JSON_STRUCTURAL_INDEXER_CUSTOM_BIT_INDEXER, then it
  // will provide its own version of the code.
#ifdef SIMDJSON_GENERIC_JSON_STRUCTURAL_INDEXER_CUSTOM_BIT_INDEXER
  simdjson_inline void write(uint32_t idx, uint64_t bits);
#else
  simdjson_inline void write(uint32_t idx, uint64_t bits) { __builtin_trap() /* STUB: not implemented */; }
#endif // SIMDJSON_GENERIC_JSON_STRUCTURAL_INDEXER_CUSTOM_BIT_INDEXER

};

class json_structural_indexer {
public:
  /**
   * Find the important bits of JSON in a 128-byte chunk, and add them to structural_indexes.
   *
   * @param partial Setting the partial parameter to true allows the find_structural_bits to
   *   tolerate unclosed strings. The caller should still ensure that the input is valid UTF-8. If
   *   you are processing substrings, you may want to call on a function like trimmed_length_safe_utf8.
   */
  template<size_t STEP_SIZE>
  static error_code index(const uint8_t *buf, size_t len, dom_parser_implementation &parser, stage1_mode partial) noexcept;

private:
  simdjson_inline json_structural_indexer(uint32_t *structural_indexes);
  template<size_t STEP_SIZE>
  simdjson_inline void step(const uint8_t *block, buf_block_reader<STEP_SIZE> &reader) noexcept;
  simdjson_inline void next(const simd::simd8x64<uint8_t>& in, const json_block& block, size_t idx);
  simdjson_warn_unused simdjson_inline error_code finish(dom_parser_implementation &parser, size_t idx, size_t len, stage1_mode partial);

  json_scanner scanner{};
  utf8_checker checker{};
  bit_indexer indexer;
  uint64_t prev_structurals = 0;
  uint64_t unescaped_chars_error = 0;
};

simdjson_inline json_structural_indexer::json_structural_indexer(uint32_t *structural_indexes) : indexer{structural_indexes} {}

// Skip the last character if it is partial
simdjson_inline size_t trim_partial_utf8(const uint8_t *buf, size_t len) { __builtin_trap() /* STUB: not implemented */; }

//
// PERF NOTES:
// We pipe 2 inputs through these stages:
// 1. Load JSON into registers. This takes a long time and is highly parallelizable, so we load
//    2 inputs' worth at once so that by the time step 2 is looking for them input, it's available.
// 2. Scan the JSON for critical data: strings, scalars and operators. This is the critical path.
//    The output of step 1 depends entirely on this information. These functions don't quite use
//    up enough CPU: the second half of the functions is highly serial, only using 1 execution core
//    at a time. The second input's scans has some dependency on the first ones finishing it, but
//    they can make a lot of progress before they need that information.
// 3. Step 1 does not use enough capacity, so we run some extra stuff while we're waiting for that
//    to finish: utf-8 checks and generating the output from the last iteration.
//
// The reason we run 2 inputs at a time, is steps 2 and 3 are *still* not enough to soak up all
// available capacity with just one input. Running 2 at a time seems to give the CPU a good enough
// workout.
//
template<size_t STEP_SIZE>
error_code json_structural_indexer::index(const uint8_t *buf, size_t len, dom_parser_implementation &parser, stage1_mode partial) noexcept { __builtin_trap() /* STUB: not implemented */; }

template<>
simdjson_inline void json_structural_indexer::step<128>(const uint8_t *block, buf_block_reader<128> &reader) noexcept { __builtin_trap() /* STUB: not implemented */; }

template<>
simdjson_inline void json_structural_indexer::step<64>(const uint8_t *block, buf_block_reader<64> &reader) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void json_structural_indexer::next(const simd::simd8x64<uint8_t>& in, const json_block& block, size_t idx) { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline error_code json_structural_indexer::finish(dom_parser_implementation &parser, size_t idx, size_t len, stage1_mode partial) { __builtin_trap() /* STUB: not implemented */; }

} // namespace stage1
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

// Clear CUSTOM_BIT_INDEXER so other implementations can set it if they need to.
#undef SIMDJSON_GENERIC_JSON_STRUCTURAL_INDEXER_CUSTOM_BIT_INDEXER

#endif // SIMDJSON_SRC_GENERIC_STAGE1_JSON_STRUCTURAL_INDEXER_H
