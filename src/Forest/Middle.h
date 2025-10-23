#pragma once
#include "NonBottom.h"
#include "NonTop.h"
namespace Forest {
    template <class T>
    class Middle : public NonBottom<T>, public NonTop<T> {
        template <class Type>
        class TransNormalTop;
        friend class TransNormalTop<T>;
    protected:
    public:
        Middle(NonBottom<T>* up, NonTop<T>* left, NonTop<T>* right) : NonTop<T>(up), NonBottom<T>(left, right) {

        }
        void update() override {
            NonBottom<T>::update();
            this->getUp()->update();
        }
        template <class Base>
        long long getOffsetToBase() {
            return reinterpret_cast<long long>(static_cast<Base*>(this)) - reinterpret_cast<long long>(this);
        }
        NonTop<T>* toNonTop(NormalTop<T>* newTop) override {
            auto returnable = new(this) Middle(newTop, this->getLeft(), this->getRight());
            assert(this->getUp());
            return returnable;
        }
        Middle<T>* derivedThis() override {
            assert(this == static_cast<Node<T>*>(this));
            return this;
        }
    };
}