#include <bits/stdc++.h>
using namespace std;


// void Permutations(string & str, int index, vector<string>& result) {

//     if (index == str.size()) {
//         result.push_back(str);
//         return ;
//     }

//     for (int i = index; i < str.size(); i++) {
//         swap(str[index], str[i]);                       // Fix character at index
//         Permutations(str, index + 1, result);          // Recurse for remaining string
//         swap(str[index], str[i]);                      // Backtrack
        
//     }   

// }


// int main() {

//     string s = "abc";
//     vector<string> result;

//     Permutations(s, 0, result);

//     for(string ele: result){
//         cout<<ele<<endl;
//     }
    
//     return 0;
// }


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


void permutations(string ans, string original, vector<string>&v) {

    if (original == "") {
        v.push_back(ans);
        return;
    }

    for(int i=0; i<original.length(); i++){

        char ch = original[i];
        string left = original.substr(0,i);         // from  0   to  i-1
        string right = original.substr(i+1);        // from  i+1 to  last

        permutations(ans+ch, left+right, v); 

    }   

}    
    

int main(){
    string str = "abc";
    vector<string>v;

    permutations("", str, v);

    for(string ele:v){
        cout<<ele<<endl;
    }
 return 0;

}
