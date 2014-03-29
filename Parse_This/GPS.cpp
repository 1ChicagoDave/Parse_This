/*
 * GPS.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: dave-
 */

#include "GPS.h"
#include "Sentence.h"
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

GPS::GPS() : activeDataFields(0x0), activeStatusFields(0x0) {

}

/**	Takes pointer to NMEA sentence as argument (GP, PK, etc...) and returns the correct checksum value.	**/
int GPS::makeChecksum(char* sentence) {
	// TODO: Look for delimiters:"$" and "*". IF present, only XOR substring between.
	// char* strippedSentence;
	char* strippedSentence = strtok(sentence, " $.*");	// remove "$" and "*"
	unsigned char xorChecksum = 0;
	unsigned long iLen = std::strlen(strippedSentence);

	for (size_t i = 0; i < iLen; ++i) {
		xorChecksum ^= (char) strippedSentence[i];
	}
	return xorChecksum;
}

