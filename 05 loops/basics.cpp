#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int i,n;

  // to display the AP upto n terms 1,3,5,7,9,.......
  // an= a +(n-1)d
  // an= 1 +(n-1)2
  // an = 2n-1
  
 //   cout<<"enter the n terms of 1,3,5,7,.. AP you want to print\n";
 //   cin>>n;
  
 //   for(i=1; i<=(2*n-1); i=i+2){
 //     cout<<i<<endl;
 //   }
    

  // // to get rid of this formula we can use another approach
    // int a = 1;
    // for(i=1; i<=n; i++){
    //  cout<<a<<endl;
    //  a= a+2;
    // }
 

 //  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  //  to display the GP upto n terms 1,2,4,8,16,.......

//     cout<<"enter the n terms of GP you want to print\n";
//     cin>>n;
//     int a = 1;

//     for(i=1; i<=n; i++){
//      cout<<a<<endl;
//      a= a*2;
//     }


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// while loop condition


//   int i = 1;
//   while(i<=10){
//     cout<<i<<endl;
//     i++;
//   }



//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
 // do while loop condition
 // it's major disadvantage is, it runs at least once irrespective of the condition satisfies or not 


//  int i= 1;
//  do {
//     cout<<i<<endl;
//     i++;
//  } while(i <= 10);


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// print the Upper case alphabets with thier ASCII values

for(int i=65; i<=90; i++){
  cout<<char(i)<<"-->"<<i<<endl;
}


 return 0;

}