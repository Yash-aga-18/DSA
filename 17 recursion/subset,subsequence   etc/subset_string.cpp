#include <bits/stdc++.h>
using namespace std;

// // return all poosible subsets of string
// // return all poosible subsets of string without dupliacte in ans


void backtrack(string& s, int start, string& path, vector<string>& result) {

    result.push_back(path);

    for (int i = start; i < s.size(); i++) {

        if (i > start && s[i] == s[i - 1]) continue;   // skip duplicates

        path.push_back(s[i]);
        backtrack(s, i + 1, path, result);
        path.pop_back();

    }

}


vector<string> subsets(string str) {

    sort(str.begin(), str.end());
    
    vector<string> result;
    string path;

    backtrack(str, 0, path, result);

    return result;
    
}



int main() {

    string str = "acc";

    vector<string> out = subsets(str);

    for (string sub : out) {
        cout << "[" << sub << "]" << endl;
    }

    return 0;

}

