#pragma once
#include "../ArenaStack/ArenaMultiType.h"
#include "TransLonely.h"
#include "TransNormalTop.h"
#include "DataNodeHandle.h"
namespace Forest {
    template <class T>
    class Forest {
    private:
        ArenaStack::MultiTypeArena<TransLonely<T>, TransNormalTop<T>> arena;
    public:
        DataNodeHandle<T> createNode(const T& data) {
            return {(arena.template push<TransLonely<T>>(data))->operator->()};
        }
        NodeHandle<T> merge(const NodeHandle<T>& handle1, const NodeHandle<T>& handle2) {
            if (handle1.getTop() == handle2.getTop()) return handle1.getTop();
            auto ptr = arena.template pushRaw<TransNormalTop<T>>();
            return {handle1.getPtr()->getHead()->merge(handle2.getPtr()->getHead(), ptr)};
        }
    };
}