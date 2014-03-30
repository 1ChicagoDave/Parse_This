/*
 * Command.h
 *
 *  Created on: Mar 25, 2014
 *      Author: dave-
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "GPS.h"
using namespace std;

class Command: public GPS {
public:
	Command();
	char setting(int, char*);// Takes PMTK# and setting string, computes checksum, concatenates, passes as function pointer
	int set(int, char&);
	int query(int);
	virtual ~Command();
};

#endif /* COMMAND_H_ */
