#pragma once
#include "Arena.h"
namespace ArenaStack {
    template <class T>
    class ArenaAlone : virtual public Arena<T> {
    public:
        ArenaAlone() = default;
        ArenaAlone(const ArenaAlone& other) = default;
        ArenaAlone(ArenaAlone&& other) = default;
        void transmuteRemoveNext() override {

        }
    protected:
        ArenaAlone(T* data) : Arena<T>(data) {}
    };
}