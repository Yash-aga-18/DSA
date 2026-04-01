#include <bits/stdc++.h>
using namespace std;

// in selection sort the smallest element is sorted the first at leftmost place (generally)
// you have to swap the current elemnt with the min element

int main()
{
    int arr[]={1,2,4,0,2};
    int n = 5;
  
    for(int ele: arr){               //prints the array
        cout<<ele<<" ";
    }
    cout<<endl;


    for(int i=0; i<n-1; i++){

        int minidx = i;
        for(int j=i+1; j<n; j++){

            if(arr[j] < arr[minidx]){
                minidx = j;
            }

        }

        if (minidx != i)   swap(arr[i], arr[minidx]);   // only swap when needed
    }


    for(int ele: arr){               //prints the array
        cout<<ele<<" ";
    }
    cout<<endl;


  return 0;

}

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// IMP POINTS------------------>


//  TC in three cases---->      (it can't be optimized)

//     worst case--> O(n^2)
//     avg case--> O(n^2)         
//     best case--> O(n^2)


//   Selection sort is unstable sort i.e relative order of elemnt is not maintained
    
//   no. of swaps = (n-1)           // in worst case
//  bubble sort is much better than this but selection wins --> only in no. of swaps
// it is used when we required some startng elemnts as minimum   eg--> give first three min elemnts of an array 

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//   5 3 7 1 2


//      Pass 1 (i = 0):
//      Look for min in [5, 3, 7, 1, 2]
//      Min = 1 at index 3
//      Swap arr[0] and arr[3]
//      → 1 3 7 5 2

//      Pass 2 (i = 1):
//      Look for min in [3, 7, 5, 2]
//      Min = 2 at index 4
//      Swap arr[1] and arr[4]
//      → 1 2 7 5 3

//      Pass 3 (i = 2):
//      Look for min in [7, 5, 3]
//      Min = 3 at index 4
//      Swap arr[2] and arr[4]
//      → 1 2 3 5 7

//      Pass 4 (i = 3):
//      Look for min in [5, 7]
//      Already sorted, no swap

//      Pass 5 (i = 4):
//      Only one element left, nothing to do
