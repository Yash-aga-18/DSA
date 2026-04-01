#include <bits/stdc++.h>
using namespace std;
// ques--> generate binary strings of specific length without consecutive 1


void generate(string str, int n){

    if(str.length() == n){
        cout<< str<<endl;
        return;
    }

    generate(str+'0' ,n);               // Always allowed to add '0'

    if (str == "" || str.back() != '1')     generate(str+'1', n);

}



int main()
{
 
    string str ="";
    int n = 4;
    
    generate(str,n);    


 return 0;

}