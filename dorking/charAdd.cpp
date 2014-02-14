#include <iostream>
using namespace std;
int main() {
  cout << "give me a letter then an int\n";
  char a = 0;
  int b = 0;
  cin >> a >> b;

  cout << char(a + b) << endl;
  return 0;
}
