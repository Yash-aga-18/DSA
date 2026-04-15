#include <bits/stdc++.h>
using namespace std;

// leetcode Q->781      Rabbits in Forest   


int numRabbits(vector<int>& answers) {

    // Step 1: count frequency of each answer
    unordered_map<int, int> mp;
    for(int x : answers)    mp[x]++;
    

    int total = 0;

    // Step 2: process each group
    for(auto it : mp) {

        int x = it.first;    // answer
        int count = it.second;

        int groupSize = x + 1; // each group size

        // number of groups needed (ceil)
        int groups = (count + groupSize - 1) / groupSize;

        total += groups * groupSize;
    }

    return total;
}

int main() {

    // Example input
    vector<int> answers = {1, 1, 2};

    int result = numRabbits(answers);

    cout << "Minimum Rabbits: " << result << endl;

    return 0;
}