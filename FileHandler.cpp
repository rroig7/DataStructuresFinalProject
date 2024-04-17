//
// Created by rroig on 4/17/2024.
//

#include "FileHandler.h"
#include <utility>
#include <limits>

FileHandler::FileHandler(std::string path) : filePath(std::move(path)) {}

const std::string &FileHandler::getFilePath() const {
    return filePath;
}

void FileHandler::setFilePath(const std::string &path) {
    FileHandler::filePath = path;
}

std::vector<std::string> FileHandler::getRowAsVector() {
    std::ifstream inputFile(filePath);
    std::string dummy;
    inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    
    if(!inputFile.is_open()){
        std::cout << "Error opening file: " + filePath << std::endl;
        exit(1);
    }
    while(std::getline(inputFile, dummy)){
        std::cout << dummy << std::endl; 
    }
    
    inputFile.close();
    
    return {};
    
}

FileHandler::FileHandler() = default;
