#pragma once
#include "Bottom.h"
#include "NonTop.h"
namespace Forest {
    template <class T>
    class TransLonely;
    template <class T>
    class NormalBottom : public Bottom<T>, public NonTop<T>  {
        friend class TransLonely<T>;
        friend class Forest<T>;
    protected:
    public:
        NormalBottom(const T& data, NonBottom<T>* up) : Bottom<T>(data), NonTop<T>(up) {
        }
        void update(const T& newData) override {
            Bottom<T>::update(newData);
            this->getUp()->update();
        }
        template <class Base>
        long long getOffsetToBase() {
            return reinterpret_cast<long long>(static_cast<Base*>(this)) - reinterpret_cast<long long>(this);
        }
        NonTop<T>* toNonTop(NormalTop<T>* newTop) override {
            return new(this) NormalBottom(this->getData(), newTop);
        }
        NormalBottom<T>* derivedThis() override {
            assert(this == static_cast<Node<T>*>(this));
            return this;
        }
    };
}