#include <bits/stdc++.h>
using namespace std;

// leetcode Q->119 
// return only specific row (0-based indexing) 

// Input: rowIndex = 3
// Output: [1,3,3,1]

int main() {

  int n;  
  cout<<"enter which row to print"<<endl;
  cin>>n;

    vector<int> row(n + 1, 0);    // size n+1, initialized with 0
    row[0] = 1;                   // first element always 1

    for (int i = 1; i <= n; i++) {
      for (int j = i; j > 0; j--) {   // update in reverse to avoid overwriting needed values

        row[j] += row[j - 1];
      }
    }

    for (int ele : row)     cout<<ele<<" ";

 return 0;

}


/*Step-by-step Example (n = 4)
Initial:
row = [1, 0, 0, 0, 0]

i = 1:

j = 1 → row[1] += row[0] → 0 + 1 = 1

row = [1, 1, 0, 0, 0]

i = 2:

j = 2 → row[2] += row[1] → 0 + 1 = 1

j = 1 → row[1] += row[0] → 1 + 1 = 2

row = [1, 2, 1, 0, 0]

i = 3:

j = 3 → row[3] += row[2] → 0 + 1 = 1

j = 2 → row[2] += row[1] → 1 + 2 = 3

j = 1 → row[1] += row[0] → 2 + 1 = 3

row = [1, 3, 3, 1, 0]

i = 4:

j = 4 → row[4] += row[3] → 0 + 1 = 1

j = 3 → row[3] += row[2] → 1 + 3 = 4

j = 2 → row[2] += row[1] → 3 + 3 = 6

j = 1 → row[1] += row[0] → 3 + 1 = 4

row = [1, 4, 6, 4, 1]


✅ Final row (n = 4): 1 4 6 4 1
  */