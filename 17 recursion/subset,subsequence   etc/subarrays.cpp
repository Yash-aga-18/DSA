#include <bits/stdc++.h>
using namespace std;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Ques--> print subarrays of k length

// vector<vector<int>> subarray(vector<int>& arr, int k) {

//     vector<vector<int>> result;
//     int n = arr.size();

//     for (int start = 0; start <= n - k; start++) {      // start can go last upto only last kth elemnt
//         vector<int> subarray;

//         for (int i = start; i <= start + k - 1;  i++) {     // can push only k elements
//             subarray.push_back(arr[i]);
//         }

//         result.push_back(subarray);
        
//     }

//     return result;
// }


// int main() {

//     vector<int> arr = {1, 2, 3, 4, 5};
//     int k = 2;
//     vector<vector<int>> output = subarray(arr, k);


//     for (vector<int> subset : output) {         // Print all 

//         cout << "[";
//         for (int i = 0; i < subset.size(); ++i) {
//             cout << subset[i];
//             if (i != subset.size() - 1) cout << ",";    // to exclude last
//         }
//         cout << "]" << endl;

//     }

//     return 0;
// }


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Ques--> Prints all the possible subarrays

vector<vector<int>> subarray(vector<int>& arr) {
    
    vector<vector<int>> result;
    int n = arr.size();

    for (int start = 0; start < n; start++) {
        
        vector<int> subarray;

        for (int i = start; i < n; ++i) {
            subarray.push_back(arr[i]);
            result.push_back(subarray);                 // copy of current subarray
        }

    }

    return result;
    
}



int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<vector<int>> output = subarray(arr);


    for (vector<int> subset : output) {         // Print all 

        cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ",";    // to exclude last
        }
        cout << "]" << endl;

    }

    return 0;
}