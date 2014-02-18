/*******************************************
 *
 * Title: Performing tedious operations on lots of integers.
 * 
 * Author: Lance Brown
 *
 * CS1021-001 February 17, 2014
 *
 * Lab 6
 *
 * ******************************************
 *
 * Description: The program reads in a number of integers from an input text file. It then checks each
 *     value to determine if it is even or odd, prime, or one of the 10 largest numbers. The results of
 *     all those tests are printed to the screen, and the numbers meeting the specified criteria are 
 *     output to a corresponding text file.
 *
 * Input: Input file "input.txt"
 *
 * Output: Results of each test
 *
 * Procedure: The program reads in the input file, and checks first if the value is even using modulus
 *     operator. If it is even, the number is added to "evens.txt" and increments the even count. If it 
 *     is not even, it is marked as odd and output to the "odds.txt" file and increments the odd count.
 *     If the value is odd, check if it is prime by taking the modulous of the value and every int up to
 *     the int closest to the square root of the value. If prime, the number is added to "primes.txt" and 
 *     the prime count is incremented. The number is then checked against the largest 10 previous numbers,
 *     and if it is larger than any, replaces that number in the array and the other number is checked the
 *     same way. At the end, the count of evens, odds, primes and the 10 largest numbers are displayed.
 *
 * Constraints: input file must contain only integers. -1 is a sentinel value.
 *
 *************************Begin Program******
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;
bool isEven(int value){

  return value % 2 == 0;
}
bool isOdd(int value) {
  return !isEven(value);
}
bool isPrime(int value) {
  bool prime = 0;
  int root = (int)round(sqrt(value));
  for (int i = 2; i <= root; i++){
    if (value % i == 0){
      prime = 0;
      break;
    } else {
      prime = 1;
    }
  }
  return prime;
}
void addToLongest(int biggest[], int size, int value) {
  int bumped = 0;//placeholder for the number knocked out of array
  for (int i = 0; i < size; i++){ 
    if (value > biggest[i]){
      bumped = biggest[i];//knock out lower number
      biggest[i] = value;//replace with larger number
      addToLongest(biggest, size, bumped);
      break;

    }
  }

}
bool isVampire(int num){
  
  stringstream ss;
  stringstream concatOne;
  stringstream concatTwo;
  ss << num;
  string numS = ss.str();
  int size = numS.size();
  if (size == 4){//true condition
    int characters[size];
    for (int i = 0; i < size; i++) {
      characters[i] = numS[i] - '0';
    }
    
    for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++){
        for (int k = 0; k < size; k++){
          for (int l = 0; l < size; l++){
            if (i == j || i == k || i == l || j == k || j == l || k == l){
              continue;
            }
            int fangOne;
            int fangTwo;
            int firstCharacter = characters[i];
            int secondCharacter = characters[j];
            int thirdCharacter = characters[k];
            int fourthCharacter = characters[l];
            concatOne << firstCharacter << secondCharacter;
            concatOne >> fangOne;
            concatTwo << thirdCharacter << fourthCharacter;
            concatTwo >> fangTwo;
            
            
            cout <<"num: " << num << setw(5) << " fang one: " << fangOne << setw(5) << " Fang two: " << fangTwo << endl;
           // cout << "i: " << i << setw(5) << " | " << setw(5) << "j: " << j << setw(5) << " | " << setw(5) << "k: " << k << setw(5) << " | " << setw(5) << "l: " << l << endl;
            cout << "first character: " << firstCharacter << setw(5) << " second character: " << secondCharacter << setw(5) << " third: " << thirdCharacter << setw(5) << " fourth: "  << fourthCharacter << endl;
            if (fangOne * fangTwo == num){
              
              return true;
            }
            
          }
        }
      }
    }
    
  }
return false;

}


int main() {
  ifstream inFile;
  inFile.open ("input.txt");
  int count = 0;
  int value = 0;
  int evenCount = 0;
  int oddCount = 0;
  int primeCount = 0;
  int size = 10;
  int biggest[size];
  int vampCount = 0;
  
  stringstream ss;
  for (int i; i < size; i++){
    biggest[i] = 0;
  }
  ofstream evenOutFile;
  evenOutFile.open ("evens.txt");
  ofstream oddOutFile;
  oddOutFile.open ("odds.txt");
  ofstream primeOutFile;
  primeOutFile.open ("primes.txt");
  ofstream vampOutFile;
  vampOutFile.open ("vampires.txt");
  inFile >> value;
  while (!inFile.eof() && !(value == -1)){
    count++;
    bool prime = 0;
    if (isEven(value)){
      evenCount++;
      evenOutFile << value << endl;
    }
    else if (isOdd(value)){
      oddCount++;
      oddOutFile << value << endl;
      if (isPrime(value)){
        primeCount++;
        primeOutFile << value << endl;
        prime = true;
      }
      
    }
      addToLongest(biggest, size, value);
      if (!prime){
        if (isVampire(value)){
          vampCount++;
          vampOutFile << value << endl;
        }
      }
    
      
    inFile >> value;
  }
  inFile.close();
  evenOutFile.close();
  oddOutFile.close();
  primeOutFile.close();
  vampOutFile.close();
  cout << "Numbers read in: " << count << endl;
  cout << "Even numbers: " << evenCount << endl;
  cout << "Odd numbers: " << oddCount << endl;
  cout << "Prime numbers: " << primeCount << endl;
  cout << "Vampire numbers: " << vampCount << endl;
  cout << "Ten largest numbers:" << endl;
  for (int i = 0; i < size; i++){
    cout << "  - " <<  biggest[i] << endl;
  }
}
