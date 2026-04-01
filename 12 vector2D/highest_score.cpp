#include <bits/stdc++.h>
using namespace std;

// leetcode Q->861
// you given a m*n matx flip rows or col to so that score in matrix is highest
// eg-->  0 0 1 1   1 0 1 0   1 1 0 0
//        1 1 1 1 + 1 0 0 1 + 1 1 1 1  =  15 + 9 + 15 = 39


int main()
{
  
  int m,n;
  cout<<"enter the values of m and n"<<endl;
  cin>>m;
  cin>>n;

  int grid[m][n];

  cout<<"enter the values"<<endl;             // taking input
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
  cout<<endl;
  
    for(int i=0; i<m; i++){               // prints the matx
        for(int j=0; j<n; j++){
          cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }   

cout<<endl;

// step-1---> flip only those rows who is leading by 0

    for(int i=0; i<m; i++){
        if(grid[i][0]==0) {             // check if leads by zero or not

            for(int  j=0; j<n; j++){
                if(grid[i][j]==0)    grid[i][j]=1;
                else                 grid[i][j]=0;
            }
        }
    }        

// step-2---> flip the whole col if (no of zeroes> no of ones) starting from 1st col

    for(int j=1; j<n; j++){

        int noz=0,noo=0;
        
        for(int i=0; i<m; i++){
            if(grid[i][j]==0)   noz++;
            else                noo++;
        }

        if(noz>noo){
            for(int i=0; i<m; i++){
                if(grid[i][j]==0)    grid[i][j]=1;
                else                 grid[i][j]=0;
            }
        }
    }

    cout<<"new matx is--->"<<endl;
    for(int i=0; i<m; i++){               // prints the matx
        for(int j=0; j<n; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    int sum=0;

    for(int i=0; i<m; i++){               // prints the sum
        int x=0;
        for(int j=n-1; j>=0; j--){
            sum += grid[i][j]*pow(2,x);
            x++;
        }
    }

    cout<<"sum is --> "<<sum;
  
 return 0;

}