//
// Created by rroig on 4/17/2024.
//

#include "FileHandler.h"
#include "Graph.h"

int main(){
    
    FileHandler infile("../airports.csv");

    infile.getRowsAsVector();
    
    return 0;
}