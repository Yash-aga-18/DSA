#include <bits/stdc++.h>
using namespace std;

// leetcode Q->704 implementing binary search

int main()
{


int n;
cout<<"enter the size of arr"<<endl;
cin>>n;

    int arr[n];

    cout<<"enter array in ascending order "<<endl;          // takes the input
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"your array is "<<endl;              // prints the array
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    int target;                             // target input
    cout<<"enter the target"<<endl;
    cin>>target;


    int low = 0;
    int high = n-1;
    bool flag = false;
    int mid =-1;

    while(low <= high){

    mid = low + (high-low)/2;

        if(arr[mid]==target)  {
            flag = true;
            break;
        }

        if(arr[mid]<target)      low = mid+1;
        if(arr[mid]>target)      high = mid-1;

    }

    if(flag == true)    cout<<"element found at "<<mid;
    else                cout<<"not found";


  return 0;

}
/*

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
IMP POINTS------------------>

works only if arr is sorted

TC in three cases---->

worst case--> O(logn)
avg case--> O(logn)        
best case--> O(1)

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
 Array: 1 2 3 5 7
 Target: 6

 Initial low = 0, high = 4

  Pass 1:
  mid = 0 + (4 - 0) / 2 = 2
  arr[mid] = 3
  3 < 6 → target is on the right → low = mid + 1 =3

  Pass 2:
  low = 3, high = 4
  mid = 3 + (4 - 3) / 2 = 3
  arr[mid] = 5
  5 < 6 → target is on the right → low = mid + 1 =4

  Pass 3:
  low = 4, high = 4
  mid = 4 + (4 - 4) / 2 = 4
  arr[mid] = 7
  7 > 6 → target is on the left → high = mid - 1 =3

  Now, low = 4, high = 3 → low > high → loop exits → Target not found

  
*/


