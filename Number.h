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
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <typeinfo>
#include <algorithm>

using namespace std;

class Number
{
public:
    // Returns a map of Number pointer properties
    virtual map<string, Number*> getValues() = 0;
    virtual void setValues(string key, Number* val) = 0;
    virtual void simplify() = 0;
    virtual void display() = 0;
    virtual double toDouble() = 0;
    virtual string toString() = 0;
    
    // Used only for Integers
    virtual long getValue() = 0;
    virtual void setValue(long value) = 0;
    
    // Used only for Transcendentals
    virtual string getTranscendentalValue() = 0;
    virtual void setTranscendentalValue(string value) = 0;
    
    // Used to return vector Log uses to store split logs.
    // virtual vector<Number*> getLogValues() = 0;
    // virtual void setLogValues(int index, Number* val) = 0;
    
    // Abstract operation methods
    virtual Number* add(Number*) = 0;
    virtual Number* subtract(Number*) = 0;
    virtual Number* multiply(Number*) = 0;
    virtual Number* divide(Number*) = 0;
    virtual Number* exponentiate(Number*) = 0;
};

#endif	/* NUMBER_H */

