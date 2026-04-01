#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2529. Maximum Count of Positive Integer and Negative Integer
// count no of positive and neg. integers and return whether which is maximum
// arr is already sorted   and   0 is neithr pos or neg


int main()
{
    int nums[] = {-3,-2,-1,0,0,1,2};

    int n = sizeof(nums)/sizeof(nums[0]);

    int low = 0;
    int high = n-1;
    int mid = -1;

    int pos = 0;
    int neg = 0;

// step1--> count lowest pos integer

    while(low<=high){
        mid  = low + (high-low)/2;

        if (nums[mid]>0){

            if(mid>0 && nums[mid-1]>0)   high = mid-1;
            else { 
                pos = n-mid;
                break;
            }
        }
        else {
            low = mid+1;
        }
    }

// resetting the values 
    low = 0;
    high = n-1;
    mid = -1;
    
    while(low<=high){
        mid  = low + (high-low)/2;

        if (nums[mid]<0){
            
            if(mid<n-1 && nums[mid+1]<0)   low = mid+1;
            else { 
                neg = mid+1;
                break;
            }
        }
        else {
            high = mid-1;
        }
    }

    if(pos>=neg)    cout<<pos;
    else            cout<<neg;
        
}
