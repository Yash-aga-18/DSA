#include <bits/stdc++.h>
using namespace std;

// leetcode Q->11
// Find two lines that together with the x-axis form a container, 
// such that the container contains the most water.
// Return the maximum amount of water a container can store.

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation:the max area of water is between 8 and 7   

int main()
{
    
    int x,n;
    cout<<"enter the size of array  ";
    cin>>n;
    
    vector<int>v(n);
    
    cout<<"enter the array "<<endl;
    for(int i=0; i<n; i++)     {
        cin>>x;
        v[i]=x;
    }
    

    int i = 0;
    int j = n-1;
    int maxwater = 0;

    while(i<j){
        int width = j-i;
        int height = min(v[i],v[j]);

        int water = width*height;
        
        maxwater = max(maxwater,water);
         
        if (v[i]<v[j])   i++;
        else             j--; 
    }

    cout<<"maxwater is "<<maxwater;



 return 0;

}