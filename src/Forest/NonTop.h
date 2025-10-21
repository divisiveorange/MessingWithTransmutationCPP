#pragma once
#include "Node.h"
namespace Forest {
    template <class T>
    class NonBottom;
    template <class T>
    class NonTop : Node<T> {
    protected:
        NonBottom<T>* up;
    public:
        Top* getHead() override {
            return up->getHead();
        }
    };
}
