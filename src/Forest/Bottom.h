#pragma once
#include "Node.h"
namespace Forest {
    template <class T>
    class Bottom : virtual public Node<T> {
    protected:
        T data;
    public:
        Bottom(const T& data) : data(data) {}
        const T& getSum() const override {
            return data;
        }
        virtual void update(const T& newData) {
            data = newData;
        }
    };
}
