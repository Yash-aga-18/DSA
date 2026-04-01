#include <bits/stdc++.h>#define DAY_ONE cout<<"monday"; 
#define DAY_TWO cout<<"tuesday"; 
#define DAY_THREE cout<<"wednesday"; 
#define DAY_FOUR cout<<"thursday"; 
#define DAY_FIVE cout<<"friday"; 
#define DAY_SIX cout<<"saturday"; 
#define DAY_SEVEN cout<<"sunday"; 

#define MONTH_ONE cout<<"Jan 31 days"; 
#define MONTH_TWO cout<<"Feb 28 days"; 
#define MONTH_THREE cout<<"March 31 days"; 
#define MONTH_FOUR cout<<"April 30 days"; 
#define MONTH_FIVE cout<<"May 31 days"; 
#define MONTH_SIX cout<<"June 30 days"; 
#define MONTH_SEVEN cout<<"July 31 days";
#define MONTH_EIGHT cout<<"Aug 31 days"; 
#define MONTH_NINE cout<<"Sep 30 days"; 
#define MONTH_TEN cout<<"Oct 31 days"; 
#define MONTH_ELEVEN cout<<"Nov 30 days"; 
#define MONTH_TWELVE cout<<"Dec 31 days"; 

#define ERROR cout<<"enter a valid number";

using namespace std;

int main()
{

//  // question --> wap to take input from 1 to 7 and write corresponding week day starting from monday

//  int x;
//  cout<<"enter nth day of the week \n";
//  cin>>x;
//   switch(x)
//    {
//      case 1:
//      DAY_ONE
//      break;
//      case 2:
//      DAY_TWO
//      break;    
//      case 3:
//      DAY_THREE
//      break;
//      case 4:
//      DAY_FOUR
//      break;
//      case 5:
//      DAY_FIVE
//      break;
//      case 6:
//      DAY_SIX
//      break;
//      case 7:
//      DAY_SEVEN
//      break;
 
//      default:
//     ERROR
    
//    }  

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// question--> Write a program to input month number and print total number of days in month using switch case.

  int x;
  cout<<"enter the month number\n";
  cin>>x;
  switch(x){

    case 1:   MONTH_ONE
    break;

    case 2:   MONTH_TWO
    break;

    case 3:   MONTH_THREE
    break;

    case 4:   MONTH_FOUR
    break;

    case 5:   MONTH_FIVE
    break;

    case 6:   MONTH_SIX
    break;

    case 7:   MONTH_SEVEN
    break;

    case 8:   MONTH_EIGHT
    break;

    case 9:   MONTH_NINE
    break;
    
    case 10:  MONTH_TEN
    break;
    
    case 11:  MONTH_ELEVEN
    break;

    case 12:  MONTH_TWELVE
    break;
 
    default:  ERROR;
    break;

  } 
 

  return 0;
 
}