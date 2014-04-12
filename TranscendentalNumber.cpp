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

TranscendentalNumber::TranscendentalNumber(string value, Number* coefficient) {
    this->value = value;
    this->coefficient = coefficient;
}
TranscendentalNumber::~TranscendentalNumber() {
    delete coefficient;
}

//Get and set methods
string TranscendentalNumber::getValue() {
    return value;
}
Number * TranscendentalNumber::getCoefficient() {
    return coefficient;
}
void TranscendentalNumber::setValue(string value) {
    this->value = value;
}
void TranscendentalNumber::setCoefficient(Number* coefficient) {
    this->coefficient = coefficient;
}

void TranscendentalNumber::simplify() {
    // Exists to satisfy Number Parent class.
}

void TranscendentalNumber::display() {
    // Exists to display Number Parent class.
	//Please call getValue() to return pi or e.
}
double TranscendentalNumber::toDouble(){
	//Coefficient is currently a number, so I am weary of its implmentation here,
	//as it requires very good operator overloading.
	//If we run out of time, consider changing back to int for simplicity.
	if (!value.compare("pi") || !value.compare("PI")){
		return /*coefficient*/3.14;
	}
	else if(!value.compare("e")){
		return /*coefficient*/2.72;
	}
	else{
	    return 0;
	}
}
string TranscendentalNumber::toString(){
	//Yea... hm... how to deal with this coefficient...
	return /*coefficient*/value
}
