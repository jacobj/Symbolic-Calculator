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

Number Exponential::getValue() {
    return value;
}

Number Exponential::getExponent() {
    return exponent;
}

Number Exponential::getCoefficient() {
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
    if (typeid(value) == Integer && typeid(exponent) == RationalNumber) {
        value->setValue((long)pow(value->getValue(), exponent->getNumerator->getValue()));
        exponent->getNumerator()->setValue(1);
        vector<int> primes; 
        primes = findPrimeFactors(value->getValue(), 2, primes);
        // Sort results in descending order. rend().
        sort(primes.begin(), primes.end());
        int value = value->getValue();
        int coefficient = coefficient->getValue();
        reduceInsideRoot(primes);
        value.setValue(value);
        coefficient.setValue(value);
    }
    // Add functionality to simplify Rationals.
    if (typeid(value) == RationalNumber) {
        if (typeid(exponent) == Integer) {
            // Square both denominator and numerator
            if (typeid(value->getDenominator()) == Integer) {
                value->getDenominator()->setValue((long)pow(value->getDenominator()->getValue(), exponent.getValue()));
            } else {
                // Convert Denominator to it's own exponential.
            }
            if (typeid(value->getNumerator()) == Integer) {
                value->getNumerator()->setValue((long)pow(value->getNumerator()->getValue(), exponent.getValue()));
            } else {
                // Convert Numerator to it's own exponential.
            }
            // Possibly simplify?
            value->simplify();
        }
        // Edit reduceInsideRoot to be more abstract.
        if (typeid(exponent) == RationalNumber) {
            if (typeid(value->getDenominator()) == Integer) {
                value->getDenominator->setValue((long)pow(value->getDenominator->getValue(), exponent->getNumerator->getValue()));
                vector<int> primes1;
                primes1 = findPrimeFactors(value->getDenominator->getValue(), 2, primes);
            } else {
                // Convert Denominator to it's own exponential.
            }
            if (typeid(value->getNumerator()) == Integer) {
                value->getNumerator->setValue((long)pow(value->getNumerator->getValue(), exponent->getNumerator->getValue()));
                vector<int> primes2;
                primes2 = findPrimeFactors(value->getNumerator->getValue(), 2, primes);
            } else {
                // Convert Numerator to it's own exponential.
            }
            exponent->getNumerator()->setValue(1);
            value->simplify();
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
void Exponential::reduceInsideRoot(int &value, int &coefficient, vector<int> primeFactors) {
    int counter = 1;
    int current = primeFactors[0];
    for (int i = 0; i < primeFactors.size(); i++) {
        if (current == primeFactors[i]) {
            counter++;
        } else {
            current = primeFactors[i];
            counter = 1;
        }
        if (counter == nthRoot) {
            coefficient *= primeFactors[i];
            for (int j = 0; j < nthRoot; j++) {
                value /= primeFactors[i];
            }
            counter = 0;
        }
    }
}
