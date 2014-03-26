//lets try this again

#include <iostream>
#include <fstream> 
#include <cmath>
#include <string>

using namespace std;

double convert(double x /*value to be converted*/, double min /*minimum lat or long irl degrees*/){
  x = abs(x);
  x += abs(min);
  x *= 7;
  return x;
}
void draw(ifstream &inFile, ofstream &outFile){
  double minLong = 0;//y
  double minLat = 0;//x
  double maxLong = 0;//y
  double maxLat = 0;//x
  inFile >> minLat >> minLong;
  inFile >> maxLat >> maxLong;
  double width = convert(maxLat, minLat);
  double height = convert(maxLong, minLong);




}


int main(){
  ifstream inFile;
  ofstream outFile;
  inFile.open("USA.txt");
  outFile.open("usa.html");
  draw(inFile, outFile);



}


