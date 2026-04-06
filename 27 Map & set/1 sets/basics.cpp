#include <bits/stdc++.h>
using namespace std;

int main()
{
    // =========================
    // UNORDERED SET (Hash Table)
    // =========================

    unordered_set<int> s;

    // INSERTION (Average O(1))
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);

    // Traversal (order is NOT sorted, depends on hashing)
    cout << s.size() << endl;
    for(int ele : s)     cout << ele << " ";
    cout << endl;

    // Duplicate elements are NOT allowed
    s.insert(40);  // ignored
    s.insert(40);  // ignored
    s.insert(40);  // ignored

    s.insert(100);
    s.insert(200);

    // DELETE operation (Average O(1))
    s.erase(30);

    cout << s.size() << endl;
    for(int ele : s)     cout << ele << " ";
    cout << endl;

    // SEARCH operation (Average O(1))
    int target = 30;

    if( s.find(target) != s.end() )   cout << "exist" << endl;
    else                            cout << "not exist" << endl;
    

    // NOTE:
    // s.find(x) returns iterator to element if found
    // otherwise returns s.end()

    return 0;
}