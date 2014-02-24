//*************************************8
// Title: Sorting products by price and rating
// Author: Lance Brown
// CS1021-001 February 24, 2014
// Lab: 7
//
// ************************************
//
// Description: The program takes input from a text file of products, reviews, and prices.
//     The products are all printed to the screen in the order they appear in the input file.
//     The user is prompted to input a 'p' 'r' or 'q' which will then sort the products by
//     price, rating or quit the program. The program sorts by price using the bubble sort
//     and sorts by review using selection sort.
//
// Input: products.txt, user input char
//
// Output: products listed in requested order
//
// Procedure: The program reads in each line from the input file and assigns each value to
//      the appropriate position in an array of custom (struct) type. It then prints out
//      the contents of the array and asks user for input on how to sort it. If the user 
//      chooses a price sort, it calls a bubble sort function and prints the results,
//      prompting for another input choice. If review sort is chosen, it calls a selection
//      sort function that sorts the products by review in descending order. The user can
//      quit by entering 'q' when prompted.
//
// Constraints: input file must be named "products.txt" and begin with an iteger denoting
//     how many products are to be read in.
//
// ***********************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iomanip>
using namespace std;

struct Product{ //custom type for products
  string name;
  float price;
  float reviews;
};


void printProduct(Product &p){ //will print out one product's information
  cout << " " << setprecision(2) << fixed << p.price << " " << setprecision(1) << fixed << p.reviews << " stars: " << p.name << endl;
}
void printSorted(Product p[], int size){//will print all products sorted however they're sorted
  for (int i = 0; i < size; i++){
    printProduct(p[i]);
  }
}

void ratingSort(Product p[], int size){//this is a selection sort
                                       //sorted by review
  for (int fill = 0; fill < size -1; fill ++){
    int posMin = fill;
    for (int next = fill + 1; next < size; next ++){
      if (p[next].reviews > p[posMin].reviews){//have to do > rather than < for descending order
        posMin = next;
      }
    }
    if (posMin != fill) {
      Product tmp = p[fill];
      p[fill] = p[posMin];
      p[posMin] = tmp;
    }
  }
  printSorted(p,size);


}
void priceSort(Product p[], int size){//this is a bubble sort
                                      //sorted by price
  bool sorted = false;
  int maxId = size - 1;
  Product tmp;
  while (!sorted) {
    sorted = true;

    for (int i = 0; i < maxId; i++){
      if (p[i].price > p[i+1].price){
       sorted = false;
       tmp = p[i];
       p[i] = p[i+1];
       p[i+1] = tmp;
      }
    }
    maxId--;
  }
  printSorted(p,size);
}


int main() {
  ifstream inFile;
  inFile.open("products.txt");
  string line;
  getline(inFile,line);
  const int SIZE = atoi(line.c_str());//how many products will be read, given by first value in file
  Product myProducts[SIZE];
  for (int i = 0; i < SIZE; i++){//read in each line and give it a home in the array
    getline(inFile,line);
    myProducts[i].name = line;
    getline(inFile,line);
    myProducts[i].price = atof(line.c_str());
    getline(inFile, line);
    myProducts[i].reviews = atof(line.c_str()); 
  }
  char sortType = 0;//will be replaced by user input
  cout << "Popular tablets:" << endl;
  printSorted(myProducts,SIZE);//list the products unsorted
  while (sortType != 'q'){
    cout << "Sort by price ('p'), review ('r'), or quit ('q')? ";
    cin >> sortType;
    check:
    if (sortType == 'q'){//quit condition
     break;
    } else if (sortType == 'p'){//sort by price
        cout << endl << "Sorted by price:" << endl;
        priceSort(myProducts,SIZE);
    } else if (sortType == 'r'){//sort by review
        cout << endl << "Sorted by rating:" << endl;
        ratingSort(myProducts,SIZE);
    } else {//invalid input
        cout << "Please enter 'p', 'r', or 'q': ";
        cin >> sortType;
        goto check;
    }
  }
     

}
