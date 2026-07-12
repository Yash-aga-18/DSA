#include <bits/stdc++.h>
using namespace std;

// leetcode Q->75
//  // sort the array of  0,1,2

void sort01 (vector<int>&v){
  int no0=0;
  int no1=0;
  int no2=0;
    
  for(int i=0; i<v.size(); i++){
    if(v[i]==0)      no0++;
    else if(v[i]==1) no1++;
    else             no2++;
  }
  
  for(int i=0; i<v.size(); i++){
    if(i<no0)            v[i]=0;
    else if(i<(no0+no1)) v[i]=1;
    else                 v[i]=2;
  }
    
}



void sortdutch (vector <int>&v) {
  int  n = v.size();
  int  low = 0;
  int  mid = 0;
  int  high = n-1;

  while(mid<=high){

    if(v[mid]==0){
      swap(v[low],v[mid]);
      low++;
      mid++;
    }

    else if(v[mid]==2){
      swap(v[mid],v[high]);
      high--;
    }

    else mid++;

  }
}    


int main()
{

  int x,n;
 vector<int>v;
  
  cout<<"enter the size of array  ";
  cin>>x;
  cout<<"enter the array \n";
  
  for(int i=0; i<x; i++){                         // taking input 
    cin>>n;       
    v.push_back(n);       
  }       
       
  
  for(int i=0; i<v.size(); i++){                  // prints the input
    cout<<v[i]<<" ";       
  }       
  cout<<endl;       
 
  
// // two pass method 

//   sort01(v);
  
//   for(int i=0; i<v.size(); i++){
//     cout<<v[i]<<" ";
//  }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //  // dutch flag method   or   3 pointer method  or one pass method

 sortdutch(v);

  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
 }
  


 return 0;

}