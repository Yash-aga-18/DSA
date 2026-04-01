#include <bits/stdc++.h>
using namespace std;

// Find a subarray which have maxinmum sum of length is k

void subarraySum1(vector<int>& arr, int k) {
    
    int n = arr.size();
    int maxSum = INT_MIN;
    int start_idx = -1;
    
    for(int i=0; i<=n-k; i++){
        int sum = 0;
        
        for(int j=i; j<i+k; ++j){
            sum += arr[j];
        }

        if(sum>maxSum){
            maxSum = sum;
            start_idx = i;
        }
    }

    cout << "Max sum = " << maxSum << endl;
    cout<<"from index "<<start_idx<<" to "<<start_idx+k-1;
    
}
// Time Complexity: O(n*k)   Space Complexity: O(1)




void subarraySum2(vector<int>& arr, int k) {
    
    int n = arr.size();
    
    int currSum = 0;
    for(int i = 0; i < k; i++)   currSum += arr[i];

    int maxSum = currSum;
    int end = 0;

    // sliding window
    for(int high = k; high < n; high++){
        int low = high-k+1;

        currSum += arr[high] - arr[low-1];     //add new incoming elemnt and remove the leftmost elmnt

        if(currSum > maxSum){
            maxSum = currSum;
            end = high;
        }
    }

    cout << "Max sum = " << maxSum << endl;
    cout << "From index " << end-k+1 << " to " << end << endl;
}

// Time Complexity: O(n)   Space Complexity: O(1)



int main()
{
    
    vector<int>arr = {7,1,2,5,8,4,9,3,6};
    int k = 3;

    // subarraySum1(arr,k);
    subarraySum2(arr,k);



 return 0;

}