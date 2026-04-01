#include <bits/stdc++.h>
using namespace std;

// leetcode Q->33
//  find an elemnt in rotated array     eg--->28,45,1,2,5,7,18,19

int main()
{
    
    int arr[]={28,45,1,2,5,7,18,19};
    int target = 1;
    int n = sizeof(arr)/sizeof(arr[0]);

    int low = 0, high = n-1;
    int mid = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == target)    break;

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