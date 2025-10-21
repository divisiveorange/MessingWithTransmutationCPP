#pragma once
#include "Node.h"
namespace Forest {
    template <class T>
    class TransNormalTop;
    template <class T>
    class Top : Node<T> {
    public:
        Top* getHead() override {
            return *this;
        }
        Top* merge(Top<T>* otherTop, TransNormalTop<T>* constructionLocation) {
            TransNormalTop<T>* newTop = new(constructionLocation) TransNormalTop<T>(this, otherTop);
            otherTop->ToNonTop(newTop);
            this->ToNonTop(newTop);
            return newTop;
        }
    protected:
        virtual void ToNonTop(Top* newTop) = 0;
    };
}