//
// Created by rroig on 4/17/2024.
//

#include "AirportNode.h"

AirportNode::AirportNode(std::string Airport) { 
    name = Airport;
}

void AirportNode::Add_Edge( AirportNode* OtherNode, int Distance, int Cost){
    Edges.push_back(new DirectFlight(OtherNode, Distance, Cost) );
}

void AirportNode::Print_Edges() {
    for(int i = 0; i < Edges.size(); i++){
        cout<< Edges[i]->Port->name<<" ";
    }
}
  