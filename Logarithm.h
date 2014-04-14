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
#include "Exponential.h"
#include "TranscendentalNumber.h"

class Logarithm: public Number
{
private:
	map<string, Number*> values;
    // char smoothOperator;
public:
    Logarithm(Number* coefficient, Number* value, Number* base);
    Logarithm(string input);
    ~Logarithm();

    void simplify();
    void splitLog(vector<long> primes);
    void display();
    double toDouble();
    string toString();
    
    map<string, Number*> getValues();
    void setValues(string key, Number* val);
    int logBaseN(long value, long n, int counter);
    // vector<long> findPrimeFactors(long number, long i, vector<long> primeFactors);

    // Operation methods
    Number* add(Number*);
    Number* subtract(Number*);
    Number* multiply(Number*);
    Number* divide(Number*);
    Number* exponentiate(Number*);

    // Used to satisfy Number.h
    long getValue();
    void setValue(long value);
    string getTranscendentalValue();
    void setTranscendentalValue(string value);
};


#endif	/* LOGARITHM_H */

