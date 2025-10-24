#pragma once
#include <optional>
namespace Forest {
    template <class T>
    class Bottom;
    template <class T>
    class NonBottom;
    template <class T>
    class NonTop;
    template <class T>
    class NormalTop;
    template <class T>
    class Top;
    template <class T>
    class Node {
    public:
        virtual Top<T>* const getHead() const = 0;
        virtual NonTop<T>* toNonTop(NormalTop<T>* newTop) = 0;
        virtual const T& getSum() const = 0;
        virtual ~Node() {}
        virtual std::optional<Top<T>*> isTop() const = 0;
        virtual Node<T>* derivedThis() = 0;
    };
}