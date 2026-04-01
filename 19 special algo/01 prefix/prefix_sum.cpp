#include <bits/stdc++.h>
using namespace std;
// leetcode Q->1480  running sum 1D  

// Input:  [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
// solve in     TC O(n) and SC O(n) or O(1)



void prefix_sum1(vector<int>& arr){         // creating extra space

    vector<int> pre;
    int sum = 0;

    for(int i =0; i<arr.size(); i++){
        
        sum += arr[i];
        pre.push_back(sum);

    }

    for(int ele:pre)    cout<<ele<<" ";
    cout<<endl;

}



void prefix_sum2(vector<int>& arr){         // without creating extra space

    int sum = 0;

    for(int i =0; i<arr.size(); i++){
        
        sum += arr[i];
        arr[i]=sum;
        
    }

    for(int ele:arr)    cout<<ele<<" ";
    cout<<endl;

}



void prefix_sum3(vector<int>& arr){             // most efficient

    for(int i = 1; i<arr.size(); i++)  {        // start from 1 as 1st elemnt always is same 
        arr[i] += arr[i-1];
    }

    for(int ele:arr)    cout<<ele<<" ";
    cout<<endl;

}

void a_and_b(vector<int>& arr, int a, int b){        // only to find between given indices

    for(int i = 1; i<arr.size(); i++)  {            // first calucalate as regular
        arr[i] += arr[i-1];
    }

    cout<< ( arr[b] - arr[a-1] );       // to obtain the sum between 2 indices

}


int main()
{

    vector<int> arr = {5,9,3,4,8,7,6};


  //   prefix_sum1 ( arr);          // creating extra space
  //   prefix_sum2 ( arr);          // without creating extra space
 //    prefix_sum3 ( arr);          // most efficient


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  //    it is mostly used in to find the sum between 2 indices

    a_and_b(arr, 2, 5);


 return 0;

}
