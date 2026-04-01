#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2273     Find Resultant Array After Removing Anagrams
// You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.
// words[i-1] and words[i] are anagrams, and delete words[i] from words. 
// eg-->words = ["abba","baba","bbaa","cd","cd"]
//      Output: ["abba","cd"]


int main()
{
    int n;
    cout<<"enter no. of words to enter ";
    cin>>n;
    
    cout<<"enter string-->"<<endl;
    vector<string> words(n);
    for(int i=0; i<n; i++){
        cin>>words[i];
    }

    vector<string> res;
        
    res.push_back(words[0]);
        
    for (int i = 1; i < words.size(); ++i) {

            
        string prev = res.back();
        string curr = words[i];


        sort(prev.begin(), prev.end());
        sort(curr.begin(), curr.end());
            
        if (prev != curr) res.push_back(words[i]);
            
    }
    
    cout<<"final string-->"<<endl;
    for(string ele:res)     cout<<ele<<" ";
    


 return 0;

}