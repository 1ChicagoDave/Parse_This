/**
 * \file Bit_Parser.cpp
 * ------------
 * \date Mar 29, 2014
 * \author dave-
 *	----------
 *
 *	What?:		Test function and program to confirm viability of concept/code.
 *
 *	Concept:	Setting individual bits (of uint32_t), each bit corresponding to specific
 *				variable/datafield/function which needs to be declared based on which NMEA
 *				sentences are being requested from GPS module (indicated by GPS constructor
 *				arguments).
 *
 *	Version:	"standard"
 */

#include <iostream>
#include <math.h>

using namespace std;

static string variableNames[8] = { "magVar", "geiodSep", "PDOPw", "PDOPf",
		"HDOPw", "HDOPf", "VDOPw", "VDOPf" };

// TODO: implement all binary/variable/bit-register-type-methods as templates in library -
unsigned int parseBinary(const uint16_t *val, int n) {
	uint8_t variableCounter = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (*val & (1 << i)) {
			variableCounter += 1;
			std::cout << variableNames[n - 1 - i] << '\n';
		} else {
			std::cout << "0" << '\n';
		}
	}
	return variableCounter;
}

int main() {

	uint16_t variableRegister = 0b11001101;
//	 uint8_t hexValues[] = {0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1};

	cout << "variable count = " << parseBinary(&variableRegister, 8) << '\n';
	return 0;
}

/** Results :
 * 	time: 0 memory: 3472 signal:0
 *
 * Output:
 *
 * magVar
 * geiodSep
 * 0
 * 0
 * HDOPw
 * HDOPf
 * 0
 * VDOPf
 * variable count = 5
 *
 */

