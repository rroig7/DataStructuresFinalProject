//
// Created by danie on 4/17/2024.
//

#include "AirportNode.h"

using namespace std;
int main()
{
    vector<AirportNode*> CentralCenter;

    AirportNode T1("ATL");
    AirportNode T2("AUS");
    T1.Add_Edge(&T2, 812, 102 );
    CentralCenter.push_back(&T1);
    CentralCenter.push_back(&T2);



    return 0;
}