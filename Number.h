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
    // Returns a map of Number pointer properties
    virtual unordered_map<string, Number*> getValues() = 0;
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
    virtual vector<Number*> getLogValues() = 0;
    virtual void setLogValues(int index, Number* val) = 0;
};

#endif	/* NUMBER_H */

