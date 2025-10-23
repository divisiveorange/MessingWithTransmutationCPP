#pragma once
#include "Lonely.h"
#include "NormalBottom.h"
#include "../GeneralLib/PaddingForTrans.h"
namespace Forest {
    template <class Type>
    class TransLonelyHolder;
    template <class T>
    class TransLonely : protected Lonely<T>, PaddingForTrans<Lonely<T>, NormalBottom<T>> {
    private:
        friend class TransLonelyHolder<T>;
        NonTop<T>* toNonTop(NormalTop<T>* newTop) override {
            checkValid<Bottom<T>, TransLonely<T>,NormalBottom<T>>(this);
            return new(derivedThis()) NormalBottom<T>(this->getData(), newTop);
        }
        TransLonely(const T& data) : Lonely<T>(data) {}
    public:
        ~TransLonely() {

        }
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
        TransLonely<T>* derivedThis() override {
            assert(this == static_cast<Node<T>*>(this));
            return this;
        }
    };
}