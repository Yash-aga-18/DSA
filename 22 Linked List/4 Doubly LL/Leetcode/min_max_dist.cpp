#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2058
// Find Minimum and Maximum Distance Between Critical Points

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

vector<int> nodesBetweenCriticalPoints(Node* head) {

    if(head == NULL || head->next == NULL || head->next->next == NULL) {
        return {-1, -1};
    }

    vector<int> critical;

    Node* prev = head;
    Node* curr = head->next;
    Node* nextt = head->next->next;

    int idx = 1;

    while(nextt != NULL){

        if( (curr->val < prev->val && curr->val < nextt->val) ||
            (curr->val > prev->val && curr->val > nextt->val) ) {

            critical.push_back(idx);
        }

        prev = curr;
        curr = nextt;
        nextt = nextt->next;
        idx++;
    }

    if(critical.size() < 2) return {-1, -1};

    int minDist = INT_MAX;

    for(int i = 1; i < critical.size(); i++){
        minDist = min(minDist, critical[i] - critical[i-1]);
    }

    int maxDist = critical.back() - critical.front();

    return {minDist, maxDist};
}

int main() {

    // Example:
    // 1 → 3 → 2 → 2 → 3 → 2 → 2 → 2 → 7

    Node* a = new Node(1);
    Node* b = new Node(3);
    Node* c = new Node(2);
    Node* d = new Node(2);
    Node* e = new Node(3);
    Node* f = new Node(2);
    Node* g = new Node(2);
    Node* h = new Node(2);
    Node* i = new Node(7);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    h->next = i;

    Node* head = a;

    vector<int> result = nodesBetweenCriticalPoints(head);

    cout << "Min Distance: " << result[0] << endl;
    cout << "Max Distance: " << result[1] << endl;

    return 0;
}