#include <bits/stdc++.h>#include<cmath>             //used for mathematical func
using namespace std;

// some in-built functions are min(x,y)   max(x,y)  sqrt(x)


float mini(float x,float y){          // these are formal parameters
  float a;
  if(x<y)     a = x;
  else        a = y;
  
 return a;

}

int main()
{

  cout<<mini(3.5,4.1);                // these are actual parameters 
//   cout<<max(3.5,4.1);
cout<<sqrt(9);


 return 0;

}

// lets suppose we have mini(3,4)
// and in float mini(int x = 23, int y = 14)
// cout<<x<<y          it gives the value of actual parameter irrespective of the formal poaramerter
// it gives the output 3 4

// and if we pass only one value mini(3)
// it gives the output 3 14

// if you have given any value in formal parameter it should be given to all variables in argument
// int mini(int x=3, int y)     it is wrong and gives error 