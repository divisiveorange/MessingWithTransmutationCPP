#pragma once
#include "PaddingForTrans.h"
#include "IncreasableAlone.h"
#include "IncreasableWithNext.h"
#include "TransIncreasableWithNext.h"

namespace ArenaStack {
    template <class T>
    class TransIncreasableAlone : protected IncreasableAlone<T>,
    protected PaddingForTrans<IncreasableAlone<T>, IncreasableWithNext<T>, IncreasableAlone<T>> {
        friend class TransIncreasableNext;
    protected:
        void transmuteAddNext(std::unique_ptr<FullArena<T>>&& next) override {
            checkValid<IncreasableArena<T>, std::remove_reference_t<decltype(*this)>, TransIncreasableWithNext<T>>(this);
            new(this) TransIncreasableWithNext<T>(this->data, this->currentPlace, std::move(next));
        }
    public:
        TransIncreasableAlone() : IncreasableAlone<T>() {}
        TransIncreasableAlone(T* data, uint32_t currentPlace) : IncreasableAlone<T>(data, currentPlace) {}
        IncreasableArena<T>& getIncreasable() override {
            return *this;
        }
        auto& operator*() {
            return IncreasableArena<T>::operator*();
        }
        auto operator->() {
            return IncreasableArena<T>::operator->();
        }
        template<class To>
        long long getOffsetToBase() {
            return reinterpret_cast<long long>(dynamic_cast<To*>(this)) - reinterpret_cast<long long>(this);
        }
    };
}
