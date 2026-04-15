#include <bits/stdc++.h>
using namespace std;

// leetcode Q->135  Candy 
// distribute min. candy such that the high rank children gets more than neighbour



// =======================
// 1. Two Pass Solution
// =======================
int candyTwoPass(vector<int>& ratings) {

    int n = ratings.size();
    vector<int> candies(n, 1); // each gets at least 1

    // left → right
    for(int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }

    // right → left
    for(int i = n-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]) {
            candies[i] = max(candies[i], candies[i+1] + 1);
        }
    }

    // sum all candies
    return accumulate(candies.begin(), candies.end(), 0);
}


// =======================
// 2. Optimal (Slope)
// =======================
int candyOptimal(vector<int>& ratings) {

    int n = ratings.size();
    if(n == 0) return 0;

    int sum = 1; // first child
    int i = 1;

    while(i < n) {

        // equal ratings
        if(ratings[i] == ratings[i-1]) {
            sum += 1;
            i++;
            continue;
        }

        // increasing slope
        int peak = 1;
        while(i < n && ratings[i] > ratings[i-1]) {
            peak++;
            sum += peak;
            i++;
        }

        // decreasing slope
        int down = 1;
        while(i < n && ratings[i] < ratings[i-1]) {
            sum += down;
            down++;
            i++;
        }

        // fix peak overlap
        if(down > peak)     sum += down - peak;
        
    }

    return sum;
}


// =======================
// MAIN
// =======================
int main() {

    vector<int> ratings = {1,3,6,8,9,5,3};

    cout << "Two Pass: " << candyTwoPass(ratings) << endl;
    cout << "Optimal : " << candyOptimal(ratings) << endl;

    return 0;
}