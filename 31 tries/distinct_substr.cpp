#include <bits/stdc++.h>
using namespace std;

// GFG---> Count of distinct substrings


// Trie Node
struct Node {
    Node* child[26];

    Node() {
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};


int countSubs(string &str) {

    Node* root = new Node();

    int n = str.size();
    int count = 0;

    // generate all substrings
    for (int i = 0; i < n; i++) {

        Node* curr = root;

        for (int j = i; j < n; j++) {

            int idx = str[j] - 'a';

            // if new path → new substring
            if (curr->child[idx] == NULL) {
                curr->child[idx] = new Node();
                count++;
            }

            curr = curr->child[idx];
        }
    }

    return count ;

}


int main() {

    string str = "ababaa";

    int ans = countSubs(str);

    cout << "String: " << str << "\n";
    cout << "Distinct substrings: " << ans << "\n";

    return 0;
}