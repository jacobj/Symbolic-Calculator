/*
* File:        Expression.h
*
* Authors:     Brent Lewis
*              Jacob Jenkins
*              Shreya Nirmalan
*              Nicola Frachesen
*              Elaine Del Rosario
*
*/

#include "Expression.h"

//Constructor
Expression::Expression(string expr){
	string temp;
	for(int i = 0;i < expr.size();i++)
	{
		if(isOperator(expr.substr(i,1)))
			operators.push_back(expr.substr(i,1));
		else if(isNumeric(expr.substr(i,1)))
		{
			operands.push_back(new Integer(expr.substr(i,1)));
		}
		else
		{
			//TODO add logs and sqrt

		}
	}
}

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
	/*vector<Number*> Expression::getLogValues()
	{

	}
	void Expression::setLogValues(int index, Number* val)
	{

	}*/

	Number* Expression::add(Number* val)
	{
		stringstream valStream;
		valStream << toString() << "+" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
    Number* Expression::subtract(Number* val)
    {
		stringstream valStream;
		valStream << toString() << "-" << val->toString();
		string str = valStream.str();
		return new Expression(str);
    }
    Number* Expression::multiply(Number* val)
    {
		stringstream valStream;
		valStream << toString() << "*" << val->toString();
		string str = valStream.str();
		return new Expression(str);
    }
   	Number* Expression::divide(Number* val)
   	{
		stringstream valStream;
		valStream << toString() << "/" << val->toString();
		string str = valStream.str();
		return new Expression(str);
   	}
    Number* Expression::exponentiate(Number* val)
    {
		stringstream valStream;
		valStream << toString() << "^" << val->toString();
		string str = valStream.str();
		return new Expression(str);
    }

    bool Expression::isNumeric(string token)
    {
    	if(token == "1" || token == "2" ||
    	   token == "3" || token == "4" ||
    	   token == "5" || token == "6" ||
    	   token == "7" || token == "8" ||
    	   token == "9" || token == "0")
    		return true;
    	else
    		return false;
    }

    bool Expression::isOperator(string token)
    {
        if( token == "+" || token == "-" ||
            token == "*" || token == "/" ||
            token == "^")
            return true;
        else
            return false;
    }
