#include <bits/stdc++.h>
using namespace std;
// merge two different sorted arr into a new arr 

vector<int> merge(vector<int>&v1 , vector<int>&v2){      // we can return an array or vector also
    int m = v1.size();
    int n = v2.size();
    vector<int>v(m+n);           // new vector is created of combined size of both

    int i=0;
    int j=0;
    int k=0;

    while(i<m && j<n){
        if(v1[i]<v2[j]) {
            v[k]=v1[i];
            i++;
        }
        else {
            v[k]=v2[j];
            j++;
        }

     k++;
    }           //till here some elemnts are remaining either in one vector


    if(i==m){               // it means all the elemnts of v1 are pushed already
        while(j<n){
            v[k]=v2[j];
            j++;
            k++;
        }
    }

    if(j==n){                // it means all the elemnts of v2 are pushed already
        while(i<m){
            v[k]=v1[i];
            i++;
            k++;
        }
    }

  return v;  
}


int main()
{
  vector<int>v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(5);
  v1.push_back(8);

 for(int i=0; i<v1.size(); i++)
 cout<<v1[i]<<" ";
 cout<<endl;



  vector<int>v2;
  v2.push_back(0);
  v2.push_back(3);
  v2.push_back(4);
  v2.push_back(6);
  v2.push_back(7);
  v2.push_back(9);
  v2.push_back(10);

 for(int i=0; i<v2.size(); i++)
 cout<<v2[i]<<" ";
 cout<<endl;


  vector<int>v3 = merge(v1,v2);

 for(int i=0; i<v3.size(); i++)
 cout<<v3[i]<<" ";

 return 0;

}