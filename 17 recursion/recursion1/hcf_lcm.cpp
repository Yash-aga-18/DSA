#include <bits/stdc++.h>
using namespace std;

// Euclidean algorithm for HCF/GCD
// T.C → O(log(min(a, b)))
// S.C → O(log(min(a, b))) due to recursion stack

int hcf(int a, int b) {

    if (a == 0)     return b;

    return  hcf(b % a, a);

}

int main() {

    int a = 8;
    int b = 40;

    int ans = hcf(a, b);

    cout << "HCF: " << ans << endl;
    cout << "LCM: " << (a * b) / ans;

    return 0;
}

/*

    a×b = HCF(a,b) × LCM(a,b)

*/
