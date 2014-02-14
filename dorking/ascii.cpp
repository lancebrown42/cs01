//Write a program which accepts a character and display its ASCII value.

#include <iostream>
using namespace std;

int main() {
  char c;
  cout << "Type a character and hit enter to display its ASCII value." << endl;
  cin >> c;
  cout << "The ASCII equivalent is : " << (int)c << endl;
  return 0;
}
