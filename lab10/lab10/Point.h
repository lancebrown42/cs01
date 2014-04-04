/*
 * Point.h
 *
 *  Created on: Apr 2, 2014
 *      Author: lance
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
	double getX(double x);
	double getY(double y);
	
	
private:
	double x;
	double y;
	
	
};



#endif /* SOURCE_H_ */
