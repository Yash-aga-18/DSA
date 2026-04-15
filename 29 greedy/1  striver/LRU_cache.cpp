#include <bits/stdc++.h>
using namespace std;

// GFG---> Page Faults in LRU


int pageFaults(int N, int C, int pages[]) {

    unordered_set<int> st;        // pages in memory
    unordered_map<int,int> last;  // last used index

    int faults = 0;

    for(int i = 0; i < N; i++) {

        int page = pages[i];

        // page not in memory → fault
        if(st.find(page) == st.end()) {

            faults++;

            // if memory full → remove LRU
            if(st.size() == C) {

                int lruPage = -1;
                int minIndex = INT_MAX;

                // find least recently used page
                for(auto x : st) {
                    if(last[x] < minIndex) {
                        minIndex = last[x];
                        lruPage = x;
                    }
                }

                st.erase(lruPage);
                last.erase(lruPage); // clean removal
            }

            st.insert(page);
        }

        last[page] = i; // update usage
    }

    return faults;
}



int main() {

    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int N = 12;
    int C = 3;

    cout << pageFaults(N, C, pages) << endl;

    return 0;
}