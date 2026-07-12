#include <bits/stdc++.h>
using namespace std;

// a matrix is 2D array

// 2D array is just array of arrays  it means there is an array inside an array

//  eg--> arr[2][3]  it actually means there is array of size row i.e 2 and each block of array containbs array of size of column i.e 3
// arr[2][3]={10,20,30,40,50,60}  array of size 2 each has an array of size 3 having 10,20,30 and in another 40,50,60 stores

int main()
{

// // it is necessary to declare columns size but not necessary rows in case of initializations


// // ways of initialization-->>>>
// //method 1-->

//   int arr[4][3];                 //   rows-->4      0,1,2,3           //     columns-->3    0,1,2
//   arr[0][0]=34;
//   cout<<arr[0][0]<<endl;

 
// //method 2-->

//   int arr1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//   //    values are always filled row wise  
//   cout<<arr1[0][0]<<endl;

// //method 3-->

//   int arr2[3][3]={10,20,30,40,50,60,70,80};
//   //    values are always filled row wise  
//   cout<<arr2[2][2];

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//input and output in 2D array

int row, column;
cout<<"enter no. of rows and column\n";
cin>>row;
cin>>column;
int arr[row][column];

cout<<"enter the elemnts of array"<<endl;
for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
        cin>>arr[i][j];
    }
}

for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// into passing in a function
/*

 it is not working till we passed both row,col in formal arguments; hence it is major drawback

    change(arr[][]){        //change(arr[2][3])    
        .....    
    }

    int main(){
        int arr[2][3];
        change(arr);
    }


*/
 return 0;

}