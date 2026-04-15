#include <bits/stdc++.h>
using namespace std;

// GFG ---> Min no. of platforms required


int minPlatform(vector<int>& arr, vector<int>& dep) {

    int n = arr.size();

    sort(arr.begin(), arr.end()); // sort arrivals
    sort(dep.begin(), dep.end()); // sort departures

    int i = 0, j = 0;
    int platforms = 0;
    int ans = 0;

    while(i < n && j < n) {

        if(arr[i] <= dep[j]) {
            platforms++;   // new train arrives
            i++;
        }
        else {
            platforms--;   // train departs
            j++;
        }

        ans = max(ans, platforms); // track max platforms needed
    }

    return ans;
}

int main() {

    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << minPlatform(arr, dep) << endl;

    return 0;
}