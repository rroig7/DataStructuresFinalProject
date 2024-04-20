//
// Created by rroig on 4/18/2024.
//

#include "GraphAlgorithms.h"
#include "Queue.cpp"
#include <algorithm>

GraphAlgorithms::GraphAlgorithms() {}

void GraphAlgorithms::findShortestPath(const string &startingNode, const string &destinationNode ) {
    Queue<AirportNode*> queue(100);
    vector<vector<string>> paths;
    vector<string> visited;
    int distance;
    string pathTaken;

    AirportNode *cur = graph->search(startingNode);
    queue.enqueue(cur);

    while (cur->name != destinationNode){
        cur = queue.front();
        visited.push_back(cur->name);
        pathTaken.append(cur->name + "->");
        
        for (auto x: cur->Edges){
            queue.enqueue(graph->search(x->getPort()->name));
        }
        queue.dequeue();
    }
    
    return;
}

Graph *GraphAlgorithms::getGraph() const {
    return graph;
}

void GraphAlgorithms::setGraph(Graph *graph) {
    GraphAlgorithms::graph = graph;
}

GraphAlgorithms::GraphAlgorithms(Graph *graph) : graph(graph) {
}
