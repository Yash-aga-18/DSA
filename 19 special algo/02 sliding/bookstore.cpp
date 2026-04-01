#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1052  Grumpy Bookstore Owner

// A bookstore receives customers each minute (customers[i]) and the owner may be grumpy (grumpy[i]).
// Customers are satisfied only when the owner is NOT grumpy.

// The owner can use a secret trick to stay calm for `k` consecutive minutes, but only once.
// Find the maximum number of satisfied customers by choosing the best k-minute window.

// Example: customers = [1,0,1,2,2,1,7,5] 
//          grumpy    = [0,1,0,1,0,1,0,1]   , k=3
//   modified grumpy--> [0,1,0,1,0,0,0,0]
//  1+1+2+1+7+5           answer = 17



void maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        
    int n = customers.size();
    
    int alreadySatisfied = 0;   // people already happy
    int windowGain = 0;         // extra happiness if boss uses trick
    int maxWindowGain = 0;      // best possible extra happiness

// Step 1: Count already satisfied customers and extra gain for the first window of size k
    for(int i = 0; i < n; i++) {

        if(grumpy[i] == 0)  alreadySatisfied += customers[i];  // these are always happy

        if(i < k && grumpy[i] == 1) windowGain += customers[i]; // these become happy if trick used
    }
    maxWindowGain = windowGain;


// Step 2: Slide the window across remaining minutes to count extra gain of window size k
    for(int high = k; high < n; high++) {

        int low = high-k+1;

        if(grumpy[high] == 1)   windowGain += customers[high];     // add new element entering window
        if(grumpy[low-1] == 1)  windowGain -= customers[low-1];   // remove element exiting window


        if(windowGain > maxWindowGain)  maxWindowGain = windowGain;
    }


    // Step 3: total satisfied = always happy + best window gain
    cout<< (alreadySatisfied + maxWindowGain);
}


int main()
{
    
    vector<int>customers = {1,0,1,2,2,1,7,5};
    vector<int>grumpy =    {0,1,0,1,0,1,0,1};
    int minutes = 3;

    maxSatisfied(customers,grumpy,minutes);
 
  return 0;

}