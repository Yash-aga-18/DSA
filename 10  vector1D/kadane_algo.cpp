#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1, 2, -1, 1, 1, -3, 2, 1};
    // vector<int> nums = {-3, -2, -1, -4}; // test all-negative case

    int sum = 0;
    int maxSum = INT_MIN;
    int start = 0, left = 0, right = 0;

    for (int i = 0; i < nums.size(); i++) {
        
        sum += nums[i];

        if (sum > maxSum) {
            maxSum = sum;
            left = start;
            right = i;
        }

        if (sum < 0) {
            sum = 0;
            start = i + 1;
        }

    }


    // if all numbers are negative
    if (maxSum == INT_MIN) {

        maxSum = nums[0];
        left = right = 0;
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > maxSum) {
                maxSum = nums[i];
                left = right = i;
            }

        }

    }


    cout << "Maximum Subarray: ";
    for (int i = left; i <= right; i++) {
        cout << nums[i] << " ";
    }
    cout << "\nMaximum Sum = " << maxSum << endl;

    return 0;
}
