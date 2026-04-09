#include <bits/stdc++.h>
using namespace std;

// leetcode Q->703  return the kth largest elemnt from a stream


class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);

            if(pq.size() > k)   pq.pop();
            
        }

    }
    
    int add(int val) {
        
        pq.push(val);
        if(pq.size() > k)   pq.pop();
        

        return pq.top(); // kth largest
    }

};

int main() {

    vector<int> nums = {4,5,8,2};
    KthLargest obj(3, nums);

    cout << obj.add(3) << endl;   // 4
    cout << obj.add(5) << endl;   // 5
    cout << obj.add(10) << endl;  // 5
    cout << obj.add(9) << endl;   // 8
    cout << obj.add(4) << endl;   // 8

    return 0;
}