
//expression
setTerms(string expression)
{
	//finds the position of the operator
	int pos = expression.find_first_of("+-*/"); 	
	
	//check if a valid operator was entered
	if(pos == -1)
	{
		string exception = "ERROR! Enter a valid operator! (+ - * /)\n";
		throw exception;
	}  
	
	/*************************************************
	  determines if the operation is division and
	  then checks if the denominator is 0 by searching
	*************************************************/
	if(expression[pos] == '/' && atof(expression.substr(pos+1,expression.size()).c_str()) == 0)
	{
		string exception = "ERROR! Cannot divide by zero!\n";
		throw exception;
	}
		
	//sets the first number to a
	setATerm(atof(expression.substr(0,pos).c_str()));  
			
	//sets the operator
	setOperator(expression[pos]);					   
			
	//sets the second number to b
	setBTerm(atof(expression.substr(pos+1,expression.size()).c_str())); 
}
