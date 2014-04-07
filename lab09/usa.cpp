/*****************************
 * Title: USA USA USA USA USA USA
 * Author: Lance Brown
 * CS1021-001 March 24, 2014
 * Laboratory 9
 **************************
 * Description: Takes input from a text file listing coordinates for state boundaries and outputs an html file which maps
 *     the country as a vector image.
 * Input: USA.txt
 * Output: usa.html
 * Procedure: Reads in the min and max lat and long for the map, converts it to a positive x,y plane for html use,
 *     then reads in each region and makes the same conversion for each coordinate point and writes the points in
 *     an SVG function in an html document.
 * Constraints: Only works in the Northwestern hemisphere
 *
 *
 * **************************/

#include <iostream> 
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

double convert(double x, double min){
  x -= min;
  x *= 20;
  return abs(x);
}
void draw(ifstream &inFile, ofstream &outFile, double minLong, double maxLat){
  string subregion;
  string region;
<<<<<<< HEAD
  string multiword;//keeps washington dc, new-anything from ballsing it up
=======
  string multiword;
>>>>>>> e550844291d85e039d1b3e21f75f52dac067722e
  int points = 0;
  double x = 0;
  double y = 0;
    inFile >> subregion;
    if (subregion == "District"){
      inFile >> multiword >> multiword;
    }else if (subregion == "New" || subregion == "North" || subregion == "South" || subregion == "West" || subregion == "Rhode"){
      inFile >> multiword;
    }
    inFile >> region;
    inFile >> points;
  outFile << "<polygon points=\"";
  for (int i = 0; i < points; i++){
    inFile >> x >> y;
    x = convert(x,minLong);
    y = convert(maxLat,y);
    outFile << x << "," << y;
    if (i < points - 1){
      outFile << " ";
    }
  }
  outFile << "\" style=\"fill:lime;stroke:black;stroke-width:1\" /> ";


}
int main(){
  ifstream inFile;
  ofstream outFile;
  inFile.open("USA.txt");
  outFile.open("usa.html");
  double minLong = 0;//minimum longitude 
  double minLat = 0;//minimum latitude
  double maxLong = 0;//max longitude
  double maxLat = 0;// max latitude
  int regions = 0; //number of "states" or regions to be read
  inFile >> minLong >> minLat >> maxLong >> maxLat >> regions;
<<<<<<< HEAD
  double width = 0;//canvas width converted
  double height = 0;//canvas height converted
=======
  double width = 0;
  double height = 0;
>>>>>>> e550844291d85e039d1b3e21f75f52dac067722e
  width = convert(maxLong,minLong);
  height = convert(maxLat,minLat);
  outFile << "<svg height=\"" << height << "\" width=\"" << width <<"\">" << endl;
  for (int i = 0; i < regions; i++){
    draw(inFile, outFile, minLong, maxLat);
    
  }
  outFile << " </svg>" ;
  inFile.close();
  outFile.close();
  return 0;
}
