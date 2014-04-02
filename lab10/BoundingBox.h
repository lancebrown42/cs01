/*
 * BoundingBox.h
 *
 *  Created on: Mar 31, 2014
 *      Author: student
 */

#ifndef BOUNDINGBOX_H_
#define BOUNDINGBOX_H_

using namespace std;

class BoundingBox {
public:
	BoundingBox(double minLatitude,double minLongitude,double maxLatitude,double maxLongitude);

	double translateLatitude(double latitude);
	double translateLongitude(double longitude);

private:
	double minLatitude;
	double minLongitude;
	double maxLatitude;
	double maxLongitude;
	double height;
	double width;
};



#endif /* BOUNDINGBOX_H_ */
