namespace ArenaStack {
    template <class T>
    class Arena {
    protected:
        // I feel that child classes should be able to access the protected members of their parents through other objects
        friend class IncreasableArena;
        friend class FullArena;
        friend class ArenaWithNext;
        friend class ArenaAlone;
        friend class IncreasableWithNext;
        friend class IncreasableAlone;
        friend class FullWithNext;
        friend class FullAlone;
        friend class TransIncreasableWithNext;
        friend class TransIncreasableAlone;
        friend class TransFullWithNext;
        friend class TransFullAlone;
        constexpr static std::size_t size = 4096*4;
        T* data;
    public:
        virtual void transmuteAddNext(std::unique_ptr<FullArena>&& next) = 0;
        virtual void transmuteRemoveNext() = 0;
        Arena(T* data) : data(data) {}
    public:
        Arena() {
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