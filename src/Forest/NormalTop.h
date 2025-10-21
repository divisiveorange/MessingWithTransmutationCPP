#pragma once
#include "NonBottom.h"
#include "Top.h"
namespace Forest {
    template <class T>
    class NormalTop : public Top<T>, public NonBottom<T> {
    public:
        NormalTop(NonTop<T>* left, NonTop<T>* right) : NonBottom<T>(left, right) {}
    };
}
