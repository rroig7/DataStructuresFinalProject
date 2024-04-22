//
// Created by rroig on 4/18/2024.
//

#include "GraphAlgorithms.h"
#include "Queue.cpp"
#include <algorithm>
#include "TripleTuple.cpp"

GraphAlgorithms::GraphAlgorithms() {}


void GraphAlgorithms::findShortestPath(const string &startingNode, const string &destinationNode ) {
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

        //If the same then dequeue current front and replace cur
        if(THESAME) {
            queue.dequeue();
            cur = queue.front();
            numPrevLevel--;
            continue;
        }

        //Add our current node to the BFS path and increment number of nodes in the next distance
        pathTaken.append(cur->name + "->");
        numNextLevel += cur->Edges.size();

        //If We found the node, stop enqueeing more nodes
        if(!hasFound) {
            for (auto x: cur->Edges) {
                queue.enqueue(graph->search(x->getPort()->name));
            }
        }
        //Add Current node to visited list and replace current node with front of queue
        visited.push_back(cur->name);
        queue.dequeue();
        if(!queue.empty()) {
            cur = queue.front();
        }
        numPrevLevel--;
        //if exchaused all nodes on a currentl level, replace numlevel with nextlevel and increase the distance
        //from the start
        if(!numPrevLevel && !hasFound){
            //pathTaken += '|';
            numPrevLevel = numNextLevel;
            numNextLevel = 0;
            distance++;
        }
    }

    //cout<<distance<<endl;
   // cout<<pathTaken<<endl;

    vector<string> Ports;
    int pos = 0;
    while(pos < pathTaken.size())
    {
        pos = pathTaken.find("->");
        Ports.push_back(pathTaken.substr(0, pos));
        pathTaken.erase(0, pos+2);

    }

    bool CanReach = false;
    for(auto i : Ports)
    {
        if(destinationNode == i)
        {
            CanReach = true;
            break;
        }
    }

    if(!CanReach)
    {
        cout<<"Cannot reach " << destinationNode << " from " << startingNode<<endl;
    }
    else
    {
        SearchAlg(startingNode, destinationNode, distance);
    }


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
    while(distance != totalDistance)
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

    //Find the Tuple that has the Target
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

    //Trace the path starting from the target and ending at the start node
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

    //Print and celebrate
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

void GraphAlgorithms::visitState(string Start, string State) {
    vector<AirportNode*> All_Ports = graph->search_by_state(State);

    for(auto i : All_Ports)
    {
        findShortestPath(Start, i->name);
    }
}

void GraphAlgorithms::Total_Connections() {
    Tuple<string, int> All_Connections[166];

    int j = 0;

    //fills the table of all sums with their appropriate keys
    for(auto i : graph->All_Keys())
    {
        int total = 0;
        total += graph->search(i)->Edges.size();
        total += graph->All_Inbound(i).size();
        All_Connections[j] = Tuple<string, int>(i, total);
        j++;
    }

    //Algorithm to sort array largest -> smalllest
    for(int i = 1; i < 166; i++) {
        for (j = 0; j < 166-i; j++) {

            if(All_Connections[j].getVal2() < All_Connections[j+1].getVal2())
            {
                auto temp = All_Connections[j];
                All_Connections[j] = All_Connections[j+1];
                All_Connections[j+1] = temp;
            }
        }
    }

    //print out the result
    for(auto i : All_Connections)
    {
        cout<< i.getVal1() << ": " << i.getVal2() << endl;
    }

}

GraphAlgorithms::GraphAlgorithms(Graph graph) {
    
}


// Helper function
bool sortbyth(const TripleTuple<AirportNode*, AirportNode*, int>& a,
              const TripleTuple<AirportNode*, AirportNode*, int>& b)
{
    return (a.getVal3() < b.getVal3());
}


