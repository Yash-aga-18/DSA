#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    int arr[3][3]= {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    

    // // print--->     1   42   753   86   9

    // for (int k = 0; k<n; k++){           // prints upper half
    //     int i = k;
    //     int j = 0;

    //     while(i>=0 && j<n){
    //         cout<<arr[i][j];
    //         i--;
    //         j++;
    //     }
    //     cout<<endl;
    // }


    // for (int k = 1; k < n; k++) {        // prints lower half
    //     int i = n - 1;
    //     int j = k;

    //     while (i >= 0 && j < n) {
    //         cout << arr[i][j];
    //         i--;
    //         j++;
    //     }
    //     cout << endl;
    // }

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
   
    // // print--->    3   26    159    48     7

    for (int k = n - 1; k >= 0; k--) {
        int i = 0;
        int j = k;

        while (i < n && j < n) {
            cout << arr[i][j];
            i++;
            j++;
        }
        cout << endl;
    }

    for (int k = 1; k < n; k++) {
        int i = k;
        int j = 0;

        while (i < n && j < n) {
            cout << arr[i][j];
            i++;
            j++;
        }
        cout << endl;
    }



 return 0;

}