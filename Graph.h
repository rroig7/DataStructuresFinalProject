//
// Created by rroig on 4/18/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_GRAPH_H
#define DATASTRUCTURESFINALPROJECT_GRAPH_H
#include "AirportNode.h"

class Graph {
private:
    vector<AirportNode*> nodes;
public:
    const vector<AirportNode *> &getNodes() const;

    void setNodes(const vector<AirportNode *> &nodes);

public:
    Graph();
    void Add_Airport(AirportNode* Airport);
    
};


#endif //DATASTRUCTURESFINALPROJECT_GRAPH_H
