#include <bits/stdc++.h>
using namespace std;

// input string of length n and find no. of vowels

int main()
{
  cout<<"enter your string "<<endl;
  string str;
  getline(cin,str);             
  cout<<str<<endl;

 int count=0;
  for(int i=0; i<str.size(); i++){
    if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
      count++;
    }
  }

  cout<<"no. of vowels are "<<count;
  
 return 0;

}