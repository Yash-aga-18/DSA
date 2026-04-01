#include <bits/stdc++.h>
using namespace std;

int partition1(vector<int>& arr, int low, int high) {   // taking first elemnt as pivot
    
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j) {

        while(arr[i] <= pivot && i < high)   i++;  // Move i until we find a value >  pivot
        while(arr[j] > pivot  && j > low)    j--;  // Move j until we find a value <= pivot

        if(i < j) swap(arr[i], arr[j]);           // Swap misplaced elements

    }

    swap(arr[low], arr[j]);
    return j;
}


int partition2(vector<int>& arr, int low, int high) {   // taking middle elemnt as pivot

    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[low], arr[randomIndex]);

    // int mid = low + (high - low) / 2;
    // swap(arr[low], arr[mid]);            // move middle pivot to first position for consistency

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



void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {

        // int pivotIndex = partition1(arr, low, high);            // taking first elemnt as pivot
        
        // int pivotIndex = partition2(arr, low, high);               // taking middle elemnt as pivot
        int pivotIndex = partition2 (arr, low, high);             // taking random elemnt as pivot

        quickSort(arr, low, pivotIndex - 1); 
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {

    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Before sorting: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "After sorting:  ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// IMP POINTS------------------>


//  TC in three cases---->

//     worst case--> O(n logn)
//     avg case-->   O(n logn)   
//     best case-->  O(n^2)


//     quick sort is not stable sort   i.e relative order of elemnt is not maintained
//    in-place: quick Sort (standard version)
//      S.C. is---> O(log n) stack frames

// Middle pivot reduces chance of worst-case partitions & keep it closer to O(n logn)