/*
 * Polygon.h
 *
 *  Created on: Apr 14, 2014
 *      Author: Lance Brown
 */

#ifndef POLYGON_H_
#define POLYGON_H_
#include "BoundingBox.h"
#include <vector>
#include <string>
#include "County.h"
using namespace std;

class Polygon{

public:
	Polygon(string region, string boundingName);
	void addPoint(Point p);
	string getSVG(BoundingBox &box, vector<County> &counties);
	string getRegionName();
	string getBoundingName();
private:
	vector<Point> points;
	string region;
	string boundingName;



};

#endif /* POLYGON_H_ */
