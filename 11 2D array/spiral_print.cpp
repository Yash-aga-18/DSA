#include <bits/stdc++.h>
using namespace std;

// leetcode Q->54
// spiral print 
// 1    2   3   4   5
// 6    7   8   9   10   --> 1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 13 12 
// 11  12  13   14  15
// 16  17  18   19  20
 

int main()
{
  
  int m,n;
  
  cout<<"enter value of m*n of mtx"<<endl;
  cin>>m;
  cin>>n;
  int arr[m][n];

  int minr=0;
  int minc=0;
  int maxr=m-1;
  int maxc=n-1;
   
  cout<<"enter the elemnts of mtx"<<endl;
   for(int i=0; i<m; i++){              // taking input in mtx
      for(int j=0; j<n; j++){
       cin>>arr[i][j];      
      } 
   }

  cout<<"matrix is-->"<<endl;
   for(int i=0; i<m; i++){              // printing input of mtx
      for(int j=0; j<n; j++){
         cout<<arr[i][j]<<" ";      
      } 
     cout<<endl;
   }
   cout<<endl;


// //  to print the output in spiral form 
// there are 4 approaches used -->

// right  we travel through minr   from minc to maxc    minr++
// down   we travel through maxc   from minr to maxr    maxc--

// left   we travel through maxr   from maxc to minc    maxr--
// up     we travel through minc   from maxr to minr    minc++

// count <= tne  would still allow one more iteration and possibly enter the loop 
// means inner for loops could try to run again


   int count=0;            // used to run the loop only times of no. of elements
   int tne=m*n;            // no of elements 
  
   while(minr<=maxr && minc<=maxc) {

      for(int j=minc; j<=maxc && count<tne; j++){      // right
        cout<<arr[minr][j]<<" ";
        count++;
      }
      minr++;
    

      for(int i=minr; i<=maxr && count<tne; i++){      // down
         cout<<arr[i][maxc]<<" ";
         count++;
      }
      maxc--;


      for(int j=maxc; j>=minc && count<tne; j--){      // left
         cout<<arr[maxr][j]<<" ";
         count++;
      }
      maxr--;


      for(int i=maxr; i>=minr && count<tne; i--){      // up
         cout<<arr[i][minc]<<" ";
         count++;
      }
      minc++;


   }

 return 0;

}