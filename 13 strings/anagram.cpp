#include <bits/stdc++.h>
using namespace std;

// leetcode Q->242

// check wether given 2 strings are anagram or not
// anagram is set of words that can be re-arranged to form a new word
// eg--> rat  tar is anagram   but    rat  cat   are not anagram

int main()
{
  string str1;
  cout<<"enter 1st string\n";
  cin>>str1;

  string str2;
  cout<<"enter 2nd string\n";
  cin>>str2;

  if(str1.size()==str2.size()) {   // as after sorting if it is anagram it becomes equal
    
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());

    if(str1==str2) cout<<"anagram";
  }

  else          cout<<"not anagram";

  
  
 return 0;

}