#include <bits/stdc++.h>
using namespace std;

// // leetcode Q->1342. Number of Steps to Reduce a Number to Zero

// In one step, if the current number is even, you have to divide it by 2, 
// otherwise, you have to subtract 1 from it.


int steps(int count ,int num){

    if(num==0)      return count;

    if(num%2==0)    return steps(count+1 , num/2);
    else            return steps(count+1 , num-1);

}



int main()
{
    
    int num;
    cout<<"enter the number ";
    cin>>num;

    
    cout<<steps(0,num);


 return 0;

}