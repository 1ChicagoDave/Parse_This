/*
 * Sentence.h
 *
 *  Created on: Mar 25, 2014
 *      Author: dave-
 */

#ifndef SENTENCE_H_
#define SENTENCE_H_
using namespace std;

class Sentence: public GPS {
private:
	nmeaID_t GPGLL = 0xF1F80000, GPRMC = 0xFFF8CC00, GPVTG = 0xFF00, GPGGA =
			0xF1FF004C, GPGSA = 0x3F, GPGSV, GPZDA = 0xFE000000;
protected:
	uint32_t activeDataFields;	// 32 bits - one for each data field to declare
	uint8_t activeStatusFields;	// 5 LSB used
	uint32_t dataFieldHelper(nmeaID_t[], uint8_t);
	void setDataFields(nmeaID_t&);
	uint8_t statusFields[5] = { 0x10, 0x10, 0x0, 0x09, 0x06, 0x0, 0x0 };

public:
	Sentence();		// Default constructor
	Sentence(nmeaID_t);
	Sentence(nmeaID_t, nmeaID_t);
	Sentence(nmeaID_t, nmeaID_t, nmeaID_t);
	Sentence(nmeaID_t, nmeaID_t, nmeaID_t, nmeaID_t);
	Sentence(nmeaID_t, nmeaID_t, nmeaID_t, nmeaID_t, nmeaID_t,);
	Sentence(nmeaID_t, nmeaID_t, nmeaID_t, nmeaID_t, nmeaID_t, nmeaID_t,);
	Sentence(nmeaID_t, nmeaID_t, nmeaID_t, nmeaID_t, nmeaID_t, nmeaID_t,
			nmeaID_t,);
	void (*pfRMC[])(void);

	uint8_t size;
	// nmeaID_t sentenceTypes;

	bool satID = false;		// flag to declare satChannel[] array or not

};

#endif /* SENTENCE_H_ */
