#include <bits/stdc++.h>
using namespace std;

// leetcode Q->22  Generate Parentheses

// write a function to generate all combinations of well-formed parentheses.
// Input: n = 3
// Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]

void backtrack1(string& str, int open, int close, int n, vector<string>& result) {

    if (close == n) {
        result.push_back(str);
        return;
    }

    if (open < n) {
        str.push_back('(');
        backtrack1(str, open + 1, close, n, result);
        str.pop_back();
    }

    if (open > close) {
        str.push_back(')');
        backtrack1(str, open, close + 1, n, result);
        str.pop_back();
    }
    
}


void backtrack2( string str,int open, int close, int n, vector<string>& result) { 
    if(close == n) { 
        result.push_back(str); 
        return; 
    } 

    if (open<n)     backtrack2( str+'(', open+1, close,   n, result ); 
    if (open>close) backtrack2( str+')', open,   close+1, n, result ); 

}

vector<string> generateParenthesis(int n) {

    vector<string> result;
    string str = "";
    backtrack1(str, 0, 0, n, result);
    
    // backtrack2(str, 0, 0, n, result);
    return result;
}

int main() {
    int n = 3;
    vector<string> output = generateParenthesis(n);

    cout << "[" << endl;
    for (int i = 0; i < output.size(); ++i) {
        cout << "\" " << output[i] << " \""<<endl;
    }
    cout << "]" << endl;

    return 0;
}
