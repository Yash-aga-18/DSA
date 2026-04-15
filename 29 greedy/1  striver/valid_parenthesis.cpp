#include <bits/stdc++.h>
using namespace std;

// leetcode Q->678   Valid Parenthesis String

// method-1--> try recursion by goging to each possibilty results to O(3^k) TLE


bool checkValidString(string s) {

// Track minimum and maximum open brackets
    int minOpen = 0;
    int maxOpen = 0;

    for(char c : s) {

        if(c == '(') {
            minOpen++;
            maxOpen++;
        }

        else if(c == ')') {
            minOpen--;
            maxOpen--;
        }

        else { // '*'
            minOpen--;
            maxOpen++;
        }


        if(minOpen < 0) minOpen = 0;           // If maxOpen goes negative, too many closing brackets

        if(maxOpen < 0) return false;           // If maxOpen goes negative, too many closing brackets

    }

    return minOpen == 0;            // String is valid if all opens are closed
}

int main() {

    string s = "(*))";

    if(checkValidString(s)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}