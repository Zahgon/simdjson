#ifndef SIMDJSON_GENERIC_ONDEMAND_ARRAY_ITERATOR_INL_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_GENERIC_ONDEMAND_ARRAY_ITERATOR_INL_H
#include "simdjson/generic/ondemand/base.h"
#include "simdjson/generic/ondemand/array_iterator.h"
#include "simdjson/generic/ondemand/value-inl.h"
#include "simdjson/generic/ondemand/value_iterator-inl.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

simdjson_inline array_iterator::array_iterator(const value_iterator &_iter) noexcept
  : iter{_iter}
{}

simdjson_inline simdjson_result<value> array_iterator::operator*() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool array_iterator::operator==(const array_iterator &other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool array_iterator::operator!=(const array_iterator &) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline array_iterator &array_iterator::operator++() noexcept { __builtin_trap() /* STUB: not implemented */; }

simdjson_inline bool array_iterator::at_end() const noexcept { __builtin_trap() /* STUB: not implemented */; }
} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

namespace simdjson {

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator>::simdjson_result(
  SIMDJSON_IMPLEMENTATION::ondemand::array_iterator &&value
) noexcept
  : SIMDJSON_IMPLEMENTATION::implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator>(std::forward<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator>(value))
{ __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator>::simdjson_result(error_code error) noexcept
  : SIMDJSON_IMPLEMENTATION::implementation_simdjson_result_base<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator>({}, error)
{
}

simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::value> simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator>::operator*() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator>::operator==(const simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator> &other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator>::operator!=(const simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator> &other) const noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator> &simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator>::operator++() noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_inline bool simdjson_result<SIMDJSON_IMPLEMENTATION::ondemand::array_iterator>::at_end() const noexcept { __builtin_trap() /* STUB: not implemented */; }
} // namespace simdjson

#endif // SIMDJSON_GENERIC_ONDEMAND_ARRAY_ITERATOR_INL_H