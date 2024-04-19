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
    vector< vector<string> > fileData = infile.getFileVector();
    
    MiniHash T1(166);
    
    T1.setTable(fileData);
    T1.printTable();
    
    return 0;
}