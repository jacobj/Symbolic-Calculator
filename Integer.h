/*
 * File:        Integer.h
 *
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 *
 *
 */

#ifndef INTEGER_H
#define	INTEGER_H

#include "Number.h"
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class Integer : public Number {
private:
    long value;

public:
    Integer(long value);
    Integer();
    
    long getValue();
    void setValue(long value);
    void display();
    double toDouble();

    // Implemented to satisfy Number.h
    unordered_map<string, Number*>* getValues();
    string getTranscendentalValue();
    void setTranscendentalValue(string value); 
    vector<Number*>* getLogValues();
    void simplify();
    
    // Overloaded operators
    Integer operator+(const Integer& integer);
    Integer operator-(const Integer& integer);
    Integer operator*(const Integer& integer);
    Integer operator/(const Integer& integer);
};

#endif	/* INTEGER_H */

