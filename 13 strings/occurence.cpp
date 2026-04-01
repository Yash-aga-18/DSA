#include <bits/stdc++.h>
using namespace std;

int main()
{

// //   find the most occured character in string if all the characters are in lower case

  // string str = "physicswallah";
  // vector<int> v1(26, 0);

  // // Count frequency of each character
  // for (char ch : str) {
  //   v1[ch - 'a']++;
  // }

  // // Find max frequency
  // int maxFreq = 0;
  // for (int i = 0; i < 26; i++) {
  //   if (v1[i] > maxFreq) maxFreq = v1[i];
  // }

  // // Print characters with max frequency
  // for (int i = 0; i < 26; i++) {

  //   if (v1[i] == maxFreq)    cout << char('a' + i) << " " << maxFreq << endl;
    
  // }


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// find the most occured word in sentence  stored in string

 string str = "I am YASH AGARWAL. I am in in IMSEC in am.";
 stringstream ss(str);        // stringstream is used to store words seperated by spaces
 string temp;

 vector<string>v;
 
  while (ss>>temp) {
    v.push_back(temp);
  }

  sort(v.begin(),v.end());        // it sorts all the words based on ascii value

  int count = 1;
  int maxcount = 1;

  for(int i=1; i<v.size(); i++){            // find max times of occurenece

    if(v[i]==v[i-1])    count++;
    else                count = 1;

    maxcount = max(count,maxcount);  

  }

  count = 1;
  for(int i=1; i<v.size(); i++){            // find the word who has most occurence
    if(v[i]==v[i-1])    count++;
    else                count = 1;

    if(count==maxcount) cout<<v[i]<<" --> "<<maxcount<<endl;  
  
  }


 return 0;

}