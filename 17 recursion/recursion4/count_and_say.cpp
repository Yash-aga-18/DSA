#include <bits/stdc++.h>
using namespace std;

// leetcode Q->38  Count and Say
// Input: n = 5
// Output: "111221"

// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = RLE of "1" = "11"
// countAndSay(3) = RLE of "11" = "21"
// countAndSay(4) = RLE of "21" = "1211"
// countAndSay(5) = RLE of "1211" = "111221"

string count_say(int n) {
    
    if (n==1)   return "1";
    string str = count_say(n-1);

    string ans = "";
    int count = 1;
    char ch = str[0];

    for(int i=1; i<str.size(); i++){
        char next = str[i];

        if(ch==next)    count++;
        
        else{
            ans += (to_string(count)  +ch);
            count = 1;
            ch = next;
        }
        
    }
    
    ans += (to_string(count)  +ch);  // to return the last element

    return ans;

}


int main()
{
    
    int n =5;
    
    cout<<"\" "<<count_say(n)<<" \"";

 return 0;

}