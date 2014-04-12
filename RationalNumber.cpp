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
    this->denominator = denominator;
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
    // If the denominator is an Integer,
    if (Integer* denominatorptr = dynamic_cast<Integer*>(denominator)) {
        // If the numerator is an Integer (easiest case),
        if (Integer* numeratorptr = dynamic_cast<Integer*>(numerator)) {
            // Find the the common factor via Euclid's method.
            int gcd = findGCD(denominatorptr->getValue(), 
                              numeratorptr->getValue());
            // Divide the values by that factor to simplify.
            denominatorptr->setValue(denominatorptr->getValue() / gcd);
            numeratorptr->setValue(numeratorptr->getValue() / gcd);
        }
        // Else, if the numerator is an Exponential,
        else if (Exponential* numeratorptr = dynamic_cast<Exponential*>(numerator)) {
            // If the numerator's coefficient is an Integer,
            if (Integer* coefficientptr = dynamic_cast<Integer*>(numeratorptr->getCoefficient())) {
                int gcd = findGCD(denominatorptr->getValue(),
                                  coefficientptr->getValue());
                denominatorptr->setValue(denominatorptr->getValue() / gcd);
                coefficientptr->setValue(coefficientptr->getValue() / gcd);
            }
        }
        // Else, if the numerator is an Transcendental
        else if (TranscendentalNumber* numeratorptr = dynamic_cast<TranscendentalNumber*>(numerator)) {
            // If the numerator's coefficient is an Integer,
            if (Integer* coefficientptr = dynamic_cast<Integer*>(numeratorptr->getCoefficient())) {
                int gcd = findGCD(denominatorptr->getValue(),
                                  coefficientptr->getValue());
                denominatorptr->setValue(denominatorptr->getValue() / gcd);
                coefficientptr->setValue(coefficientptr->getValue() /gcd);
            }
        }
        // Logarithm is not yet compilable
        /*
        // Else, if the numerator is a Logarithm,        
        else if (Logarithm* numeratorptr = dynamic_cast<Logarithm*>(numerator)) {
            // If the numerator's coefficient is an Integer,
            if (Integer* coefficientptr = dynamic_cast<Integer*>(numeratorptr->getCoefficient())) {
                int gcd = findGCD(denominatorptr->getValue(),
                                  coefficientptr->getValue());
                denominator->setValue(denominatorptr->getValue() / gcd);
                coefficientptr->setValue(coefficientptr->getValue() /gcd);
            }
        }
        */
    }
    // ALL CODE BELOW IS OLD AND MUST BE REFACTORED.
    // Cases for Logs, Exponentials, Transcendentals
    else if (Exponential* denominatorptr = dynamic_cast<Exponential*>(denominator)) {
        if (Exponential* numeratorptr = dynamic_cast<Exponential*>(numerator)) {
            // Need to test if this works.
            if (*(numeratorptr->getValue()) == *(denominatorptr->getValue()) &&
                *(numeratorptr->getExponent()) == *(denominatorptr->getExponent())) {
                /*
                if (Integer* denominatorCoefficientptr = dynamic_cast<*Integer>(denominator->getCoefficient())) {
                    denominator = new Integer(denominatorCoefficientptr->getValue());
                } else if (Exponential* denominatorCoefficientptr = dynamic_cast<*Exponential>(denominator->getCoefficient())) {
                    // Make the denominator only consist of the coefficient.
                    denominator = new Exponential(denominatorCoefficientptr->getValue(), 
                                                  denominatorCoefficientptr->getExponent(),
                                                  denominatorCoefficientptr->getCoefficient());
                }
                if (Integer* numeratorCoefficientptr = dynamic_cast<*Integer>(denominator->getCoefficient())) {
                    numerator = new Integer(numeratorCoefficientptr->getValue());
                } else if (Exponential* numeratorCoefficientptr = dynamic_cast<*Exponential>(numerator->getCoefficient())) {
                    // Make the denominator only consist of the coefficient.
                    denominator = new Exponential(numeratorCoefficientptr->getValue(), 
                                                  numeratorCoefficientptr->getExponent(),
                                                  numeratorCoefficientptr->getCoefficient());
                }
                */
                // Instead, let's preserve the number as is, this saves many lines of code.
                denominatorptr->setValue(new Integer(1));
                denominatorptr->setExponent(new Integer(1));
                numeratorptr->setValue(new Integer(1));
                numeratorptr->setValue(new Integer(1));
            }
        }
    }
    /* 
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
        // If both the denominator and numerator are logarithms and both
        // contain the same value and nthRoot, then cancel them out.
        if (denominator->getValue() == numerator->getValue() 
            && denominator->getNthRoot() == numerator->getNthRoot()) {
            denominator = new Integer(denominator->getCoefficient());
            numerator = new Integer(numerator->getCoefficient());
        } else {
            return;
        }
    }
    if (typeid(denominator) == Logarithm && typeid(numerator) == Logarithm) {
        
        // If both the denominator and numerator are logarithms and both
        // contain the same value and base, then cancel them out.
        
        if (denominator->getValue() == numerator->getValue() 
            && denominator->getBase() == numerator->getBase()) {
            denominator = new Integer(denominator->getCoefficient());
            numerator = new Integer(numerator->getCoefficient());
        } else {
            return;
        }
    */
}

// Use euclid's algorithm
int RationalNumber::findGCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return findGCD(b, a % b);
    }
}
