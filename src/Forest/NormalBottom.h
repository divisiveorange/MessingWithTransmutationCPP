#pragma once
#include "Bottom.h"
#include "NonTop.h"
namespace Forest {
    template <class T>
    class NormalBottom : public Bottom<T>, public NonTop<T> {
    public:
        void update(const T& newData) override {
            Bottom<T>::update(newData);
            this->up->update();
        }
    };
}