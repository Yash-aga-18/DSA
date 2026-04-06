#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2744     find maximum number of pairs that can be formed

//  given an array consisting of distinct strings
//  pair--> if there exist reverse of the string in array also



string rev(string str){
    reverse(str.begin(), str.end());
    return str;
}

int maximumNumberOfStringPairs(vector<string>& words) {

    unordered_set<string> s;
    int count = 0;

    for(int i = 0; i < words.size(); i++){

        string reversed = rev(words[i]);

        // if reverse already exists → pair found
        if(s.find(reversed) != s.end()){
            count++;
            s.erase(reversed);   // remove to avoid reuse (not required in this ques)
        }
        else{
            s.insert(words[i]);
        }
    }

    return count;
}



int main() {

    vector<string> words = {"ab", "ba", "cd", "dc", "ee"};

    int result = maximumNumberOfStringPairs(words);

    cout << "Maximum number of pairs: " << result << endl;

    return 0;
}