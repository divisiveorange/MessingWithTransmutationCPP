#pragma once
#include "Middle.h"
#include "NormalTop.h"
#include "../GeneralLib/PaddingForTrans.h"
namespace Forest {
    template <class Type>
    class TransNormalTopHolder;
    template <class T>
    class TransNormalTop : protected NormalTop<T>, PaddingForTrans<NormalTop<T>, Middle<T>> {
    private:
        friend class TransNormalTopHolder<T>;
        friend class Top<T>;
        NonTop<T>* toNonTop(NormalTop<T>* newTop) override {
            checkValid<NonBottom<T>, std::remove_reference_t<decltype(*this)>,Middle<T>>(this);
            return new(this->derivedThis()) Middle<T>(newTop, this->getLeft(), this->getRight());
        }
        NormalTop<T>* top() {
            return this;
        }
        TransNormalTop(NonTop<T>* left, NonTop<T>* right) : NormalTop<T>(left, right) {
        }
    public:
        NonBottom<T>& operator*() {
            return *this;
        }
        NonBottom<T>* operator->() {
            return this;
        }
        template <class Base>
        long long getOffsetToBase() {
            return reinterpret_cast<long long>(static_cast<Base*>(this)) - reinterpret_cast<long long>(this);
        }
        TransNormalTop<T>* derivedThis() override {
            assert(this == static_cast<Node<T>*>(this));
            return this;
        }
    };
}
