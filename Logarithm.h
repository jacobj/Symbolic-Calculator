/* 
 * File:        Logarithm.h
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#ifndef LOGARITHM_H
#define	LOGARITHM_H
#include "Number.h"

class Logarithm: public Number
{
    public:
	    Logarithm(Number coefficient, vector<Number> values, Number base);
	    Logarithm(Number coefficient, Number value, Number base);
	    ~Logarithm();

        void simplify();
        void splitLog(vector<int> primes)
        void display();
        double toDouble();
        string toString();
    
        Number getCoefficient();
        vector<Number*> getValues();
        Number getBase();
        void setCoefficient(Number coefficient);
        void setValue(Number value);
        void setValues(vector<Number> values);
        void setBase(Number base);
		Logarithm operator+(const Logarithm& log);
		Logarithm operator-(const Logarithm& log);
		Logarithm operator*(const Logarithm& log);
		Logarithm operator/(const Logarithm& log);

    private:
        Number coefficient;
        vector<Number> values;
        Number base;
};


#endif	/* LOGARITHM_H */

