#pragma once
#include "Arena.h"
namespace ArenaStack {
    template <class T>
    class FullArena : virtual public Arena<T> {
    public:
        virtual FullArena& getFullArena() = 0;
        FullArena(const FullArena& other) = default;
        FullArena(FullArena&& other) = default;
        ~FullArena() override {
            for (auto i = this->size - 1; i >= 0; i--) {
                this->data[i].~T();
            }
        }
        auto operator*() {
            return getFullArena();
        }
        auto operator->() {
            return &getFullArena();
        }
    protected:
        FullArena(T* data) : Arena<T>(data) {}
    };
}