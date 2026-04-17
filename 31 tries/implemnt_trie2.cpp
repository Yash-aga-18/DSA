#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1804  Implement Trie II (Prefix Tree)


struct Node {
    Node* child[26];
    int cntEnd;     // count of words ending here
    int cntPrefix;  // count of words passing through

    Node() {
        for (int i = 0; i < 26; i++) child[i] = NULL;
        cntEnd = 0;
        cntPrefix = 0;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->child[idx] == NULL) {
                curr->child[idx] = new Node();
            }

            curr = curr->child[idx];
            curr->cntPrefix++;   // increase prefix count
        }

        curr->cntEnd++;  // word ends here
    }


    // count exact word
    int countWordsEqualTo(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->child[idx] == NULL) return 0;

            curr = curr->child[idx];
        }

        return curr->cntEnd;
    }


    // count words with given prefix
    int countWordsStartingWith(string prefix) {
        Node* curr = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (curr->child[idx] == NULL) return 0;

            curr = curr->child[idx];
        }

        return curr->cntPrefix;
    }


    //  erase word
    void erase(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->child[idx] == NULL)       return; // word not present

            curr = curr->child[idx];
            curr->cntPrefix--;   // decrease prefix count
        }

        curr->cntEnd--;   // decrease word end count
    }
};


int main() {

    Trie trie;

    // inserting words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apple");

    // queries
    cout << "Count 'apple': " << trie.countWordsEqualTo("apple") << "\n";
    cout << "Count 'app': " << trie.countWordsEqualTo("app") << "\n";

    cout << "Prefix 'app': " << trie.countWordsStartingWith("app") << "\n";
    cout << "Prefix 'ap': " << trie.countWordsStartingWith("ap") << "\n";

    // erase one "apple"
    trie.erase("apple");

    cout << "\nAfter erase:\n";
    cout << "Count 'apple': " << trie.countWordsEqualTo("apple") << "\n";
    cout << "Prefix 'app': " << trie.countWordsStartingWith("app") << "\n";

    return 0;
}