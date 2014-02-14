//Write a program which accept principle, rate and time from user and print the simple interest.

#include <iostream>
using namespace std;

int main() {
  cout << "Principle: ";
  double p = 0;
  cin >> p;
  cout << "Rate: ";
  double r = 0;
  cin >> r;
  cout << "Time: ";
  double t = 0;
  cin >> t;
  double i = p * r * t;
  cout << "You're paying " << i << " in interest." << endl;
  return 0;
}
