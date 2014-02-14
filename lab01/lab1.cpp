// ***********************************
// Title: A riddle program for Lab 1
// Author: Lance Brown
// CS1021-01 Date January 13, 2014
// Laboratory: 1
//
// ***********************************
//
// Description: This program presents a riddle for the user with a series of clues.
//
// Input: Only from user.
//
// Output: Displays to the terminal a series of riddle clues and the answer.
//
// Procedure: Each riddle clue is displayed. There is a wat until user
// input is read to determine if the next clue should be displayed.
// Finally, when the user needs no more clues, the riddle answer is displayed.
//
// Constraints: The riddle should have at least 2 clues and be G-Rated.
//
// ***********BEGIN PROGRAM*************

#include <iostream>
using namespace std;


int main() {
  cout << "Welcome. Here is a riddle:\n";
  cout << "If you say my name, then I am gone. Who am I?\n";
  cout << "Do you need another clue? (y/n)";
  char response;
  cin >> response;
  if ( response == 'y' ) {
    cout << "Ok, here is the next clue.\n";
    cout << "If you say nothing, then I am golden.\n";
  }
  cout << "Hit any key then enter to see the answer";
  cin >> response;
  cout << "If you said \"Silence\", then you are correct!\n";
  return 0;
}

//*********END OF PROGRAM****************


