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

class TranscendentalNumber :: public Number{
public:
	TranscendentalNumber(String value, int coefficient);
	~TranscendentalNumber();
	simplify();

	void getValue();
	void getCoefficient();
	String setValue(String value);
	int setCoefficient(int coefficient);
    
    TranscendentalNumber operator+(const TranscendentalNumber& value);
    TranscendentalNumber operator-(const TranscendentalNumber& value);
    TranscendentalNumber operator*(const TranscendentalNumber& value);
    TranscendentalNumber operator/(const TranscendentalNumber& value);

private:
	String value;
	Number coefficient;
};

#endif	/* TRANSCENDENTALNUMBER_H */

