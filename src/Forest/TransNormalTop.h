#pragma once
#include "Middle.h"
#include "NormalTop.h"
#include "../GeneralLib/PaddingForTrans.h"
namespace Forest {
    template <class T>
    class TransNormalTop : protected NormalTop<T>, PaddingForTrans<NormalTop<T>, Middle<T>> {
    private:
        friend class Top<T>;
        NonTop<T>* toNonTop(NormalTop<T>* newTop) override {
            checkValid<NonBottom<T>, std::remove_reference_t<decltype(*this)>,Middle<T>>(this);
            new(this) Middle<T>(newTop, this->left, this->right);
            return reinterpret_cast<NonTop<T> *>(this);
        }
        NormalTop<T>* top() {
            return this;
        }
    public:
        TransNormalTop(NonTop<T>* left, NonTop<T>* right) : NormalTop<T>(left, right) {}
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
    };
}
