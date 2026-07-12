#include <bits/stdc++.h>
using namespace std;

// leetcode Q->88
// merge two different sorted arr into the given arr 


int main()
{
  vector<int> nums1 = {10, 11, 12, 13, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};

  int i = nums1.size() - nums2.size() - 1; // last valid element in nums1
  int j = nums2.size() - 1;                // last element in nums2
  int k = nums1.size() - 1;                // last index in nums1

  while (j >= 0){

    if (i >= 0 && nums1[i] > nums2[j]){
      nums1[k] = nums1[i];
      i--;
    }
    
    else {
      nums1[k] = nums2[j];
      j--;
    }

    k--;
    
  }

  for (int x : nums1) {
    cout << x << " ";
  }

  return 0;
}