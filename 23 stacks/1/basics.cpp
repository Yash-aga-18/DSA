#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    stack<int>st;
    cout<<st.size()<<endl;      // to get size of stack
    
    st.push(10);                // to push in stack
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<st.size()<<endl;
    
    st.pop();                   // to pop in stack
    st.pop();
    cout<<st.size()<<endl;

    cout<<st.top()<<endl;             // to access top of stack
    cout<<endl;
    
//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// to print the whole stack---->
//  here we lose the elemnts during popping (if we don't store them in another stack)


    //  cout<<st;             // it's invalid in c++ but in java it returns the whole stack

    while(st.size()>0){

        cout<<st.top() <<endl;
        st.pop();
    }




 return 0;

}