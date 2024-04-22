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
    const vector< vector<string> >& fileData = infile.getFileVector();
    
    auto *T1 = new Graph(166);
    
    GraphAlgorithms algos;
    GraphAlgorithms algosTwo;
    T1->setTable(fileData);
    
    //lol idk why this is here
    //    algos.SearchAlg("MSP", "MIA", 2);
    
    // Problem 1
    cout << "Problem 1" << endl;
    algos.setGraph(T1);
    
    // Problem 2
    cout << "Problem 2" << endl;
    algos.findShortestPath("IAD", "MIA");

    // Problem 3
    cout << "Problem 3" << endl;
    algos.visitState("IAD", "NY");



    // Problem 4
    cout << "Problem 4" << endl;


    // Problem 5
    cout << "Problem 5" << endl;
    algos.Total_Connections();


    // Undirected Graph
    // Problem 6
    cout << "Problem 6" << endl;
    Graph T2(T1);
    T2.unDirect(fileData);

    // Problem 7
    cout << "Problem 7" << endl;
    algosTwo.setGraph(&T2);
    algosTwo.minSpanningTree_Prim();
    
    // Problem 8 Done
    cout << "Problem 8" << endl;
    algosTwo.minSpanningTree_Kruskal();
    
    



    //T1->printTable();
    
    return 0;
}