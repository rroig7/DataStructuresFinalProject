//
// Created by rroig on 4/17/2024.
//

#include "FileHandler.h"
#include "AirportNode.h"
#include "DirectFlight.h"
#include "iostream"

using namespace std;
class MiniHashNode
{
public:
    string Key;
    AirportNode* Data;

    MiniHashNode(string KEY,  AirportNode* DATA)
    {
        Key = KEY;
        Data = DATA;
    }

};

class MiniHash
{
public:
    int capacity;
    MiniHashNode* table[166];

    MiniHash(int H_Capacity)
    {
        capacity = H_Capacity;
        for(int i = 0; i < capacity; i++)
        {
            table[i] = nullptr;
        }

    }

    bool insert(const string& Key, AirportNode* Value)
    {
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

    AirportNode* search(string Key)
    {
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
};

int main(){
    
    FileHandler infile("../airports.csv");
    vector< vector<string> > fileData = infile.getRowsAsVector();


    int UniqueTotal = 0;
    for(vector<string> i : fileData)
    {
        static string Prev_Port = " ";
        if(Prev_Port == i[0]) { continue; }
        UniqueTotal++;
        Prev_Port = i[0];
    }
    for(vector<string> i : fileData)
    {
        static vector<string> FoundAlready;
        string CurPort = i[1];
        bool NoFind = false;
        for(vector<string> j : fileData)
        {
            if(CurPort == j[0]) {
                NoFind = true; break;
            }
        }
        if(!NoFind)
        {
            for(string k : FoundAlready)
            {
                if(CurPort == k)
                {NoFind = true; break;}
            }
            if(!NoFind) {
                FoundAlready.push_back(CurPort);
                UniqueTotal++;
            }
        }

    }

    MiniHash T1(UniqueTotal);

    for(int j = 0; j < 2; j++) {
        for (vector<string> i: fileData) {
            AirportNode *Node = new AirportNode(i[j]);
            bool completion = T1.insert(i[j], Node);
            if (!completion) {
                free(Node);
            }
        }
    }

    for(vector<string> i : fileData)
    {
        T1.search(i[0])->Add_Edge(T1.search(i[1]), stoi(i[6]), stoi(i[7]));
    }

    for(MiniHashNode* i : T1.table)
    {
        cout<<"Airport:" << i->Key << " Edges:";
        i->Data->Print_Edges();
        cout<<endl;
    }


    return 0;
}