#include <bits/stdc++.h>
using namespace std;

int main()
{
  
  
int row, column;
cout<<"enter no. of rows and column\n";
cin>>row;
cin>>column;
int arr[row][column];

cout<<"enter the elements of array"<<endl;
for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
        cin>>arr[i][j];
    }
}

int min=INT_MAX;
int max=INT_MIN;
int sum=0;
int n=0;                // no of elemnts

for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
        if(arr[i][j]<min)   min=arr[i][j];
        if(arr[i][j]>max)   max=arr[i][j];
        sum += arr[i][j];
        n++;
    }
}

 float avg = float(sum)/float(n);

  cout<<"min-->"<<min;
  cout<<endl;
  cout<<"max-->"<<max;
  cout<<endl;
  cout<<"sum-->"<<sum;
  cout<<endl;
  cout<<"avg-->"<<avg;
  
 return 0;

}