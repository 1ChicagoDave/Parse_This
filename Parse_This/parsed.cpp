/*
 * parsed.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: dave-
 */

#include "parsed.h"

parsed::parsed() {
	// TODO Auto-generated constructor stub

}

uint16_t parsed::timeUTC() {

	uint16_t utcTime = getFieldL(UTCtime);
	return utcTime;
}

char parsed::timeLoc(int8_t offset) {

	offset *= 10000;
	offset += getField(UTCtime*);
	return offset;
}

/** \fn parsed::date
 *
 *  \param char1 a single character: u = UTC , l = local
 *  \param char2 an integer: timezone offset from UTC
 *
 *  \returns uint16_t a long integer: in format of ddmmyy
 */
// TODO: Parameter 1 is pretty pointless. just complicates.
// either make another overload with only parameter 1
// or eliminate parameter 1 altogether.
uint16_t parsed::date(char char1, int8_t signedChar) {
}

/** \fn parsed::date
 *
 *  \brief Formatted date string in familiar "DateTime" format
 *  Example: "January 31, 2012"
 *  Can be UTC or local, depending on passed parameters.
 *
 *  \param char1 a single character: u = UTC , l = local
 *  \param char2 an integer: timezone offset from UTC
 *
 *  \returns char a string: in format of "Month dd, yyyy"
 */
char parsed::date(char char1, int8_t signedChar) {
}

float* parsed::latitudeDD() {
}

char* parsed::latitudeDMS() {
}

char parsed::latitudeNS() {
}

float* parsed::longitudeDEC() {
}

char* parsed::longitudeDMS() {
}

char parsed::longitudeEW() {
}

uint8_t parsed::fixQuality() {
}

uint8_t parsed::satsUsed() {

	return getFieldI(satsUsed);
}

float parsed::HDOP() {

	return getFieldI(HDOP);
}

float parsed::altitudeS() {
}

uint16_t parsed::altitudeI() {
}

float parsed::altitude(char arg1) {
}

float parsed::geoidSep() {

	float geoid = getField(geoidSepWhole);
	geoid += getField(geoidSepFract) / 100;
	return geoid;

}

char parsed::statusInd() {
	///	Returns "A" or "V"

	return getField(statusInd);
}

uint8_t parsed::satsInView() {
}

uint8_t parsed::satIDs() {
}

uint8_t parsed::satElevation() {
}

uint16_t parsed::satAzimuth() {
}

uint8_t parsed::satSNR() {
}

uint8_t parsed::groundSpeed() {
}

float parsed::headingS() {
}

uint8_t parsed::headingI() {
}

float parsed::headingRads() {
}

float parsed::horizSpeedNS() {
}

uint8_t parsed::horizSpeedNI() {
}

float parsed::horizSpeedKS() {
}

uint8_t parsed::horizSpeedKI() {
}
