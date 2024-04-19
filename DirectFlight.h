//
// Created by danie on 4/17/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_DIRECTFLIGHT_H
#define DATASTRUCTURESFINALPROJECT_DIRECTFLIGHT_H
#include <string>
class AirportNode;

class DirectFlight {
private:
    AirportNode* Port;
public:
    AirportNode *getPort() const;

    void setPort(AirportNode *port);

    int getDWeight() const;

    void setDWeight(int dWeight);

    int getCWeight() const;

    void setCWeight(int cWeight);

private:
    int D_Weight;
    int C_Weight;
    
public:
    DirectFlight(AirportNode* Airport, int Distance, int Cost);

};



#endif //DATASTRUCTURESFINALPROJECT_DIRECTFLIGHT_H
