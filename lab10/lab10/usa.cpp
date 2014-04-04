/*****************************
 * usa.cpp
 * Author: Lance Brown
 * CS1021-001
 * Laboratory 10
 * *********************
 * Description: Takes input from a text file listing coordinates for state boundaries and outputs an html file which maps
 *     the country as a vector image.
 * Input: USA.txt
 * Output: usa.html
 * Procedure: Reads in the min and max lat and long for the map, converts it to a positive x,y plane for html use,
 *     then reads in each region and makes the same conversion for each coordinate point and writes the points in
 *     an SVG function in an html document. Same as in Lab 9, only using the BoundingBox and Point classes.
 * Constraints: Only works in the Northwestern hemisphere
 * **************************/

#include <iostream> 
#include <fstream>
#include <cmath>
#include <string>
#include <BoundingBox.h>
#include <Point.h>
using namespace std;


void draw(ifstream &inFile, ofstream &outFile){
  string subregion;
  string region;
  string multiword;
  int points = 0;
  double x = 0;
  double y = 0;
    inFile >> subregion;
    if (subregion == "District"){
      inFile >> multiword >> multiword; //keeps dc, new-anything and north,south,west whatever from messing it all up
    }else if (subregion == "New" || subregion == "North" || subregion == "South" || subregion == "West" || subregion == "Rhode"){
      inFile >> multiword;
    }
    inFile >> region;
    inFile >> points;
  outFile << "<polygon points=\"";
  for (int i = 0; i < points; i++){
    inFile >> x >> y;
    Point point = Point(x,y);//turns it into an object
    point.translatePoint(point);//converts to usable coordinates
    outFile << point.getX() << "," << point.getY();
    if (i < points - 1){
      outFile << " ";
    }
  }
  outFile << "\" style=\"fill:none;stroke:black;stroke-width:1\" /> ";


}
int main(){
  ifstream inFile;
  ofstream outFile;
  inFile.open("USA.txt");
  outFile.open("usa.html");
  double minLong = 0;
  double minLat = 0;
  double maxLong = 0;
  double maxLat = 0;
  int regions = 0;
  inFile >> minLong >> minLat >> maxLong >> maxLat >> regions;
  BoundingBox box(minLat,minLong,maxLat,maxLong);//defines width and height in usable coordinates
  double width = box.getWidth();
  double height = box.getHeight();
  outFile << "<svg height=\"" << height << "\" width=\"" << width <<"\">" << endl;
  for (int i = 0; i < regions; i++){
    draw(inFile, outFile);
    
  }
  outFile << " </svg>" ;
  inFile.close();
  outFile.close();
  return 0;
}
