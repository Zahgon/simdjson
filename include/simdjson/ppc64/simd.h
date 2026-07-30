#ifndef SIMDJSON_PPC64_SIMD_H
#define SIMDJSON_PPC64_SIMD_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/ppc64/base.h"
#include "simdjson/ppc64/bitmanipulation.h"
#include "simdjson/internal/simdprune_tables.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <type_traits>

namespace simdjson {
namespace ppc64 {
namespace {
namespace simd {

using __m128i = __vector unsigned char;

template <typename Child> struct base {
  __m128i value;

  // Zero constructor
  simdjson_inline base() : value{__m128i()} { __builtin_trap() /* STUB: not implemented */; }

  // Conversion from SIMD register
  simdjson_inline base(const __m128i _value) : value(_value) { __builtin_trap() /* STUB: not implemented */; }

  // Conversion to SIMD register
  simdjson_inline operator const __m128i &() const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline operator __m128i &() { __builtin_trap() /* STUB: not implemented */; }

  // Bit operations
  simdjson_inline Child operator|(const Child other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline Child operator&(const Child other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline Child operator^(const Child other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline Child bit_andnot(const Child other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline Child &operator|=(const Child other) { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline Child &operator&=(const Child other) { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline Child &operator^=(const Child other) { __builtin_trap() /* STUB: not implemented */; }
};

template <typename T, typename Mask = simd8<bool>>
struct base8 : base<simd8<T>> {
  typedef uint16_t bitmask_t;
  typedef uint32_t bitmask2_t;

  simdjson_inline base8() : base<simd8<T>>() { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline base8(const __m128i _value) : base<simd8<T>>(_value) {}

  friend simdjson_inline Mask operator==(const simd8<T> lhs, const simd8<T> rhs) { __builtin_trap() /* STUB: not implemented */; }

  static const int SIZE = sizeof(base<simd8<T>>::value);

  template <int N = 1>
  simdjson_inline simd8<T> prev(simd8<T> prev_chunk) const { __builtin_trap() /* STUB: not implemented */; }
};

// SIMD byte mask type (returned by things like eq and gt)
template <> struct simd8<bool> : base8<bool> {
  static simdjson_inline simd8<bool> splat(bool _value) { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline simd8() : base8<bool>() { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8(const __m128i _value)
      : base8<bool>(_value) { __builtin_trap() /* STUB: not implemented */; }
  // Splat constructor
  simdjson_inline simd8(bool _value)
      : base8<bool>(splat(_value)) { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline int to_bitmask() const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline bool any() const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<bool> operator~() const { __builtin_trap() /* STUB: not implemented */; }
};

template <typename T> struct base8_numeric : base8<T> {
  static simdjson_inline simd8<T> splat(T value) { __builtin_trap() /* STUB: not implemented */; }
  static simdjson_inline simd8<T> zero() { __builtin_trap() /* STUB: not implemented */; }
  static simdjson_inline simd8<T> load(const T values[16]) { __builtin_trap() /* STUB: not implemented */; }
  // Repeat 16 values as many times as necessary (usually for lookup tables)
  static simdjson_inline simd8<T> repeat_16(T v0, T v1, T v2, T v3, T v4,
                                                   T v5, T v6, T v7, T v8, T v9,
                                                   T v10, T v11, T v12, T v13,
                                                   T v14, T v15) { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline base8_numeric() : base8<T>() { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline base8_numeric(const __m128i _value)
      : base8<T>(_value) {}

  // Store to array
  simdjson_inline void store(T dst[16]) const { __builtin_trap() /* STUB: not implemented */; }

  // Override to distinguish from bool version
  simdjson_inline simd8<T> operator~() const { __builtin_trap() /* STUB: not implemented */; }

  // Addition/subtraction are the same for signed and unsigned
  simdjson_inline simd8<T> operator+(const simd8<T> other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<T> operator-(const simd8<T> other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<T> &operator+=(const simd8<T> other) { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<T> &operator-=(const simd8<T> other) { __builtin_trap() /* STUB: not implemented */; }

  // Perform a lookup assuming the value is between 0 and 16 (undefined behavior
  // for out of range values)
  template <typename L>
  simdjson_inline simd8<L> lookup_16(simd8<L> lookup_table) const { __builtin_trap() /* STUB: not implemented */; }

  // Copies to 'output" all bytes corresponding to a 0 in the mask (interpreted
  // as a bitset). Passing a 0 value for mask would be equivalent to writing out
  // every byte to output. Only the first 16 - count_ones(mask) bytes of the
  // result are significant but 16 bytes get written. Design consideration: it
  // seems like a function with the signature simd8<L> compress(uint32_t mask)
  // would be sensible, but the AVX ISA makes this kind of approach difficult.
  template <typename L>
  simdjson_inline void compress(uint16_t mask, L *output) const { __builtin_trap() /* STUB: not implemented */; }

  template <typename L>
  simdjson_inline simd8<L>
  lookup_16(L replace0, L replace1, L replace2, L replace3, L replace4,
            L replace5, L replace6, L replace7, L replace8, L replace9,
            L replace10, L replace11, L replace12, L replace13, L replace14,
            L replace15) const { __builtin_trap() /* STUB: not implemented */; }
};

// Signed bytes
template <> struct simd8<int8_t> : base8_numeric<int8_t> {
  simdjson_inline simd8() : base8_numeric<int8_t>() { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8(const __m128i _value)
      : base8_numeric<int8_t>(_value) { __builtin_trap() /* STUB: not implemented */; }
  // Splat constructor
  simdjson_inline simd8(int8_t _value) : simd8(splat(_value)) { __builtin_trap() /* STUB: not implemented */; }
  // Array constructor
  simdjson_inline simd8(const int8_t *values) : simd8(load(values)) { __builtin_trap() /* STUB: not implemented */; }
  // Member-by-member initialization
  simdjson_inline simd8(int8_t v0, int8_t v1, int8_t v2, int8_t v3,
                               int8_t v4, int8_t v5, int8_t v6, int8_t v7,
                               int8_t v8, int8_t v9, int8_t v10, int8_t v11,
                               int8_t v12, int8_t v13, int8_t v14, int8_t v15)
      : simd8((__m128i)(__vector signed char){v0, v1, v2, v3, v4, v5, v6, v7,
                                              v8, v9, v10, v11, v12, v13, v14,
                                              v15}) { __builtin_trap() /* STUB: not implemented */; }
  // Repeat 16 values as many times as necessary (usually for lookup tables)
  simdjson_inline static simd8<int8_t>
  repeat_16(int8_t v0, int8_t v1, int8_t v2, int8_t v3, int8_t v4, int8_t v5,
            int8_t v6, int8_t v7, int8_t v8, int8_t v9, int8_t v10, int8_t v11,
            int8_t v12, int8_t v13, int8_t v14, int8_t v15) { __builtin_trap() /* STUB: not implemented */; }

  // Order-sensitive comparisons
  simdjson_inline simd8<int8_t>
  max_val(const simd8<int8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<int8_t>
  min_val(const simd8<int8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<bool>
  operator>(const simd8<int8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<bool>
  operator<(const simd8<int8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
};

// Unsigned bytes
template <> struct simd8<uint8_t> : base8_numeric<uint8_t> {
  simdjson_inline simd8() : base8_numeric<uint8_t>() { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8(const __m128i _value)
      : base8_numeric<uint8_t>(_value) { __builtin_trap() /* STUB: not implemented */; }
  // Splat constructor
  simdjson_inline simd8(uint8_t _value) : simd8(splat(_value)) { __builtin_trap() /* STUB: not implemented */; }
  // Array constructor
  simdjson_inline simd8(const uint8_t *values) : simd8(load(values)) { __builtin_trap() /* STUB: not implemented */; }
  // Member-by-member initialization
  simdjson_inline
  simd8(uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t v5,
        uint8_t v6, uint8_t v7, uint8_t v8, uint8_t v9, uint8_t v10,
        uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15)
      : simd8((__m128i){v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12,
                        v13, v14, v15}) { __builtin_trap() /* STUB: not implemented */; }
  // Repeat 16 values as many times as necessary (usually for lookup tables)
  simdjson_inline static simd8<uint8_t>
  repeat_16(uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4,
            uint8_t v5, uint8_t v6, uint8_t v7, uint8_t v8, uint8_t v9,
            uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14,
            uint8_t v15) { __builtin_trap() /* STUB: not implemented */; }

  // Saturated math
  simdjson_inline simd8<uint8_t>
  saturating_add(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<uint8_t>
  saturating_sub(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }

  // Order-specific operations
  simdjson_inline simd8<uint8_t>
  max_val(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<uint8_t>
  min_val(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
  // Same as >, but only guarantees true is nonzero (< guarantees true = -1)
  simdjson_inline simd8<uint8_t>
  gt_bits(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
  // Same as <, but only guarantees true is nonzero (< guarantees true = -1)
  simdjson_inline simd8<uint8_t>
  lt_bits(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<bool>
  operator<=(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<bool>
  operator>=(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<bool>
  operator>(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<bool>
  operator<(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }

  // Bit-specific operations
  simdjson_inline simd8<bool> bits_not_set() const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<bool> bits_not_set(simd8<uint8_t> bits) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<bool> any_bits_set() const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8<bool> any_bits_set(simd8<uint8_t> bits) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline bool bits_not_set_anywhere() const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline bool any_bits_set_anywhere() const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline bool bits_not_set_anywhere(simd8<uint8_t> bits) const { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline bool any_bits_set_anywhere(simd8<uint8_t> bits) const { __builtin_trap() /* STUB: not implemented */; }
  template <int N> simdjson_inline simd8<uint8_t> shr() const { __builtin_trap() /* STUB: not implemented */; }
  template <int N> simdjson_inline simd8<uint8_t> shl() const { __builtin_trap() /* STUB: not implemented */; }
};

template <typename T> struct simd8x64 {
  static constexpr int NUM_CHUNKS = 64 / sizeof(simd8<T>);
  static_assert(NUM_CHUNKS == 4,
                "PPC64 kernel should use four registers per 64-byte block.");
  const simd8<T> chunks[NUM_CHUNKS];
  template<int idx> simd8<uint8_t> get() const { __builtin_trap() /* STUB: not implemented */; }

  simd8x64(const simd8x64<T> &o) = delete; // no copy allowed
  simd8x64<T> &
  operator=(const simd8<T>& other) = delete; // no assignment allowed
  simd8x64() = delete;                      // no default constructor allowed

  simdjson_inline simd8x64(const simd8<T> chunk0, const simd8<T> chunk1,
                                  const simd8<T> chunk2, const simd8<T> chunk3)
      : chunks{chunk0, chunk1, chunk2, chunk3} { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline simd8x64(const T ptr[64])
      : chunks{simd8<T>::load(ptr), simd8<T>::load(ptr + 16),
               simd8<T>::load(ptr + 32), simd8<T>::load(ptr + 48)} { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline void store(T ptr[64]) const { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline simd8<T> reduce_or() const { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline uint64_t compress(uint64_t mask, T *output) const { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline uint64_t to_bitmask() const { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline uint64_t eq(const T m) const { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline uint64_t eq(const simd8x64<uint8_t> &other) const { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline uint64_t lteq(const T m) const { __builtin_trap() /* STUB: not implemented */; }
}; // struct simd8x64<T>

} // namespace simd
} // unnamed namespace
} // namespace ppc64
} // namespace simdjson

#endif // SIMDJSON_PPC64_SIMD_INPUT_H
