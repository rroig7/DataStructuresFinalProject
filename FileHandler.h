//
// Created by rroig on 4/17/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_FILEHANDLER_H
#define DATASTRUCTURESFINALPROJECT_FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <vector>


class FileHandler {
public:
    explicit FileHandler(std::string path);

    FileHandler();

    const std::string &getFilePath() const;

    void setFilePath(const std::string &path);
    
    std::vector<std::vector<std::string>> getRowsAsVector();

private:
    std::string filePath;
};


#endif //DATASTRUCTURESFINALPROJECT_FILEHANDLER_H
