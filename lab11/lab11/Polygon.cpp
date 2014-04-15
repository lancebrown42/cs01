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


string Polygon::getSVG(BoundingBox &box) {
	stringstream ss;
	ss << "<!-- " << region << " -->" << endl;
	ss << "<polygon points =\"";
	for (int i = 0; i < points.size(); i++){
		Point p = points[i];
		box.translatePoint(p);
		ss << p.getX() << "," << p.getY() << " ";
	}
	ss << "\" style=\"fill:white;stroke:black;stroke-width:1\" />" << endl;
	return ss.str();
}

string Polygon::getRegionName() {
	return region;
}

string Polygon::getBoundingName() {
	return boundingName;
}


