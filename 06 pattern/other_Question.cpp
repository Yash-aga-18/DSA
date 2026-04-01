#include <bits/stdc++.h>
using namespace std;


int space(int num) {

    for(int k=0; k<num ; k++) {
        cout<<" ";
    }
  return -1;
}



int main()
{
  
 int i,j,k;
 int n = 5;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  //  diamond pattern


// for(i=0; i<n; i++){                                 // upper part of diamond
//     for(j=0; j<n-i-1; j++){
//         cout<<"   ";
//     }
//     for(j=0; j<i+1; j++){
//         cout<<" * ";
//     }
//     if(i!=0){
//         for(j=0; j<i; j++){
//             cout<<" * ";
//         }
//     }
//     cout<<endl;
//    }


// for(i=n-1; i>0; i--){                               // lower part of diamond
//     for(j=0; j<n-i; j++){
//         cout<<"   ";
//     }
//     for(j=0; j<i; j++){
//         cout<<" * ";
//     }
//     if(i!=1){
//         for(j=0; j<i-1; j++){
//             cout<<" * ";
//         }
//     }
//     cout<<endl;
//    }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  //    hourglass pattern

// for(i=n; i>0; i--){
//     for(j=0; j<n-i; j++){
//         cout<<" ";
//     }
//     for(j=0; j<i; j++){
//         cout<<"*";
//     }
//     if(i!=1){
//         for(j=0; j<i-1; j++){
//             cout<<"*";
//         }
//     }
//     cout<<endl;
//    }
// for(i=1; i<n; i++){                                 // lower part of hourglass
//     for(j=0; j<n-i-1; j++){
//         cout<<" ";
//     }
//     for(j=0; j<i+1; j++){
//         cout<<"*";
//     }
//     if(i!=0){
//         for(j=0; j<i; j++){
//             cout<<"*";
//         }
//     }
//     cout<<endl;
//    }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  //  hollow pyramid


//  for(i=0; i<n-1; i++){
//     for(j=0; j<n-i-1; j++){
//         cout<<" ";                      // print outer spacs
//     }
//     cout<<"*";                          // print the first star
//     if(i!=0){
//         for(j=0; j<2*i-1; j++){
//         cout<<" ";                      // print the inner spaces
//         }
//         cout<<"*";                      // print the second star
//     }
//     cout<<endl;
//  }

// for(j=0; j<2*n-1; j++){                 // used to print the base line of pattern
//     cout<<"*";
// }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  //    hollow inverted pyramid


//  for(j=0; j<2*n-1; j++){                 // used to print the top line of pattern
//     cout<<"*";
//  }
//   cout<<endl;

//  for(i=1; i<n; i++){
//     for(j=0; j<i; j++){
//         cout<<" ";                            // print outer spacs
//     }                             
//     cout<<"*";                              // print the first star
                              
//     if(i!=(n-1)){                             
//         for(j=0; j<2*(n-i-1)-1; j++){                             
//         cout<<" ";                              // print the inner spaces
//         }                             
//         cout<<"*";                            // print the second star
//     }
//     cout<<endl;
//  }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//   //  hollow diamond


// for(i=0; i<n; i++){
//     for(j=0; j<n-i-1; j++){
//         cout<<" ";                      // print outer spacs
//     }
//     cout<<"*";                          // print the first star
//     if(i!=0){
//         for(j=0; j<2*i-1; j++){
//         cout<<" ";                      // print the inner spaces
//         }
//         cout<<"*";                      // print the second star
//     }
//     cout<<endl;
//  }


//  for(i=n-2; i>=0; i--){
//     for(j=0; j<n-i-1; j++){
//         cout<<" ";                            // print outer spacs
//     }                             
//     cout<<"*";                              // print the first star
                              
//     if(i!=0){                             
//         for(j=0; j<2*i-1; j++){                             
//         cout<<" ";                              // print the inner spaces
//         }                             
//         cout<<"*";                            // print the second star
//     }
//     cout<<endl;
//  }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // hollow hourglass


//  for(j=0; j<2*n-1; j++){                 // used to print the top line of pattern
//     cout<<"*";
//  }
//   cout<<endl;

//  for(i=1; i<n; i++){
//     for(j=0; j<i; j++){
//         cout<<" ";                            // print outer spacs
//     }                             
//     cout<<"*";                              // print the first star
                              
//     if(i!=(n-1)){                             
//         for(j=0; j<2*(n-i-1)-1; j++){                             
//         cout<<" ";                              // print the inner spaces
//         }                             
//         cout<<"*";                            // print the second star
//     }
//     cout<<endl;
//  }


//  for(i=1; i<n-1; i++){
//     for(j=0; j<n-i-1; j++){
//         cout<<" ";                      // print outer spaces
//     }
//     cout<<"*";                          // print the first star
//     if(i!=0){
//         for(j=0; j<2*i-1; j++){
//         cout<<" ";                      // print the inner spaces
//         }
//         cout<<"*";                      // print the second star
//     }
//     cout<<endl;
//  }

// for(j=0; j<2*n-1; j++){                 // used to print the base line of pattern
//     cout<<"*";
// }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // number pyramid pallindrome           1     121     12321      1234321


// for (i=0; i<n; i++){
//     for(j=0; j<n-1-i; j++){
//         cout<<" ";
//     }
//     for(k=1; k<=i+1; k++){
//         cout<<k;
//     }
//     if(i!=0){
//         for(k=i; k>0; k--){
//             cout<<k;
//         }
//     }
//     cout<<endl;
// }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  //  spiral pattern     pseudo code
//      1 1 1 1 1
//      1 2 2 2 1
//      1 2 3 2 1
//      1 2 2 2 1
//      1 1 1 1 1

    n=3;

for(i=1; i<=2*n-1; i++){
    for(j=1; j<=2*n-1; j++){

        int a = i;
        int b = j;
        
        if(a>n)  a = 2*n - i;
        if(b>n)  b = 2*n - j;

        cout<<min(a,b)<<" ";
    }
    cout<<endl;
}


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  //  spiral pattern

//       3 3 3 3 3
//       3 2 2 2 3
//       3 2 1 2 3
//       3 2 2 2 3
//       3 3 3 3 3

// just make little changes in last cout


// for(i=1; i<=2*n-1; i++){
//     for(j=1; j<=2*n-1; j++){

//         int a = i;
//         int b = j;
        
//         if(a>n)   a = 2*n - i;
//         if(b>n)   b = 2*n - j;

//         int x = min(a,b);
//         cout<<n-x+1<<" ";

//     }
//     cout<<endl;
// }


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  //  swastik pattern


    // int n = 15;
 

    // for(int i=0; i<n; i++){

    //     if(i==0 || i==n-1) {           // 1st and last line ke liuye
            
    //         if(i==0){
    //             cout<<"*";
    //             space((n/2)-1);
    //             for(int k=0; k<n/2 +1; k++){
    //                 cout<<"*";
    //             }
    //             cout<<endl;
    //         }

    //         else{
    //             for(int k=0; k<n/2 +1; k++){
    //                 cout<<"*";
    //             }
    //             space((n/2)-1);
    //             cout<<"*";

    //         }

    //     }                              // yha khatam


    //     else{           

    //         if(i<int(n/2 )) {                // ye upper half dega 
    //             cout<<"*";
    //             space((n/2)-1);
    //             cout<<"*";
    //             cout<<endl;
    //         }

            
    //         if(i==int(n/2)){                  // mid wali straight line
    //             for(int k=0; k<n; k++){
    //                 cout<<"*";
    //             }
    //             cout<<endl;
    //         }


    //         if(i>int(n/2)) {                    // lower part dega 
                
    //             space(n/2);
    //             cout<<"*";
    //             space( n/2 -1);
    //             cout<<"*";
    //             cout<<endl;
    //         }

    //     }
        
    // }




 return 0;

}