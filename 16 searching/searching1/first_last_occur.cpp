#include <bits/stdc++.h>
using namespace std;

// leetcode Q->34
// ques--> find first,last occurence of an elemnt in sorted array 

int main() {


    vector<int> v = {1,2,2,2,3,3,3,3,4,5,5,5,6,7,7,8,9};
    int target = 2;
    int n = v.size();

//     int start_idx = -1;
//     int end_idx   = -1;

//     int low = 0;
//     int high = n-1;
//     int mid = -1;

//     while (low <= high) {

//         mid = low + (high - low) / 2;

//         if (v[mid] == target) {

//             start_idx = mid;
//             end_idx = mid;

//             // expand left
//             while (start_idx > 0 && v[start_idx - 1] == target)         start_idx--;

//             // expand right
//             while (end_idx < n - 1 && v[end_idx + 1] == target)  end_idx++;

//             break;          // target found, no need to continue binary search
//         }

//         else if (v[mid] < target)   low = mid + 1;
        
//         else                        high = mid - 1;
        
//     }

//     cout << start_idx << " " << end_idx << endl;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    int low = 0;
    int high = n-1;
    int mid =-1;
    bool flag = false;

    while(low <= high){

       mid = low + (high-low)/2;

        if(v[mid]==target){

            if(mid > 0  &&  v[mid-1]==target)  high = mid-1;
            
            else   {   
                flag =true;
                break;  
            } 
        }

        else if(v[mid]<target)      low  = mid+1;
        else if(v[mid]>target)      high = mid-1;

    }

    if(flag == true) cout<<"first occurrence at "<< mid<<endl;
    // else             cout<<"Element not found";              // no need to print


// reset the values
    low = 0;
    high = n-1;
    mid =-1;
    flag = false;

    while(low <= high){

       mid = low + (high-low)/2;

        if(v[mid]==target){

            if(mid < n-1 && v[mid+1]==target)  {    
                low = mid+1;
            }
            else   {   
                flag =true;
                break;  
            } 
        }

        else if(v[mid]<target)      low  = mid+1;
        else if(v[mid]>target)      high = mid-1;

    }

    if(flag == true) cout<<"last occurrence at "<< mid;
    
    else             cout<<"Element not found";




 return 0;

}

/*

Version 1 slows down badly when target has many duplicates.
It has to walk left and right linearly.

Version 2 is always fast.
Because it uses only binary search logic and never walks element-by-element.

*/