#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n,num;

  cout<<"enter the size of array"<<endl;
  cin>>n;

  int arr[n];
  cout<<"enter your array"<<endl;
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  cout<<"enter the element "<<endl;
  cin>>num;

  bool flag=false;    
  for(int i=0; i<n; i++){
    if(arr[i]==num)  {
      cout<<"element found at index "<<i<<endl;
      flag=true;
      break;
    }
  }
    if (flag)  cout<<" found";                   // it executes if flag is true
    if (!flag)  cout<<"not found";              // it executes if flag is false



 return 0;

}