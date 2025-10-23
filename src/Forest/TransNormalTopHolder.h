#pragma once
#include "TransNormalTop.h"

namespace Forest {
    template<class T>
    class TransNormalTopHolder {
        long long offset;
        alignas(alignof(TransNormalTop<T>)) char storage[sizeof(TransNormalTop<T>)]{};
    public:
        TransNormalTopHolder(NonTop<T>* left, NonTop<T>* right) {
            auto ptr = new(storage) TransNormalTop<T>(left, right);
            offset = ptr->template getOffsetToBase<NonBottom<T>>();
            auto test = getPtr();
        }
        NonBottom<T>* getPtr() {
            return reinterpret_cast<NonBottom<T>*>(storage + offset);
        }

    };
}
