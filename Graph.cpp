//
// Created by rroig on 4/18/2024.
//

#include "Graph.h"
#include "AirportNode.h"
#include <iostream>


Graph::Graph(int H_Capacity){
    capacity = H_Capacity;
    for(int i = 0; i < capacity; i++)
    {
        table[i] = nullptr;
    }

}

Graph::Graph(Graph *Other_Graph) {
    
    capacity = Other_Graph->capacity;
    for(int i =0; i < capacity; i++)
    {
        table[i] = new GraphNode(Other_Graph->table[i]);
    }
}

bool Graph::insert(const string &Key, AirportNode *Value){
    int totalASCII = 0;
    for(char i : Key)
    {
        totalASCII += i;
    }

    int HashIndex = totalASCII % capacity;
    if(table[HashIndex] == nullptr) {
        table[HashIndex] = new GraphNode(Key, Value);
        return true;
    }

    while(true)
    {
        if(table[HashIndex] == nullptr) {
            table[HashIndex] = new GraphNode(Key, Value);
            return true;
        }
        else
        {
            if(table[HashIndex]->Key == Key) {
                return false;
            }
            HashIndex = (HashIndex + 1) % capacity;
        }
    }

}

AirportNode *Graph::search(string Key){
    int totalASCII = 0;
    for(char i : Key)
    {
        totalASCII += i;
    }
    int HashIndex = totalASCII % capacity;

    while(true) {
        if (table[HashIndex]->Key == Key) {
            return table[HashIndex]->Data;
        }
        HashIndex = (HashIndex + 1) % capacity;
    }
}

vector<AirportNode*> Graph::search_by_state(string state){

    vector<AirportNode*> return_vector;
    for(auto i : table)
    {
        if(i->Data->state == state){
            return_vector.push_back(i->Data);
        }
    }

    return return_vector;
}

void Graph::setTable(std::vector<std::vector<std::string>> csvRows) {
    for(int j = 0; j < 2; j++) {
        for (vector<string> i: csvRows) {
            auto *Node = new AirportNode(i[j], i[2], i[3]);
            bool completion = insert(i[j], Node);
            if (!completion) {
                free(Node);
            }
        }
    }

    for(vector<string> i : csvRows)
    {
        search(i[0])->Add_Port(search(i[1]), stoi(i[6]), stoi(i[7]), true);
    }

}

void Graph::printTable() {
    for(GraphNode* i : table)
    {
        cout<<"Airport:" << i->Key <<endl
        << "    Edges:";
        i->Data->Print_Edges();
        cout<<endl<<"    Prev_Ports:";
        i->Data->print_PrevPorts();
        cout<<endl;
    }
}

int Graph::getCapacity() const {
    return capacity;
}

void Graph::setCapacity(int capacity) {
    Graph::capacity = capacity;
}

GraphNode *const *Graph::getTable() const {
    return table;
}

void Graph::unDirect(std::vector<std::vector<std::string>> csvRows){
    for(vector<string> i : csvRows)
    {
        AirportNode* key = search(i[0]);
        int distance = stoi(i[6]);
        int cost = stoi(i[7]);
        
        search(i[1])->Add_Port(key, distance, cost, false);
    }
}

vector<AirportNode *> Graph::All_Inbound(string Target) {
    vector<AirportNode*> return_vector;

    //Iterates through the table's data
    for(auto i : table)
    {
        if(i->Data->name == Target) { continue; }

        //Iterates through a Airport's Edge vector to see if the target is within the vector
        for(auto j : i->Data->Edges)
        {
            if(j->getPort()->name == Target)
            {
                return_vector.push_back(i->Data);
            }
        }
    }

    return return_vector;
}

vector<string> Graph::All_Keys() {

    vector<string> keys;
    for(auto i : table)
    {
        keys.push_back(i->Key);
    }

    return keys;
}

AirportNode* Graph::getNode(const string& nodeName) {
    for (AirportNode* node : vertices) {
        if (node->getName() == nodeName) {
            return node;
        }
    }
    return nullptr; // Node not found
}

void Graph::addEdge(const string& origin, const string& destination, int distance, int cost) {
    //Adds a directed edge starting from the origin to the destination and includes
    //the distance and cost
    AirportNode* orgNode = getNode(origin);
    AirportNode* destNode = getNode(destination);
    if (orgNode && destNode) {
        orgNode->addEdge(destNode, distance, cost);
    }
}

void Graph::addVertex(const string& vertexName) {
    //Adds a vertex to the graph if it doesn't already exist
    if (!contains(vertexName)) {
        AirportNode* newNode = new AirportNode(vertexName);
        vertices.push_back(newNode);
    }
}



