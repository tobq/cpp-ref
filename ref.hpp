//
// Created by tobia on 21/02/2021.
//
#pragma once


/**
 * Properly propagates const-ness (even as a class field - unlike native refs)
 * 
 * `operator.()` not here yet, so using `operator->()` until then
 * @tparam referenced type
 */

template<class T>
class ref {
    T &r;

    inline auto ptr() const {
        return (T const *) std::addressof(r);
    }

    inline auto ptr() {
        return std::addressof(r);
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

/**
 * specialization to flatten refs to refs
 * @tparam T type of template parameter ref (ref<T>)
 */
template<class T>
struct ref<ref<T>> : ref<T> {
    constexpr ref(ref<T> r) : ref<T>(r) {} // NOLINT(google-explicit-constructor)
};
