//
// Created by Alexander Garrity on 10/10/2025.
//

#ifndef TESTINGTRANSMUTATION_PADDINGFORTRANS_H
#define TESTINGTRANSMUTATION_PADDINGFORTRANS_H
#include <algorithm>
#include <alloca.h>
#include <type_traits>
#include <assert.h>

#endif //TESTINGTRANSMUTATION_PADDINGFORTRANS_Ho
template<class CurrentType, class... Convertables>
class PaddingForTrans {
public:

private:
    char padding[std::max(std::size_t{0},std::max({std::size_t{0}, sizeof(Convertables)...}) - sizeof(CurrentType))];
};
template<class Base, class From, class To>
    static void checkValid(From* local) {
    static_assert(std::is_base_of_v<Base, To>);
    static_assert((sizeof(From) >= sizeof(To)));
    static_assert((alignof(From) >= alignof(To)));
    To* temp = static_cast<To*>(alloca(sizeof(To)));
    assert(local->template getOffsetToBase<To>() == temp->template getOffsetToBase<To>());
}