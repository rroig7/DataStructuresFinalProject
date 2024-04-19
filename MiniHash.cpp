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

void MiniHash::setTable(std::vector<std::vector<std::string>> csvRows) {
    for(int j = 0; j < 2; j++) {
        for (vector<string> i: csvRows) {
            auto *Node = new AirportNode(i[j]);
            bool completion = insert(i[j], Node);
            if (!completion) {
                free(Node);
            }
        }
    }

    for(vector<string> i : csvRows)
    {
        search(i[0])->Add_Edge(search(i[1]), stoi(i[6]), stoi(i[7]));
    }

}

void MiniHash::printTable() {
    for(MiniHashNode* i : table)
    {
        cout<<"Airport:" << i->Key << " Edges:";
        i->Data->Print_Edges();
        cout<<endl;
    }
}

int MiniHash::getCapacity() const {
    return capacity;
}

void MiniHash::setCapacity(int capacity) {
    MiniHash::capacity = capacity;
}

MiniHashNode *const *MiniHash::getTable() const {
    return table;
}
