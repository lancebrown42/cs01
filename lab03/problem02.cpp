//**********************************************
//
// Title: Problem 2: finding min and max of 3 ints
// Author: Lance Brown
// CS1021-001 Date: January 27, 2014
// Laboratory 03
//
// *********************************************
//
// Description: The program asks the user for three integers and prints out the 
//   minimum and maximum values of the three.
//
// Input: Three user supplied integers
//
// Output: The minimum of the range and the maximum
//
// Procedure: Program asks user for three integers then compares the inputs to
//   determine the minimum and maximum using if/else if statements. The minimum
//   and maximum values of the three inputs are then printed.
//
// Constraints: Input must be unique integer values.
//
// ***************Begin Program*****************

#include <iostream>
using namespace std;

int main() {
  int first = 0; // the first int from input
  int second = 0; // the second int from input
  int third = 0; //
  cout << "Enter three numbers: ";
  cin >> first >> second >> third;
  
  //find the min
  int min = 0;
  if (first < second && first < third) {
    min = first;
  } else if (second < first && second < third) {
      min = second;
  } else if (third < second && third < first) {
      min = third;
  }
    else {
      cout << "Please enter unique integers." << endl;
  }

  //find the max
  int max = 0;
  if (first > second && first > third) {
    max = first;
  } else if (second > first && second > third) {
      max = second;
  } else if (third > second && third > first) {
      max = third;
  } else {
      cout << "Please enter unique integers." << endl;
  }


  cout << endl << "Minimum of " << first << ", " << second << ", and  "
    << third << " is " << min << endl;
  cout << "Maximum of " << first << ",  " << second << ", and  " << third << 
   " is " <<  max << endl;

  return 0;
}

