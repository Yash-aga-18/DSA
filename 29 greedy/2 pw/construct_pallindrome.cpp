#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1400     Construct K Palindrome Strings


// Function to check if k palindromes can be formed
bool canConstruct(string s, int k) {

    // Case 1: not enough characters
    if(k > s.size()) return false;

    int freq[26] = {0};

    // Step 1: count frequency
    for(char c : s) {
        freq[c - 'a']++;
    }

    // Step 2: count odd frequencies
    int odd = 0;
    for(int i = 0; i < 26; i++) {
        
        if(freq[i] % 2 != 0)    odd++;
        
    }

    // Step 3: check condition
    return odd <= k;
}

int main() {

    // Input
    string s = "annabelle";
    int k = 2;

    // Function call
    bool result = canConstruct(s, k);

    // Output
    if(result) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}