#pragma once
#include "Node.h"
namespace Forest {
    template <class T>
    class NonBottom;
    template <class T>
    class NonTop : virtual public Node<T> {
    protected:
        NonBottom<T>* up;
    public:
        NonTop(NonBottom<T>* up) : up(up) {}
        Top<T>* getHead() override {
            return up->getHead();
        }
    };
}
