#include <bits/stdc++.h>
using namespace std;

// leetcode Q->74

// searh an elemnt in matx such that only rows sorted in ascending order
//  in most efficient manner
// eg--->    1    3     5    7  
        //   10   11    16   20  
        //   23   30    34   60  
          
        

int main() {

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



    int low = 0;
    int high = m * n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        int row = mid / n;   
        int col = mid % n;   

        int value = matrix[row][col];

        if (value == target) { 
            cout<<"true";      // ✅ found
            return 0;
        }

        if (value < target)     low = mid + 1;    // search right half
        else                    high = mid - 1;   // search left half
    
    }

    cout<<"false";
  
 return 0;


}
/*

we can also apply same approach in using leetcode ques-->240
using top right corner approach
but using this approach TC is o(m+n)
but using binary search we reduce it to O(log(m*n))



*/