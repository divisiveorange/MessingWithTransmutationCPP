#pragma once

namespace ArenaStack {
    template <class T>
    class FullAlone;
    template <class T>
    class FullArena;
    template <class T>
    class Arena {
        // An explanation of this class heirarchy is included in the readme
    protected:
        constexpr static std::size_t size = 4096*4;
        T* data;
        void swapData(Arena& other) {
            std::swap(data, other.data);
        }
    public:
        virtual void transmuteAddNext(std::unique_ptr<FullArena<T>>&& next) = 0;
        virtual void transmuteRemoveNext() = 0;
        Arena(T* data) : data(data) {}
        Arena() {
            // Malloc seems easiest to reason with because new[] does too much implicitly
            data = static_cast<T*>(malloc(sizeof(T)*size));
        }
        Arena(const Arena& other) {
            Arena();
            memcpy(other.data, data, sizeof(T)*size);
        }
        Arena(Arena&& other)  noexcept : data(other.data) {
            other.data = nullptr;
        }
        virtual ~Arena() {
            free(data);
        }
    };
}