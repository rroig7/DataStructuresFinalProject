//
// Created by rroig on 4/18/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_MINIHASH_H
#define DATASTRUCTURESFINALPROJECT_MINIHASH_H
#include "MiniHashNode.h"

class MiniHash
{
private:
    int capacity;
public:
    int getCapacity() const;

    void setCapacity(int capacity);

    MiniHashNode *const *getTable() const;

private:
    MiniHashNode* table[166];
public:


    MiniHash(int H_Capacity);
    
    bool insert(const string& Key, AirportNode* Value);

    AirportNode* search(string Key);
    
    void setTable(std::vector<std::vector<std::string>> csvRows);
    
    void printTable();
    
};


#endif //DATASTRUCTURESFINALPROJECT_MINIHASH_H
