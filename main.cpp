//
// Created by rroig on 4/17/2024.
//

#include "FileHandler.h"
#include "Graph.h"
#include <vector>


int main(){
    
    FileHandler infile("../airports.csv");
    
    std::vector<std::vector<std::string>> fileData = infile.getRowsAsVector();
    
    return 0;
}