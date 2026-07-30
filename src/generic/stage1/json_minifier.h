#ifndef SIMDJSON_SRC_GENERIC_STAGE1_JSON_MINIFIER_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE1_JSON_MINIFIER_H
#include <generic/stage1/base.h>
#include <generic/stage1/json_scanner.h>
#include <generic/stage1/buf_block_reader.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

// This file contains the common code every implementation uses in stage1
// It is intended to be included multiple times and compiled multiple times
// We assume the file in which it is included already includes
// "simdjson/stage1.h" (this simplifies amalgation)

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace stage1 {

class json_minifier {
public:
  template<size_t STEP_SIZE>
  static error_code minify(const uint8_t *buf, size_t len, uint8_t *dst, size_t &dst_len) noexcept;

private:
  simdjson_inline json_minifier(uint8_t *_dst)
  : dst{_dst}
  { __builtin_trap() /* STUB: not implemented */; }
  template<size_t STEP_SIZE>
  simdjson_inline void step(const uint8_t *block_buf, buf_block_reader<STEP_SIZE> &reader) noexcept;
  simdjson_inline void next(const simd::simd8x64<uint8_t>& in, const json_block& block);
  simdjson_warn_unused simdjson_inline error_code finish(uint8_t *dst_start, size_t &dst_len);
  json_scanner scanner{};
  uint8_t *dst;
};

simdjson_inline void json_minifier::next(const simd::simd8x64<uint8_t>& in, const json_block& block) { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused simdjson_inline error_code json_minifier::finish(uint8_t *dst_start, size_t &dst_len) { __builtin_trap() /* STUB: not implemented */; }

template<>
simdjson_inline void json_minifier::step<128>(const uint8_t *block_buf, buf_block_reader<128> &reader) noexcept { __builtin_trap() /* STUB: not implemented */; }

template<>
simdjson_inline void json_minifier::step<64>(const uint8_t *block_buf, buf_block_reader<64> &reader) noexcept { __builtin_trap() /* STUB: not implemented */; }

template<size_t STEP_SIZE>
error_code json_minifier::minify(const uint8_t *buf, size_t len, uint8_t *dst, size_t &dst_len) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace stage1
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SRC_GENERIC_STAGE1_JSON_MINIFIER_H