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
    
    void simplify();
    void display();
    long getValue();
    void setValue(long value);
    Integer operator+(const Integer& integer);
    Integer operator-(const Integer& integer);
    Integer operator*(const Integer& integer);
    Integer operator/(const Integer& integer);
    
};

#endif	/* INTEGER_H */

