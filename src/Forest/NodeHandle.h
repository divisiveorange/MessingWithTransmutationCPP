#pragma once
#include "Node.h"
namespace Forest::NodeHandles {
    template <class T>
    class NodeHandle {
        friend class Forest;
        const Node<T>* inner;
    protected:
        virtual Node<T>* getPtr() const {
            return inner;
        }
        NodeHandle(Node<T>* inner) : inner(inner) {}
    public:
        virtual operator==(const NodeHandle& other) const {
            return this->getPtr() == other.getPtr();
        }
        virtual NodeHandle getTop() const {
            return {getPtr()->getHead()};
        }
        virtual const T& getSum() const {
            return getPtr()->getSum();
        }
    };
}