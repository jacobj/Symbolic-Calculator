/* 
 * File:        Calculator.h
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 *              
 * 
 */

#ifndef CALCULATOR_H
#define	CALCULATOR_H

#include <iostream>
#include <cstdlib>
#include <stack>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Calculator {

private:
	//vector<Number> previousAnswers;
	//vector<Number> previousInputs;
        vector<string> expression;
public:
	//constructor
        Calculator(string);
        
    //function prototypes
    vector<string> getExpressionTokens(string&);
    void getTokensHelper(string);
    bool infixToRPN(vector<string>&, vector<string>&);
    bool isOperator(string);
    bool isParentheses(string);
	int comparePrecedence(string, string);
        
	Calculator();
	void calculate();

};


#endif	/* CALCULATOR_H */

