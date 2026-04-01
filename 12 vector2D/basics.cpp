#include <bits/stdc++.h>
using namespace std;

int main()
{

//   in 1D array we write as arr[4]={1,2,3,4};  
//   in 1D vector we write as vector<int>v(4);  
  
//  2D vector is vector of vectors just like similar to (array of arrays)  
//  we can have different no of coluns in each row in 2D vector
//  eg--> v = {{1,2,3},{4,5},{6,7,8,9,10,11}}

// in 2D array it is necessary to mention dimensions while passing into functions 
// while there is no need to mention size of 2D vector passing to function


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ways to initialize 2D vectors   --------->

// vector<vector<int>>v;
// vector<vector<int>>v1(3);       // initially it stores 3 vectors and can modify

// to write similarly arr[3][4] in form of vector we can write as follows-->

// vector<vector<int>>v1(3,vector<int> (4));        // it means make a vector of size 3 rows and each row stores the size of vector 4

// vector<vector<int>>v1(3,vector<int> (4,9));      // it makes vector of size rows 3 and coumn 4 and in each column stores the value equals to 9 
  
// vector<vector<int>>v;
  // int row = v.size();                // to access rows
  // int column = v[0].size();          // to access columns we have to go to any block of rows


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // inserting the elements --------->

vector<int>v1 ={1,2,3,4,};
vector<int>v2 ={5,6};
vector<int>v3 ={7,8,9,10,11,12};

vector<vector<int>>v;    // can't dirertly insert values in 2d vectors
v.push_back(v1);         //  only vector is pushed in push_back function
v.push_back(v2);
v.push_back(v3);
  
cout<<v[2][3];             // prints 10

v.pop_back();             // it deletes the last row completely
 



return 0;

}