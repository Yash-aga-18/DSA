#include <bits/stdc++.h>
using namespace std;

// rotate by 3 means
// 7 8 9 10 11 12 13  ---> 11 12 13 7 8 9 10   

void display(vector<int>a)
{
  for(int i=0; i<a.size(); i++)
    cout<<a[i]<<" ";

 cout<<endl;
}

void reverse(int i, int j, vector<int>&v)
{
  while (i <= j) {
    swap(v[i], v[j]);
    i++;
    j--;
  }
}


int main()
{

  int n;
 cout<<"enter size of array :";
 cin>>n;

  vector<int>v1(n);

  cout<<"enter array"<<endl;
  for(int i=0; i<v1.size(); i++)
  cin>>v1[i];

 cout<<endl;

  int k;
 cout<<"rotate by: ";
 cin>>k;
 
 // lets take an array 7 8 9 10 11 12 13  by 3 

  if(k>n) k = k % n;                       // avoid unnecessary rotation
  if(k==0) display(v1);


  reverse(0,   n-k-1, v1);                // it rotates array till before k             // 10 9 8 7 11 12 13
  reverse(n-k, n-1,   v1);                // it reverse rotating times part             // 10 9 8 7 13 12 11
  reverse(0,   n-1,   v1);                  // it reverse whole array                     // 11 12 13 7 8 9 10


  // reverse(0, n-1, v1);     // reverse whole array
  // reverse(0, k-1, v1);     // reverse first k elements
  // reverse(k, n-1, v1);     // reverse remaining elements
  display(v1);
  
 return 0;

}