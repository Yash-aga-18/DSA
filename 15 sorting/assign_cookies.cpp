#include <bits/stdc++.h>
using namespace std;

int main()
{
    
     
// leetcode Q->455   Assign Cookies
// let arry of greed[i]  and array of cookies[i]  
// you can fulfill the greed by only giving same size or larger cookie 
//  and only 1 cookie is allowed  give no. of greedy children fulfilled


// eg--> g = [1,2], s = [1,2,3]         ans is -->2   as only 1st,2nd child eats the cookie


   vector<int> greed = {1,2};
   vector<int> cookie = {1,2,3};

   sort(greed.begin(),greed.end());
   sort(cookie.begin(),cookie.end());

   int i = 0;
   int j = 0;
   int count = 0;

    while(i<greed.size() && j<cookie.size()) {

        if(cookie[j]>=greed[i])  {
            count++;
            i++;
        }

        j++;
    }

   cout<<count;




 return 0;

}