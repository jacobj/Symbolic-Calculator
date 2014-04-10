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

#include "Integer.h"

// Constructor
Integer::Integer(long value) {
    this->value = value;
}

Integer::Integer() {
    this->value = 0;
}

// Get-Set methods
long Integer::getValue() {
    return value;
}

void Integer::setValue(long value) {
    this->value = value;
}

// Simplify method
void Integer::simplify() {
    // Exists to satisfy Number Parent class.
}

Integer Integer:: operator+(const Integer &integer) {
    Integer temp;
    temp.value = value + integer.value;
    return temp;
}

Integer Integer:: operator-(const Integer &integer) {
    Integer temp;
    temp.value = value - integer.value;
    return temp;
}

Integer Integer:: operator*(const Integer &integer) {
    Integer temp;
    temp.value = value * integer.value;
    return temp;
}

Integer Integer:: operator/(const Integer &integer) {
    try {
        Integer temp;
        if (integer.value == 0) {
            throw invalid_argument("Cannot divide by 0!");
        }
        catch (invalid_argument &ex) {
            cerr << ex.what() << endl;
        }
        temp.value = value / integer.value;
        return temp;
    }
