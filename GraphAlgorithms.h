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

    void findShortestPath(const string &startingNode, const string &destinationNode, Graph* graph1 );

    GraphAlgorithms();
    
    GraphAlgorithms(Graph graph);

    vector<string> searchNaway(const string& Start, const string& Target, int distance);
};


#endif //DATASTRUCTURESFINALPROJECT_GRAPHALGORITHMS_H
