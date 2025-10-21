#pragma once
#include "../GeneralLib/PaddingForTrans.h"
#include "FullWithNext.h"
#include "FullAlone.h"
namespace ArenaStack {
    template <class T>
    class TransFullAlone;
    template <class T>
    class TransFullWithNext : protected FullWithNext<T>,
    protected PaddingForTrans<FullWithNext<T>, FullWithNext<T>, FullAlone<T>> {
        friend class TransFullAlone<T>;
    public:
        TransFullWithNext(T* data, std::unique_ptr<FullArena<T>>&& next) : FullWithNext<T>(data, std::move(next)) {}
        void transmuteRemoveNext() override {
            checkValid<FullArena<T>, std::remove_reference_t<decltype(*this)>, TransFullAlone<T>>(this);
            this->next.release();
            new(this) TransFullAlone<T>(this->data);
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
