/* 
 * File:        Exponential.h
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#ifndef EXPONENTIAL_H
#define	EXPONENTIAL_H

#include "Number.h"
#include "RationalNumber.h"
#include "Integer.h"

using namespace std;

class Exponential : public Number {  
private:
    unordered_map<string, Number*> values;

public:
	Exponential(Number* value, Number* exponent, Number* coefficient);
	~Exponential();
    void simplify();
    void display();
    double toDouble();
    unordered_map<string, Number*> getValues();
    void setValues(string key, Number* val);

    // Only used in exponent
    vector<int> findPrimeFactors(int number, int i, vector<int> primeFactors);
    void reduceInsideRoot(int &value, int &coefficient, int root, vector<int> primeFactors);
    
    // Used to satisfy Number.h
    long getValue();
    void setValue(long value);
    string getTranscendentalValue();
    void setTranscendentalValue(string value); 
    vector<Number*> getLogValues();
    void setLogValues(int index, Number* val);

    // Exponential operator+(const nthRootIrrational& nthRoot);
    // Exponential operator-(const nthRootIrrational& nthRoot);
    // Exponential operator*(const nthRootIrrational& nthRoot);
    // Exponential operator/(const nthRootIrrational& nthRoot);
};
    
#endif	/* EXPONENTIAL_H */
    
