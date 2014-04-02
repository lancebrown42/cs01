/*
 * BoundingBox.cpp
 *
 *  Created on: Mar 31, 2014
 *      Author: student
 */
#include <BoundingBox.h>
#include <iostream>
#include <cmath>
#include <string>






BoundingBox::BoundingBox(double minLatitude, double minLongitude,
		double maxLatitude, double maxLongitude) {

}

double BoundingBox::translateLatitude(double latitude) {
	latitude = maxLatitude - latitude;
	return latitude;
}

double BoundingBox::translateLongitude(double longitude) {
	longitude -= minLongitude;
	return longitude;

}

int main(){

}
