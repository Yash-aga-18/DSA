#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n, arr[100],sum=0;
  cout<<"enter the no of elemnts"<<endl;
  cin>>n;
  cout<<"enter the elemnts"<<endl;
  
  for(int i=0; i<n; i++){
    cin>>arr[i];
    sum=sum+arr[i];
  }
  cout<<"sum of array is --> "<<sum;



 return 0;

}