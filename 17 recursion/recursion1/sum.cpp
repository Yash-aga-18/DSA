#include <bits/stdc++.h>
using namespace std;


void sum_para (int sum, int n){          //using another parameter
    if(n==0){

        cout<<"sum is "<<sum<<endl;
        return;
    }

    sum_para( sum+n, n-1);
}



int sum(int n){                   // without parameter
    
    if(n==0)    return 0;

   return( n + sum(n-1) );
}


int main()
{
    int n;

    cout<<"enter a number"<<endl;
    cin>>n;


    sum_para(0,n);

    cout<<"sum is "<<sum(n);

    

 return 0;

}