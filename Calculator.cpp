/* 
 * File:        Calculator.cpp
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#include "Calculator.h"

//Constructor
Calculator::Calculator() {}

Calculator::Calculator( string expr )
{
	addInput(expr);
}

//function definitions

int Calculator::comparePrecedence(string op1, string op2)
{
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
vector<string> Calculator::setExpressionTokens(string& expression)
{
    vector<string> tokens;
    string str = "";
    
    for(int i = 0; i < (int) expression.length();i++)
    {
        string token(1,expression[i]);
        
        if(isOperator(token) || isParentheses(token))
        {
            if(!str.empty())
            {
                tokens.push_back(str);
            }
            str = "";
            tokens.push_back(token);
        }
        else
        {
            if(!token.empty() && token != " ")
            {
                str.append(token);
            }
            else
            {
                if(str != "")
                {
                    tokens.push_back(str);
                    str = "";
                }
            }
        }
    }
    tokens.push_back(str);
    return tokens;
}

bool Calculator::infixToRPN(vector<string>& tokens, vector<string>& rpn)
{
    bool success = true;
    
    list<string> out;
    stack<string> stack;
    
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
        else
        {
        	if(token != "")
        		out.push_back( token );
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

//double Calculator::RPNtoDouble( vector<string> tokens )
void Calculator::calculate()      
{
    stack<string> st;

    // For each token          
    for ( int i = 0; i < (int) expression.size(); ++i )
    {         
        const string token = expression[ i ];
  
        // If the token is a value push it onto the stack          
        if ( !isOperator(token) )          
        {          
            st.push(token);          
        }          
        else          
        {    
            double result =  0.0;    
  
            // Token is an operator: pop top two entries          
            const string val2 = st.top();        
            st.pop();        
            const double d2 = strtod( val2.c_str(), NULL );          
  
            if ( !st.empty() )    
            {    
                const string val1 = st.top();        
                st.pop();        
                const double d1 = strtod( val1.c_str(), NULL );       
  
                //Get the result          
                result = token == "+" ? d1 + d2 :          
                         token == "-" ? d1 - d2 :          
                         token == "*" ? d1 * d2 :          
                                        d1 / d2;          
            }    
            else    
            {    
                if ( token == "-" )    
                    result = d2 * -1;    
                else     
                    result = d2;    
            }    
  
  
            // Push result onto stack         
            ostringstream s;        
            s << result;        
            st.push( s.str() );

        }          
    }
    if(st.top().c_str() != " ")
    {
    	previousAnswers.push_back(st.top().c_str());
    	expression.clear();
    }
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

bool Calculator::isParentheses(string token)
{  
    if(token == "(" || token == ")")
        return true;
    else
        return false;
}

vector<string> Calculator::getExpression()
{
	return expression;
}

void Calculator::addInput(string exp)
{	
    vector<string> temp = setExpressionTokens(exp);
    
    if( infixToRPN(temp, expression) )

    	previousInputs.push_back( exp );

    	
    else

        cout << "mismatching parentheses\n" << endl;

}

