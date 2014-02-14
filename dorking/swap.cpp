//Write a program to swap the values of two variables.

#include <iostream>
using namespace std;

int main() {
  double a = 0;
  double b = 0;
  double c = 0;
  cout << "What does A equal?\n";
  cin >> a;
  cout << "what does B equal?\n";
  cin >> b;
  c = a;
  a = b;
  b = c;
  cout << "Wrong, A = " << a << " and B = " << b << endl;
  return 0;
}
