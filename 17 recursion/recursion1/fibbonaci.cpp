#include <bits/stdc++.h>
using namespace std;

//   1, 1, 2, 3, 5, 8,13,21,34........


// Recursive function to get the nth Fibonacci number
int fibo(int n) {

    if (n == 1 || n == 2) return 1;

    return fibo(n - 1) + fibo(n - 2);
}


// Recursive function to print the Fibonacci series  acts as loop
void printFibonacci(int index, int n) {

    if (index > n)  return;

    cout << fibo(index) << endl;        // funcn calls
    printFibonacci(index + 1, n);
}


int main() {

    int n;
    cout << "Enter Fibonacci numbers to print: ";
    cin >> n;

    printFibonacci(1, n);
    
    cout<<endl;
    cout<<fibo(n);      // prints the last number of series

    return 0;
}
