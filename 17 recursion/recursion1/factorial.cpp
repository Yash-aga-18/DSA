#include <bits/stdc++.h>
using namespace std;

// recursion --> funcn calling itself
// base case is the condition which tell when will the recursion should terminate


int fact(int n){
    
  if (n==0 || n==1)   return 1;            // base case 

  return(n*fact(n-1));                    // recursive call
   
  
}

int main()
{
  int n;
  
  cout<<"enter a number"<<endl;
  cin>>n;
  cout<<fact(n);                       // function call
  
  
 return 0;

}
