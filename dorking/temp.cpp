//Write a program which accept temperature in Farenheit and print it in centigrade.

#include <iostream>
using namespace std;
int main() {
  cout << "What's the temperature in degrees Fahrenheit?\n";
  double f = 0;
  cin >> f;
  double c = (f - 32) * 5 / 9;
  cout << "That's " << c << " degrees centigrade!" << endl;
  return 0;
}

