#include <bits/stdc++.h>
using namespace std;

//  leetcode Q->713  Subarray Product Less Than K

// Count how many contiguous subarrays have a product strictly less than k.
// Return 0 if no such subarray exists.

// Example:
// nums = [10,5,2,6], k = 100 → output = 8
//      Valid subarrays: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]
//      Note: [10,5,2] has product 100 → not allowed because product must be < k.

// Example:
// nums = [1,2,3], k = 0 → output = 0



void product(vector<int>& arr, int target) {

    int n = arr.size();
    int left = 0;

    long long prod = 1;
    int count = 0;

    for(int right = 0; right < n; right++) {

        // expand
        prod *= arr[right];

        // shrink until product becomes valid
        while(left <= right && prod >= target) {
            prod /= arr[left];
            left++;
        }

        // count valid subarrays ending at 'right'
        count += (right - left + 1);
    }

    cout << count;
    
}


int main()
{
    
    vector<int>arr = {10,5,2,8};
    int k = 100;

    product(arr,k);


 return 0;

}