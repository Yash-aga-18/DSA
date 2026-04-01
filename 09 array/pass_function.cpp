#include <bits/stdc++.h>
using namespace std;

// we can't directly access the length of array in functions so 
// we also pass the length of array usaully


void display(int a[],int size) {         // void display(int *a,int size)
 
  for(int i=0; i<size; i++) {
   cout<<a[i]<<" ";
  }

  cout<<endl;
 return;

}

void change(int b[], int size){
  b[0]=9;
  return;
}


int main()
{
//  IMP----> array is passed by reference

  int arr[5]={1,2,3,4,5};

//  int size =sizeof(arr)/sizeof(arr[0]); 
//  cout<<size<<endl;

//   display(arr, size);             // it is highly recommended to pass the size of an array 
//   change(arr, size);
//   display(arr, size);


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


int *ptr = arr;
int *ptr1 = &arr[0];
//  cout<<ptr<<endl<<&arr[0]<<endl;
  
//  int *ptr = &arr;             // this is wrong 
//  int *ptr = arr[0];           // this is wrong because it can't stores integer value
 

//   for(int i=0; i<5; i++)
//   cout<<ptr[i];                 // it prints entire arr


  ptr[3] = 98;     // it also updates the value of arr

  *ptr = 8;        // it also updates the value of arr[0]
  ptr++; 
  *ptr = 9;        // it updates the value of arr[1]
  ptr = arr;

  for(int i=0; i<5; i++){
    cout<<*ptr<<" ";                 
    ptr++;
  }

 ptr = arr;            // it is advised to do this to remain ptr same as start


 return 0;

}