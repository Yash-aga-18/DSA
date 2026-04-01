#include <bits/stdc++.h>
using namespace std;

int main()
{
    
// leetcode Q->69       find sqrt(x)

    int x;
    cout<<"enter the value of x:"<<endl;
    cin>>x;

    if (x == 0 || x == 1)   return x;

    int low = 0;
    int high = x/2;
    int mid = -1;
    bool flag = false;

    while (low <= high) {
        mid = low + (high - low) / 2;

        long long m = (long long) (mid);
        long long y = (long long) (x);

        if (m * m == y) {
            cout<<mid;
            flag = true;
            break; 
        }

        else if (m * m < y)     low = mid + 1;
        
        else if (m * m > y)     high = mid - 1;
        
    }    
    
    if(flag == false) cout<<low-1;
    


 return 0;

}