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

#include <vector>
#include <string>

class Expression : public Number {
public:
	//constructor
	Expression(vector<Number> numbers, vector<char> operators);
	void addNumber(Number number);
	void addOperator(char operand);
	vector<Numbers> getNumbers();
	vector<char> getOperators();
	void setNumbers(vector<Number> numbers);
	void setOperators(vector<char> operators);
	string display();
	void simplify();
	Expression operator+(const Expression& expression);
	Expression operator-(const Expression& expression);
	Expression operator*(const Expression& expression);
	Expression operator/(const Expression& expression);

private:
	vector<Number> numbers;
	vector<char> operators;
};

#endif	/* EXPRESSION_H */

