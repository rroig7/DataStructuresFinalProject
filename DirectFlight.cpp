//
// Created by rroig on 4/19/2024.
//
#include "DirectFlight.h"

DirectFlight::DirectFlight(AirportNode *Airport, int Distance, int Cost){
Port = Airport;
D_Weight = Distance;
C_Weight = Cost;
}

AirportNode *DirectFlight::getPort() const {
    return Port;
}

void DirectFlight::setPort(AirportNode *port) {
    Port = port;
}

int DirectFlight::getDWeight() const {
    return D_Weight;
}

void DirectFlight::setDWeight(int dWeight) {
    D_Weight = dWeight;
}

int DirectFlight::getCWeight() const {
    return C_Weight;
}

void DirectFlight::setCWeight(int cWeight) {
    C_Weight = cWeight;
}