#include <bits/stdc++.h>
using namespace std;


priority_queue<int> leftHeap;   // max heap → smaller half
priority_queue<int, vector<int>, greater<int>> rightHeap;  // min heap → larger half

unordered_map<int, int> delayed; // lazy delete map

int leftSize = 0, rightSize = 0;




// remove elements which are marked for deletion (from max heap)
void pruneLeft() {
    while (!leftHeap.empty() && delayed[leftHeap.top()]) {
        delayed[leftHeap.top()]--;
        leftHeap.pop();
    }
}

// remove elements from min heap
void pruneRight() {
    while (!rightHeap.empty() && delayed[rightHeap.top()]) {
        delayed[rightHeap.top()]--;
        rightHeap.pop();
    }
}


// balance both heaps so size difference ≤ 1
void balance() {

    // leftHeap has extra element → move to rightHeap
    if (leftSize > rightSize + 1) {

        rightHeap.push(leftHeap.top());
        leftHeap.pop();

        leftSize--;
        rightSize++;

        pruneLeft();
    }

    // rightHeap has more elements → move to leftHeap
    else if (leftSize < rightSize) {

        leftHeap.push(rightHeap.top());
        rightHeap.pop();

        rightSize--;
        leftSize++;

        pruneRight();
    }
}


// add new number
void add(int num) {

    // goes to leftHeap (max heap)
    if (leftHeap.empty() || num <= leftHeap.top()) {

        leftHeap.push(num);
        leftSize++;

    } 
    // goes to rightHeap (min heap)
    else {

        rightHeap.push(num);
        rightSize++;

    }

    balance();
}

// remove number (lazy deletion)
void remove(int num) {

    delayed[num]++; // mark for deletion

    // decide which heap it belongs to
    if (num <= leftHeap.top()) {
        leftSize--;
        if (num == leftHeap.top())      pruneLeft();
    } 

    else {
        rightSize--;
        if (num == rightHeap.top())     pruneRight();
    }

    balance();
}


// get current median
double getMedian(int k) {

    if (k % 2 != 0) return leftHeap.top();      // odd size → top of max heap
    
    return ((double)leftHeap.top() + rightHeap.top()) / 2.0;    // even size → average of both tops
}




vector<double> medianSlidingWindow(vector<int>& arr, int k) {

//     // // 🔥 IMPORTANT: reset globals (must!)
//     // while (!leftHeap.empty())   leftHeap.pop();
//     // while (!rightHeap.empty()) rightHeap.pop();
//     // delayed.clear();
//     // leftSize = rightSize = 0;



    vector<double> ans;

    for (int i = 0; i < arr.size(); i++) {

        add(arr[i]); // add element

        // when window size reached
        if (i >= k - 1) {

            ans.push_back(getMedian(k)); // store median

            remove(arr[i-k + 1]); // remove outgoing element
        }
    }

    return ans;
}




int main() {

    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<double> ans = medianSlidingWindow(arr, k);

    for(double x : ans) cout << x << " ";

    return 0;
}