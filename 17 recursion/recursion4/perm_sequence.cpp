#include <bits/stdc++.h>
using namespace std;


// leetcode Q->60    same hard ques but T.C. exceeds for higher value of n
//  whats is kth permutation for n digit strings
//   input:   n= 3    k = 4;
//  output:   231     (123, 132, 213, 231, 312, 321)   


long long factorial(int n){

    if(n<=1)    return 1;
    return n*factorial(n-1); 
}


string perm (string str, int k, string ans){
    
    int n = str.length();

    if (n==1){                                  // to enter the last digit
        ans += str;     
        return ans;
    }

    int fact = factorial(n-1);                 // gives no. of ways to enter remaining digits
    int idx = k/fact;                          // gives the idx to enter in the ans
    if( k%fact == 0)     idx--;


    char ch = str[idx];
    string left =  str.substr(0,idx);             // from  0   to  i-1
    string right = str.substr(idx+1);             // from  i+1 to  last
    str = left + right;                           // updates the remaining string
    

    k = k % fact;                                   // updates to new value of k
    if(k==0)            k = fact;                   // it means last element of the group


    return perm(str, k, ans+ch);

}



int main(){

    int n = 4;
    int k = 6;
    string str = "";
    string ans = "";

    for(int i=1; i<=n; i++){              // enter elemnts in str
        str += to_string(i);  
    }

    cout<< perm ( str, k, ans);

 
  return 0;


}

/*

// If no characters are left, we have built the full permutation
// so return the final answer.
if (n == 0) return ans;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// (n-1)! = size of one block of permutations starting with the same digit.
// Example: for "1234", each starting digit has 3! = 6 permutations.
int fact = factorial(n - 1);

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Find which block the k-th permutation falls into.
// idx = index of the character to pick from 'str'.
// If k is perfectly divisible by fact, we move 1 step left (idx--)
// because k is 1-indexed.
int idx = k / fact;
if (k % fact == 0) idx--;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

char ch = str[idx];   // pick the digit at index 'idx'
// Remove the chosen digit from the string and form the reduced string.
// Example: "12345", idx=2 → next="1245"
string next = str.substr(0, idx) + str.substr(idx + 1);

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Update k for the next step.
// We move into the (smaller) block formed after removing one digit.
// If k % fact == 0, it means we're at the last permutation of the block, 
// so next k becomes fact.
k = k % fact;
if (k == 0) k = fact;

*/
    

