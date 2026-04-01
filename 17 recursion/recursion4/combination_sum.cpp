#include <bits/stdc++.h>
using namespace std;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// // leetcode Q->39  Combination Sum I

// //  array of distinct integers and a target
// //  return a list of all unique combinations of elemnts of arr where the chosen numbers 
// //  sum to target. You may return the combinations in any order.
// //  The same number may be chosen from arr unlimited number of times.
// //   Input: candidates = [2,3,5], target = 8
// //   Output: [  [2,2,2,2], [2,3,3], [3,5] ] 



// void backtrack(vector<int>& arr, int target, vector<int>& v, vector<vector<int>>& result, int idx) {

//     if (target == 0) {
//         result.push_back(v);
//         return;
//     } 

//     if (target < 0)   return;


//     for (int i = idx; i < arr.size(); i++) {

//         v.push_back(arr[i]);
//         backtrack(arr, target-arr[i], v, result, i);
//         v.pop_back();

//     }

// }


// vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    
//     vector<int> v;
//     vector<vector<int>> result;

//     backtrack(arr, target, v, result, 0);

//     return result;
// }


// int main() {
    
//     vector<int> arr = {2,3,5};
//     int target = 8;

//     vector<vector<int>> output = combinationSum(arr, target);

    
//     for (vector<int> subset : output) {      // Print all 

//         cout << "[";
//         for (int i = 0; i < subset.size(); ++i) {
//             cout << subset[i];
//             if (i != subset.size() - 1) cout << ",";    // to exclude last
//         }
//         cout << "]" << endl;
//     }

//  return 0;

// }


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


// // leetcode Q->40  Combination Sum II (same no. can't be repeated)

// //  array of distinct integers and a target
// //  return a list of all unique combinations of elemnts of arr where the chosen numbers 
// //  sum to target. You may return the combinations in any order. without repeating the elemnt
// //   Input: candidates = [10,1,2,7,6,1,5], target = 8
// //   Output:  [ [1,1,6], [1,2,5], [1,7], [2,6] ]


// void backtrack(vector<int>& arr, int target, vector<int>& v, vector<vector<int>>& result, int idx) {

//     if (target == 0) {
//         result.push_back(v);
//         return;
//     }
//     if (target < 0)   return;


//     for (int i = idx; i < arr.size(); i++) {
        
//         if (i>idx && arr[i] == arr[i-1])       continue;      // to skips the repeated

//         v.push_back(arr[i]);
//         backtrack(arr, target-arr[i], v, result, i+1);
//         v.pop_back();

//     }

// }


// vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    
//     vector<vector<int>> result;
//     vector<int> v;
//     sort(arr.begin(),arr.end());

//     backtrack(arr, target, v, result, 0);

//     return result;
// }


// int main()
// {
    
//     vector<int> arr = {2,3,5};
//     int target = 8;

//     vector<vector<int>> output = combinationSum(arr, target);
    
//     for (vector<int> subset : output) {     // Print all 

//         cout << "[";
//         for (int i = 0; i < subset.size(); ++i) {
//             cout << subset[i];
//             if (i != subset.size() - 1) cout << ",";    // to exclude last
//         }
//         cout << "]" << endl;
//     }

//  return 0;

// }



//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


// // leetcode Q->216  Combination Sum III (same no can't be repeated and from 1 to 9)

// //  Only numbers 1 through 9 are used and return a list of all unique combinations of elemnts of arr
// //  where the chosen numbers sum to target. of specific length 
// //  You may return the combinations in any order. without repeating the elemnt
// //   Input: k = 3, n = 7
// //   Output: [[1,2,4]]


void backtrack(vector<int>& arr, int target, vector<int>& v, vector<vector<int>>& result, int idx, int k) {

    if (target == 0 && v.size()==k) {
        result.push_back(v);
        return;
    }
    if (target<0 || v.size()>k )   return;


    for (int i = idx; i < arr.size(); i++) {              // or run the loop--->   int i = idx; i<9; i++ 
        
        v.push_back(arr[i]);
        backtrack(arr, target-arr[i], v, result, i+1, k);
        v.pop_back();

    }

}


vector<vector<int>> combinationSum(vector<int>& arr, int target, int k) {
    
    vector<int> v;
    vector<vector<int>> result;

    backtrack(arr, target, v, result, 0, k);

    return result;
}


int main()
{
    
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int target = 8;
    int k = 3;

    vector<vector<int>> output = combinationSum(arr, target, k);
    
    for (vector<int> subset : output) {     // Print all 

        cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i != subset.size() - 1)  cout<< ",";    // to exclude last
        }
        cout << "]" << endl;
        
    }

 return 0;

}
