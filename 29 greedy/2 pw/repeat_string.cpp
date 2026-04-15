#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2182     Construct String With Repeat Limit


string repeatLimitedString(string str, int repeatLimit) {


    unordered_map<char, int> mp;
    for(char ch : str) mp[ch]++;


    // Step 2: max heap (largest char first)
    priority_queue<char> pq;
    for(auto ele : mp) pq.push(ele.first);



    string ans = "";

    while(!pq.empty()) {

        char curr = pq.top();
        pq.pop();

        int freq = mp[curr];

        // use upto repeatLimit
        int use = min(repeatLimit, freq);

        for(int i = 0; i < use; i++)        ans += curr;
        mp[curr] -= use;


        // if still remaining → need breaker
        if(mp[curr] > 0) {

            // IMPORTANT FIX
            if(pq.empty()) break;       // no smaller char → stop

            char next = pq.top();

            ans += next;
            mp[next]--;

            // pop back next if not exists
            if(mp[next] == 0)   pq.pop();

            // push current back (still remaining)
            pq.push(curr);
        }
        
    }

    return ans;
}


int main() {

    string str = "cczazcc";
    int repeatLimit = 3;

    string ans = repeatLimitedString(str, repeatLimit);

    cout << "Result: " << ans << endl;

    return 0;
}