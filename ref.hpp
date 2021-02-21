/**
 * `operator.()` not here yet, so using `operator->()` until then
 */
template<class T>
class ref {
    T &r;

    inline auto ptr() {
        return &r;
    }

    inline auto ptr() const {
        return (T const &) &r;
    }

public:
    ref(T &ref) : r(ref) {} // NOLINT(google-explicit-constructor)
    ref(T *const const_ptr) : r(*const_ptr) {} // NOLINT(google-explicit-constructor)
    ref() = delete;

    inline auto operator&() { // NOLINT(google-runtime-operator)
        return ptr();
    }

    inline auto operator&() const { // NOLINT(google-runtime-operator)
        return ptr();
    }

    inline auto &operator*() {
        return *ptr();
    }

    inline auto &operator*() const {
        return *ptr();
    }

    inline auto operator->() {
        return ptr();
    }

    inline auto operator->() const {
        return ptr();
    }
};
