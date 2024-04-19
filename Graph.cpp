//
// Created by rroig on 4/18/2024.
//

#include "Graph.h"

Graph::Graph() {}

void Graph::Add_Airport(AirportNode *Airport) {

}

const vector<AirportNode *> &Graph::getNodes() const {
    return nodes;
}

void Graph::setNodes(const vector<AirportNode *> &nodes) {
    Graph::nodes = nodes;
}
