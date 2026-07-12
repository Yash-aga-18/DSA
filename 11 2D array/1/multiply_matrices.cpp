#include <bits/stdc++.h>
using namespace std;

int main()
{
   int m1,n1;
   int m2,n2;
  
  cout<<"enter value of m*n of mtx1"<<endl;
  cin>>m1;
  cin>>n1;
  int arr1[m1][n1];


  cout<<"enter value of m*n of mtx2"<<endl;
  cin>>m2;
  cin>>n2;
  int arr2[m2][n2];

  if(n1!=m2)   cout<<"multiplication cant be done";             // condition checks
  
  else{               
   
    cout<<"enter the elemnts of mtx1"<<endl;
    for(int i=0; i<m1; i++){
      for(int j=0; j<n1; j++){
        cin>>arr1[i][j];
      }
    }   

    cout<<"mtx1-->"<<endl;
    for(int i=0; i<m1; i++){                   // prints the mtx1
      for(int j=0; j<n1; j++){
        cout<<arr1[i][j]<<" ";
      }
      cout<<endl;
    }
     
    cout<<endl;   


   cout<<"enter the elemnts of mtx2"<<endl;
   for(int i=0; i<m2; i++){
      for(int j=0; j<n2; j++){
        cin>>arr2[i][j];
      }
    }   

    cout<<"mtx2-->"<<endl;
   for(int i=0; i<m2; i++){                   // prints the mtx2
      for(int j=0; j<n2; j++){
        cout<<arr2[i][j]<<" ";
      }
      cout<<endl;
    }
     cout<<endl;   


    // now multiplication is starting
    int res[m1][n2];

    for(int i=0; i<m1; i++){
      for(int j=0; j<n2; j++){ 
        res[i][j] = 0;
                 
        for (int k=0; k<n1; k++){                  // res[i][j]= a[i][0]*b[0][j]  +  a[i][1]*b[1][j]  + ....        
          res[i][j] += arr1[i][k]* arr2[k][j];
        } 

      }
    }


   cout<<"after multiplication -->"<<endl;
    
    for(int i=0; i<m1; i++){
      for(int j=0; j<n2; j++){               
        cout<<res[i][j]<<" ";
      }
      cout<<endl;
    }
      
    
  }
   
  
 return 0; 
 
}