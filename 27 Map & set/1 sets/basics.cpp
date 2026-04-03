#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    
    cout<<s.size() <<endl;
    for(int ele :s)     cout<<ele <<" ";
    cout<<endl;

    // we canmt insert the duplicate elemnts
    
    s.insert(40);
    s.insert(40);
    s.insert(40);
    s.insert(100);
    s.insert(200);
    
    s.erase(30);

    cout<<s.size() <<endl;
    for(int ele :s)     cout<<ele <<" ";
    cout<<endl;
    
    int target = 30;
    if( s.find(target) != s.end()  ){
        cout<<"exist"<<endl;
    }
    else    cout<<"not exist"<<endl;
    // s.find(is used to find the target till last  and if not found it returns last elemnt)

    
 return 0;

}