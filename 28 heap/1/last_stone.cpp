#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1046      Last Stone Weight

int lastStoneWeight(vector<int>& stones) {

    // max heap
    priority_queue<int> pq;

    // push all stones
    for(int x : stones) {
        pq.push(x);
    }

    // process until one or zero stones left
    while(pq.size() > 1) {

        int first = pq.top(); 
        pq.pop();

        int second = pq.top(); 
        pq.pop();

        int diff = first - second;

        if(diff != 0)            pq.push(diff);

    }

    // if empty → return 0
    if(pq.size() == 0)  return 0;
    return pq.top();

}



int main() {

    vector<int> stones = {2, 7, 4, 1, 8, 1};

    int result = lastStoneWeight(stones);

    cout << "Last Stone Weight: " << result << endl;

    return 0;
}