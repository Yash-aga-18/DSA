#include <bits/stdc++.h>
using namespace std;

// Ques-->number of ways to go from the top-left corner to the bottom-right corner
// now we suppose the revrse matx lets start from destination to source
// using only 2 variables
// let going to (3,3)-->(0,0)


int maze(int er, int ec){
    
    if(er<0 || ec<0 )   return 0;
    if(er==0 && ec==0)  return 1;


    int right = maze( er,   ec-1 );         // if he moves right
    int down  = maze( er-1, ec   );         // if he moves down

    return right + down;
    
}


void printmaze(int er, int ec, string S){
    
    if(er<0 || ec<0)      return;

    if(er==0 && ec==0) {
        cout<<S<<endl;
        return;
    }

    printmaze( er,   ec-1, S+"R");         // if he moves right
    printmaze( er-1, ec,   S+"D");         // if he moves down

}



int main()
{
    int m,n;

    cout<<"enter the m"<<endl;
    cin>>m; 
    cout<<"enter the n"<<endl;
    cin>>n; 
    
    cout<<"no. of possible ways is --> "<<maze(m, n);

    cout<<endl;
    printmaze( m, n, "");
    


 return 0;

}