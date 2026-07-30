#ifndef SIMDJSON_ARM64_SIMD_H
#define SIMDJSON_ARM64_SIMD_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/arm64/base.h"
#include "simdjson/arm64/bitmanipulation.h"
#include "simdjson/internal/simdprune_tables.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace arm64 {
namespace {
namespace simd {

#if SIMDJSON_REGULAR_VISUAL_STUDIO
namespace {
// Start of private section with Visual Studio workaround


#ifndef simdjson_make_uint8x16_t
#define simdjson_make_uint8x16_t(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, \
                             x13, x14, x15, x16)                                   \
   ([=]() {                                                                        \
     uint8_t array[16] = {x1, x2,  x3,  x4,  x5,  x6,  x7,  x8,                    \
                                 x9, x10, x11, x12, x13, x14, x15, x16};           \
     return vld1q_u8(array);                                                       \
   }())
#endif
#ifndef simdjson_make_int8x16_t
#define simdjson_make_int8x16_t(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, \
                             x13, x14, x15, x16)                                  \
   ([=]() {                                                                       \
     int8_t array[16] = {x1, x2,  x3,  x4,  x5,  x6,  x7,  x8,                    \
                                 x9, x10, x11, x12, x13, x14, x15, x16};          \
     return vld1q_s8(array);                                                      \
   }())
#endif

#ifndef simdjson_make_uint8x8_t
#define simdjson_make_uint8x8_t(x1, x2, x3, x4, x5, x6, x7, x8)                \
   ([=]() {                                                                    \
     uint8_t array[8] = {x1, x2,  x3,  x4,  x5,  x6,  x7,  x8};                \
     return vld1_u8(array);                                                    \
   }())
#endif
#ifndef simdjson_make_int8x8_t
#define simdjson_make_int8x8_t(x1, x2, x3, x4, x5, x6, x7, x8)                 \
   ([=]() {                                                                    \
     int8_t array[8] = {x1, x2,  x3,  x4,  x5,  x6,  x7,  x8};                 \
     return vld1_s8(array);                                                    \
   }())
#endif
#ifndef simdjson_make_uint16x8_t
#define simdjson_make_uint16x8_t(x1, x2, x3, x4, x5, x6, x7, x8)               \
   ([=]() {                                                                    \
     uint16_t array[8] = {x1, x2,  x3,  x4,  x5,  x6,  x7,  x8};               \
     return vld1q_u16(array);                                                  \
   }())
#endif
#ifndef simdjson_make_int16x8_t
#define simdjson_make_int16x8_t(x1, x2, x3, x4, x5, x6, x7, x8)                \
   ([=]() {                                                                    \
     int16_t array[8] = {x1, x2,  x3,  x4,  x5,  x6,  x7,  x8};                \
     return vld1q_s16(array);                                                  \
   }())
#endif

// End of private section with Visual Studio workaround
} // namespace
#endif // SIMDJSON_REGULAR_VISUAL_STUDIO


  template<typename T>
  struct simd8;

  //
  // Base class of simd8<uint8_t> and simd8<bool>, both of which use uint8x16_t internally.
  //
  template<typename T, typename Mask=simd8<bool>>
  struct base_u8 {
    uint8x16_t value;
    static const int SIZE = sizeof(value);

    // Conversion from/to SIMD register
    simdjson_inline base_u8(const uint8x16_t _value) : value(_value) {}
    simdjson_inline operator const uint8x16_t&() const { return this->value; }
    simdjson_inline operator uint8x16_t&() { __builtin_trap() /* STUB: not implemented */; }

    // Bit operations
    simdjson_inline simd8<T> operator|(const simd8<T> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<T> operator&(const simd8<T> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<T> operator^(const simd8<T> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<T> bit_andnot(const simd8<T> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<T> operator~() const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<T>& operator|=(const simd8<T> other) { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<T>& operator&=(const simd8<T> other) { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<T>& operator^=(const simd8<T> other) { __builtin_trap() /* STUB: not implemented */; }

    friend simdjson_inline Mask operator==(const simd8<T> lhs, const simd8<T> rhs) { __builtin_trap() /* STUB: not implemented */; }

    template<int N=1>
    simdjson_inline simd8<T> prev(const simd8<T> prev_chunk) const { __builtin_trap() /* STUB: not implemented */; }
  };

  // SIMD byte mask type (returned by things like eq and gt)
  template<>
  struct simd8<bool>: base_u8<bool> {
    typedef uint16_t bitmask_t;
    typedef uint32_t bitmask2_t;

    static simdjson_inline simd8<bool> splat(bool _value) { __builtin_trap() /* STUB: not implemented */; }

    simdjson_inline simd8(const uint8x16_t _value) : base_u8<bool>(_value) { __builtin_trap() /* STUB: not implemented */; }
    // False constructor
    simdjson_inline simd8() : simd8(vdupq_n_u8(0)) { __builtin_trap() /* STUB: not implemented */; }
    // Splat constructor
    simdjson_inline simd8(bool _value) : simd8(splat(_value)) { __builtin_trap() /* STUB: not implemented */; }

    // We return uint32_t instead of uint16_t because that seems to be more efficient for most
    // purposes (cutting it down to uint16_t costs performance in some compilers).
    simdjson_inline uint32_t to_bitmask() const { __builtin_trap() /* STUB: not implemented */; }
    // Returns 4-bit out of each byte, alternating between the high 4 bits and low
    // bits result it is 64 bit.
    simdjson_inline uint64_t to_bitmask64() const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline bool any() const { __builtin_trap() /* STUB: not implemented */; }
  };

  // Unsigned bytes
  template<>
  struct simd8<uint8_t>: base_u8<uint8_t> {
    static simdjson_inline uint8x16_t splat(uint8_t _value) { __builtin_trap() /* STUB: not implemented */; }
    static simdjson_inline uint8x16_t zero() { __builtin_trap() /* STUB: not implemented */; }
    static simdjson_inline uint8x16_t load(const uint8_t* values) { __builtin_trap() /* STUB: not implemented */; }

    simdjson_inline simd8(const uint8x16_t _value) : base_u8<uint8_t>(_value) { __builtin_trap() /* STUB: not implemented */; }
    // Zero constructor
    simdjson_inline simd8() : simd8(zero()) { __builtin_trap() /* STUB: not implemented */; }
    // Array constructor
    simdjson_inline simd8(const uint8_t values[16]) : simd8(load(values)) { __builtin_trap() /* STUB: not implemented */; }
    // Splat constructor
    simdjson_inline simd8(uint8_t _value) : simd8(splat(_value)) { __builtin_trap() /* STUB: not implemented */; }
    // Member-by-member initialization
#if SIMDJSON_REGULAR_VISUAL_STUDIO
    simdjson_inline simd8(
      uint8_t v0,  uint8_t v1,  uint8_t v2,  uint8_t v3,  uint8_t v4,  uint8_t v5,  uint8_t v6,  uint8_t v7,
      uint8_t v8,  uint8_t v9,  uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15
    ) : simd8(simdjson_make_uint8x16_t(
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15
    )) { __builtin_trap() /* STUB: not implemented */; }
#else
    simdjson_inline simd8(
      uint8_t v0,  uint8_t v1,  uint8_t v2,  uint8_t v3,  uint8_t v4,  uint8_t v5,  uint8_t v6,  uint8_t v7,
      uint8_t v8,  uint8_t v9,  uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15
    ) : simd8(uint8x16_t{
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15
    }) { __builtin_trap() /* STUB: not implemented */; }
#endif

    // Repeat 16 values as many times as necessary (usually for lookup tables)
    simdjson_inline static simd8<uint8_t> repeat_16(
      uint8_t v0,  uint8_t v1,  uint8_t v2,  uint8_t v3,  uint8_t v4,  uint8_t v5,  uint8_t v6,  uint8_t v7,
      uint8_t v8,  uint8_t v9,  uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15
    ) { __builtin_trap() /* STUB: not implemented */; }

    // Store to array
    simdjson_inline void store(uint8_t dst[16]) const { __builtin_trap() /* STUB: not implemented */; }

    // Saturated math
    simdjson_inline simd8<uint8_t> saturating_add(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<uint8_t> saturating_sub(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }

    // Addition/subtraction are the same for signed and unsigned
    simdjson_inline simd8<uint8_t> operator+(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<uint8_t> operator-(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<uint8_t>& operator+=(const simd8<uint8_t> other) { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<uint8_t>& operator-=(const simd8<uint8_t> other) { __builtin_trap() /* STUB: not implemented */; }

    // Order-specific operations
    simdjson_inline uint8_t max_val() const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline uint8_t min_val() const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<uint8_t> max_val(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<uint8_t> min_val(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<bool> operator<=(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<bool> operator>=(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<bool> operator<(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<bool> operator>(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    // Same as >, but instead of guaranteeing all 1's == true, false = 0 and true = nonzero. For ARM, returns all 1's.
    simdjson_inline simd8<uint8_t> gt_bits(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    // Same as <, but instead of guaranteeing all 1's == true, false = 0 and true = nonzero. For ARM, returns all 1's.
    simdjson_inline simd8<uint8_t> lt_bits(const simd8<uint8_t> other) const { __builtin_trap() /* STUB: not implemented */; }

    // Bit-specific operations
    simdjson_inline simd8<bool> any_bits_set(simd8<uint8_t> bits) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline bool any_bits_set_anywhere() const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline bool any_bits_set_anywhere(simd8<uint8_t> bits) const { __builtin_trap() /* STUB: not implemented */; }
    template<int N>
    simdjson_inline simd8<uint8_t> shr() const { __builtin_trap() /* STUB: not implemented */; }
    template<int N>
    simdjson_inline simd8<uint8_t> shl() const { __builtin_trap() /* STUB: not implemented */; }

    // Perform a lookup assuming the value is between 0 and 16 (undefined behavior for out of range values)
    template<typename L>
    simdjson_inline simd8<L> lookup_16(simd8<L> lookup_table) const { __builtin_trap() /* STUB: not implemented */; }

    // Returns 4-bit out of each byte, alternating between the high 4 bits and low
    // bits result it is 64 bit.
    simdjson_inline uint64_t to_bitmask64() const { __builtin_trap() /* STUB: not implemented */; }
    // Copies to 'output" all bytes corresponding to a 0 in the mask (interpreted as a bitset).
    // Passing a 0 value for mask would be equivalent to writing out every byte to output.
    // Only the first 16 - count_ones(mask) bytes of the result are significant but 16 bytes
    // get written.
    // Design consideration: it seems like a function with the
    // signature simd8<L> compress(uint16_t mask) would be
    // sensible, but the AVX ISA makes this kind of approach difficult.
    template<typename L>
    simdjson_inline void compress(uint16_t mask, L * output) const { __builtin_trap() /* STUB: not implemented */; }

    // Copies all bytes corresponding to a 0 in the low half of the mask (interpreted as a
    // bitset) to output1, then those corresponding to a 0 in the high half to output2.
    template<typename L>
    simdjson_inline void compress_halves(uint16_t mask, L *output1, L *output2) const { __builtin_trap() /* STUB: not implemented */; }

    template<typename L>
    simdjson_inline simd8<L> lookup_16(
        L replace0,  L replace1,  L replace2,  L replace3,
        L replace4,  L replace5,  L replace6,  L replace7,
        L replace8,  L replace9,  L replace10, L replace11,
        L replace12, L replace13, L replace14, L replace15) const { __builtin_trap() /* STUB: not implemented */; }

    template<typename T>
    simdjson_inline simd8<uint8_t> apply_lookup_16_to(const simd8<T> original) { __builtin_trap() /* STUB: not implemented */; }
  };

  // Signed bytes
  template<>
  struct simd8<int8_t> {
    int8x16_t value;

    static simdjson_inline simd8<int8_t> splat(int8_t _value) { return vmovq_n_s8(_value); }
    static simdjson_inline simd8<int8_t> zero() { return vdupq_n_s8(0); }
    static simdjson_inline simd8<int8_t> load(const int8_t values[16]) { return vld1q_s8(values); }

    // Conversion from/to SIMD register
    simdjson_inline simd8(const int8x16_t _value) : value{_value} {}
    simdjson_inline operator const int8x16_t&() const { return this->value; }
    simdjson_inline operator int8x16_t&() { __builtin_trap() /* STUB: not implemented */; }

    // Zero constructor
    simdjson_inline simd8() : simd8(zero()) { __builtin_trap() /* STUB: not implemented */; }
    // Splat constructor
    simdjson_inline simd8(int8_t _value) : simd8(splat(_value)) { __builtin_trap() /* STUB: not implemented */; }
    // Array constructor
    simdjson_inline simd8(const int8_t* values) : simd8(load(values)) { __builtin_trap() /* STUB: not implemented */; }
    // Member-by-member initialization
#if SIMDJSON_REGULAR_VISUAL_STUDIO
    simdjson_inline simd8(
      int8_t v0,  int8_t v1,  int8_t v2,  int8_t v3, int8_t v4,  int8_t v5,  int8_t v6,  int8_t v7,
      int8_t v8,  int8_t v9,  int8_t v10, int8_t v11, int8_t v12, int8_t v13, int8_t v14, int8_t v15
    ) : simd8(simdjson_make_int8x16_t(
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15
    )) { __builtin_trap() /* STUB: not implemented */; }
#else
    simdjson_inline simd8(
      int8_t v0,  int8_t v1,  int8_t v2,  int8_t v3, int8_t v4,  int8_t v5,  int8_t v6,  int8_t v7,
      int8_t v8,  int8_t v9,  int8_t v10, int8_t v11, int8_t v12, int8_t v13, int8_t v14, int8_t v15
    ) : simd8(int8x16_t{
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15
    }) {}
#endif
    // Repeat 16 values as many times as necessary (usually for lookup tables)
    simdjson_inline static simd8<int8_t> repeat_16(
      int8_t v0,  int8_t v1,  int8_t v2,  int8_t v3,  int8_t v4,  int8_t v5,  int8_t v6,  int8_t v7,
      int8_t v8,  int8_t v9,  int8_t v10, int8_t v11, int8_t v12, int8_t v13, int8_t v14, int8_t v15
    ) { __builtin_trap() /* STUB: not implemented */; }

    // Store to array
    simdjson_inline void store(int8_t dst[16]) const { __builtin_trap() /* STUB: not implemented */; }

    // Explicit conversion to/from unsigned
    //
    // Under Visual Studio/ARM64 uint8x16_t and int8x16_t are apparently the same type.
    // In theory, we could check this occurrence with std::same_as and std::enabled_if but it is C++14
    // and relatively ugly and hard to read.
#ifndef SIMDJSON_REGULAR_VISUAL_STUDIO
    simdjson_inline explicit simd8(const uint8x16_t other): simd8(vreinterpretq_s8_u8(other)) { __builtin_trap() /* STUB: not implemented */; }
#endif
    simdjson_inline explicit operator simd8<uint8_t>() const { __builtin_trap() /* STUB: not implemented */; }

    // Math
    simdjson_inline simd8<int8_t> operator+(const simd8<int8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<int8_t> operator-(const simd8<int8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<int8_t>& operator+=(const simd8<int8_t> other) { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<int8_t>& operator-=(const simd8<int8_t> other) { __builtin_trap() /* STUB: not implemented */; }

    // Order-sensitive comparisons
    simdjson_inline simd8<int8_t> max_val(const simd8<int8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<int8_t> min_val(const simd8<int8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<bool> operator>(const simd8<int8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<bool> operator<(const simd8<int8_t> other) const { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8<bool> operator==(const simd8<int8_t> other) const { __builtin_trap() /* STUB: not implemented */; }

    template<int N=1>
    simdjson_inline simd8<int8_t> prev(const simd8<int8_t> prev_chunk) const { __builtin_trap() /* STUB: not implemented */; }

    // Perform a lookup assuming no value is larger than 16
    template<typename L>
    simdjson_inline simd8<L> lookup_16(simd8<L> lookup_table) const { __builtin_trap() /* STUB: not implemented */; }
    template<typename L>
    simdjson_inline simd8<L> lookup_16(
        L replace0,  L replace1,  L replace2,  L replace3,
        L replace4,  L replace5,  L replace6,  L replace7,
        L replace8,  L replace9,  L replace10, L replace11,
        L replace12, L replace13, L replace14, L replace15) const { __builtin_trap() /* STUB: not implemented */; }

    template<typename T>
    simdjson_inline simd8<int8_t> apply_lookup_16_to(const simd8<T> original) { __builtin_trap() /* STUB: not implemented */; }
  };

  template<typename T>
  struct simd8x64 {
    static constexpr int NUM_CHUNKS = 64 / sizeof(simd8<T>);
    static_assert(NUM_CHUNKS == 4, "ARM kernel should use four registers per 64-byte block.");
    const simd8<T> chunks[NUM_CHUNKS];
    template<int idx> simd8<uint8_t> get() const { __builtin_trap() /* STUB: not implemented */; }

    simd8x64(const simd8x64<T>& o) = delete; // no copy allowed
    simd8x64<T>& operator=(const simd8<T>& other) = delete; // no assignment allowed
    simd8x64() = delete; // no default constructor allowed

    simdjson_inline simd8x64(const simd8<T> chunk0, const simd8<T> chunk1, const simd8<T> chunk2, const simd8<T> chunk3) : chunks{chunk0, chunk1, chunk2, chunk3} { __builtin_trap() /* STUB: not implemented */; }
    simdjson_inline simd8x64(const T ptr[64]) : chunks{simd8<T>::load(ptr), simd8<T>::load(ptr+16), simd8<T>::load(ptr+32), simd8<T>::load(ptr+48)} { __builtin_trap() /* STUB: not implemented */; }

    simdjson_inline void store(T ptr[64]) const { __builtin_trap() /* STUB: not implemented */; }

    simdjson_inline simd8<T> reduce_or() const { __builtin_trap() /* STUB: not implemented */; }


    simdjson_inline uint64_t compress(uint64_t mask, T * output) const { __builtin_trap() /* STUB: not implemented */; }

    simdjson_inline uint64_t to_bitmask() const { __builtin_trap() /* STUB: not implemented */; }

    simdjson_inline uint64_t eq(const T m) const { __builtin_trap() /* STUB: not implemented */; }

    simdjson_inline uint64_t lteq(const T m) const { __builtin_trap() /* STUB: not implemented */; }
  }; // struct simd8x64<T>

} // namespace simd
} // unnamed namespace
} // namespace arm64
} // namespace simdjson

#endif // SIMDJSON_ARM64_SIMD_H
