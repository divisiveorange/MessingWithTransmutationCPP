#pragma once
#include <memory>
#include "Arena.h"

namespace ArenaStack {
    template <class T>
    class FullArena;
    template <class T>
    class ArenaWithNext : virtual public Arena<T> {
    public:
        ArenaWithNext(const ArenaWithNext& other) = default;
        ArenaWithNext(ArenaWithNext&& other) = default;
        void transmuteAddNext(std::unique_ptr<FullArena<T>>&& next) override {
            auto currentNext = std::move(this->next);
            this->next = std::move(next);
            this->next->transmuteAddNext(std::move(currentNext));
        }
    protected:
        std::unique_ptr<FullArena<T>> next;
        ArenaWithNext(T* data, std::unique_ptr<FullArena<T>>&& next) : Arena<T>(data), next(std::move(next)) {}
    };
}
