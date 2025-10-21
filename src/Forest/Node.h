#pragma once
namespace Forest {
    template <class T>
    class Bottom;
    template <class T>
    class NonBottom;
    template <class T>
    class NonTop;
    template <class T>
    class Top;
    template <class T>
    class Node {
    public:
        virtual Top<T>* getHead() = 0;
        virtual const T& getSum() = 0;
        virtual ~Node() {}
    };
}