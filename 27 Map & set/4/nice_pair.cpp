#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1814  Count nice pair

// Nice pair is --> nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

// Hint-->  if nums[i] - rev(nums[i]) == nums[j] - rev(nums[i])
// so we had to check if there exist the same diff alrraedy in map or not



// function to reverse a number
int rev(int num)
{
    int ans = 0;

    while(num > 0)
    {
        ans = ans * 10 + (num % 10);
        num = num / 10;
    }

    return ans;
}


// function to count nice pairs
int countNicePairs(vector<int>& nums)
{
    unordered_map<int, int> mp;

    long long ans = 0;
    int MOD = 1e9 + 7;

    for(int ele : nums)
    {
        int diff = ele - rev(ele);

        // existing elements with same diff form valid pairs
        ans = (ans + mp[diff]) % MOD;

        // increase frequency
        mp[diff]++;
    }

    return ans;
}


// ===============================
// MAIN FUNCTION
// ===============================
int main()
{
    vector<int> nums = {42, 11, 1, 97};

    int res = countNicePairs(nums);

    cout << res << endl;

    return 0;
}