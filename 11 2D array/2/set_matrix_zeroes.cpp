#include <bits/stdc++.h>
using namespace std;


// leetcode Q->73   Set Matrix Zeroes

// Given an m x n integer matrix matrix, if an element is 0, 
// set its entire row and column to 0's.

// Input:  [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]



void display(vector<vector<int>> &arr, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



void method1(vector<vector<int>> &arr2, vector<vector<int>> &arr1, int m, int n) {
    
    // Making a copy of the used part of arr1 into arr2
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr2[i][j] = arr1[i][j];
        }
    }


    // Checking for zeroes in the copy (arr2) and making changes in the original (arr1)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr2[i][j] == 0) {
                
                for (int b = 0; b < n; b++)  arr1[i][b] = 0;   // Making the entire row 0 in arr1
        
                for (int a = 0; a < m; a++)  arr1[a][j] = 0;  // Making the entire column 0 in arr1

            }
        }
    }

    display(arr1, m, n);        // to display the output

}



void method2(vector<vector<int>> &arr1, int m, int n) {

    vector<bool> r(m, true);
    vector<bool> c(n, true);

// if any zeroes found in the row then make changes in r[i] similarly for c[j]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr1[i][j] == 0) {
                r[i] = false;
                c[j] = false;
            }
        }
    }

// Step 2: Zero out marked rows
    for (int i = 0; i < m; i++) {
        if (r[i] == 0) {
            for (int j = 0; j < n; j++)     arr1[i][j] = 0;
            
        }
    }

// Step 3: Zero out marked columns
    for (int j = 0; j < n; j++) {
        if (c[j] == 0) {
            for (int i = 0; i < m; i++)     arr1[i][j] = 0;
            
        }
    }

    display(arr1, m, n);  // show output
}



void method3 (vector<vector<int>> &arr1, int m, int n) {
    
    // init row =  arr[...][0]
    // init col =  arr[0][...]

    bool firstRow = true, firstCol = true;

    
    for (int j = 0; j < n; j++)     // check if first row has zero
        if (arr1[0][j] == 0)    firstRow = false;
    

    for (int i = 0; i < m; i++)     // check if first col has zero
        if (arr1[i][0] == 0)    firstCol = false;



    // mark rows and cols using first row/col except first row,col
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {

            if (arr1[i][j] == 0) {

                arr1[i][0] = 0;  // mark row
                arr1[0][j] = 0;  // mark col
            }
        }
    }

    // set zerores using markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {

            if(arr1[i][j] !=0 ) {   
                if (arr1[i][0] == 0 || arr1[0][j] == 0)   arr1[i][j] = 0;
            }
        }
    }


    // finally zero the first row if needed
    if (firstRow == 0) {
        for (int j = 0; j < n; j++) arr1[0][j] = 0;
    }

    // finally zero the first col if needed
    if (firstCol == 0) {
        for (int i = 0; i < m; i++) arr1[i][0] = 0;
    }

    display(arr1, m, n);
}





int main() {

    int m, n;

    cout << "enter value of m*n of mtx" << endl;
    cin >> m >> n;

    vector<vector<int>> arr1(m,vector<int>(n));
    
    cout << "enter the elements of mtx" << endl;            // input
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>arr1[i][j];
        }
    }
    
    cout << "Original Matrix:" << endl;
    display(arr1, m, n);
    
    
    cout << "Matrix after setting zeroes:" << endl;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// // method-1  using an extra 2-d arr------>

// Time: O(mn(m + n)) (can get very expensive if m, n are large)
// Space: O(mn)
    
    // vector<vector<int>> arr2(m,vector<int>(n));
    // method1(arr2, arr1, m, n);
    

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// // method-2  using extra 2 (1-d) arr------>

// Time: O(mn) 
// Space: O(m+n)

    // method2(arr1, m, n);


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// // method-3  without using extra space------>

// Time: O(mn) 
// Space: O(1)

    method3(arr1, m, n);



    return 0;
}