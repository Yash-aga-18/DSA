#include <bits/stdc++.h>
using namespace std;

int main() {

// vector<int>v;           // you need not to mention the size


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// //   for inserting----------->

//   v1={6,1,9,0};
//   cout<<v1[3];
 

//   v.push_back(6);
//   v.push_back(1);
//   v.push_back(9);
//   v.push_back(0);
  

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // for accessing the vector----------->

//   cout<<v[0]<<endl;
//   cout<<v[1]<<endl;
//   cout<<v[2]<<endl;
//   cout<<v[3]<<endl;
  


//   // for getting the size of vector
//   cout<<v.size()<<endl;
  

//   // for getting the capacity of vector       //  its capacity is increased by double the previous, if it is full
//   cout<<v.capacity()<<endl;
 

// //  for deletion
// v.pop_back();                       // size is reduced but not capacity 


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//  vector<int>v;

//   v.push_back(6);
//   cout<<v[0]<<endl;
//   cout<<v.size()<<endl;
//   cout<<v.capacity()<<endl<<endl;

//   v.push_back(7);
//   cout<<v[1]<<endl;
//   cout<<v.size()<<endl;
//   cout<<v.capacity()<<endl<<endl;

//   v.push_back(9);
//   cout<<v[2]<<endl;
//   cout<<v.size()<<endl;
//   cout<<v.capacity()<<endl<<endl;

//   v.push_back(10);
//   cout<<v[3]<<endl;
//   cout<<v.size()<<endl;
//   cout<<v.capacity()<<endl<<endl;


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//  vector<int>v;

//   v.push_back(6);
//   v.push_back(1);
//   v.push_back(9);
//   v.push_back(0);



//   for(int i=0; i<v.size(); i++) {            // prints the vector
//     cout<<v[i];
//   }

// cout<<endl;


//   cout<<"size before pop_back "<<v.size()<<endl;
//   cout<<"cap. before pop_back "<<v.capacity()<<endl;


//  v.pop_back();                              // deletes the last element

//   for(int i=0; i<v.size(); i++) {
//    cout<<v[i];
//   }

// cout<<endl;


//   cout<<"size after pop_back "<<v.size()<<endl;
//   cout<<"cap. after pop_back "<<v.capacity()<<endl;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  to initalize a vector there are many ways

//   vector<int>v(5);        // now its initial size and capacity is both 5 and value at each index is zero
//   cout<<v[0];
 

//   vector<int>v1(5,7);       // now its initial size and capacity is both 5 and value at each index is 7
//   cout<<v1[5];


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// take input in vector------------->


// vector<int>v(4);                    // when you treat vector same as array

// for(int i=0; i<v.size(); i++)
// cin>>v[i];

// for(int i=0; i<v.size(); i++)
// cout<<v[i]<<" ";



// vector<int>v;                    // when size of vector is not given

// for(int i=0; i<5; i++) {
//  int x;
//  cin>>x;
//  v.push_back(x);
// }


// for(int i=0; i<v.size(); i++)
// cout<<v[i]<<" ";


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // modify the vector and sorting of vector

//  vector<int> v;

//   v.push_back(6);
//   v.push_back(1);
//   v.push_back(9);
//   v.push_back(10);

//  cout<<v[2]<<endl;

//   v[2]=876;         // it modify the value at index 2
//   cout<<v[2]<<endl;

//   v.at(3)=34;       // it modify the value at index 3
//   cout<<v.at(3)<<endl;

//   for(int i=0; i<v.size(); i++){
//     cout<<v.at(i)<<" ";
//   }
//   cout<<endl;

//   sort(v.begin(),v.end());              //  use #include<algorithm>
//  for(int i=0; i<v.size(); i++){
//     cout<<v.at(i)<<" ";
//   }
//   cout<<endl;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// vector<int> v(3);  // v = {0, 0, 0}

// // vector<int>v0(3) = {1,2,3};      // incorrect
// vector<int>v1 = {1,2,3};           // or by using push_back  

// vector<int>v2(3);         
// v2.push_back(1);                //  {0,0,0,1}


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// // make vector duplicate of an array ------------------>

  // int arr[]= {1,3,5,4,7,8,6};
  // int n = sizeof(arr)/sizeof(arr[0]);


// // 1st method ------->

//   vector<int>v;

//   for(int i =0; i<n; i++){
//     v.push_back(arr[i]);
//   }
  

// // 2nd method ------->
  
//   vector<int>v(n);

//   for(int i =0; i<n; i++){
//     v[i]=arr[i];
//   }


// // 3rd method ------->
  
  // vector<int>v(arr,arr+n);
  


  // for(int i =0; i<n; i++){
  //   cout<< v[i];
  // }  


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

  int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
  
  vector<int> v(arr+3, arr+8);          //copies elemnt from index 3 to index 7(inclusive)

  for (int x : v)   cout << x << " ";


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  v.clear();    //   Removes all elements from the vector.  Size becomes 0.   Capacity stays the same.





  return 0;
    
}