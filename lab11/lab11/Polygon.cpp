/*
 * Polygon.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: student
 */

#include "Polygon.h"
#include <sstream>


Polygon::Polygon(string region, string boundingName) {
	this->region = region;
	this->boundingName = boundingName;
}



void Polygon::addPoint(Point p) {
	points.push_back(p);
}


string Polygon::getSVG(BoundingBox &box, vector<County> &counties) {
	stringstream ss;
	ss << "<!-- " << region << " -->" << endl;
	ss << "<polygon points =\"";
	for (int i = 0; i < points.size(); i++){
		Point p = points[i];
		box.translatePoint(p);
		ss << p.getX() << "," << p.getY() << " ";
	}
	int rVote, dVote, oVote;
	for (int i = 0; i < counties.size(); i++){

		if (region == counties[i].getCountyName()){
			rVote = counties[i].getRVote();
			dVote = counties[i].getDVote();
			oVote = counties[i].getOVote();
			break;
		} else{
			continue;
		}
	}
	int allVotes;
	allVotes = rVote + dVote + oVote;
	double red, green, blue;
	red = rVote / allVotes;
	blue = dVote / allVotes;
	green = oVote / allVotes;
	ss << "\" style=\"fill:" << red << "," << green << "," << blue << ";stroke:black;stroke-width:1\" />" << endl;
	return ss.str();
}

string Polygon::getRegionName() {
	return region;
}

string Polygon::getBoundingName() {
	return boundingName;
}


