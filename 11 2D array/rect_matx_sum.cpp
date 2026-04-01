#include <bits/stdc++.h>
using namespace std;

// You are given a 2D matrix of size m x n filled with integers. 
// Then, you are given two coordinates (l1, r1) and (l2, r2)
// which represent the top-left and bottom-right corners of a rectangle inside the matrix.
// Your task is to find the sum of all elements inside that rectangle


int main()
{
    int m,n;
  
    cout<<"enter value of m,n"<<endl;
    cin>>m;
    cin>>n;

    
    int arr[m][n];
  
    cout<<"enter the elemnts of mtx"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
  
    for(int i=0; i<m; i++){                   // prints the mtx
        for(int j=0; j<n; j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int sum = 0;
    int l1,r1,l2,r2;

    cout<<"enter the values of (l1,r1)"<<endl;
    cin>>l1;
    cin>>r1;

    cout<<"enter the values of (l2,r2)"<<endl;
    cin>>l2;
    cin>>r2;
      
    for(int i=l1; i<=l2; i++) {
        for(int j=r1; j<=r2; j++) {
            
            sum += arr[i][j];
        }

    }
    cout<<sum;

 return 0;

}