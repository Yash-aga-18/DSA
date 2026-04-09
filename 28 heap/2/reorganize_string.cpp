#include <bits/stdc++.h>
using namespace std;

// leetcode Q->767  Reorganize string such a way that 2 adjacent char must not have same value


string reorganizeString(string str) {

    unordered_map<char, int> freq;
    for(char ch : str)    freq[ch]++;
    

    // max heap -> {frequency, character}
    priority_queue<pair<int, char>> pq;

    for(auto it : freq) {
        pq.push( {it.second, it.first} );
    }

    string ans = "";

    while(pq.size() > 1) {

        auto p1 = pq.top(); 
        pq.pop();
        
        auto p2 = pq.top(); 
        pq.pop();


        ans += p1.second;
        ans += p2.second;

        p1.first--;
        p2.first--;

        if(p1.first > 0) pq.push(p1);
        if(p2.first > 0) pq.push(p2);
    }

    // if one element left
    if(!pq.empty()) {
        auto last = pq.top(); 
        pq.pop();

        if(last.first > 1)  return ""; // not possible

        ans += last.second;
    }

    return ans;
}

int main() {

    string s = "aab";

    cout << reorganizeString(s) << endl; // aba

    return 0;
}