#include <bits/stdc++.h>
using namespace std;

// leetcode Q->3    Longest Substring Without Repeating Characters


// 🔹 Method 1: Using unordered_map
int longestSubstring_map(string s) {

    unordered_map<char, int> mp;

    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.size(); right++) {

        char ch = s[right];

        if (mp.find(ch) != mp.end() && mp[ch] >= left) {
            left = mp[ch] + 1;
        }

        mp[ch] = right;

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}


// 🔹 Method 2: Using array (faster)
int longestSubstring_array(string s) {

    vector<int> lastSeen(256, -1);

    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.size(); right++) {

        char ch = s[right];

        if (lastSeen[ch] >= left) {
            left = lastSeen[ch] + 1;
        }

        lastSeen[ch] = right;

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}


int main() {

    // 🔥 Test Case
    string s = "abcabcbb";

    cout << "Using map: " << longestSubstring_map(s) << endl;
    cout << "Using array: " << longestSubstring_array(s) << endl;

    return 0;
}