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
#include "BoundingBox.h"
#include <cstdlib>
#include "Polygon.h"
#include <sstream>
#include <stdlib.h>
using namespace std;

const double HEIGHT = 500;
const double WIDTH = 1130;

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
  stringstream ss;
  string line;
  for (int i = 0; i < 6; i++){
	  getline(inFile,line);
	  ss << line;
  }

  ss >> minLong >> minLat >> maxLong >> maxLat >> regions;
  BoundingBox box(minLat,minLong,maxLat,maxLong, WIDTH, HEIGHT);//defines width and height in usable coordinates
  outFile << "<html><body>" << endl;
  outFile << "<svg height=\"" << HEIGHT << "\" width=\"" << WIDTH <<"\">" << endl;
  for (int regionNum = 0; regionNum < regions; regionNum++){
    string token = "";
    string regionName = "";
    while (token != "USA"){
    	 getline(inFile,token);
    	if (token != "USA"){
    		if (regionName == ""){
    			regionName = token;
    		} else {
    			regionName += " ";
    			regionName += token;
    		}
    	}
    }
    int numPoints;
    getline(inFile,line);
    numPoints = atoi(line.c_str());
    Polygon poly(regionName);
    for (int i = 0; i < numPoints; i++) {
    	getline(inFile,line);
    	Point p(line);
    	poly.addPoint(p);
    }
    outFile << poly.getSVG(box);
    
  }
  outFile << " </svg></body></html>" << endl;
  inFile.close();
  outFile.close();
  return 0;
}
