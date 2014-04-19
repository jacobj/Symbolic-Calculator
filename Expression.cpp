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
Expression::Expression(string& expr){
	strExpression = expr;
	addInput(strExpression);
	sort();


	/*for(int i = 0;i<expr.size();i++)
	{
		int pos = expr.find_first_of("+-/*");

		if(pos == -1)
		{
			string exception = "ERROR! This isn't a log! \n";
			throw exception;
		}

		string op(1, expr[pos]);
		string term = expr.substr(0, pos);
		string secondTerm = expr.substr(pos+1, expr.size());
	

		operators.push_back(op);
		term = expr.substr(0, pos);
		secondTerm = expr.substr(pos+1, expr.size());

		if(term.find_first_of("^") != -1)
		{
			operands.push_back(new Exponential(term));
		}
		else if(term.find_first_of(":") != -1)
		{
			operands.push_back(new Logarithm(term));
		}
		else if(term.find_first_of("e") != -1)
		{
			operands.push_back(new TranscendentalNumber(term));
		}
		else if(term.find_first_of("p") != -1)
		{
			operands.push_back(new TranscendentalNumber(term));
		}
		else
		{
			operands.push_back(new Integer(term));
		}

		if(secondTerm.find_first_of("^") != -1)
		{
			operands.push_back(new Exponential(secondTerm));
		}
		else if(secondTerm.find_first_of(":") != -1)
		{
			operands.push_back(new Logarithm(secondTerm));
		}
		else if(secondTerm.find_first_of("e") != -1)
		{
			operands.push_back(new TranscendentalNumber(secondTerm));
		}
		else if(secondTerm.find_first_of("p") != -1)
		{
			operands.push_back(new TranscendentalNumber(secondTerm));
		}
		else
		{
			operands.push_back(new Integer(secondTerm));
		}
	}*/
}

