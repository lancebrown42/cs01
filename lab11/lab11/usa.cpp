/*****************************
 * usa.cpp
 * Author: Lance Brown
 * CS1021-001
 * Laboratory 11/12
 * *********************
 * Description: Takes in a lot of text files about the country as data and outputs an HTML file that represents the
 * 		voting allegiance of each county in a given election.
 * Input: USA-county.txt, *2012.txt
 * Output: usa.html
 * Procedure: Reads in the min and max lat and long for the map, converts it to a positive x,y plane for html use,
 *     then reads in each region (county) and makes the same conversion for each coordinate point. It then reads in the election
 *     results for each region and calculates the "color" of its political affiliation in that year and writes the points and colors in
 *     an SVG function in an html document.
 * Constraints: Only works in the Northwestern hemisphere
 * **************************/
#include <istream>
#include <iostream> 
#include <fstream>
#include <cmath>
#include <string>
#include "BoundingBox.h"
#include <cstdlib>
#include "Polygon.h"
#include <sstream>
#include <stdlib.h>
#include <set>
#include "County.h"
using namespace std;

const double HEIGHT = 500;
const double WIDTH = 1130;

int main() {
	ifstream inFile;
	ofstream outFile;
	inFile.open("USA-county.txt");
	outFile.open("usa.html");
	double minLong = 0;
	double minLat = 0;
	double maxLong = 0;
	double maxLat = 0;
	int regions = 0;
	vector<Polygon> polygons;
	stringstream ss;
	string line;
	//minLong, minLat, maxLong, maxLat, regions
	getline(inFile, line);//minlong/lat
	ss << line;
	ss >> line;
	minLong = atof(line.c_str());
	ss >> line;
	minLat = atof(line.c_str());
	ss.clear();
	getline(inFile, line);//maxlong/lat
	ss << line;
	ss >> line;
	maxLong = atof(line.c_str());
	ss >> line;
	maxLat = atof(line.c_str());
	getline(inFile, line);//number of regions
	regions = atoi(line.c_str());

	 /*cout << "minLong: "<< minLong << "  minLat: " << minLat << endl;
	 cout << "maxLong: "<< maxLong << "  maxLat: " << maxLat << endl;
	 cout << "regions: "<< regions << endl;*/

	BoundingBox box(minLat, minLong, maxLat, maxLong, WIDTH, HEIGHT); //defines width and height in usable coordinates
	outFile << "<html><body>" << endl;
	outFile << "<svg height=\"" << HEIGHT << "\" width=\"" << WIDTH << "\">"
			<< endl;
	for (int regionNum = 0; regionNum < regions; regionNum++) {//makes a polygon of each region

		while (!inFile.eof()) {
			string boundingName = "";
			string regionName = "";
			getline(inFile, line);
			getline(inFile, regionName);
			getline(inFile, boundingName);

			int numPoints;
			getline(inFile, line);
			numPoints = atoi(line.c_str());

			Polygon poly(regionName,boundingName);//polygon
			for (int i = 0; i < numPoints; i++) {
				getline(inFile, line);
				Point p(line);
				poly.addPoint(p);
			}
			polygons.push_back(poly);

		}
	}
	set<string> states;//list of states
	for (unsigned int i = 0; i < polygons.size(); i++){
		states.insert(polygons[i].getBoundingName());//witchcraft
	}
	//cout << states.size() << " states" << endl;
	/*for (set<string>::iterator iti = states.begin(); iti != states.end(); iti++){
		cout << (*iti) << endl;
	}*/
	vector<County> counties;//vector of counties
	//cout << "iterator" << endl;

	  for (set<string>::iterator it = states.begin(); it != states.end(); it++) {
	    if ((*it) == ""){//iterator magic
	    	continue;
	    }
		string fileName = (*it) + "2012.txt";
	    ifstream countyFile;
	    countyFile.open(fileName.c_str());
    	//cout << fileName << endl;
	    string filler;
    	string countyName;
    	string repVote;
    	string demVote;
    	string othVote;
    	getline(countyFile,filler);//because whitespace
	    while (!countyFile.eof()){
	    	//read in county name and votes
	    	getline(countyFile, countyName, ',');
	    	//cout << countyName << endl;
	    	getline(countyFile, repVote, ',');
	    	//cout << repVote << endl;
	    	getline(countyFile, demVote, ',');
	    	//cout << demVote << endl;
	    	getline(countyFile, othVote, ',');
	    	getline(countyFile, filler);
	    	//cout << othVote << endl;
	    	/*getline(countyFile, line);
	    	ss << line;
	    	ss >> countyName >> repVote >> othVote;
	    	ss.clear();*/



	    	string stateName = *it;
	    	int rVote,dVote,oVote;
	    	rVote = atoi(repVote.c_str());
	    	dVote = atoi(demVote.c_str());
	    	oVote = atoi(othVote.c_str());
	    	County county(countyName,stateName,rVote,dVote,oVote);
	    	counties.push_back(county);
	    }

	    // PROCESS THE FILE
	    // read county description
	    // add the county object to the counties vector
	    countyFile.close();
	  }
	for (unsigned int polyNum = 0; polyNum < polygons.size(); polyNum++){
		Polygon p = polygons[polyNum];
		outFile << p.getSVG(box, counties);//write the html file
	}
	outFile << " </svg></body></html>" << endl;
	inFile.close();
	outFile.close();
	return 0;
}
