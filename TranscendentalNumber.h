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
//#include "Exponential.h"
#include "Expression.h"
#include "Integer.h"
//#include "Logarithm.h"
//#include "RationalNumber.h"

class TranscendentalNumber : public Number {
public:
	TranscendentalNumber(string value, Number* coefficient);
	TranscendentalNumber(string value);
	~TranscendentalNumber();
	void simplify();
	void display();
	double toDouble();
	string toString();

    //Operation Methods
    Number* add(Number* val);
    Number* subtract(Number* val);
    Number* multiply(Number* val);
    Number* divide(Number* val);
    Number* exponentiate(Number* val);

	map<string, Number*> getValues();
	void setValues(string key, Number* val);
	string getTranscendentalValue();
	void setTranscendentalValue(string value);
	Number * getCoefficient();
	void setCoefficient(Number* coefficient);

    // Used to satisfy Number.h
    long getValue();
    void setValue(long value);

private:
	string value;
	map<string, Number*> values;
};

#endif	/* TRANSCENDENTALNUMBER_H */

