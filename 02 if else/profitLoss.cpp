#include <bits/stdc++.h>
using namespace std;

int main()
{

  int SP,CP,P,L,x;
  cout<<"enter the cost price\n";
  cin>>CP;
  cout<<"enter the selling price\n";
  cin>>SP;
 
 x = SP - CP;
   if(x>0) {
      cout<<"profit of rs "<<x;
   } 
   else if (x<0){
     cout<<"loss of rs "<<(x * -1);
   }
   else{
     cout<<"neither profit nor loss";
   }

 return 0;

}