#include <bits/stdc++.h>
using namespace std;

//print the power set for a given n number
// int n= 3;
// ans--> [ [],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3] ]

int main()
{
    
    int n = 3;
    int subsets = 1 << n;   // 2^n
    vector<vector<int>> v;

    // Loop through all subset numbers
    for (int i = 0; i < subsets; i++) {

        vector<int> temp;

        // Check each bit of i
        for (int j = 0; j < n; j++) {

            // If j-th bit of i is set, include element (j+1)
            int mask = 1 << j;
            if (i & mask)   temp.push_back(j + 1);
            
        }

        v.push_back(temp);

    }

    // Print result
    for (vector<int> subset : v) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }



 return 0;

}