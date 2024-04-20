//
// Created by rroig on 4/18/2024.
//

#include "GraphAlgorithms.h"
#include "Queue.cpp"
#include <algorithm>

GraphAlgorithms::GraphAlgorithms() {}

void GraphAlgorithms::findShortestPath(const string &startingNode, const string &destinationNode, Graph* graph1) {
    Queue<AirportNode*> queue(100);
    vector<string> visited;
    int distance = 0;
    int numPrevLevel = 1;
    int numNextLevel = 0;
    bool hasFound = false;
    string pathTaken;

    AirportNode *cur = graph->search(startingNode);
    queue.enqueue(cur);

    while (numPrevLevel){
        if(cur->name == destinationNode) {
            hasFound = true;
        }

        //Character Comparisons Because == was not working for some reason
        bool THESAME = false;
        for(const auto& x : visited)
        {
            int sameChar = 0;
            int i = 0;
            for(char y : x)
            {
                if(y == cur->name[i]) {
                    sameChar++;
                }
                i++;
            }
            if(sameChar == x.length()) { THESAME = true; break;}
        }
        if(THESAME) {
            queue.dequeue();
            cur = queue.front();
            numPrevLevel--;
            continue;
        }

        pathTaken.append(cur->name + "->");
        numNextLevel += cur->Edges.size();

        if(!hasFound) {
            for (auto x: cur->Edges) {
                queue.enqueue(graph->search(x->getPort()->name));
            }
        }
        visited.push_back(cur->name);
        queue.dequeue();
        cur = queue.front();
        numPrevLevel--;
        if(!numPrevLevel && !hasFound){
            pathTaken += '|';
            numPrevLevel = numNextLevel;
            numNextLevel = 0;
            distance++;
        }
    }

    cout<<distance<<endl;
    cout<<pathTaken<<endl;
    vector<string> Result = searchNaway(startingNode, destinationNode, distance);

    if(!Result.empty())
    {
        int totalDistance = 0;
        int totalCost = 0;
        cout<<"The shortest route from " << startingNode << " to " << destinationNode << " is ";
        for(int i = 0; i < Result.size()-1; i++)
        {
            cout<<Result[Result.size() - i] << + "->";
            AirportNode* target = graph1->search(Result[i+1]);
            for(auto k : target->Edges)
            {
                    if(k->getPort()->name == Result[i])
                    {
                        totalDistance += k->getDWeight();
                        totalCost += k->getCWeight();
                        break;
                    }
            }
        }
        cout<<Result[0]<< ". The length is " << totalDistance << ". The cost is " << totalCost;

    }

}


Graph *GraphAlgorithms::getGraph() const {
    return graph;
}

void GraphAlgorithms::setGraph(Graph *graph) {
    GraphAlgorithms::graph = graph;
}

vector<string> GraphAlgorithms::searchNaway(const string& Start, const string& Target, int distance) {
    AirportNode* cur = graph->search(Start);
    static vector<vector<string>> ToReturn;
    static vector<vector<int>> TotalDistance(0);
    static vector<int> distanceVector;
    static int startDistance = distance;
    static bool hasFound = false;
    static vector<string> Finished;

    for(auto i : Finished)
    {
        if(i == Start) { return {}; }
    }

    if(distance)
    {
        for(auto i : cur->Edges)
        {
            vector<string> Returned = searchNaway(i->getPort()->name, Target, distance - 1);
            if(hasFound){
                for(auto k : cur->Edges)
                {
                    if(k->getPort()->name == Returned.back()) {
                        distanceVector.push_back(k->getDWeight());
                        break;
                    }
                }
            }
            if(startDistance == distance && hasFound){
                hasFound = false;
                Returned.push_back(Start);
                ToReturn.push_back(Returned);
                TotalDistance.push_back(distanceVector);
                distanceVector.clear();
            }
            else if(hasFound && distance == 1){
                Returned.push_back(Start);
                Finished.push_back(Start);
                return Returned;
            }
            else if(hasFound) {
                Returned.push_back(Start);
                return Returned;
            }
        }
        Finished.push_back(Start);
        if(distance != startDistance) { return {}; }
    }
    else
    {

        if (Start == Target)
        {
         hasFound = true;
            return {Start};
        }
        else{
            //Finished.push_back(Start);
            return {};
        }

    }

    if(ToReturn.empty()) {
        return {};
    }
    if(ToReturn.size() == 1) {
        return ToReturn[0];
    }
    else {

        int equalNodeDistances = 0;
        int totalCalls = 0;
        for (int i = 0; i < ToReturn.size() - 1; i++) {
            for (int j = i+1; j < ToReturn.size() - i; j++) {
                totalCalls++;
                if (ToReturn[i].size() == ToReturn[j].size()) {
                    equalNodeDistances++;
                }
            }
        }

        if(totalCalls != equalNodeDistances)
        {
            vector<string> smallestDistance = ToReturn[0];
            for (int i = 1; i < ToReturn.size() - 1; i++) {
                static int smallestDisIndex = 0;
                if(smallestDistance.size() > ToReturn[i].size())
                {
                    smallestDistance = ToReturn[i];
                    smallestDisIndex = i;
                }
                else if(smallestDistance.size() == ToReturn[i].size())
                {
                    int totalDistances[2] = {0};
                    int k = smallestDisIndex;

                    for(vector<int> x : TotalDistance)
                    {
                        for(int j : x)
                        {
                            totalDistances[k] += j;
                        }
                        k = i;
                    }

                    if(totalDistances[0] > totalDistances[1]){
                        smallestDistance = ToReturn[i];
                        smallestDisIndex = i;
                    }

                }
            }
        }
        else
        {
            int totalDistances[ToReturn.size()];
            for(auto i : totalDistances)
            {
                totalDistances[i] = 0;
            }

            int k = 0;
            for(vector<int> i : TotalDistance)
            {
                for(int j : i)
                {
                    totalDistances[k] += j;
                }
                k++;
            }

            int* smallestPointer;
            smallestPointer = min_element(totalDistances, totalDistances+ToReturn.size());

            for(int i = 0; i < ToReturn.size(); i++)
            {
                if(totalDistances[i] == *smallestPointer)
                {
                    return ToReturn[i];
                }
            }
        }
    }
}


