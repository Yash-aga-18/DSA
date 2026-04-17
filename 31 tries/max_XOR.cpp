#include <bits/stdc++.h>
using namespace std;

// leetcode Q->421  Maximum XOR of Two Numbers in an Array


// Node structure
struct Node {
    Node* child[2];   // only 0 and 1

    Node() {
        child[0] = child[1] = NULL;
    }
};



Node* root = new Node();   // initialize root


// insert number into trie
void insert(int num) {

    Node* curr = root;

    // go from MSB → LSB
    for (int i = 31; i >= 0; i--) {

        int bit = (num >> i) & 1;   // extract i-th bit

        // create node if not present
        if (curr->child[bit] == NULL) {
            curr->child[bit] = new Node();
        }

        curr = curr->child[bit];   // move forward
    }
}

// get max XOR for a number
int getMax(int num) {

    Node* curr = root;
    int ans = 0;

    for (int i = 31; i >= 0; i--) {

        int bit = (num >> i) & 1;

        // try opposite bit to maximize XOR
        if (curr->child[1 - bit] != NULL) {

            ans |= (1 << i);              // set this bit in answer
            curr = curr->child[1 - bit];  // move opposite
        }
        else {
            curr = curr->child[bit];      // move same
        }
    }

    return ans;
}



int main() {

    vector<int> arr = {3, 10, 5, 25, 2, 8};

    // insert all numbers
    for (int num : arr) {
        insert(num);
    }

    int maxi = 0;

    // find maximum XOR
    for (int num : arr) {
        maxi = max(maxi, getMax(num));
    }

    cout << "Maximum XOR: " << maxi << "\n";

    return 0;
}