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
    
    Queue<int> test(50);
    
    for (int i = 0; i < 10; i++){
        test.enqueue(i);
    }
    test.print();
    
    GraphAlgorithms algos;
    T1->setTable(fileData);

    algos.setGraph(T1);

    algos.findShortestPath("IAD", "MIA");
    
    //T1.printTable();
    Graph T2(T1);
    T2.unDirect(fileData);
    //T2.printTable();
    
    
    return 0;
}