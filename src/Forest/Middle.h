#pragma once
#include "NonBottom.h"
#include "NonTop.h"
namespace Forest {
    template <class T>
    class Middle : public NonTop<T>, public NonBottom<T> {
    public:
        Middle(NonBottom<T>* up, NonTop<T>* left, NonTop<T>* right) : NonTop<T>(up), NonBottom<T>(left, right) {}
        void update() override {
            NonBottom<T>::update();
            this->up->update();
        }
        template <class Base>
        long long getOffsetToBase() {
            return reinterpret_cast<long long>(static_cast<Base*>(this)) - reinterpret_cast<long long>(this);
        }
    };
}