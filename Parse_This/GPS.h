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
public:
	GPS();		/// default constructor
	// static enum nmeaID_t {GPGLL, GPRMC, GPVTG, GPGGA, GPGSA, GPGSV, GPZDA };
	// nmeaID_t sentenceTypes;

	int makeChecksum(char*);

};

#endif /* GPS_H_ */
