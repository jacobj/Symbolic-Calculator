/* 
 * File:        nthRootIrrational.cpp
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#include "Exponential.h"


using namespace std;

Exponential::Exponential(Number* value, Number* exponent, Number* coefficient) {
    this->value = value;
    this->exponent = exponent;
    this->coefficient = coefficient;
}

Exponential::~Exponential() {
    delete value;
    delete exponent;
    delete coefficient;
}

Number * Exponential::getValue() {
    return value;
}

Number * Exponential::getExponent() {
    return exponent;
}

Number * Exponential::getCoefficient() {
    return coefficient;
}

void Exponential::setValue(Number* value) {
    this->value = value;
}

void Exponential::setExponent(Number* exponent) {
    this->exponent = exponent;
}

void Exponential::setCoefficient(Number* coefficient) {
    this->coefficient = coefficient;
}
  
// Simplify method.
void Exponential::simplify() {
    if (Integer* valueptr = dynamic_cast<Integer*>(value)) { 
        if (RationalNumber* exponentptr = dynamic_cast<RationalNumber*>(exponent)) {
            if (Integer* numeratorptr = dynamic_cast<Integer*>(exponentptr->getNumerator())) {
                if (Integer* denominatorptr = dynamic_cast<Integer*>(exponentptr->getDenominator())) {
                    // Raise the value to nth power and set the exponent to 1.
                    valueptr->setValue((long)pow(valueptr->getValue(), numeratorptr->getValue()));
                    numeratorptr->setValue(1);
                    // Break up value into it's prime factors.
                    vector<int> primes; 
                    primes = findPrimeFactors(valueptr->getValue(), 2, primes);
                    // Sort results in descending order. rend().
                    sort(primes.begin(), primes.end());
                    
                    /*
                      int value = value->getValue();
                      int coefficient = coefficient->getValue();
                      reduceInsideRoot(primes);
                      this->value->setValue(value);
                      this->coefficient->setValue(coefficient);
                    */
                }
            }
        }
    }
    // Add functionality to simplify Rationals.
    if (RationalNumber* valueptr = dynamic_cast<RationalNumber*>(value)) {
        if (Integer* exponentptr = dynamic_cast<Integer*>(exponent)) {
            // Square both denominator and numerator
            if (Integer* denominatorptr = dynamic_cast<Integer*>(valueptr->getDenominator())) {
                denominatorptr->setValue((long)pow(denominatorptr->getValue(),
                                                     exponentptr->getValue()));
            } 
            else {
                // Convert Denominator to it's own exponential.
            }
            if (Integer* numeratorptr = dynamic_cast<Integer*>(valueptr->getNumerator())) {
                numeratorptr->setValue((long)pow(numeratorptr->getValue(),
                                                 exponentptr->getValue()));
            } 
            else {
                // Convert Numerator to it's own exponential.
            }
            // Possibly simplify?
            value->simplify();
        }
        // Raise a rational to a rational
        if (RationalNumber* exponentptr = dynamic_cast<RationalNumber*>(exponent)) {
            // Grab the denominator and numerator of the exponent and store them in their own pointer.
            if (Integer* exponentNumeratorptr = dynamic_cast<Integer*>(exponentptr->getNumerator())) { 
                // If the Integer's denominator is an Integer.
                if (Integer* exponentDenominatorptr = dynamic_cast<Integer*>(exponentptr->getDenominator())) {                    
                    if (Integer* denominatorptr = dynamic_cast<Integer*>(valueptr->getDenominator())) {
                        // Rase the denominator to the power of the exponent's numerator
                        denominatorptr->setValue((long)pow(denominatorptr->getValue(),
                                                           exponentNumeratorptr->getValue()));
                        vector<int> primes1;
                        primes1 = findPrimeFactors(denominatorptr->getValue(), 2, primes1);
                    } 
                    else {
                        // Convert Denominator to it's own exponential.
                    }
                    if (Integer* numeratorptr = dynamic_cast<Integer*>(valueptr->getDenominator())) {
                        numeratorptr->setValue((long)pow(numeratorptr->getValue(),
                                                         exponentNumeratorptr->getValue()));
                        vector<int> primes2;
                        primes2 = findPrimeFactors(numeratorptr->getValue(), 2, primes2);
                    } 
                    else {
                        // Convert Numerator to it's own exponential.
                    }
                    // Work in progress.
                    // numeratorptr->setValue(1);
                    // value->simplify();
                }      
            }
        }
    }
}

// Find the primes. Helper method.
vector<int> Exponential::findPrimeFactors(int number, int i, vector<int> primeFactors) {
    if (number < i) {
        return primeFactors;
    } else if (number % i == 0) {
        primeFactors.push_back(i);
        return findPrimeFactors(number / i, 2, primeFactors);
    } else {
        return findPrimeFactors(number, i++, primeFactors);
    }
}

// Reduce value and multiply coefficients. Helper Method.
void Exponential::reduceInsideRoot(int &value, int &coefficient, int root, vector<int> primeFactors) {
    int counter = 1;
    int current = primeFactors[0];
    for (int i = 0; i < primeFactors.size(); i++) {
        if (current == primeFactors[i]) {
            counter++;
        } else {
            current = primeFactors[i];
            counter = 1;
        }
        if (counter == root) {
            coefficient *= primeFactors[i];
            for (int j = 0; j < root; j++) {
                value /= primeFactors[i];
            }
            counter = 0;
        }
    }
}
