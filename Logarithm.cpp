#include "Logarithm.h"

using namespace std;

Logarithm::Logarithm(int coefficient, vector<int> values, Number base) {
  this->coefficient = coefficient;
  this->values = values;
  this->base = base;
}

Logarithm::Logarithm(int coefficient, int value, Number base) {
  this->coefficient = coefficient;
  // Not sure if this is a propper initialization. We will find out when we build
  this->values.push_back(value);
  this->base = base;
}

// Make more general, in case other logs are added.
void Logarithm::simplify() {
  vector<int> primes;
  vector<int> primes = findPrimeFactors(values.[0], 2, primes);
  splitLog(primes);
}

void Logarithm::splitLog(vector<int> primes) {
  // Not the best way to do this, will be overhauled later.
  values.clear()
  for (int i = 0; i < primes.size(); i++) {
    values.push_back(primes[i])
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
