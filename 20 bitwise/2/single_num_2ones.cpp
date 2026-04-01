#include <bits/stdc++.h>
using namespace std;

// given an array, every elemnt apearring twice except only 2 single items

int main()
{
    
    vector<int> nums = {1, 2, 1, 3, 2, 5};

    int res = 0;

    // Step 1: XOR all numbers (duplicates cancel out)
    for (int x : nums) {
        res = res ^ x;
    }
    // res = a ^ b (a and b are the two unique numbers)

    // Step 2: Find rightmost set bit
    int rightmost = (res & (res - 1)) ^ res;

    int b1 = 0, b2 = 0;

    // Step 3: Divide numbers into two groups
    for (int x : nums) {
        if (x & rightmost)  b1 = b1 ^ x;   // group 1
        else                b2 = b2 ^ x;   // group 2
    }

    // Step 4: Result
    cout << "Unique numbers are: " << b1 << " and " << b2 << endl;

    return 0;

}

