#include <bits/stdc++.h>
using namespace std;


int ascending1(int i, int n){               //using another parameter
    
    if(i==n)    return i;
    cout<<i<<endl;
    return(ascending1(i+1,n));

}


int descending(int n){

    if(n==1)    return 1;
    cout<<n<<endl;
    return(descending(n-1));

}

void ascending(int n){                       // without parameter

    if(n==0)    return;
    ascending(n-1);
    cout<<n<<endl;

}

int main() {
  
    int n;
    
    cout<<"enter a number"<<endl;
    cin>>n;

    cout<<"ascending number-->"<<endl;
    cout<<ascending1(1,n);                       
    
    cout<<endl;
    cout<<"descending number-->"<<endl;
    cout<<descending(n);   
    
    cout<<endl;
    cout<<"ascending number-->"<<endl;
    ascending(n); 
                      
  
 return 0;

}