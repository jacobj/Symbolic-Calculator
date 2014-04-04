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

nthRootIrrational::nthRootIrrational(int value, int base, int coefficient) {
  this->value = value;
  this->base = base;
  this->coefficient = coefficient;
}

// Simplify method.
void nthRootIrrational::simplify() {
  vector<int> primes; 
  primes = findPrimeFactors(value, 2, primes);
  // Sort results in descending order. rend().
  sort(primes.begin(), primes.end());
  reduceInsideRoot(primes);
}

// TODO: Possibly rename methods below.

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
      counter = 1
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
