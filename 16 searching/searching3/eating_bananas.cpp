#include <bits/stdc++.h>
using namespace std;

// leetcode Q->875  Koko Eating Bananas

// you had given some bananas in pile[i] and h hours. you have to return 
// min. speed of eating banana per hour so that the monkey can eat all of them in given time
// but catch is if let there is only 1 banana in pile and let speed is 2banana/hr
// it cannot move to the next pile by just eating 1 from this pile
// and eating other 1 from another pile


bool check(int mid, vector<int>& pile, int hours, int n) {

    long long totalHours = 0;

    for (int i = 0; i < n; i++) {

        int bananas = pile[i];      // current pile
        int hoursForThisPile = 0;   // hours needed for this pile


        if (bananas % mid == 0)     hoursForThisPile = bananas / mid;
        else    hoursForThisPile = (bananas / mid) + 1;  // leftover bananas => extra hour
        

        totalHours += hoursForThisPile;

        if (totalHours > hours)     return false;      // too slow, no need to continue
        
    }

    return totalHours <= hours;

}



int main() {

    vector<int> pile = {30, 11, 23, 4, 20};
    int hours = 8;

    int n = pile.size();

    int low  = 1;
    int high = *max_element(pile.begin(), pile.end());

    int ans  = high;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (check(mid, pile, hours, n)) {
            ans = mid;
            high = mid - 1;
        }

        else    low = mid + 1;
        
    }

    cout<<"min speed required is " << ans;

    return 0;
}


/*
Brute force approcah-->

we start from 1 to high not applying binary search
we go one by one 


*/