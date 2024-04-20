//
// Created by rroig on 4/18/2024.
//

#include "GraphAlgorithms.h"
#include "Queue.h"

GraphAlgorithms::GraphAlgorithms() {}

void GraphAlgorithms::findShortestPath(AirportNode *targetNode, AirportNode *destinationNode ) {
    Queue<AirportNode*> Ports(100);
    int distance;

    AirportNode *cur;
    Ports.enqueue(targetNode);

    while (cur != targetNode){
        cur = Ports.front();


    }



}

Graph *GraphAlgorithms::getGraph() const {
    return graph;
}

void GraphAlgorithms::setGraph(Graph *graph) {
    GraphAlgorithms::graph = graph;
}
