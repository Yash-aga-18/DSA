#include <bits/stdc++.h>
using namespace std;

// An inversion is a pair of indices (i, j) such that:
// i < j and   arr[i] > arr[j]

// eg--->  int arr[] = {5,1,3,4,9,7,6};
// (0,1) → (5 and 1)      (0,2) → (5 and 3)        (0,3) → (5 and 4)  
// (4,5) → (9 and 7)      (4,6) → (9 and 6)  
// (5,6) → (7 and 6)  


int cnt = 0;

void mergeParts(vector<int>& v, int low, int mid, int high) {
    
    vector<int> temp;   
    
    int left  = low;       
    int right = mid + 1;     

    while(left <= mid && right <= high) {

        if(v[left] <= v[right])     temp.push_back( v[left++] );

        else {
            cnt += (mid-left+1);               // only this line is changed
            temp.push_back( v[right++] );
        }
    }
 
    while(left  <= mid)     temp.push_back(v[left++]);
    while(right <= high)    temp.push_back(v[right++]);

    for(int x = low; x <= high; x++) {
        v[x] = temp[x-low];
    } 

}


void mergeSort(vector<int>& v, int low, int high) {
    
    if(low >= high) return;    

    int mid = (low + high) / 2;

    mergeSort( v, low,   mid  );       
    mergeSort( v, mid+1, high);       

    mergeParts(v, low, mid, high);  
}


int main() 
{

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // Method 2--->(merge sort)        T.C is---> O(n logn)   
      
    vector<int> v = {5, 1, 3, 4, 9, 7, 6};
    int n = v.size();


    cout << "Before sorting: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    mergeSort(v, 0, n-1);

    cout << "After sorting:  ";
    for(int x : v) cout << x << " ";
    cout << endl;

    cout<<"Total inversions are: "<<cnt;

  return 0;

}

//  // Method 1--->(brute force)        T.C is---> O(n^2)   
// compare the selected elemnt with all the right elemnts

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Left half:  [2, 5, 7]       Right half: [1, 6, 8]

compare 2 with 1 --> all the elemnts from 2 to last in left is gretaer than 1


*/

// The number of inversions tells you how far the array is from being sorted.

// Sorted array --> 0 inversions.
// Completely reversed array --> maximum inversions = n*(n-1)/2.(using merge sort)