#include <bits/stdc++.h>
using namespace std;

// int fac(int n){
//     int x=1;
//     for(int i=1; i<=n; i++)
//     x=x*i;
//     return x;
// }


// int main()
// {

//   int n,r;

//   cout<<"enter n"<<endl;
//   cin>>n;
//   cout<<"enter r"<<endl;
//   cin>>r;

// // nCr=n!/{ r! * (n-r)! }
// // nPr=n!/ (n-r)!

//  int nfact= fac(n);
//  int rfact= fac(r);
//  int nrfact= fac(n-r);

//  cout<<"nCr is "<<nfact/(rfact*nrfact)<<endl;
//  cout<<"nPr is "<<nfact/(nrfact);

 //  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  int fact(int n){
    int x=1;
    for(int i=1; i<=n; i++)
    x=x*i;
    return x;
  }

  int combination(int n, int r){                           // nCr
    int comb = fact(n)/(fact(r) * fact(n-r));
    return comb;
  }

  int permutation(int n, int r){                          // nPr
    int per = fact(n) / fact(n - r);
    return per;
  }
  

  int main()
  {
  
  int n,r;

  cout<<"enter n"<<endl;
  cin>>n;
  cout<<"enter r"<<endl;
  cin>>r;
  
  int ncr = combination(n,r);
  int npr = permutation(n,r);
  
  cout<<"nCr is "<<ncr<<endl;
  cout<<"nPr is "<<npr;
  
  
 return 0;

}