#include <bits/stdc++.h>
using namespace std;

// Lower Bound -> First element >= target
int lowerBound(vector<int>& arr, int target) {

    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

// Upper Bound -> First element > target
int upperBound(vector<int>& arr, int target) {

    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    vector<int> v = {1,2,4,5,9,15,18,21,24};

    int target = 10;

    int lb = lowerBound(v, target);
    int ub = upperBound(v, target);

    cout << "Lower Bound Index : " << lb << endl;

    if (lb == v.size())
        cout << "Lower Bound Value : Doesn't exist\n";
    else
        cout << "Lower Bound Value : " << v[lb] << endl;

    cout << endl;




    cout << "Upper Bound Index : " << ub << endl;

    if (ub == v.size())
        cout << "Upper Bound Value : Doesn't exist\n";
    else
        cout << "Upper Bound Value : " << v[ub] << endl;
}