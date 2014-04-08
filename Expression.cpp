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

#include "Expression.h"

//Constructor
Expression::Expression(vector<Number> numbers, vector<char> operators) {
	this->numbers = numbers;
	this->operators = operators;
}

//Adds a number object to the numbers vector
void Expression::addNumber(Number number) {
	numbers.push_back(number);
}
//Adds an operator to the operators vector
void Expression::addOperator(char operand) {
	operators.push_back(operand);
}

//Get-Set methods
vector<Number> Expression::getNumbers() {
	return numbers;
}
vector<char> Expression::getOperators() {
	return operators;
}
void Expression::setNumbers(vector<Number> numbers) {
	this->numbers = numbers;
}
void Expression::setOperators(vector<char> operators) {
	this->operators = operators;
}

//displays expression as a string
string Expression::display() {
	//Exists to satisfy Number parent class
}

//Simplifies the expression by combining like terms
void Expression::simplify() {
	//Exists to satisfy the Number Parent Class
}