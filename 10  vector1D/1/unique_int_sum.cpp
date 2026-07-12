#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1304  Find N Unique Integers Sum up to Zero

// Input: n = 5
// Output: [-7,-1,1,3,4]
// Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

int main()
{
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;

    vector<int> v(n, 0);
    int a = 1;
    if (v.size() % 2 != 0)   n--;       
    // to make ensure loop runs even time and in odd add last elemnt automatically to 0

    for (int i = 0; i < n; i += 2)  {

        v[i]     = a;
        v[i + 1] = -a;
        a++;    // to have new integer 

    }

    for(int ele:v)  cout<<ele<<" ";      // to print


    return 0;
}