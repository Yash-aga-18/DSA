#include <bits/stdc++.h>
using namespace std;

// ---------------- NODE ----------------
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> topView(Node *root) {

    // column -> first node value
    map<int, int> mp;


    // {node, column}
    queue<pair<Node*, int>> q;

    // Start from root at column 0
    q.push({root, 0});

    while (!q.empty()) {

        auto front = q.front();
        q.pop();

        Node* node = front.first;

        int col = front.second;

        // Store only the first node of every column.
        // Since BFS visits level by level, the first node
        // encountered is the topmost node.
        if (mp.find(col) == mp.end()) {
            mp[col] = node->val;
        }

        // Left child
        if (node->left) {
            q.push({node->left, col - 1});
        }

        // Right child
        if (node->right) {
            q.push({node->right, col + 1});
        }
    }

    vector<int> ans;

    // Traverse each column from left to right
    for (auto column : mp) {

        ans.push_back(column.second);
    }

    return ans;
}


vector<int> bottomView(Node *root) {

    // column -> latest node value
    map<int, int> mp;


    // {node, column}
    queue<pair<Node*, int>> q;

    // Start from root at column 0
    q.push({root, 0});

    while (!q.empty()) {

        auto front = q.front();
        q.pop();

        Node* node = front.first;

        int col = front.second;

        // Keep updating the node of every column.
        // Since BFS visits level by level, the last node
        // encountered is the bottommost node.
        mp[col] = node->val;

        // Left child
        if (node->left) {
            q.push({node->left, col - 1});
        }

        // Right child
        if (node->right) {
            q.push({node->right, col + 1});
        }
    }

    vector<int> ans;

    // Traverse each column from left to right
    for (auto column : mp) {

        ans.push_back(column.second);
    }

    return ans;
}


int main()
{
    /*
                1
               / \
              2   3
             / \   \
            4   5   7
                 \  /
                  6 8
    */

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    Node* h = new Node(8);

    a->left  = b;
    a->right = c;

    b->left  = d;
    b->right = e;

    e->right = f;

    c->right = g;

    g->left  = h;


    vector<int> top    = topView(a);
    vector<int> bottom = bottomView(a);


    cout << "Top View:    ";
    for (int x : top) cout << x << " ";
    cout << endl;

    cout << "Bottom View: ";
    for (int x : bottom) cout << x << " ";
    cout << endl;

    return 0;
}