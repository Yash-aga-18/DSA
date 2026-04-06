#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1657   Check wheteher the given 2 strings are close or not


bool closeStrings(string str1, string str2) {

    if (str1.size() != str2.size())     return false;

    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;

    // Step 1: frequency count
    for (char ch : str1) mp1[ch]++;
    for (char ch : str2) mp2[ch]++;

    // Step 2: check same characters exist or not
    for (auto ele : mp1) {
        char ch = ele.first;

        if (mp2.find(ch) == mp2.end())      return false;   //not find the same ch
        
    }

    // Step 3: frequency distribution check
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;

    for (auto ele : mp1) {
        int count = ele.second;
        freq1[count]++;
    }

    for (auto ele : mp2) {
        int count = ele.second;
        freq2[count]++;
    }

    return freq1 == freq2;


}

int main() {

    // 🔥 Test Case
    string str1 = "aabbcc";
    string str2 = "ccbbaa";

    if (closeStrings(str1, str2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}