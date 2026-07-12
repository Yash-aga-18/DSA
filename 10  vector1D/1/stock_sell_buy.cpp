#include <bits/stdc++.h>
using namespace std;

// leetcode Q->121 Best Time to Buy and Sell Stock 

// You are given an array prices[] where prices[i] is the price of a stock on the ith day.

// You may choose a single day to buy one stock and choose a different day in the future to sell that stock.
// Return the maximum profit you can achieve.
// If no profit is possible, return 0.

// Example:
// Input:  prices = {7,1,5,3,6,4}
// Output: 5
// Explanation:
// Buy at price 1 and sell at price 6.
// Profit = 6 - 1 = 5.
// */



int maxProfit(vector<int>& prices) {

    int low = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); i++) {

        low =   min(low, prices[i]);
        
        profit = max(profit, prices[i] - low);
    }

    return profit;
}

int main() {

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Maximum Profit = " << maxProfit(prices);

    return 0;
}