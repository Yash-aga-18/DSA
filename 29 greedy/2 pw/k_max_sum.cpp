#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2600   K Items With the Maximum Sum


int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {

    int sum = 0;

    // Step 1: take +1 items
    int takeOnes = min(numOnes, k);
    sum += takeOnes;
    k -= takeOnes;

    // Step 2: take 0 items (no effect on sum)
    int takeZeros = min(numZeros, k);
    k -= takeZeros;

    
    // Step 3: remaining are -1 items
    sum -= k;

    return sum;
}



int main() {

    // Input
    int numOnes = 3;
    int numZeros = 2;
    int numNegOnes = 1;
    int k = 4;

    // Function call
    int result = kItemsWithMaximumSum(numOnes, numZeros, numNegOnes, k);

    // Output
    cout << "Maximum Sum: " << result << endl;

    return 0;
}