#pragma once
#include "IncreasableArena.h"
#include "ArenaAlone.h"
namespace ArenaStack {
    template <class T>
    class IncreasableAlone : public IncreasableArena<T>, public ArenaAlone<T> {
    public:
        IncreasableAlone() : Arena<T>(), IncreasableArena<T>(), ArenaAlone<T>() {}
        void pop() override {
            if (this->currentPlace > 0) {
                --this->currentPlace;
                this->data[this->currentPlace].~T();
            }
        }
    protected:
        IncreasableAlone(T* data, uint32_t currentPlace) : Arena<T>(data), ArenaAlone<T>(data), IncreasableArena<T>(data, currentPlace) {}
    };
}
