#include <bits/stdc++.h>
using namespace std;

// wave print is to print matrix in wavy form
// 1 2 3
// 4 5 6    --> 1 2 3 6 5 4 7 8 9  this is required output
// 7 8 9

int main()
{

  int m, n;

  cout << "enter value of m*n of mtx" << endl;
  cin >> m;
  cin >> n;
  int arr[m][n];

  cout << "enter the elemnts of mtx" << endl;
  for (int i = 0; i < m; i++) { // taking input in mtx
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  cout << "matrix is-->" << endl;
  for (int i = 0; i < m; i++) { // printing input of mtx
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // //  to print the output in wave form  acc to given ques

  //    for(int i=0; i<m; i++){
  //         if(i % 2 == 0){                 // if row is 0,2,4....
  //             for(int j=0; j<n; j++){
  //               cout<<arr[i][j]<<" ";
  //             }
  //         }
  //         else {                          // if row is 1,3,5....
  //             for(int j=n-1; j>=0; j--){
  //               cout<<arr[i][j]<<" ";
  //             }
  //         }
  //     }

  //  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // 1 2 3
  // 4 5 6   -->    1 4 7 8 5 2 3 6 9
  // 7 8 9

  //  to print the output in wave form

  for (int j = 0; j < n; j++) {

    if (j % 2 == 0) {             // if column is 0,2,4....
      for (int i = 0; i < m; i++) {
        cout << arr[i][j] << " ";
      }
    }
    
    else  {                       // if column is 1,3,5....
      for (int i = m - 1; i >= 0; i--)  {
        cout << arr[i][j] << " ";
      }
    }
  }

  return 0;
}