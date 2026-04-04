#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2094  Finding 3-Digit Even Numbers

// return all the possible unique integers having :
//   it must be even
//   should be of length 3
//   should not have leading zeroes




// ===============================
// APPROACH 1: Using 2 Maps
// ===============================
vector<int> usingMaps(vector<int>& arr)
{
    unordered_map<int,int> mp;

    // build frequency map
    for(int d : arr)    mp[d]++;

    vector<int> ans;

    // check all 3-digit even numbers
    for(int i = 100; i <= 999; i += 2)
    {
        int x = i;

        int a = x % 10;   // ones
        x /= 10;

        int b = x % 10;   // tens
        x /= 10;

        int c = x;        // hundreds

        // copy map
        unordered_map<int,int> temp = mp;

        // check availability
        if(temp[a] > 0)
        {
            temp[a]--;

            if(temp[b] > 0)
            {
                temp[b]--;

                if(temp[c] > 0)
                {
                    temp[c]--;
                    ans.push_back(i);
                }
            }
        }
    }

    return ans;
}


// ===============================
// APPROACH 2: Using Frequency Array (BEST)
// ===============================
vector<int> usingFreqArray(vector<int>& arr)
{
    vector<int> freq(10, 0);

    // build frequency array
    for(int d : arr)    freq[d]++;

    vector<int> ans;

    // check all 3-digit even numbers
    for(int i = 100; i <= 999; i += 2)
    {
        int x = i;

        int a = x % 10;   // ones
        x /= 10;

        int b = x % 10;   // tens
        x /= 10;

        int c = x;        // hundreds

        // required digits
        vector<int> need(10,0);

        need[a]++;
        need[b]++;
        need[c]++;

        bool valid = true;

        // compare required vs available
        for(int d = 0; d <= 9; d++)
        {
            if(need[d] > freq[d])
            {
                valid = false;
                break;
            }
        }

        if(valid)   ans.push_back(i);
    }

    return ans;
}



int main()
{
    vector<int> arr = {2,1,3,0};

    vector<int> ans1 = usingMaps(arr);
    vector<int> ans2 = usingFreqArray(arr);

    cout << "Using Maps:\n";
    for(int x : ans1)
        cout << x << " ";
    cout << endl;
    cout << endl;

    cout << "Using Freq Array:\n";
    for(int x : ans2)
        cout << x << " ";
    cout << endl;

    return 0;
}