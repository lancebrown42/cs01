//*********************************************
//
// Title: Fuel efficiency calculator: Lab 04
// Author: Lance Brown
// CS1021-001  February 3, 2014
// Lab: 4
//
// ********************************************
//
// Description: The program calculates a users mileage, fuel and cost efficiency for a trip based
//     on user input values. It asks for initial odometer reading, amount of fuel added, new 
//     odometer reading, and total cost of fill-up, and outputs the distance traveled, miles
//     per gallon, cost per gallon, and miles per dollar. It then loops and asks again until 
//     user inputs an end condition. Upon an end condition, the total distance, mpg, $pg and
//     mp$ is printed and the program terminates.
//
// Input: user provided odometer reading, number of gallons, cost of transaction, and new
//     odometer reading
//
// Output: distance travelled, miles per gallon, cost per gallon, and miles per dollar for
//     each fillup
//
// Procedure: the program asks the user for the intial odometer reading. It enters a while loop,
//     which is controlled by a bool set to false by default. It asks the user for gallons input,
//     and checks the signage with an if statement. If the value is positive, it continues to ask
//     for cost of transaction, and new odo reading. It then calculates MPG, dollars per gallon,
//     and miles per dollar and prints the results to the screen. The distance, gallons and cost
//     are added to variables calculating the totals for the trip. Loop repeats. If the if value
//     is negative, the program calculates the total mileage, mpg, cost per gallon, and miles
//     per dollar for the trip and prints them to the screen. The end condition bool is set to
//     true, and the while loop ends, terminating the program with a farewell print.
//
// Constraints: odometer readings must always be an int, all other inputs are doubles. Negative
//     gallons terminates the program.
//
// *************Begin Program*****************

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  cout << fixed;
  cout << "This program will compute an automobile's gas mileage statistics." << endl;
  int odometer = 0; //variable to track odometer readings
  int twodometer = 0; //variable allowing for comparison between new and old odo values
  int distance = 0; //difference between the odometer reading
  int totalDistance = 0; //tracks total distance
  double gallons = 0; //tracks gallons, negative value ends program
  double totalGallons = 0; //tracks total gallons
  double cost = 0; //tracks total cost of fillup
  double totalCost = 0; // tracks total cost of trip
  double mpg = 0; //miles per gallon
  double price = 0; //price per gallon
  double mileCost = 0; //cost per mile
  double finalMpg = 0; //used in final instance
  double finalPrice = 0;
  double finalMileCost = 0;
  int fillUp = 1; //tracks which fillup you're on
  bool end = false; //bool to end loop if conditions are met

  
  cout << "Enter initial odometer reading: ";
  cin >> odometer;
  while (end == false) {
    cout << endl << "Fill-up #" << fillUp << endl;
    cout << "Enter gallons used (negative number to end): ";
    cin >> gallons;
    if (gallons >= 0) {
      cout << "Enter price paid: $";
      cin >> cost;
      cout << "Enter new odometer reading: ";
      cin >> twodometer;
      distance = twodometer - odometer;
      totalDistance += distance;
      totalGallons += gallons;
      totalCost += cost;
      mpg = (double) distance / gallons;
      price = cost / gallons;
      mileCost = distance / cost;
      
      cout << endl << "Stats for fill-up #" << fillUp << ":" << endl;
      cout << " * " << distance << " miles" << endl;
      cout << " * " << setprecision(1) << mpg << " miles per gallon" << endl;
      cout << " * $" << setprecision(2) << price << " per gallon" << endl;
      cout << " * " << setprecision(2) << mileCost << " miles per dollar" << endl;
      odometer = twodometer;
      fillUp++;
    } else {
      finalMpg = (double) totalDistance / totalGallons;
      finalPrice = totalCost / totalGallons;
      finalMileCost = totalDistance / totalCost;

      cout << endl << "Final statistics: After " << fillUp - 1 << " fill-ups." << endl;
      cout << " * " << totalDistance << " miles" << endl;
      cout << " * " << setprecision(1) << finalMpg << " miles per gallon" << endl;
      cout << " * $" << setprecision(2) << finalPrice << " per gallon" << endl;
      cout << " * " << setprecision (2) << finalMileCost << " miles per dollar" << endl;
      end = true;
    }
  }
  cout << endl << "Goodbye!" << endl;
  





  return 0;

}
