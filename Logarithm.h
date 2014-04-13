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
#include "RationalNumber.h"
#include "Integer.h"

class Logarithm: public Number
{
	private:
	map<string, Number*> values;
    vector<Number> LogValues;
    char smoothOperator;
    public:
	    Logarithm(Number* coefficient, vector<Number*> LogValues, Number* base);
	    ~Logarithm();

        void simplify();
        void splitLog(vector<int> primes);
        void display();
        double toDouble();
        string toString();
    
        map<string, Number*> getValues();
        void setValues(string key, Number* val);
        vector<Number*> getLogValues();
        void setLogValues(vector<Number*> LogValues);
        vector<int> findPrimeFactors(int number, int i, vector<int> primeFactors);

		/*Logarithm operator+(const Logarithm& log);
		Logarithm operator-(const Logarithm& log);
		Logarithm operator*(const Logarithm& log);
		Logarithm operator/(const Logarithm& log);*/

		// Used to satisfy Number.h
		long getValue();
		void setValue(long value);
        string getTranscendentalValue();
	    void setTranscendentalValue(string value);
};


#endif	/* LOGARITHM_H */

