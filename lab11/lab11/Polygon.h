/*
 * Polygon.h
 *
 *  Created on: Apr 14, 2014
 *      Author: student
 */

#ifndef POLYGON_H_
#define POLYGON_H_
#include "BoundingBox.h"
#include <vector>
#include <string>
using namespace std;

class Polygon{

public:
	Polygon(string region);
	void addPoint(Point p);
	string getSVG(BoundingBox &box);
private:
	vector<Point> points;
	string region;



};

#endif /* POLYGON_H_ */
