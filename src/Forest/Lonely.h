#pragma once
#include "Bottom.h"
#include "Top.h"
namespace Forest {
    template <class T>
    class Lonely : public Top<T>, public Bottom<T> {
    };
}