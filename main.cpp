//
// Created by rroig on 4/17/2024.
//

#include "FileHandler.h"
#include "AirportNode.h"

int main(){
    
    FileHandler infile("../airports.csv");
    
    infile.getRowAsVector();
    
    return 0;
}