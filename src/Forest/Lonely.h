#pragma once
#include "Bottom.h"
#include "Top.h"
namespace Forest {
    template <class T>
    class Lonely : public Bottom<T>, public Top<T> {
    public:
        Lonely(const T& data) : Bottom<T>(data) {}
    };
}