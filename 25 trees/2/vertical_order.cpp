#include <bits/stdc++.h>
using namespace std;

// leetcode Q->987 Vertical Order Traversal of a Binary Tree

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};


vector<vector<int>> verticalTraversal(Node* root) {

    // column -> row -> multiple node values
    map<int, map<int, vector<int>>> mp;


    // {node, {row, col}}
    queue<pair<Node*, pair<int, int>>> q;

    // Start from root at (0,0)
    q.push({root, {0, 0}});

    while (!q.empty()) {

        auto front = q.front();
        q.pop();

        Node* node = front.first;

        int row = front.second.first;
        int col = front.second.second;

        // Store the node according to its column and row.
        // Go to this column → go to this row → insert the node value.
        mp[col][row].push_back(node->val);

        // Left child
        if (node->left) {
            q.push({node->left, {row + 1, col - 1}});
        }

        // Right child
        if (node->right) {
            q.push({node->right, {row + 1, col + 1}});
        }
    }

    vector<vector<int>> ans;

    // Traverse each column from left to right
    for (auto column : mp) {

        vector<int> vertical;

        // Traverse each row in the current column
        for (auto row : column.second) {

            sort(row.second.begin(), row.second.end());     // as we used vector and Leetcode asks in sorted order

            // Traverse all node values at this (row, column)
            for (int value : row.second) {

                vertical.push_back(value);
            }
        }

        ans.push_back(vertical);
    }

    return ans;
}


int main() {

    /*
            1
          /   \
         7     9
        / \   / \
       2   6 4   0
      /         / \
     8         13  7
    */

    Node* a = new Node(1);

    Node* b = new Node(7);
    Node* c = new Node(9);

    Node* d = new Node(2);
    Node* e = new Node(6);
    Node* f = new Node(4);
    Node* g = new Node(0);

    Node* h = new Node(8);
    Node* i = new Node(13);
    Node* j = new Node(7);


    a->left  = b;
    a->right = c;

    b->left  = d;
    b->right = e;

    c->left  = f;
    c->right = g;

    d->left  = h;

    g->left  = i;
    g->right = j;


    Node* root = a;
    vector<vector<int>> ans = verticalTraversal(root);

    for (auto column : ans) {
        for (int x : column)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}