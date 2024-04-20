//
// Created by rroig on 4/18/2024.
//

#include "GraphNode.h"



GraphNode::GraphNode(string KEY, AirportNode* DATA)
{
Key = std::move(KEY);
Data = DATA;
}

GraphNode::GraphNode(GraphNode *Other) {
    Key = Other->Key;
    Data = new AirportNode(Other->Data);
}