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
	simplify();
}

void Expression::simplify()
{
	vector<Number*> tempOperands;
	vector<string> tempOperators;

	if(operands.size() > 1)
	{
		for(int i = 0; i < operands.size();i++)
		{
			if(operands [i] != NULL)
			{
				for(int j = i+1; j < operands.size();j++)
				{
					if(typeid(*operands[i]) == typeid(*operands[j]))
					{
						if(typeid(*operands[i]) == typeid(TranscendentalNumber))
						{
							if(operands[i]->getTranscendentalValue().compare(operands[j]->getTranscendentalValue()) == 0)
							{
								if(operators[i].compare(operators[j]) == 0)
								{
									operands[i] = calculate(operands[i],operands[j],"+");
								}
								else
								{
									if(operators[i] == "+")
									{
										operands[i] = calculate(operands[i],operands[j],"-");
									}
									else
									{
										operands[i] = calculate(operands[j],operands[i],"-");
									}
								}
								if(typeid(*operands[i]) != typeid(Integer))
								{
									if( operands[i]->getValues()["coefficient"]->getValue() < 0)
									{
										Number *temp = new Integer("-1");
										operands[i] = calculate(operands[i],temp,"*");
										operators[i]="-";
									}
								}
								operands[j] = NULL;
							}
						}
						else
						{
							if(operators[i].compare(operators[j]) == 0)
							{
								operands[i] = calculate(operands[i],operands[j],"+");
								operands[j] = NULL;
							}
							else
							{

							}
						}
					}
				}
				tempOperands.push_back(operands[i]);
				tempOperators.push_back(operators[i]);
			}
		}

		operands = tempOperands;
		operators = tempOperators;

		for(int i = 1;i<operands.size()-1;i++)
		{
			if(operands[i]->toString().compare("0") == 0)
			{
				for(int j = i;j<operands.size()-1;j++)
				{
					operands[j] = operands[j+1];
					operators[j] = operators[j+1];
				}
				operands.pop_back();
				operators.pop_back();
			}
		}

	}
	if(operands.back()->toString().compare("0") == 0)
	{
		operands.pop_back();
		operators.pop_back();
	}

	if(operands.front()->toString().compare("0") == 0)
	{
		if(operators.front().compare("-") == 0)
			operators[0] = "0";

		for(int i = 0;i<operands.size()-1;i++)
		{
			operands[i] = operands[i+1];
		}
		if(operators[1].compare("+") == 0)
		{
			for(int i = 1;i<operators.size()-1;i++)
				operators[i] = operators[i+1];
		}
		else
		{
			for(int i = 0;i<operators.size()-1;i++)
					operators[i] = operators[i+1];
		}
		operands.pop_back();
		operators.pop_back();
	}

}
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

