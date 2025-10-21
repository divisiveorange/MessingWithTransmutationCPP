#pragma once
#include "Bottom.h"
#include "NonTop.h"
namespace Forest {
    template <class T>
    class NormalBottom : public Bottom<T>, public NonTop<T> {
    public:
        NormalBottom(const T& data, NonBottom<T>* up) : Bottom<T>(data), NonTop<T>(up) {}
        void update(const T& newData) override {
            Bottom<T>::update(newData);
            this->up->update();
        }
        template <class Base>
        long long getOffsetToBase() {
            return reinterpret_cast<long long>(static_cast<Base*>(this)) - reinterpret_cast<long long>(this);
        }
    };
}