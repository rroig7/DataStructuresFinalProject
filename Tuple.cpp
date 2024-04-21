//
// Created by rroig on 4/20/2024.
//

#include "Tuple.h"


template<typename T, typename V>
Tuple<T, V>::Tuple(T Val1, V Val2) {

    val1 = Val1;
    val2 = Val2;
}

template<typename T, typename V>
Tuple<T, V>::Tuple() {}


template<typename T, typename V>
T Tuple<T, V>::getVal1() const {
    return val1;
}

template<typename T, typename V>
void Tuple<T, V>::setVal1(T val1) {
    Tuple::val1 = val1;
}

template<typename T, typename V>
V Tuple<T, V>::getVal2() const {
    return val2;
}

template<typename T, typename V>
void Tuple<T, V>::setVal2(V val2) {
    Tuple::val2 = val2;
}

