#pragma once
#include "FullArena.h"
#include "ArenaWithNext.h"
namespace ArenaStack {
    template <class T>
    class FullWithNext : public FullArena<T>, public ArenaWithNext<T> {
    protected:
        FullWithNext(T* data, std::unique_ptr<FullArena<T>>&& next) : Arena<T>(data), FullArena<T>(data), ArenaWithNext<T>(data, std::move(next)) {}
    };
}
