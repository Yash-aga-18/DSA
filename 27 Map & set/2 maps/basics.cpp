#include <bits/stdc++.h>
using namespace std;

int main()
{
    // =========================
    // UNORDERED MAP (Hash Table)      
    // =========================

//  Map works on principle of (Key,value) pair

    unordered_map<int,int> mp;

    // insertion
    mp[1] = 10;
    mp[2] = 20;
    mp[3] = 30;
    mp[4] = 40;
    mp[5] = 50;

    cout << mp.size() << endl;
    for(auto ele : mp)     cout << ele.first << " " << ele.second << endl;
    cout << endl;

    // Duplicate keys NOT allowed (value gets updated)
    mp[2] = 200;   // updated
    mp[2] = 300;   // updated again

    mp[10] = 1000;
    mp.erase(3);

    cout << mp.size() << endl;
    for(auto ele : mp)     cout << ele.first << " " << ele.second << endl;
    cout << endl;

    int key = 3;

    if( mp.find(key) != mp.end() )   cout << "exist" << endl;
    else                             cout << "not exist" << endl;
    
    cout << mp[100] << endl;   // creates key 100 with value 0


    // NOTE:
    // mp[key] -> inserts key if not present (default value 0)
    // mp.find(x) -> safe search (does NOT insert)


}

/*
    // INSERTION (O(log n))
    // Traversal (order is NOT sorted)    we can also use pair instead of auto 

    // DELETE operation (Average O(1))
    // SEARCH operation (Average O(1))

*/