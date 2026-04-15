#include <bits/stdc++.h>
using namespace std;


bool lemonadeChange(vector<int>& arr) {
    
    int n = arr.size();

    int five = 0;
    int ten = 0;

    for(int i=0; i<n; i++) {
        
        int note = arr[i];

        if(note == 5)       five++;
        

        else if(note == 10) {

            if(five>0){
                five--; // Give one $5 as change
                ten++;  // Accept the $10 bill
            }

            else        return false; // Cannot provide change

        }

        else { // bill == 20

            if (five > 0 && ten > 0) {
                five--; // Use one $5
                ten--;  // Use one $10
            } 

            else if (five >= 3) {
                five -= 3; // Use three $5 bills
            } 

            else        return false; // Cannot provide change
        }

    }

    
    return true;

}


int main() {

    vector<int> bills = {5, 5, 5, 10, 20};

    cout << "Queue of customers: ";
    for (int bill : bills) cout << bill << " ";
    cout << endl;

    bool ans = lemonadeChange(bills);

    if (ans)        cout << "possible" << endl;
    else            cout << "not possible" << endl;

    return 0;
}
