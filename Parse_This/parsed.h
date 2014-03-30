/*
 * parsed.h
 *
 *  Created on: Mar 25, 2014
 *      Author: dave-
 */

#ifndef PARSED_H_
#define PARSED_H_

#include "Sentence.h"
#include <stdint.h>
#include "stdint.h"

class parsed: public Sentence {
private:

public:
	parsed();						//	Constructor
	/**
	 *
	 */

	uint16_t timeUTC();			//	UTC Time (default)
	char timeLoc(int8_t);		//	timezone offset	(calculated)
	uint16_t date(char, int8_t);	//	(u or l), (timezone offset) ddmmyy
	char date(char, int8_t);//	(u or l), )offset)	familiar "datetime" format
	float* latitudeDD();			//	Decimal Degrees (DD)
	char* latitudeDMS();			//	Degrees, Minutes, Seconds
	char latitudeNS();			//	North/South?
	float* longitudeDEC();			//	Decimal Degrees (DD)
	char* longitudeDMS();			//	Degrees, Minutes, Seconds
	char longitudeEW();			//	East/West
	uint8_t fixQuality();			//	GGA	/	(0, 1, 2, 3)
	uint8_t satsUsed();				//	number of sats being used (0 -12)
	float HDOP();			//	Horizontal Dilution of Precision ( 1 == GOOD!)
	float altitudeS();			//	in meters (default) -
	uint16_t altitudeI();		//	in meters (intger) -
	float altitude(char arg1);	//	convert to km, ft, mi, etc
	float geoidSep();				//	in meters (default)
	char statusInd();			//	GLL & RMC sentence (A = Valid, V = Invalid)
	//	*Status set to "A" (valid) for Modes (A & D), to "V" (invalid) for all other values of Mode Indicator.
	uint8_t satsInView();			//	GSV sentence	(
	uint8_t satIDs();				//	GSV	(1-32)
	uint8_t satElevation();			//	GSV	(0-90)
	uint16_t satAzimuth();		//	GSV	(0-359)
	uint8_t satSNR();				//	GSV	(0-99)
	uint8_t groundSpeed();			//	RMC speed over ground (knots)
	float headingS();				//	degrees	(default) ###.##
	uint8_t headingI();				//	degrees	(default) ###
	float headingRads();			//	radians	(calculated)

	float horizSpeedNS();			//	VTG - knots	(default)	###.##
	uint8_t horizSpeedNI();			//	VTG - knots	(default)	###
	float horizSpeedKS();			//	VTG - km/h	(calculated)	###.##
	uint8_t horizSpeedKI();			//	VTG - km/h	(calculated)	###

};

#endif /* PARSED_H_ */
