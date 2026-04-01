#include <bits/stdc++.h>
using namespace std;

//  to find first neg number of k sized window


int main() {
    
    vector<int> arr = {0, -1, -2, 3, 4, -5, 6, 4, 7, -8};
    int k = 3;
    int n = arr.size();

    vector<int> ans;
    queue<int> q;

    // store indices of negative numbers
    for(int i = 0; i < n; i++){
        if(arr[i] < 0) q.push(i);
    }

    int i = 0;

    while(i <= n-k){

        // remove indices that are out of window
        while(q.size() > 0 && q.front() < i){
            q.pop();
        }

        // check if negative number exists inside window
        if(q.size() == 0 || q.front() >= i + k)     ans.push_back(0);
        else                                        ans.push_back(arr[q.front()]);
        
        i++;
    }

    // print original array
    cout << "Array: ";
    for(int ele :arr){
        cout << ele << " ";
    }

    cout << endl;

    // print result
    cout << "First -ve in each window: ";
    for(int ele :ans){
        cout << ele << " ";
    }

    cout << endl;

    return 0;
    
}