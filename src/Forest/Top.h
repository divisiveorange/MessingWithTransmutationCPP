#pragma once
#include "Node.h"
#include "NormalTop.h"

namespace Forest {
    template <class T>
    class TransNormalTop;
    template <class T>
    class Top : virtual public Node<T> {
    public:
        Top<T>* const getHead() const override {
            return const_cast<Top<T>* const>(this);
        }
        NonBottom<T>* merge(Top<T>* otherTop, TransNormalTop<T>* constructionLocation) {
            NonTop<T>* nonTopOther = otherTop->toNonTop(constructionLocation->top());
            NonTop<T>* nonTopThis = this->toNonTop(constructionLocation);
            TransNormalTop<T>* newTop = new(constructionLocation) TransNormalTop<T>(nonTopThis, nonTopOther);
            return newTop->top();
        }
        std::optional<Top<T>*> isTop() const override {
            return {const_cast<Top<T>*>(this)};
        }
    protected:
        virtual NonTop<T>* toNonTop(NormalTop<T>* newTop) = 0;
    };
}
