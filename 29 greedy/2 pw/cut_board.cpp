#include <bits/stdc++.h>
using namespace std;

// GFG--->  Minimum Cost to cut a board into squares



int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        
    // Step 1: sort both in descending order
    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());
    
    int i = 0;
    int j = 0;
    
    int hz = 1; // horizontal pieces
    int vt = 1; // vertical pieces
    
    int cost = 0;
    
    // Step 2: greedy pick maximum cost cut first
    while(i < x.size() && j < y.size()) {
        

        if(x[i] > y[j]) {   // vertical cut

            cost += x[i] * hz; 
            vt++;
            i++;
        }

        else {              // horizontal cut
        
            cost += y[j] * vt; 
            hz++;
            j++;
        }
    }
    
    // Step 3: remaining cuts
    while(i < x.size()) {
        cost += x[i] * hz;
        i++;
    }
    
    while(j < y.size()) {
        cost += y[j] * vt;
        j++;
    }
    
    return cost;
}



int main() {

    int n = 6, m = 4;

    vector<int> x = {2, 1, 3, 1, 4}; // vertical cuts
    vector<int> y = {4, 1, 2};       // horizontal cuts

    int result = minCost(n, m, x, y);

    cout << "Minimum Cost: " << result << endl;

    return 0;
}