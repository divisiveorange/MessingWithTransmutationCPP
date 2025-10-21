#pragma once
#include "FullAlone.h"
#include "FullWithNext.h"
#include "PaddingForTrans.h"
#include "TransFullWithNext.h"

namespace ArenaStack {
    template <class T>
    class TransFullAlone : protected FullAlone<T>,
    protected PaddingForTrans<FullAlone<T>, FullWithNext<T>, FullAlone<T>> {
        friend class TransFullWithNext<T>;
    public:
        TransFullAlone(T* data) : FullAlone<T>(data) {}
        void transmuteAddNext(std::unique_ptr<FullArena<T>>&& next) override {
            checkValid<FullArena<T>, std::remove_reference_t<decltype(*this)>, TransFullWithNext<T>>(this);
            new(this) TransFullWithNext<T>(this->data, std::move(next));
        }
        FullArena<T>& getFullArena() override {
            return *this;
        }
        auto& operator*() {
            return FullArena<T>::operator*();
        }
        auto operator->() {
            return FullArena<T>::operator->();
        }
        template<class To>
        long long getOffsetToBase() {
            return reinterpret_cast<long long>(dynamic_cast<To*>(this)) - reinterpret_cast<long long>(this);
        }
    };
}
