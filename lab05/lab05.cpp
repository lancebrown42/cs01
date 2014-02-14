//*************************************************
//
// Title:
// Author:
// CS1021-001 February 10, 2014
// Lab 05
//
// *************************************************
//
// Description:
//
// Input:
//
// Output:
//
// Procedure:
//
// Constraints:
//
// *****************Begin Program********************
//
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int rollDie() {
  return rand() % 6 + 1;
}

bool playOneGame(int point, int roll, int attempt) {
  bool win = 0;
  while (point != roll && attempt < 3) {
    roll = rollDie();
    cout << "Roll #" << ++attempt << " is " << roll << endl;
  }
  if (point == roll){
    win = 1;
  }else {
    win = 0;}
  return win;
}

void display(int balance) {
  cout << "Account balance $" << balance << endl;
}

int main() {
  int balance = 100;//total account balance, goes up or down with win and loss
  int wager = -1;//player bet, initialiazed to -1 because 0 is exit condition
  int point = 0; //player guess
  int attempt = 0; //which roll it is per round
  int roll = 0; //value of roll
  int winCount = 0; //how many wins the player has
  bool win = 0; //if the game was won or lost

  srand (time(NULL)); //seed the random number
  while (balance > 0) {
    display(balance);
    cout << "Enter wager (0 to exit): ";
    cin >> wager;
    if (wager == 0) { //check for exit value
      break;
    }else if( wager > balance || wager < 0) { //check for invalid input
      while (wager > balance || wager < 0){
      cout << "Error: You must enter a wager between $1 and $" << balance << " (type 0 to exit): ";
      cin >> wager; //accept a new input
      }
    
      if (wager == 0) { //check for exit value
        break;
      }
    }
    
    cout << endl << "Enter your point value (1-6): ";
    cin >> point;
    while (!(point < 6 && point > 0)) { //check for invalid input
      cout << "Error: Enter your point value, must be between 1 and 6: ";
      cin >> point;
    }
    win = playOneGame(point, roll, attempt); //play the game, and return win or loss
    if (win){
      cout << " ** You win! **" << endl;
      winCount++;
      balance += wager;
    }else {
      cout << " ** You Lose **" << endl;
      balance -= wager;
    }
  }
  if (balance == 0) { //if bankrupt
    cout << "Game over, you are out of money!" << endl;
  }
//end result
  cout << "Your final account balance is $" << balance << endl;

}
