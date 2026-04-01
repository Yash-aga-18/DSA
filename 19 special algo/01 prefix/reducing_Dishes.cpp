#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1402  Reducing Dishes  (return maximum total)
// Dish can be prepared in any order also he can discard any of them dishes

// Input: [-1,-8,0,5,-9]
// Output: 14
// Explanation: After Removing the second and last dish, 
// the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14)

void dishes2 ( vector<int>& arr){

    int n = arr.size();
    sort(arr.begin(), arr.end());

    int total = 0;  // final max score
    int sum = 0;    // running sum of selected dishes
    
    // Step 2: Iterate from largest value backward
    // Keep taking dishes while beneficial
    for(int i = n-1; i >= 0; i--) {

        sum += arr[i];  // add current dish

        // If adding this dish makes partial sum negative,
        // stop because earlier numbers are even smaller.
        
        if(sum < 0) break;

        total += sum;  // accumulate contribution

    }

    cout<< total;

}




void dishes1 ( vector<int>& arr){

    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<int> suff(n);

    suff[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        suff[i] = suff[i+1]+arr[i];
    }


    int idx = -1;
    for(int i=0; i<n; i++){
        if(suff[i]>=0){
            idx = i;
            break;
        }
    }


    if(idx==-1){

        cout<<"0";
        return;
    }

    
    int x = 1;
    int ans = 0;
    for(int i = idx; i<n; i++){
        ans += arr[i]*x; 
        x++;
    }
    cout<<ans;
    
}
// concept used --> first sort arr to always use +ve and make a suffix arr 
// find the first elemnt from left which is non-negative(including zero)
// using idx we start multiply and add them one by one 

int main()
{

    vector<int> arr ={-1,-8,0,5,-9};

    for(int ele:arr)    cout<<ele<<" ";         // print  arr
    cout<<endl;
    
    // dishes1(arr);
    dishes2(arr);

 return 0;

}