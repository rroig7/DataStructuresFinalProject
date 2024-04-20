//
// Created by rroig on 4/18/2024.
//

#include "GraphAlgorithms.h"
#include "Queue.h"

GraphAlgorithms::GraphAlgorithms() {}

void GraphAlgorithms::findShortestPath(AirportNode *targetNode, AirportNode *destinationNode ) {
    Queue<AirportNode*> queue;
    int distance;
    
    AirportNode *cur;
    queue.enqueue(targetNode);
    
    while (cur != targetNode){
        cur = queue.front();
        
        
    }
    
    
    
}

Graph *GraphAlgorithms::getGraph() const {
    return graph;
}

void GraphAlgorithms::setGraph(Graph *graph) {
    GraphAlgorithms::graph = graph;
}
