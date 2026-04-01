#include <bits/stdc++.h>
using namespace std;

// Ques--> print subsequence of k length


void backtrack(vector<int>& arr, int start, vector<int>& path, vector<vector<int>>& result, int k) {

    if (path.size()==k) {           // only this condition is extra for length k
        result.push_back(path);
        return ;   
    }

    for (int i = start; i < arr.size(); i++) {              
        
        if (i > start && arr[i] == arr[i - 1])      continue;       // to skip the duplicate elemnt

        path.push_back(arr[i]);
        backtrack(arr, i+1, path, result, k);
        path.pop_back();

    }

}

vector<vector<int>> subsequence(vector<int>& arr, int k) {

    vector<int> path;
    vector<vector<int>> result;
    
    sort(arr.begin(), arr.end());           // Sort to bring duplicates together
    backtrack(arr, 0, path, result, k);

    return result;

}


int main() {
    
    vector<int> arr = {1,2,3,4};
    int k = 3;                       // let subsequence of length 3

    vector<vector<int>> output = subsequence(arr,k);


    
    for (vector<int> subset : output) {     // Print all 

        cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ",";    // to exclude last
        }
        cout << "]" << endl;

    }

    return 0;
}