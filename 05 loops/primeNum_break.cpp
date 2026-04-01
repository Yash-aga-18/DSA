#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i,n,flag=0;
  cout<<"enter the number \n";
  cin>>n;

  if(n>=2) {

    for(i=2; i<n; i++){
      if(n%i == 0){
        flag=1;
        break;
      }
    }

    if(flag==0)   cout<<"it is prime";
    else          cout<<"it is composite number";

  }
    
  else if(n==1)   cout<<"neither prime nor composite";
  else            cout<<"invalid number";

 return 0;

}