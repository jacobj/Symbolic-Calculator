#include "Logarithm.h"

using namespace std;

Logarithm::Logarithm(int coefficient, Number base) {
  this->coefficient = coefficient;
  this->base = base;
}

// Damn, this might need to return an Expression. Might need to retool some definitions
// of Expressions and Logs.
void Logarithm::simplify() {
  vector<int> primes = findPrimeFactors();
  splitLog(primes);
}

Expression Logarithm::splitLog(vector<int> primes) {
  Expression e;
  for (int i = 0; i < primes.size(); i++) {
    Logarithm l;
    l.setBase(base);
    l.setCoefficient(primes[i]);
    e.add(l);
  }
  return e;
}
