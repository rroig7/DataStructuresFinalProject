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
    T getVal1();

    void setVal1(T val1);

    V getVal2();

    void setVal2(V val2);

public:
    Tuple();
    
    Tuple(T Val1, V Val2);
    
    
    
};




#endif //DATASTRUCTURESFINALPROJECT_TUPLE_H
