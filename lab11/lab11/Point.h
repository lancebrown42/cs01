/*
 * Point.h
 * Author: Lance Brown
 * CS1021-001
 * Laboratory 10
 */

#ifndef SOURCE_H_
#define SOURCE_H_
using namespace std;

class Point {
public:
	Point(double x, double y);
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();
	
private:
	double x;
	double y;
	
	
};



#endif /* SOURCE_H_ */