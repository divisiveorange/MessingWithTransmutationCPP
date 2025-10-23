#pragma once
#include <algorithm>
#include <alloca.h>
#include <type_traits>
#include <assert.h>

template<class CurrentType, class... Convertables>
class PaddingForTrans {
    char padding[std::max(std::size_t{0},std::max({std::size_t{0}, sizeof(Convertables)...}) - sizeof(CurrentType))];
};
template<class Base, class From, class To>
void checkValid(From* local) {
    static_assert(std::is_base_of_v<Base, To>);
    static_assert((sizeof(From) >= sizeof(To)));
    static_assert((alignof(From) >= alignof(To)));
    // To* temp = static_cast<To*>(alloca(sizeof(To)));
    assert(local->template getOffsetToBase<Base>() == static_cast<To*>(alloca(sizeof(To)))->template getOffsetToBase<Base>());
    // If this assertion fails, you can reorient your multiple inheritances. If you can't then transmutation between
    // these types isn't possible
}