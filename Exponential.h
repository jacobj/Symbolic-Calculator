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
 public:
	Exponential(Number* value, Number* exponet, Number* coefficient);
	~Exponential();
    void simplify();
    vector<int> findPrimeFactors(int number, int i, vector<int> primeFactors);
    void reduceInsideRoot(vector<int> primeFactors);
    
    Number getValue();
    Number getExponent();
    Number getCoefficient();
    void setValue(Number* value);
    void setExponent(Number* exponent);
    void setCoefficient(Number* Coefficient);
    // Exponential operator+(const nthRootIrrational& nthRoot);
    // Exponential operator-(const nthRootIrrational& nthRoot);
    // Exponential operator*(const nthRootIrrational& nthRoot);
    // Exponential operator/(const nthRootIrrational& nthRoot);
    
 private:
    Number* value;
    Number* exponent;
    Number* coefficient;
};
    
#endif	/* EXPONENTIAL_H */
    
    
