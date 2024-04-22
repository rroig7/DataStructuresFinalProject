//
// Created by rroig on 4/21/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_TRIPLETUPLE_H
#define DATASTRUCTURESFINALPROJECT_TRIPLETUPLE_H


/**
 * @class I had to make this class cause of one stupid bug.
 * */
template<typename T, typename V, typename S>
class TripleTuple {
public:

    TripleTuple();

    TripleTuple(T val1, V val2, S val3);

    T getVal1() const;

    void setVal1(T val1);

    V getVal2() const;

    void setVal2(V val2);

    S getVal3() const;

    void setVal3(S val3);

private:
    T val1;
    V val2;
    S val3;
    
};




#endif //DATASTRUCTURESFINALPROJECT_TRIPLETUPLE_H
