#include <bits/stdc++.h>
using namespace std;

// Write a program to calculate the sum and print of odd numbers between a and b 


int sum(int first, int last){

    if(first>last)          return 0;
 
    if( first%2 != 0) {            

        cout<<first<<endl;
        return  first + sum(first+2,last);
    }

    else  return sum(first+1,last);

}


int main()
{
    
    int first,last;
    cout<<"enter the first and last number ";
    cin>>first>>last;

    int ans = sum(first,last);            // to print the numbers and stores the answer
    cout<<"sum is :"<<ans;


 return 0;

}