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
	vector<string> previousAnswers;
	vector<Number*> previousA;
	vector<string> previousInputs;
    vector<string> expression;
    vector<Number*> expressionB;
public:
	//constructors
	Calculator();
    Calculator(string);
        
    //function prototypes
    

    vector<string> getPreviousInputs();
    vector<string> getPreviousAnswers();
    vector<string> getExpression();
    vector<string> setExpressionTokens(string&);
    
    Number* assignToClass(string&);//, vector<Number*>);
    bool isNumeric(string);
    bool addInput(string);
    
    //double RPNtoDouble( vector<string> tokens );
    void calculate();
    string getLatestAnswer();
    
    bool infixToRPN(vector<string>&, vector<string>&);
    bool isOperator(string);
    bool isParentheses(string);
    
	int comparePrecedence(string, string);
	
	

};


#endif	/* CALCULATOR_H */