Number* Expression::add(Number* val)
{
	bool matchFound = false;
	if (typeid(*val) == typeid(Integer))
	{
		for(int i = 0; i < operands.size(); i++)
		{
			if(typeid(*operands[i]) == typeid(Integer))
			{
				matchFound = true;
				if(i > 0)
					operands[i] = calculate(operands[i],val,operators[i]);
				else
				{
					if(operators[i] == "0")
						operands[i] = calculate(operands[i],val,"+");
					else
						operands[i] = calculate(operands[i],val,operators[i]);
				}
				if(operands[i]->getValue() < 0)
				{
					if(i > 0)
					{
						Number *temp = new Integer("-1");
						operands[i] = calculate(operands[i],temp,"*");
						operators[i]="+";
					}
					else
					{
						Number *temp = new Integer("-1");
						operands[i] = calculate(operands[i],temp,"*");
						operators[i]="0";
					}
				}
			}
		}
	}
	else if (typeid(*val) == typeid(TranscendentalNumber))
	{
		for(int i = 0; i < operands.size(); i++)
		{
			if(typeid(*operands[i]) == typeid(TranscendentalNumber))
			{
				if(operands[i]->getTranscendentalValue() == val->getTranscendentalValue())
				{
					matchFound = true;
					if(i > 0)
						operands[i] = calculate(operands[i],val,operators[i]);
					else
					{
						if(operators[i] == "0")
							operands[i] = calculate(operands[i],val,"+");
						else
							operands[i] = calculate(operands[i],val,operators[i]);
					}
					if(typeid(*operands[i]) != typeid(Integer))
					{
						if(operands[i]->getValues()["coefficient"]->getValue() < 0)
						{
							if(i>0)
							{
								Number *temp = new Integer("-1");
								operands[i] = calculate(operands[i],temp,"*");
								operators[i]="+";
							}
							else
							{
								Number *temp = new Integer("-1");
								operands[i] = calculate(operands[i],temp,"*");
								operators[i]="+";
							}
						}
					}
				}
			}
		}
	}
	else if (typeid(*val) == typeid(RationalNumber))
	{
		for(int i = 0; i < operands.size(); i++)
		{
			if(typeid(*operands[i]) == typeid(Integer))
			{
				matchFound = true;
				if(i > 0)
					operands[i] = calculate(operands[i],val,operators[i]);
				else
				{
					if(operators[i] == "0")
						operands[i] = calculate(operands[i],val,"+");
					else
						operands[i] = calculate(operands[i],val,operators[i]);
				}
				if(operands[i]->getValue() < 0)
				{
					if(i > 0)
					{
						Number *temp = new Integer("-1");
						operands[i] = calculate(operands[i],temp,"*");
						operators[i]="+";
					}
					else
					{
						Number *temp = new Integer("-1");
						operands[i] = calculate(operands[i],temp,"*");
						operators[i]="0";
					}
				}
			}
		}
	}
	else if (typeid(*val) == typeid(Expression))
	{
		string tempStr= val->toString();
		Number *temp = new Expression(tempStr);
		for(int i = 0; i < operands.size(); i++)
		{
			if(operators[i] == "0" || operators[i] == "+")
				temp = calculate(temp,operands[i], "+");
			else
				temp = calculate(temp,operands[i], "-");
		}
		return temp;
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
	if(!matchFound)
	{
		operators.push_back("+");
		operands.push_back(val);
		simplify();
	}
	else
		simplify();
	return this;
}

Number* Expression::subtract(Number* val)
{
	bool matchFound = false;
	if (typeid(*val) == typeid(Integer))
	{
		for(int i = 0; i < operands.size(); i++)
		{
			if(typeid(*operands[i]) == typeid(Integer))
			{
				matchFound = true;
				if(operators[i]=="-")
					operands[i] = calculate(operands[i],val,"+");
				else
					operands[i] = calculate(operands[i],val,"-");

				if(operands[i]->getValue() < 0)
				{
					Number *temp = new Integer("-1");
					operands[i] = calculate(operands[i],temp,"*");
					operators[i]="-";
				}
			}
		}
	}
	else if (typeid(*val) == typeid(TranscendentalNumber))
	{
		for(int i = 0; i < operands.size(); i++)
		{
			if(typeid(*operands[i]) == typeid(TranscendentalNumber))
			{
				if(operands[i]->getTranscendentalValue() == val->getTranscendentalValue())
				{
					matchFound = true;
					if(operators[i]=="-")
						operands[i] = calculate(operands[i],val,"+");
					else
						operands[i] = calculate(operands[i],val,"-");

					if(typeid(*operands[i]) != typeid(Integer))
					{
						if(operands[i]->getValues()["coefficient"]->getValue() < 0)
						{
							Number *temp = new Integer("-1");
							operands[i] = calculate(operands[i],temp,"*");
							operators[i]="-";
						}
					}
				}
			}
		}
	}
	else if (typeid(*val) == typeid(RationalNumber))
	{
		for(int i = 0; i < operands.size(); i++)
		{
			if(typeid(*operands[i]) == typeid(RationalNumber))
			{
				operands[i] = calculate(operands[i],val,"-");
			}
		}
	}
	else if (typeid(*val) == typeid(Expression))
	{
		string tempStr= val->toString();
		Number *temp = new Expression(tempStr);
		temp = calculate(temp, new Integer("-1"),"*");
		temp = calculate(this,temp, "+");
		return temp;
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
	if(!matchFound)
	{
		operators.push_back("-");
		operands.push_back(val);
	}
	else
		simplify();
	return this;
}
Number* Expression::multiply(Number* val)
{
	if (typeid(*val) == typeid(Expression))
	{
		string tempstr = val->toString();
		Expression *expr = new Expression(tempstr);
		vector<Number*> tempOperands;
		vector<string> tempOperators;

		for(int i = 0; i < operands.size(); i++)
		{
			for(int j = 0; j < expr->getOperands().size();j++)
			{
				tempOperands.push_back(calculate(operands[i],expr->getOperands()[j],"*"));

				//if the operators are both + or -
				if(operators[i].compare(expr->getOperators()[j]) == 0)
				{
					if(i == 0 && j == 0)
						tempOperators.push_back("0");

					else
						tempOperators.push_back("+");
				}
				//different
				else
				{
					if(i == 0 && j == 0)
						tempOperators.push_back("-");

					else
					{
						if(i == 0)
						{
							if(operators[i] == "0")
								tempOperators.push_back(expr->getOperators()[j]);
							//if the first operators is negative
							else
							{
								if(operators[i].compare(expr->getOperators()[j]) == 0)
									tempOperators.push_back("+");
								else
									tempOperators.push_back("-");
							}
						}
						else if(j == 0)
						{
							if(expr->getOperators()[j] == "0")
								tempOperators.push_back(operators[i]);
							//if the first operators is negative
							else
							{
								if(expr->getOperators()[j].compare(operators[i]) == 0)
									tempOperators.push_back("+");
								else
									tempOperators.push_back("-");
							}
						}
						else
						{
							if(operators[i].compare(expr->getOperators()[j]) == 0)
								tempOperators.push_back("+");
							else
								tempOperators.push_back("-");
						}
					}
				}
			}
		}
		operands = tempOperands;
		operators = tempOperators;
	}
	else
	{
		for(int i = 0; i < operands.size(); i++)
		{
			operands[i] = calculate(operands[i],val,"*");
			if(typeid(*operands[i]) != typeid(Integer) &&
			   typeid(*operands[i]) != typeid(RationalNumber))
			{
				if(operands[i]->getValues()["coefficient"]->getValue() < 0)
				{
					Number *temp = new Integer("-1");
					operands[i] = calculate(operands[i],temp,"*");
					if(operators[i]== "+" || operators[i] == "0")
						operators[i]="-";
					else if(operators[i] == "-")
					{
						if(i == 0)
							operators[i] = "0";
						else
							operators[i] = "+";
					}
				}
			}
			else
			{
				if(operands[i]->getValue() < 0)
				{
					Number *temp = new Integer("-1");
					operands[i] = calculate(operands[i],temp,"*");
					if(operators[i]== "+" || operators[i] == "0")
						operators[i]="-";
					else if(operators[i] == "-")
					{
						if(i == 0)
							operators[i] = "0";
						else
							operators[i] = "+";
					}

				}
			}
		}
	}
	simplify();
	return this;
}
Number* Expression::divide(Number* val)
{
	if (typeid(*val) == typeid(Expression))
	{
		return new RationalNumber(this, val);
	}
	else
	{
		for(int i = 0; i < operands.size(); i++)
		{
			operands[i] = calculate(operands[i],val,"/");
			if(typeid(*operands[i]) != typeid(Integer) &&
			   typeid(*operands[i]) != typeid(RationalNumber))
			{
				if(operands[i]->getValues()["coefficient"]->getValue() < 0)
				{
					Number *temp = new Integer("-1");
					operands[i] = calculate(operands[i],temp,"*");
					operators[i]="-";
				}
			}
			else
			{
				if(operands[i]->getValue() < 0)
				{
					Number *temp = new Integer("-1");
					operands[i] = calculate(operands[i],temp,"*");
					operators[i]="-";
				}
			}
		}
	}
	simplify();
	return this;
}
Number* Expression::exponentiate(Number* val)
{
	if (typeid(*val) == typeid(Integer))
	{
		if(val->getValue() == 0)
			return new Integer("1");
		else if(val->getValue() == 1)
			return this;
		else if(val->getValue() == 2)
		{
			if(operands.size() > 2)
				return new Exponential(this, val, new Integer("1"));
			else
				return this->multiply(this);
		}
		else
		{
			return new Exponential(this, val, new Integer("1"));
		}
	}
	else
	{
		return new Exponential(this, val, new Integer("1"));
	}
}

bool Expression::isNumeric(string token)
{
	string onesDigit = token.substr(0,1);
		if(token.find_first_of("1234567890ep.") != -1 &&
		   token.find_first_of("_") == -1	)
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
		}
		else if(isNumeric(token))
		{
			out.push_back( token );
		}
	}

	while ( !stack.empty() )
	{
		string stackToken = stack.top();

		// Pop the operator onto the output queue./
		out.push_back( stackToken );
		stack.pop();
	}

	rpn.assign( out.begin(), out.end() );
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
                	if(expression[i+1] == "-")
                	{
                		operators.push_back("-");
                		i++;
                	}
                	else
                		operators.push_back("0");
                }
            }
            else
            {
            	if(token == ":")
            	{
					Number *coeff = new Integer("1");
					Number *value = operands[i-1];
					Number *base = operands[i-2];
					operands.pop_back();
					operands.pop_back();
//					if(typeid(*n1) == typeid(Integer))
//						base = new Integer(n1->toString());
//					else if(typeid(*n1) == typeid(TranscendentalNumber))
//						base = new TranscendentalNumber(n1->toString());

					operands.push_back(new Logarithm(coeff,value,base));

            	}
            	else
            	{
            		operators.push_back(token);
            	}
            }
      }
}

