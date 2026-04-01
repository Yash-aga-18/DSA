#include <bits/stdc++.h>
using namespace std;

int main()
{
 
 int i,n;
  cout<<"enter the last num to print\n";
  cin>>n;
  for(i=1; i<=n; i++){
    
    if(i%2==0)  continue;
    
   cout<<i<<endl;

  }

 return 0;

}

// continue statement skips that iteration and move it to next iteration
// break statement skips whole iteration and stop the loop
