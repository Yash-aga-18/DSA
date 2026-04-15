#include <bits/stdc++.h>
using namespace std;

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
    int n = deadline.size();

    vector<pair<int,int>> jobs;
    for(int i = 0; i < n; i++) {
        jobs.push_back({profit[i], deadline[i]});
    }

    // sort by profit (descending)
    sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());

    int maxDeadline = *max_element(deadline.begin(), deadline.end());

    vector<int> slot(maxDeadline+1, -1); // time slots
    
    int count = 0;
    int totalProfit = 0;

    for(int i = 0; i < n; i++) {

        int prof = jobs[i].first;
        int dead = jobs[i].second;

        // find free slot from dead → 1
        for(int j = dead; j > 0; j--) {

            if(slot[j] == -1) {
                
                slot[j] = i;      // assign job
                
                count++;
                totalProfit += prof;
                
                break;
                
            }
        }
        
        
    }

    return {count, totalProfit};

    
}

int main() {

    vector<int> deadline = {2, 2, 1, 3};
    vector<int> profit   = {50, 10, 20, 30};

    vector<int> ans = jobSequencing(deadline, profit);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}