#include <bits/stdc++.h>
using namespace std;

// we can also do the sorting using in-built funcn of vector    sort(v.begin(),v.end())
// its time complx is O(n logn)


// in bubble sort the largest element is sorted the first at rightmost place (generally)
// you have to swap the current elemnt with the next element if condn satisfy


int main()
{
  
//   int arr[]={5,3,7,1,2};
//   int n = 5;

//     for(int i=0; i<n; i++){
//       cout<<arr[i]<<" ";
//     }
//     cout<<endl;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


    // for(int i=0; i<n-1; i++){            //  n-1 passes are requires
    //     for(int j=0; j<n-1; j++){

    //         if(arr[j]>arr[j+1]) {
    //             swap(arr[j],arr[j+1]);
    //         }
    //     }
    // }

    // for(int i=0; i<n; i++){
    //   cout<<arr[i]<<" ";
    // }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


    // for(int i=0; i<n-1; i++){
    //     for(int j=0; j<n-1-i; j++){             // as last elemnted is sorted so no need to check

    //         if(arr[j]>arr[j+1]) {
    //             swap(arr[j],arr[j+1]);
    //         }
    //     }

    // }

    // for(int i=0; i<n; i++){
    //   cout<<arr[i]<<" ";
    // }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// best solution----->

//     for(int i=0; i<n-1; i++){

//         bool flag = true;
//         for(int j=0; j<n-1-i; j++){

//             if(arr[j]>arr[j+1]) {                
//                 swap(arr[j],arr[j+1]);
//                 flag = false;
//             }
//         }

//         if (flag == true){          // can be true only when it is sorted
//             break;
//         }
    
//     }

//     for(int i=0; i<n; i++){
//       cout<<arr[i]<<" ";
//     }



//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// IMP POINTS------------------>


//  TC in three cases---->

//     worst case--> O(n^2)
//     avg case--> O(n^2)          // but its actually is O ( (n^2) /2)  equivalent to O(n^2)
//     best case--> O(n)


//     Buuble sort is stable sort i.e relative order of elemnt is maintained
    
//     no. of swaps = n*(n-1) / 2           // in worst case


// In-place Sorting---------------->
// Refers to space usage.
// Uses O(1) or O(log n) extra space.


// Examples:

// In-place: Selection Sort, Insertion Sort, Quick Sort
// Not in-place: Merge Sort (standard version)

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//   5 3 7 1 2


//      Pass 1:
//      5 > 3 → swap → 3 5 7 1 2
//      5 < 7 → no swap
//      7 > 1 → swap → 3 5 1 7 2
//      7 > 2 → swap → 3 5 1 2 7

//      Pass 2:
//      3 < 5 → no swap
//      5 > 1 → swap → 3 1 5 2 7
//      5 > 2 → swap → 3 1 2 5 7

//      Pass 3:
//      3 > 1 → swap → 1 3 2 5 7
//      3 > 2 → swap → 1 2 3 5 7

//      Pass 4:
//      Already sorted, no swaps → exit early.

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Sort String in decreasing order after removal of values smaller than a particular element.


    // string s = "AZYZXBDXJK";
    // char element = 'X';
    // string str;

    // for(int i=0; i<s.length(); i++){
        
    //     if(s[i] >= element) {
    //         str.push_back(s[i]);
    //     }
    // }

    // cout<<str<<endl;


    // for(int i=0; i<str.length()-1; i++){

    //     bool flag = true;
    //     for(int j=0; j<str.length()-1-i; j++){
     
    //        if(str[j]<str[j+1]) {                     // to sort in descending order
    //             swap(str[j],str[j+1]);
    //             flag = false;
    //         }
    //     }
     
    //    if (flag == true){          // can be true only when it is sorted
    //         break;
    //     }
     
    // }


    // cout<<str;


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Push zeroes to end while maintaining the relative order of other elements.

int arr[] = {5,0,2,0,0,1,4,0,3,0};
int n = 10 ;


    // for(int i=0; i<n; i++){
    //   cout<<arr[i]<<" ";
    // }
    // cout<<endl;


    // for(int i=0; i<n-1; i++){

    //     bool flag = true;
    //     for(int j=0; j<n-1-i; j++){

    //         if(arr[j] == 0){
    //             swap(arr[j],arr[j+1]);
    //             flag = false;
    //         }
        
    //     }
        
    //     if (flag == true){         
    //         break;
    //     }
         
    // }

    // for(int i=0; i<n; i++){
    //   cout<<arr[i]<<" ";
    // }
    // cout<<endl;



//  we can do in another way as we have to move all the non zero elemnts forward
//  and fill the remaining array with zero
// it is most opimized


    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    int pos = 0; 

    // First pass: move all non-zero elements forward
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            arr[pos] = arr[i];
            pos++;
        }
    }

    // Fill remaining positions with zeroes
    while(pos < n) {
        arr[pos] = 0;
        pos++;
    }

    // Print modified array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


 return 0;

}