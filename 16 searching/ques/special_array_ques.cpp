#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1608 Special Array With X Elements Greater Than or Equal X

// you have given an array you have to return a number X such that 
// there are X elemnts are greater than or equals to X

// eg.--> 1 2 4 5 6    ans-->3
//  as there are 3 elemnts greater than or equal to 3 

int main()
{
    vector<int>nums = {1,2,4,5,6,7};

    sort(nums.begin(), nums.end());
    int n = nums.size();

    // Step 1: If even the smallest element >= n
    // Then all n elements are >= n → special number is n

    if (nums[0] >= n) {
        cout << n;
        return 0;
    }

    int low = 0;
    int high = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // find first element >= mid
        int idx = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
        int count = n - idx;

        if (count == mid){
            cout<< mid;                // perfect match
            return 0;
        }

        else if (count > mid)   low = mid + 1;       // need a larger x (more count)

        else                    high = mid - 1;            // need smaller x
    }

    return -1;                         // no such x found

  
  
  
 return 0;

}