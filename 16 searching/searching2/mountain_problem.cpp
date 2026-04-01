#include <bits/stdc++.h>
using namespace std;

// leetcode Q->852
// return index of MAX elemnt in mountain array         eg--> 1 3 5 4 2 1

int main()
{
    
    int arr[]={3,5,3,2,0};
    int n = 5;
    
    int low = 0;
    int high = n-1;
    int mid = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        // Check if mid is the peak
        if ((mid == 0 || arr[mid-1] < arr[mid]) && (mid == n-1 || arr[mid+1] < arr[mid]) ){
            break;
        } 

        // If slope is ascending, move right
        else if (mid < n-1 && arr[mid] < arr[mid+1])    low = mid + 1;
        
        else high   = mid-1;        // If slope is descending, move left
            
    }
    
    cout<<mid;


 return 0;

}