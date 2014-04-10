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
#define NUMBER_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include <vector>

using namespace std;

class Number
{
public:
    virtual void simplify() = 0;
    virtual void display() = 0;
    // virtual Number& operator+(const Number& number) = 0;
    // virtual Number& operator-(const Number& number) = 0;
    // virtual Number& operator*(const Number& number) = 0;
    // virtual Number& operator/(const Number& number) = 0;
};

#endif  /* NUMBER_H */
