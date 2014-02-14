#include <iostream>
#include <cctype>
using namespace std;
int main() {
  char i;
  cout << "give me a lower case character: ";
  cin >> i;
 // islower(i) ? toupper(i) : cout << "follow the instructions\n";
  cout << char(toupper(i)) << endl;
  return 0;

