#pragma once
#include "ArenaStack.h"
namespace ArenaStack {
    template<class... Ts>
    class MultiTypeArena {
        // Allowing storing mulitple types in multiple arenas but the same variable
    public:
        template<class T>
        void pop() {
            std::get<Stack<T>>(arenas).pop();
        }
        template<class T, class... Args>
        T* push(Args... args) {
            return std::get<Stack<T>>(arenas).push(std::forward<Args>(args)...);
        }
        template<class T>
        T* pushRaw() {
            return std::get<Stack<T>>(arenas).pushRaw();
        }
    private:
        std::tuple<Stack<Ts>...> arenas;
    };
}