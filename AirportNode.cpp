//
// Created by rroig on 4/17/2024.
//

#include "AirportNode.h"

AirportNode::AirportNode(std::string Airport) { 
    name = Airport;
}

AirportNode::AirportNode(AirportNode *Other) {
    name = Other->name;
    Edges = vector<DirectFlight*>(Other->Edges);
    Prev_Ports = vector<DirectFlight*>(Other->Prev_Ports);
}

void AirportNode::Add_Port(AirportNode* OtherNode, int Distance, int Cost, bool direction){
    if(direction) { 
        Edges.push_back(new DirectFlight(OtherNode, Distance, Cost) );
    }
    else{
        Prev_Ports.push_back(new DirectFlight(OtherNode, Distance, Cost) );
    }
}


void AirportNode::Print_Edges() {
    for(int i = 0; i < Edges.size(); i++){
        cout<< Edges[i]->getPort()->name<<" ";
    }
}
  