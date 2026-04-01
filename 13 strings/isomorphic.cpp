#include <bits/stdc++.h>
using namespace std;

// leetcode Q->205

// to check 2 strings are isomorphic
// isomorphic means thatr 2 strrings are connected to each other by a specific character
// eg->    eggtree   anndraa      e is mapped to a or vice versa
// eg-->   badc      baba      it looks well when we see from perspective of 1st string but
//                             from 2nd string perspective b is mapped to d and b so it is not isomorphic

int main()
{
    string s1 = "abac";
    string s2 = "xyyx";

    //     if(s1.length() != s2.length()){
    //         cout<<"length issue not isomorphic";
    //         return 0;
    //     }

    //     vector<int>arr(150,-1);           // almost all the chracters lie less than 150 ascii value
    //     // we stored -1 as we had to take the sum of ascii values and sum can never be negative

    // // checks mapping from s1 to s2

    //     for(int i=0; i<s1.length(); i++){

    //         int idx = int(s1[i]);                     // idx stores the ascii value
    //         int sum = s1[i]+s2[i];

    //         if( arr[idx] == -1)     arr[idx] = sum;     // we store their sum value

    //         else if (arr[idx] != sum) {      // it works when value is stored already i.e their sum
    //             cout<<"not isomorphic";
    //             return 0;
    //         }
    //     }

    //     arr.clear();             // removes all elements
    //     arr.resize(150, -1);    // resizes to 150 elements, each initialized to -1 again

    // // checks mapping from s2 to s1

    //     for(int i=0; i<s2.length(); i++){

    //         int idx = int(s2[i]);                     // idx stores the ascii value
    //         int sum = s1[i]+s2[i];

    //         if( arr[idx] == -1)     arr[idx]= sum;             // we store their sum value

    //         else if (arr[idx] != sum) {      // it works when value is stored already i.e their sum
    //             cout<<"not isomorphic";
    //             return 0;
    //         }
    //     }

    //   cout<<"isomorphic";

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//     Problems with your current code

// Sum-based mapping is unsafe
// Example: 'a' + 'c' == 'b' + 'b' → both sums = 196.
// So s1 = "ac", s2 = "bb" would incorrectly look valid.


    if (s1.length() != s2.length())     {
        cout<<"not isomorphic due to length";
        return 0;
    }

    vector<int> map1(150, -1); // map from s1 → s2
    vector<int> map2(150, -1); // map from s2 → s1

    for (int i = 0; i < s1.length(); i++) {

        char c1 = s1[i];
        char c2 = s2[i];

        // If not mapped yet
        if (map1[c1] == -1 && map2[c2] == -1) {
            map1[c1] = c2;
            map2[c2] = c1;
        }
        
        // If mapping already exists, it must be consistent
        else if (map1[c1] != c2 || map2[c2] != c1)   {

            cout<<"not isomorphic";
            return 0;

        }
    }

    cout<<"isomorphic";


  return 0;


}