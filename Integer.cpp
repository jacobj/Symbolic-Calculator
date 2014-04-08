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
Integer:: Integer(int coefficient) {
	this->coefficient = coefficient;
}

// Get-Set methods
int Integer:: getCoefficient() {
    return coefficient;
}
void Integer:: setCoefficient(int coefficient) {
    this->coefficient = coefficient;
}

// Simplify method
void Integer:: simplify() {
        // Exists to satisfy Number Parent class.
}
