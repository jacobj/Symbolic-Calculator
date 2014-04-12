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
	string toString();

	map<string, Number*> getValues();
	void setValues(string key, Number* val);
	string getTranscendentalValue();
	void setTranscendentalValue(string value);
	Number * getCoefficient();
	void setCoefficient(Number* coefficient);
    
    TranscendentalNumber operator+(const TranscendentalNumber& value);
    TranscendentalNumber operator-(const TranscendentalNumber& value);
    TranscendentalNumber operator*(const TranscendentalNumber& value);
    TranscendentalNumber operator/(const TranscendentalNumber& value);

    // Used to satisfy Number.h
    long getValue();
    void setValue(long value);
    string getTranscendentalValue();
    void setTranscendentalValue(string value);
    vector<Number*> getLogValues();
    void setLogValues(int index, Number* val);

/*private:
	string value;
	Number* coefficient;*/
};

#endif	/* TRANSCENDENTALNUMBER_H */

