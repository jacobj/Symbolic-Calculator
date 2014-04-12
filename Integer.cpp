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
Integer::Integer(long value) {
    this->value = value;
}

Integer::Integer() {
    this->value = 0;
}

// Get-Set methods
long Integer::getValue() {
    return value;
}

void Integer::setValue(long value) {
    this->value = value;
}

void Integer::display() {
    // Implement this.
}

double Integer::toDouble(){
	// get method can also be used here if double value not needed
	return (double) value;
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
  
   /* try {
        	Integer temp;
        	if (integer.value == 0) {
            	throw invalid_argument("Cannot divide by 0!");
            	cout << "Cannot divide by 0" << endl;
       	 	}
       	 }
    catch (invalid_argument &ex) {
            	cerr << ex.what() << endl;
        }*/
 
// The methods below exist only to satisfy Number.h.
unordered_map<string, Number*>* Integer::getValues() {
    return NULL;
}

void setValues(string key, Number* val) {
    return;
}

vector<Number*> getLogValues() {
    return NULL;
}

string Integer::getTranscendentalValue() {
    return "";
}

void Integer::setTranscendentalValue(string value) {
    return;
}

void Integer::simplify() {
    return;
}
