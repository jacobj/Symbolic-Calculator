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
Expression::Expression(string expr){
	operators.push_back(expr);
}


/*Expression::Expression(vector<Number> numbers, vector<char> operators) {
	this->numbers = numbers;
	this->operators = operators;
}*/

// Returns a map of Number pointer properties
	map<string, Number*> Expression::getValues()
	{

	}
	void Expression::setValues(string key, Number* val)
	{

	}
	void Expression::simplify()
	{

	}
	void Expression::display()
	{

	}
	double Expression::toDouble()
	{

	}
	string Expression::toString()
	{

	}

	// Used only for Integers
	long Expression::getValue()
	{

	}
	void Expression::setValue(long value)
	{

	}

	// Used only for Transcendentals
	string Expression::getTranscendentalValue()
	{

	}
	void Expression::setTranscendentalValue(string value)
	{

	}

	// Used to return vector Log uses to store split logs.
	vector<Number*> Expression::getLogValues()
	{

	}
	void Expression::setLogValues(int index, Number* val)
	{

	}
	
	Number* Expression::add(Number* val)
	{
	}
    Number* Expression::subtract(Number* val)
    {
    }
    Number* Expression::multiply(Number* val)
    {
    }
   	Number* Expression::divide(Number* val)
   	{
   	}
    Number* Expression::exponentiate(Number* val)
    {
    }


