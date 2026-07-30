#ifndef SIMDJSON_SRC_GENERIC_STAGE1_UTF8_VALIDATOR_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE1_UTF8_VALIDATOR_H
#include <generic/stage1/base.h>
#include <generic/stage1/buf_block_reader.h>
#include <generic/stage1/utf8_lookup4_algorithm.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace stage1 {

/**
 * Validates that the string is actual UTF-8.
 */
template<class checker>
bool generic_validate_utf8(const uint8_t * input, size_t length) { __builtin_trap() /* STUB: not implemented */; }

bool generic_validate_utf8(const char * input, size_t length) { __builtin_trap() /* STUB: not implemented */; }

} // namespace stage1
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SRC_GENERIC_STAGE1_UTF8_VALIDATOR_H