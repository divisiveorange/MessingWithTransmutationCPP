#pragma once
#include "Node.h"
#include "Top.h"
namespace Forest {
    template <class T>
    class NonBottom;
    template <class T>
    class NonTop : virtual public Node<T> {
    protected:
        NonBottom<T>* up;
    public:
        NonTop(NonBottom<T>* up) : up(up) {}
        Top<T>* const getHead() const override {
            return up->getHead();
        }
        std::optional<Top<T>*> isTop() const override {
            return {};
        }
    };
}
