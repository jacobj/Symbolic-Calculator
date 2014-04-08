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
	TranscendentalNumber(enum value, int coefficient);
	simplify();

	void getValue();
	void getCoefficient();
	enum setValue(enum value);
	int setCoefficient(int coefficient);


private:
	enum value;
	int coefficient;
}

#endif	/* TRANSCENDENTALNUMBER_H */

