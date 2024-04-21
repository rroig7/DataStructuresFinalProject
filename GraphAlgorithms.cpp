//
// Created by rroig on 4/18/2024.
//

#include "GraphAlgorithms.h"
#include "Queue.cpp"
#include <algorithm>

GraphAlgorithms::GraphAlgorithms() {}

void GraphAlgorithms::findShortestPath(const string &startingNode, const string &destinationNode ) {
    Queue<AirportNode*> queue(100);
    vector<vector<string>> paths;
    vector<string> visited;
    int distance;
    string pathTaken;

    AirportNode *cur = graph->search(startingNode);
    queue.enqueue(cur);

    while (cur->name != destinationNode){
        cur = queue.front();
        visited.push_back(cur->name);
        pathTaken.append(cur->name + "->");
        
        for (auto x: cur->Edges){
            queue.enqueue(graph->search(x->getPort()->name));
        }
        queue.dequeue();
    }
    
    return;
}

Graph *GraphAlgorithms::getGraph() const {
    return graph;
}

void GraphAlgorithms::setGraph(Graph *graph) {
    GraphAlgorithms::graph = graph;
}

GraphAlgorithms::GraphAlgorithms(Graph *graph) : graph(graph) {
}

void GraphAlgorithms::SearchAlg(string Start, string Target, int distance) {

    vector< Tuple<string, Tuple<int, int>> > OptimalPath;
    Queue<AirportNode*> queue(100);
    int numPrev = 0;
    int numNext = 0;
    int totalDistance = 0;

    AirportNode* cur = graph->search(Start);
    queue.enqueue(cur);
    OptimalPath.push_back(Tuple<string, Tuple<int, int>> (cur->name + ": NULL", Tuple<int, int>(0, 0) ) );
    numPrev = cur->Edges.size();

    int i = 0;
    while(distance - totalDistance != 1)
    {
        //Grab and set the total cumlative cost at Cur
        int CurWeight, CurCost;
        for(auto k : OptimalPath)
        {
            if(cur->name == k.getVal1().substr(0, 3)){
                CurWeight = k.getVal2().getVal1();
                CurCost = k.getVal2().getVal2();
                break;
            }
        }

        //Get All Adjacent Nodes
        vector<Edge*> OtherChildren = GetChildren(cur);
        for(auto j : OtherChildren) {
            //Enqueue Edges and increment numNext
            queue.enqueue(j->getPort());
            numNext += j->getPort()->Edges.size();

            //Set a Tuple of Weights
            Tuple<int, int> Weights(j->getDWeight() + CurWeight, j->getCWeight() + CurCost);
            bool Collision = false;

            //Look for any colissions, if so, compare.
            //If the new onw is less optimal, do not replace it
            for(auto k : OptimalPath)
            {
                string condition = k.getVal1().substr(0, 3);
                if(j->getPort()->name == k.getVal1().substr(0, 3))
                {
                    Collision = true;
                    if(Weights.getVal1() < k.getVal2().getVal1()){
                        k.setVal1(j->getPort()->name + ": " + cur->name);
                        k.setVal2(Weights);
                        break;
                    }
                }
            }
            //If no collision, add to the vector of paths
            if(!Collision) {
                OptimalPath.push_back(Tuple<string, Tuple<int, int>>(j->getPort()->name + ": " + cur->name, Weights));
            }
            numPrev--;
        }
        queue.dequeue();
        cur = queue.front();
        //If Completed total numbeer of children nodes at a certain distance
        //Increment distance and restart counting
        if(!numPrev)
        {
            numPrev = numNext;
            numNext = 0;
            totalDistance++;
        }
    }

    Tuple<string, Tuple<int, int>> TargetTuple;
    vector<string> Path;

    for(auto i : OptimalPath)
    {
        string condition = i.getVal1().substr(0, 3);
        if(condition == Target)
        {
         TargetTuple = i;
         break;
        }
    }

    string Cur = TargetTuple.getVal1().substr(5);
    Path.push_back(Target);
    while(Cur != Start)
    {
        for(auto i : OptimalPath)
        {
            string condition = i.getVal1().substr(0, 3);
            if(Cur == condition)
            {
                Path.insert(Path.begin(), Cur);
                Cur = i.getVal1().substr(5);
                break;
            }
        }
    }
    Path.insert(Path.begin(), Start);

    cout<<"The shortest Path from " << Start << " to " << Target << " is: ";
    for(auto i : Path)
    {
        cout<<i<<"->";
    }
    cout<<". The distance is " << TargetTuple.getVal2().getVal1() << ". The cost is " << TargetTuple.getVal2().getVal2()<<endl;
}

vector<Edge*> GraphAlgorithms::GetChildren(AirportNode *Node) {
    Edge* children[Node->Edges.size()];
    //Fill Children Array
    int i = 0;
    for (auto j: Node->Edges) {
        children[i] = j;
        i++;
    }

    //Order Array By Least Distance
    for(int j = 1; j < Node->Edges.size(); j++) {
        for (i = 0; i < Node->Edges.size() - j; i++) {
            if (children[i]->getDWeight() > children[i + 1]->getDWeight()) {
                Edge *temp = children[i];
                children[i] = children[i + 1];
                children[i + 1] = temp;
            }
        }
    }
    vector<Edge*> ReturnVector;
    for(auto i : children)
    {
        ReturnVector.push_back(i);
    }
    return ReturnVector;
}
