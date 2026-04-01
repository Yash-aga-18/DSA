#include <bits/stdc++.h>
using namespace std;

// leetcode Q->118 PASCAL TRIANGLE

int main() {
  int n;  
  cout<<"enter the no of rows"<<endl;
  cin>>n;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


    // vector<vector<int>>v;

    // for(int i=1; i<=n;i++){
    //    vector<int>a(i);     // used to create vectors of different size in vector
    //    v.push_back(a);
    // }
    

    // for(int i=0; i<n;i++){
    //     for(int j=0; j<=i; j++){
        
    //         if(j==0 || i == j )  v[i][j] = 1;

    //         else     v[i][j] = v[i-1][j-1] + v[i-1][j];

    //     }
    // }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++) {

        v[i].resize(i + 1);         // make row of size i+1
        v[i][0] = v[i][i] = 1;      // first and last elements = 1

        for (int j = 1; j < i; j++) {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }



    for(int i=0; i<n;i++){
        for(int j=0; j<=i; j++){
        
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
  
  
  
 return 0;

}