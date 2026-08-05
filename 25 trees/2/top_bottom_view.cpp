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

// ---------------- QUEUE NODE ----------------
class QNode {
public:
    Node* node;
    int hd;

    QNode(Node* n, int h) {
        node = n;
        hd = h;
    }
};

// ---------------- FIND RANGE ----------------
void findRange(Node* root, int hd, int& minHD, int& maxHD) {
    if (root == NULL) return;

    if (hd < minHD) minHD = hd;
    if (hd > maxHD) maxHD = hd;

    findRange(root->left, hd - 1, minHD, maxHD);
    findRange(root->right, hd + 1, minHD, maxHD);
}

// ---------------- MERGED FUNCTION ----------------
void topBottomView(Node* root, vector<int>& top, vector<int>& bottom) {

    if (root == NULL) return;

    int minHD = 0, maxHD = 0;
    findRange(root, 0, minHD, maxHD);

    int width = maxHD - minHD + 1;

    top.assign(width, -1);
    bottom.assign(width, -1);

    vector<bool> filled(width, false);

    queue<QNode> q;
    q.push(QNode(root, 0));

    while (!q.empty()) {
        QNode front = q.front();
        q.pop();

        Node* node = front.node;
        int hd = front.hd;

        int index = hd - minHD;

        // TOP VIEW → first occurrence
        if (!filled[index]) {
            top[index] = node->val;
            filled[index] = true;
        }

        // BOTTOM VIEW → overwrite
        bottom[index] = node->val;

        if (node->left != NULL) {
            q.push(QNode(node->left, hd - 1));
        }

        if (node->right != NULL) {
            q.push(QNode(node->right, hd + 1));
        }
    }
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

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    e->right = f;
    c->right = g;
    g->left = h;

    vector<int> top, bottom;

    topBottomView(a, top, bottom);

    cout << "Top View:    ";
    for (int x : top) cout << x << " ";
    cout << endl;

    cout << "Bottom View: ";
    for (int x : bottom) cout << x << " ";
    cout << endl;

    return 0;
}