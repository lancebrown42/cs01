/*
 * Polygon.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: student
 */

#include "Polygon.h"
#include <sstream>
#include <iostream>


Polygon::Polygon(string region, string boundingName) {//default constructor
	this->region = region;
	this->boundingName = boundingName;
}



void Polygon::addPoint(Point p) {//adds a point ot the polygon
	points.push_back(p);
}


string Polygon::getSVG(BoundingBox &box, vector<County> &counties) {//writes the SVG html stuff to the .html file
																	//calculates votes and color of each county
	stringstream ss;
	ss << "<!-- " << region << " -->" << endl;
	ss << "<polygon points =\"";
	for (unsigned int i = 0; i < points.size(); i++){
		Point p = points[i];
		box.translatePoint(p);
		ss << p.getX() << "," << p.getY() << " ";
	}
	int rVote = 0;
	int dVote = 0;
	int oVote = 0;
	for (unsigned int i = 0; i < counties.size(); i++){
		//cout << "region: " << region << "   " << "countyName: "<< counties[i].getCountyName() << endl;
		//while (boundingName == counties[i].getStateName()){


			if (region == counties[i].getCountyName() || region == counties[i].getCountyName() + " Parish"){
				rVote = counties[i].getRVote();
				dVote = counties[i].getDVote();
				oVote = counties[i].getOVote();
				break;
			} else{
				continue;
			}
		//}
	}
	double allVotes = 0;
	allVotes = rVote + dVote + oVote;
	//cout << "r: " << rVote << "     d: " << dVote << "     o: " << oVote << endl;
	double redDec = 0;
	double blueDec = 0;
	double greenDec = 0;
	int red  = 0;
	int green = 0;
	int blue = 0;
	redDec = rVote / allVotes;
	blueDec = dVote / allVotes;
	greenDec = oVote / allVotes;
	red = redDec * 255;//because the first number is between 0 and 1, have to get between 0 and 255
	green = greenDec * 255;
	blue = blueDec * 255;
	ss << "\" style=\"fill:rgb(" << red << "," << green << "," << blue << ");stroke:black;stroke-width:1\" />" << endl;
	return ss.str();
}

string Polygon::getRegionName() {
	return region;
}

string Polygon::getBoundingName() {
	return boundingName;
}


