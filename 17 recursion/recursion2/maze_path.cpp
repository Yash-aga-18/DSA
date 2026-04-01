#include <bits/stdc++.h>
using namespace std;

// Ques-->number of ways to go from the top-left corner to the bottom-right corner
// supposse maze is in form of 2D matrix
// he can only allowed to go either down or right at a time
// print their path also


int maze(int sr, int sc, int er, int ec){
    
    if(sr>er || sc>ec)      return 0;
    if(sr==er && sc==ec)    return 1;


    int right = maze( sr,   sc+1, er, ec);            // if he moves right
    int down  = maze( sr+1, sc,   er, ec);            // if he moves down

    return right + down;
    
}


void printmaze(int sr, int sc, int er, int ec, string S){
    
    if(sr>er || sc>ec)      return;

    if(sr==er && sc==ec) {
        cout<<S<<endl;
        return;
    }

    printmaze( sr,   sc+1,  er, ec, S+"R");         // if he moves right
    printmaze( sr+1, sc,er, ec,     S+"D");         // if he moves down

    
}



int main()
{
    int m,n;

    cout<<"enter the m"<<endl;
    cin>>m; 
    cout<<"enter the n"<<endl;
    cin>>n; 
    
    cout<<"no. of possible ways is --> "<<maze( 0, 0, m, n);

    cout<<endl;
    printmaze( 0, 0, m, n, "");
    


 return 0;

}