/*
 * County.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: student
 */

#include "Polygon.h"





County::County() {
	countyName = "";
	stateName = "";
	rVote = 0;
	dVote = 0;
	oVote = 0;
}

County::County(string countyName, string stateName, int rVote, int dVote, int oVote){
	this->countyName = countyName;
	this->stateName = stateName;
	this->rVote = rVote;
	this->dVote = dVote;
	this->oVote = oVote;
}

int County::getRVote() {
	return rVote;
}

int County::getDVote() {
	return dVote;
}

int County::getOVote() {
	return oVote;
}

void County::setCountyName(string countyName) {
	this->countyName = countyName;
}

void County::setStateName(string stateName) {
	this->stateName = stateName;
}

string County::getCountyName() {
	return countyName;
}

string County::getStateName() {
	return stateName;
}

void County::setVote(int rVote, int dVote, int oVote) {
	this->rVote = rVote;
	this->dVote = dVote;
	this->oVote = oVote;
}

