#include <bits/stdc++.h>
using namespace std;


// leetcode Q->493   return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].


// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1



long long cnt = 0;

void mergeParts(vector<int>& v, int low, int mid, int high){

    vector<int> temp;

    // ---------------------------------------------------------
    // Count reverse pairs BEFORE merging (important)
    // ---------------------------------------------------------
    int j = mid+1;

    for(int i = low; i <= mid; i++){
        while(j <= high && (long long)v[i] > 2LL * v[j]){
            j++;
        }
        cnt += (j - mid-1);
    }

    // ---------------------------------------------------------
    // Standard merge logic (like merge sort)
    // ---------------------------------------------------------
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


void mergeSort(vector<int>& v, int low, int high){

    if(low >= high) return;

    int mid = (low + high) / 2;

    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);

    mergeParts(v, low, mid, high);
}


int main(){

    vector<int> v = {1, 3, 2, 3, 1};
    
    cout << "Before sorting: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    mergeSort(v, 0, v.size() - 1);

    cout << "After sorting:  ";
    for(int x : v) cout << x << " ";
    cout << endl;

    cout << "Total reverse pairs are: " << cnt << endl;

    return 0;
}