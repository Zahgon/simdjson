#ifndef SIMDJSON_GENERIC_ONDEMAND_ARRAY_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_ARRAY_INL_H
#include "simdjson/jsonpathutil.h"
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/array.h"
#include "simdjson/generic/ondemand/array_iterator-inl.h"
#include "simdjson/generic/ondemand/json_iterator.h"
#include "simdjson/generic/ondemand/value.h"
#include "simdjson/generic/ondemand/value_iterator-inl.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

//
// ### Live States
//
// While iterating or looking up values, depth >= iter->depth. at_start may vary. Error is
// always SUCCESS:
//
// - Start: This is the state when the array is first found and the iterator is just past the `{`.
//   In this state, at_start == true.
// - Next: After we hand a scalar value to the user, or an array/object which they then fully
//   iterate over, the iterator is at the `,` before the next value (or `]`). In this state,
//   depth == iter->depth, at_start == false, and error == SUCCESS.
// - Unfinished Business: When we hand an array/object to the user which they do not fully
//   iterate over, we need to finish that iteration by skipping child values until we reach the
//   Next state. In this state, depth > iter->depth, at_start == false, and error == SUCCESS.
//
// ## Error States
//
// In error states, we will yield exactly one more value before stopping. iter->depth == depth
// and at_start is always false. We decrement after yielding the error, moving to the Finished
// state.
//
// - Chained Error: When the array iterator is part of an error chain--for example, in
//   `for (auto tweet : doc["tweets"])`, where the tweet element may be missing or not be an
//   array--we yield that error in the loop, exactly once. In this state, error != SUCCESS and
//   iter->depth == depth, and at_start == false. We decrement depth when we yield the error.
// - Missing Comma Error: When the iterator ++ method discovers there is no comma between elements,
//   we flag that as an error and treat it exactly the same as a Chained Error. In this state,
//   error == TAPE_ERROR, iter->depth == depth, and at_start == false.
//
// ## Terminal State
//
// The terminal state has iter->depth < depth. at_start is always false.
//
// - Finished: When we have reached a `]` or have reported an error, we are finished. We signal this
//   by decrementing depth. In this state, iter->depth < depth, at_start == false, and
//   error == SUCCESS.
//

simdjson_inline array::array(const value_iterator &_iter) noexcept
  : iter{_iter}
{
}

simdjson_inline simdjson_result<array> array::start(value_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<array> array::start_root(value_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<array> array::started(value_iterator &iter) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<array_iterator> array::begin() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<array_iterator> array::end() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused simdjson_warn_unused simdjson_inline error_code array::consume() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<std::string_view> array::raw_json() noexcept { __builtin_trap() /* STUB: not implemented */; }

SIMDJSON_PUSH_DISABLE_WARNINGS
SIMDJSON_DISABLE_STRICT_OVERFLOW_WARNING
simdjson_inline simdjson_result<size_t> array::count_elements() & noexcept { __builtin_trap() /* STUB: not implemented */; }
SIMDJSON_POP_DISABLE_WARNINGS

simdjson_inline simdjson_result<bool> array::is_empty() & noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<bool> array::reset() & noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<value> array::at_pointer(std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }

inline simdjson_result<value> array::at_path(std::string_view json_path) noexcept { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Func>
  requires std::invocable<Func, value>
#else
template <typename Func>
#endif
inline error_code array::for_each_at_path_with_wildcard(std::string_view json_path, Func&& callback) noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<value> array::at(size_t index) noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array>::simdjson_result(
  SIMDJSON_IMPLEMENTATION::ondemand::array &&value
) noexcept
  : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::array>(
      std::forward<SIMDJSON_IMPLEMENTATION::ondemand::array>(value)
    )
{ __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array>::simdjson_result(
  error_code error
) noexcept
  : implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::array>(error)
{ __builtin_trap() /* STUB: not implemented */; }

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array>::begin() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array>::end() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline  simdjson_result<size_t> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array>::count_elements() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline  simdjson_result<bool> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array>::is_empty() & noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline  simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array>::at(size_t index) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline  simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array>::at_pointer(std::string_view json_pointer) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline  simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array>::at_path(std::string_view json_path) noexcept { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_SUPPORTS_CONCEPTS
template <typename Func>
  requires std::invocable<Func, SIMDJSON_IMPLEMENTATION::ondemand::value>
#else
template <typename Func>
#endif
simdjson_inline error_code simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array>::for_each_at_path_with_wildcard(std::string_view json_path, Func&& callback) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline  simdjson_result<std::string_view> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array>::raw_json() noexcept { __builtin_trap() /* STUB: not implemented */; }
} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_ARRAY_INL_H
