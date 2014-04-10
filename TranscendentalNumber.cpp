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

TranscendentalNumber::TranscendentalNumber(enum value, Number coefficient) {
    this->value;
    this->coefficient = coefficient;
}

//Get and set methods
enum NAME TranscendentalNumber::getValue() {
    return value;
}
int TranscendentalNumber::getCoefficient() {
    return coefficient;
}
void TranscendentalNumber::setNumerator(enum value) {
    this->value = value;
}
void TranscendentalNumber::setDenominator(Number coefficient) {
    this->coefficient = coefficient;
}
