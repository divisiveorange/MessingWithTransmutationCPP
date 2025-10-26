#pragma once
#include "NodeHandle.h"
#include "Bottom.h"
#include "Forest.h"
namespace Forest {
    template <class T>
    class Forest;
    template <class T>
    class DataNodeHandle : public NodeHandle<T> {
    protected:
        friend class Forest<T>;
        const Bottom<T>* getPtr() const override {
            // Ideally, this class would instead directly store a Bottom* but that would require an abstract Node Handle class
            // and that seemed unnecessary for the task at hand
            return dynamic_cast<const Bottom<T>*>(NodeHandle<T>::getPtr());
        }
        DataNodeHandle(Bottom<T>* inner) : NodeHandle<T>(inner) {}
    public:
        const T& getValue() const {
            return this->getSum();
        }
    };
}