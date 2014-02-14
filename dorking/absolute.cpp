//Find the absolute value of a number entered by the user.
#include <iostream>
using namespace std;
int main() {
  cout << "Give me an integer.\n";
  int a;
  cin >> a;
  (a > 0) ? cout << a << endl : cout << -a << endl;
  return 0;
}
