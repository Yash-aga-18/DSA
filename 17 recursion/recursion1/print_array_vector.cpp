#include <bits/stdc++.h>
using namespace std;

void display_arr(int arr[],int n, int idx){
    
    if(idx==n)  return;

    cout<<arr[idx]<<" ";
    display_arr( arr, n, idx+1);

}


void display_vector(const vector<int>&v, int idx){
    
    if(idx==v.size())  return;

    cout<<v[idx]<<" ";
    display_vector( v, idx+1);

}


int main()
{
    
    int arr[] = {5,7,589,54,2,4,69,47};
    int n = sizeof(arr)/sizeof(arr[0]); 

    display_arr(arr,n,0);
    cout<<endl;
    
    vector<int>v(n);
    for(int i=0; i<n; i++)      v[i]=arr[i];        // push all the elemnt to vector

    display_vector(v,0);   



 return 0;

}