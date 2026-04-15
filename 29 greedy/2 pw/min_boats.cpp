#include <bits/stdc++.h>
using namespace std;

// leetcode Q->881      Min Boats to Save People


int numRescueBoats(vector<int>& people, int limit) {

    // Step 1: Sort weights
    sort(people.begin(), people.end());

    int left = 0;                      // lightest person
    int right = people.size() - 1;     // heaviest person
    int count = 0;                     // number of boats

    // Step 2: Two pointer approach
    while (left <= right) {

        int curr_weight = people[left] + people[right];
        

        // if lightest + heaviest can go together
        if (curr_weight <= limit) {
            left++;   // move left (paired)
            right--;  // move right
        }

        else {  // heaviest goes alone
            right--;
        }

        count++; // one boat used in both cases
    }

    return count;
}



int main() {

    // Example input
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;

    int result = numRescueBoats(people, limit);

    cout << "Minimum Boats Needed: " << result << endl;

    return 0;
}