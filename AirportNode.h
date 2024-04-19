//
// Created by rroig on 4/17/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_AIRPLANENODE_H
#define DATASTRUCTURESFINALPROJECT_AIRPLANENODE_H

#include <vector>
#include "iostream"
#include "DirectFlight.h"
class DirectFlight;

using namespace std;
class AirportNode {
public:
    string name;
    vector<DirectFlight*> Edges;

    AirportNode(string Airport);
    void Add_Edge( AirportNode* OtherNode, int Distance, int Cost);
    void Print_Edges();


};



#endif //DATASTRUCTURESFINALPROJECT_AIRPLANENODE_H
