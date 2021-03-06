#pragma once
#include "TypePack.h"

#include "Type.h"
#include "TypePack.ops.h"

#include <type_traits> // std::conditional_t

namespace meta17 {

template<class T, class... Ts>
constexpr auto removeType(TypePack<Ts...>, Type<T> = {}) {
    return (std::conditional_t<type<T> == type<Ts>, TypePack<>, TypePack<Ts>>{} + ...);
}
template<class T, class TP>
using RemoveType = decltype(removeType<T>(TP{}));

template<class From, class To, class... Ts>
constexpr auto replaceType(TypePack<Ts...>, Type<From> = {}, Type<To> = {})
    -> TypePack<std::conditional_t<(type<From> == type<Ts>), To, Ts>...> {
    return {};
}
template<class F, class T, class TP>
using ReplaceType = decltype(replaceType<F, T>(TP{}));

} // namespace meta17
