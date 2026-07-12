#include <bits/stdc++.h>
using namespace std;

// leetcode Q->59
// spiral matrix generate

//                                                               1    2    3    4   
//  1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 13 12    --->      12   13   14   5      
//                                                               11   16   15   6  
//                                                               10   9    8    7  



int main()
{
  
  int n;
  
  cout<<"enter value of n"<<endl;
  cin>>n;
  int arr[n][n];

  int minr=0;
  int minc=0;
  int maxr=n-1;
  int maxc=n-1;
   

// //  to print the output in spiral form 
// there are 4 approaches used -->

// right  we travel through minr   from minc to maxc    minr++
// down   we travel through maxc   from minr to maxr    maxc--

// left   we travel through maxr   from maxc to minc    maxr--
// up     we travel through minc   from maxr to minr    minc++


   int count=1;            // used to run the loop only times of no. of elements
   int tne=n*n;          // no of elements 
  
    while(minr<=maxr && minc<=maxc) {

      for(int j=minc; j<=maxc && count<=tne; j++){      // right
         arr[minr][j]=count;
         count++;
      }
      minr++;
    

      for(int i=minr; i<=maxr && count<=tne; i++){      // down
         arr[i][maxc]=count;
         count++;
      }
      maxc--;


      for(int j=maxc; j>=minc && count<=tne; j--){      // left
         arr[maxr][j]=count;
         count++;
      }
      maxr--;


      for(int i=maxr; i>=minr && count<=tne; i--){      // up
         arr[i][minc]=count;
         count++;
      }
      minc++;

    }


   cout<<"matrix is-->"<<endl;
   for(int i=0; i<n; i++){              // printing input of mtx
      for(int j=0; j<n; j++){
         cout<<arr[i][j]<<" ";      
      } 
     cout<<endl;
   }
   cout<<endl;
 return 0;

}