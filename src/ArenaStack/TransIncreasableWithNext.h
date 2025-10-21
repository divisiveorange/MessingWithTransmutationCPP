#pragma once
#include "../GeneralLib/PaddingForTrans.h"
#include "IncreasableWithNext.h"
#include "IncreasableAlone.h"
namespace ArenaStack {
    template <class T>
    class TransIncreasableAlone;
    template <class T>
    class TransIncreasableWithNext : protected IncreasableWithNext<T>,
    protected PaddingForTrans<IncreasableWithNext<T>, IncreasableWithNext<T>, IncreasableAlone<T>> {
        friend class TransIncreasableAlone<T>;
    public:
        TransIncreasableWithNext(std::unique_ptr<FullArena<T>>&& next) : IncreasableWithNext<T>(next) {}
        TransIncreasableWithNext(T* data, uint32_t currentPlace, std::unique_ptr<FullArena<T>>&& next) : IncreasableWithNext<T>(data, currentPlace, std::move(next)) {}
    protected:
        void transmuteRemoveNext() override {
            checkValid<IncreasableArena<T>, std::remove_reference_t<decltype(*this)>, TransIncreasableAlone<T>>(this);
            this->next.release();
            new(this) TransIncreasableAlone<T>(this->data, this->currentPlace);
        }
    public:
        IncreasableArena<T>& getIncreasable() override {
            return *this;
        }
        template<class To>
        long long getOffsetToBase() {
            return reinterpret_cast<long long>(dynamic_cast<To*>(this)) - reinterpret_cast<long long>(this);
        }
    };
}
