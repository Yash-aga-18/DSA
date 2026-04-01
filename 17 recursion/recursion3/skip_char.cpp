#include <bits/stdc++.h>
using namespace std;

// Ques----> skips a character from a string


// void remove1(string ans, string original, char target){  
// // its time complexity is O(n^2) and space compl is also much higher 


//     if (original.length()==0){      // base case
//         cout<<ans;
//         return;
//     }

//     char ch = original[0];

//     if(ch==target)      return remove1( ans,    original.substr(1), target);
//     else                return remove1( ans+ch, original.substr(1), target);

// }



string remove(string ans, string original, char target, int idx){

    if (idx == original.length())   return ans;
    
    
    char ch = original[idx];

    if(ch==target)      return remove( ans,    original, target, idx+1);
    else                return remove( ans+ch, original, target, idx+1);

}



int main()
{
    
    string original;
    char target;

    cout<<"enter a string ---> "<<endl;
    getline(cin,original);
    
    cout<<"enter a character ";
    cin>>target;
    
    cout<<remove("",original,target,0);



 return 0;

}