// Returns a map of Number pointer properties
	map<string, Number*> Expression::getValues()
	{

	}
		void Expression::setValues(string key, Number* val)
	{

	}
	void Expression::simplify(){}
	double Expression::toDouble()
	{
			 stack<double> st;
		     double val1b;
		     double val2b;
		     double result = 0.0;

		     // For each token
		     for ( int i = 0; i < (int) expression.size(); ++i )
		     {
		        	const string token = expression[ i ];

		            // If the token is a value push it onto the stack
		            if ( !isOperator(token) )
		            {
		            	Number *token2 = assignToClass(expression[i]);
		                st.push(token2->toDouble());
		            }
		            else
		            {

		                // Token is an operator: pop top two entries
		                val2b = st.top();
		                st.pop();

		               if ( !st.empty() )
		                {
		                	val1b = st.top();
		                	st.pop();

		                	//Get the result
		                	result = token == "+" ? val1b + val2b :
		                			 token == "-" ? val1b - val2b :
		                		     token == "*" ? val1b * val2b :
		                             token == "/" ? val1b / val2b :
		                                        pow(val1b, val2b);
		                }
		                else
		                {
		                	if ( token == "-" )
		                		result = val2b * -1;
		                	else
		                		result = val2b;
		                }
		                // Push result onto stack
		                st.push(result);

		            }
		        }
		     return st.top();
	}
	string Expression::toString()
	{
		stringstream temp;
		for(int i = 0;i<operands.size();i++)
		{
			if(operators[i] != "0")
				temp << operators[i];
			temp << operands[i]->toString();
		}
		return strExpression = temp.str();
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

	Number* Expression::add(Number* val)
	{
		if (typeid(*val) == typeid(Integer))
		{
			for(int i = 0; i < operands.size(); i++)
			{
				if(typeid(*operands[i]) == typeid(Integer))
				{
					operands[i] = calculate(operands[i],val,"+");
				}
			}
		}
		else if (typeid(*val) == typeid(TranscendentalNumber))
		{
			for(int i = 0; i < operands.size(); i++)
			{
				if(typeid(*operands[i]) == typeid(TranscendentalNumber))
				{
					operands[i] = calculate(operands[i],val,"+");
				}
			}
		}
		else if (typeid(*val) == typeid(RationalNumber))
		{
			for(int i = 0; i < operands.size(); i++)
			{
				if(typeid(*operands[i]) == typeid(RationalNumber))
				{
					operands[i] = calculate(operands[i],val,"+");
				}
			}
		}
		/*else if (typeid(*val) == typeid(RationalNumber)){
			stringstream RatNumStream;
			RatNumStream << getValue() << "/1";
			string str = RatNumStream.str();
			Number* RatNum = new RationalNumber(str);
			return RatNum->add(val);
		}
		else{
			stringstream valStream;
			valStream << toString() << "+" << val->toString();
			string str = valStream.str();
			return new Expression(str);
		}*/
		return this;
	}

    Number* Expression::subtract(Number* val)
    {
    	if (typeid(*val) == typeid(Integer))
    			{
    				for(int i = 0; i < operands.size(); i++)
    				{
    					if(typeid(*operands[i]) == typeid(Integer))
    					{
    						operands[i] = calculate(operands[i],val,"-");
    					}
    				}
    			}
    			else if (typeid(*val) == typeid(TranscendentalNumber))
    			{
    				for(int i = 0; i < operands.size(); i++)
    				{
    					if(typeid(*operands[i]) == typeid(TranscendentalNumber))
    					{
    						operands[i] = calculate(operands[i],val,"-");
    					}
    				}
    			}
    			/*else if (typeid(*val) == typeid(RationalNumber)){
    				stringstream RatNumStream;
    				RatNumStream << getValue() << "/1";
    				string str = RatNumStream.str();
    				Number* RatNum = new RationalNumber(str);
    				return RatNum->add(val);
    			}
    			else{
    				stringstream valStream;
    				valStream << toString() << "+" << val->toString();
    				string str = valStream.str();
    				return new Expression(str);
    			}*/
    			return this;
    }
    Number* Expression::multiply(Number* val)
    {
    	if (typeid(*val) == typeid(Integer))
    			{
    				for(int i = 0; i < operands.size(); i++)
    				{
    					if(typeid(*operands[i]) == typeid(Integer))
    					{
    						operands[i] = calculate(operands[i],val,"*");
    					}
    				}
    			}
    			else if (typeid(*val) == typeid(TranscendentalNumber))
    			{
    				for(int i = 0; i < operands.size(); i++)
    				{
    					if(typeid(*operands[i]) == typeid(TranscendentalNumber))
    					{
    						operands[i] = calculate(operands[i],val,"*");
    					}
    				}
    			}
    			/*else if (typeid(*val) == typeid(RationalNumber)){
    				stringstream RatNumStream;
    				RatNumStream << getValue() << "/1";
    				string str = RatNumStream.str();
    				Number* RatNum = new RationalNumber(str);
    				return RatNum->add(val);
    			}
    			else{
    				stringstream valStream;
    				valStream << toString() << "+" << val->toString();
    				string str = valStream.str();
    				return new Expression(str);
    			}*/
    			return this;
    }
   	Number* Expression::divide(Number* val)
   	{
   		if (typeid(*val) == typeid(Integer))
   				{
   					for(int i = 0; i < operands.size(); i++)
   					{
   						if(typeid(*operands[i]) == typeid(Integer))
   						{
   							operands[i] = calculate(operands[i],val,"/");
   						}
   					}
   				}
   				else if (typeid(*val) == typeid(TranscendentalNumber))
   				{
   					for(int i = 0; i < operands.size(); i++)
   					{
   						if(typeid(*operands[i]) == typeid(TranscendentalNumber))
   						{
   							operands[i] = calculate(operands[i],val,"/");
   						}
   					}
   				}
   				/*else if (typeid(*val) == typeid(RationalNumber)){
   					stringstream RatNumStream;
   					RatNumStream << getValue() << "/1";
   					string str = RatNumStream.str();
   					Number* RatNum = new RationalNumber(str);
   					return RatNum->add(val);
   				}
   				else{
   					stringstream valStream;
   					valStream << toString() << "+" << val->toString();
   					string str = valStream.str();
   					return new Expression(str);
   				}*/
   				return this;
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
    	string onesDigit = token.substr(0,1);
    	if(onesDigit == "1" || onesDigit == "2" ||
			onesDigit == "3" || onesDigit == "4" ||
			onesDigit == "5" || onesDigit == "6" ||
			onesDigit == "7" || onesDigit == "8" ||
			onesDigit == "9" || onesDigit == "0" ||
			onesDigit == "e" || onesDigit == "p" ||
			onesDigit == "pi" || onesDigit == "l")
    		return true;
    	else
    		return false;
    }

    bool Expression::isOperator(string token)
    {
        if( token == "+" || token == "-" ||
            token == "*" || token == "/" ||
            token == "^" || token == ":")
            return true;
        else
            return false;
    }

void Expression::infixToRPN(vector<string>& tokens, vector<string>& rpn)
{
	bool success = true;

	stack<string>stack;
	list<string>out;

	for(int i = 0; i <tokens.size();i++)
	{
		string token = tokens[i];

		if( isOperator( token ))
		{
			string o1 = token;
			if(token != ":")
			{

			if( !stack.empty() )
			{
				string o2 = stack.top();
				while( isOperator( o2 ) &&
					   (comparePrecedence(o1, o2) == 0 ||
					   comparePrecedence(o1, o2) == -1))
				{
					stack.pop();
					out.push_back( o2 );

					if ( !stack.empty() )
						o2 = stack.top();

					else
						break;
				}
			}
				stack.push(o1);
			}
			else
				stack.push( o1 );
		}
		else if ( token == "(" )
		{
			// Push token to top of the stack
			stack.push( token );
		}
		else if ( token == ")" )
		{
			// Until the token at the top of the stack is a left parenthesis,
			// pop operators off the stack onto the output queue.
			string topToken  = stack.top();

			while ( topToken != "(" )
			{
				out.push_back(topToken );
				stack.pop();

				if ( stack.empty() )
					break;

				topToken = stack.top();
			}

			// Pop the left parenthesis from the stack, but not onto the output queue.
			if ( !stack.empty() )
				stack.pop();

			// If the stack runs out without finding a left parenthesis,
			// then there are mismatched parentheses.
			if ( topToken != "(" )
			{
				//return false;
			}
		}
		else if(isNumeric(token))
		{
			out.push_back( token );
		}
		//TODO will handle pi, e, log, etc.
		else
		{

		}
	}

	while ( !stack.empty() )
	{
		string stackToken = stack.top();

		// If the operator token on the top of the stack is a parenthesis,
		// then there are mismatched parentheses.
		if ( isParentheses( stackToken )   )
		{
			success = false;
		   // return success;
		}

		// Pop the operator onto the output queue./
		out.push_back( stackToken );
		stack.pop();
	}

	rpn.assign( out.begin(), out.end() );

	//return success;
}

void Expression::sort()
{

     // For each token
     for ( int i = 0; i < (int) expression.size(); ++i )
     {
        	const string token = expression[ i ];

            // If the token is a value push it onto the stack
            if ( !isOperator(token) )
            {
            	operands.push_back(assignToClass(expression[i]));
                if(i == 0)
                {
                	operators.push_back("0");
                }
            }
            else
            {
                operators.push_back(token);
            }
      }
}

Number* Expression::calculate(Number* num1, Number* num2, string op)
{
	Number* result;
	Number *n1 = NULL, *n2 = NULL;
	stringstream logStream;
	string log;

	//determine type of num1
	if(typeid(*num1) == typeid(Integer))
		n1 = new Integer(num1->toString());

	else if(typeid(*num1) == typeid(TranscendentalNumber))
		n1 = new TranscendentalNumber(num1->toString());

	else if(typeid(*num1) == typeid(RationalNumber))
		n1 = new RationalNumber(num1->toString());

	else if(typeid(*num1) == typeid(Exponential))
		n1 = new Exponential(num1->toString());

	else if(typeid(*num1) == typeid(Logarithm))
		n1 = new Logarithm(num1->toString());
	else
	{
		string temp = num1->toString();
		n1 = new Expression(temp);
	}

	//determine type of num2
	if(typeid(*num2) == typeid(Integer))
		n2 = new Integer(num2->toString());

	else if(typeid(*num2) == typeid(TranscendentalNumber))
		n2 = new TranscendentalNumber(num2->toString());

	else if(typeid(*num2) == typeid(RationalNumber))
		n2 = new RationalNumber(num2->toString());

	else if(typeid(*num2) == typeid(Exponential))
		n2 = new Exponential(num2->toString());

	else if(typeid(*num2) == typeid(Logarithm))
		n2 = new Logarithm(num2->toString());
	else
	{
		string temp = num2->toString();
		n2 = new Expression(temp);
	}

	if(op == "+")
		result = n1->add(n2);
	else if(op == "-")
		result = n1->subtract(n2);
	else if(op == "*")
			result = n1->multiply(n2);
	else if(op == "/")
			result = n1->divide(n2);
	else if(op == "^")
			result = n1->exponentiate(n2);
	else if(op == ":")
	{
		logStream << "log_" << n1->toString() << op << n2->toString();
		log = logStream.str();
		return new Logarithm(log);
	}

	return result;
}

vector<string> Expression::setExpressionTokens(string& expr)
{
    vector<string> tokens;
    string str = "";

    for(int i = 0; i < (int) expr.length();i++)
    {
        string token(1,expr[i]);

        if(isOperator(token) || isParentheses(token))
        {
            if(!str.empty())
            {
                tokens.push_back(str);
            }
            str = "";
            tokens.push_back(token);
        }
        else if(isNumeric(token))
        {
        	if(token == "p")
        		token = token + (expr[++i]);
        	else if(token == "l")
        	{
        		token = "";
        	}


        	str.append(token);
        }
        else
        {
        	if(str != "")
        	{
        		if(token == "p")
        		{
        			token = token + (expr[++i]);
        			str.append(token);
        		}
        		else
        		{
        			tokens.push_back(str);
        			str = "";
        		}
        	 }
        }

    }
    if(tokens.empty())
    	return tokens;
    else
    {
    	tokens.push_back(str);
    	return tokens;
    }
}

void Expression::addInput(string exp)
{
	bool success = true;
    vector<string> temp = setExpressionTokens(exp);

     infixToRPN(temp, expression);

}

Number* Expression::assignToClass(string& token)
{
	Number *temp;

	if(isNumeric(token))
	{
		//if(token == "e" || token == "pi")
		if(token.find_first_of("pe") != -1)
			temp = new TranscendentalNumber(token);
		else
			temp = new Integer(token);
	}
	return temp;
}

int Expression::comparePrecedence(string op1, string op2)
{
	//if both operators are the same
	//return 0 for equal precedence
    if(op1.compare(op2) == 0)
        return 0;

    if(op1 == "^")
        return 1;

    else if(op1 == "*" || op1 == "/")
    {
        if(op2 == "^")
            return -1;
        else
            return 1;
    }
    else
        return -1;
}

bool Expression::isParentheses(string token)
{
    if(token == "(" || token == ")")
        return true;
    else
        return false;
}
void Expression::display(){}
