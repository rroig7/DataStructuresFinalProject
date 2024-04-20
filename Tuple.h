//
// Created by rroig on 4/20/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_TUPLE_H
#define DATASTRUCTURESFINALPROJECT_TUPLE_H

template<typename T, typename V>
class Tuple {
private:
    T val1;
    V val2;
public:
    T getVal1() const;

    void setVal1(T val1);

    V getVal2() const;

    void setVal2(V val2);

public:
    Tuple();
    
    Tuple(T val1, T val2);
    
    
    
};

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


#endif //DATASTRUCTURESFINALPROJECT_TUPLE_H
