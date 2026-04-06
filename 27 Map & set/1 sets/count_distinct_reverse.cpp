#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2442     Count distinct elemnts can be in vector after reversing it


// reverse a number
int rev(int n) {
    
    int temp = 0;

    while (n > 0) {
        int rem = n % 10;
        temp = temp * 10 + rem;
        n = n / 10;
    }

    return temp;
}


// main logic
int countDistinctIntegers(vector<int>& nums) {

    unordered_set<int> s;

    for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);          // original
        s.insert(rev(nums[i]));     // reversed
    }

    return s.size();
}



int main() {

    vector<int> nums = {1, 13, 10, 12, 31};

    int ans = countDistinctIntegers(nums);

    cout << "Distinct count = " << ans << endl;

    return 0;
}