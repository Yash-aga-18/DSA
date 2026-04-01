#include <bits/stdc++.h>
using namespace std;

// leetcode Q->14
// return the longest prfix in string

int main()
{
  
  vector<string>v;
  v.push_back("flower");
  v.push_back("flow");
  v.push_back("flee");

  int n= v.size();
  sort(v.begin(),v.end());
  
  if(v.size()==1){
    cout<<v[0];
  }
  else{

    string first = v[0];
    string last = v[n-1];
    string s = "";

    // we have to simply compare only first and last as 
    // whole vector is sorted, in middle of first and last lexiographically
    
    for( int i=0; i<(min( first.size(),last.size() )); i++){     

      if(first[i]==last[i]){
        s+=first[i];                                   //  + operator used to concatenate
      }
      else  break;

    }

    cout<<s;
    
  }


 return 0;

}