//
// Created by rroig on 4/18/2024.
//

#include "MiniHash.h"
#include <iostream>


MiniHash::MiniHash(int H_Capacity){
    capacity = H_Capacity;
    for(int i = 0; i < capacity; i++)
    {
        table[i] = nullptr;
    }

}

bool MiniHash::insert(const string &Key, AirportNode *Value){
    int totalASCII = 0;
    for(char i : Key)
    {
        totalASCII += i;
    }

    int HashIndex = totalASCII % capacity;
    if(table[HashIndex] == nullptr) {
        table[HashIndex] = new MiniHashNode(Key, Value);
        return true;
    }

    while(true)
    {
        if(table[HashIndex] == nullptr) {
            table[HashIndex] = new MiniHashNode(Key, Value);
            return true;
        }
        else
        {
            if(table[HashIndex]->Key == Key) {
                return false;
            }
            HashIndex = (HashIndex + 1) % capacity;
        }
    }

}

AirportNode *MiniHash::search(string Key){
    int totalASCII = 0;
    for(char i : Key)
    {
        totalASCII += i;
    }
    int HashIndex = totalASCII % capacity;

    while(true) {
        if (table[HashIndex]->Key == Key) {
            return table[HashIndex]->Data;
        }
        HashIndex = (HashIndex + 1) % capacity;
    }
}
