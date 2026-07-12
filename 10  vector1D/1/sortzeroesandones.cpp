#include <bits/stdc++.h>
using namespace std;

void sort01(vector<int>&v){
   int n = v.size();
   int noz=0;
   int noo=0;

   for(int i=0; i<v.size(); i++){
      if(v[i]==0) noz++;
      else noo++;
   } 
   
   for(int i=0; i<n; i++){
      if(i<noz) v[i]=0;
      else v[i]=1;
   }

}


void sort01m2(vector<int>&v){       // 2pointer approach
   int n=v.size();
   int i=0;
   int j=n-1;

    while(i<j){
      
      if(v[i]==0) i++;
      if(v[j]==1) j--;

      else if(v[i]==1 && v[j]==0) {                  // swap the values   
         swap(v[i],v[j]);
         i++;
         j--;
      }
   }
}



int main()
{
 vector<int>v;

 v.push_back(0); 
 v.push_back(1); 
 v.push_back(0); 
 v.push_back(0); 
 v.push_back(1); 
 v.push_back(1); 
 v.push_back(0); 
 v.push_back(1); 
  
 for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
 } 
  cout<<endl;

 //  sort(v.begin(),v.end());
 //  for(int i=0; i<v.size(); i++){
 //     cout<<v[i]<<" ";
 //  } 

  
//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // two pass method

//  sort01(v);
//   for(int i=0; i<v.size(); i++){
//      cout<<v[i]<<" ";
//   } 


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// //  one pass method              using two pointers

 sort01m2(v);
   
   for(int i=0; i<v.size(); i++){
     cout<<v[i]<<" ";
   } 


 return 0;

}