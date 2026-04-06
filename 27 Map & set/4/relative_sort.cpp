#include <bits/stdc++.h>
using namespace std;


// 🔹 Method 1: Ordered Map (map)
vector<int> relativeSort_map(vector<int>& arr1, vector<int>& arr2) {

    int n = arr1.size();

    map<int, int> mp;

    // Step 1: count frequency
    for(int i = 0; i < n; i++){
        
        int ele = arr1[i];
        mp[ele]++;
    }

    vector<int> ans;

    // Step 2: elements from arr2 (priority order)
    for(int i = 0; i < arr2.size(); i++){
        int ele = arr2[i];

        int freq = mp[ele];

        while(freq > 0){
            ans.push_back(ele);
            freq--;
        }

        mp.erase(ele);   // safe here
    }

    // Step 3: remaining elements (sorted because map)
    for(auto ele : mp){
    
        int num  = ele.first;
        int freq = ele.second;

        while(freq > 0){
            ans.push_back(num);
            freq--;
        }
    }

    return ans;
}


// 🔹 Method 2: Unordered Map (Faster)
vector<int> relativeSort_unordered(vector<int>& arr1, vector<int>& arr2) {

    int n = arr1.size();

    unordered_map<int, int> mp;

    // Step 1: count frequency
    for(int i = 0; i < n; i++){
        
        int ele = arr1[i];
        mp[ele]++;
    }

    vector<int> ans;

    // Step 2: elements from arr2 (priority order)
    for(int i = 0; i < arr2.size(); i++){
        int ele = arr2[i];

        int freq = mp[ele];

        while(freq > 0){
            ans.push_back(ele);
            freq--;
        }

        mp.erase(ele);   // safe here
    }

    // collect remaining
    vector<int> remaining;

    for (auto p : mp) {

        int num   = p.first;
        int count = p.second;

        while (count > 0) {
            remaining.push_back(num);
            count--;
        }
    }

    // sort remaining
    sort(remaining.begin(), remaining.end());

    // merge
    for (int x : remaining) {
        ans.push_back(x);
    }

    return ans;
}


int main() {

    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};

    vector<int> ans1 = relativeSort_map(arr1, arr2);
    vector<int> ans2 = relativeSort_unordered(arr1, arr2);

    cout << "Using ordered map:\n";
    for (int x : ans1) cout << x << " ";

    cout << "\n\nUsing unordered map:\n";
    for (int x : ans2) cout << x << " ";

    return 0;
}