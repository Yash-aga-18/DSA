#include <bits/stdc++.h>
using namespace std;

int power(int base, int exp){

  if(exp==0 ) return 1;

  return (base * power(base,exp-1));

}



int main()
{
  int base, exp;

  cout<<"enter the base"<<endl;
  cin>>base;
    
  cout<<"enter the exponent"<<endl;
  cin>>exp;
    
  cout<<"ans is --> "<<power(base,exp);

    
    
 return 0;

}
/*
  in this case the time copmlexity is  --> calculated same as normal but generally O(n)
  in this case the space copmlexity is --> generally O(n)stack frames


*/