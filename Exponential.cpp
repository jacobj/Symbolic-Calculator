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

#include "nthRootIrrational.h"

using namespace std;

Exponential::Exponential(Number* value, Number* exponet, Number* coefficient) {
    this->value = value;
    this->exponet = exponet;
    this->coefficient = coefficient;
}

Exponential::~Exponential() {
    delete value;
    delete exponet;
    delete coefficient;
}

Number Exponential::getValue() {
    return value;
}

Number Exponential::getExponet() {
    return base;
}

Number nthRootIrrational::getCoefficient() {
    return coefficient;
}

void nthRootIrrational::setValue(Number value) {
    this->value = value;
}

void nthRootIrrational::setExponet(int base) {
    this->base = base;
}

void nthRootIrrational::setCoefficient(Number coefficient) {
    this->coefficient = coefficient;
}
  
// Simplify method.
void nthRootIrrational::simplify() {
    if (typeid(value) == Integer && typeid(exponet) == RationalNumber) {
        value.setValue((long)pow(value.getValue(), exponet.getNumerator()));
        exponet.setValue(1);
        vector<int> primes; 
        primes = findPrimeFactors(value->getValue(), 2, primes);
        // Sort results in descending order. rend().
        sort(primes.begin(), primes.end());
        reduceInsideRoot(primes);
    }
    // Add functionality to simplify Rationals.
}

// Find the primes. Helper method.
vector<int> nthRootIrrational::findPrimeFactors(int number, int i, vector<int> primeFactors) {
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
void nthRootIrrational::reduceInsideRoot(vector<int> primeFactors) {
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
            coefficient.setValue(coefficient.getValue() * primeFactors[i]);
            for (int j = 0; j < nthRoot; j++) {
                value.setValue(value.getValue() / primeFactors[i]);
            }
            counter = 0;
        }
    }
}
