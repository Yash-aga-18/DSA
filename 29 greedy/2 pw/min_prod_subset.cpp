#include <bits/stdc++.h>
using namespace std;

int minProductSubset(vector<int>& arr) {

    int n = arr.size();

    int count_neg = 0;
    int count_zero = 0;

    int max_neg = INT_MIN; // closest to 0
    int min_pos = INT_MAX;

    int prod = 1;

    for(int i = 0; i < n; i++) {

        if(arr[i] == 0) {
            count_zero++;
            continue;
        }

        if(arr[i] < 0) {
            count_neg++;
            max_neg = max(max_neg, arr[i]);
        }

        if(arr[i] > 0) {
            min_pos = min(min_pos, arr[i]);
        }

        prod *= arr[i];
    }


    // all zeros
    if(count_zero == n)     return 0;

    // no negative
    if(count_neg == 0) {
        if(count_zero > 0) return 0;
        
        return  min_pos;
    }

    // even negatives → remove one
    if(count_neg % 2 == 0) {
        prod /= max_neg;
    }

    return prod;
}

int main() {

    vector<int> arr = {-1, -1, -2, 4, 3};

    int result = minProductSubset(arr);

    cout << "Minimum Product Subset: " << result << endl;

    return 0;
}