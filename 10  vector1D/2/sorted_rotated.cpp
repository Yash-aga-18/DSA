#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1752 Check if Array Is Sorted and Rotated

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].


int main()
{

    vector<int> nums = {3, 4, 5, 1, 2};
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {

        if (nums[i] > nums[(i + 1) % n]) {          // Compare each element with next (circularly)
            count++;
        }

        if (count > 1) {
            cout<<"false";
            return 0;
        }
    }    

    cout<< "true";


 return 0;

}


/*
(i + 1) % n wraps around so the last element compares with the first.
Example for [3,4,5,1,2]:

3 < 4
4 < 5
5 > 1 ✅ (rotation point found → count = 1)
1 < 2
2 < 3 (wraps to start)

Only one place where the order “drops” → sorted & rotated ✅

If we found more than one drop, then it’s not sorted-rotated ❌
*/