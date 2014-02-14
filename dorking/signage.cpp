//Write a program to check whether the given number is positive or negative (using ? : ternary operator )
//

#include <iostream>
using namespace std;

int main() {
  int a = 0;
  cout << "Give me an integer, and I'll tell you if it's positive or negative.\n" ;
  cin >> a;
  (a >= 0) ? cout << "I'm positive it's positive.\n" : cout << "It's not positive.\n";
  return 0;
}



