#pragma once
#include "NonBottom.h"
#include "Top.h"
namespace Forest {
    template <class T>
    class NormalTop : public NonBottom<T>, public Top<T> {
    public:
        NormalTop(NonTop<T>* left, NonTop<T>* right) : NonBottom<T>(left, right) {}
    };
}
