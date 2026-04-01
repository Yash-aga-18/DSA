#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b ){

int temp;
temp=*a;
*a=*b;
*b=temp;
// return;

}


int main()
{
    int a=5,b=8;

    swap(&a,&b);
    cout<<a<<" "<<b;

 return 0;

}