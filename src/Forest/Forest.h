#pragma once
#include "../ArenaStack/ArenaMultiType.h"
#include "TransLonelyHolder.h"
#include "TransNormalTopHolder.h"
#include "DataNodeHandle.h"
namespace Forest {
    template <class T>
    class Forest {
    private:
        ArenaStack::MultiTypeArena<TransLonelyHolder<T>, TransNormalTopHolder<T>> arena;
    public:
        DataNodeHandle<T> createNode(const T& data) {
            return {(arena.template push<TransLonelyHolder<T>>(data))->getPtr()};
        }
        NodeHandle<T> merge(const NodeHandle<T>& handle1, const NodeHandle<T>& handle2) {
            if (handle1.getTop() == handle2.getTop()) return handle1.getTop();
            auto ptr = arena.template pushRaw<TransNormalTopHolder<T>>();
            auto head1 = handle1.getPtr()->getHead();
            auto head2 = handle2.getPtr()->getHead();
            auto returnable = NodeHandle<T>{head1->merge(head2, ptr)};
            NonBottom<T>* innerData = dynamic_cast<NonBottom<T>*>(const_cast<Node<T>*>(returnable.inner));
            return returnable;
        }
    };
}