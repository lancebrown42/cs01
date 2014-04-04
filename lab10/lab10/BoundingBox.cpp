/*
 * BoundingBox.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: lance
 */
#include <iostream>
#include <BoundingBox.h>
#include <cmath>
using namespace std;




BoundingBox::BoundingBox() {
}

BoundingBox::~BoundingBox(){

}

BoundingBox::BoundingBox(double minLat, double minLong, double maxLat,
		double maxLong) {
	minLatitude = minLat;
	minLongitude = minLong;
	maxLatitude = maxLat;
	maxLongitude = maxLong;
	width = translateLongitude(maxLongitude) - translateLongitude(minLongitude);
	height = translateLatitude(minLatitude) - translateLatitude(maxLatitude);
}

BoundingBox::BoundingBox(double width, double height) {
}

double BoundingBox::translateLatitude(double latitude) {
	latitude = maxLatitude - latitude;
	latitude *= 20;
	return abs(latitude);
}

double BoundingBox::translateLongitude(double longitude) {
	longitude -= minLongitude;
	longitude *= 20;
	return abs(longitude);
}

double BoundingBox::getWidth(){
	return width;
}

double BoundingBox::getHeight(){
	return height;
}
