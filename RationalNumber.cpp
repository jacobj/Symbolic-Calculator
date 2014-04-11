/* 
 * File:        RationalNumber.cpp
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#include "RationalNumber.h"

RationalNumber::RationalNumber(Number* numerator, Number* denominator) {
    this->numerator = numerator;
    this->denominator = denominator
        }

RationalNumber::~RationalNumber() {
    delete numerator;
    delete denominator;
}

//Get and set methods.
Number * RationalNumber::getNumerator() {
    return numerator;
}

Number * RationalNumber::getDenominator() {
    return denominator;
}

void RationalNumber::setNumerator(Number* numerator) {
    this->numerator = numerator;
}

void RationalNumber::setDenominator(Number* denominator) {
    this->denominator = denominator;
}

// Simplify helper method.
void RationalNumber::simplify() {
    // Simplify coefficients first if they are Integers
    if (typeid(denominator) == Integer && typeid(numerator) == Integer) {
        int gcd = findGCD(denominator->getValue(), 
                          numerator->getValue());
        denominator->setValue(denominator->getValue() / gcd);
        numerator->setValue(numerator->getValue() / gcd);
    }
    if (typeid(denominator->getCoefficient()) == Integer && 
        typeid(numerator->getCoefficient()) == Integer) {
        int gcd = findGCD(denominator->getCoefficient()->getValue(), 
                          numerator->getCoefficient()->getValue());
        denominator->getCoefficient->setValue(denominator->getCoefficient()->getValue() / gcd);
        numerator->getCoefficient->setValue(numerator->getCoefficient()->getValue() / gcd);
    }
    if (typeid(denominator) == TranscendentalNumber && 
        typeid(numerator) == TranscendentalNumber) {
        if (denominator->getValue() == numerator->getValue()) {
            // Then these values cancel
            denominator = new Integer(denominator->getCoefficient());
            numerator = new Integer(numerator->getCoefficient());
            return;
        } else {
            return;
        }
    }
    if (typeid(denominator) == nthRootIrrational && 
        typeid(numerator) == nthRootIrrational) {
        /*
         * If both the denominator and numerator are logarithms and both
         * contain the same value and nthRoot, then cancel them out.
         */
        if (denominator->getValue() == numerator->getValue() 
            && denominator->getNthRoot() == numerator->getNthRoot()) {
            denominator = new Integer(denominator->getCoefficient());
            numerator = new Integer(numerator->getCoefficient());
        } else {
            return;
        }
    }
    if (typeid(denominator) == Logarithm && typeid(numerator) == Logarithm) {
        /*
         * If both the denominator and numerator are logarithms and both
         * contain the same value and base, then cancel them out.
         */
        if (denominator->getValue() == numerator->getValue() 
            && denominator->getBase() == numerator->getBase()) {
            denominator = new Integer(denominator->getCoefficient());
            numerator = new Integer(numerator->getCoefficient());
        } else {
            return;
        }
    } else {
        return;
    }
}

// Use euclid's algorithm
int RationalNumber::findGCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
