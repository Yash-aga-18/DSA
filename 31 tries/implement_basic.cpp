#include <bits/stdc++.h>
using namespace std;

// leetcode Q->208      Implement Trie (Prefix Tree)


// Simple Trie Node
struct Node {
    Node* child[26];   // store children (a–z)
    bool isEnd;        // marks end of word

    // constructor
    Node() {
        for (int i = 0; i < 26; i++)    child[i] = NULL;
        isEnd = false;
    }
};

class Trie {
    Node* root;

public:
    // constructor
    Trie() {
        root = new Node();   // create root node
    }
    
    
    // insert word
    void insert(string word) {
        Node* curr = root;   // start from root

        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';   // convert char to index

            // if node doesn't exist → create it
            if (curr->child[idx] == NULL) {
                curr->child[idx] = new Node();
            }

            
            curr = curr->child[idx];      // move to next node
        }

        curr->isEnd = true;         // mark end of word
        
    }



    // search full word
    bool search(string word) {
        Node* curr = root;

        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';

            // if path breaks → word not found
            if (curr->child[idx] == NULL)   return false;

            curr = curr->child[idx];
        }

        return curr->isEnd;     // check if it's actually a complete word
        
    }
    
    // check prefix
    bool startsWith(string prefix) {
        Node* curr = root;

        for (int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';

            // if path breaks → prefix not found
            if (curr->child[idx] == NULL)   return false;

            curr = curr->child[idx];
        }

        return true;        // prefix exists
        
    }
};

int main() {

    Trie trie;

    vector<string> operations = {
        "insert", "search", "search", "startsWith", "insert", "search"
    };

    vector<string> values = {
        "apple", "apple", "app", "app", "app", "app"
    };

    for (int i = 0; i < operations.size(); i++) {

        if (operations[i] == "insert") {
            trie.insert(values[i]);
            cout << "null" << endl;
        }

        else if (operations[i] == "search") {
            cout << (trie.search(values[i]) ? "true" : "false") << endl;
        }

        else if (operations[i] == "startsWith") {
            cout << (trie.startsWith(values[i]) ? "true" : "false") << endl;
        }
    }

    return 0;
}