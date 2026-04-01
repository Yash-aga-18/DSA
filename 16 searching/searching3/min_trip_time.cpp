#include <bits/stdc++.h>
using namespace std;

// // leetcode Q->2187   Minimum Time to Complete Trips

// you had given time  in time[i] and totaltrips. 
// there are seperate buses and each bus takes time[i] to complete a trip. you have to return
// min. time required for all buses to complete at least totalTrips trips. 

// Input: time = [1,2,3], totalTrips = 5
// Output: 3
// Explanation:
// - At time t = 1, the number of trips completed by each bus are [1,0,0]. 
// - At time t = 2, the number of trips completed by each bus are [2,1,0]. 
// - At time t = 3, the number of trips completed by each bus are [3,1,1]. 
//   Now The total number of trips completed is 3 + 1 + 1 = 5.

// So the minimum time needed for all buses to complete at least 5 trips is 3.


bool check(int mid, vector<int>& time, int totaltrips) {

    int trips = 0;
    int n = time.size();

    for (int i = 0; i < n; i++) {

        trips += mid / time[i];

        // early exit
        if (trips >= totaltrips)    return true;
    }

    return trips >= totaltrips;

}


int main() {

    vector<int> time = {1, 2, 3};
    int totaltrips = 5;

    int n = time.size();

    // Step 1 -> find min and max possible time
    int minTime = 1;

    int maxElem = *max_element(time.begin(), time.end());
    int maxTime = maxElem * totaltrips;   

    int low = minTime;
    int high = maxTime;
    int ans = maxTime;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (check(mid, time, totaltrips)) {
            ans = mid;         
            high = mid - 1;
        } 

        else    low = mid + 1;    
        
    }

    cout << "min time required is " << ans;

    return 0;
}


/*
maxElem * totaltrips ?
maxElem = the slowest bus (largest time per trip)

Example:
time = [1,2,3]
maxElem = 3

This means one bus needs 3 units to finish 1 trip.
If we let only the slowest bus do all trips alone:
totalTrips = 5
Total time = 3 * 5 = 15

*/

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
Brute force approcah-->

// - At time t = 1, the number of trips completed by each bus are [1/1, 1/2, 1/3] = [1,0,0] 
// - At time t = 2, the number of trips completed by each bus are [2/1, 2/2, 2/3] = [2,1,0] 
// - At time t = 3, the number of trips completed by each bus are [3/1, 3/2, 3/3] = [3,1,1] 

here we get so stops and ans  = 3;


*/
