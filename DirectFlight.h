//
// Created by danie on 4/17/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_DIRECTFLIGHT_H
#define DATASTRUCTURESFINALPROJECT_DIRECTFLIGHT_H
#include <string>

template<typename T>
class DirectFlight {
public:
    T* name;
    int D_Weight;
    int C_Weight;

    DirectFlight( T* Airport, int Distance, int Cost) {name = Airport; D_Weight = Distance; C_Weight = Cost;}
};


#endif //DATASTRUCTURESFINALPROJECT_DIRECTFLIGHT_H
