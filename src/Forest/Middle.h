#pragma once
#include "NonBottom.h"
#include "NonTop.h"
namespace Forest {
    template <class T>
    class Middle : public NonTop<T>, public NonBottom<T> {
    public:
        void update() override {
            NonBottom<T>::update();
            this->up->update();
        }
    };
}