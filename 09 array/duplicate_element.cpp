#include <bits/stdc++.h>
using namespace std;

// Given an array of size n+1. One element is duplicate in the array. Find it.

int main()
{
//   there are 3 methods to solve it

// 1--> find one by one elemnt using 2 nested loops
// 2--> create a vector of same size by putting all initals to 0   and push_back() one by one based on their index value
//      and update it to 1 any elemnt whose value is 2 is that duplicate element

// 3--> using some mathematics
  
int arr[8]={5,7,4,6,2,1,3,1};

int sum =0;
int n = sizeof(arr)/sizeof(arr[0]) -1 ;

for(int i=0; i<n+1; i++){
    sum += arr[i];
}

int s = n*(n+1)/2;

cout<<sum-s;
  
  
return 0;

}