#include <bits/stdc++.h>
using namespace std;

// leetcode Q->29   divide two integers only bitwise


long divide(long dividend,long divisor){
   
    if (divisor == 0) return INT_MAX;
    if (dividend == INT_MIN && divisor == -1)   return INT_MAX;

    // determine sign
    bool sign = true;
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))     sign = false;

    // convert to positive long long
    long long n = llabs((long long)dividend);
    long long d = llabs((long long)divisor);

    long long quotient = 0;

    while (n >= d) {

        int cnt = 0;

        while(n >= (d << (cnt+1))){     // d* 2^cnt+1 == d << (cnt+1) 
            cnt++;
        }

        quotient += (1LL<<cnt);             //   2^cnt == 1<<cnt
        n -= (d<<cnt);                 //   d*2^cnt == d<<cnt

    }

    if (!sign) quotient = -quotient;

    // bring it to int range
    if (quotient > INT_MAX) return INT_MAX;
    if (quotient < INT_MIN) return INT_MIN;

    return (int)quotient;

}

int main()
{
    
    long dividend, divisor;
    cout<<"enter the dividend and divisor"<<endl;

    cin>>dividend;
    cin>>divisor;


    cout<< divide(dividend,divisor);


 return 0;

}
/*
We have to  find which (divisor* 2^x) can be the maximum to remove from dividend
Then we remove that value from dividend and again do same step


Example: divide 21 by 3

Initial values:
n = 21
d = 3
quotient = 0

------------------------------------------------
while (n >= d)
------------------------------------------------

================= ITERATION 1 =================
n = 21

cnt = 0

Inner while loop:
Check how much we can shift divisor (d) without exceeding n

d << (cnt+1) = 3 << 1 = 6   <= 21  ✔  → cnt = 1
d << (cnt+1) = 3 << 2 = 12  <= 21  ✔  → cnt = 2
d << (cnt+1) = 3 << 3 = 24  > 21   ✘  → stop

So:
cnt = 2
d << cnt = 3 << 2 = 12

Update quotient:
quotient += 1 << 2 = 4

Subtract from n:
n = 21 - 12 = 9

------------------------------------------------

================= ITERATION 2 =================
n = 9

cnt = 0

Inner while loop:
d << 1 = 6   <= 9 ✔  → cnt = 1
d << 2 = 12  > 9 ✘  → stop

cnt = 1
d << cnt = 3 << 1 = 6

Update quotient:
quotient += 1 << 1 = 2
Total quotient = 6

Subtract from n:
n = 9 - 6 = 3

------------------------------------------------

================= ITERATION 3 =================
n = 3

cnt = 0

Inner while loop:
d << 1 = 6 > 3 ✘  → stop

cnt = 0
d << cnt = 3 << 0 = 3

Update quotient:
quotient += 1 << 0 = 1
Total quotient = 7

Subtract from n:
n = 3 - 3 = 0

------------------------------------------------

Loop ends because:
n < d   (0 < 3)

Final Answer:
21 / 3 = 7



*/