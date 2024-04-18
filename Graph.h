//
// Created by rroig on 4/18/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_GRAPH_H
#define DATASTRUCTURESFINALPROJECT_GRAPH_H
#include "AirportNode.h"

class Graph {
    
    vector<AirportNode*> nodes;
    
    Graph();
    void Add_Airport(AirportNode* Airport);
    
};


#endif //DATASTRUCTURESFINALPROJECT_GRAPH_H
