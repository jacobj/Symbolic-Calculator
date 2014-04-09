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
#include <stack>
#include <list>
#include <string>
#include <vector>

class Expression{// : public Number {
public:
	//constructor
        Expression(string expr);
	Expression(vector<Number> numbers, vector<char> operators); //may not be needed
        
        //function prototypes
        vector<string> getExpressionTokens(string&);
        void getTokensHelper(string);
        bool infixToRPN(vector<string>&, vector<string>&);
        bool isOperator(string);
        bool isParentheses(string);
        int comparePrecedence(string, string);
        
        
	void addNumber(Number number); //may not be needed
	void addOperator(char operand); //may not be needed
	vector<Numbers> getNumbers(); //may not be needed
	vector<char> getOperators(); //may not be needed
	void setNumbers(vector<Number> numbers); //may not be needed
	void setOperators(vector<char> operators); //may not be needed
	string display();
	void simplify(); //may not be needed

private:
        vector<string> expression;
	vector<Number> numbers; //may not be needed
	vector<char> operators; //may not be needed
};

#endif	/* EXPRESSION_H */

