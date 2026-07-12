#include <bits/stdc++.h>
using namespace std;


/*
// leetcode Q->2149 


You are given an array of even length consisting of an 
equal number of positive and negative integers.

Rearrange the array such that:
1. Positive and negative numbers alternate.
2. The relative order of positives is maintained.
3. The relative order of negatives is maintained.
4. The first element is positive.

Example:
Input : [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]

Time Complexity : O(n)
Space Complexity: O(n)
*/


vector<int> rearrangeEqual(vector<int> &nums) {

    vector<int> ans(nums.size());

    int pos = 0;
    int neg = 1;

    for (int x : nums) {

        if (x > 0) {
            ans[pos] = x;
            pos += 2;
        }
        else {
            ans[neg] = x;
            neg += 2;
        }
    }

    return ans;
}

/*
=========================================================
Question 2: GFG - Rearrange Array Alternately
=========================================================

Given an array containing positive and negative numbers.
Rearrange them alternately while preserving their relative order.

If one type of number is exhausted, append the remaining
elements at the end.

Example:

Input:  [9,4,-2,-1,5,0,-5,-3,2]
Output: [9,-2,4,-1,5,-5,0,-3,2]

Time Complexity : O(n)
Space Complexity: O(n)
*/

vector<int> rearrangeGFG(vector<int> &arr) {

    vector<int> pos;
    vector<int> neg;

    // Separate positives and negatives
    for (int x : arr) {

        if (x >= 0)     pos.push_back(x);
        else            neg.push_back(x);
    }

    vector<int> ans;

    int i = 0;
    int j = 0;

    // Alternate positives and negatives
    while (i < pos.size() && j < neg.size()) {

        ans.push_back(pos[i++]);
        ans.push_back(neg[j++]);
    }

    // Remaining positives
    while (i < pos.size())      ans.push_back(pos[i++]);

    // Remaining negatives
    while (j < neg.size())      ans.push_back(neg[j++]);

    return ans;
}



int main() {

    // -------- LeetCode Example --------
    vector<int> arr1 = {3,1,-2,-5,2,-4};

    vector<int> ans1 = rearrangeEqual(arr1);

    cout << "LeetCode Output:\n";

    for (int x : ans1)
        cout << x << " ";

    cout << "\n\n";

    // -------- GFG Example --------
    vector<int> arr2 = {9,4,-2,-1,5,0,-5,-3,2,1,4,5};

    vector<int> ans2 = rearrangeGFG(arr2);

    cout << "GFG Output:\n";

    for (int x : ans2)
        cout << x << " ";

    cout << endl;

    return 0;
}