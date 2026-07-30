#ifndef SIMDJSON_SRC_GENERIC_STAGE2_TAPE_WRITER_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE2_TAPE_WRITER_H
#include <generic/stage2/base.h>
#include <simdjson/internal/tape_type.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <cstring>

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace stage2 {

struct tape_writer {
  /** The next place to write to tape */
  uint64_t *next_tape_loc;

  /** Write a signed 64-bit value to tape. */
  simdjson_inline void append_s64(int64_t value) noexcept;

  /** Write an unsigned 64-bit value to tape. */
  simdjson_inline void append_u64(uint64_t value) noexcept;

  /** Write a double value to tape. */
  simdjson_inline void append_double(double value) noexcept;

  /** Write a big integer (as string) to tape. src points to first digit, len is byte count. */
  simdjson_inline void append_bigint(const uint8_t *src, size_t len, uint8_t *&string_buf) noexcept;

  /**
   * Append a tape entry (an 8-bit type,and 56 bits worth of value).
   */
  simdjson_inline void append(uint64_t val, internal::tape_type t) noexcept;

  /**
   * Skip the current tape entry without writing.
   *
   * Used to skip the start of the container, since we'll come back later to fill it in when the
   * container ends.
   */
  simdjson_inline void skip() noexcept;

  /**
   * Skip the number of tape entries necessary to write a large u64 or i64.
   */
  simdjson_inline void skip_large_integer() noexcept;

  /**
   * Skip the number of tape entries necessary to write a double.
   */
  simdjson_inline void skip_double() noexcept;

  /**
   * Write a value to a known location on tape.
   *
   * Used to go back and write out the start of a container after the container ends.
   */
  simdjson_inline static void write(uint64_t &tape_loc, uint64_t val, internal::tape_type t) noexcept;

private:
  /**
   * Append both the tape entry, and a supplementary value following it. Used for types that need
   * all 64 bits, such as double and uint64_t.
   */
  template<typename T>
  simdjson_inline void append2(uint64_t val, T val2, internal::tape_type t) noexcept;
}; // struct tape_writer

simdjson_inline void tape_writer::append_s64(int64_t value) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void tape_writer::append_u64(uint64_t value) noexcept { __builtin_trap() /* STUB: not implemented */; }

/** Write a double value to tape. */
simdjson_inline void tape_writer::append_double(double value) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void tape_writer::skip() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void tape_writer::skip_large_integer() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void tape_writer::skip_double() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void tape_writer::append(uint64_t val, internal::tape_type t) noexcept { __builtin_trap() /* STUB: not implemented */; }

template<typename T>
simdjson_inline void tape_writer::append2(uint64_t val, T val2, internal::tape_type t) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void tape_writer::write(uint64_t &tape_loc, uint64_t val, internal::tape_type t) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline void tape_writer::append_bigint(const uint8_t *src, size_t len, uint8_t *&string_buf) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace stage2
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SRC_GENERIC_STAGE2_TAPE_WRITER_H