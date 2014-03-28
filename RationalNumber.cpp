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

RationalNumber::RationalNumber(Number *numerator, Number *denominator) {
  this->numerator = numerator;
  this->denominator = denominator
}

RationalNumber::~RationalNumber() {
  delete numerator;
  delete denominator;
}

// Simplify helper method.
void RationalNumber::simplify() {
  // Simplify coefficients first
  int gcd = simplify(denominator.getCoefficient(), numerator.getCoefficient());
  denominator.setCoefficient(denominator.getCoefficient() / gcd);
  numerator.setCoefficient(numerator.getCoefficient() / gcd);
  /*
   * If both the denominator and numerator are transcendental numbers and both
   * contain the same value, then cancel them out.
   */
  if (typeid(denominator) == TranscendentalNumber && 
      typeid(numerator) == TranscendentalNumber) {
    if (denominator.getValue() == numerator.getValue()) {
      // Then thise values cancel
      denominator = new Integer(denominator.getCoefficient());
      numerator = new Integer(numerator.getCoefficient());
      return;
    }
    return;
  }
  if (typeid(denominator) == nthRootIrrational && 
      typeid(numerator) == nthRootIrrational) {
    /*
     * If both the denominator and numerator are logarithms and both
     * contain the same value and nthRoot, then cancel them out.
     */
    if (denominator.getValue() == numerator.getValue() 
        && denominator.getNthRoot() == numerator.getNthRoot()) {
      denominator = new Integer(denominator.getCoefficient());
      numerator = new Integer(numerator.getCoefficient());
    }
    return;
  }
  if (typeid(denominator) == Logarithm && typeid(numerator) == Logarithm) {
    /*
     * If both the denominator and numerator are logarithms and both
     * contain the same value and base, then cancel them out.
     */
    if (denominator.getValue() == numerator.getValue() 
        && denominator.getBase() == numerator.getBase()) {
      denominator = new Integer(denominator.getCoefficient());
      numerator = new Integer(numerator.getCoefficient());
    }
    return;
  }
  return;
}

// Use euclid's algorithm
int RationalNumber::simplify(int a, int b) {
  if (b == 0)
    return a;
  else 
    return gcd(b, a % b);
}
