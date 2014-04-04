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

using namespace std;

class BoundingBox {

public:
	BoundingBox();
	BoundingBox(double minLatitude, double minLongitude, double maxLatitude, double maxLongitude);
	BoundingBox(double width, double height);
	virtual ~BoundingBox();
	double getWidth();
	double getHeight();

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
