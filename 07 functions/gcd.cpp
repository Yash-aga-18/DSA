#include <bits/stdc++.h>
using namespace std;

int hcf1(int a, int b) {

  int gcd = 1;
  for (int i = min(a, b); i >= 1; i--) {

    if ((a % i == 0) && (b % i == 0)) {
      gcd = i;
      break;
    }
    
  }

  return gcd;
}


int hcf2 (int a, int b){    //The Euclidean Algorithm

  while(a > 0 && b > 0) {

    if(a > b)  a = a % b;
        
    else       b = b % a; 
        
  }
    
  if(a == 0)  return b;
  return a;

}


int main()
{

  int a,b;
  cout<<"enter first number:";
  cin>>a;
  cout<<"enter second number:";
  cin>>b;

  cout<<hcf1(a,b);
  cout<<endl;
  cout<<hcf2(a,b);

 return 0;

}

/*

The Euclidean Algorithm  ------>hcf(a,b) = hcf(a-b , b)  where a>b

Eg   n1 = 20, n2 = 15:

gcd(20,15) = gcd(20-15, 15) = gcd(5, 15)
gcd(5,15)  = gcd(15-5, 5)   = gcd(10, 5)
gcd(10,5)  = gcd(10-5, 5)   = gcd(5, 5)
gcd(5,5)   = gcd(5-5, 5)    = gcd(0, 5)
Hence, return 5 as the gcd.


*/