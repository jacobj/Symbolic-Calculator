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

TranscendentalNumber::TranscendentalNumber(String value, Number coefficient) {
    this->value = value;
    this->coefficient = coefficient;
}
TranscendentalNumber::~TranscendentalNumber() {
    delete coefficient;
}

//Get and set methods
String TranscendentalNumber::getValue() {
    return value;
}
int TranscendentalNumber::getCoefficient() {
    return coefficient;
}
void TranscendentalNumber::setValue(String value) {
    this->value = value;
}
void TranscendentalNumber::setCoefficient(Number coefficient) {
    this->coefficient = coefficient;
}
