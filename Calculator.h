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

using namespace std;

class Calculator
{
private:
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
    
    void addInput(string);
    
    //double RPNtoDouble( vector<string> tokens );
    void calculate();
    
    bool infixToRPN(vector<string>&, vector<string>&);
    bool isOperator(string);
    bool isParentheses(string);
    
	int comparePrecedence(string, string);
	
	

};


#endif	/* CALCULATOR_H */


