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
bool isEven(int value){ //function to check if values are even

  return value % 2 == 0;
}
bool isOdd(int value) { //checks if value is odd
  return !isEven(value);
}
bool isPrime(int value) {//checks if value is prime
  bool prime = 0;
  int root = (int)round(sqrt(value));//find the square root of value and round up and make an int
  for (int i = 2; i <= root; i++){//starts at 2, goes up to root because afterward it would repeat
    if (value % i == 0){//false condition
      prime = 0;
      break;
    } else {//true condition
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
bool isVampire(int num){//checks if value is vampire
  
  stringstream ss;
  ss << num;
  string numS = ss.str();
  int size = numS.size();
  if (size == 4){//true condition
    int characters[size];
    for (int i = 0; i < size; i++) {//convert chars to ints
      characters[i] = numS[i] - '0';
    }
    
    for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++){
        for (int k = 0; k < size; k++){
          for (int l = 0; l < size; l++){//so nested
            if (i == j || i == k || i == l || j == k || j == l || k == l){//you cant use each digit more than once
              continue;
            }
            
            int fangOne;
            int fangTwo;
            ss << characters[i] << characters[j] << endl;//digits for first fang
                                                         //that fucking endl....
            ss >> fangOne;
            ss << characters[k] << characters[l] << endl;//digits for second fang
            ss >> fangTwo;
            
            
            if (fangOne * fangTwo == num){//check if vamp
              
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
  int count = 0;//total number of values read
  int value = 0;//the value read in
  int evenCount = 0;//total number of evens found
  int oddCount = 0;//total number of odds found
  int primeCount = 0;//total number of primes found
  int size = 10;//the top (size) numbers of the set
  int biggest[size];//array of largest values
  int vampCount = 0;//total number of vampires found
  
  stringstream ss;
  for (int i; i < size; i++){//initialize the large number array to zero
    biggest[i] = 0;
  }
  ofstream evenOutFile;//start opening files
  evenOutFile.open ("evens.txt");
  ofstream oddOutFile;
  oddOutFile.open ("odds.txt");
  ofstream primeOutFile;
  primeOutFile.open ("primes.txt");
  ofstream vampOutFile;
  vampOutFile.open ("vampires.txt");
  inFile >> value;
  while (!inFile.eof() && !(value == -1)){//break at end of file or at sentinal value
    count++;
    bool prime = 0;
    if (isEven(value)){//check if value is even
      evenCount++;
      evenOutFile << value << endl;
    }
    else if (isOdd(value)){//check if it is odd
      oddCount++;
      oddOutFile << value << endl;
      if (isPrime(value)){//if value is odd, check if it is prime
        primeCount++;
        primeOutFile << value << endl;
        prime = true;
      }
      
    }
      addToLongest(biggest, size, value);//see if value can be added to the "biggest" list
      if (!prime){
        if (isVampire(value)){//check if it's vampire if it isnt prime (no vamp can be prime)
          vampCount++;
          vampOutFile << value << endl;
        }
      }
    
      
    inFile >> value;//read the next value
  }
  inFile.close();//start closing things
  evenOutFile.close();
  oddOutFile.close();
  primeOutFile.close();
  vampOutFile.close();
  cout << "Numbers read in: " << count << endl;//print it all out
  cout << "Even numbers: " << evenCount << endl;
  cout << "Odd numbers: " << oddCount << endl;
  cout << "Prime numbers: " << primeCount << endl;
  cout << "Vampire numbers: " << vampCount << endl;
  cout << "Ten largest numbers:" << endl;
  for (int i = 0; i < size; i++){
    cout << "  - " <<  biggest[i] << endl;
  }
}
