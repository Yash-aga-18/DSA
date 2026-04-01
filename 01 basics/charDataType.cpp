#include <bits/stdc++.h>
using namespace std;

int main()
{

  char ch = 'a';
  cout<< ch; 
 
  ch = '1';
  cout<< ch; 
   
  ch = '#';
  cout<< ch; 
  
  ch = '\0';
  cout<< ch; 
  
  ch = ' ';
  cout<< ch; 



  cout<<(int)ch;            //  it is used to get the ascii value of any character

 

//    '0'	  -->  48		          '1'	  -->  49	

//    'A'	  -->  65             'B'	  -->  66
//    'a'	  -->  97             'b'	  -->  98

//    ch = 'ab';     //  it is invalid
 // ascii value of A=65 continues till Z ,    a=97 continue till z ,    0=48 continues till 9

 // character is of always single character except \0  it's ascii value is 0
 //  here now 1,#,a all are act as character and have a different vaule

 
 

 
 return 0;

}