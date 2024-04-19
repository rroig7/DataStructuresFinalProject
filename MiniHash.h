//
// Created by rroig on 4/18/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_MINIHASH_H
#define DATASTRUCTURESFINALPROJECT_MINIHASH_H
#include "MiniHashNode.h"

class MiniHash
{
public:
    int capacity;
    MiniHashNode* table[166];

    MiniHash(int H_Capacity);
    
    bool insert(const string& Key, AirportNode* Value);

    AirportNode* search(string Key);
};


#endif //DATASTRUCTURESFINALPROJECT_MINIHASH_H
