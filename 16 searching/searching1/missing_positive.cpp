#include <bits/stdc++.h>
using namespace std;

// ques--> find smallest positive missing number in sorted arr starting from zero 

int main()
{
    

    vector<int>v = {0,1,2,4,5,6,7};
    int n = v.size();
  
    int low = 0;
    int high = n-1;
    int mid =-1;

    while(low <= high){
        mid = low + (high-low)/2;

        if(v[mid]==mid){
            low = mid+1;
        }
        
        else{
            high=mid-1;
        }

    }

    cout<<low;




 return 0;

}