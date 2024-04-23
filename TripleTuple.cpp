//
// Created by rroig on 4/21/2024.
//

#include "TripleTuple.h"


template<typename T, typename V, typename S>
TripleTuple<T, V, S>::TripleTuple(T val1, V val2, S val3):val1(val1), val2(val2), val3(val3) {}

template<typename T, typename V, typename S>
TripleTuple<T, V, S>::TripleTuple()= default;

template<typename T, typename V, typename S>
T TripleTuple<T, V, S>::getVal1() const {
    return val1;
}

template<typename T, typename V, typename S>
void TripleTuple<T, V, S>::setVal1(T val1) {
    TripleTuple::val1 = val1;
}

template<typename T, typename V, typename S>
V TripleTuple<T, V, S>::getVal2() const {
    return val2;
}

template<typename T, typename V, typename S>
void TripleTuple<T, V, S>::setVal2(V val2) {
    TripleTuple::val2 = val2;
}

template<typename T, typename V, typename S>
S TripleTuple<T, V, S>::getVal3() const {
    return val3;
}

template<typename T, typename V, typename S>
void TripleTuple<T, V, S>::setVal3(S val3) {
    TripleTuple::val3 = val3;
}