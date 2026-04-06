#include <bits/stdc++.h>
using namespace std;

// leetcode Q->49  Group Aangrams
// group all the same angrams together


vector<vector<string>> groupAnagrams(vector<string>& arr) {
        
    unordered_map<string, vector<string>> mp;

    for(int i = 0; i < arr.size(); i++){

        string str = arr[i];
        sort(str.begin(), str.end());

        // check if key exists
        if(mp.find(str) != mp.end()) {
            
            vector<string> temp = mp[str];   // copy existing vector
            temp.push_back(arr[i]);          // add new word
            mp[str] = temp;                 // store back

        }
        else {

            vector<string> temp;
            temp.push_back(arr[i]);
            mp[str] = temp;
        }

    }


    vector<vector<string>> result;
    for(auto ele : mp)  result.push_back(ele.second);
    

    return result;
}



int main() {

    vector<string> arr = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = groupAnagrams(arr);

    // print result
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}