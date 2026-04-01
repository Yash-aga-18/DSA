#include <bits/stdc++.h>
using namespace std;

// leetcode Q->779  kthGrammar

// We build a table of n rows (1-indexed). start by writing 0 in the 1st row. 
// Now in every subsequent row, we look at the previous row and replace each occurrence of
//  0 with 01,  1 with 10. return the kth elemnt in last row
// eg--> INPUT: n=4   k=7
//       OUTPUT: 0
// // explaination:   
//                                0
//                         /              \
//                     0                      1
//                  /     \               /       \
//                0         1           1           0
//              /   \     /   \       /   \       /   \
//             0     1   1     0     1     0     0     1
//                                               ^ this is the ans



    
int kthGrammar(int n, int k) {

    if(n == 1)          return 0;

    if(k%2 == 0) {           //  even, flip_prev , k/2

        int prevAns = kthGrammar(n-1, k/2);
        if(prevAns == 0)    return 1;
        else return 0;
    }

    else {                  // odd , same_prev , k/2+1

        int prevAns = kthGrammar(n-1, (k/2)+1);
        return prevAns;

    }
}



int main(){

    int n = 4;
    int k = 7;

    cout<< kthGrammar(n,k);
    
  return 0;

}

// we always visit to previos ans and by using it we return the output 
// T.C. ---> O(n)
// S.C. ---> O(1)