// Problem 8 Done
int GraphAlgorithms::minSpanningTree_Kruskal() {

    vector<AirportNode*> vertices;
    vector<TripleTuple<AirportNode*, AirportNode*, int>> allEdges = graph->getAllEdgesAsPairsWithCost();

    int mst_wt = 0;
    // Sorts the edges by weight
    std::sort(allEdges.begin(), allEdges.end(),sortbyth);

    // Fill the vertices vector with all the vertices in the graph. 
    for (auto x : graph->All_Keys()){
        vertices.push_back(graph->search(x));
    }

    // Create a vector to store the vertices included in the MST
    vector<AirportNode*> mst_vertices;
    cout << "Minimal Spanning Tree:" << endl << "Edge:            Weight:" << endl;
    // Iterate through all the edges in the graph
    for (auto e : allEdges){

        // Get the vertices of the edge
        AirportNode* u = e.getVal1();
        AirportNode* v = e.getVal2();


        
        // Check if the vertices of the edge are already included in the MST
        if (std::find(mst_vertices.begin(), mst_vertices.end(), u) == mst_vertices.end() ||
            std::find(mst_vertices.begin(), mst_vertices.end(), v) == mst_vertices.end()) {

            // If they are not, add the edge to the MST and add the weight of the edge to the mst_wt
            cout << u->name << " - " << v->name << "        " << e.getVal3() << endl;
            
            mst_wt += e.getVal3();

            // Add the vertices to the MST vertices
            mst_vertices.push_back(u);
            mst_vertices.push_back(v);
        }
    }
    
    cout << "Total weight of the MST: " << mst_wt << endl;
    
    return mst_wt;
}

// Problem 7 Done
int GraphAlgorithms::minSpanningTree_Prim() {
    
    // Put all verticies into a vector
    vector<AirportNode*> verticies;
    for (auto v: graph->All_Keys()){
        verticies.push_back(graph->search(v));
    }
    
    vector<TripleTuple<AirportNode*, AirportNode*, int>> allEdges = graph->getAllEdgesAsPairsWithCost();

    std::sort(allEdges.begin(), allEdges.end(),sortbyth);

    // Creating mstVerticies vector to track current verticies in the MST
    vector<AirportNode*> mstVertices;
    
    // Push the first vertice in the verticies vector into mstVerticies (The node pushed in doesn't matter as it is arbitrary
    mstVertices.push_back(verticies[0]);
    vector<TripleTuple<AirportNode*, AirportNode*, int>> toCheck;

    //TESTING
    int totalMstCost = 0;
    int totalEdges = 0;

    // Should add all the edges of all mstVerticies into a temp vector for checking each edge to find the smallest one.
    for (auto v : verticies){
        
        // If the current vertice already exists in the mstVerticies vector, then skip this code block.
        if (std::find(mstVertices.begin(), mstVertices.end(), v) == mstVertices.end()){
            string origin = v->name;
            
            
            
            // Fills toCheck vector with all edges of the current mstVerticies.
            for (auto e : allEdges){
                if (origin == e.getVal1()->name){
                    toCheck.push_back(e);
                }
            }
//            
//            for (auto x : mstVertices){
//                for (auto e: allEdges){
//                    if (x->name == e.getVal1()->name){
//                        toCheck.push_back(e);
//                    }
//                }
//            }

            // Sort toCheck to get the smallest edge value in first position.
            std::sort(toCheck.begin(), toCheck.end(),sortbyth);

            // Get the smallest edge in the current mstVertices and push the node it leads to into mstVerticies.
            
            origin = toCheck[0].getVal1()->name;
            AirportNode* smallestEdge = toCheck[0].getVal2();
            int smallestEdgeCost = toCheck[0].getVal3();
            mstVertices.push_back(smallestEdge);

            // Print out origin airport name, destination airport name, and cost of the edge between them.
            cout << origin << " - " << smallestEdge->name << " " << smallestEdgeCost << endl;
            
            totalMstCost += smallestEdgeCost;
            totalEdges++;

            // Clear toCheck vector to prevent double-checking.
            toCheck.clear();
        }
    }
    
    cout << "Verticies: "<< mstVertices.size() << endl;
    cout << "Edges: "<< totalEdges << endl;
    cout << "Total Cost: " << totalMstCost << endl;
    return 0;
}