#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cout<<"enter number of students"<<endl;
  cin>>n;
  int marks[n];


  cout<<"enter the marks:"<<endl;
  for(int i=0; i<n; i++)
  cin>>marks[i];


 cout<<"roll no having less than 35"<<endl;
  for(int i=0; i<n; i++){
    
    if(marks[i]<35)   cout<<i<<" ";
  }




 return 0;

}