#include <bits/stdc++.h>
using namespace std;

// #define MAX 100   it is called macro generally write before int main
 // it is used to repace all the position where max is written by 100
//  I have used macros in switch folder basics file
// macros are generally written in capitals letters to differentate it from variable
// nested macros are also possible


#define MAX 987
#define SUM(x,y) x+y
#define PRO1(x,y) x*y
#define PRO2(x,y) ((x)*(y))
#define FINAL MAX-100

int main()
{

//   cout<<MAX;
//  int a,b;
//  float result;
//  cin>>a;
//  cin>>b;
//   result=SUM(a,b);
//   cout<<result;
// result = PRO1(10.2+2,2);
//   cout<<result<<"\n";
// // here 10.2+2*2  acc to order of precedence and order of associativity reult = 14.

// result = PRO2(10.2+2,2);
//   cout<<result;
  
  // cout<< FINAL;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// just like macros there is another keyword used to create alaises

typedef long double abc;
abc x;          // it is equivalent to    long double x;
cin>>x;
cout<<sizeof(x); 




 return 0;

}