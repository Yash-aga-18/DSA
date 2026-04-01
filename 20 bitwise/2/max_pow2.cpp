#include <bits/stdc++.h>
using namespace std;

// find max power of 2 such that it is smaller or equal than given n
// eg--> n = 90
// ans-->    6 (as 2^6 is 64)

// follow-up ---> find just greater power of 2 than the elemnt


int main()
{
    
    int n = 64;

    int cnt = 0;
    
    // while next power of 2 is <= n
    while ((1 << (cnt + 1)) <= n) {
        cnt++;
    }

    cout << cnt << endl;


 return 0;

}