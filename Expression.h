/*
* File:        Expression.h
*
* Authors:     Brent Lewis
*              Jacob Jenkins
*              Shreya Nirmalan
*              Nicola Frachesen
*              Elaine Del Rosario
*
*
*/

#ifndef EXPRESSION_H
#define	EXPRESSION_H

#include "Number.h"
#include <iostream>
#include <cstdlib>
#include <stack>
#include <list>
#include <string>
#include <vector>

using namespace std;

#include "Calculator.h"

class Expression : public Number {
private:
	vector<string> operators;
	vector<Number*> operands;
public:

	Expression(string);
	// Returns a map of Number pointer properties
	map<string, Number*> getValues();
	void setValues(string key, Number* val);
	void simplify();
	void display();
	double toDouble();
	string toString();
	bool isNumeric(string);
	bool isOperator(string);

	// Used only for Integers
	long getValue();
	void setValue(long value);

	// Used only for Transcendentals
	string getTranscendentalValue();
	void setTranscendentalValue(string value);

	// Used to return vector Log uses to store split logs.
	vector<Number*> getLogValues();
	void setLogValues(int index, Number* val);

	Number* add(Number*);
    Number* subtract(Number*);
    Number* multiply(Number*);
   	Number* divide(Number*);
    Number* exponentiate(Number*);
};

#endif	/* EXPRESSION_H */

