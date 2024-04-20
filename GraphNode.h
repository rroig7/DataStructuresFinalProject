//
// Created by rroig on 4/18/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_GRAPHNODE_H
#define DATASTRUCTURESFINALPROJECT_GRAPHNODE_H

#include <iostream>
#include <utility>
#include "AirportNode.h"

using namespace std;
class GraphNode
{
public:
    string Key;
    AirportNode* Data;

    GraphNode(string KEY, AirportNode* DATA);
    GraphNode(GraphNode* Other);

};



#endif //DATASTRUCTURESFINALPROJECT_GRAPHNODE_H
