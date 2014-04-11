/*
	This file tests the Calculator class
*/

#include "Calculator.h"

int main()
{
	Calculator calculator("1+2");
	vector<string> expressions;
	
	calculator.addInput("(3 * 5)");
	expressions = calculator.getPreviousInputs();
	
	for(int i = 0; i < expressions.size();i++)
	{
		cout << expressions[i];
		cout << endl;
	}
	return 0;
}
