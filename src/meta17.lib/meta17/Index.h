#pragma once
#include "Const.h"

#include <cstddef> // size_t

namespace meta17 {

/// Index is a specialized Const
template<size_t I>
using Index = Const<I>;

template<size_t I>
constexpr auto index = Index<I>{};

} // namespace meta17
