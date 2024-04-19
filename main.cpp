//
// Created by rroig on 4/17/2024.
//

#include "FileHandler.h"
#include "AirportNode.h"
#include "DirectFlight.h"
#include "iostream"
#include "MiniHash.h"

using namespace std;


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
            auto *Node = new AirportNode(i[j]);
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