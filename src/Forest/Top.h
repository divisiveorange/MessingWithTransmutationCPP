#pragma once
#include "Node.h"
#include "NormalTop.h"

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
        Top<T>* const getHead(void** up) const override {
            return const_cast<Top<T>* const>(this);
        }
        NonBottom<T>* merge(Top<T>* const otherTop, TransNormalTopHolder<T>* constructionLocation) {
            NonTop<T>* nonTopOther = otherTop->derivedThis()->toNonTop(nullptr);
            NonTop<T>* nonTopThis = this->derivedThis()->toNonTop(nullptr);
            NormalTop<T>* newTop = dynamic_cast<NormalTop<T>*>((new(constructionLocation)TransNormalTopHolder<T>(nonTopThis, nonTopOther))->getPtr());
            nonTopOther = nonTopOther->derivedThis()->toNonTop(newTop);
            nonTopThis = nonTopThis->derivedThis()->toNonTop(newTop);
            // long long offset = reinterpret_cast<char*>(nonTopThis) - reinterpret_cast<char volatile*>(&nonTopThis->up);
            // long long offsetOther = reinterpret_cast<char*>(nonTopOther) - reinterpret_cast<char volatile*>(&nonTopOther->up);
            // *reinterpret_cast<TransNormalTop<T>**>(reinterpret_cast<char*>(otherTop) + offsetOther) = newTop;
            // *reinterpret_cast<TransNormalTop<T>**>(reinterpret_cast<char*>(this) + offset) = newTop;
            // nonTopOther->up = newTop;
            // reinterpret_cast<NonTop<T>*>(this)->up = newTop;
            // reinterpret_cast<NonTop<T>*>(otherTop)->up = newTop;
            // nonTopThis->up = newTop;
            // assert(newTop == nonTopThis->getHead());
            // auto var = newTop->getHead();
            return newTop;
        }
        std::optional<Top<T>*> isTop() const override {
            return {const_cast<Top<T>*>(this)};
        }
    protected:
        NonTop<T>* toNonTop(NormalTop<T>* newTop) override = 0;
    };
}
