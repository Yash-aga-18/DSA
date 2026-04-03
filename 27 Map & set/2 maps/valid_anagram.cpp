#include <bits/stdc++.h>
using namespace std;

// leetcode Q->242   Vaid Anagram
// given 2 strings,  check whether they are anagram or not



// 🔹 Method 1: using two maps
bool isAnagram1(string str1, string str2) {

    if(str1.size() != str2.size())      return false;
    
    unordered_map<char,int> mp1;
    unordered_map<char,int> mp2;

    for(int i=0; i<str1.size(); i++){
        mp1[ str1[i] ]++ ; 
        mp2[ str2[i] ]++ ; 
    }

    for(auto ele: mp1){

        char ch = ele.first;
        if( mp2[ch] != mp1[ch])    return false;

    }

    return true;

}


// 🔹 Method 2: using single map (optimized)
bool isAnagram2(string str1, string str2) {

    if(str1.size() != str2.size())      return false;
    
    unordered_map<char,int> mp;

    for(int i=0; i<str1.size(); i++){

        char ch1 = str1[i];
        mp[ch1]++;
        
    }


    for(int i=0; i<str2.size(); i++){

        char ch2 = str2[i];
        mp[ch2]--;

        if(mp[ch2] == 0)    mp.erase(ch2);
        
    }

    if(mp.size()>0)     return false;
    return true;

}



int main() {

    string str1 = "listen";
    string str2 = "silent";

    cout << "Method 1: " << isAnagram1(str1, str2) << endl;
    cout << "Method 2: " << isAnagram2(str1, str2) << endl;

    return 0;
}