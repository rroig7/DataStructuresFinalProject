//
// Created by rroig on 4/19/2024.
//
#include "Edge.h"

Edge::Edge(AirportNode *Airport, int Distance, int Cost){
Port = Airport;
D_Weight = Distance;
C_Weight = Cost;
}

AirportNode *Edge::getPort() const {
    return Port;
}

void Edge::setPort(AirportNode *port) {
    Port = port;
}

int Edge::getDWeight() const {
    return D_Weight;
}

void Edge::setDWeight(int dWeight) {
    D_Weight = dWeight;
}

int Edge::getCWeight() const {
    return C_Weight;
}

void Edge::setCWeight(int cWeight) {
    C_Weight = cWeight;
}