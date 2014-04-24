/* 
 * File:        Calculator.cpp
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 */

#include "Calculator.h"

//constructors
Calculator::Calculator() {}

Calculator::Calculator( string expr )
{
	addInput(expr);
}

//function definitions

bool Calculator::addInput(string exp)
{
	bool success = true;
    vector<string> temp = setExpressionTokens(exp);

    if(temp.empty())
    {
    	cout << "Enter an actual expression!" << endl;
    	success = false;
    	return success;
    }

    if( infixToRPN(temp, expression) )
    {
    	previousInputs.push_back( exp );
    	return success;
    }

    else
    {
        cout << "\nMismatching parentheses!\n" << endl;
        success = false;
        return success;
    }
}

Number* Calculator::assignToClass(string& token)
{
	Number *temp;

	if(isNumeric(token))
	{
		if(token.find_first_of("+-") != -1)
			temp = new Expression(token);
		else if(token.find_first_of("pe") != -1)
			temp = new TranscendentalNumber(token);
		else if(token.find_first_of("/") != -1)
			temp = new RationalNumber(token);
		else
			temp = new Integer(token);
	}
	return temp;
}

/*
 * returns 1 if op1 is of greater precedence than op2
 * Ex: op1 = * and op2 = +, return 1
 *
 * returns 0 if op1 is of the same precedence as op2
 * Ex: op1 = * and op2 = /, return 0
 *
 * returns -1 if op1 is of lesser precedence than op2
 * Ex: op1 = + and op2 = *, return -1
 *
 */
void Calculator::calculate()
{
    stack<Number*> st;
    Number* val1b;
    Number* val2b;
    Number* resultt;

    // For each token
    for ( int i = 0; i < (int) expression.size(); ++i )
    {
    	const string token = expression[ i ];

        // If the token is a value push it onto the stack
        if ( !isOperator(token) )
        {
        	Number *token2 = assignToClass(expression[i]);
            st.push(token2);
        }
        else
        {

            // Token is an operator: pop top two entries
            val2b = st.top();
            st.pop();
            //beginning of Number type
            if ( !st.empty() )
            {
            	if(token == "-" && typeid(*val2b)==typeid(RationalNumber) &&
            			   expression[i+1] == "^")
            	{
            		Number *temp = new Integer("-1");
            		resultt = calculate(val2b,temp,"*");
            	}
            	else
            	{
					val1b = st.top();
					st.pop();

					try
					{
						resultt = calculate(val1b, val2b, token);
					}
					catch(string exception)
					{
						throw exception;
					}
            	}
            }
            else
            {
                if ( token == "-" )
                {
                	Number *temp = new Integer("-1");
                    resultt =  calculate(val2b,temp,"*");
                }
                else
                    resultt = val2b;
            }
            // Push result onto stack
            if(typeid(*resultt) == typeid(Exponential))
            {
            	if(resultt->getValues()["value"]->getValue() == 1)
            	{
            		string temp = resultt->toString();
            		resultt = assignToClass(temp);
            	}
            }
            st.push(resultt);

        }
    }

    if(!st.empty())// && st.top() != " ")
    {
    	previousA.push_back(st.top());
    	expression.clear();
    }
}

Number* Calculator::calculate(Number* num1, Number* num2, string op)
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
		n1 = assignToClass(tempStr);
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
			n1 = new Exponential(num1->toString());

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
		n1 = assignToClass(tempStr);
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
			n2 = new Exponential(num2->toString());

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
		logStream << "log_" << n1->toString() << op << n2->toString();
		log = logStream.str();
		return new Logarithm(log);
	}

	return result;
}
int Calculator::comparePrecedence(string op1, string op2)
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

vector<string> Calculator::getPreviousInputs()
{
	return previousInputs;
}

vector<string> Calculator::getPreviousAnswers()
{
	return previousAnswers;
}
vector<Number*> Calculator::getPreviousA()
{
	return previousA;
}
vector<string> Calculator::getExpression()
{
	return expression;
}

Number* Calculator::getLatestAnswer()
{
	return previousA.back();
}

vector<string> Calculator::setExpressionTokens(string& expr)
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
        		i++;
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

bool Calculator::infixToRPN(vector<string>& tokens, vector<string>& rpn)
{
    bool success = true;
    bool leadingNegative = false;
    bool pushed = false;
    
    stack<string>stack;
    list<string>out;

    for(int i = 0; i <tokens.size();i++)
    {
        string token = tokens[i];
        
        if(token == "-" && i == 0)
        	leadingNegative = true;

        if( isOperator( token ) )
        {

            string o1 = token;
            if( !stack.empty() )
            {
                string o2 = stack.top();
                if(!pushed && !leadingNegative && o1 == "-" && o2 == "-")
                {
                	stack.pop();
                	o1 = "+";
                }
                else
                {
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
            }
            stack.push( o1 );
            pushed = false;
        }
        else if ( token == "(" )          
        {          
//        	if(stack.top()=="-")
//        	{
//        		stack.pop();
//        		stack.push("+");
//        		leadingNegative = true;
//        	}
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
                return false;      
            }                                            
        }
        else if(isNumeric(token))
        {
        	out.push_back( token );
        	pushed = true;
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
            return success;      
        }      
  
        // Pop the operator onto the output queue./      
        out.push_back( stackToken );                        
        stack.pop();
    }          

    rpn.assign( out.begin(), out.end() );
  
    return success;
}

bool Calculator::isOperator(string token)
{
    if( token == "+" || token == "-" ||
        token == "*" || token == "/" ||
        token == "^" || token == ":")
        return true;
    else
        return false;   
}

bool Calculator::isNumeric(string token)
{
	string onesDigit = token.substr(0,1);
	if(onesDigit == "1" || onesDigit == "2" ||
	   onesDigit == "3" || onesDigit == "4" ||
	   onesDigit == "5" || onesDigit == "6" ||
	   onesDigit == "7" || onesDigit == "8" ||
	   onesDigit == "9" || onesDigit == "0" ||
	   onesDigit == "e" || onesDigit == "p" ||
	   onesDigit == "pi")
	   return true;
	//else if()
	else
		return false;
}

bool Calculator::isParentheses(string token)
{  
    if(token == "(" || token == ")")
        return true;
    else
        return false;
}

