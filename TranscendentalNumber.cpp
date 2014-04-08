/* 
 * File:        TranscendentalNumber.cpp
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#include "TranscendentalNumber.h"

using namespace std;

TranscendentalNumber::TranscendentalNumber(enum value, int coefficient) {
  this->value;
  this->coefficient = coefficient;
}

//Get and set methods
enum TranscendentalNumber::getValue() {
  return value;
}
int TranscendentalNumber::getCoefficient() {
  return coefficient;
}
void TranscendentalNumber::setNumerator(enum value) {
  this->value = value;
}
void TranscendentalNumber::setDenominator(int coefficient) {
  this->coefficient = coefficient;
}