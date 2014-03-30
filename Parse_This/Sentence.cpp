/*
 * Sentence.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: dave-
 */

#include "Sentence.h"
#include "GPS.h"
using namespace std;

/**
 *  default constructor - GPRMC
 */
Sentence::Sentence() :
		size(1) {
	nmeaID_t nmeaIDarray[1] = { GPRMC };
	dataFieldHelper(nmeaIDarray, size);
}

/// Passes array to dataFieldHelper - > setDataFields();
Sentence::Sentence(nmeaID_t id0) :
		size(1) {
	nmeaID_t nmeaIDarray[1] = { id0 };
	dataFieldHelper(nmeaIDarray, size);
}

Sentence::Sentence(nmeaID_t id0, nmeaID_t id1) :
		size(2) {
	nmeaID_t nmeaIDarray[2] = { id0, id1 };
	dataFieldHelper(nmeaIDarray, size);
}

Sentence::Sentence(nmeaID_t id0, nmeaID_t id1, nmeaID_t id2) :
		size(3) {
	nmeaID_t nmeaIDarray[3] = { id0, id1, id2 };
	dataFieldHelper(nmeaIDarray, size);
}

Sentence::Sentence(nmeaID_t id0, nmeaID_t id1, nmeaID_t id2, nmeaID_t id3) :
		size(4) {
	nmeaID_t nmeaIDarray[4] = { id0, id1, id2, id3 };
	dataFieldHelper(nmeaIDarray, size);
}

Sentence::Sentence(nmeaID_t id0, nmeaID_t id1, nmeaID_t id2, nmeaID_t id3,
		nmeaID_t id4) :
		size(5) {
	nmeaID_t nmeaIDarray[5] = { id0, id1, id2, id3, id4 };
	dataFieldHelper(nmeaIDarray, size);
}

Sentence::Sentence(nmeaID_t id0, nmeaID_t id1, nmeaID_t id2, nmeaID_t id3,
		nmeaID_t id4, nmeaID_t id5) :
		size(6) {
	nmeaID_t nmeaIDarray[6] = { id0, id1, id2, id3, id4, id5 };
	dataFieldHelper(nmeaIDarray, size);
}

Sentence::Sentence(nmeaID_t id0, nmeaID_t id1, nmeaID_t id2, nmeaID_t id3,
		nmeaID_t id4, nmeaID_t id5, nmeaID_t id6) :
		size(7) {
	nmeaID_t nmeaIDarray[7] = { id0, id1, id2, id3, id4, id5, id6 };
	dataFieldHelper(nmeaIDarray, size);
}

uint32_t Sentence::dataFieldHelper(nmeaID_t id[], uint8_t arraySize) {
	for (uint8_t i = 0; i < arraySize; ++i) {
		setDataFields(id[i]);
		if (satID) {
			uint8_t satChannel[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		}
	}
	return activeDataFields;
}

void Sentence::setDataFields(nmeaID_t& id) {

	activeDataFields |= id;
	activeStatusFields |= statusFields[id];

	if (activeDataFields & 0x2)		// we're expecting GPGSA sentences
			{
		satID = true;			// flag to declare satellite channel/ID array
	}

}

