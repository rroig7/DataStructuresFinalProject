//
// Created by rroig on 4/17/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_AIRPLANENODE_H
#define DATASTRUCTURESFINALPROJECT_AIRPLANENODE_H

#include <vector>
#include "iostream"
#include "Edge.h"

class Edge;

using namespace std;
class AirportNode {
public:
    string name;
    string city;
    string state;
    vector<Edge*> Edges;
    vector<Edge*> Prev_Ports;

    explicit AirportNode(string Airport, string Home_City, string Home_State);
    AirportNode(AirportNode* Other);
    void Add_Port(AirportNode* OtherNode, int Distance, int Cost, bool direction);
    void Print_Edges();
    void print_PrevPorts();
    const std::string& getName() const;

};



#endif //DATASTRUCTURESFINALPROJECT_AIRPLANENODE_H
