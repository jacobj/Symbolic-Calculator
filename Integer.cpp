/*
 * File:        Integer.h
 *
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 *
 *
 */

#include "Integer.h"

// Constructor
Integer::Integer(long val) {
    this->value = value;
}

Integer::Integer(string val){
	const long d2 = strtol( val.c_str(), NULL ,0);
	this->value = d2;

}
Integer::Integer() {
    this->value = 0;
}

// Get-Set methods
long Integer::getValue() {
    return value;
}

void Integer::setValue(long val) {
    this->value = val;
}

void Integer::display() {
    // Implement this.
}

double Integer::toDouble(){
	// get method can also be used here if double value not needed
	return (double) value;
}
string Integer::toString(){
	stringstream valueStream;
	valueStream << value;
	string str = valueStream.str();
	return str;
}

 
// The methods below exist only to satisfy Number.h.
map<string, Number*> Integer::getValues() {
    //return NULL;
}

void Integer::setValues(string key, Number* val) {
}

// vector<Number*> Integer::getLogValues() {
//    // return NULL;
// }

// void Integer::setLogValues(int index, Number* val) {
// }

string Integer::getTranscendentalValue() {
    //return "";
}

void Integer::setTranscendentalValue(string value) {
}

void Integer::simplify() {
}

Number* Integer::add(Integer* val){
	//this->value += val->value;
	//return new Integer(this->toString());
}

Number* Integer::add(Number* val)
{
	if (typeid(*val) == typeid(Integer)) {
		this->value += val->getValue();
		Number* result = new Integer(this->toString());
        return result;
	}
}
Number* Integer::subtract(Number* val)
{
	if (typeid(*val) == typeid(Integer)) {
        this->value -= val->getValue();
        Number* result = new Integer(this->toString());
        return result;
    }
}
Number* Integer::multiply(Number* val)
{
    if (typeid(*val) == typeid(Integer)) {
        this->value *= val->getValue();
        Number* result = new Integer(this->toString());
        return result;
    }
    // Add cases where this multiplies into coefficients
}
Number* Integer::divide(Number* val)
{
    if (typeid(*val) == typeid(Integer)) {
        if (this->value % val->getValue() == 0) {
            this->value /= val->getValue();
            Number* result = new Integer(this->toString());
            return result;
        }
    }
    // Add cases where this divides out coefficients
    else {
        // Make sure this pointer is generic first
        Number* numerator = this;
        Number* result = new RationalNumber(this, val);
        return result;
    }
}
Number* Integer::exponentiate(Number* val)
{

}
