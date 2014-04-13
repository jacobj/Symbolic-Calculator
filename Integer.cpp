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

Integer Integer:: operator+(const Integer &integer) {
    Integer temp;
    temp.value = value + integer.value;
    return temp;
}

Integer Integer:: operator-(const Integer &integer) {
    Integer temp;
    temp.value = value - integer.value;
    return temp;
}

Integer Integer:: operator*(const Integer &integer) {
    Integer temp;
    temp.value = value * integer.value;
    return temp;
}

Integer Integer:: operator/(const Integer &integer) {
	Integer temp;
    if (integer.value == 0) {
    	cout << "Cannot divide by 0" << endl;
    	temp.value = 0;
    	return temp;
    }
    temp.value = value / integer.value;
    return temp;
}
 
// The methods below exist only to satisfy Number.h.
map<string, Number*> Integer::getValues() {
    //return NULL;
}

void Integer::setValues(string key, Number* val) {
}

vector<Number*> Integer::getLogValues() {
   // return NULL;
}

void Integer::setLogValues(int index, Number* val) {
}

string Integer::getTranscendentalValue() {
    //return "";
}

void Integer::setTranscendentalValue(string value) {
}

void Integer::simplify() {
}

