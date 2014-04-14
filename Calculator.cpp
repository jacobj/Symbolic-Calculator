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
		if(token == "e" || token == "pi")
			temp = new TranscendentalNumber(token);
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
    stack<string> st;
    stack<Number*> st2;
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
            st.push(token);
            st2.push(token2);
        }
        else
        {

            double result =  0.0;

            // Token is an operator: pop top two entries
            string val2 = st.top();
            val2b = st2.top();
            st.pop();
            st2.pop();
            //const double d2 = strtod( val2.c_str(), NULL );

           /* if ( !st.empty() )
            {
            	const string val1 = st.top();
            	st.pop();
            	const double d1 = strtod( val1.c_str(), NULL );

            	//Get the result
            	result = token == "+" ? d1 + d2 :
            			 token == "-" ? d1 - d2 :
            		     token == "*" ? d1 * d2 :
                         token == "/" ? d1 / d2 :
                                    pow(d1, d2);
            }
            else
            {
            	if ( token == "-" )
            		result = d2 * -1;
            	else
            		result = d2;
            }*/
            //beginning of Number type
            if ( !st2.empty() )
            {
                val1b = st2.top();
                st2.pop();
                //calculate(val1, val2, token);
                resultt = calculate(val1b, val2b, token);
            }
            else
            {
                /*if ( token == "-" )
                    result = d2 * -1;
                else
                    result = d2;*/
            }


            // Push result onto stack
            ostringstream s;
            s << result;
            st.push( s.str() );
            st2.push(resultt);

        }
    }
    if(!st.empty() && st.top().c_str() != " ")
    {
    	previousAnswers.push_back(st.top().c_str());
    	previousA.push_back(st2.top());
    	expression.clear();
    }
}

Number* Calculator::calculate(Number* num1, Number* num2, string op)
{
	Number* result;
	Number *n1 = NULL, *n2 = NULL;

	//determine type of num1
	if(typeid(*num1) == typeid(Integer))
		n1 = new Integer(num1->toString());

	else if(typeid(*num1) == typeid(TranscendentalNumber))
		n1 = new TranscendentalNumber(num1->toString());

	//TODO work on additional class cases

	/*else if(typeid(num1) == typeid(RationalNumber))
	else if(typeid(num1) == typeid(Exponential))
	else if(typeid(num1) == typeid(Logarithm)))*/

	//determine type of num2
	if(typeid(*num2) == typeid(Integer))
			n2 = new Integer(num2->toString());

	else if(typeid(*num2) == typeid(TranscendentalNumber))
			n2 = new TranscendentalNumber(num2->toString());

			//TODO work on additional class cases
		/*else if(typeid(num2) == typeid(RationalNumber))
		else if(typeid(num2) == typeid(Exponential))
		else if(typeid(num2) == typeid(Logarithm)))*/

	if(op == "+")
		result = n1->add(n2);
	if(op == "-")
		result = n1->subtract(n2);

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

string Calculator::getLatestAnswer()
{
	return previousAnswers.back();
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
    
    //TODO why does the debugger pause here?
    stack<string>stack;
    list<string>out;

    for(int i = 0; i <tokens.size();i++)
    {
        string token = tokens[i];
        
        if( isOperator( token ) )
        {
            string o1 = token;
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
                return false;      
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
        token == "^")
        return true;
    else
        return false;   
}

bool Calculator::isNumeric(string token)
{
	if(token == "1" || token == "2" ||
	   token == "3" || token == "4" ||
	   token == "5" || token == "6" ||
	   token == "7" || token == "8" ||
	   token == "9" || token == "0" ||
	   token == "e" || token == "p" ||
	   token == "pi")
		return true;
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

