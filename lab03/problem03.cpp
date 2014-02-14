//**********************************************
//
// Title: Problem 3: Magic dates
// Author: Lance Brown
// CS1021-001 Date: January 27, 2014
// Laboratory 03
//
// *********************************************
//
// Description: Program that asks user for a date in a certain format. It then
//   outputs whether or not that specific date is a "Magic date", where the day
//   multiplied by the month is equivalent to the year. 
//
// Input:User supplied date in format month/day/year
//
// Output: Indication of whether or not the input date is magic.
//
// Procedure: Program prompts user for input of a date, which is then parsed
//   into three integer variables and a character placeholder. The integers are
//   checked to make sure the date is valid. If input is valid, the day and
//   month are multiplied, and the result is compared to the year to determine
//   if the date is considered magic.
//
// Constraints: must be an input of valid date in format m/d/y using only the
//   last two digits of the year, or last if it is an 0(*something) year
//
// ***************Begin Program*****************

#include <iostream>
using namespace std;

int main() {
  int month = 0; //month input
  int day = 0; //day input
  int year = 0; //year input
  char slash = 0; //will allow program to ignore /'s in input
  cout << "Enter a date in the format m/d/y: ";
  cin >> month >> slash >> day >> slash >> year;

// ******* THIS COMMENT BLOCK IS WORTHLESS BUT I DONT WANT TO DELETE IT****
/*  cout << "Enter a date in the format m/d/y: ";
  string date;
  getline(cin,date); //read input as a string
  
  // find the /'s in string so they can be disregarded
  size_t slash1 = date.find("/");
  size_t slash2 = date.find("/", slash1 + 1);
  size_t slash3 = date.find("/", slash2 +1);

  // break date into substrings
  string strMonth = date.substr(0,slash1);
  string strDay = date.substr(slash1,slash2);
  string strYear = date.substr(slash2);

  //convert numbers in substrings to ints
  month = atoi(strMonth);
  day = atoi(strDay);
  year = atoi(strYear);

  //smash face on table because prof just explained a much easier way to do this.
*/
  
  //check for valid input format
  if (!(month <= 12 && month >= 1)) {
    cout << endl << "Please input a valid date with month between 1 and 12.\n";
  }
  if (!(day <= 31 && day >= 1)) {
    cout << endl << "Please input a valid date with day between 1 and 31.\n";
  }
  if (!(year <= 99)) {
    cout << endl << "Please input a valid date with year between 00 and 99.\n";
  }
  
  //multiply month and day
  int monthDay = month * day;

  // check to see if its a magic date
  if (monthDay == year){
    cout << "The date " << month << slash << day << slash << year
      << " is a magic date.\n";
  } else {
    cout << "The date " << month << slash << day << slash << year
      << " is NOT a magic date.\n";
  }
  return 0;
  
}


