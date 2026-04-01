#include <bits/stdc++.h>
using namespace std;

int main()
{

//  Ques : Given an array with N distinct elements, convert the given array such that the order of elements
//  is  same, i.e., 0 is placed in the place of the smallest element, 1 is placed for the second smallest element,
//  ... N-1 is placed for the largest element.(only +ve numbers are allowed)

// eg--> arr = [19, 23, 8, 16]  
//       arr = [2,  3,  0,  1]

//  vector<int> v = {19, 23, 8, 16};
// int idx = 0;
// for (int i = 0; i < v.size(); i++) {

//     int min = INT_MAX;
//     int min_idx = -1;
    
//     for (int j = 0; j < v.size(); j++) {
//         if (v[j] < min && v[j] > 0) {            // finding smallest positive
//             min = v[j];
//             min_idx = j;
//         }
//     }

//     v[min_idx] = idx;  // replace smallest with rank
//     idx--;             // use negative to mark processed
// }

// // convert negatives back to positive rank
// for (int i = 0; i < v.size(); i++) {
//     v[i] = -v[i];
//     cout << v[i] << " ";
// }

 
//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// find an integer (say K) such that after replacing each and every index of the array 
// by |ai  – K| results in a sorted array.  give range of k


    int arr[]= {5,3,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int ele: arr)   cout<<ele<<" ";
    cout<<endl;


    // float kmin = float (INT_MIN);
    // float kmax = float (INT_MAX);

    // for(int i = 0; i < n-1; i++) {

    //     int a = arr[i];
    //     int b = arr[i+1];
    //     float value = (a + b) / 2.0;

    //     if(a < b)       kmax = min(kmax, value);           // floor division
    //     else if(a > b)  kmin = max(kmin, value);           // ceil division
        
    //     // if a == b → no restriction, skip
    // }
    
    // if( kmin - int(kmin) !=0 )     kmin = int(kmin)+1;   // decimal to integer for kmin

    // if(kmin > kmax)         cout << "No value exists" << endl; 
    // else if(kmin == kmax)   cout << kmin << endl;  // only one K 
    // else                    cout << kmin << " " << kmax << endl;  // range of valid K



//                   OR


    int kmin = INT_MIN;
    int kmax = INT_MAX;

    for(int i = 0; i < n-1; i++) {

        int a = arr[i];
        int b = arr[i+1];

        if(a < b)       kmax = min(kmax, (a+b)/2);       // floor
        else if(a > b)  kmin = max(kmin, (a+b+1)/2);     // ceil
    }

    if(kmin > kmax)         cout << "No value exists" << endl; 
    else if(kmin == kmax)   cout << kmin << endl;
    else                    cout << kmin << " " << kmax << endl;

                                                                                              

 return 0;

}