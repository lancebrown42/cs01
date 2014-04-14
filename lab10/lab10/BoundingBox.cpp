/*
 * BoundingBox.cpp
 * Author: Lance Brown
 * CS1021-001
 * Laboratory 10
 */
#include <iostream>
#include <BoundingBox.h>
#include <cmath>
#include <Point.h>
#include <fstream>
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

BoundingBox::BoundingBox(Point &point) {
	minLongitude = -124.731216; //I have no idea how to do this correctly
	maxLatitude = 49.384365;
	point.setX(translateLongitude(point.getX()));
	point.setY(translateLatitude(point.getY()));

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
