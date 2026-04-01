#include <bits/stdc++.h>
using namespace std;

// Intereleave the first half into second half  (Method-->2)
// Input:  1 2 3 4 5 6 7 8
// Output: 1 5 2 6 3 7 4 8


// Rearrange queue
void rearrangeQueue(queue<int>& q) {
    int n = q.size();
    stack<int> st;

    // Step 1: Push first half into stack
    for (int i = 0; i < n / 2; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Push stack elements back into queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move first half to back
    for (int i = 0; i < n / 2; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: Again push first half into stack
    for (int i = 0; i < n / 2; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 5: Interleave
    while (!st.empty()) {
        q.push(st.top());
        st.pop();

        q.push(q.front());
        q.pop();
    }
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
    cout << "Enter no. of elements (even): ";
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