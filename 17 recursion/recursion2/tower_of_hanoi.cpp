#include <bits/stdc++.h>
using namespace std;

// you have 3 rods and do all this in min steps

// Move one disk at a time.
// Only move the top disk from a rod.
// You can’t put a bigger disk on a smaller one.
// Move all disks from the start rod to the last rod.

void TOH(int n, char beg, char aux, char end){

    if(n==0)    return;

    TOH(n-1, beg, end, aux);              // Move n-1 disks from beg to aux using end
    cout << beg<<" --> "<<end << endl;    // Move nth disk from beg to end
    TOH(n-1, aux, beg, end);              // Move n-1 disks from aux to end using beg

}

int main()
{
    
    int disk;
    cout<<"enter the disks : ";
    cin>>disk;

    TOH (disk,'A','B','C');

    long long moves = pow(2,disk) - 1; 
    cout<<"total moves = "<<moves;

 return 0;

}