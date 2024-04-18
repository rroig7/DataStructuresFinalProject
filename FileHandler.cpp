//
// Created by rroig on 4/17/2024.
//

#include "FileHandler.h"
#include <utility>
#include <limits>
#include <algorithm>

FileHandler::FileHandler(std::string path) : filePath(std::move(path)) {}

const std::string &FileHandler::getFilePath() const {
    return filePath;
}

void FileHandler::setFilePath(const std::string &path) {
    FileHandler::filePath = path;
}

// Returns a vector of vectors containing each row in the csv.
std::vector<std::vector<std::string>> FileHandler::getRowsAsVector() {
    std::ifstream inputFile(filePath);
    std::string currentLine;
    
    std::vector<std::vector<std::string>> to_return;
    
    // Skips first line of the input file.
    inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Shows an error if the file does not open properly.
    if(!inputFile.is_open()){
        std::cout << "Error opening file: " + filePath << std::endl;
    }
    // Iterate through each line of the file and save it to the currentLine variable.
    while(std::getline(inputFile, currentLine)){
        std::vector<std::string> currentLineVector;
        // Strips the " character from the string.
        currentLine.erase(std::remove(currentLine.begin(), currentLine.end(), '\"'), currentLine.end());
        
        std::string to_insert;
        
        // Using "," as a delimiter for each row. This will be different from the input file but overall is easier to code.
        for (auto x : currentLine){
            if (x == ','){
                currentLineVector.push_back(to_insert);
                to_insert.clear();
                continue;
            }
            to_insert.push_back(x);
        }
        to_return.push_back(currentLineVector);
    }
    
    inputFile.close();
    
    return to_return;
    
}

FileHandler::FileHandler() = default;
