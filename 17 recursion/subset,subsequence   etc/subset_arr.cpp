#include <bits/stdc++.h>
using namespace std;
//subset == subsequence

// leetcode Q->78   return subsets of arr having unique elemnts
// Input: nums = [1,2,3]
// Output:       [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


// leetcode Q->90   return subsets of arr having duplicats elemnts but not in result
// Input: nums = [1,2,2]
// Output:       [[],[1],[1,2],[1,2,2],[2],[2,2]]



void backtrack(vector<int>& arr, int start, vector<int>& path, vector<vector<int>>& result) {

    result.push_back(path);
    

    for (int i = start; i < arr.size(); i++) {                // loop acts as base cond for return
        
        if (i > start && arr[i] == arr[i - 1])      continue;       // to skip the duplicate elemnt
        
        path.push_back(arr[i]);
        backtrack(arr, i+1, path, result);
        path.pop_back();

    }

}

vector<vector<int>> subsets(vector<int>& arr) {

    vector<int> path;
    vector<vector<int>> result;

    sort(arr.begin(), arr.end());           // Sort to bring duplicates together
    backtrack(arr, 0, path, result);

    return result;

}


int main() {
    
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> output = subsets(arr);

    
    for (vector<int> subset : output) {     // Print all 

        cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i != subset.size() - 1)       cout << ",";          // to exclude last
        }
        cout << "]" << endl;
    
    }

    return 0;

}

/*
====================================================================
                     SUBSET BACKTRACKING TRACE
====================================================================

CALL: start = 0, path = { }
  -> PUSH to result: { }

FOR LOOP: i = 0 to 2
--------------------------------------------------------------

i = 0   (arr[0] = 1)
    CHOOSE  → push 1
    path = { 1 }
    RECURSE → backtrack(start = 1)


====================================================================
CALL: start = 1, path = { 1 }
  -> PUSH to result: { 1 }

FOR LOOP: i = 1 to 2
--------------------------------------------------------------

i = 1   (arr[1] = 2)
    CHOOSE  → push 2
    path = { 1 2 }
    RECURSE → backtrack(start = 2)


====================================================================
CALL: start = 2, path = { 1 2 }
  -> PUSH to result: { 1 2 }

FOR LOOP: i = 2 to 2
--------------------------------------------------------------

i = 2   (arr[2] = 3)
    CHOOSE  → push 3
    path = { 1 2 3 }
    RECURSE → backtrack(start = 3)


====================================================================
CALL: start = 3, path = { 1 2 3 }
  -> PUSH to result: { 1 2 3 }

FOR LOOP: i = 3 to 2   (NO ITERATIONS)

    BACKTRACK ← pop 3
    path = { 1 2 }

BACKTRACK ← pop 2
path = { 1 }


--------------------------------------------------------------
i = 2   (arr[2] = 3)
    CHOOSE → push 3
    path = { 1 3 }
    RECURSE → backtrack(start = 3)


====================================================================
CALL: start = 3, path = { 1 3 }
  -> PUSH to result: { 1 3 }

FOR LOOP: i = 3 to 2   (NO ITERATIONS)

    BACKTRACK ← pop 3
    path = { 1 }

BACKTRACK ← pop 1
path = { }


--------------------------------------------------------------
i = 1   (arr[1] = 2)
    CHOOSE → push 2
    path = { 2 }
    RECURSE → backtrack(start = 2)


====================================================================
CALL: start = 2, path = { 2 }
  -> PUSH to result: { 2 }

FOR LOOP: i = 2 to 2
--------------------------------------------------------------

i = 2   (arr[2] = 3)
    CHOOSE → push 3
    path = { 2 3 }
    RECURSE → backtrack(start = 3)


====================================================================
CALL: start = 3, path = { 2 3 }
  -> PUSH to result: { 2 3 }

FOR LOOP: i = 3 to 2   (NO ITERATIONS)

    BACKTRACK ← pop 3
    path = { 2 }

BACKTRACK ← pop 2
path = { }


--------------------------------------------------------------
i = 2   (arr[2] = 3)
    CHOOSE → push 3
    path = { 3 }
    RECURSE → backtrack(start = 3)


====================================================================
CALL: start = 3, path = { 3 }
  -> PUSH to result: { 3 }

FOR LOOP: i = 3 to 2   (NO ITERATIONS)

    BACKTRACK ← pop 3
    path = { }


====================================================================
                      FINAL SUBSETS GENERATED
====================================================================
{ }
{ 1 }
{ 1 2 }
{ 1 2 3 }
{ 1 3 }
{ 2 }
{ 2 3 }
{ 3 }

====================================================================
*/

