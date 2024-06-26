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

    vector<Edge*> GetChildren(AirportNode* Node);
public:
    Graph *getGraph() const;

    void setGraph(Graph *graph);

public:
    void findShortestPath(const string &startingNode, const string &destinationNode );

public:
    GraphAlgorithms();
    
    GraphAlgorithms(Graph graph);

    explicit GraphAlgorithms(Graph *graph);

    void SearchAlg(string Start, string Target, int distance);

    void visitState(string Start, string State);

    void Total_Connections();

    int minSpanningTree_Kruskal();
    
    int minSpanningTree_Prim();

    vector< Tuple<string, Tuple<int, int>> > DFS(string Start, string Target, int N);

    void DFS_nAway(string Start, string Target, int N);

};


#endif //DATASTRUCTURESFINALPROJECT_GRAPHALGORITHMS_H
