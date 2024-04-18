//
// Created by rroig on 4/17/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_AIRPLANENODE_H
#define DATASTRUCTURESFINALPROJECT_AIRPLANENODE_H

#include <vector>
#include "DirectFlight.h"

using namespace std;
class AirportNode {
public:
    string name;
    vector<DirectFlight<AirportNode*>*> Edges;

    AirportNode(string Airport);
    void Add_Edge( AirportNode* OtherNode, int Distance, int Cost);


};


#endif //DATASTRUCTURESFINALPROJECT_AIRPLANENODE_H
