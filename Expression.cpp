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
                getTokensHelper(expr);
}

Expression::Expression(vector<Number> numbers, vector<char> operators) {
	this->numbers = numbers;
	this->operators = operators;
}

//function definitions

int Expression::comparePrecedence(string op1, string op2)
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
vector<string> Expression::getExpressionTokens(string& expression)
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

bool Expression::infixToRPN(vector<string>& tokens, vector<string>& rpn)
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
            out.push_back( token );             
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

bool Expression::isOperator(string token)
{
    if( token == "+" || token == "-" ||
        token == "*" || token == "/" ||
        token == "^")
        return true;
    else
        return false;   
}

bool Expression::isParentheses(string token)
{  
    if(token == "(" || token == ")")
        return true;
    else
        return false;
}

void Expression::getTokensHelper(string exp)
{
    vector<string> temp = getExpressionTokens(exp);
    
    if(infixToRPN( temp, expression))
    {
        for(int i = 0; i < expression.size(); i++)
            cout << expression[i];
    }
    else
        cout << "mismatching parentheses" << endl;
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