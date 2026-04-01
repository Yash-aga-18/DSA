#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2483. Minimum Penalty for a Shop

// the penalty is calculated as follows:
// For every hour when the shop is open and no customers come, the penalty increases by 1.
// For every hour when the shop is closed and customers come,  the penalty increases by 1.
// Once shop is closed, it can't open again.
// Return the earliest hour 

// Input: "YYNY"
// Output: 2
// Explanation: 
// - Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
// - Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
// - Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
// - Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
// - Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
// Closing the shop at 2nd



void penalty2(string& str) {

    int n = str.size();
    int penalty = count(str.begin(), str.end(), 'Y');
    int bestPenalty = penalty;
    int bestHour = 0;


    for (int i = 0; i < n; i++) {

        if (str[i] == 'Y')      penalty--;
        else                    penalty++;
        
        if (penalty < bestPenalty) {
            bestPenalty = penalty;
            bestHour = i + 1;   // Closing after this hour
        }
    }

    cout << bestPenalty << " is the required penalty at hour " << bestHour << endl;

}

// STEP: Move closing hour from 0 --> n  and adjust penalty in constant time.

// If current char = 'Y':
//     That customer was counted earlier as "closed while customer came".
//     But now shop is open for this hour → remove that penalty (penalty--).

// If current char = 'N':
//     Now the shop is open but no customer → penalty increases (penalty++).v


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

void penalty1(string &str) {

    int n = str.size();

    // We consider closing hours from 0 to n, so arrays of size n+1
    vector<int> preN  (n+1, 0);   
    vector<int> suffY (n+1, 0);   

    // Build prefix: count of 'N' before each position
    for (int i = 0; i < n; i++) {
        preN[i + 1] = preN[i] + (str[i] == 'N');
    }

    // Build suffix: count of 'Y' from each position to end
    for (int i = n-1; i >= 0; i--) {
        suffY[i] = suffY[i+1] + (str[i] == 'Y');
    }

    // cout << "preN:   ";
    // for (int x : preN) cout << x << " ";
    // cout << "\n";

    // cout << "suffY:  ";
    // for (int x : suffY) cout << x << " ";
    // cout << "\n";


    int bestPenalty = INT_MAX;
    int bestHour = 0;

    // Try closing at each hour i: 0..n
    for (int i = 0; i <= n; i++) {
        int penalty = preN[i] + suffY[i];

        if (penalty < bestPenalty) {
            bestPenalty = penalty;
            bestHour = i;
        }
    }

    cout << bestPenalty << " is the required answer at " << bestHour << " hour\n";
}


//  concept used --> we can calculate no. of Y at & after the idx and no. of N before it
//  and sum together and find minimum value betweern thier sums

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


int main()
{
    string str = "YYNY";
    
    penalty1(str);
    penalty2(str);

 return 0;

}