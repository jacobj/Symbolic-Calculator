#include "Logarithm.h"

using namespace std;

/*
 * TODO: Write a little bit about what this class does in relation to Expression
 */

Logarithm::Logarithm(Number coefficient, vector<Number> values, Number base) {
    this->coefficient = coefficient;
    this->values = values;
    this->base = base;
}

Logarithm::Logarithm(Number coefficient, Number value, Number base) {
    this->coefficient = coefficient;
    // Not sure if this is a proper initialization. We will find out when we build
    this->values.push_back(value);
    this->base = base;
}

Logarithm::~Logarithm() {
    delete coefficient;
    delete values;
    delete base;
}

// Get Methods
Number Logarithm::getCoefficient() {
    return coefficient;
}
vector<Number> Logarithm::getValues() {
    return values;
}
Number Logarithm::getBase() {
    return base;
}

// Set Methods
void Logarithm::setCoefficient(Number coefficient) {
    this->coefficient = coefficient;
}
void Logarithm::setValue(Number value) {
    // not sure if this is the correct way to write this particular set method... seems okay
    this->values.push_back(value);
}
void Logarithm::setValues(vector<Number> values) {
    this->values = values;
}
void Logarithm::setBase(Number base) {
    return base;
}

// Make more general, in case other logs are added.
void Logarithm::simplify() {
    vector<int> primes;
    vector<int> primes = findPrimeFactors(values.[0].getValue(), 2, primes);
    splitLog(primes);
}
void Logarithm::display() {
    // Exists to satisfy Number Parent class. May be needed in the future.
}
double Logarithm::toDouble(){
	//DON'T FORGET return stuff here
}
string Logarithm::toString(){
	//DON'T FORGET THIS, EITHER
}

void Logarithm::splitLog(vector<int> primes) {
    // Not the best way to do this, will be overhauled later.
    values.clear();
    for (int i = 0; i < primes.size(); i++) {
        values.push_back(primes[i]);
    }
}

vector<int> Logarithm::findPrimeFactors(int number, int i, vector<int> primeFactors) {
    if (number < i) {
        return primeFactors;
    } else if (number % i == 0) {
        primeFactors.push_back(i);
        return findPrimeFactors(number / i, 2, primeFactors);
    } else {
        return findPrimeFactors(number, i++, primeFactors);
    }
}
