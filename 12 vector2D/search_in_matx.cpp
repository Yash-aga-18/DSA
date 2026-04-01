#include <bits/stdc++.h>
using namespace std;

// leetcode Q->240

// searh an elemnt in matx such that both rows and col sorted in ascending order
//  in most efficient manner
// eg--->    1    4    7   11   15 
        //   2    5    8   12   19 
        //   3    6    9   16   22 
        //   10  13   14   17   24 
        //   18  21   23   26   30
        

int main()
{
    int m,n;
    cout<<"enter the values of m and n"<<endl;
    cin>>m;
    cin>>n;

    int matrix[m][n];

    cout<<"enter the values"<<endl;             // taking input
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
  cout<<endl;
  

    for(int i=0; i<m; i++){               // prints the matx
        for(int j=0; j<n; j++){
          cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }   
 cout<<endl;

    int target;
    cout<<"enter the value of target "<<endl;
    cin>>target;

 // we always start from top right corner 
//   if matrix[i][j] < target go to botttom
//   else go to left
  

    int i = 0;
    int j = n-1;
    int count =0;

    while(i<m && j>=0){

        if(matrix[i][j]==target){
            count++;
            break;
        }

        else {   
            if (matrix[i][j] < target)    i++;
            else                          j--;
        }
    }

    if(count==0)    cout<<"target not found";
    else cout<<"target found at ["<<i<<"]["<<j<<"]";
  
  
 return 0;


}
/*
top-right (or bottom-left) works

The key is: at each step, you must be able to discard an entire row or column.
If you start at top-right (matrix[0][n-1]):
If target < value → move left (entire column to the right is larger → discard it).
If target > value → move down (entire row above is smaller → discard it).


If you start at bottom-left (matrix[m-1][0]):
If target < value → move up (discard row below).
If target > value → move right (discard column to the left).
Both guarantee you shrink the search space by one row or one column each step → O(m + n).

*/