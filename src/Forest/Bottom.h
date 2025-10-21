#pragma once
#include "Node.h"
namespace Forest {
    template <class T>
    class Bottom : public Node<T> {
    protected:
        T data;
    public:
        const T& getSum() override {
            return data;
        }
        virtual void update(const T& newData) {
            data = newData;
        }
    };
}
