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
#include "Integer.h"
#include "TranscendentalNumber.h"
#include "Exponential.h"
#include "Logarithm.h"
#include "RationalNumber.h"

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
	vector<string> expression;
	vector<string> operators;

	vector<Number*> operands;

	string strExpression;

public:

	Expression(string&);
	// Returns a map of Number pointer properties
	map<string, Number*> getValues();

	vector<string> setExpressionTokens(string&);
	vector<string> getOperators();
	vector<Number*> getOperands();

	void infixToRPN(vector<string>& tokens, vector<string>& rpn);
	void setValues(string key, Number* val);
	void addInput(string);
	void simplify();
	void display();
	void sort();

	double toDouble();
	string toString();

	bool isNumeric(string);
	bool isOperator(string);
	bool isParentheses(string token);

	int comparePrecedence(string op1, string op2);

	// Used only for Integers
	long getValue();
	void setValue(long value);

	// Used only for Transcendentals
	string getTranscendentalValue();
	void setTranscendentalValue(string value);

	Number* calculate(Number*, Number*, string);
	Number* assignToClass(string& token);
	Number* add(Number*);
    Number* subtract(Number*);
    Number* multiply(Number*);
   	Number* divide(Number*);
    Number* exponentiate(Number*);
};

#endif	/* EXPRESSION_H */

