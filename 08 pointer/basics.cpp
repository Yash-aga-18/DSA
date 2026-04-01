#include <bits/stdc++.h>
using namespace std;

// to store the value of addresss of a variable, pointer is used

// (int* p)  or  (int * p)  or (int *p)


int main()
{
    int x=784;
    int *p=&x;                //  it means value of adress of x is stored in p        
    
    cout<<p<<endl;
    cout<<&x<<endl;               // both above cases give same result 
    cout<<&p<<endl;               // it gives the address of p
    cout<<*p<<endl;              // it gives the value stored at address of x
    cout<<sizeof(p)<<endl;

    *p=56;                                // we can update the value of x 
    cout<<x<<endl;

    cin>>*p;
    cout<<x;

 return 0;

}

// a pointer stores a memory address, and:
// On a 32-bit system, addresses are 32 bits → 4 bytes
// On a 64-bit system, addresses are 64 bits → 8 bytes

// It doesn’t matter if it's a:
//char*   or  int*   or  double*   or  void*

// 👉 All of them take same amount of memory — because they all just hold one address.