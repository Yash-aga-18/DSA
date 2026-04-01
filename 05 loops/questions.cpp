#include <bits/stdc++.h>
using namespace std;

int main()
{


  // // to count the no. of digits

  // int n,temp,count=0;
  // cout<<"enter the number \n";
  // cin>>n;
  // temp=n;

  // while(temp>0){
  //   temp=temp/10;
  //   count++;
  // }
  // cout<<"no of digits are "<<count;


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// // to print sum of digits


//   int n,temp,rem,sum=0;
//   cout<<"enter the number \n";
//   cin>>n;
//   temp=n;

//   while(temp>0){
//     rem=temp%10;
//     sum=sum+rem;
//     temp=temp/10;
//   }
//  cout<<"sum of digits of "<<n<<" is "<<sum;


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // to reverse a number


//   int n,temp,rev=0,rem;
//   cout<<"enter the number \n";
//   cin>>n;
//   temp=n;

//   while(temp>0){
//     rem=temp % 10;
//     rev=rev*10 + rem;
//     temp=temp / 10;
//   }
//  cout<<"reverse of "<<n<<" is "<<rev;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // to print the factorial


//  int n,i,fact=1;
//   cout<<"enter the number \n";
//   cin>>n;
 
//   for(i=1; i<=n; i++){
//     fact = fact * i;
//   }

//  cout<<"factorial of "<<n<<" is "<<fact;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // print fibbonaci series       1 1 2 3 5


//  int n, i, sum=0, a=1, b=1;
//  cout<<"enter the no. of terms \n";
//   cin>>n;
   
//   if(n<=0)
//   cout<<"Invalid case";
  
//   else if(n==1)
//     cout<<a;

//   else if(n>=2) {
//     cout<<a<<" "<<b<<" ";
//     for(i=1; i<=n-2; i++) {
//       sum = a + b;
//       a = b;
//       b = sum;
//       cout<<sum<<" ";
//     }
//   }


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// // print the sum of all the even digits of a given number    eg-->  4556   gives 10


//  int n,num,sum=0,rem;

//  cout<<"enter a number"<<endl;
//  cin>>n;
//  num=n;

//   while(num!=0) {
//    rem = num % 10;
    
//     if(rem % 2 == 0)
//     sum += rem;

//    num /= 10;
//   }
//  cout<<sum;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  //  Armstrong nmber checks

// int n,num,c=0,rem=0,sum=0;

// cout<<"Enter a number"<<endl;
// cin>>n;
// num = n;

//   while(num!=0){
//     num = num / 10;
//     c++;
//   }
  
//   num = n;

//   while(num!=0) {
//     rem = num % 10;
//     sum = sum + (pow(rem,c));
//     num = num / 10;
//   }

//   if (n == sum)  cout<<"armstrong";
//   else cout<<"not armstrong";


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  // prints armstrong number


  for (int i = 1; i<=500; i++) {
    int temp = i;
    int c = 0, rem = 0, sum = 0;

    while(temp != 0){
      temp /= 10;
      c++;
    }
    
    temp =i;

    while(temp != 0){
      rem = temp % 10;
      sum += pow(rem,c);
      temp = temp /10;
    }
    
    if (sum == i)   cout<<i<<" ";
  }
  

 return 0;

}