#pragma once
#include "Node.h"
#include "NonTop.h"
namespace Forest {
    template <class T>
    class Forest;
    template <class T>
    class NonBottom : virtual public Node<T> {
    protected:
        virtual NonTop<T>* getLeft() const {
            return left;
        }
        virtual NonTop<T>* getRight() const {
            return right;
        }
        virtual const T& getSumCache() const {
            return sumCache;
        }
        virtual void setLeft(NonTop<T>* left) {
            this->left = left;
        }
        virtual void setRight(NonTop<T>* right) {
            this->right = right;
        }
        virtual void setSumCache(const T& cache) {
            this->sumCache = cache;
        }
    private:
        friend class Forest<T>;
    private:
        NonTop<T> *left, *right;
        T sumCache;
    public:
        NonBottom(NonTop<T>* left, NonTop<T>* right) : left(left), right(right), sumCache(left->getSum() + right->getSum()) {
        }
        virtual void update() {
            setSumCache(getLeft()->getSum() + getRight()->getSum());
        }
        const T& getSum() const override {
            return getSumCache();
        }
    };
}
