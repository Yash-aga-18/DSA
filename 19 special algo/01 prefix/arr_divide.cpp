#include <bits/stdc++.h>
using namespace std;

//  given an array of integers. Your task is to determine whether there exists
//  an index i such that the sum of all elements to the 
//  left of i is equal to the sum of all elements to the right of i




void divide(vector<int>& arr){

    int n = arr.size();
    vector<int> pre = arr; // keep original array safe

    // create prefix sum
    for(int i = 1; i < n; i++){
        pre[i] += pre[i - 1];
    }

    cout << "Prefix array: ";
    for(int ele : pre) cout << ele << " ";
    cout << endl;

    int low = 0, high = n-1;
    int total = pre[n-1];

    while(low <= high){
        
        int mid = low + (high - low)/2;

        if(2 * pre[mid] == total){

            cout << "Balanced point found at index " << mid << endl;
            cout << "Value = " << arr[mid] << endl;
            return;
        }

        else if(2 * pre[mid] < total)   low = mid + 1;
        else                            high = mid - 1;
    }

    cout << "No equal partition index exists.";
}





int main()
{

    vector<int> arr = {1,2,3,4,5,5};
    int n = arr.size();

    for(int ele:arr)    cout<<ele<<" ";     //print initial
    cout<<endl;

    divide(arr);

 return 0;

}
