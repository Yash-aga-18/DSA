    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

// leetcode Q->42
//  ques to determine the amount of water trapped between the buildings width of each bar is 1 unit
// eg--> height=[0,1,0,2,1,0,1,3,2,1,2,1]
// answer is--> 6


// there are 2 methods by creating 2 arrays or by creating one array


int amount2(vector<int>&v){                  // by using 2 arrays
    int n=v.size();

// step 1--> find prev greatest element
    int prev[n];             // prev greatest element array
    prev[0]=-1;
    int max=v[0];

    for(int i=1; i<n; i++){            // to craete an array of prev greatest element
        prev[i]=max;                    
        if(max<v[i])    max=v[i];       
    }

// step 2--> find next greatest element
    int next[n];            // next greatest element array
    next[n-1]=-1;
    max=v[n-1];

    for(int i=n-2; i>=0; i--){              // to craete an array of next greatest element but from last
        next[i]=max;                        
        if(max<v[i])    max=v[i];       
    }

// step-->3 to create a new array or update existing array by finding the min value b/w prev and next array
    
    //  creating a new array
    //  int mini[n];
    //  for(int i=0; i<n; i++){
    //     mini[i]=min(prev[i],next[i]);
    //  }

    // update the prev arr as mini arr to save time and space complexity
    for(int i=0; i<n; i++){
        prev[i]=min(prev[i],next[i]);
    }


// step 4--> to find the amount of water
// amount is always the difference b/w mini value and height of building 
    
    int water = 0;
    for(int i=0; i<n; i++){      

        // if(v[i]<mini[i])     water += mini[i]-v[i];

        if(v[i]<prev[i])        water += prev[i]-v[i];    
        
    }
    return water;
}

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


int amount1(vector<int>&v){                  // by using 1 array
    int n=v.size();

// step 1--> find prev greatest element   (same as before)
    int prev[n];             // prev greatest element array
    prev[0]=-1;
    int max=v[0];

    for(int i=1; i<n; i++){            // to create an array of prev greatest element
        prev[i]=max;                    
        if(max<v[i])    max=v[i];       
    }


// step 2--> find next greatest element but by using prev as next greatest element array
//         also there is no need to find min element sepertely we have done this ion this array simulataneously

    prev[n-1]=-1;
    max=v[n-1];

    for(int i=n-2; i>=0; i--){              // to create an array of next greatest element but from last
        if(max<prev[i]) prev[i]=max;        // it push value of max in array and value should be minimum                    
        if(max<v[i])    max=v[i];           // it updates the value of max
    }

// step 4--> to find the amount of water
// amount is always the difference b/w mini value and height of building

    int water = 0;

    for(int i=0; i<n; i++){             
        
        if(v[i]<prev[i])    water += prev[i]-v[i];    
        
    }

  return water;
}

// //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{

  int x,n;
  vector<int>v;
  cout<<"enter the size of array  ";
  cin>>x;
  cout<<"enter the array \n";
  
  for(int i=0; i<x; i++){                         // taking input 
    cin>>n;       
    v.push_back(n);       
    }       
       
  for(int i=0; i<v.size(); i++){                  // prints the input
    cout<<v[i]<<" ";       
  }       
    cout<<endl;       
         
  int result2 = amount2(v);       
  int result1 = amount1(v);       
  
  cout<<"amount of water by using 2 arrays is "<<result2;            // prints the amount of water
  cout<<endl;
  cout<<"amount of water by using 1 arrays is "<<result1;            // prints the amount of water

 
 return 0;

}