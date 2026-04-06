#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1865  Finding Pairs With a Certain Sum

class FindSumPairs {
public:
    vector<int> arr1;                      // stores nums1 (fixed)
    vector<int> arr2;                      // stores nums2 (modifiable)
    unordered_map<int, int> freq;          // frequency map of nums2

    // Constructor
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {

        arr1 = nums1;                      // copy nums1
        arr2 = nums2;                      // copy nums2

        // build frequency map for nums2
        for (int x : arr2) {
            freq[x]++;                     // count occurrences of each number
        }

    }


    
    void add(int index, int val) {

        int oldVal = arr2[index];          // get old value at index
        freq[oldVal]--;                    // remove old value from frequency map


        arr2[index] += val;                // update value in nums2


        int newVal = arr2[index];          // get new updated value
        freq[newVal]++;                    // add new value to frequency map
        
    }
    
    int count(int tot) {

        int ans = 0;                       // store number of valid pairs

        for (int x : arr1) {               // iterate over nums1

            int need = tot - x;            // find required value in nums2


            // if required value exists in nums2 ; add its frequency (multiple pairs possible)
            if (freq.find(need) != freq.end()) ans += freq[need];         
            
        }

        return ans;                        // return total pairs
    }

};


int main() {

    // 🔥 Test Case (same as LeetCode example)
    vector<int> nums1 = {1,1,2,2,2,3};
    vector<int> nums2 = {1,4,5,2,5,4};

    FindSumPairs obj(nums1, nums2);

    cout << obj.count(7) << endl;   // 8

    obj.add(3, 2);                 // nums2 becomes [1,4,5,4,5,4]

    cout << obj.count(8) << endl;   // 2
    cout << obj.count(4) << endl;   // 1

    obj.add(0, 1);                 // nums2 becomes [2,4,5,4,5,4]
    obj.add(1, 1);                 // nums2 becomes [2,5,5,4,5,4]

    cout << obj.count(7) << endl;   // 11

    return 0;
}