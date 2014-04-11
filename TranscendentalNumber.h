/* 
 * File:        TranscendentalNumber.h
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#ifndef TRANSCENDENTALNUMBER_H
#define	TRANSCENDENTALNUMBER_H

#include "Number.h"

class TranscendentalNumber : public Number {
public:
	TranscendentalNumber(string value, Number* coefficient);
	~TranscendentalNumber();
	void simplify();
	void display();
	double toDouble();

	string getValue();
	Number * getCoefficient();
	void setValue(string value);
	void setCoefficient(Number* coefficient);
    
    TranscendentalNumber operator+(const TranscendentalNumber& value);
    TranscendentalNumber operator-(const TranscendentalNumber& value);
    TranscendentalNumber operator*(const TranscendentalNumber& value);
    TranscendentalNumber operator/(const TranscendentalNumber& value);

private:
	string value;
	Number* coefficient;
};

#endif	/* TRANSCENDENTALNUMBER_H */

