#pragma once
#include "Node.h"
#include "NormalTop.h"
#include "TransNormalTopHolder.h"

namespace Forest {
    template <class T>
    class TransNormalTopHolder;
    template <class T>
    class Top : virtual public Node<T> {
        static void checkValid( NonTop<T>* nonTopOther, NonTop<T>* nonTopThis) {
            assert(nonTopOther->up);
            assert(nonTopThis->up);
        }
    public:
        Top<T>* const getHead() const override {
            return const_cast<Top<T>* const>(this);
        }
        NonBottom<T>* merge(Top<T>* const otherTop, TransNormalTopHolder<T>* constructionLocation) {
            NonTop<T>* nonTopOther = otherTop->derivedThis()->toNonTop(nullptr);
            NonTop<T>* nonTopThis = this->derivedThis()->toNonTop(nullptr);
            NormalTop<T>* newTop = dynamic_cast<NormalTop<T>*>((new(constructionLocation)TransNormalTopHolder<T>(nonTopThis, nonTopOther))->getPtr());
            nonTopOther->derivedThis()->toNonTop(newTop);
            nonTopThis->derivedThis()->toNonTop(newTop);
            return newTop;
        }
        std::optional<Top<T>*> isTop() const override {
            return {const_cast<Top<T>*>(this)};
        }
    protected:
        NonTop<T>* toNonTop(NormalTop<T>* newTop) override = 0;
    };
}
