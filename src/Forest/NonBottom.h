#pragma once
#include "Node.h"
namespace Forest {
    template <class T>
    class NonBottom {
    protected:
        NonTop<T>* left, right;
        T sumCache;
    public:
        virtual void update() {
            sumCache = left->getSum() + right->getSum();
        }
        const T& getSum() override {
            return sumCache;
        }
    };
}
