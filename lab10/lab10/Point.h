/*
 * Point.h
 * Author: Lance Brown
 * CS1021-001
 * Laboratory 10
 */

#ifndef SOURCE_H_
#define SOURCE_H_
#include <iostream>
#include <string>
using namespace std;

class Point {
public:
	Point(double x, double y);
	virtual ~Point();
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();
	void translatePoint(Point &point);
	
private:
	double x;
private:
	double y;
	
	
};



#endif /* SOURCE_H_ */
