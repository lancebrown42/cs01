// Lab 01 trial stuff
// beginner shit

#include <iostream>
using namespace std;

// function that gets an integer from the user
int getNumber(){
  int number; // hold user input integer
              // ask user for and store integer
  cout << "Enter an integer: ";
  cin >> number;
  return number; // return integer entered by user
} // end function get number
	

int main(){
  int number = getNumber(); // get integer from user
  if ( number <= 0 ) {
    return 0;
  } else {
    // display numbers from one to user input number
    for ( int i = 1; i <= number; i++ ) {
      cout << i << endl;
    }
  }
  return 0;

}
