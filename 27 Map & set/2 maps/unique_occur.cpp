#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1207     Unique occurence
// Return true if the no. of occurrences of each value in the array is unique.



// function to check unique occurrences
bool uniqueOccurrences(vector<int>& arr) {

    unordered_map<int, int> mp;
    unordered_set<int> s;

    // count frequency
    for (int val : arr) {
        mp[val]++;
    }

    // check if frequencies are unique
    for (auto val : mp) {

        int freq = val.second;

        if (s.find(freq) != s.end())    return false;
        else                            s.insert(freq);
    }

    return true;
}


int main() {

    vector<int> arr = {1, 2, 2, 1, 1, 3};

    for (int val : arr) {
        cout<<val<< " ";
    }
    cout<<endl;

    if (uniqueOccurrences(arr)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}