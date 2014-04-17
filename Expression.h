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
	vector<string> operators;
	vector<string> expression;
	vector<Number*> operands;
	string strExpression;
public:

	Expression(string&);
	// Returns a map of Number pointer properties
	map<string, Number*> getValues();
	vector<string> setExpressionTokens(string&);
	void setValues(string key, Number* val);
	void simplify();
	void display();
	double toDouble();
	string toString();
	bool isNumeric(string);
	bool isOperator(string);
	void addInput(string);

	// Used only for Integers
	long getValue();
	void setValue(long value);
	void calculate();

	// Used only for Transcendentals
	string getTranscendentalValue();
	void setTranscendentalValue(string value);
	void infixToRPN(vector<string>& tokens, vector<string>& rpn);
	int comparePrecedence(string op1, string op2);
	bool isParentheses(string token);

	Number* calculate(Number*, Number*, string);
	Number* assignToClass(string& token);
	Number* add(Number*);
    Number* subtract(Number*);
    Number* multiply(Number*);
   	Number* divide(Number*);
    Number* exponentiate(Number*);
};

#endif	/* EXPRESSION_H */

