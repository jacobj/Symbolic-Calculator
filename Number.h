/* 
 * File:   Number.h
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#ifndef NUMBER_H
#define	NUMBER_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class Number
{
public:
    virtual unordered_map<string, Number*> getValues() = 0;
    // Used only to return long values of Integers
    virtual long getValue() = 0;
    virtual void setValue(long value) = 0;
    // Used to return String value of Transcendental
    virtual string getTranscendentalValue() = 0;
    virtual void setTranscendentalValue(string value) = 0;
    virtual void simplify() = 0;
    virtual void display() = 0;
    virtual double toDouble() = 0;
    // Get/Set methods
    /*virtual Number& getValue() = 0;
    virtual Number& getExponent() = 0;
    virtual Number& getCoefficient() = 0;
    virtual Number& getNumerator() = 0;
    virtual Number& getDenominator() = 0;*/
};

#endif	/* NUMBER_H */

