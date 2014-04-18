/*
 * BoundingBox.h
 *
 *  Created on: Apr 2, 2014
 *      Author: Lance Brown
 */

#ifndef BOUNDINGBOX_H_
#define BOUNDINGBOX_H_

#include "Point.h"

using namespace std;

class BoundingBox {

public:
	BoundingBox(double minLatitude, double minLongitude, double maxLatitude, double maxLongitude, double width, double height);
	void translatePoint(Point &point);
	BoundingBox(Point &point);

private:
	double minLongitude;
	double minLatitude;
	double maxLongitude;
	double maxLatitude;
	double width;
	double height;
	double translateLatitude(double latitude);
	double translateLongitude(double longitude);

};


#endif /* BOUNDINGBOX_H_ */
