#include <bits/stdc++.h>
using namespace std;


int main()
{
    
//  decimal to binary

    // int num = 11;
    // string res = "";

    // int temp = num;

    // while(temp>0){

    //     if (temp%2 == 1) res += '1';
    //     else res+= '0';

    //     temp /=2;
    // }

    // reverse(res.begin(), res.end());
    // cout<<res<<endl;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//  binary to decimal

    string bin = "1011";
    int power = 1;
    int ans = 0; 

    for(int i = bin.size()-1; i>=0; i--){

        if(bin[i] == '1')   ans += power;
        power *= 2 ;

    }
    cout<<ans<<endl;



 return 0;

}