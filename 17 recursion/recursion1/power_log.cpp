#include <bits/stdc++.h>
using namespace std;

// Fast exponentiation: O(log n) time, O(log n) recursion stack

int power(int base, int exp) {

  if (exp == 0) return 1;      // base^0 = 1
  if (exp == 1) return base;   // base^1 = base

  int ans = power(base, exp / 2);

  if (exp % 2 == 0)     return ans * ans;    //3^8 = (3^4) * (3^4)  so ans*ans 
  else                  return ans * ans * base;

}


int main() {
  int base, exp;

  cout << "Enter the base: ";
  cin >> base;

  cout << "Enter the exponent: ";
  cin >> exp;

  cout << "Answer is --> " << power(base, exp);
  return 0;
}

/*
Time Complexity  : O(log n)
Space Complexity : O(log n) due to recursive stack frames
*/
