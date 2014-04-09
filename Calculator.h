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

#include <vector>

class Calculator {
public:
	Calculator();
	void calculate();

private:
	vector<Number> previousAnswers;
	vector<Number> previousInputs;
};


#endif	/* CALCULATOR_H */

