#include <bits/stdc++.h>
using namespace std;

void display(vector<int>&a){

  for(int i=0; i<a.size(); i++) {
   cout<<a[i]<<" ";
  }

  cout<<endl;
}


void rev(int i, int j, vector<int>&v)
{

  while (i < j) {
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
  for(int i=0; i<v1.size(); i++) {
   cin>>v1[i];
  }
  cout<<endl;
  

//   vector<int>v2(n);

//   for(int i=0; i<v1.size(); i++){
//    int j = v1.size()-1-i;            //    i + j = size - 1
//    v2[i] = v1[j];
//   }

//   display(v2);

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  without extra array

// int i=0;
// int j=v1.size()-1;
// while(i<=j){
//     swap(v[i],v[j]);
//     i++;
//     j--;
// }



// for(int i=0,j=v1.size()-1; i<=j; i++, j-- ){
//     swap(v[i],v[j]);
// }



//  reverse(v1.begin(),v1.end());           // it is in-built function

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  reverse a part of an array

int x,y;
cout<<"enter first & last index for reverse"<<endl;
cin>>x;
cin>>y;

reverse( v1.begin()+x, v1.begin()+y+1 );


// rev(x,y,v1);
display(v1);



return 0;

}