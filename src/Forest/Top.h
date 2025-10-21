#pragma once
#include "Node.h"
#include "NormalTop.h"

namespace Forest {
    template <class T>
    class TransNormalTop;
    template <class T>
    class Top : virtual public Node<T> {
    public:
        Top<T>* getHead() override {
            return this;
        }
        Top<T>* merge(Top<T>* otherTop, TransNormalTop<T>* constructionLocation) {
            NonTop<T>* nonTopOther = otherTop->toNonTop(constructionLocation->top());
            NonTop<T>* nonTopThis = this->toNonTop(constructionLocation);
            TransNormalTop<T>* newTop = new(constructionLocation) TransNormalTop<T>(nonTopThis, nonTopOther);
            return newTop->top();
        }
    protected:
        virtual NonTop<T>* toNonTop(NormalTop<T>* newTop) = 0;
    };
}
