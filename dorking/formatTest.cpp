//
//
//  Write a program which accepts a character and display its next character.

#include <iostream>
using namespace std;

int main() {
  char c;
  cout << "Give me a character and I'll tell you the next.\n";
  cin >> c;
  cout << "The character after " << c << " is " << (char(int(c) + 1)) << endl;
  return 0;
}

