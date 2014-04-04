/*
 * BoundingBox.h
 *
 *  Created on: Apr 2, 2014
 *      Author: lance
 */

#ifndef BOUNDINGBOX_H_
#define BOUNDINGBOX_H_

#include <iostream>
#include <string>
#include<Point.h>

using namespace std;

class BoundingBox {

public:
	BoundingBox();
	BoundingBox(double minLatitude, double minLongitude, double maxLatitude, double maxLongitude);
	BoundingBox(Point &point);
	virtual ~BoundingBox();
	double getWidth();
	double getHeight();

private:
	double minLongitude;
private:
	double minLatitude;
private:
	double maxLongitude;
private:
	double maxLatitude;
private:
	double width;
private:
	double height;
private:
	double translateLatitude(double latitude);
private:
	double translateLongitude(double longitude);

};


#endif /* BOUNDINGBOX_H_ */
