//
// Created by rroig on 4/17/2024.
//

#include "AirportNode.h"

AirportNode::AirportNode(std::string Airport) { name = Airport; }

void AirportNode::Add_Edge( AirportNode* OtherNode, int Distance, int Cost)
{ Edges.push_back( new DirectFlight<AirportNode*>(&OtherNode, Distance, Cost ) ); }

