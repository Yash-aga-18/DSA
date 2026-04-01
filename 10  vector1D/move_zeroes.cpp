#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, move all 0's to 
// the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Input: nums = [0,1,0,3,12]
// Output:       [1,3,12,0,0]


int main()
{
    
    int n;
    cout<<"enter the size of array  ";
    cin>>n;

    vector<int>v(n);
    
    cout<<"enter the array \n";
    for(int i=0; i<n; i++)  cin>>v[i];                      // taking input 
          
    for(int i=0; i<n; i++)   cout<<v[i]<<" ";              // prints the input
    cout<<endl;   
           
    int j = 0;

    for(int  i=0; i<v.size(); i++){
        
        if(v[i]!=0){

            if(i!=j)    swap(v[j],v[i]);  // to avoid unnecessary swappings
            j++;
        }
    }
    
    for(int i=0; i<n; i++)   cout<<v[i]<<" ";              // prints the input



 return 0;

}
/*
 j rukega 0 par and i non-zero ko dhundega

*/