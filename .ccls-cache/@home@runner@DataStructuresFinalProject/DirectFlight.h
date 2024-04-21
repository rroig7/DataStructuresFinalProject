//
// Created by danie on 4/17/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_DIRECTFLIGHT_H
#define DATASTRUCTURESFINALPROJECT_DIRECTFLIGHT_H
#include <string>
class AirportNode;

class DirectFlight {
public:
    AirportNode* Port;
    int D_Weight;
    int C_Weight;

    DirectFlight(AirportNode* Airport, int Distance, int Cost)
    {
        Port = Airport;
        D_Weight = Distance;
        C_Weight = Cost;
    }
};



#endif //DATASTRUCTURESFINALPROJECT_DIRECTFLIGHT_H
