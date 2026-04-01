#include <bits/stdc++.h>
using namespace std;

// leetcode Q->199 Binary Tree  Right/Left  Side View

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


// ---------------- BFS FUNCTION ----------------
vector<vector<int>> BFS(Node* root) {

    vector<vector<int>> ans;

    if (root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        int size = q.size();   // ⭐ number of nodes at current level
        vector<int> level;

        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            level.push_back(temp->val);

            if (temp->left)  q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        ans.push_back(level);
    }

    return ans;
}


// ---------------- MAIN ----------------
int main()
{
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    Node* root = a;

    vector<vector<int>> ans = BFS(root);

    cout << "Left View:  ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " ";
    }
    cout << endl;



    cout << "Right View: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][ans[i].size() - 1] << " ";
    }
    cout << endl;

    return 0;
}