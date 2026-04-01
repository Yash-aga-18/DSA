#include <bits/stdc++.h>
using namespace std;

// Ques--> return no of ways to climb up the stairs but condn is either 
// he can take one by one step OR  take 2 steps at a time
// eg--> to climb 3 stairs there are 3 ways --> 111 or 12 or 21
// it is just similar to fibbonaci almost.


int stair(int n){

    if(n==1)    return 1;
    if(n==2)    return 2;       // there are 2 ways--> 11 or 2

    return ( stair(n-1)+stair(n-2) );
}


int main()
{
    int n;

    cout<<"enter the n"<<endl;
    cin>>n; 
    
    cout<<"ans is --> "<<stair(n);
    cout<<endl;

   
 return 0;

}