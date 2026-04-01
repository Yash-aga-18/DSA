#include <bits/stdc++.h>
using namespace std;

// find max elemnt in arr using and without third variable

int print_max1(int arr[],int n, int idx, int ans){        //using 3rd variable
    
    if(idx==n)  return ans;

    if(arr[idx]>ans)    ans = arr[idx];
    return print_max1( arr, n, idx+1, ans);

}


int print_max2(int arr[],int n, int idx){               //without using 3rd variable
    
    if(idx==n)  return INT_MIN;

    return max( arr[idx], print_max2(arr, n, idx+1) );

}


int main()
{
    
    int arr[] = {5,7,589,54,2,4,69,47};
    int n = sizeof(arr)/sizeof(arr[0]); 

    int ans = print_max1( arr,n, 0, INT_MIN);
    cout<<ans<<endl;

    ans = print_max2( arr,n, 0);
    cout<<ans<<endl;
    
 return 0;

}