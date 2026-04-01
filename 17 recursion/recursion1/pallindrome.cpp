#include <bits/stdc++.h>
using namespace std;

bool pallindrome(string str, int i, int j){

    if(i>j)                 return true;
    
    if(str[i]!=str[j])      return false;
    else                    return(str, i+1, j-1);

} 

int main()
{
    
    string str = "racecar";

    cout<<pallindrome(str,0,str.length()-1);


 return 0;

}