#include <bits/stdc++.h>
using namespace std;

int main()
{
  
  int arr[]={5,3,7,1,2};
  int n =5;

  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;


  // for(int i=1; i<n; i++){
  //   int j = i;
        
  //   while( j>=1 && arr[j]<arr[j-1] ){
  //     swap (arr[j],arr[j-1]);
  //     j--;
  //   }

  // }


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//    5 3 7 1 2 

//      i = 1: 5 > 3 → swap → [3 5 7 1 2]

//      i = 2: 5 < 7 → no swap

//      i = 3: 7 > 1 → swap → [3 5 1 7 2] → 5 > 1 → swap → [3 1 5 7 2] → 3 > 1 → swap → [1 3 5 7 2]

//      i = 4: 7 > 2 → swap → [1 3 5 2 7] → 5 > 2 → swap → [1 3 2 5 7] → 3 > 2 → swap → [1 2 3 5 7]

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

  // Insertion sort using shifting


  for (int i = 1; i < n; i++) {

    int key = arr[i];       // element to insert
    int j = i - 1;

    // shift elements greater than key to the right
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    
    arr[j + 1] = key;   // place key at the correct position
  }



  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  
  cout<<endl;


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// arr = {5, 3, 7, 1, 2}


// Step 1: i = 1 → key = 3
// Compare with previous: 5 > 3 → shift 5 → [5, 5, 7, 1, 2]
// j moves to -1 → stop
// Place key at j+1 = 0 → [3, 5, 7, 1, 2]


// Step 2: i = 2 → key = 7
// Compare with previous: 5 > 7? No → stop
// Place key at j+1 = 2 (same place) → [3, 5, 7, 1, 2]


// Step 3: i = 3 → key = 1
// Compare with previous: 7 > 1 → shift 7 → [3, 5, 7, 7, 2]
// Compare with 5 > 1 → shift 5 → [3, 5, 5, 7, 2]
// Compare with 3 > 1 → shift 3 → [3, 3, 5, 7, 2]
// j = -1 → stop → place key at j+1 = 0 → [1, 3, 5, 7, 2]


// Step 4: i = 4 → key = 2
// Compare with 7 > 2 → shift 7 → [1, 3, 5, 7, 7]
// Compare with 5 > 2 → shift 5 → [1, 3, 5, 5, 7]
// Compare with 3 > 2 → shift 3 → [1, 3, 3, 5, 7]
// Compare with 1 > 2? No → stop → place key at j+1 = 1 → [1, 2, 3, 5, 7]



 return 0;

}  

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// IMP POINTS------------------>


//  TC in three cases---->

//     worst case--> O(n^2)
//     avg case--> O(n^2)          // but its actually is O ( (n^2) /2)  equivalent to O(n^2)
//     best case--> O(n)


//     Insertion sort is stable sort i.e relative order of elemnt is maintained
    
//     no. of swaps = n*(n-1) / 2           // in worst case


// Shift-based insertion sort is more efficient in terms of 
// assignments, especially for large arrays.
// The number of comparisons stays the same, but shifting avoids repeated swaps.


