#include <bits/stdc++.h>
using namespace std;

// check a number is in power of 2


int main()
{
    int num;
    cout<<"Enter a number ";
    cin>>num;

    if(num<=0) {        //  if -ve or 0 
        cout<<"Invalid number";
        return 0;
    }


    if ( (num & (num-1)) == 0) cout<<"yes";
    else cout<<"no";


 return 0;

}

/*

n     = 1000
n-1   = 0111
--------------
&       0000  → ✔

*/