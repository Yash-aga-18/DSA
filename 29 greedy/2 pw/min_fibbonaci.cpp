#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1414     Find the Minimum Number of Fibonacci Numbers Whose Sum Is K


int findMinFibonacciNumbers(int k) {

    vector<int> fib = {1, 1};   // pre-generated fib vector

    // Step 1: generate fibonacci numbers up to k
    while (fib.back() < k) {
        int n = fib.size();
        fib.push_back(fib[n - 1] + fib[n - 2]);
    }

    int count = 0;

    // Step 2: greedy (take largest first)
    for (int i = fib.size() - 1; i >= 0; i--) {

        if (fib[i] <= k) {
            k -= fib[i];   // subtract
            count++;       // count it
        }

        if (k == 0) break; // done
    }

    return count;
}

int main() {

    int k = 19; // input

    int result = findMinFibonacciNumbers(k);

    cout << "Minimum Fibonacci Numbers: " << result << endl;

    return 0;
}