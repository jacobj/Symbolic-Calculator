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
    this->values["numerator"] = numerator;
    this->values["denominator"] = denominator;
}

RationalNumber::~RationalNumber() {
    delete values["numerator"];
    delete values["denominator"];
}

unordered_map<string, Number*> RationalNumber::getValues() {
    return values;
}

void RationalNumber::setValues(string key, Number* val) {
    values[key] = val;
}

double RationalNumber::toDouble(){
    return values["numerator"]->toDouble() / values["denominator"]->toDouble();
}
string RationalNumber::toString(){
	stringstream valueStream;
	valueStream << values["numerator"]->toString() << "/" << values["denominator"]->toString();
	string str = valueStream.str();
	return str;
}

// Simplify helper method.
void RationalNumber::simplify() {
    // If the denominator is an Integer,
    if (typeid(*values["denominator"]) == typeid(Integer)) {
        // If the numerator is an Integer (easiest case),
        if (typeid(*values["numerator"]) == typeid(Integer)) {
            // Find the the common factor via Euclid's method.
            int gcd = findGCD(values["denominator"]->getValue(), 
                              values["numerator"]->getValue());
            // Divide the values by that factor to simplify.
            values["denominator"]->setValue(values["denominator"]->getValue() / gcd);
            values["numerator"]->setValue(values["numerator"]->getValue() / gcd);
        }
        // Else, if the numerator is something else,
        else if (typeid(*values["numerator"]) != typeid(Integer)) {
            // If the numerator's coefficient is an Integer,
            if (typeid(*values["numerator"]->getValues()["coefficient"]) == typeid(Integer)) {
                int gcd = findGCD(values["denominator"]->getValue(),
                                  values["numerator"]->getValues()["coefficient"]->getValue());
                values["denominator"]->setValue(values["denominator"]->getValue() / gcd);
                values["numerator"]->getValues()["coefficient"]->setValue(values["numerator"]->getValues()["coefficient"]->getValue() / gcd);
            }
        }
    }
    // ALL CODE BELOW IS OLD AND MUST BE REFACTORED.
    // Cases for Logs, Exponentials, Transcendentals
    /*
    else if (Exponential* denominatorptr = dynamic_cast<Exponential*>(denominator)) {
        if (Exponential* numeratorptr = dynamic_cast<Exponential*>(numerator)) {
            // Need to test if this works.
            if (*(numeratorptr->getValue()) == *(denominatorptr->getValue()) &&
                *(numeratorptr->getExponent()) == *(denominatorptr->getExponent())) {
                
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
                
                // Instead, let's preserve the number as is, this saves many lines of code.
                denominatorptr->setValue(new Integer(1));
                denominatorptr->setExponent(new Integer(1));
                numeratorptr->setValue(new Integer(1));
                numeratorptr->setValue(new Integer(1));
            }
        }
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

vector<Number*> RationalNumber::getLogValues() {
    return NULL;
}

void RationalNumber::setLogValues(int index, Number* val) {
    return;
}

string RationalNumber::getTranscendentalValue() {
    return "";
}

void RationalNumber::setTranscendentalValue(string value) {
    return;
}
