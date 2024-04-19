//
// Created by rroig on 4/18/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_MINIHASHNODE_H
#define DATASTRUCTURESFINALPROJECT_MINIHASHNODE_H

#include <iostream>
#include <utility>
#include "AirportNode.h"

using namespace std;
class MiniHashNode
{
public:
    string Key;
    AirportNode* Data;

    MiniHashNode(string KEY,  AirportNode* DATA);
};



#endif //DATASTRUCTURESFINALPROJECT_MINIHASHNODE_H
