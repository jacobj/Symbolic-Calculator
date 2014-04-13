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
#include <sstream>
#include <cmath>

#include "Integer.h"

using namespace std;

class Calculator
{
private:
	vector<Number*> previousA;
	vector<Number*> expressionB;
	vector<string> previousAnswers;
	vector<string> previousInputs;
    vector<string> expression;
public:
	//constructors
	Calculator();
    Calculator(string);
        
    //function prototypes

    vector<string> getPreviousInputs();
    vector<string> getPreviousAnswers();
    vector<string> getExpression();
    vector<string> setExpressionTokens(string&);

    Number* calculate(Number*, Number*, string);
    Number* assignToClass(string&);

    bool isNumeric(string);
    bool addInput(string);
    bool infixToRPN(vector<string>&, vector<string>&);
    bool isOperator(string);
    bool isParentheses(string);
    
    void calculate();

    string getLatestAnswer();
    
	int comparePrecedence(string, string);
	
	

};


#endif	/* CALCULATOR_H */


