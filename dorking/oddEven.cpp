//Write a program to check whether the given number is even or odd (using ? : ternary operator )

#include <iostream> 
using namespace std;

int main() {
  int a = 0;
  cout << "Give me an integer and I'll tell you if it's odd or even.\n";
  cin >> a;
  ( a % 2 == 0 ) ? cout << "It's even.\n" : cout << "It's odd.\n";
  return 0;
}

