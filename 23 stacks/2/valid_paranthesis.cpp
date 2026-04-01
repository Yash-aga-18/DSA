#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "((())()())";

    stack<char> st;
    
    if( (str.size() %2) != 0 )  {
        cout << "not valid";
        return 0;
    }


    for(int i = 0; i < str.length(); i++) {

        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[')     st.push(ch);
        
        else {

            //  if there is no opening bracket in starting of str and  
            // if the stack is empty, calling: st.top()  is undefined behavior

            if(st.empty())  {        

                cout << "not valid";
                return 0;
            }

            if(ch == ')' && st.top() == '(')            st.pop();
            else if(ch == '}' && st.top() == '{')       st.pop();
            else if(ch == ']' && st.top() == '[')       st.pop();

            else
            {
                cout << "not valid";
                return 0;
            }

        }

    }


    if(st.empty())      cout << "valid";
    else                cout << "not valid";

    return 0;
}