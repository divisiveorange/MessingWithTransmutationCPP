#pragma once
#include "ArenaStack.h"
namespace ArenaStack {
    template<class... Ts>
    class MultiTypeArena {
    public:
        template<class T>
        void pop() {
            std::get<Stack<T>>(arenas).pop();
        }
        template<class T, class... Args>
        T* push(Args... args) {
            return std::get<Stack<T>>(arenas).push(std::forward<Args>(args)...);
        }
    private:
        std::tuple<Stack<Ts>...> arenas;
    };
}