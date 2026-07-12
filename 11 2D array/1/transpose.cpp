#include <bits/stdc++.h>
using namespace std;

int main()
{

//   int row,column;
  
//   cout<<"enter row and col"<<endl;
//   cin>>row;
//   cin>>column;
  
//   int arr1[row][column];

//   cout<<"enter the elements of mtx"<<endl;
//   for(int i=0; i<row; i++){
//       for(int j=0; j<column; j++){
//           cin>>arr1[i][j];
//       }
//   }

//   for(int i=0; i<row; i++){               
//       for(int j=0; j<column; j++){
//          cout<<arr1[i][j]<<" ";
//         }
//        cout<<endl;
//     }
//     cout<<endl;


// // to print transpose there are three methods
// // 1--> switch outer loop and inner loop  as before i denotes rows now it denotes column 
// // 2--> run normal loop just cout<<arr[j][i] 
// // 3--> creating new array  


//   int arr2[column][row];
//   for(int i=0; i<column; i++){               // pushing all the elemnt of arr1 into arr2
//       for(int j=0; j<row; j++){
//           arr2[i][j] = arr1[j][i];
//         }
//     }

//   cout<<"transpose of matrix is-->"<<endl;
//     for(int i=0; i<column; i++){
//         for(int j=0; j<row; j++){               
//          cout<<arr2[i][j]<<" ";
//         }
//       cout<<endl;
//     }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// leetcode Q->867 Transpose Matrix (not necessarily n*n)
// Given a 2D integer array matrix, return the transpose of matrix.

  int m,n;

  cout<<"enter value of m,n"<<endl;
  cin>>m;
  cin>>n;
  
  vector<vector<int>>arr1(m,vector<int>(n));

  cout<<"enter the elemnts of mtx"<<endl;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cin>>arr1[i][j];
    }
  }

  for(int i=0; i<m; i++){       // prints the mtx
    for(int j=0; j<n; j++){               
     cout<<arr1[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;


  vector<vector<int>>arr2(n,vector<int>(m));

  for (int i = 0; i < m;i++) { 
    for (int j = 0; j < n; j++) {
      arr2[j][i]=arr1[i][j];
    }
  }
  
  cout<<"transpose of matrix is-->"<<endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){               
     cout<<arr2[i][j]<<" ";
    }
    cout<<endl;
  }


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// QUES--> an array of size(n*n) transpose given array without creating new array

//  int n;
  
//   cout<<"enter value of n"<<endl;
//   cin>>n;
  
//   int arr1[n][n];

//   cout<<"enter the elemnts of mtx"<<endl;
//   for(int i=0; i<n; i++){
//     for(int j=0; j<n; j++){
//       cin>>arr1[i][j];
//     }
//   }

//   for(int i=0; i<n; i++){                       // prints the mtx   
//     for(int j=0; j<n; j++){
//       cout<<arr1[i][j]<<" ";
//     }
//     cout<<endl;
//   }
//   cout<<endl;


//   for(int i=0; i<n; i++){               // make changes in existing array             
//     for(int j=i+1; j<n; j++){
      
//     swap(arr1[i][j],arr1[j][i]);
      
//     }
//   }
 
//   cout<<"transpose of matrix is-->"<<endl;
//   for(int i=0; i<n; i++){
//     for(int j=0; j<n; j++){               
//      cout<<arr1[i][j]<<" ";
//     }
//     cout<<endl;
//   }
   
 return 0;

}