#include <bits/stdc++.h>
using namespace std;

// leetcode Q->33
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// but the elemnts may be duplicated

int main()
{
    
    int arr[]={2,5,6,0,0,1,2};
    int target = 1;
    int n = sizeof(arr)/sizeof(arr[0]);

    int low = 0, high = n-1;
    int mid = -1;

    while (low <= high) {
        
        mid = low + (high - low) / 2;

        if (arr[mid] == target)    break;

        // Handle duplicates — can’t decide which side is sorted
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        // Check which half is sorted

        if (arr[low] <= arr[mid]) {     // Left half sorted

            if (arr[low] <= target && target < arr[mid])      high = mid - 1;
            else    low = mid + 1;
        } 

        else {                       // Right half sorted

            if (arr[mid] < target && target <= arr[high])       low = mid + 1;
            else    high = mid - 1;
        }

    }

    cout<<mid;


 return 0;

}
/*
    if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
        low++;
        high--;
        continue;
    }


    just by adding this we can shrink the space to remove ambiguity
*/