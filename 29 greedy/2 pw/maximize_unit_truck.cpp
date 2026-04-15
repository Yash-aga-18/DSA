#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1710     Maximum Units on a Truck



bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] > b[1];     // sort by units per box (descending)
}

// Function to calculate maximum units
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

    // Step 1: Sort using cmp
    sort(boxTypes.begin(), boxTypes.end(), cmp);


    int totalUnits = 0;

    // Step 2: Pick boxes greedily
    for(int i = 0; i < boxTypes.size(); i++) {

        int numberOfBoxes = boxTypes[i][0];
        int unitsPerBox   = boxTypes[i][1];

        // take as many as possible
        int boxesTaken = min(truckSize, numberOfBoxes);

        totalUnits += boxesTaken * unitsPerBox;
        truckSize -= boxesTaken;

        if(truckSize == 0) break; // truck full
    }

    return totalUnits;
}



int main() {

    // Input
    vector<vector<int>> boxTypes = {
        {1, 3},
        {2, 2},
        {3, 1}
    };

    int truckSize = 4;

    // Function call
    int result = maximumUnits(boxTypes, truckSize);

    // Output
    cout << "Maximum Units: " << result << endl;

    return 0;
}