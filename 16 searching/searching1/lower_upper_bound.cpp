#include <bits/stdc++.h>
using namespace std;

// Ques: Given a sorted integer array and an integer ‘x’, find the lower,upper bound of x. 
// eg--> 1,4,7,8,9,15,17,25     lower bound of 20 is 17 and upper is 25


int main() {

    vector<int> v = {1 ,2, 4, 5, 9, 15, 18, 21, 24};
    int n = v.size();
    int target = 9;

    int lower = -1;
    int upper = -1;

    // Boundary cases
    if (target < v[0]) {
        lower = -1;
        upper = v[0];
    }

    else if (target > v[n - 1]) {
        lower = v[n - 1];
        upper = -1;
    }

    else {

        int low = 0;
        int high = n - 1;
        int mid = -1;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (v[mid] < target) {
                lower = v[mid];
                low = mid + 1;
            }

            else if (v[mid] > target) {
                upper = v[mid];
                high = mid - 1;
            }

            else {          // v[mid] == target

                if (mid > 0)      lower = v[mid - 1];
                if (mid < n - 1)  upper = v[mid + 1];
                break;

            }
        }

    }

    cout << "Lower bound: ";
    if (lower == -1) cout << "does not exist";
    else cout << lower;

    cout << "\nUpper bound: ";
    if (upper == -1) cout << "does not exist";
    else cout << upper;

    return 0;
}

