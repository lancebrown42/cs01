//**********************************************
//
// Title: Problem 4: Change for a dollar game 
// Author: Lance Brown
// CS1021-001 Date: January 27, 2014
// Laboratory 03
//
// *********************************************
//
// Description: Program asks user for a number of quarters, dimes, nickels, and
//   pennies. The sum of the coins is calculated, and if it equals exactly one
//   dollar, the player wins. If not, they lose.
//
// Input: 4 user defined integers representing the number of each denomination
//   of coin.
//
// Output: The result of the game, which can be a win, loss, or warning about
//   playing within the bounds of the game.
//
// Procedure: The program asks for a quantity of each type of coin, upon input
//   it checks to make sure the input is within the rules of the game, namely
//   that there is at least one of each coin and no more than a dollar's worth
//   of each. It uses a separate boolean function to check whether or not the 
//   user is following the rules. The value of the coins is then added and the 
//   sum is compared to the winning conditions. Either a winning or losing
//   statement is printed.
//
// Constraints: Inputs must be integers, the value of a single coin type cannot
//  be zero or exceed one dollar.
//
// ***************Begin Program*****************
//
#include <iostream>
using namespace std;

//function to weed out cheaters
bool cheatCheck(int coin){
  if (coin < 1 || coin >= 100){
    cout << "You must have at least 1 of each coin, and less than 1 dollar of that coin type.\n";
    return 1;
  } else {
    return 0; 
  }
}

int main() {
  int quarter = 0;
  int dime = 0;
  int nickel = 0;
  int penny = 0;
  int value = 0; //summation of value of all coins

  cout << "Welcome to the change-for-a-dollar game!" << endl;
  cout << "Enter the number of quarters you have: ";
  cin >> quarter;
  quarter = 25 * quarter; //change quantity of coins into value
  if (cheatCheck(quarter) == 1){ //check for cheating
    goto QUIT; //end game if cheating
  }
  cout << "Enter the number of dimes you have: ";
  cin >> dime;
  dime = 10 * dime; //change quatity to value
  if (cheatCheck(dime) == 1){ //check for cheating
    goto QUIT; //end if cheating
  }
  cout << "Enter the number of nickels you have: ";
  cin >> nickel;
  nickel = 5 * nickel; //change to value
  if (cheatCheck(nickel) == 1){ //cheat check
    goto QUIT; //end if cheating
  }
  cout << "Enter the number of pennies you have: ";
  cin >> penny; //dont need to convert to value, since each is worth 1
  if (cheatCheck(penny) == 1) { //check for cheating
    goto QUIT; //end if cheating
  }

  //add coins  
  value = quarter + dime + nickel + penny;
  //check if win or loss

    if (value == 100){
      cout << "You win! The total adds up to 1 dollar!\n"; //winning
    } else if (value < 100){
      cout << "You lose, your total of " << value << " cents is less than 1 dollar.\n"; //too small
    } else if (value > 100){
      cout << "You lose, your total of " << value << " cents is greater than 1 dollar.\n"; //too big
    }
goto QUIT;

QUIT: return 0;
}
