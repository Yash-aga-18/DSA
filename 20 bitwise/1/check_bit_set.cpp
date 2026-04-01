#include <bits/stdc++.h>
using namespace std;

// A bit is SET means the value of that bit is 1.


void check_bit(int n, int i){

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// // Using Left shift

    // Create mask by left shifting 1 by i positions
    // i = 2 → mask = 0001 << 2 = 0100
    int mask = 1 << i;

    // AND with n to check the bit
    if (n & mask)  cout<<"Bit is SET";      // Non-zero result means bit is set  
    else           cout<<"Bit is NOT set";  // Zero means bit is not set

    cout<<endl;


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// // Using Right shift


    // Right shift n by i positions as it cames the checking bit to rightmost
    int shifted = n >> i;

    // AND with 1 to check the least significant bit
    if (shifted & 1)    cout << "Bit is SET";
    else                cout << "Bit is NOT set";

    cout<<endl;


}



void set_bit(int &n, int i){

    int mask = 1 << i;

    n = n | mask;    // Or with n to set the bit

    cout<<"New number after setting is --> "<<n;
    cout<<endl;

}


void clear_bit(int &n, int i){

    int mask = 1 << i;
    mask = ~mask;

    n = n & mask;    // And with n to clear the bit

    cout<<"New number after clearing is --> "<<n;
    cout<<endl;

}


void toggle_bit(int &n, int i){

    int mask = 1 << i;

    n = n ^ mask;    // And with n to toggle the bit

    cout<<"New number after togggling is --> "<<n;
    cout<<endl;

}



void remove_last_set_bit(int &n){

    n = n & (n-1);

    cout<<"New number after removing last set bitR is --> "<<n;
    cout<<endl;

}


void count_set_bits(int &n) {
    int count = 0;

    while (n > 0) {
        n = n & (n - 1);   // removes last set bit
        count++;
    }

    cout<<"no. of set bits are --> "<< count;
}


void find_right_set_bits(int &n) {
    int count = 0;

    // This isolates the rightmost set bit
    int rightmost = (n & (n - 1)) ^ n;

    cout << "Rightmost set bit value = " << rightmost << endl; // it gives the value only

}


int main()
{

    int n = 13;   // 1101
    int i = 1;    // check 2nd bit (0-based)


    check_bit(n,i);
    set_bit  (n,i);
    clear_bit(n,i);
    toggle_bit(n,i);
    remove_last_set_bit(n);
    count_set_bits(n);
    find_right_set_bits(n);


    return 0;

}

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
/* Check ith bit is SET or not

 Left Shift------>

    n    = 1101      i = 2
    mask = 0100   (1 << 2)

    1101
&   0100
-----------
    0100  → non-zero → Bit is set
-----------
 
 
Right Shift------>

    n    =   1101      i = 2
    n >> 2 = 0011

   0011
&  0001
---------
   0001  → non-zero → SET
-----------


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Set ith bit 
    
    n    = 1001      i = 1
mask =     0001 << 1 = 0010
Step 2: OR operation

   1001
|  0010
---------
   1011     <-- New number is 11
-----------

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Clear ith bit

    n     = 1011      i = 1
mask  =     0001 << 1 = 0010
~mask =     1101

Step 2: AND operation

   1011
|  0010
----------
   1001     <-- New number is 9
-----------


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Toggle ith bit

    n     = 1011      i = 1
mask  =     0001 << 1 = 0010

Step 2: XOR operation

   1011
^  0010
----------
   1001     <-- New number is 9
-----------

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Remove last SET bit

Apply the rule for n − 1

Rule recap:
Rightmost 1 → becomes 0
All bits to the right → become 1
Left remains unchanged

n     = 10010000
n - 1 = 10001111


*/
