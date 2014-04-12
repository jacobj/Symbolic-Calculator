/*
	This file tests the Calculator class
*/

#include "Calculator.h"

int main()
{
	Calculator calculator;
	vector<string> inputs, answers;
	string input;
	
	/*//addition test cases
	calculator.addInput("1+2");
	calculator.calculate();
	
	calculator.addInput("(1+2"); //should produce "mismatch parentheses error"
	calculator.calculate();
	
	calculator.addInput("1+2+3)"); //should produce "mismatch parentheses error"
	calculator.calculate();
	
	calculator.addInput("(1+2)+3");
	calculator.calculate();

	calculator.addInput("(1+2+3)");
	calculator.calculate();
	
	calculator.addInput("1+(2+3)");
	calculator.calculate();
	
	calculator.addInput("-1+2");
	calculator.calculate();
	
	calculator.addInput("1+(-2)");
	calculator.calculate();
	
	calculator.addInput("(1+(-2))");
	calculator.calculate();

	calculator.addInput("1+(2)");
	calculator.calculate();

	calculator.addInput("(1+2)-(1 + 2)");
	calculator.calculate();

	//subtraction test cases
	calculator.addInput("2-1");
	calculator.calculate();

	calculator.addInput("(2-1)");
	calculator.calculate();

	calculator.addInput("2-(1)");
	calculator.calculate();

	calculator.addInput("((2)-(1))");
	calculator.calculate();

	calculator.addInput("-2-1");
	calculator.calculate();

	calculator.addInput("1-2");
	calculator.calculate();

	calculator.addInput("2-1-1");
	calculator.calculate();

	calculator.addInput("2-(1-1)");
	calculator.calculate();
	
	//multiplication test cases
	calculator.addInput("1 * 2");
	calculator.calculate();

	calculator.addInput("2 * 3");
	calculator.calculate();
	
	calculator.addInput("2 * 3 * 4");
	calculator.calculate();

	calculator.addInput("(2 * 3) * 7");
	calculator.calculate();

	calculator.addInput("2 * 3");
	calculator.calculate();

	//division test cases
	calculator.addInput("2 / 1");
	calculator.calculate();

	calculator.addInput("0 / 2");
	calculator.calculate();

	calculator.addInput("2 / 0");
	calculator.calculate();

	calculator.addInput("(3 / 3)/3");
	calculator.calculate();

	calculator.addInput("2 / 1");
	calculator.calculate();*/
	
	//exponent test cases
	calculator.addInput("2 ^ 2");
	calculator.calculate();

	calculator.addInput("2 ^ (2)");
	calculator.calculate();

	calculator.addInput("(2) ^ 2");
	calculator.calculate();

	calculator.addInput("(2^2)");
	calculator.calculate();

	calculator.addInput("2^2)");
	calculator.calculate();

	calculator.addInput("(2^2");
	calculator.calculate();

	calculator.addInput("2^3");
	calculator.calculate();

	calculator.addInput("2*2^3");
	calculator.calculate();

	calculator.addInput("2^3*2");
	calculator.calculate();

	calculator.addInput("1+2^3");
	calculator.calculate();

	calculator.addInput("2^3+1");
	calculator.calculate();

	calculator.addInput("2^(1+2");
	calculator.calculate();

	calculator.addInput("2^(1+2)");
	calculator.calculate();

	calculator.addInput("2^2^2");
	calculator.calculate();

	calculator.addInput("4^(1/2)");
	calculator.calculate();

	calculator.addInput("8^(1/3)");
	calculator.calculate();

	calculator.addInput("(3/4)^(2)");
	calculator.calculate();

	calculator.addInput("(-1)^2");
	calculator.calculate();

	calculator.addInput("-1^2");
	calculator.calculate();

	calculator.addInput("0^2");
	calculator.calculate();

	inputs = calculator.getPreviousInputs();
	answers = calculator.getPreviousAnswers();
	for(int i = 0; i < inputs.size();i++)
	{
		cout << "Expression: " << inputs[i] << endl;
		cout << endl;
		cout << "Answer: " << answers[i] << endl;
	}
	return 0;
}

