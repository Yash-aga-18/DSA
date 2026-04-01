#include <bits/stdc++.h>
using namespace std;

// Intereleave the first half into second half      (Method-->1)
// Input:  1 2 3 4 5 6 7 8
// Output: 1 5 2 6 3 7 4 8


// Reverse a queue using stack
void reverseQueue(queue<int>& q) {
    stack<int> st;

    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

// Rearrange queue
void rearrangeQueue(queue<int>& q) {
    int n = q.size();
    stack<int> st;

    // Step 1: Push first half into stack
    for (int i = 0; i < n / 2; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Reverse remaining queue
    reverseQueue(q);

    // Step 3: Interleave elements
    while (!st.empty()) {
        int st_ele = st.top();
        int q_ele = q.front();

        q.push(q_ele);
        q.push(st_ele);

        q.pop();
        st.pop();
    }

    // Step 4: Final reverse
    reverseQueue(q);
}

// Print queue
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    // Input
    int n;
    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // Rearrange
    rearrangeQueue(q);

    // Output
    cout << "Rearranged Queue: ";
    printQueue(q);

    return 0;
}