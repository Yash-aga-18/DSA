#include <bits/stdc++.h>
using namespace std;

int main()
{
/*

   time complexity ------------------>
 
  O(1) means constant time — the algorithm takes the same amount of time regardless of the input size.
  O(k) == O(1)

  not valid to describe an infinite loop  
     

  O(kn) ==  O(n)
  O(n +- k) == O(n)
  O(n^k + n^m) = O(n^k)        // where k>m
  
  Time complexity does not refer to the time taken by the machine to execute a particular code.

  If we run the same code in a low-end machine(e.g. old windows machine) and in a high-end machine(e.g. Latest MacBook),
  we will observe that two different machines take different amounts of time for the same code. 
  The high-end machine will take lesser time as compared to the low-end machine. 
  So, the time taken by a machine can be changed depending on the configuration. 

 Definition:
 The rate at which the time, required to run a code, changes with respect to the input size, is the time complexity. 
 Basically, the time complexity of a particular code depends on the given input size, 
 not on the machine used to run the code.
  

 
//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

  O(5n^3 + 3) == O(n^3)
  O(5n^(13/2) + 7n^4 +2n^3 ) == O(n^(13/2))

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    for(int i=0; i<n; i++){
        cout<<i;
    }
    
    for(int i=0; i<m; i++){
        cout<<i;
    }
  
    T.C is O(n+m)

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<i;
        }
    }


    for(int i=0; i<n; i++){
        for(int j=i+1; j<m; j++){
            cout<<i;
        }
    }


    T.C is O(n*m)                   // in both the cases

 //  If j<n   then     T.C is O(n^2)                                        // it is the worst and try to be avoided
 // if there is another loop inside let k<n   then      T.C is O(n^3)       // it is even worse than n^2


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    for(int i=0; i<n; i*=k){
        cout<<i;
    }
    
    T.C is O(log n)                                                     // it is the best among the n and n^2 and n^3
    
 

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    for(int i=0; i<n; i*=k){
       for(int j=0; j<n/2; j++){
            cout<<i;
        }
    }

    
    T.C is O(n*log n)



//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------



*/ 
  
 return 0;

}