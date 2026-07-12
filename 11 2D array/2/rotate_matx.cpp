#include <bits/stdc++.h>
using namespace std;
// leetcode Q->48 
// to rotate a given n*n array by 90 degree
//  1 2 3           7 4 1
//  4 5 6   -->     8 5 2 
//  7 8 9           9 6 3

int main()
{
  int n;
  
  cout<<"enter value of n"<<endl;
  cin>>n;
  
  vector<vector<int>>arr1(n,vector<int>(n));

  cout<<"enter the elemnts of mtx"<<endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>arr1[i][j];
    }
  }

  for(int i=0; i<n; i++){                   // prints the mtx
    for(int j=0; j<n; j++){
      cout<<arr1[i][j]<<" ";
    }
    cout<<endl;
  }
   
  cout<<endl;

// step 1--> make transpose of the mtx
 
  for(int i=0; i<n; i++){               // make changes in existing array             
    for(int j=i+1; j<n; j++){

     swap(arr1[i][j],arr1[j][i]);
 
    }
  }

   
// step 2--> reverse elemnts of each row

  for (int i = 0; i < n; i++) {
    reverse(arr1[i].begin(), arr1[i].end());
  }



  cout<<"after rotation -->"<<endl;
    
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){   

      cout<<arr1[i][j]<<" ";
    }
    cout<<endl;
  }
   
 
  

 return 0;

}

// for clockwise rotation       do step-1 then step-2
// for anti-clockwise rotation  do step-2 then step-1