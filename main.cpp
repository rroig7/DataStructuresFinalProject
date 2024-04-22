//
// Created by rroig on 4/17/2024.
//

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
    T1->unDirect();
    T1->printTable();
    T1->PrimAlg();

    //algos.findShortestPath("IAD", "MIA");
    //algos.SearchAlg("MSP", "MIA", 2);
    
    //T1.printTable();
    //Graph T2(T1);
    //T2.unDirect(fileData);
    //T2.printTable();
    //unDirectedGraph T2(T1);
    //T2.printEdges();
    //T2.PrimAlg();
    //algos.visitState("IAD", "NY");
    //algos.Total_Connections();
    //T1->printTable();
    //algos.DFS_nAway("IAD", "MIA", 10);
    //T2.PrimAlg();

    return 0;
}