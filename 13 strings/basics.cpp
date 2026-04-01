#include <bits/stdc++.h>
using namespace std;

int main()
{

//   // strings are basically char arrays
// all are characters enclosed in (" ") except \ and \0


//   char str0[] = {'a','b','c','d','e'} ;
//   char str1[6] = {'a','b','c','d','e'} ;         // take 1 extrra size for \0
//   char str2[] = "abcdefgty67890" ;
//   char str3[5] = "abcd" ;                    // already last space reserved for \0

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// to print a string--------->

//   for(int i=0; i<=5; i++){
//      cout<<str1[i];
//   }



//   for(int i=0; str[i]!='\0'; i++){
//     cout<<str0[i];
//   }


    
//   cout<<str0<<endl;
//   cout<<str1<<endl;

    
//      char str1[5] = {'a','b','c','d','e'} ;             // a b c d \0
//      char str1[6] = {'a','b','c','d','e'} ;             // a b c d e
// //   cout<<int(str1[9]);       // it indicates that '\0' is placed at the end

// in c++ strings are mutable  i.e str[0]='v';      it will updates the stored str1[0] index value  

// // it is reccomended to use #include<string> as header file before using string as data type
// // string is class but we here to study as data type-->

//  string str = "Yash Agarwal";                  
//  cout<<str<<endl;                               
 

// cout << "He said, \"Hello! \"   ";       // way to print double quotes also
// Output: He said, "Hello! "

// Without the backslash, the compiler would get confused because
//  the inner " would prematurely end the string.


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// // input in string-->


//   string s;   

//   cin>>s;                     // but problem is when you enter space it treats as '\0'
//   getline(cin,s);             // it is used to overcome the above problem
//   cout<<s;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// some built in functions are  -------->


//  string str = "abcd";
//   cout<<str<<endl;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// // to find length -------->  


//   string str = "abcd";
//     cout<<str.size()<<endl;          //  or we can use
//     cout<< str.length()<<endl;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// // push back and pop back -------->  


//  string str = "abcd";
//     str.push_back('e');     // we can only use char to pushback
//     cout<<str<<endl;

//     str.pop_back();         // it deletes the last char
//     cout<<str<<endl;


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


// //   + operator -------->            // used to concatenates 2 strings
//     string s = "abc";
//     string t = "123";
//     s = s + t;
//     cout<<s<<endl;
//     s = s + t + "963";
//     cout<<s<<endl;

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// // reverse-------->  
//     string temp = "abcdefgh";


//  // reverse(temp.begin(), temp.end());          // it reverses whole string 
//  // cout<<temp<<endl;


//  //   int i=0, j=temp.length();
//  //   reverse(temp.begin()+2, temp.end());          // it reverses till end of string 
//  //   cout<<temp<<endl;

//       reverse(temp.begin()+2, temp.end()-3);          // it reverses specific part of string 

//  //            OR

//     reverse(temp.begin()+2, temp.begin()+5);          // it reverses specific part of string 
//     cout<<temp<<endl;     

// note that you have to add 1 more index till you want it reverse 
// in this case it reverses the 2nd,3rd,4th index only   not 5th index


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//substring()  --------> 


// string s="abcdefg";

// // s.substr(idx,len)         // basic format

// cout << s.substr(1,3)<<endl;              // starts print from 1st index upto next 3 characters     i.e. bcd
// cout << s.substr(2)<<endl;                // starts print from 2nd index to last i.e cdefg
// cout << s.substr(s.size() - 3)<<endl;       // last 3 chars to print
// cout << s.substr(0, s.size() - 3)<<endl;    // start at 0, take (length - 3) chars
// int start = 2; // from 'c'
// int end = 5;   // till 'f'
// string sub = s.substr(start, end - start + 1);
// cout << sub << endl;  // Output: "cdef"


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// to_string()-------->         //it is used to convert any data type to string


// int x=10;
// string s = to_string(x);
// cout<<s;
// //  can used to find no of digits of a no. without any loop just by using str.length()

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// // sort()-------->  
// // similarly like vectors  sort(s.begin(),s.end());    but it sorts based on ASCII value

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------


// //stringstream variable(string_name)        // it is used to store or print string word by word
// // it is recommended to use #include<sstream> as header file
// // or we can understand as it removes spaces from a given string

//    string str="I am studying in ims eng. college. second year";
//    stringstream s1(str);            
//    string temp;        

//     while(s1>>temp){            // method to take input in another string
//         cout<<temp<<endl;       
//     }
// // string temp is taking input from stringstream ss
// //  I
// //  am
// //  studying...


// string s = "123 456";
// stringstream ss(s);
// int a, b;
// ss >> a >> b;
// cout << a+b; // 579

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// stoi() and stoll()           // they didnt store leading zeroes
// stoi--> string to int
// stoll--> string to long long


// string str1="0012345";
// int x = stoi(str1);

// string str2="1234561256464";
// long long y = stoll(str2);

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// .compare()----------------->

// string s = "abzd";
// string t = "abxe";
  
// cout<<s.compare(s);

// //  0   if s == t
// //  +ve if s > t
// //  -ve if s < t 


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// .back()-------------->   to access the last element of string

string str = "abcdefxyz";
cout<<str.back();


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------




 return 0;

}