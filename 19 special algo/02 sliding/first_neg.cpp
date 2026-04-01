#include <bits/stdc++.h>
using namespace std;

//  find first negative elemnt in window size k.

vector<int> find_neg(vector<int> arr, int k){

    int n = arr.size();
    vector<int> ans;

    int first_neg_idx = -1;

    // Process first window
    for(int i = 0; i < k; i++){

        if(arr[i] < 0){
            first_neg_idx = i;
            break;
        }

    }

    // Push result for the first window
    if(first_neg_idx == -1) ans.push_back(0);
    else                    ans.push_back(arr[first_neg_idx]);


    // Slide the window
    for(int high = k; high < n; high++){
        int low = high-k+1;

        // If the previous negative is still in the window, use it
        if(first_neg_idx >= low)    ans.push_back(arr[first_neg_idx]);
        
        else{       // Otherwise find a new negative in this window
            
            first_neg_idx = -1;
            for(int i = low; i <= high; i++){
                if(arr[i] < 0){
                    first_neg_idx = i;
                    break;
                }
            }

            if(first_neg_idx == -1) ans.push_back(0);
            else                    ans.push_back(arr[first_neg_idx]);
        }

    }


    return ans;
    
}


int main()
{
    
    vector<int>arr = {2,-3,4,-4,-7,-1,4,2,6};
    int k = 3;

    vector<int>answer = find_neg(arr,k);

    for(int ele : answer) cout<<ele<<", ";

 return 0;

}