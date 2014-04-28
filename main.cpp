/* 
 * File:        main.cpp
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
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Calculator calculator;
    vector<string> previousExpressions;
    vector<Number*> previousAnswers;
    char mainMenu, reviewMenu, helpMenu;
    bool keepGoing, proceed;
    int previous;
    string expr;
    string ans = "", mem = "";
    string choice;
    
    cout << "*** Welcome to the Calculator Program! ***" << endl;

cout << " ____              ___                    ___             __             " << endl;
cout << "/\\  _`\\           /\\_ \\                  /\\_ \\           /\\ \\__          " << endl;
cout << "\\ \\ \\/\\_\\     __  \\//\\ \\     ___   __  __\\//\\ \\      __  \\ \\ ,_\\    __   " << endl;
cout << " \\ \\ \\/_/_  /'__`\\  \\ \\ \\   /'___\\/\\ \\/\\ \\ \\ \\ \\   /'__`\\ \\ \\ \\/  /'__`\\ " << endl;
cout << "  \\ \\ \\L\\ \\/\\ \\L\\.\\_ \\_\\ \\_/\\ \\__/\\ \\ \\_\\ \\ \\_\\ \\_/\\ \\L\\.\\_\\ \\ \\_/\\  __/ " << endl;
cout << "   \\ \\____/\\ \\__/.\\_\\/\\____\\ \\____\\\\ \\____/ /\\____\\ \\__/.\\_\\\\ \\__\\ \\____\\" << endl;
cout << "    \\/___/  \\/__/\\/_/\\/____/\\/____/ \\/___/  \\/____/\\/__/\\/_/ \\/__/\\/____/" << endl;

    
    //this do-while loop represents the main menu
    do
        {
            cout << "\nWhat do you want to do?\n" << endl;
        
            cout << "(1) Compute a new expression." << endl;
            cout << "(2) Review previous expressions and answers." << endl;
            cout << "(3) Help." << endl;
            cout << "(4) Quit." << endl;
            cout << "\nEnter your choice: ";
        
            cin >> mainMenu;
            cin.ignore();
            cout << endl;
        
            switch(mainMenu)
                {
                case '1':
                    keepGoing = true;
                    while(keepGoing)
                        {
						cout << "\nEnter 'back' to return to the main menu or 'quit' to exit the program." << endl;
                            cout << "\nEnter your expression: ";
                            getline(cin, expr);
                            if(expr == "back" || expr == "quit")
                                keepGoing = false;
                            else
                                {
                            		string temp2 = expr;
                            		while(temp2.find("ans") != -1 || temp2.find("mem") != -1)
                            		{
                            			stringstream temp;

                            			if(temp2.find("ans") != -1)
                            			{
											int pos = temp2.find("ans");

											temp << temp2.substr(0,pos) << ans
												 << temp2.substr(pos+3,expr.size());

											temp2 = temp.str();
                            			}
                            			else
                            			{
                            				int pos = temp2.find("mem");

											temp << temp2.substr(0,pos) << mem
												 << temp2.substr(pos+3,expr.size());

											temp2 = temp.str();
                            			}
                            		}

                            		if(temp2 != expr)
                            			expr = temp2;

                            		if(calculator.addInput(expr))
                                    {
                            			try
                            			{
											calculator.calculate();
											cout << "\nAnswer: " << (calculator.getLatestAnswer())->toString() << endl;
											ans = "(" + (calculator.getLatestAnswer())->toString() + ")";
                            			}
                            			catch(string exception)
                            			{
                            				cout << exception << endl;
                            			}
                                    }
                                }
                        }
                    break;
                case '2':
                    previousExpressions = calculator.getPreviousInputs();
            	
                    if(previousExpressions.size() == 0)
                        cout << "There are no previous expressions!" << endl;
            	
                    else{
                    	previousAnswers = calculator.getPreviousA();
                        //this do-while loop is for the user to access previous answers and expressions 
                        do
                            {
                                cout << "\nWould you like to view previous expressions or answers?\n" << endl;

                                cout << "(1) View previous expressions." << endl;
                                cout << "(2) View previous answers." << endl;
                                cout << "(3) Convert a previous answer to a decimal." << endl;
                                cout << "(4) Store a previous answer into the 'mem' variable." << endl;
                                cout << "(5) Return to Main Menu" << endl;
                                cout << "\nEnter your choice: ";

                                cin >> reviewMenu;
                                cin.ignore();
                                cout << endl;

                                switch (reviewMenu)
                                    {
                                    case '1':
                                        cout << "\nHere are the previous expressions: \n" << endl;

                                        for(int i = previousExpressions.size()-1;i>=0;i--)
										{
											cout << "Expression " << (previousExpressions.size()-i) << ": "
												 << previousExpressions[i] << "\n"
												 << endl;
										}
                                        break;
                                    case '2':
                                        cout << "\nHere are the previous answers: \n" << endl;

                                        for(int i = previousAnswers.size()-1;i>=0;i--)
										{
											cout << "Answer " << (previousExpressions.size()-i) << ": "
												 << previousAnswers[i]->toString() << "\n"
												 << endl;
										}
                                        break;
                                    case '3':
                                        do
										{
                                        	do
											{
												cout << "\nIndicate the answer you wish to convert (Enter ""1"" for the first answer, etc.): ";
												cin >> previous;
											} while (previous > previousAnswers.size());

											cout << "\nOriginal form: \n" << endl;
											cout << previousAnswers[previousAnswers.size()-previous]->toString() << endl;

											cout << "\nHere is the floating point form:\n " << endl;
											cout << previousAnswers[previousAnswers.size()-previous]->toDouble() << endl;

											cout << "\nContinue? (Y/N) ";
											cin >> choice;

											if(choice == "Y" || choice == "y")
											{
												proceed = true;
											}
											else if(choice == "N" || choice == "n")
											{
												proceed = false;
											}
										}while (proceed); //end while
                                        break;
                                    case '4':
                                    	cout << "\nIndicate the answer you wish to store in the 'mem' variable "
											 << "(Enter ""1"" for the first answer, etc.): " ;
										cin >> previous;

										//update this
										mem = "(" + previousAnswers[previousAnswers.size()-previous]->toString() + ")";

										cout << "\nmem = " + mem << endl;
										break;
                                    case '5':
                                        cout << "Returning back to the main menu..." << endl;
                                        break;
                                    default:
                                        cout << " Invalid selection! Please choose 1, 2, 3, 4, or 5.\n" << endl;
                                    }
                            }while(reviewMenu != '5'); //end while
                    }
                    break;
                case '3':
                    //this do-while loop represents the help menu
                    do
                        {
                            cout << "What do you need help with?\n" << endl;

                            cout << "(1) Entering an expression" << endl;
                            cout << "(2) Exponents" << endl;
                            cout << "(3) Square/Nth roots" << endl;
                            cout << "(4) Logarithms" << endl;
                            cout << "(5) Fractions" << endl;
                            cout << "(6) Decimals" << endl;
                            cout << "(7) How your answer will be displayed" << endl;
                            cout << "(8) Return to main menu" << endl;
                            cout << "\nEnter your choice: ";
                    
                            cin >> helpMenu;
                            cin.ignore();
                            cout << endl;

                            switch(helpMenu) 
                                {
                                case '1':
                                    cout << "To enter your expression: \n 1) Type in your first value \n 2) Type in your operator, \n 3) Type your second value \n\nEx: 4*5 \t (3 + 5) / 2 \nApproved Operators: +, -, *, /, ^ \nTranscedental Numbers: pi, e \n" << endl;
                                    break;
                                case '2':
                                    cout << "To write out an exponent, use the following format: \n a^x \n\nThis will be read as 'a raised to the power of x'.\n" << endl;
                                    break;
                                case '3':
                                    cout << "To write out a square root or nth root, use the following formats: \n x^(1/2) \t x^(1/n) \n \nThis will read as 'the square root of x' or 'the nth root of x'. \n" << endl;
                                    break;
                                case '4':
                                    cout << "To write out a logarithm, use the following format: \n log_b:x \n \nThis will read as 'log base b of x'. \n" << endl;
                                    break;
                                case '5':
                                    cout << "To write out a fraction or rational number, use the following format: a/b \n \nThis will read as 'a over b'. \n" << endl;
                                    break;
                                case '6':
                                    cout << "If your input is a terminating decimal, then your answer will return as a simplified fraction. \nEx: .25 = 1/4 \t .2 = 1/5\n\nExceptions include: \n.3333 = 1/3 \t .6666 = 2/3 \t .9999 = 1\n" << endl;
                                    break;
                                case '7':
                                    cout << "Please keep in mind that your answers will be returned in their simplest forms as \nintegers (i.e. 2 + 2 = 4), fractions (i.e. 2/6 = 1/3), logarithms (i.e. log_10:6 = log_10:2 + log_10:3), \n or expressions (i.e. 2 + 2 + pi^2 = 4 + pi^2). \nIf you wish to receive decimal answers, please go to the main menu and press 2 to review previous answers. \nFrom here, you can also set previous answers to the ans keyword." << endl;
                                    break;
                                case '8':
                                    cout << "Returning back to the main menu..." << endl;
                                    break;
                                default:
                                    cout << "Invalid selection! Choose 1, 2, 3, 4, 5, 6, 7, or 8.\n" << endl;
                                }
                        }while(helpMenu != '8');
                    break;
                case '4':
                    break;
                default:
                    cout << "Invalid selection! Choose 1, 2, 3, or 4!\n" << endl;
                }
        
        }while(mainMenu != '4' && expr != "quit");
    
    return 0;
}
