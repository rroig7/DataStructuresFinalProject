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

Tuple<string, int> GraphAlgorithms::SearchAlg(string Start, string Target) {
    vector< Tuple<string, Tuple<int, int>> > Paths;
    bool hasFound;
    string path;
    Queue<int> nodesInNextLevel;
    Queue<AirportNode*> queue;
    Queue<Tuple<int, int>> Weights;
    int curDistance;
    Tuple<int, int> totals(0, 0);
    AirportNode* cur = graph->search(Start);

    queue.enqueue(cur);
    Weights.enqueue(totals);


    while(!queue.empty()) {
        cur = queue.front();
        path += cur->name + "->";
        totals.setVal1(totals.getVal1() + Weights.front().getVal1());
        totals.setVal2(totals.getVal2() + Weights.front().getVal2());


        if(cur->name == Target){
            hasFound = true;
        }

        //If the Airport travels to other Airports, set the distance and change the path
        if(cur->Edges.size())
        {
            if(nodesInNextLevel.empty()){
                curDistance = cur->Edges.size();
            }
            else
            {
                nodesInNextLevel.enqueue(curDistance);
                curDistance = cur->Edges.size();
                path += path += cur->name + "->";
            }
        }

        // Enqueueing current node's edges in order of the least distance weight if we haven't found node
        Edge* children[cur->Edges.size()];
        if(!hasFound) {

            //Fill Children Array
            int i = 0;
            for (auto j: cur->Edges) {
                children[i] = j;
                i++;
            }

            //Order Array By Least Distance
            for(int j = 1; j < cur->Edges.size(); j++) {
                for (i = 0; i < cur->Edges.size() - j; i++) {
                    if (children[i]->getDWeight() > children[i + 1]->getDWeight()) {
                        Edge *temp = children[i];
                        children[i] = children[i + 1];
                        children[i + 1] = temp;
                    }
                }
            }

            //Enqueue Edge Nodes and Weights
            for(auto j : children)
            {
                queue.enqueue(graph->search(j->getPort()->name));
                Weights.enqueue(Tuple<int, int>(j->getDWeight(), j->getCWeight()));
            }
        }
        queue.dequeue();

        //traversed all the other ports, remove it form the path
        if(!curDistance) {
            curDistance = nodesInNextLevel.front() - 1;
            nodesInNextLevel.dequeue();
            path.erase(path.length()-5);
            Weights.dequeue();
            totals.setVal1(totals.getVal1() - Weights.front().getVal1());
            totals.setVal2(totals.getVal2() - Weights.front().getVal2());
        }

}








}
