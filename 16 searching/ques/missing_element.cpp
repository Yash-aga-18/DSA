#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1539  kTH MISSING POSITIVE INTEGER

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. 
// The 5th missing positive integer is 9.


int main()
{
   vector<int>arr = {2,3,4,7,11};
   int k = 2;
    
   int low = 0, high = arr.size() - 1;


   while (low <= high) {

      int mid = low + (high - low) / 2;

      int missing = arr[mid] - mid -1;    // count of missing numbers before arr[mid]

      if (missing < k)   low  = mid + 1;
      else               high = mid - 1;
      
   }
   // cout<<< low + k;     // u can return this or u can


   // if k-th missing is before first element
   if (low == 0) {
      cout << k;
      return 0;
   }

   low = low-1;

   int missingBefore = arr[low] - (low) - 1;
   int ans = arr[low] + (k - missingBefore);

   cout << ans;


  
 return 0;

}

/*

   low = low-1;
   int missingBefore = arr[low] - (low) - 1;
   int ans = arr[low] + (k - missingBefore);

   cout << ans;



   on simplifying this-->
   ans = arr[low] + (k - arr[low]  + (low)   + 1);       put value of missingbefore
   ans =            (k             + (low)   + 1);
   ans =            (k             + (low-1) + 1);       as low = low-1
   ans = low+k;



*/