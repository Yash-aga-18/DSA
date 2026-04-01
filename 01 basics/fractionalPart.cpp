#include <bits/stdc++.h>
using namespace std;

int main()
{
 // fractional part is the no. after decimal in positive numbers
 // but for negative no. it is calculated as (number-greatest integer)  
 
 // greatest integer is the number lies on left side of the number line 
 // eg:--> greatest integer for 1.7 it is 1          for -1.7 it is -2 
 // eg:--> fractional part for  1.7 it is 0.7          for -1.7 it is ( -1.7-(-2) = 0.3 ) 

  float x;
  cin>>x;                
 
  if(x>=0) {                 //7.8
    int y = (int)x;          // 7
    x = x - y;
    cout<<x;
  }

  if(x<0) {                 //-1.3
    int y = (int)x;         //-1
    y = y - 1;              //-2
    x = x - y;              //-1.3-(-2)=0.7
    cout<<x;
 }

 return 0;

}