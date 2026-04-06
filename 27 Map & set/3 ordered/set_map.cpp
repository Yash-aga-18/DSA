#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ===============
    // ORDERED MAP    
    // ===============

    map<int,int> mp;

    // INSERTION (O(log n))
    mp[1] = 10;
    mp[3] = 30;
    mp[2] = 20;
    mp[5] = 50;
    mp[4] = 40;
    mp[0] = 60;


    // Traversal (always sorted by key)     //  imp
    cout << mp.size() << endl;
    for(auto ele : mp)  cout << ele.first << " " << ele.second << endl;
    cout << endl;

    // Duplicate keys NOT allowed (value gets updated)
    mp[2] = 200;
    mp[2] = 300;

    mp[10] = 1000;

    // DELETE (O(log n))
    mp.erase(3);

    cout << mp.size() << endl;
    for(auto ele : mp)  cout << ele.first << " " << ele.second << endl;
    cout << endl;

    int key = 3;

    // SEARCH (O(log n))
    if(mp.find(key) != mp.end())            cout << "exist" << endl;
    else                                    cout << "not exist" << endl;

    // Inserts key 100 with default value 0
    cout << mp[100] << endl;


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // ==============
    // ORDERED SET 
    // ==============

    set<int> s;

    // INSERTION (Average O(1))
    s.insert(10);
    s.insert(40);
    s.insert(30);
    s.insert(20);
    s.insert(1);
    s.insert(0);
    s.insert(4);

    // Traversal (order is alway sorted, depends on hashing)
    cout << s.size() << endl;
    for(int ele : s)     cout << ele << " ";
    cout << endl;

    // Duplicate elements are NOT allowed
    s.insert(40);  // ignored
    s.insert(40);  // ignored
    s.insert(40);  // ignored

    s.insert(200);
    s.insert(100);

    // DELETE operation
    s.erase(30);

    cout << s.size() << endl;
    for(int ele : s)     cout << ele << " ";
    cout << endl;

    // SEARCH operation
    int target = 30;
    if( s.find(target) != s.end() )   cout << "exist" << endl;
    else                            cout << "not exist" << endl;
    

    return 0;
}

/*
    =========================
    ORDERED MAP (map)
    =========================

    • Based on Red-Black Tree (BST)
    • Keys are always SORTED

    -------------------------
    Time Complexity    <-- IMP
    -------------------------
    INSERTION : O(log n)
    DELETE    : O(log n)
    SEARCH    : O(log n)

    -------------------------
    Important Notes
    -------------------------
    • mp[key] → inserts key if not present (default = 0)
    • mp.find(x) → safe search (does NOT insert)
    • Duplicate keys NOT allowed
    • Stores data in sorted order (by key)


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    =========================
    ORDERED SET (set)
    =========================

    • Based on Red-Black Tree (BST)
    • Elements are always SORTED

    -------------------------
    Time Complexity    <-- IMP
    -------------------------
    INSERTION : O(log n)
    DELETE    : O(log n)
    SEARCH    : O(log n)

    -------------------------
    Important Notes
    -------------------------
    • Duplicate elements NOT allowed
    • Stores only keys (no value like map)
    • Automatically keeps elements sorted
    • s.find(x) → returns iterator if found, else s.end()
    • s.count(x) → returns 1 (exists) or 0 (not exists)
*/