/*
 * Command.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: dave-
 */

#include "Command.h"

Command::Command() {
	// TODO Auto-generated constructor stub

}


int Command::set(int pmtk, char &settings) {

	bool ackResponse = GPS.ackListen();

	return ackResponse;

}

int Command::query(int pmtk) {
	//	Use in function pointer?

	//	Constructs PMTK query string from argument (3-digit integer ID)
	//	Computes and appends valid checksum?? If needed.  - Lookup table?
	// 	Return full check-summed string.

	char queryString;
	return queryString;
}

char Command::setting(int int1, char s) {
	// Takes PMTK# and setting string, computes checksum, concatenates, passes as function pointer?

	char commandString;
	return commandString;
}

Command::~Command() {
	// TODO Auto-generated destructor stub
}

