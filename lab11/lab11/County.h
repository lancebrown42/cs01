/*
 * County.h
 *
 *  Created on: Apr 16, 2014
 *      Author: student
 */

#ifndef COUNTY_H_
#define COUNTY_H_
#include "Polygon.h"

class County{
public:
	County();
	County(string countyName, string stateName, int rVote, int dVote, int oVote);
	int getRVote();
	int getDVote();
	int getOVote();
	string getCountyName();
	string getStateName();
	void setCountyName(string countyName);
	void setStateName(string stateName);
	void setVote(int rVote, int dVote, int oVote);


private:
	string countyName;
	string stateName;
	int rVote;
	int dVote;
	int oVote;
};


#endif /* COUNTY_H_ */
