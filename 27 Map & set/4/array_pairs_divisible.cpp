#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1497     Check If Array Pairs Are Divisible by k

// divide the array into pairs such that the sum of each pair is divisible by k.


bool canArrange(vector<int>& arr, int k) {

    unordered_map<int, int> mp;

    // Step 1: store remainders
    for (int i = 0; i < arr.size(); i++) {
        int rem = arr[i] % k;

        // handle negative numbers  (trick)
        if (rem < 0) rem += k;

        mp[rem]++;
    }

    // Step 2: check remainder = 0
    if (mp[0] % 2 != 0)     return false;


    // Step 3: check other remainders
    for (auto ele : mp) {

        int rem = ele.first;

        // avoid double checking of zeroes
        if (rem == 0) continue;

        int other = k - rem;
        if (mp[rem] != mp[other]) return false;
        
    }

    return true;

}



int main() {

    // 🔥 Test Case
    vector<int> arr = {2, 4, 1, 3};
    int k = 5;

    if (canArrange(arr, k)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}