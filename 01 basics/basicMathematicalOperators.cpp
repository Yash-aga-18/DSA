#include <bits/stdc++.h>
using namespace std;

int main()
{

    
 //   x = x + 5        is same as       x += 5 
  //  same things applies for all basic mathematical operators

 // ++x is pre increment it means value is updated before
 // x++ is post increment it means value is updated later 


 // --x is pre decrement it means value is updated before
 // x-- is post decrement it means value is updated later 

 // in use of modulous operator both a nd b must is of int data tpe in c++

 //    (a % b)    is same as   (a % -b)     but not same as    (-a % b)  or (-a % -b)
 //    (-a % b)  is same as    (-a % -b)

  cout<< 99 % -2<<endl;;
  
  
  float x;
  x = 7.0/22.0;
  cout<<(float)x;          // it will give the value as float same as 7.0/22    7/22.0
  // but if i do x = 7 /22   it gives zero because both 7 and 22 acts as int value 
 
 //    && gives output when both cond is true
 //    || gives output when either of the cond is true

 //  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//  to get the ceil value 

    int x = 23;
    int mid = 5; 
    int ceil  = (x+mid-1)/mid;

    // x + mid - 1 = 23 + 5 - 1 = 27
    // 27 / 5 = 5

    int floor = x/mid;

 
 return 0;

}