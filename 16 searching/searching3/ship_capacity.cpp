#include <bits/stdc++.h>#include <numeric>   // <-- needed for accumulate

using namespace std;


// leetcode Q->1011   Capacity To Ship Packages Within D Days

// you have given some weights and some days  you have to utilize all the days but
//  you have to minimize the no. of capacity you want to transfer the weight in a day.
//  weights can be picked only in the same order as given.


// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// we can also take the capacity like 100 but we have to reduce it so even we can transfer all the weights also


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// bool check(int mid, vector<int> &weight, int days, int n){


//     int m = mid;        // m denotes the capacity
//     int count = 1;      // helps to count days  
//     int sum = 0;
    
//     for(int i=0; i<n; i++){

//         if( m>= weight[i]){       // it can carry the load
//             m -= weight[i];
//         }
//         else{
//             count++;
//             m = mid;            // to ready the ship for next day we reset the capacity
//             m -= weight[i];     // also loads the weight
            
//         }

//     }

//     if(count<=days) return true;
//     else            return false;

// }



// int main()
// {

//     vector<int>weight = {3,2,2,4,1,4};
//     int days = 3;

//     int n = weight.size();

// // Step1--> You have to find the possible min and max capacity

//     int min = INT_MIN;          // min capacity possible is max weight
//     int max = 0;                // max capacity can be anything but we take their sum 

// for(int i=0; i<n; i++){
//     if(min<weight[i])   min = weight[i];
//     max += weight[i];
// }


//     int low = min;
//     int high = max;
//     int mid = -1;
//     int capacity = 0;

//     while(low<=high){
//         mid = low + (high-low)/2;

//         if(check(mid,weight,days,n)){

//             capacity = mid;
//             high = mid-1;
//         }
//         else  low = mid+1; 

//     }

//     cout<<"min capacity required is "<<capacity;

    
  
//  return 0;

// }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Check function to verify if a given capacity can ship all packages in "days"

bool check(int mid, vector<int> &weight, int days, int n) {

    int usedDays = 1;       // start with day 1
    int currLoad = 0;       // current day's load

    for (int i = 0; i < n; i++) {

        int item = weight[i];            // current weight
        int possible = currLoad + item;      

        if (possible <= mid) {           // can we add this item today
            currLoad = possible;              
        }
        else {

            usedDays++;                     // need new day
            currLoad = item;                // start new day with this item

        }
    }

    return usedDays <= days;        // return true if usedDays <= given days
}



int main() {

    vector<int> weight = {3,2,2,4,1,4};
    int days = 3;

    int n = weight.size();

    // Step 1 -> Find min and max possible capacity

    int minCap = *max_element(weight.begin(), weight.end());  // at least max weight
    int maxCap = accumulate(weight.begin(), weight.end(), 0); // sum of all weights

    int low = minCap, high = maxCap;
    int capacity = maxCap;   // default answer

    // Binary Search
    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (check(mid, weight, days, n)) {

            capacity = mid;      // mid is a possible answer
            high = mid - 1;      // try smaller capacity
        }


        else    low = mid + 1;       // increase capacity
        
    }

    
    cout << "min capacity required is " << capacity;

    return 0;
    
}
