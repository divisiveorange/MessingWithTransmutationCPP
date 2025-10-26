#pragma once
#include "Node.h"
#include "Top.h"
#include "NonBottom.h"
namespace Forest {
    template <class T>
    class NonBottom;
    template <class T>
    class Forest;
    template <class T>
    class TransNormalTop;
    template <class T>
    class NonTop : virtual public Node<T> {
        NonBottom<T>* volatile up = nullptr;
    protected:
        friend class Top<T>;
        friend class Forest<T>;
        friend class TransNormalTop<T>;
        virtual void setUp(NonBottom<T>* up) {
            this->up = up;
        }
    public:
        NonTop(NonBottom<T>* up) : up(up) {}
        Top<T>* const getHead() const override {
            auto up = this->getUp();
            assert(up != nullptr);
            return up->getHead();
        }
        std::optional<Top<T>*> isTop() const override {
            return {};
        }
        virtual NonBottom<T> * getUp() const {
            assert(up != nullptr);
            return up;
        }
        NonTop<T>* toNonTop(NormalTop<T>* newTop) override = 0;
    };
}
