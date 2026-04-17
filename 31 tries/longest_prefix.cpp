#include <bits/stdc++.h>
using namespace std;

// GFG----> Longest Valid Word with All Prefixes 


// Trie Node
struct Node {
    Node* child[26];
    bool isEnd;

    Node() {
        for (int i = 0; i < 26; i++) child[i] = NULL;
        isEnd = false;
    }
};


// Trie
class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // insert word
    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->child[idx] == NULL) {
                curr->child[idx] = new Node();
            }

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    // check if all prefixes exist
    bool check(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            curr = curr->child[idx];

            // every prefix must be a word
            if (curr->isEnd == false) return false;
        }

        return true;
    }
};


// main logic
string longestValidWord(vector<string>& words) {

    Trie trie;

    // insert all words
    for (string str : words) {
        trie.insert(str);
    }

    string ans = "";

    for (string str : words) {

        if (trie.check(str)) {

            // pick longest OR lexicographically smaller
            if (str.size() > ans.size() || 
               (str.size() == ans.size() && str < ans)) {
                
                ans = str;
            }
        }
        
        
    }

    return ans;
}


int main() {

    vector<string> words = {"a","ap","app","appl","apple","apply"};

    string ans = longestValidWord(words);

    cout << ans << "\n";

    return 0;
}