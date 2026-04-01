#include <bits/stdc++.h>
using namespace std;

int main()
{

  int x;
  x = 5 > 8 ? 10 : 1 != 2 < 5 ? 20 :30;
  cout<<"value of x is "<<x;
  
  //   it solves from right to left
  //   1 != 2 < 5 ? 20 :30       
  //   from hierarchy order relational solved first  so 2<5 gives true  i.e.   1     
  //   1 != 1  which gives us false so final value becomes 30

  //   x = 5 > 8  ?  10 : 30
  // so final value is to be 30


 //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

 //   in some questions tough terniary is given eg-  x = 10 > 8 ? 70 : 1 != 2 < 5 ? 20 :30;
 //  here no need to solve whole equation but only check is 10 > 8    true so no need to solve the whole ques
 
 
 //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //  The ternary operator ?: promotes both values to a common type
// When using the ternary operator ?:    C++ promotes types to the "higher precision" type
// char/bool → int → float → double → long double


  int test = 0;    
  cout << "First character " << '1' << endl;
  cout << "Second character " << (test ? 3 : '1') << endl;   
  

  // test ? 3 : '1'
  // test is 0 → condition is false
  // So the expression becomes '1'  
  // both promotres to the integer instead of char and '1' ascii value is 49
 
 
 return 0;

}