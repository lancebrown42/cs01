//************************************************
//Title: Calculating windchill for lab02
//Author: Lance Brown
//CS1021-001 Date: January 20, 2014
//Laboratory: 2
//
//************************************************
//
//Description: This program accepts two user input integers of temperature
//    (degrees F) and windspeed (MPH) and outputs the old and new style
//    windchill calculations in both fahrenheit and centigrade
//Input: User input, 2 ints.
//Output: Fahrenheit temperature and old and new style windchills, centigrade
//    temperature and old and new style winchills
//Procedure: The program requests two integer values from the user, temperature
//    and windspeed. Upon input, the program uses the two inputs to calculate
//    the windspeed based on the new formula:
//    (T(wc) = 35.74 + 0.6215T - 35.75(V^0.16) + 0.4275T(V^0.16)
//    and the old formula:
//    T(wc)=.081 x (3.71 x sqrt(V) + 5.81 - 0.25 x V) x (T - 91.4) + 91.4
//    The program outputs the temperature in degrees fahrenheit, and the
//    old and new formulae results in degrees fahrenheit, and then the
//    calculated centrigrade temperature and old and new formulae results in 
//    centigrade.
//*****************Begin Program******************

#include <iostream>
#include <cmath>
using namespace std;

//function to convert fahrenheit to celcius
//f is a double representing degrees fahrenheit
double convert(int f){
  double c = 0; //degrees centigrade, will be output
  c = (f - 32) * (5.0 / 9.0); //convert f to c
  return c;
}

//function to calculate the windchill in degrees f using the new formula  given
//  temp(t) and windspeed(s)
double newWindchill(double t,double s){
  double chill = 0; //represents the windchill, will be output
  chill = 35.74 + 0.6215 * t - 35.75 * pow(s,0.16) + 0.4275 * t * pow(s,0.16);
  return chill;
}

//function to calculate the winchill in degrees f using the old formula given
//  temp(t) and windspeed(s)
double oldWindchill(double t, double s){
  double chill = 0; //represents the windchill, will be output
  chill = 0.081 * (3.71 * sqrt(s) + 5.81 - 0.25 * s) * (t - 91.4) + 91.4;
  return chill;
}

//main, asks for input, calls new and old winchill fxns, prints temp and chills
//    to the screen and then prints it all again in degrees C after calling
//    conversion fxn to calculate it
int main(){
  int T = 0; //user input temp in degrees F
  int S = 0; //user input windspeed in MPH
  cout << "Please enter a temperature in degrees Fahrenheit: ";
  cin >> T;
  cout << "Please enter the wind speed in MPH: ";
  cin >> S;
  
  double C = 0; //temp in degrees C
  double newChill = 0; //new windchill in degrees F
  double oldChill = 0; //old windchill in degrees F
  double newCentChill = 0; //new windchill in degrees C
  double oldCentChill = 0; //old windchill in degrees C
  newChill = round(newWindchill(T,S));
  oldChill = round(oldWindchill(T,S));
  C = convert(T);
  newCentChill = round(convert(newChill));
  oldCentChill = round(convert(oldChill));

  cout << "Temp: " << T << " degrees Fahrenheit:" << endl;
  cout << " new wind chill formula: " << newChill << endl;
  cout << " old wind chill formula: " << oldChill << endl;
  cout << "Temp: " << round(C) << " Centigrade:" << endl;
  cout << " new wind chill formula: " << newCentChill << endl;
  cout << " old wind chill formula: " << oldCentChill << endl;
  return 0;
}

