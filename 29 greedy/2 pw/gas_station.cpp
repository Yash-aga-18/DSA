#include <bits/stdc++.h>
using namespace std;

// leetcode Q->134      Gas Station


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    int n = gas.size();
    
    
// //  u can use this loop and use another loop then---->

    // int totalGas = 0;
    // int totalCost = 0;
    
    // for (int i = 0; i < gas.size(); i++) {
    //     totalGas += gas[i];
    //     totalCost += cost[i];
    // }
        
    // if (totalGas - totalCost  < 0)  return -1;
        
    
    int tank  = 0;       // current fuel in tank
    int total = 0;       // total gas - total cost (to check if possible)
    int start = 0;       // answer (starting index)

    for(int i=0; i<n; i++) {

        int diff = gas[i] - cost[i];    // net fuel gain/loss at station i

        tank += diff;   // add to current tank
        total += diff;  
        // track overall feasibility     or u can check total in another loop 

        // if tank becomes negative → cannot reach next station
        if(tank < 0) {

            // so we cannot start from any previous station
            start = i + 1;  // move start to next station

            tank = 0;       // reset tank and try again
        }
    }


    if(total < 0)       return -1;
    
    return start;
}



int main() {

    vector<int> gas  = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << "Start Index: " << canCompleteCircuit(gas, cost) << endl;

    return 0;
}