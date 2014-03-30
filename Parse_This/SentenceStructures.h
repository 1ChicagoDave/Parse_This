/*
 * SentenceStructures.h
 *
 *  Created on: Mar 26, 2014
 *      Author: David R Ratliff
 *      
 *	"Lookup table" for multiple possible NMEA sentence types.     
 *	 
 */
#include "Sentence.h"
#include "GPS.h"

/*
 *                                                           12
 1         2 3       4 5        6  7   8   9    10 11|  13
 |         | |       | |        |  |   |   |    |  | |   |
 $--RMC,hhmmss.ss,A,llll.ll,a,yyyyy.yy,a,x.x,x.x,xxxx,x.x,a,m,*hh<CR><LF>
 
 1:	UTC Time
 2:	Status, V=Navigation receiver warning A=Valid
 3:	Latitude
 4:	N or S
 5:	Longitude
 6:	E or W
 7:	Speed over ground, knots
 8:	Track made good, degrees true
 9:	Date, ddmmyy
 10:	Magnetic Variation, degrees
 11:	E or W
 12:	FAA mode indicator (NMEA 2.3 and later)
 13:	Checksum
 *
 */

//  RMC sentence variable/contatiner name scheme : 
//  $--RMC,hhmmss.ss,status,latdm.latm,ns,longdm.longm,ew,groundSpeedWhole.groundSpeedFraction,headingWhole.
//		headingFraction,ddmmyy,magVarWhole.magVarFraction,magVarCard,FAA,*checksum<CR><LF>
///	ALL GPS sentence data field storage index -
/// if (sentenceTypes == ALL )

/**
 * \typedef typedef uint32_t dataFieldName
 * 	\brief	unsigned integer 32-bit
 * 		Type for complete listing of possible GPS NMEA sentence data fields
 */
typedef uint32_t dataFieldName;

/**
 *	Complete listing of possible GPS NMEA sentence data fields
 *	...and their hex bit identifier value
 *
 *	TODO: <template>??
 *
 */
dataFieldName 	hrsWhole = 0x80000000,
				minsWhole = 0x40000000,
				secsWhole = 0x20000000,
				secsFract = 0x10000000, 		///	time	// 4
				///	time == 0xF0000000
				day = 0x8000000,
				month = 0x4000000,
				year = 0x2000000, 				///	date	// 3
				/// date = 0xE000000
				latDegMinWhole = 0x1000000,
				latMinFract = 0x800000,
				cardNS = 0x400000, 							///	latitude and N/S	//	3
				/// lat == 0x1C00000
				longDegMinWhole = 0x200000,
				longMinFract = 0x100000,
				cardEW = 0x80000, 							///	longitude and E/W	//	3
				/// long == 0x380000
				altitudeWhole = 0x40000,
				altitudeFract = 0x20000,
				altitudeUnits = 0x10000,					///	altitude			//	3
				///	altitude == 0x70000
				knotSpeedWhole = 0x8000,
				knotSpeedFract = 0x4000,
				kiloSpeedWhole = 0x2000,
				kiloSpeedFract = 0x1000,		///	speed and units	// 4
				/// knotSpeed = 0xC000	kiloSpeed == 0x3000  BOTH == 0xF000

				///	course/headings in degrees	// 4
				trueCourseWhole = 0x800,
				trueCourseFract = 0x400,
				magCourceWhole = 0x200,
				magCourceFract = 0x100,
				/// trueCourse == 0xC00	magCourse == 0x300		BOTH == 0xF00

				/// Earth/environmental info	// 2
				magVar = 0x80,
				geoidSep = 0x40,

				///	dilution of precions	// 6
				PDOPwhole = 0x20,
				PDOPfract = 0x10,
				HDOPwhole = 0x8,
				HDOPfract = 0x4,
				VDOPwhole = 0x2,
				VDOPfract = 0x1;
				/// PDOP == 0x30	HDOP == 0xC		VDOP = 0x3	ALL = 0x3F

				//	4+3+3+3+3+4+4+4+1+2+6 = 37 variables - 5 == 32
				// 11111111 11111111 11111111 11111111


typedef uint8_t statusFieldName;
statusFieldName statusAV = 0x10, posFix0123 = 0x08, modeAM = 0x04, mode123 =
		0x02,								///	fix/quality indicators	// 4
		qtySatsUsed = 0x01;								///	satellite info	// 1
/// 00011111

/**	if GPSsentenceTypes includes GSA, initialize this array -
 *	tracks which satellites are using which channel on GPS module
 *	array index == [GPSchannel], value == {satellite number}
 */
uint8_t satOnChannel[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/** if GPS.sentenceTypes includes GSV, initialize this array -
 * 	2D array tracking satID, satElevation, satAzimuth, and satSNR
 * 	up to 12 satellites worth of info
 * 	array index == [satID], values == {satElevation, satAzimuth,, satSNR}
 * 		**?? - make vector??
 */
uint8_t satsInView[12][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
		{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0,
				0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, };



//	Example Jump table for RMC sentence
void (*pfRMC[])(
		void) {hoursMin(), secondsFract(), statusInd(), latDegMin(), latMin(), northSouth(),
			longDegMin(), longMin, eastWest(), groundSpeedWhole(), groundSpeedFract(),
			courseWhole(), courseFract(), dateFull(), pfNULL(), pfNULL(), pfNULL(),
			pfNULL()};

