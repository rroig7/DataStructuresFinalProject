//
// Created by rroig on 4/18/2024.
//

#include "MiniHashNode.h"


MiniHashNode::MiniHashNode(string KEY,  AirportNode* DATA)
{
Key = std::move(KEY);
Data = DATA;
}