#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1  Two sum

int main()
{
 
  int x,n;
 vector<int>v;

 cout<<"enter size of array :";
 cin>>n;

  cout<<"enter array"<<endl;
  for(int i=0; i<n; i++) {
    int val;
    cin>>val;
    v.push_back(val);
  }

  cout<<"enter target : ";
  cin>>x;
  cout<<endl;

  
  for(int i=0; i<v.size()-1; i++){
    for(int j=i+1; j<v.size(); j++){

      if(v[i]+v[j]==x)    cout<< "(" <<i<< "," <<j<< ")" <<endl;
      
    }
  }

  
 return 0;

}