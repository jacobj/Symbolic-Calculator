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
Integer::Integer(int value) {
    this->value = value;
}

// Get-Set methods
int Integer::getValue() {
    return value;
}

void Integer::setValue(int value) {
    this->value = value;
}

// Simplify method
void Integer::simplify() {
    // Exists to satisfy Number Parent class.
}
