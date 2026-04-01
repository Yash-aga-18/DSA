#include <bits/stdc++.h>
using namespace std;
// leetcode Q->31

// // next permutation of array is greater than prev one
// eg arr1[]={1,2,3,4}
// you are given 2134 then the next perm is 2314


void next_perm(vector<int>&v ){

int n=v.size();
int idx=-1;

// step 1    to find pivot idx
for(int i=n-2; i>=0; i--){
    if(v[i]<v[i+1]){
        idx=i;
        break;
    }
}
cout<<v[idx]<<endl;

// step 2  idx reamin -1 only if the perm is already greatest  eg--> 5 4 3 2 1
    if(idx==-1){
        reverse(v.begin(),v.end());
        return;
    }

// step 2  if idx changes then make the array sorted/reverse
// (as array in descending order) after the idx always so we tries to make in ascending order
    // to reverse array between i,j  then you have to--> reverse(v.begin()+i,v.end()j+1)   
    // remember the end should be j+1

    reverse(v.begin()+(idx+1),v.end());

// step 3  you have to find just greater num than pivot element
    int j=-1;

    for(int i=idx+1; i<n; i++){
        if(v[idx]<v[i]){
            j=i;
            break;
        }
    }

// step 4  now swap idx and j
    swap(v[idx],v[j]);


    return;

}



int main()
{
    vector<int>v(5);
    cout<<"enter the perm. of an array from 1 to 5"<<endl;

    for(int i=0;i<v.size(); i++){                    // taking input of perm from user
        cin>>v[i];
    }

    for(int i=0;i<v.size(); i++){                // print a vector
     cout<<v[i]<<" ";
    }
    cout<<endl;


    next_perm(v);


    for(int i=0;i<v.size(); i++){                // print next perm
        cout<<v[i]<<" ";
    }



 return 0;

}