Number* Expression::calculate(Number* num1, Number* num2, string op)
{
	Number* result;
		Number *n1 = NULL, *n2 = NULL, *temp = NULL;
		stringstream logStream;
		string log, tempStr;

		if(typeid(*num1) == typeid(Expression))
		{
			tempStr = num1->toString();
			n1 = assignToClass(tempStr);
		}
		else if(typeid(*num1) == typeid(Logarithm))
		{
			tempStr = num1->toString();
			if(isNumeric(tempStr))
				n1 = assignToClass(tempStr);
			else
				n1 = new Logarithm(tempStr);
		}
		else
		{
			//determine type of num1
			if(typeid(*num1) == typeid(Integer))
			{
				string temp = num1->toString();
				n1 = new Integer(num1->toString());
			}

			else if(typeid(*num1) == typeid(TranscendentalNumber))
				n1 = new TranscendentalNumber(num1->toString());

			else if(typeid(*num1) == typeid(RationalNumber))
				n1 = new RationalNumber(num1->toString());

			else if(typeid(*num1) == typeid(Exponential))
			{
				n1 = new Exponential(num1->getValues()["value"],
									 num1->getValues()["exponent"],
									 num1->getValues()["coefficient"]);
			}

			else if(typeid(*num1) == typeid(Logarithm))
				n1 = new Logarithm(num1->toString());
			else
			{
				string temp = num1->toString();
				n1 = new Expression(temp);
			}
		}

		if(typeid(*num2) == typeid(Expression))
		{
			tempStr = num2->toString();
			n2 = assignToClass(tempStr);
		}
		else if(typeid(*num2) == typeid(Logarithm))
		{
			tempStr = num2->toString();
			if(isNumeric(tempStr))
				n2 = assignToClass(tempStr);
			else
				n2 = new Logarithm(tempStr);
		}
		else
		{
			//determine type of num2
			if(typeid(*num2) == typeid(Integer))
				n2 = new Integer(num2->toString());

			else if(typeid(*num2) == typeid(TranscendentalNumber))
				n2 = new TranscendentalNumber(num2->toString());

			else if(typeid(*num2) == typeid(RationalNumber))
				n2 = new RationalNumber(num2->toString());

			else if(typeid(*num2) == typeid(Exponential))
			{
				n2 = new Exponential(num2->getValues()["value"],
									 num2->getValues()["exponent"],
									 num2->getValues()["coefficient"]);
			}

			else if(typeid(*num2) == typeid(Logarithm))
				n2 = new Logarithm(num2->toString());
			else
			{
				string temp = num2->toString();
				n2 = new Expression(temp);
			}
		}

		if(op == "+")
			result = n1->add(n2);
		else if(op == "-")
			result = n1->subtract(n2);
		else if(op == "*")
				result = n1->multiply(n2);
		else if(op == "/")
		{
			if(typeid(*n2) == typeid(Integer))
			{
				if(n2->getValue() == 0)
				   {
						string exception = "\nERROR: Cannot divide by zero!";
						throw exception;
				   }
			}
				result = n1->divide(n2);
		}
		else if(op == "^")
				result = n1->exponentiate(n2);
		else if(op == ":")
		{
			if(typeid(*n2) != typeid(Exponential))
			{
				logStream << "log_" << n1->toString() << op << n2->toString();
				log = logStream.str();
				return new Logarithm(log);
			}
			else
			{
				Number *coeff = new Integer("1");
				Number *value = n2;
				Number *base;
				if(typeid(*n1) == typeid(Integer))
					base = new Integer(n1->toString());
				else if(typeid(*n1) == typeid(TranscendentalNumber))
					base = new TranscendentalNumber(n1->toString());

				return new Logarithm(coeff,value,base);
			}
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
			if(token.find_first_of("+-") != -1)
			{
				if(token.find_first_of("+-") != 0)
					temp = new Expression(token);
				else
				{
					int pos = 1;
					if(token.substr(pos,token.size()).find_first_of("+-") != -1)
						temp = new Expression(token);
					else if(token.find_first_of("pe") != -1)
						temp = new TranscendentalNumber(token);
					else if(token.find_first_of("/") != -1)
						temp = new RationalNumber(token);
					else
						temp = new Integer(token);
				}
			}
			else if(token.find_first_of("pe") != -1)
				temp = new TranscendentalNumber(token);
			else if(token.find_first_of("/") != -1)
				temp = new RationalNumber(token);
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

	    if(op1 == "n")
	        return 1;

	    else if(op1 == "^")
	    {
	    	if(op2 == "n")
	    		return -1;
	    	else
	    		return 1;
	    }
	    else if(op1 == ":")
	    {
	    	if(op2 == "n" || op2 == "^")
				return -1;
			else
				return 1;
	    }
	    else if(op1 == "*" || op1 == "/")
	    {
	        if(op2 == "^" || op2 == "n" || op2 == ":")
	            return -1;
	        else if(op2 == "*" || op2 == "/")
	        	return 0;
	        else
	            return 1;
	    }
	    else
	    {
	    	if(op2 == "+" || op2 == "-")
	    		return 0;
	    	else
	    		return -1;
	    }
}

bool Expression::isParentheses(string token)
{
    if(token == "(" || token == ")")
        return true;
    else
        return false;
}

vector<string> Expression::getOperators()
{
	return operators;
}
vector<Number*> Expression::getOperands()
{
	return operands;
}

// Used only for Other classes
long Expression::getValue(){}
void Expression::display(){}
void Expression::setValue(long value){}
string Expression::getTranscendentalValue(){}
map<string, Number*> Expression::getValues(){}
void Expression::setTranscendentalValue(string value){}
void Expression::setValues(string key, Number* val){}
