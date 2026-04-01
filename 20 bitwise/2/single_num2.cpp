#include <bits/stdc++.h>
using namespace std;

// given an array, every elemnt apearring twice except only 1 single item

int main()
{
    
    vector<int>arr = {4,2,3,4,2};

    int res = 0;
    for(int i=0; i<arr.size(); i++){
        res = res^arr[i];
    }

    cout<<res;

 return 0;

}

// as XOR of 2 same elemnts is 0 and it will showup only the unique value