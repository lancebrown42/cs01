/*
 * Point.cpp
 * Author: Lance Brown
 * CS1021-001
 * Laboratory 10
 */
#include <Point.h>
#include <iostream>
#include <cmath>
#include <string>
#include <BoundingBox.h>

using namespace std;





Point::Point(double x, double y) {
	setX(x);
	setY(y);
}

Point::~Point() {
	//uhh
}

void Point::setX(double x) {
	this->x = x;
}

void Point::setY(double y) {
	this->y = y;

}

double Point::getX() {
	return x;

}

double Point::getY() {
	return y;
}

void Point::translatePoint(Point& point) {
	BoundingBox box(point);

}

