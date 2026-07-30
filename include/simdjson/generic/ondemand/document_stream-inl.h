#ifndef SIMDJSON_GENERIC_ONDEMAND_DOCUMENT_STREAM_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_DOCUMENT_STREAM_INL_H
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/document_stream.h"
#include "simdjson/generic/ondemand/document-inl.h"
#include "simdjson/generic/implementation_simdjson_result_base-inl.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <algorithm>
#include <stdexcept>

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

#ifdef SIMDJSON_THREADS_ENABLED

inline void stage1_worker::finish() { __builtin_trap() /* STUB: not implemented */; }

inline stage1_worker::~stage1_worker() { __builtin_trap() /* STUB: not implemented */; }

inline void stage1_worker::start_thread() { __builtin_trap() /* STUB: not implemented */; }


inline void stage1_worker::stop_thread() { __builtin_trap() /* STUB: not implemented */; }

inline void stage1_worker::run(document_stream * ds, parser * stage1, size_t next_batch_start) { __builtin_trap() /* STUB: not implemented */; }

#endif  // SIMDJSON_THREADS_ENABLED

simdjson_inline document_stream::document_stream(
  ondemand::parser &_parser,
  const uint8_t *_buf,
  size_t _len,
  size_t _batch_size,
  bool _allow_comma_separated,
  stream_format _format
) noexcept
  : parser{&_parser},
    buf{_buf},
    len{_len},
    batch_size{_batch_size <= MINIMAL_BATCH_SIZE ? MINIMAL_BATCH_SIZE : _batch_size},
    allow_comma_separated{_allow_comma_separated},
    format{_format},
    error{SUCCESS}
    #ifdef SIMDJSON_THREADS_ENABLED
    , use_thread(_parser.threaded) // we need to make a copy because _parser.threaded can change
    #endif
{
#ifdef SIMDJSON_THREADS_ENABLED
  if(worker.get() == nullptr) {
    error = MEMALLOC;
  }
#endif
}

simdjson_inline document_stream::document_stream() noexcept
  : parser{nullptr},
    buf{nullptr},
    len{0},
    batch_size{0},
    allow_comma_separated{false},
    format{stream_format::whitespace_delimited},
    error{UNINITIALIZED}
    #ifdef SIMDJSON_THREADS_ENABLED
    , use_thread(false)
    #endif
{
}

simdjson_inline document_stream::~document_stream() noexcept
{ __builtin_trap() /* STUB: not implemented */; }

inline size_t document_stream::size_in_bytes() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline size_t document_stream::truncated_bytes() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline document_stream::iterator::iterator() noexcept
  : stream{nullptr}, finished{true} {
}

simdjson_inline document_stream::iterator::iterator(document_stream* _stream, bool is_end) noexcept
  : stream{_stream}, finished{is_end} {
}

simdjson_inline simdjson_result<ondemand::document_reference> document_stream::iterator::operator*() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline document_stream::iterator& document_stream::iterator::operator++() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool document_stream::iterator::at_end() const noexcept { __builtin_trap() /* STUB: not implemented */; }


simdjson_inline bool document_stream::iterator::operator!=(const document_stream::iterator &other) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool document_stream::iterator::operator==(const document_stream::iterator &other) const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline document_stream::iterator document_stream::begin() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline document_stream::iterator document_stream::end() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void document_stream::start() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void document_stream::next() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void document_stream::next_document() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline size_t document_stream::next_batch_start() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline error_code document_stream::run_stage1(ondemand::parser &p, size_t _batch_start) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline size_t document_stream::iterator::current_index() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline std::string_view document_stream::iterator::source() const noexcept { __builtin_trap() /* STUB: not implemented */; }

inline error_code document_stream::iterator::error() const noexcept { __builtin_trap() /* STUB: not implemented */; }

#ifdef SIMDJSON_THREADS_ENABLED

inline void document_stream::load_from_stage1_thread() noexcept { __builtin_trap() /* STUB: not implemented */; }

inline void document_stream::start_stage1_thread() noexcept { __builtin_trap() /* STUB: not implemented */; }

#endif // SIMDJSON_THREADS_ENABLED

} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_stream>::simdjson_result(
  error_code error
) noexcept :
    implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::document_stream>(error)
{ __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::document_stream>::simdjson_result(
  SIMDJSON_IMPLEMENTATION::ondemand::document_stream &&value
) noexcept :
    implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::document_stream>(
      std::forward<SIMDJSON_IMPLEMENTATION::ondemand::document_stream>(value)
    )
{ __builtin_trap() /* STUB: not implemented */; }

}

#endif // SIMDJSON_GENERIC_ONDEMAND_DOCUMENT_STREAM_INL_H
