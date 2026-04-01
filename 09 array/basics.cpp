#include <bits/stdc++.h>
using namespace std;

// An array is a collection of elements, all of the same data type,
// stored in a contiguous block of memory. Each element in the array can be accessed using index.
// base adress of array is same as address of 0th index


// if during initalization all elemnts of array are not given then it is default set to 
// 0 in int type;  0.0f in float type;  '\0' in char type
// eg--> arr1[3]={0,1}  2nd index remains unfilled so by default it is set to be zero
// it applies in both 1d and 2d arrays  

int main()
{
    
    // int arr[7];           // it means 7 blocks of integer data type are now reserved   index-->  0 1 2 3...
    // arr[0]=7;             // it reserves the 0th index value is stored to be 7
    // arr[1]=4;             
    // arr[2]=5;             
    // arr[3]=145;             
    // cout<<arr[0];   
    // cout<<0[arr];        // both above results are same   

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// // you can initialize it in another way

// int arr[7]={7,145,45,7,8,9,6};          
// cout<<arr[4];      


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//  // either you have to give size of the array or 
//  // you have to initalize it with some values   or both

//   int arr[]={1,2,5,8,7,4};

//   int arr1[];         // it is not allowed
//   arr1[0]=23;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // best and most optimized way to take input and output a given array

// int arr[10];

// // input
// for(int i=0; i<10; i++)
// cin>>arr[i];

// // output
// for(int i=0; i<10; i++)
// cout<<arr[i]<<" ";

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  //  size of an array

 int arr[] = {1,3,5,6,76,7,8,896};

 int n = sizeof (arr)/sizeof(arr[0]);
    cout<<"size of arr is "<<n<<endl;


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // sort the arr

    // int arr[] = {0,2,4,0,2,0};
    // int n = sizeof(arr)/sizeof(arr[0]);

    // sort(arr,arr+n);       // use #include<algorithm>
    
    // Sort only elements from index 1 to index 4 (i.e. 2, 4, 0, 2)
    // sort(arr + 1, arr + 5);


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// there is another way to print the array or vector---->

for(int ele: arr){
    cout<<ele<<" ";
}


 return 0;

}