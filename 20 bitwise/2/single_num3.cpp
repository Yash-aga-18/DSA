#include <bits/stdc++.h>
using namespace std;

// given an array, every elemnt apearring thrice except only 1 single item

int main()
{
    
    vector<int>arr = {4,2,3,4,2,2,4};

    int ones = 0;   // bits appearing once
    int twos = 0;   // bits appearing twice

    for (int x : arr) {

        ones = (ones ^ x) & ~twos;   // Add bits to ones if not present in twos
        twos = (twos ^ x) & ~ones;   // Add bits to twos if not present in ones
        
    }

    cout<< ones;        // Remaining bits in ones represent the single number
   

 return 0;

}

