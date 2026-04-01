#include <bits/stdc++.h>
using namespace std;
// we can find kth (smallest or largest) using selecton,buuble or insertion
// but their TC is O(n*k)  and for merge sort TC is O(n*logn) 
// but using quick sort we can done in   TC is O(n) as we dont require to sort them all 


int partition(vector<int>& arr, int low, int high) {   // taking middle elemnt as pivot

    int mid = low + (high - low) / 2;

    // move middle pivot to first position for consistency
    swap(arr[low], arr[mid]);
    int pivot = arr[low];

    int i = low;
    int j = high;

    while(i < j) {

        while(arr[i] <= pivot && i < high)   i++;
        while(arr[j] > pivot  && j > low)    j--;

        if(i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}


int kthSmallest(vector<int>& arr, int low, int high, int k) {

    if(low <= high) {

        int pivot_Index = partition(arr, low, high);

        if(pivot_Index == k)            return arr[pivot_Index];
        else if(pivot_Index < k)        return kthSmallest(arr, pivot_Index+1, high, k);
        else                            return kthSmallest(arr, low, pivot_Index-1,  k);
    }

    return -1;      // only if invalid input
}


int main()
{
    
    vector<int>v = {5,1,3,4,9,7,6};
    int n = v.size();
    int k = 5;
    
    for(int ele : v)    cout<<ele<<" ";
    cout<<endl;

   cout<< kthSmallest(v, 0, n-1, k-1) << endl; 

  return 0;

}

// here we pass (k-1) so that it matches the 0 based indexing
   
//  cout<< kth_Largest(v, 0, n-1, n-k) << endl;             
//  6th smallest equivalent to 2nd largest   as  7-6+1 = 2     // in terms of 1based indexing
//  6th smallest equivalent to 2nd largest   as  7-6 = 1       // in terms of 0based indexing
