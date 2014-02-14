//**********************************************
//
// Title: Problem 1: finding min and max of 2 ints
// Author: Lance Brown
// CS1021-001 Date: January 27, 2014
// Laboratory 03
//
// *********************************************
//
// Description: The program asks the user for two integers and prints out the 
//   minimum and maximum values of the two.
//
// Input: Two user supplied integers
//
// Output: The minimum of the range and the maximum
//
// Procedure: Asks user for 2 integers, compares the two to determine the
//   minimum, then compares the two to determine the maximum. If else is used
//   to find the min, but for the max it is assumed that if the first value is
//   not greater than the second, then the second must be the max, using only 
//   one if statement.
//
// Constraints: Input must be integer values.
//
// ***************Begin Program*****************

#include <iostream>
using namespace std;

int main() {
  int first = 0; // the first int from input
  int second = 0; // the second int from input
  cout << "Enter two numbers: ";
  cin >> first >> second;
  
  //find the min
  int min = 0;
  if (first > second) {
    min = second;
  } else {
    min = first;
  }

  //find the max
  int max = second;
  if (first > second) {
    max = first;
  }
  cout << endl << "Minimum of " << first << " and " << second << " is " << min 
    << endl;
  cout << "Maximum of " << first << " and " << second << " is " << max << endl;

  return 0;
}

