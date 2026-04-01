#include <bits/stdc++.h>
using namespace std;


void mergeParts(vector<int>& v, int low, int mid, int high) {
    
    vector<int> temp;   
    
    int left  = low;       
    int right = mid + 1;     

    while(left <= mid && right <= high) {

        if(v[left] <= v[right])     temp.push_back( v[left++] );
        else                        temp.push_back( v[right++] );
        
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


int main() {
    
    vector<int> v = {5, 1, 3, 4, 9, 7, 6};
    int n = v.size();


    cout << "Before sorting: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    mergeSort(v, 0, n-1);

    cout << "After sorting:  ";
    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}



//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// IMP POINTS------------------>


//  TC in three cases---->

//     worst case--> O(n logn)
//     avg case-->   O(n logn)   
//     best case-->  O(n logn)


//     merge sort is stable sort   i.e relative order of elemnt is maintained
    

//    Not in-place: Merge Sort (standard version)
//    It uses extra space: O(n logn)  → Because merging requires temporary arrays for both halves.

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*

Dry Run Example:  v = [5, 3, 7, 1, 2]

📌 Why do we write arr[i] = temp[i - low]?

The temp array always starts from index 0 because it is newly created during each merge.
But in the original array, the sorted section we are replacing can start at any index (because merge sort is recursive).
Example: if merge is happening for indexes 3 to 6, then sorted values in temp belong to array positions 3, 4, 5, 6.
Since temp starts at index 0, we subtract low to match the correct value.
So when i = 3 (first position), i - low = 3 - 3 = 0, meaning we copy temp[0] into arr[3].


Final Sorted Output → [1, 2, 3, 5, 7]

*/