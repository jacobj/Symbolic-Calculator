/*
	This file tests the Calculator class
*/

#include "Calculator.h"

int main()
{
	Calculator calculator;
	vector<string> inputs;
	vector<Number*> answers;
	string input;
	
	//Number *integer;
	calculator.addInput("pi + pi");
	calculator.calculate();
	//calculator.addInput("e + e");
	//calculator.calculate();
	/*//exponent test cases
	calculator.addInput("-2 ^ 2");
	calculator.calculate();
	cout << calculator.getLatestAnswer() << endl;

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
	calculator.calculate();*/

	inputs = calculator.getPreviousInputs();
	answers = calculator.getPreviousA();
	for(int i = 0; i < inputs.size();i++)
	{
		cout << "Expression: " << inputs[i] << endl;
		cout << endl;
		cout << "Answer: " << answers[i]->toString() << endl;
	}
	return 0;
}
