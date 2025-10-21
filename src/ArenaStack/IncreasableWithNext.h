#pragma once
#include "IncreasableArena.h"
#include "ArenaWithNext.h"
namespace ArenaStack {
    template <class T>
    class IncreasableWithNext : public IncreasableArena<T>, public ArenaWithNext<T> {
    public:
        IncreasableWithNext(std::unique_ptr<FullArena<T>>&& next) : ArenaWithNext<T>(next) {}
        void pop() override {
            if (this->currentPlace > 0) {
                --this->currentPlace;
                this->data[this->currentPlace].~T();
            }
            else {
                this->swapData(*this->next);
                this->currentPlace = this->size;
                this->transmuteRemoveNext();
            }
        }
    protected:
        IncreasableWithNext(T* data, uint32_t currentPlace, std::unique_ptr<FullArena<T>>&& next) : Arena<T>(data), IncreasableArena<T>(data, currentPlace), ArenaWithNext<T>(data, std::move(next)) {}
    };
}