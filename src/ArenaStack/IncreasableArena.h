#pragma once
#include <cassert>
#include <utility>
#include "Arena.h"
#include "TransFullAlone.h"

namespace ArenaStack {
    template <class T>
    class IncreasableArena : virtual public Arena<T> {
    protected:
        uint32_t currentPlace = 0;
        IncreasableArena(T* data, uint32_t currentPlace) : Arena<T>(data), currentPlace(currentPlace) {}
    public:
        IncreasableArena(const IncreasableArena& other) = default;
        IncreasableArena(IncreasableArena&& other) = default;
        IncreasableArena() = default;
        template<typename... Args>
        T* push(Args&&... args) {
            if (currentPlace < this->size) {
                auto returnable = new(&(this->data[currentPlace])) T(std::forward<Args>(args)...);
                currentPlace++;
                return returnable;
            } else if (currentPlace > this->size) {
                // Shouldn't be possible
                assert(false);
            } else {
                std::unique_ptr<FullArena<T>> next(&(new TransFullAlone<T>(this->data))->getFullArena());
                this->data = nullptr;
                this->transmuteAddNext(std::move(next));
                this->data = static_cast<T*>(malloc(sizeof(T)*this->size));
                this->currentPlace = 0;
                return this->push(std::forward<Args>(args)...);
            }
        }
        virtual void pop() = 0;
        virtual IncreasableArena& getIncreasable() = 0;
        auto& operator*() {
            return getIncreasable();
        }
        auto operator->() {
            return &getIncreasable();
        }
        ~IncreasableArena() override {
            for (auto i = int64_t{currentPlace} - 1; i >= 0; i--) {
                this->data[i].~T();
            }
        }
    };
}
