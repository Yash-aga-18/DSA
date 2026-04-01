#include <bits/stdc++.h>
using namespace std;

int main()
{

  int a,b,c;

  cout<<"enter first number : ";
  cin>>a;
  cout<<"enter second number : ";
  cin>>b;
  cout<<"enter third number : ";
  cin>>c;


  if(a>b){                // a is greater than b
    if(a>c)               // a is greater than c also
      cout<<"first no.";
    else                  // c is greater than a   and a is also greater than b
    cout<<"third no.";
  }

  
  else{                   // b is greater than a
    if(b>c)               // b is greater than c also
    cout<<"second no.";
     else                  // c is greater than b   and b is also greater than b
    cout<<"third no.";
  }
  
  cout<<" is greatest";
 return 0;

}