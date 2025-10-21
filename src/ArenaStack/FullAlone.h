#pragma once
#include "FullArena.h"
#include "ArenaAlone.h"
namespace ArenaStack {
    template <class T>
    class FullAlone : public FullArena<T>, public ArenaAlone<T> {
    protected:
        FullAlone(T* data) : Arena<T>(data), FullArena<T>(data), ArenaAlone<T>(data) {}
    };
}
