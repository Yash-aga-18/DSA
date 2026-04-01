#include <bits/stdc++.h>
using namespace std;

// Ques--> no of ways to climb up the stairs but new condn is either 
// he can take one by one step OR
// or he can also take 2 steps at a time
// or he can also take 3 steps at a time

// this is the most generalised and effective way of the code


int stair(int n){

    if(n==0)    return 1;
    if(n<0)     return 0;
    // if(n==2)    return 2;      
    // if(n==3)    return 4;

    return (stair(n-1)+stair(n-2)+ stair(n-3));
    
}


void printStairs(int n, string S) {

    if(n < 0)       return;

    if(n == 0) {
        cout <<S<< endl;
        return;
    }

    printStairs( n-1, S+"1");       // Take 1 step
    printStairs( n-2, S+"2");       // Take 2 steps
    printStairs( n-3, S+"3");       // Take 3 steps

}


int main()
{
    int n;

    cout<<"enter the n"<<endl;
    cin>>n; 
    
    cout<<"no. of possible ways is --> "<<stair(n);
    cout<<endl;

    printStairs(n, "");

    


 return 0;

}