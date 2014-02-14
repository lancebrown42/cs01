//*************************************************88
//
//Title: Problem 05: converting seconds to minutes hours and days
//Author: Lance Brown
//CS1021-001 Date: January 27, 2014
//Laboratory 3
//
//****************************************************
//
// Description: Program that asks user to input a numer of seconds and then another
//   unit of time to which the seconds will be converted. The program then converts
//   seconds to the desired output unit and outputs the result.
//
// Input: User provided number of seconds, and user provided unit for conversion
//
// Output: number of days/hours/minutes in the input number of seconds
//
// Procedure: The program asks the user for a number of seconds, which it then
//   checks to make sure it is non-negative. Then user is prompted for a unit.
//   Depending on the unit, the program converts the number of seconds to that unit,
//   and saves the remainder as the remaining seconds, which it either uses for the
//   next unit conversion or just outputting the remaining seconds. If the input
//   is not an "m" "h" or a "d", an error is output and program ends.
//
// Constraints: Input must be a positive int followed by m, h, or d.
//
// *********Begin Program******************************

#include <iostream>
using namespace std;

int main(){
  int seconds = 0; //number of seconds taken as input
  char unit = 0; //desired unit for conversion
  int convertedMin = 0; // number of minutes converted from seconds
  int convertedHour = 0; // number of hours
  int convertedDay = 0; //days
  int remainder = 0; //placeholder used for division and %
  const int MINUTE = 60; //constants representing bigger units
  const int HOUR = 3600;
  const int DAY = 86400;
  cout << "Enter the number of seconds: ";
  cin >> seconds;
  if (seconds <= 0){ //make sure input is acceptable
    cout << seconds << " is an invalid value." << endl;
    return 0;}
  cout << "Do you want this to be converted to (m)inutes, (h)ours, or (d)ays? ";
  cin >> unit;


  if (unit == 'm') { //converts only to minutes and seconds if minutes is selected
    convertedMin = seconds / MINUTE;
    seconds = seconds % MINUTE;
    cout << convertedMin << " minutes, and " << seconds << " seconds." << endl;
  } else if (unit == 'h') { //converts to hours and minutes if hours is selected
    convertedHour = seconds / HOUR;
    seconds = seconds % HOUR;
    convertedMin = seconds / MINUTE;
    seconds = seconds % MINUTE;
    cout << convertedHour << " hours, " << convertedMin << " minutes, and " << remainder << " seconds." << endl;
  } else if (unit == 'd') { //converts to days hours and minutes if days is selected
    convertedDay = seconds / DAY;
    seconds = seconds % DAY;
    convertedHour = seconds / HOUR;
    seconds = seconds % HOUR;
    convertedMin = seconds / MINUTE;
    seconds = seconds % MINUTE;
    cout << convertedDay << " days, " << convertedHour << " hours, "<< convertedMin << " minutes, and " << remainder << " seconds." << endl;
  } else {
    cout << "Invalid selection." << endl; //if the input isnt valid, break
  }



  return 0;
}
