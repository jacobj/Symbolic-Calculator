/* 
 * File:        Exponential.cpp
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
    this->values["value"] = value;
    this->values["exponent"] = exponent;
    this->values["coefficient"] = coeffient;
}

Exponential::~Exponential() {
    delete values["value"];
    delete values["exponent"];
    delete values["coefficient"];
}

double Exponential::toDouble(){
	//DON'T FORGET return stuff here
}
  
// Simplify method.
void Exponential::simplify() {
    // If the value is an Integer,
    if (typeid(values["value"]) == typeid(Integer)) {
        // If the exponent is a RationalNumber,
        if (typeid(values["exponent"]) == typeid(RationalNumber)) {
            // If the exponent's numerator is an Integer,
            if (typeid(values["exponent"]->getValues()["numerator"]) == typeid(Integer)) {
                // Raise the value to nth power and set the exponent to 1.
                values["value"]->setValue(((long)pow(values["value"]->getValue(), 
                                                     values["exponent"]->getValues()["numerator"]->getValue())));
                // Set the numerator of the exponent to 1, as it has already been raised appropriately.
                values["exponent"]->getValues()["numerator"]->setValue(1);
                // If the exponent's denominator is an Integer,
            }
            if (typeid(values["exponent"]->getValues()["denominator"]) == typeid(Integer)) {
                // Break up value into it's prime factors.
                vector<int> primes; 
                primes = findPrimeFactors(values["value"]->getValue(), 
                                          2, primes);
                // Sort results in descending order.
                sort(primes.begin(), primes.end());
                int value = values["value"]->getValue();
                // If the coefficient is an Integer.
                if (typeid(values["coefficient"]) == typeid(Integer)) {
                    int coefficient = values["coefficient"]->getValue();
                    reduceInsideRoot(value, coefficient, 
                                     values["exponent"]->getValues()["denominator"]->getValue(), primes);
                    // Set value and coeffient to the returned values from reduceInsideRoot.
                    values["value"]->setValue(value);
                    values["coefficient"]->setValue(coefficient);
                }       
            }
            // What if the denominator is not an Integer? For now let's just leave it alone.
        }
    }
    // Else, if the value is a rational
    else if (RationalNumber* valueptr = dynamic_cast<RationalNumber*>(value)) {
        // And the value's numerator of the value is an Integer,
        if (Integer* numeratorptr = dynamic_cast<Integer*>(valueptr->getNumerator())) {
            // And the value's denominator is an Integer,
            if (Integer* denominatorptr = dynamic_cast<Integer*>(valueptr->getDenominator())) {
                // And the exponent is an Integer,
                if (Integer* exponentptr = dynamic_cast<Integer*>(exponent)) {
                    // Square both denominator and numerator.
                    denominatorptr->setValue((long)pow(denominatorptr->getValue(),
                                                       exponentptr->getValue()));
                    numeratorptr->setValue((long)pow(numeratorptr->getValue(),
                                                     exponentptr->getValue()));
                    // Simplify the value using the RationalNumber simplify method.
                    value->simplify();
                }
                // Raise a rational to a rational
                // If the exponent is a rational.
                else if (RationalNumber* exponentptr = dynamic_cast<RationalNumber*>(exponent)) {
                    // If the exponent's numerator is an integer.
                    if (Integer* exponentNumeratorptr = dynamic_cast<Integer*>(exponentptr->getNumerator())) { 
                        // If the exponents's denominator is an Integer.
                        denominatorptr->setValue((long)pow(denominatorptr->getValue(),
                                                           exponentNumeratorptr->getValue()));
                        numeratorptr->setValue((long)pow(numeratorptr->getValue(),
                                                             exponentNumeratorptr->getValue()));
                        exponentNumeratorptr->setValue(1);
                        value->simplify();
                        if (Integer* exponentDenominatorptr = dynamic_cast<Integer*>(exponentptr->getDenominator())) {                    
                            vector<int> primes1;
                            primes1 = findPrimeFactors(denominatorptr->getValue(), 2, primes1); 
                            vector<int> primes2;
                            primes2 = findPrimeFactors(numeratorptr->getValue(), 2, primes2);
                        }
                    } 
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
