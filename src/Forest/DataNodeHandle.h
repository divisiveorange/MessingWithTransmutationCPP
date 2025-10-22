#pragma once
#include "NodeHandle.h"
#include "Bottom.h"
namespace Forest::NodeHandles {
    template <class T>
    class DataNodeHandle : public NodeHandle<T> {
    protected:
        friend class Forest;
        Bottom<T>* getPtr() const override {
            return as<Bottom<T>*>(NodeHandle<T>::getPtr());
        }
        DataNodeHandle(Bottom<T>* inner) : NodeHandle<T>(inner) {}
    public:
        const T& getValue() const {
            return this->getSum();
        }
    };
}