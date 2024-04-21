//
// Created by danie on 4/17/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_EDGE_H
#define DATASTRUCTURESFINALPROJECT_EDGE_H
#include <string>
class AirportNode;

class Edge {
private:
    AirportNode* Port;
public:
    AirportNode *getPort() const;

    void setPort(AirportNode *port);

    int getDWeight() const;

    void setDWeight(int dWeight);

    int getCWeight() const;

    void setCWeight(int cWeight);

private:
    int D_Weight;
    int C_Weight;
    
public:
    Edge(AirportNode* Airport, int Distance, int Cost);

};



#endif //DATASTRUCTURESFINALPROJECT_EDGE_H
