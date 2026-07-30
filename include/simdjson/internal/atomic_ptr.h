#ifndef SIMDJSON_INTERNAL_ATOMIC_PTR_H
#define SIMDJSON_INTERNAL_ATOMIC_PTR_H

#include "simdjson/base.h"
#include <atomic>

namespace simdjson {
namespace internal {

template<typename T>
class atomic_ptr {
public:
  atomic_ptr(T *_ptr) : ptr{_ptr} { __builtin_trap() /* STUB: not implemented */; }

  operator const T*() const { __builtin_trap() /* STUB: not implemented */; }
  const T& operator*() const { __builtin_trap() /* STUB: not implemented */; }
  const T* operator->() const { __builtin_trap() /* STUB: not implemented */; }

  operator T*() { __builtin_trap() /* STUB: not implemented */; }
  T& operator*() { __builtin_trap() /* STUB: not implemented */; }
  T* operator->() { __builtin_trap() /* STUB: not implemented */; }
  atomic_ptr& operator=(T *_ptr) { __builtin_trap() /* STUB: not implemented */; }

private:
  std::atomic<T*> ptr;
};

} // namespace internal
} // namespace simdjson

#endif // SIMDJSON_INTERNAL_ATOMIC_PTR_H
