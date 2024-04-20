//
// Created by rroig on 4/17/2024.
//

#include "FileHandler.h"
#include "AirportNode.h"
#include "DirectFlight.h"
#include "iostream"
#include "Graph.h"

using namespace std;


int main(){
    
    FileHandler infile("../airports.csv");
    vector< vector<string> > fileData = infile.getFileVector();
    
    Graph T1(166);

    T1.setTable(fileData);
    //T1.printTable();
    Graph T2(T1);
    T2.printTable();
    
    
    return 0;
}