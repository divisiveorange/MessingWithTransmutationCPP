#pragma once
#include "TransLonely.h"

namespace Forest {
    template<class T>
    class TransLonelyHolder {
        long long offset;
        alignas(alignof(TransLonely<T>)) char storage[sizeof(TransLonely<T>)]{};
    public:
        TransLonelyHolder(const T& data) {
            auto ptr = new(storage) TransLonely<T>(data);
            offset = ptr->template getOffsetToBase<Bottom<T>>();
            auto test = getPtr();
        }
        Bottom<T>* getPtr() {
            return reinterpret_cast<Bottom<T>*>(storage + offset);
        }

    };
}
