#include <bits/stdc++.h>
using namespace std;

//  Input a string and return the number of times
//  the neighbouring characters are different from each other.

int main()
{
  
  string s;
  cout<<"enter your string"<<endl;
  cin>>s;
  int count = 0;
  int n = s.length();

    for(int i=0; i<n; i++){

        if(n==1)    break;    

        if(n==2 && s[0]!=s[1]){ 
            count ++; 
            break;
        }

        
        if(i==0){           // for 0th index
            if(s[i]!=s[i+1])   count++;
        }

        else if(i==n-1){    // for last index
            if(s[i]!=s[i-1])    count++;
        }

        else if (s[i]!=s[i+1] && s[i]!=s[i-1]){         // for all other index
            count++;
        }
    }

    cout<<count;
  
  return 0;

}