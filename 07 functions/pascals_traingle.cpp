#include <bits/stdc++.h>
using namespace std;


// int factorial (int x){
//     int f= 1 ;
//      for(int i=1; i<=x; i++){
//          f=f*i;
//      }
//      return f;
// }
 
// int combination(int x, int y){
//      int nfact = factorial(x);
//      int rfact = factorial(y);
//      int nrfact = factorial(x-y);
 
//      int ncr = nfact/(rfact*nrfact);
//      return ncr;
// }


// int main(){

//   int n=5;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<=i; j++){

//           cout<<combination(i,j)<<" ";
//         }
//         cout<<endl;
//     }


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // pascal triangle optimized

// n C (r+1) = { nCr * (n-r) } / r+1 


int main(){

    int n = 5;

    for (int i = 0; i < n; i++) {

        int curr = 1;
        for (int j = 0; j <= i; j++) {
            cout << curr << " ";
            int nxt = (curr * (i - j)) / (j + 1);
            curr = nxt;
        }
        cout << endl;
        
    }

 return 0;

}