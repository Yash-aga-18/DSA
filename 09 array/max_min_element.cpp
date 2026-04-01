#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n,num,max,min;

  cout<<"enter the size of array: ";
  cin>>n;

  int arr[n];
  cout<<"enter your array: "<<endl;
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  max=min=arr[0];
  // or we can initialize it as    max=INT_MIN    min=INT_MAX    
  // use header file #include<climits>
    
  for(int i=0; i<n; i++){
    if(arr[i]>max)     max=arr[i];
    if(arr[i]<min)     min=arr[i];
  }
    
  int smax=INT_MIN;
  int smin=INT_MAX;

  for(int i=0; i<n; i++){

   if(arr[i]>smax && arr[i]!=max)   smax=arr[i];
   if(arr[i]<smin && arr[i]!=min)   smin=arr[i];

  }
  cout<<"max-->"<<max<<" min-->"<<min<<endl;
  
  cout<<"second max-->"<<smax<<" second min-->"<<smin;

 return 0;

}