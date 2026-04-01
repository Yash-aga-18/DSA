#include <bits/stdc++.h>
using namespace std;

// leetcode Q->238  Product of Array Except Self

// return an array such that answer[i] is equal to the 
// product of all the elements of nums except nums[i].
// without division

//  Input:   [1,2,3,4]
//  Output:  [24,12,8,6]


void product2(vector<int>& arr){       // without dividing
    
    int n = arr.size();

    vector<long long> pre(n, 1);       // prefix product arr
    vector<long long> suff(n, 1);      // suffix product arr

    // Build special prefix array
    for(int i = 1; i < n; i++)          pre[i] = pre[i - 1] * arr[i - 1];

    // Build special suffix array
    for(int i = n - 2; i >= 0; i--)     suff[i] = suff[i + 1] * arr[i + 1];

    // Multiply prefix and suffix into arr
    for(int i = 0; i < n; i++)          arr[i] = pre[i] * suff[i];


}


// concept used --> here we don't make prefix and suffix product arr as usual
// here, we create them in such a way that it stores only the product before/after it
// here we don't include the idx elemnt as usual we done normally
// and it always starts/end with 1 respectively

// eg-->                  1 2 3 4 
// normal prefix arr -->  1 2 6 24
// special prefix arr --> 1 1 2 6

// we have done in same both pre and suff and we 
// multiply both pre and suff as we require the product of arr excluding the idx
// which we achived already in both (pre and suff) arr
 


void product1(vector<int>& arr){

    int n = arr.size();
    long long product = 1;
    int zeroCount = 0;

    // Step 1: Calculate product of non-zero elements and count zeros
    for(int num : arr){
        if(num == 0)        zeroCount++;
        else                product *= num;
    }

    // Step 2: Build output based on zero count
    for(int i = 0; i < n; i++){

        // Case 1: More than one zero → all results = 0
        if(zeroCount > 1)           arr[i] = 0;
        

        // Case 2: Exactly one zero → only zero-position gets product
        else if(zeroCount == 1){

            if(arr[i] == 0)     arr[i] = product;
            else                arr[i] = 0;

        }


        // Case 3: No zero → normal product except self
        else            arr[i] = product / arr[i];
        
    }

}




int main()
{
    
    vector<int> arr = {1,2,3,4};
    
    for(int ele:arr)    cout<<ele<<" ";         // print  arr
    cout<<endl;
    
    // product1(arr);
    product2(arr);
    
    for(int ele:arr)    cout<<ele<<" ";         // print prefix arr
    cout<<endl;
 
 
  return 0;

}