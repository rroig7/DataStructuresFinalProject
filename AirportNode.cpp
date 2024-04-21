//
// Created by rroig on 4/17/2024.
//

#include "AirportNode.h"

AirportNode::AirportNode(std::string Airport, string Home_City, string Home_State) {
    name = Airport;
    city = Home_City;
    state = Home_State;
}

AirportNode::AirportNode(AirportNode *Other) {
    name = Other->name;
    Edges = vector<Edge*>(Other->Edges);
    Prev_Ports = vector<Edge*>(Other->Prev_Ports);
}

void AirportNode::Add_Port(AirportNode* OtherNode, int Distance, int Cost, bool direction){
    if(direction) { 
        Edges.push_back(new Edge(OtherNode, Distance, Cost) );
    }
    else{
        Prev_Ports.push_back(new Edge(OtherNode, Distance, Cost) );
    }
}


void AirportNode::Print_Edges() {
    for(int i = 0; i < Edges.size(); i++){
        cout<< Edges[i]->getPort()->name<<" ";
    }
}
void AirportNode::print_PrevPorts(){
    for(int i = 0; i < Prev_Ports.size(); i++){
        cout<< Prev_Ports[i]->getPort()->name<<" ";
    }
}

  