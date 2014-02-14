//Write a program which input three numbers and display the largest number using ternary operator.

#include <iostream>
using namespace std;

int main(){
  int a, b , c;
  cout << "give me 3 integers\n" ;
  cin >> a >> b >> c ;
  (a < b && b < c) ? cout << a << endl << b << endl << c << endl : (b < a && a < c) ? cout << b << endl << a << endl << c << endl
	  : (c < a && a < b) ? cout << c << endl << a << endl << b << endl : (c < b && b < a) ? cout << c << endl << b << endl
	  << a << endl : cout << b << endl << c << endl << a << endl;
  return 0;
}

