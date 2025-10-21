#pragma once
#include "Node.h"
#include "NonTop.h"
namespace Forest {
    template <class T>
    class NonBottom : virtual public Node<T> {
    protected:
        NonTop<T> *left, *right;
        T sumCache;
    public:
        NonBottom(NonTop<T>* left, NonTop<T>* right) : left(left), right(right) {
            update();
        }
        virtual void update() {
            sumCache = left->getSum() + right->getSum();
        }
        const T& getSum() override {
            return sumCache;
        }
    };
}
