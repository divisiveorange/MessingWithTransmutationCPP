#pragma once
#include "TransIncreasableAlone.h"
namespace ArenaStack {
    template<class T>
    class Stack {
    public:
        template<typename... Args>
        T* push(Args&&... args) {
            return getArena().push(std::forward<Args>(args)...);
        }
        void pop() {
            getArena().pop();
        }
    private:
        TransIncreasableAlone arenaStorage;
        IncreasableArena& getArena() {
            return arenaStorage.getIncreasable();
        }
    };
}