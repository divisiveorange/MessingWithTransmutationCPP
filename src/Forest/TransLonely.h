#pragma once
#include "Lonely.h"
#include "NormalBottom.h"
#include "NormalTop.h"
#include "../GeneralLib/PaddingForTrans.h"
namespace Forest {
    template <class T>
    class TransLonely : protected Lonely<T>, PaddingForTrans<Lonely<T>, NormalBottom<T>> {
    private:
        NonTop<T>* toNonTop(NormalTop<T>* newTop) override {
            checkValid<Bottom<T>, TransLonely<T>,NormalBottom<T>>(this);
            new(this) NormalBottom<T>(this->data, newTop);
            return reinterpret_cast<NonTop<T> *>(this);
        }
    public:
        TransLonely(const T& data) : Lonely<T>(data) {}
        Bottom<T>& operator*() {
            return *this;
        }
        Bottom<T>* operator->() {
            return this;
        }
        template <class Base>
        long long getOffsetToBase() {
            return reinterpret_cast<long long>(static_cast<Base*>(this)) - reinterpret_cast<long long>(this);
        }
    };
}