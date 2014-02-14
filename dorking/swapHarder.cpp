//Write a program to swap value of two variables without using third variable. 

#include <iostream>
using namespace std;

int main() {
  int a = 0;
  int b = 0;
  cout << "Give an int\n";
  cin >> a;
  cout << "and another\n";
  cin >> b;
  a = a + b;
  b = a - b;
  a = a - b;
  cout << "the first is now " << a << " and the other: " << b << endl;
  return 0;
}
