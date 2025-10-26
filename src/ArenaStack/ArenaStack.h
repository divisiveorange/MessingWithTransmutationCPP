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
        T* pushRaw() {
            return getArena().pushRaw();
        }
        void pop() {
            getArena().pop();
        }
    private:
        TransIncreasableAlone<T> arenaStorage;
        IncreasableArena<T>& getArena() {
            return arenaStorage.getIncreasable();
        }
    };
}