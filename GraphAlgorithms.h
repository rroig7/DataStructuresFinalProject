//
// Created by rroig on 4/18/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_GRAPHALGORITHMS_H
#define DATASTRUCTURESFINALPROJECT_GRAPHALGORITHMS_H
#include "AirportNode.h"
#include "Graph.h"

class GraphAlgorithms{
private:
    Graph* graph;
public:
    Graph *getGraph() const;

    void setGraph(Graph *graph);

public:
    void findShortestPath(AirportNode *targetNode, AirportNode *destinationNode );

public:
    GraphAlgorithms();
    
};


#endif //DATASTRUCTURESFINALPROJECT_GRAPHALGORITHMS_H
