//
// Created by rroig on 4/17/2024.
//


// Test commit 
#include "FileHandler.h"
#include "AirportNode.h"
#include "Edge.h"
#include "iostream"
#include "Graph.h"
#include "Queue.cpp"
#include "GraphAlgorithms.h"

using namespace std;


int main(){
    
    FileHandler infile("../airports.csv");
    vector< vector<string> > fileData = infile.getFileVector();
    
    Graph *T1 = new Graph(166);
    
    GraphAlgorithms algos;
    T1->setTable(fileData);

    algos.setGraph(T1);

    //algos.findShortestPath("IAD", "MIA");
    //algos.SearchAlg("MSP", "MIA", 2);
    
    //T1.printTable();
    Graph T2(T1);
    T2.unDirect(fileData);
    //T2.printTable();

    //algos.visitState("IAD", "NY");
    algos.Total_Connections();
    //T1->printTable();
    
    return 0;
}