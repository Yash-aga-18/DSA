#include <bits/stdc++.h>
using namespace std;

// leetcode Q->127  Word Ladder
// GFG --> Word Ladder 1


int ladderLength(string beginWord, string endWord, vector<string>& arr) {
    
    unordered_set<string> st(arr.begin(), arr.end());
    
    // If endWord not present → impossible
    if (st.find(endWord) == st.end())       return 0;
    
    queue<pair<string, int>> q;
    q.push({beginWord, 1});   // {word, steps}
    
    if (st.find(beginWord) != st.end())     st.erase(beginWord);
    // avoid revisiting beginWord
    
    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        // If reached target
        if (word == endWord)    return steps;
        
        // Try all possible transformations
        for (int i = 0; i < word.size(); i++) {
            
            char original = word[i];
            
            for (char ch = 'a'; ch <= 'z'; ch++) {
                
                word[i] = ch;
                
                // If exists in set → valid transformation
                if (st.find(word) != st.end()) {
                    
                    q.push({word, steps + 1});
                    st.erase(word);   // mark visited
                }
            }
            
            word[i] = original;   // restore
        }
    }
    
    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    
    vector<string> arr = {"hot","dot","dog","lot","log","cog"};
    
    cout << "steps: "<<ladderLength(beginWord, endWord, arr) << endl;
    
    return 0;
}