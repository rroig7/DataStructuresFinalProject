//
// Created by rroig on 4/18/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_GRAPH_H
#define DATASTRUCTURESFINALPROJECT_GRAPH_H
#include "GraphNode.h"
#include "Tuple.cpp"

class Graph
{
private:
    int capacity;
public:
    int getCapacity() const;

    void setCapacity(int capacity);

    GraphNode *const *getTable() const;

private:
    GraphNode* table[166];

    vector<Edge*> Sort(vector<Edge*> List);
public:


    Graph(int H_Capacity);
    
    Graph(Graph* Other_Graph);
    
    bool insert(const string& Key, AirportNode* Value);

    AirportNode* search(string Key);
    
    void setTable(std::vector<std::vector<std::string>> csvRows);
    
    void printTable();
    
    void unDirect();

    vector<AirportNode*> search_by_state(string state);

    vector<AirportNode*> All_Inbound(string Target);

    vector<string> All_Keys();

    void PrimAlg();
    
};


#endif //DATASTRUCTURESFINALPROJECT_GRAPH_H
