#pragma once
#include "Node.h"
#include "Top.h"
namespace Forest {
    template <class T>
    class Forest;
    template <class T>
    class NodeHandle {
        friend class Forest<T>;
        const Node<T>* inner;
    protected:
        virtual const Node<T>* getPtr() const {
            return inner;
        }
        NodeHandle(const Node<T>* inner) : inner(inner) {}
    public:
        virtual bool operator==(const NodeHandle& other) const {
            return this->getPtr() == other.getPtr();
        }
        virtual NodeHandle getTop() const {
            return {getPtr()->getHead()};
        }
        virtual const T& getSum() const {
            return getPtr()->getSum();
        }
        virtual bool isTop() const {
            return this->getPtr()->isTop().has_value();
        }
    };
}