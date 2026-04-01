#include <bits/stdc++.h>
using namespace std;

// vector is pass by value not reference 
// to pass in any function use ampersand &   in function argument 


void change(vector<int>&a){
 a[0]=6;

}


int main() {
  
  vector<int>v;

  v.push_back(6);
  v.push_back(7);
  v.push_back(8);
  v.push_back(9);

  for(int i=0; i<v.size(); i++){
  cout<<v[i]<<" ";
  }
 cout<<endl;

  change(v);

  for(int i=0; i<v.size(); i++){
  cout<<v[i]<<" ";
  }
 cout<<endl;
  
  
 return 0;

}