/*
 * GPS.h
 *
 *  Created on: Mar 25, 2014
 *      Author: dave-
 */

#ifndef GPS_H_
#define GPS_H_
using namespace std;

typedef uint32_t nmeaID_t;

class GPS {
protected:
	static uint32_t activeDataFields;	// 32 bits - one for each data field to declare
	static uint8_t activeStatusFields;	// 5 LSB used
public:
	GPS();		/// default constructor
	// static nmeaID_t {GPGLL, GPRMC, GPVTG, GPGGA, GPGSA, GPGSV, GPZDA };
	// nmeaID_t sentenceTypes;

	int makeChecksum(char*);

};

#endif /* GPS_H_ */
