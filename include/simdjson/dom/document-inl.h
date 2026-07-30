#ifndef SIMDJSON_DOCUMENT_INL_H
#define SIMDJSON_DOCUMENT_INL_H

// Inline implementations go in here.

#include "simdjson/dom/base.h"
#include "simdjson/dom/document.h"
#include "simdjson/dom/element-inl.h"
#include "simdjson/internal/tape_ref-inl.h"
#include "simdjson/internal/jsonformatutils.h"

#include <cstring>

namespace simdjson {
namespace dom {

//
// document inline implementation
//
inline element document::root() const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused
inline size_t document::capacity() const noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused
inline error_code document::allocate(size_t capacity) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline bool document::dump_raw_tape(std::ostream &os) const noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace dom
} // namespace simdjson

#endif // SIMDJSON_DOCUMENT_INL_H
